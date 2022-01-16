
#include <vector>
#include "ssgl.h"

int main() {
    OpenGL context(640, 480, "Simple", false, false);
    
    Buffer iota;
    glNamedBufferData(iota, 1024 * 1024 * sizeof(uint32_t), nullptr, GL_STATIC_DRAW);

    auto generator = [&] {
        layout (local_size_x = 256) in;
        buffer bind_block(iota) {
            uint result[];
        };
        void glsl_main() {
            result[gl_GlobalInvocationID.x] = gl_GlobalInvocationID.x;
        }
    };

    useShader(generator());
    glDispatchCompute(1024*4, 1, 1);

    std::vector<uint32_t> result(1024 * 1024);
    glGetNamedBufferSubData(iota, 0, sizeof(uint32_t) * result.size(), result.data());
    for (int i = 0; i<1024*1024; i+=64*1024)
        printf("%u\n", result[i]);
}
