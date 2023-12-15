
#include <fstream>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>

#include "ssgl.h"
#include "gl_timing.h"

void cpu_version(uint width, uint height, std::vector<ivec2>& stones, std::vector<ivec2>& original_barriers, std::vector<int16_t>& jump_map) {
    std::vector<ivec4> barriers;
    for(auto& b : original_barriers) barriers.push_back(b.yxyx+ivec2(1, -1).xxyy);
    uint barrier_offset[2048];

    for (uint iter = 0; iter < 1000000; iter++) {
        for (int dir = 0; dir < 4; ++dir) {
            int delta = 1 - (dir & 2);
            for(int i = 0; i<barriers.size(); ++i)
                barrier_offset[i] = barriers[i][dir];

            for (int i = 0; i < stones.size(); ++i) {
                uint barrier = jump_map[dir * width * height + stones[i].y * width + stones[i].x];
                stones[i] = ivec2(barrier_offset[barrier], stones[i].x);
                barrier_offset[barrier] += delta;
            }
        }
    }
    uint result = 0;
    for (auto& s : stones)
        result += height - s.y;
    std::cout << "result " << result;
}

int main() {
    
    LARGE_INTEGER cpu_start, cpu_end, freq;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&cpu_start);

    OpenGL context(1280, 720, "AoC 2023 Day 14 part 2", false, false);

    std::ifstream file("input14.txt");
    std::vector<std::string> lines;
    for (std::string line; std::getline(file, line); lines.push_back(line));

    uint width = lines[0].length(), height = lines.size();
    std::vector<ivec2> stones, barriers;
    std::vector<int16_t> barrier_maps(width * height * 4, std::numeric_limits<int16_t>::max());

    // oof.
    auto add_barrier = [&](ivec2 v0, int barrier_index) {
        ivec2 deltas[] = { ivec2(0, -1), ivec2(-1, 0), ivec2(0, 1), ivec2(1, 0) };
        for (int dir = 0; dir < 4; ++dir) {
            ivec2 v = v0;
            ivec2 delta = deltas[dir];
            if (dir & 1) {
                v = v.yx;
                delta = delta.yx;
            }
            if(v.x>=0 && v.y>=0 && v.x<width && v.y<height)
                barrier_maps[dir * width * height + v.y * width + v.x] = -1;
            while (true) {
                v -= delta;
                uint index = v.y * width + v.x;
                if (!(v.x >= 0 && v.y >= 0 && v.x < width && v.y < height) || barrier_maps[dir * width * height + index] < 0) break;
                barrier_maps[dir*width*height+index] = barrier_index;
            }
        }
    };

    for (int y = 0; y < lines.size(); ++y)
        for (int x = 0; x < lines[y].size(); ++x) {
            if (lines[y][x] == 'O') stones.push_back({ x, y });
            if (lines[y][x] == '#') barriers.push_back({ x, y });
        }

    for (int y = 0; y < height; ++y) {
        barriers.push_back({ -1, y });
        barriers.push_back({ width, y });
    }
    for (int x = 0; x < width; ++x) {
        barriers.push_back({ x, -1 });
        barriers.push_back({ x, height });
    }
    std::default_random_engine eng;
    std::shuffle(stones.begin(), stones.end(), eng);
    std::shuffle(barriers.begin(), barriers.end(), eng);

    for(int i = 0; i<barriers.size(); ++i)
        add_barrier(barriers[i], i);

    Texture<GL_TEXTURE_2D_ARRAY> map_texture;
    glBindTexture(GL_TEXTURE_2D_ARRAY, map_texture);
    glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_R16I, width, height, 4, 0, GL_RED_INTEGER, GL_SHORT, barrier_maps.data());
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    std::cout << stones.size() << " stones, " << barriers.size() << " barriers\n";

    std::vector<uint> result = {0};
    Buffer stone_buffer(stones), barrier_buffer(barriers), result_buffer(result);
    uint steps = 10000;
    int k = 0;
    for (uint start_index = 0; start_index < 1000000000; start_index += steps) {
        auto run = [&] {
            glsl_extension(GL_NV_shader_atomic_int64, require);
            layout(local_size_x = 1024) in;
            uniform int bind(width, height, steps);
            uniform isampler2DArray bind(map_texture);
            buffer bind_block(stone_buffer) { dynamic_array(ivec2, stones); };
            buffer bind_block(barrier_buffer) { dynamic_array(ivec2, barriers); };
            buffer bind_block(result_buffer) { uint result; };

            shared int barrier_offset[2048];
            shared uint local_result;

            void glsl_main() {
                const int id = int(gl_LocalInvocationIndex), id2 = int(id + 1024);
                if (id == 0) local_result = 0;

                ivec2 stone[2]; ivec4 barrier_[2]; // in principle could need more, these are enough for my input
                int stone_barrier[2];
                barrier_[0] = barriers[id].yxyx + ivec2(1,-1).xxyy;
                barrier_[1] = barriers[id2].yxyx + ivec2(1, -1).xxyy;
                stone[0] = stones[id];
                bool second_stone = id2 < stones.length();
                if (second_stone) stone[1] = stones[id2];

                for (uint iter = 0; iter < steps; iter++) {
                    for (int dir = 0; dir < 4; ++dir) {
                        int delta = 1 - (dir & 2);
                        barrier_offset[id] = barrier_[0][dir];
                        barrier_offset[id2] = barrier_[1][dir];
                        stone_barrier[0] = texelFetch(map_texture, ivec3(stone[0], dir), 0).x;
                        if(second_stone) stone_barrier[1] = texelFetch(map_texture, ivec3(stone[1], dir), 0).x;
                        barrier();
                        stone[0] = ivec2(atomicAdd(barrier_offset[stone_barrier[0]], delta), stone[0].x);
                        if (second_stone) stone[1] = ivec2(atomicAdd(barrier_offset[stone_barrier[1]], delta), stone[1].x);
                        barrier();
                    }
                }

                uint own_result = height - stone[0].y;
                stones[id] = stone[0];
                if (second_stone) {
                    own_result += height - stone[1].y;
                    stones[id2] = stone[1];
                }
                atomicAdd(local_result, own_result);
                barrier();
                if (id == 0) result = local_result;
            }
            };

        useShader(run());
        glDispatchCompute(1, 1, 1); // just one SM!
        glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
        k++;
        if ((k % 20) == 0)
            glFinish();
    }

    //cpu_version(width, height, stones, barriers, barrier_maps);

    result = result_buffer;
    std::cout << result[0] << "\n";
    QueryPerformanceCounter(&cpu_end);
    std::cout << "solved in " << int(double(cpu_end.QuadPart - cpu_start.QuadPart)/double(freq.QuadPart)) << "s\n";

    return 0;
}