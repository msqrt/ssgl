
#include <fstream>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>

#include "ssgl.h"
#include "gl_timing.h"

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
            if(v.x>=0 && v.y>=0 && v.x<width && v.y<height)
                barrier_maps[dir * width * height + v.y * width + v.x] = -1;
            while (true) {
                v -= deltas[dir];
                uint index = v.y * width + v.x;
                if (!(v.x >= 0 && v.y >= 0 && v.x < width && v.y < height) || barrier_maps[dir * width * height + index] < 0) break;
                barrier_maps[dir*width*height+index] = barrier_index;
            }
        }
    };

    for (int y = 0; y < lines.size(); ++y)
        for (int x = 0; x < lines[y].size(); ++x) {
            if (lines[y][x] == 'O') stones.push_back({ x, y });
            if (lines[y][x] == '#') {
                add_barrier({ x, y }, barriers.size());
                barriers.push_back({ x, y });
            }
        }

    for (int y = 0; y < height; ++y) {
        add_barrier({ -1, y }, barriers.size());
        barriers.push_back({ -1, y });
        add_barrier({ width, y }, barriers.size());
        barriers.push_back({ width, y });
    }
    for (int x = 0; x < width; ++x) {
        add_barrier({ x, -1 }, barriers.size());
        barriers.push_back({ x, -1 });
        add_barrier({ x, height }, barriers.size());
        barriers.push_back({ x, height });
    }

    Texture<GL_TEXTURE_2D_ARRAY> map_texture;
    glBindTexture(GL_TEXTURE_2D_ARRAY, map_texture);
    glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_R32I, width, height, 4, 0, GL_RED_INTEGER, GL_SHORT, barrier_maps.data());
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    /*for (int i = 0; i < 4; ++i) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                std::cout << std::setw(5) << barrier_maps[i*width*height + y * width + x];
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }*/

    std::cout << stones.size() << " stones, " << barriers.size() << " barriers\n";

    std::vector<uint> result = {0};
    std::default_random_engine eng;
    std::shuffle(stones.begin(), stones.end(), eng);
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

            void glsl_func(move_stone)(arg_inout(ivec2) stone, bool y_x, int delta, int dir) {
                int barrier_index = texelFetch(map_texture, ivec3(stone, dir), 0).x;
                int coord = atomicAdd(barrier_offset[barrier_index], delta);
                if (y_x) stone.x = coord; else stone.y = coord;
            };

            void glsl_main() {
                const int id = int(gl_LocalInvocationIndex), id2 = int(id + 1024);
                if (id == 0) local_result = 0;

                ivec2 stone[2]; ivec4 barrier_[2]; // in principle could need more, these are enough for my input
                bool first_stone = id < stones.length(), first_barrier = id < barriers.length();
                if (first_stone) stone[0] = stones[id];
                if (first_barrier) barrier_[0] = barriers[id].yxyx + ivec2(1,-1).xxyy;
                bool second_stone = id2 < stones.length(), second_barrier = id2 < barriers.length();
                if (second_stone) stone[1] = stones[id2];
                if (second_barrier) barrier_[1] = barriers[id2].yxyx + ivec2(1, -1).xxyy;

                bool y_x[4] = { false, true, false, true };
                ivec4 deltas = ivec2(1, -1).xxyy;

                for (uint iter = 0; iter < steps; iter++) {
                    for (int dir = 0; dir < 4; ++dir) {
                        barrier_offset[id] = barrier_[0][dir];
                        if (second_barrier) barrier_offset[id2] = barrier_[1][dir];
                        barrier();
                        move_stone(stone[0], y_x[dir], deltas[dir], dir);
                        if (second_stone) move_stone(stone[1], y_x[dir], deltas[dir], dir);
                        barrier();
                    }
                }

                uint own_result = 0;
                if (first_stone) {
                    own_result = height - stone[0].y;
                    stones[id] = stone[0];
                }
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
        if ((k % 100) == 0) {
            glFinish();
            result = result_buffer;
            std::cout << result[0] << ", ";
            //std::cout << ".";
        }
        //stones = stone_buffer;

        /*std::vector<std::string> map(height, std::string(width, '.'));
        for (auto& s : stones) map[s.y][s.x] = 'O';
        for (auto& s : barriers) if(s.x>=0 && s.y>=0 && s.x<width && s.y<width) map[s.y][s.x] = '#';

        for (const std::string& line : map)
            std::cout << line << "\n";
        std::cout << "\n";

        if (k > 3)
            k = 5;*/
    }

    result = result_buffer;
    std::cout << "\n" << result[0] << "\n";
    QueryPerformanceCounter(&cpu_end);
    std::cout << "solved in " << (double(cpu_end.QuadPart - cpu_start.QuadPart)/double(freq.QuadPart)*1000.) << "ms\n";

    return 0;
}
