
#include "ssgl.h"
#include "gl_timing.h"
#include "math_helpers.h"

const int N = 64;

glsl_global const bool animate = true, swirl = true, twist = true;

int main() {
    OpenGL context(1920, 1080, "Grass or something");
    TimeStamp start;
    while (loop()) {
        TimeStamp now;
        float t = .001f*(float)cpuTime(start, now);

        mat4 m = perspective(.2f, 1280.f/720.f, .1f, 100.f) * inverse(lookAt(vec3(cos(t), 10.f+sin(t), 10.0f), vec3(.0f)));

        auto vertex = [&] {
            uniform mat4 bind(m);
            uniform int bind(N);
            out vec2 uv;
            out float height;
            void glsl_main() {
                int id = gl_VertexID;
                uv = vec2((id & 1), ((id + 2) % 6) / 3)*4.f-2.f;
                height = float(id / 6) / N;
                vec3 pos = vec3(uv, .3f*height).xzy;
                gl_Position = m * vec4(pos, 1.f);
            }
        };

        auto fragment = [&] {
            in vec2 uv;
            in float height;
            uniform float bind(t);
            out vec3 screen;
            void glsl_main() {
                vec3 pos = vec3(uv, height).xzy;
                vec2 wind_dir = vec2(-3.f, -3.f);
                srnd(0);
                if(animate && swirl) {
                    for (int i = 0; i < 3; ++i) {
                        float a = rnd()*2.f*pi;
                        vec2 p = mat2(cos(a), sin(a), -sin(a), cos(a))*pos.xz;
                        wind_dir += (.5f + .5f * rnd()) * vec2(cos(p.x*2.f+t*.1f), sin(p.y*4.-t*.1f));
                    }
                }
                float a = .2f*pow(height, 1.5f)*pow(.5f+.45f*sin(dot(wind_dir, pos.xz) - t * 4.f), 1.5f);
                if(animate) {
                    pos.y += a;
                    pos.xz += normalize(vec2(1.f))*a;
                }
                if (twist) {
                    srnd(1);
                    for (int i = 0; i < 3; ++i) {
                        float a = rnd() * 2.f * pi + pos.y*.1f;
                        vec2 p = mat2(cos(a), sin(a), -sin(a), cos(a)) * pos.xz;
                        pos.xz += pow(pos.y, 1.5f)*.02*(.5f + .5f * rnd()) * vec2(cos(p.x * 20.f), sin(p.y * 30.));
                    }
                }
                vec2 cell = floor(pos.xz*80.f);
                srnd(floatBitsToUint(cell.x+90.f)+19*floatBitsToUint(cell.y+100.f)); rnd();
                float thick = pow(rnd() * .5f + .5f, 4.f) - length(vec2(pos.y, a*(animate?4.f:.0f)));
                if(thick>.0f) thick += .6f;
                if(length(fract(pos.xz*80.f)-.5f+vec2(rnd(), rnd())-.5f)>.8f*thick || length(fract(cell*.003f+.5f)-.5f)>.4f) discard;
                screen = mix(vec3(.01f, .1f, .15f), vec3(.3f, .8f, .4f), height)*(rnd()*.2f+.8f);
            }
        };

        useShader(vertex(), fragment());
        glDrawArrays(GL_TRIANGLES, 0, 6*N);

        swapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    return 0;
}
