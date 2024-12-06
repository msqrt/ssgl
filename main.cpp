
#include <iostream>
#include <fstream>

#include "ssgl.h"
#include "gl_timing.h"

int main() {
    LARGE_INTEGER cpu_start, window_done, cpu_end, freq;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&cpu_start);

    OpenGL context(1280, 720, "advent of code 2024 day 6 part 2", false, false);

    QueryPerformanceCounter(&window_done);
    
    std::ifstream file("input6.txt");
    std::vector<std::string> lines;
    for (std::string line; std::getline(file, line); lines.push_back(line));
    
    ivec2 start_pos;
    std::vector<uint> map(lines.size() * 5, 0);
    for (int i = 0; i < lines.size(); ++i)
        for (int j = 0; j < lines[i].size(); ++j) {
            if (lines[i][j] == '^')
                start_pos = ivec2(i, j);
            else if (lines[i][j] == '#')
                map[i * 5 + (j >> 5)] |= 1 << (j & 31);
        }


    std::vector<uint> result = { 0 };
    Buffer result_buffer(result);
    Buffer map_buffer(map);

    TimeStamp start;

    auto comp = [&] {
        layout(local_size_x = 128) in;
        uniform ivec2 bind(start_pos);
        buffer bind_block(result_buffer) { uint result; };
        buffer bind_block(map_buffer) { dynamic_array(uint, m); };
        shared uint map[130 * 5];
        void glsl_main() {
            for (int i = int(gl_LocalInvocationID.x); i < 130 * 5; i += int(gl_WorkGroupSize.x))
                map[i] = m[i];
            barrier();
            uint loop = 0;
            for (int problem = int(gl_GlobalInvocationID.x); problem < 130 * 130; problem += int(gl_WorkGroupSize.x * gl_NumWorkGroups.x)) {
                ivec2 stone = ivec2(problem % 130, problem / 130);
                if ((map[stone.x * 5 + (stone.y >> 5)] & (1 << (stone.y & 31))) != 0 || stone == start_pos)
                    continue;
                ivec2 pos = start_pos, dir = ivec2(-1, 0);
                for (int i = 0; i < 130 * 130 * 4; i++) {
                    ivec2 updated = pos + dir;
                    if (updated.x < 0 || updated.x >= 130 || updated.y < 0 || updated.y >= 130) break;
                    if ((map[updated.x * 5 + (updated.y >> 5)] & (1 << (updated.y & 31))) != 0 || updated == stone)
                        dir = ivec2(dir.y, -dir.x);
                    else
                        pos = updated;
                    if (i + 1 == 130 * 130 * 4) loop++;
                }
            }
            atomicAdd(result, loop);
        }
    };
    useShader(comp());
    glDispatchCompute(256, 1, 1);

    TimeStamp end;

    result = result_buffer;
    QueryPerformanceCounter(&cpu_end);
    std::cout << result[0] << "\n";
    std::cout << "full time " << double(cpu_end.QuadPart - cpu_start.QuadPart) / double(freq.QuadPart)*1000. << "ms\n - device creation " << double(window_done.QuadPart - cpu_start.QuadPart) / double(freq.QuadPart)*1000. << "ms\n - simulation time " << (end - start) << "ms\n";

    return 0;
}
