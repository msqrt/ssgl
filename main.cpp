
#include <fstream>
#include <algorithm>
#include <iostream>

#include "ssgl.h"
#include "gl_timing.h"

int main() {
    
    LARGE_INTEGER cpu_start, cpu_end, freq;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&cpu_start);

    std::ifstream file("input.txt");
    std::vector<std::string> lines;
    for (std::string line; std::getline(file, line); lines.push_back(line));
    
    auto extract = [](std::string& s) {
        auto len = s.find(' ');
        if(len == std::string::npos) len = s.length();
        auto result = s.substr(0, len);
        s = s.substr(std::min(s.length(), len+1));
        return std::stoll(result);
    };

    std::vector<i64vec2> seeds;
    lines[0] = lines[0].substr(7);
    while (lines[0].length())
        seeds.push_back({ extract(lines[0]), extract(lines[0]) });
    
    std::vector<i64vec4> ranges;
    for (int i = 1; i < lines.size(); ++i)
        if (lines[i].length() == 0)
            for(auto& r : ranges) { if(r.w == -1) r.w = ranges.size(); }
        else if (!std::isalpha(lines[i][0]))
            ranges.push_back({ extract(lines[i]), extract(lines[i]), extract(lines[i]), -1 });

    std::vector<int64_t> result = {std::numeric_limits<int64_t>::max()};

    OpenGL context(1280, 720, "AoC 2023 Day 5 part 2", false, false);
    
    Buffer seed_buffer(seeds), range_buffer(ranges), result_buffer(result);

    auto run = [&] {
        glsl_extension(GL_NV_shader_atomic_int64, require);
        layout (local_size_x = 1024) in;
        buffer bind_block(seed_buffer) { dynamic_array(i64vec2, seeds); };
        buffer bind_block(range_buffer) { dynamic_array(i64vec4, ranges); };
        buffer bind_block(result_buffer) { int64_t result; };

        shared i64vec2 sseeds[10];
        shared i64vec4 sranges[233];

        void glsl_main() {
            uint lid = gl_LocalInvocationIndex;
            if (lid < 10) sseeds[lid] = seeds[lid];
            if (lid < 233) sranges[lid] = ranges[lid];
            barrier();

            int64_t smallest = result, threads = int64_t(gl_NumWorkGroups.x * gl_WorkGroupSize.x);
            for (int64_t id = int64_t(gl_GlobalInvocationID.x); ; id += threads) {
                int64_t seed = id;
                for (int k = 0; k < seeds.length(); ++k) {
                    if (seed < sseeds[k].y) {
                        seed += sseeds[k].x;
                        break;
                    }
                    else seed -= sseeds[k].y;
                    if(k+1 == seeds.length())
                        seed = -1;
                }
                if(seed < 0) break;

                for (int k = 0; k < ranges.length() && k>=0;) {
                    i64vec4 r = sranges[k];
                    if (seed >= r.y && seed < r.y + r.z) {
                        seed = r.x + seed - r.y;
                        k = int(r.w);
                    }
                    else ++k;
                }
                smallest = min(smallest, seed);
            }

            atomicMin(result, smallest);
        }
    };
    TimeStamp start;

    useShader(run());
    glDispatchCompute(200, 1, 1);

    TimeStamp end;

    result = result_buffer;

    std::cout << result[0] << "\n";
    QueryPerformanceCounter(&cpu_end);

    std::cout << "compute in " << gpuTime(start, end) << "ms\n";
    std::cout << "whole program in " << (double(cpu_end.QuadPart - cpu_start.QuadPart)/double(freq.QuadPart)*1000.) << "ms\n";

    return 0;
}
