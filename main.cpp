
#include "ssgl.h"
#include "gl_timing.h"

glsl_function mat2 get_rotation(float angle) {
    float c = cos(angle), s = sin(angle);
    return mat2(c, s, -s, c);
}

int main() {
    // init OpenGL, create window
    OpenGL context(1280, 720, "Triangle");

    // define some vertices as a CPU array
    struct Vertex { vec2 position; vec3 color; };
    Vertex verts[] = {
        {vec2(.5f, .0f), vec3(1.f, .0f, .0f)},
        {vec2(-.4f, .5f), vec3(.0f, 1.f, .0f)},
        {vec2(-.4f,-.5f), vec3(.0f, .0f, 1.f)}
    };

    // send the vertices to the GPU
    Buffer b; glNamedBufferData(b, sizeof(Vertex) * 3, verts, GL_STATIC_DRAW);
    // set up attributes corresponding to the values
    Attribute<vec2> position(b, sizeof(Vertex), 0);
    Attribute<vec3> color(b, sizeof(Vertex), sizeof(vec2));

    // start timing
    TimeStamp start;

    // while window open and ESC not pressed
    while (loop()) {
        // get time elapsed
        TimeStamp now;
        float t = .001f*(float)cpuTime(start, now);

        // define the shaders
        auto vertex = [&] {
            uniform float bind(t);
            in vec2 bind_attribute(position);
            in vec3 bind_attribute(color);
            out vec3 col;
            void glsl_main() {
                col = color;
                gl_Position = vec4(get_rotation(t)*position.xy*vec2(9.f/16.f,1.f), .0f, 1.f);
            }
        };
        auto fragment = [] {
            in vec3 col;
            out vec3 screen; // no bind, this just draws to the default framebuffer
            void glsl_main() {
                screen = col;
            }
        };

        // set up the shader and draw
        useShader(vertex(), fragment());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // show the frame and clear the screen
        swapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    return 0;
}
