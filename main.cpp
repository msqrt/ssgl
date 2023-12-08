
#include <fstream>
#include <map>
#include <algorithm>
#include <iostream>

#include "ssgl.h"
#include "gl_timing.h"

glsl_global const int64_t steps = 269, steps2 = steps*steps, steps3 = steps2*steps;

int main() {
    
    LARGE_INTEGER cpu_start, cpu_end, freq;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&cpu_start);

    std::ifstream file("input8.txt");
    std::vector<std::string> lines;
    for (std::string line; std::getline(file, line); lines.push_back(line));

    std::vector<uint32_t> direction((lines[0].size()+31)/32, 0u);
    for (int i = 0; i < lines[0].size(); ++i)
        direction[i>>5] |= int(lines[0][i] == 'R') << (i & 31);

    std::map<std::string, std::pair<std::string, std::string>> map;
    for (int i = 2; i < lines.size(); ++i)
        map[lines[i].substr(0, 3)] = { lines[i].substr(7, 3), lines[i].substr(12, 3) };

    std::map<std::string, uint16_t> indices;
    for (auto& [key, value] : map)
        indices[key] = indices.size();

    std::vector<uint32_t> step_map(indices.size());
    for (auto& [key, value] : map)
        step_map[indices[key]] = indices[value.first] | (indices[value.second] << 16);

    auto iterate_map = [&](std::vector<uint32_t> step_map) {
        std::vector<uint32_t> new_map;
        for (int j = 0; j < step_map.size(); ++j) {
            uint16_t node = j;
            for (int i = 0; i < lines[0].size(); ++i)
                node = (step_map[node] >> (16 * ((direction[i >> 5] >> (i & 31)) & 1))) & 0xFFFFu;
            new_map.push_back(node | (node << 16));
        }
        return new_map;
    };

    auto latest = step_map, full_map = step_map;
    for (int i = 0; i < 6; ++i) {
        latest = iterate_map(latest);
        if(i>=2)
            full_map.insert(full_map.end(), latest.begin(), latest.end());
    }
    std::vector<uint32_t> starts;
    for (auto& [key, value] : indices)
        if (key[2] == 'A')
            starts.push_back(value);

    std::vector<uint32_t> goals((750+31)/32, 0u);
    for (auto& [key, value] : indices)
        goals[value >> 5] |= key[2] == 'Z' ? (1 << (value & 31)) : 0u;
    
    std::vector<int64_t> result = {std::numeric_limits<int64_t>::max()};

    OpenGL context(1280, 720, "AoC 2023 Day 8 part 2", false, false);

    
    Buffer dir_buffer(direction), map_buffer(full_map), goal_buffer(goals), start_buffer(starts), result_buffer(result);

    uint groups = 120;
    for (int64_t start_index = 0; result[0] == std::numeric_limits<int64_t>::max(); start_index += groups * 1024 * steps3) {
        auto run = [&] {
            glsl_extension(GL_NV_shader_atomic_int64, require);
            layout(local_size_x = 1024) in;
            uniform int64_t bind(start_index);
            buffer bind_block(dir_buffer) { dynamic_array(uint, global_dirs); };
            buffer bind_block(map_buffer) { dynamic_array(uint, global_map); };
            buffer bind_block(goal_buffer) { dynamic_array(uint, global_goals); };
            buffer bind_block(start_buffer) { dynamic_array(uint, starts); };
            buffer bind_block(result_buffer) { int64_t result; };

            shared uint dirs[9], goals[24];
            shared uint map[750 * 4];

            void glsl_main() {
                uint lid = gl_LocalInvocationIndex;
                if (lid < 9)
                    dirs[lid] = global_dirs[lid];
                if (lid < 24)
                    goals[lid] = global_goals[lid];

                for (uint i = lid; i < 750 * 4; i += gl_WorkGroupSize.x)
                    map[i] = global_map[i];
                barrier();

                uint start_nodes[6];
                for (int i = 0; i < 6; ++i) start_nodes[i] = starts[i];

                int64_t threads = int64_t(gl_NumWorkGroups.x * gl_WorkGroupSize.x);
                int64_t id = int64_t(gl_GlobalInvocationID.x)*steps3 + start_index;
                uint nodes[6];
                for (int i = 0; i < 6; ++i) nodes[i] = start_nodes[i];
                int64_t k = 0;
                while (k < id) {
                    uint offset = 0;
                    if (k + steps3 * steps2 < id) {
                        k += steps3 * steps2;
                        offset = 750 * 3;
                    }
                    else if (k + steps3 * steps < id) {
                        k += steps3 * steps;
                        offset = 750 * 2;
                    }
                    else {
                        k += steps3;
                        offset = 750;
                    }
                    for (int i = 0; i < 6; ++i)
                        nodes[i] = map[offset + nodes[i]] & 0xffffu;
                }
                uint step = 0;
                while (k < id + steps3) {
                    bool found = true;
                    for (int i = 0; i < 6; ++i)
                        found = found && (((goals[nodes[i] >> 5] >> (nodes[i] & 31)) & 1) == 1);
                    if (found) atomicMin(result, k);
                    uint dir = (16 * ((dirs[step >> 5] >> (step & 31)) & 1));
                    for (int i = 0; i < 6; ++i)
                        nodes[i] = (map[nodes[i]] >> dir) & 0xFFFFu;
                    k++;
                    step++;
                    if (step == uint(steps)) step = 0;
                }
            }
            };

        std::cout << "scanning from " << start_index << "\n";

        useShader(run());
        glDispatchCompute(80, 1, 1);

        result = result_buffer;
    }
    std::cout << result[0] << "\n";
    QueryPerformanceCounter(&cpu_end);
    std::cout << "solved in " << (double(cpu_end.QuadPart - cpu_start.QuadPart)/double(freq.QuadPart)*1000.) << "ms\n";

    return 0;
}
