### single source gl
single source gl (ssgl) aims to make shader development smoother by letting you write GLSL shaders as lambdas within a host C++ program. This brings shaders right next to the code that calls them and lets you edit them like any C++ code: with intellisense, auto-complete, syntax highlighting, and so on. On top of that, the shaders are hot reloadable to enable interactive editing. The approach also makes it possible to automatically set up all shader inputs and outputs such as uniforms and framebuffer targets by simply declaring them using a `bind` macro, significantly shortening the host code per drawcall. In addition, the GLSL vector and matrix types are available in the host side and functions outside the shader body are supported, so you can write code once and call it both on the CPU and the GPU.

To illustrate, the following example is a complete program that defines a compute shader and uses it to fill a buffer like `std::iota` would on the CPU side.
```C++
#include <vector>
#include "ssgl.h"

int main() {
    OpenGL context(640, 480, "Simple", false, false);
    
    Buffer iota;
    glNamedBufferData(iota, 1024 * 1024 * sizeof(uint32_t), nullptr, GL_STATIC_DRAW);

    auto generator = [&] {
        layout (local_size_x = 256) in;
        buffer bind_block(iota) {
            dynamic_array(uint, result);
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
```
