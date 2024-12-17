
#include <fstream>
#include <algorithm>
#include <iostream>

#include "ssgl.h"
#include "gl_timing.h"

glsl_global const uint64_t per_iter = uint64_t(10000) * uint64_t(100000);

int main() {

    LARGE_INTEGER cpu_start, cpu_end, freq;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&cpu_start);

    OpenGL context(1280, 720, "AoC 2024 Day 17 Part 2", false, false);

    std::vector<uint64_t> result = { uint64_t(-1) };
    Buffer result_buffer(result);
    uint64_t offset = 0, end = per_iter, program = 235006351742932;

    do {

        auto run = [&] {
            glsl_extension(GL_NV_shader_atomic_int64, require);
            layout(local_size_x = 512) in;
            uniform uint64_t bind(offset, end, program);
            buffer bind_block(result_buffer) { uint64_t result; };

            void glsl_main() {
                for (uint64_t i = gl_GlobalInvocationID.x + offset; i < end; i += gl_NumWorkGroups.x * gl_WorkGroupSize.x) {
                    uint64_t A = i;
                    uint64_t target = program;
                    while (true) {
                        uint B = (uint(A) & 7u) ^ 5u;
                        B = (uint(A) >> B) ^ B;
                        if (((B ^ target) & 7u) != 0) break;
                        A >>= 3u;
                        target >>= 3u;
                        if (target == 0u) atomicMin(result, i);
                    }
                }
            }
            };

        useShader(run());
        TimeStamp before;
        glDispatchCompute(1111, 1, 1);
        TimeStamp after;

        result = result_buffer;
        offset += per_iter;
        end += per_iter;
    } while (result[0] == uint64_t(-1));

    QueryPerformanceCounter(&cpu_end);

    std::cout << result[0] << "\n";
    std::cout << "solved in " << (double(cpu_end.QuadPart - cpu_start.QuadPart) / double(freq.QuadPart)) << "s\n";

    return 0;
}
