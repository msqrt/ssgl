
#include "ssgl.h"
#include "gl_timing.h"

int main() {
    OpenGL context(1280, 720, "Triangle");

    struct Vertex { vec3 position, color; };
    Vertex verts[] = {
        {vec3(.5f, .0f, .0f), vec3(1.f, .0f, .0f)},
        {vec3(-.5f, .5f, .0f), vec3(.0f, 1.f, .0f)},
        {vec3(-.5f,-.5f, .0f), vec3(.0f, .0f, 1.f)}
    };

    Buffer b; glNamedBufferData(b, sizeof(Vertex) * 3, verts, GL_STATIC_DRAW);
    Attribute<vec3> position(b, sizeof(Vertex), 0), color(b, sizeof(Vertex), sizeof(vec3));

    TimeStamp start;
    while (loop()) {
        TimeStamp now;
        float t = .001f*(float)cpuTime(start, now);

        auto vert = [&] {
            out vec3 col;
            uniform float bind(t);
            in vec3 bind_attribute(position, color);
            void glsl_main() {
                col = color;
                float c = cos(t), s = sin(t);
                gl_Position = vec4(mat2(c,s,-s,c)*position.xy*vec2(9.f/16.f,1.f), position.z, 1.f);
            }
        };
        auto frag = [] {
            in vec3 col;
            out vec3 screen;
            void glsl_main() {
                screen = col;
            }
        };

        useShader(vert(), frag());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        swapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    return 0;
}
