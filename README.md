# single source gl

single source gl (ssgl) lets you prototype GLSL shaders as C++ lambdas that automatically capture shader inputs and outputs. This unifies code, brings powerful C++ tools into shader development, and removes code that just passes objects around. All of this makes it extremely fast to try out ideas and iterate on them.

To illustrate, the following is a program that uses a compute shader to fill a buffer with a running count. Note how the whole program sits in a single file, and how calling `useShader` is all that's required to set up the drawcall. The shader is the lambda `fill`, and the main body of the shader is in `glsl_main`. `useShader` sets up the program and binds the buffer as instructed by the `bind_block` macro.
```C++
#include <vector>
#include "ssgl.h"

int main() {
    // init OpenGL
    OpenGL context(640, 480, "iota_example", false, false);
    
    // reserve space
    Buffer iota;
    glNamedBufferData(iota, 1024 * 1024 * sizeof(uint32_t), nullptr, GL_STATIC_DRAW);
    
    // the shader itself
    auto fill = [&] {
        layout (local_size_x = 256) in;
        buffer bind_block(iota) {
            dynamic_array(uint, result); // replacement for "uint result[];"
        };
        void glsl_main() {
            result[gl_GlobalInvocationID.x] = gl_GlobalInvocationID.x;
        }
    };
    
    // call the shader
    useShader(fill());
    glDispatchCompute(1024*4, 1, 1);
    
    // display results
    std::vector<uint32_t> result(1024 * 1024);
    glGetNamedBufferSubData(iota, 0, sizeof(uint32_t) * result.size(), result.data());
    for (int i = 0; i<1024*1024; i+=64*1024)
        printf("%u\n", result[i]);
}
```

The project aims to make shader development smoother with this injection of GLSL into C++. There are several factors that go into this:
* shaders are brought right next to the code that calls them
* shaders can be edited like any C++ code: with intellisense, auto-complete, syntax highlighting, and so on
* shaders are hot reloadable so interactive editing is possible
* shader inputs and outputs such as uniforms and framebuffer targets are automatically captured, removing a bunch of supporting code
* the GLSL vector and matrix types are available on the host side
* free functions can be called from shader code; you can implement functions once and call them both on the CPU and the GPU
* no custom extensions are required, thus all major compilers are supported (tested on MSVC, GCC, and clang)

Since the code is C++ under the hood, IDE features like Intellisense work properly with shaders. This efficiently prevents making trivial type or syntax mistakes, as they're caught already while writing the code:

![](https://i.imgur.com/QnwMIau.png)

To be clear, the project is **not** about adding C++ features to shaders, or being able to run shaders on the CPU (even though the latter is possible to an extent). All of the shader code will be standard GLSL and run on the GPU. The point is that GLSL now sits within C++, improving the development experience by making shaders nicer to write and reducing the need for uninteresting code.

The project is written against C++17 and OpenGL 4.6. The C++17 features are strictly necessary, but OpenGL could be ported back at least to 3.0 -- the main hurdle would be to convert all DSA code to the old model.

The implementation is split into two folders: `impl` contains everything you need for the library to work, and that's all you need if you want to use your own windowing/OpenGL environment. `utils` contains some extra helpers and a sample windowing/GL extension loading system to keep the repository self-contained. On Linux, this windowing system requires GLFW 3.

## examples

Let's look at a few usage examples in more detail. This is not a tutorial on C++, GPU programming, or graphics, so a certain level of proficiency in each is expected. The interest is not in what we compute, but how we do it. Focusing on form over function here will let you do the opposite in your actual projects.

### simple compute shader

![](https://user-images.githubusercontent.com/1880715/150009227-71b83b32-0033-4e7b-aa08-79465e41e135.png)

We'll first go through the simple compute shader already shown above. There are more comments this time around; all crucial information is there, but some things are further explained below.

```C++
#include <vector>
 // include ssgl.h last; it defines many iffy macros that will break some other headers
#include "ssgl.h"

int main() {
    
    // an OpenGL object creates and stores a window and its OpenGL context;
    // after it goes out of scope, OpenGL is released and the window destroyed.
    OpenGL context(640, 480, "iota_example", false, false);
    
    // a Buffer creates and stores an OpenGL buffer object
    // it's basically a std::unique_ptr but for an OpenGL object instead of system memory
    Buffer iota;

    // the Buffer is implicitly castable to GLuint so you can use it with OpenGL functions
    glNamedBufferData(iota, 1024 * 1024 * sizeof(uint32_t), nullptr, GL_STATIC_DRAW);
    
    // the shader itself : do remember to capture everything with the &!
    auto fill = [&] {

        // this scope is the global scope of the shader; nothing can be executed here.
        // instead, here we declare inputs, outputs, and parameters of the shader

        // first, since this is a compute shader, we define the local workgroup size:
        layout (local_size_x = 256) in; // (this is standard GLSL syntax)
        
        // SSBOs and UBOs are bound using "bind_block", as their contents are defined
        // in a block following the declaration. bind_block takes the Buffer object
        // with the same name ("iota") from the scope above and passes it to the shader
        buffer bind_block(iota) {
            // the GLSL dynamic array syntax ("uint result[];") is not legal C++ here.
            // so we define dynamic arrays like this instead:
            dynamic_array(uint, result);
        };

        // we already have a main in C++, so we'll use "glsl_main" as the GLSL entry point
        void glsl_main() {
            // this is where the GPU will start running our code!

            // for this example, we'll write the index of the current thread to the array.
            // GLSL programs can be arbitrarily complex, this is just for the sake of brevity
            result[gl_GlobalInvocationID.x] = gl_GlobalInvocationID.x;
        }
    };
    
    // useShader sets our shader as the current shader and binds all of the required objects
    useShader(fill()); // note that we're *calling* the lambda here, not just passing it in!

    // this is the actual call to the shader. the arguments give the global size;
    // the local size is defined in the shader and all other arguments are handled by useShader
    glDispatchCompute(1024*4, 1, 1);
    
    // display results to check that something actually happened
    std::vector<uint32_t> result(1024 * 1024);
    glGetNamedBufferSubData(iota, 0, sizeof(uint32_t) * result.size(), result.data());
    for (int i = 0; i<1024*1024; i+=64*1024)
        printf("%u\n", result[i]);
}
```

Another rationale for `dynamic_array` is that C++ flexible arrays don't have the `.length()` member that GLSL dynamic arrays do. In this example, you could call `result.length()` in the shader, but there's no way to make this work if we just wrote `uint result[];`. The GLSL syntax also doesn't compile under GCC, as the implementation of `bind_block` actually introduces the block as a union.

If you wish to edit properties of the shader manually, you can do so between `useShader()` and your draw call.

You should **not** store the `Shader` object returned by a shader lambda: call the lambda every time you call `useShader()`. The values of the binds are updated by calling the lambda, so using the old `Shader` might mess things up when objects change names or names change objects.


### rotating rgb triangle

![](https://user-images.githubusercontent.com/1880715/150008489-79662388-f997-4f29-b10a-48279413fc9b.png)

This one is a classic OpenGL example. We'll use it to illustrate how vertex attributes and uniforms work.

```C++
#include "ssgl.h"
// the headers in this repo are built to respect ssgl.h, so order doesn't matter
#include "gl_timing.h"

// we use the keyword "glsl_function" to define global functions with GLSL support.
// necessary C++ keywords and specifiers can be placed before "glsl_function"
inline glsl_function mat2 get_rotation(float angle) {
    // get a 2D rotation matrix based on an angle (in radians)
    float c = cos(angle), s = sin(angle);
    return mat2(c, s, -s, c);
}

int main() {
    // init OpenGL, create window
    OpenGL context(1280, 720, "Triangle");

    // define some vertices as a CPU-side array
    struct Vertex { vec2 position; vec3 color; };
    Vertex verts[] = {
        {vec2(.5f, .0f), vec3(1.f, .0f, .0f)},
        {vec2(-.4f, .5f), vec3(.0f, 1.f, .0f)},
        {vec2(-.4f,-.5f), vec3(.0f, .0f, 1.f)}
    };

    // send the vertices array to the GPU
    Buffer b; glNamedBufferData(b, sizeof(Vertex) * 3, verts, GL_STATIC_DRAW);

    // set up attributes corresponding to the values. these are wrapper objects that act
    // as a view to the given Buffer; the arguments mostly match those of glVertexAttribPointer:
    // (buffer, stride, offset=0, type=-1, normalized=false), where typically stride is the size
    // of the vertex and offset is how many bytes into the struct the corresponding field is.
    // the template argument of Attribute is the desired shader-side type; if this doesn't match
    // the data in the buffer (say, your data is uint8_t), you can manually override the type.
    Attribute<vec2> position(b, sizeof(Vertex), 0);
    Attribute<vec3> color(b, sizeof(Vertex), sizeof(vec2));

    // stores both CPU- and GPU-side timing events (has some overhead, but OK for prototyping)
    TimeStamp start;

    // loop() is true while the window is open and ESC has not been pressed
    while (loop()) {
        TimeStamp now;
        // cpuTime() gets time in milliseconds between two stamps
        // gpuTime() would get total render operation time between the stamps
        float t = .001f*(float)cpuTime(start, now);

        // define the shaders
        auto vertex = [&] {
            // uniforms are bound with bind(name), this means basic types (including vec* and mat*)
            // and textures/images which are bound as uniforms
            uniform float bind(t);
            // attributes are bound with bind_attribute; note that you don't bind the buffer directly!
            in vec2 bind_attribute(position); // these do type checking; try changing the type to float
            in vec3 bind_attribute(color);
            out vec3 col;
            void glsl_main() {
                col = color;
                
                // shaders are hot reloadable!
                // try changing "t" to "0.5f*t" or "-t" and saving the file while the program is running
                float angle = t;

                // here we call get_rotation() defined in the beginning
                vec2 pos = get_rotation(angle)*position.xy;
                
                // GLSL's built-in variables are pre-defined
                gl_Position = vec4(pos*vec2(9.f/16.f,1.f), .0f, 1.f);
            }
        };
        auto fragment = [&] {
            in vec3 col;
            // screen is a special texture output that writes to the window sufrace.
            out vec3 bind_target(screen);
            void glsl_main() {
                // just output the interpolated value
                screen = col;
            }
        };

        // set up the shader and draw
        useShader(vertex(), fragment());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // show the frame on the screen
        swapBuffers();
        // clear the screen for the next iteration
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
```

Crucially, there are no Vertex Array Objects (VAO) or Framebuffer Objects (FBO). The only extra abstraction for turning a buffer into a vertex attribute is the `Attribute` class that defines where the attribute values are to be read from, and rendering into textures is performed by binding the desired texture directly without an intermediate object. Here we only drew to the screen which requires no FBOs in standard GL either, but rendering to textures in ssgl looks exactly the same (see the next example). Naturally VAOs and FBOs exist behind the scenes, as OpenGL requires them to be used. Automating their use can incur a performance cost, as it reduces the opportunities to reuse objects and avoid state changes. Still, the uplift in convenience is difficult to overstate. Moreover, the present goal of the library is more in prototyping than large scale development, so the choice is clear.

Also notice how we use `f` postfixes for `float`s like C++ and unlike GLSL. They get removed before compiling the shader so no GLSL compiler gets confused. It's not strictly necessary but good practice to use the `f`s, since it keeps the C++ compiler from emitting loads of warnings about conversions between `float` and `double`.

### Simple global illumination and subsurface scattering

![image](https://user-images.githubusercontent.com/1880715/151415036-80650b16-c8c0-4229-ad4f-9f2407a14e93.png)

This is a slightly more complicated example that lets us explore the rest of the key features in ssgl. The basic gist is we define some geometry procedurally and use [reflective shadow maps](http://www.klayge.org/material/3_12/GI/rsm.pdf) and [depth map based absorption](https://developer.download.nvidia.com/books/HTML/gpugems/gpugems_ch16.html) to light it nicely. The graphics techniques aren't the point here and will only be skimmed over, the key thing is in rendering to multiple targets simultaneously and using the results in a second pass.

```C++
#include "ssgl.h"
#include "gl_timing.h"
#include "math_helpers.h" // for pi, perspective(), lookat(), and rnd()

// glsl_global is equivalent to glsl_function but for variables.
glsl_global vec3 ldir = normalize(vec3(1.f, 2.f, 1.f));

int main() {
    // init OpenGL, create window
    OpenGL context(1280, 720, "Cubes");
    glEnable(GL_CULL_FACE); glEnable(GL_DEPTH_TEST);

    // create a vertex attribute and index list for a cube
    vec3 verts[8];
    for (int i = 0; i < 8; ++i)
        verts[i] = vec3(i & 1, (i/2)&1, (i/4)&1)*2.f - 1.f;
    uvec3 inds[] = {
        {0,2,1}, {1,2,3}, {0,4,2}, {2,4,6}, {0,1,4}, {4,1,5},
        {2,6,3}, {3,6,7}, {1,3,5}, {5,3,7}, {4,5,6}, {6,5,7}
    };

    Buffer vertexBuffer, indexBuffer;
    glNamedBufferData(vertexBuffer, sizeof(verts), verts, GL_STATIC_DRAW);
    glNamedBufferData(indexBuffer, sizeof(inds), inds, GL_STATIC_DRAW);
    Attribute<vec3> position(vertexBuffer, sizeof(vec3), 0);

    // create textures to render to. for reflective shadow maps we need to have an
    // enriched shadow map with normal and color information.
    Texture<GL_TEXTURE_2D> color, normal, depth;
    glTextureStorage2D(color, 1, GL_RGB32F, 2048, 2048);
    glTextureStorage2D(normal, 1, GL_RGB32F, 2048, 2048);
    glTextureStorage2D(depth, 1, GL_DEPTH24_STENCIL8, 2048, 2048);

    // start timing
    TimeStamp start;

    int instances = 800;

    // while window open and ESC not pressed
    while (loop()) {
        // get elapsed time
        TimeStamp now;
        float t = .00005f*(float)cpuTime(start, now);

        // compute matrices to transform between world, camera, and light spaces
        mat4 cameraToWorld = lookAt(vec3(cos(t), .4f, sin(t))*12.f, vec3(.0f));
        mat4 worldToClip = perspective(.5f, 16.f/9.f, .1f, 30.f) * inverse(cameraToWorld);
        mat4 worldToLight = ortho(12.f, 1.f, -7.f, 7.f) * inverse(lookAt(ldir, vec3(.0f)));

        // this vertex shader will be used for both the shadow map and the final pass,
        // but with different matrices; for this to work, we have to rename the input
        // by passing it as an argument. as the shaders themselves can only capture
        // inputs, we need to introduce an extra scope, here done by wrapping the shader
        // in an outer generator lambda.
        auto vertex = [&](mat4 matrix) {
            return [&] {
                uniform float bind(t);
                uniform mat4 bind(matrix);
                in vec3 bind_attribute(position);
                out vec3 col, p;

                // a local function is introduced using the glsl_func() macro.
                // local functions are useful as they automatically get access to uniforms
                // and such, unlike global functions, like gl_InstanceID here.
                // the "arg_out" macro corresponds to "out vec3" and "vec3&".
                // "arg_inout" and "arg_in" are also available.
                vec3 glsl_func(get_position)(vec3 p, arg_out(vec3) col, float t) {
                    // this function repositions a bunch of cubes to generate the scene
                    if (gl_InstanceID == 0) {
                        p = vec3(p.x*4.f, -1.f + p.y * .1f, p.z*4.f);
                        col = vec3(.8f);
                    }
                    else {
                        srnd(gl_InstanceID);
                        float angle = rnd() * 2.f * pi + t * 10.f;
                        float c = cos(angle), s = sin(angle);
                        p.xy = p.xy*.05f + vec2(2.f + rnd(),.0f);
                        mat3 B = basis(normalize(vec3(rnd() - .5f, 2.f, rnd() - .5f)));
                        p.xyz = mat3(B[1], B[2], B[0]) * mat3(c, .0f, s, .0f, 1.f, .0f, -s, .0f, c) * p.xyz;
                        col = mix(vec3(.2f, .1f, .05f), vec3(.8f, .4f, .1f), rnd());
                    }
                    return p;
                }; // <-- since glsl_func() maps to a lambda under the hood, we need a semicolon here!

                void glsl_main() {
                    p = get_position(position, col, t);
                    gl_Position = matrix * vec4(p, 1.f);
                }
            }();
        };
        // the first fragment shader will populate the shadow maps (with color+normal instead of just depth)
        auto lightFragment = [&] {
            // it's up to the user to make sure that the render target sizes match;
            // viewport will be set to (0,0,w,h) automatically.
            out vec3 bind_target(color, normal);
            out float bind_depth(depth); // we could also write to depth manually, but this is not necessary
            in vec3 col, p;
            void glsl_main() {
                // just write the outputs
                color = col;
                normal = normalize(cross(dFdx(p), dFdy(p)));
            }
        };

        // set up the shader and draw
        useShader(vertex(worldToLight), lightFragment());
        // here's the time to setup extra stuff like an index buffer:
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
        // useShader() binds the targets so we can clear them here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // glViewport(...) // we can set the viewport manually here if desired
        
        glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, instances);

        // actually draw to the screen
        auto fragment = [&] {
            uniform mat4 bind(worldToLight);
            uniform float bind(t);
            in vec3 col, p;
            // samplers are bound just like any uniform
            // remember, depth is in the x channel only.
            uniform sampler2D bind(color, normal, depth);

            // if we don't bind the output, we always write to the screen and can choose any variable name.
            out vec3 out_color;

            void glsl_main() {
                vec3 n = normalize(cross(dFdx(p), dFdy(p)));

                // compute the light space coordinate of our screen fragment
                vec4 lNDC = worldToLight * vec4(p, 1.f);
                lNDC.xyz = (lNDC.xyz/lNDC.w)*.5f+.5f;

                float shadow = .0f;
                vec3 scatter = vec3(.0f);

                // a different seed for each pixel every frame
                srnd(uint(gl_FragCoord.x) + 1280 * uint(gl_FragCoord.y) + floatBitsToUint(t));

                // loop for shadow filtering and the shadow map based subsurface scattering
                for (int i = 0; i < 8; ++i) {
                    vec2 jitter = (vec2(rnd(), rnd()) - .5f) / vec2(textureSize(depth, 0))*2.f;
                    // difference between shadow map and current fragment depth from the light
                    float penetration = texture(depth, lNDC.xy + jitter).x - lNDC.z;
                    // shadow mapping
                    if (penetration > -.001f)
                        shadow += 1.f;
                    // scattering
                    if (col.b < .2f) {
                        float irradiance = max(.0f, dot(texture(normal, lNDC.xy + jitter).xyz, ldir));
                        vec3 optical_length = 60.f * penetration / texture(color, lNDC.xy + jitter).xyz;
                        scatter += .2f * col * irradiance * exp(min(vec3(.0f), optical_length));
                    }
                }
                shadow /= 8.f;
                scatter /= 8.f;

                // reflective shadow mapping: each shadow map texel is treated as a virtual point light (VPL) and
                // the total contribution of all VPLs is stochastically evaluated by taking the average
                // of the colors of a set of random trials. to simplify things, we don't care if the current
                // fragment and the VPL are actually mutually visible or not
                vec3 indirect = vec3(.0f);
                for (int i = 0; i < 16; ++i) {
                    // pick a texel
                    float angle = rnd() * 2.f * pi;
                    vec2 offset = lNDC.xy+vec2(cos(angle), sin(angle)) * sqrt(float(i) + rnd())*.02f;

                    // backproject the VPL location
                    vec4 vpl_pos = inverse(worldToLight)*vec4(offset*2.f-1.f, texture(depth, offset).x*2.f-1.f, 1.0f);
                    vpl_pos.xyz /= vpl_pos.w;
                    vec3 diff = p - vpl_pos.xyz;

                    // read normal and color of VPL
                    vec3 vpl_normal = texture(normal, offset).xyz;
                    vec3 vpl_col = texture(color, offset).xyz;
                    
                    // limit the normalization factor to avoid bright splotches
                    float lensq = max(dot(diff, diff), .4f);

                    // the geometric term between the VPL and the receiver
                    diff = normalize(diff);
                    float G = max(.0f, dot(-diff, n)) * max(.0f, dot(diff, vpl_normal)) / lensq;
                    indirect += col * vpl_col * G;
                }
                indirect /= 16.f;

                vec3 direct = shadow * col * max(.0f, dot(n, ldir));
                out_color = direct + indirect + scatter;
            }
        };

        // set up the shader and draw
        useShader(vertex(worldToClip), fragment());
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
        glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, instances);

        // show the frame and clear the screen
        swapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
```

That's it! The tour is over; that's how you use ssgl. Towards the bottom of this document is a reference with slightly longer explanations and a couple of more obscure features that we skipped.

### Shadertoy adapter

![image](https://user-images.githubusercontent.com/1880715/151568002-1718ca77-b7f1-49c8-870a-7580c63d669f.png)

Just for fun, here's a snippet that lets you run most [Shadertoys](https://www.shadertoy.com/) in ssgl, you just need to prepend functions and globals with `glsl_function` and `glsl_global`. Be wary that the more esoteric syntax that some Shadertoys contain (passing swizzles as inout parameters, swizzling the result of a `*=` operation, using #defines inside a function, ...) might need to be simplified a bit.

Note that this makes the `mainImage` function a standard C++ function that you can call (and **debug**) on the CPU!

```C++
#include "ssgl.h"
#include "gl_timing.h"

glsl_global vec3      iResolution;           // viewport resolution (in pixels)
glsl_global float     iTime;                 // shader playback time (in seconds)
glsl_global float     iTimeDelta;            // render time (in seconds)
glsl_global int       iFrame;                // shader playback frame
glsl_global vec4      iMouse;                // mouse pixel coords. xy: current (if MLB down), zw: click (actually spacebar)

// shadertoy goes here:
glsl_function void mainImage(out vec4 fragColor, in vec2 fragCoord)
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord / iResolution.xy;

    // Time varying pixel color
    vec3 col = 0.5 + 0.5 * cos(iTime + uv.xyx + vec3(0, 2, 4));

    // Output to screen
    fragColor = vec4(col, 1.0);
}

int main() {
    // init OpenGL, create window
    OpenGL context(1280, 720, "Shadertoy");

    // start timing
    TimeStamp start;
    
    int frame = 0;
    float old_t = .0f;
    // while window open and ESC not pressed
    while (loop()) {
        frame++;
        // get elapsed time
        TimeStamp now;
        float t = .001f*(float)cpuTime(start, now);
        float dt = t - old_t;
        old_t = t;

        // generate a triangle large enough to cover the screen
        auto vertex = [&] {
            void glsl_main() {
                gl_Position = vec4(gl_VertexID == 0 ? 4.f : -1.0f, gl_VertexID == 1 ? 4.f : -1.0f, .5f, 1.f);
            }
        };

        ivec2 resolution = windowSize();
        ivec4 mouse = ivec4(getMouse(), keyDown(VK_SPACE), keyHit(VK_SPACE));
        
        // just pass everything along to mainImage()
        auto fragment = [&] {
            out vec3 screen;
            uniform float bind(t, dt);
            uniform ivec2 bind(resolution);
            uniform ivec4 bind(mouse);
            uniform int bind(frame);

            void glsl_main() {
                iResolution.xy = vec2(resolution);
                iTime = t;
                iTimeDelta = dt;
                iMouse = vec4(mouse);
                iFrame = frame;
                vec4 color;
                mainImage(color, gl_FragCoord.xy);
                screen = color.rgb;
            }
        };

        // set up the shader and draw
        useShader(vertex(), fragment());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // show the frame and clear the screen
        swapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
```

## reference

This is a listing of all the types and macros in single source gl.

### bind macros

The `bind` macros significantly reduce boiler plate code around drawcalls.

```C++
bind(uniform_1, uniform_2, ...)
uniform float bind(a, b, c);

bind_attribute(attribute_1, attribute_2, ...)
in vec3 bind_attribute(a, b, c);

bind_target(target_1, target_2, ...)
out vec4 bind_target(a, b, c);

bind_depth(depth_map)
out float bind_depth(shadow_map);

bind_block(b)
buffer bind_block(buff) { /*SSBO contents*/ };
uniform bind_block(buff) { /*UBO contents*/ };
```

The `bind` macro family is the main difference in single source gl to typical shader programming. Instead of declaring values to be passed directly, we'll use the corresponding macro: `bind` for uniforms, `bind_attribute` for vertex attributes, `bind_target` for render targets, `bind_depth` for depth maps, and `bind_block` for SSBOs and UBOs. These take the object or value in the scope above and pass it to the shader **with the same name**, so there's no need to specify any indices or explicitly match objects to their names. The implementation relies on variable shadowing to produce a correctly typed local object; as such, you cannot just pass the object as a differently named argument. If you wish to call the same shader with multiple objects, you should place it in a function where the argument name is used as the name of the object:

```C++
Shader wrapper(Buffer b) {
    return [&] {
        buffer bind_block(b) {/*whatever b contains*/};
        void glsl_main() {/*whatever you wanted to do with b*/}
    }();
}
```
which can now be set as the current shader with `useShader(wrapper(any_buffer))`, where `any_buffer` can indeed be any buffer you want. `wrapper` could also be a lambda. In fact, you could just add a redundant extra scope to your original shader function, but this looks somewhat confusing.

Note that some of the `bind` macros can take multiple arguments: this is purely a convenience feature, you can also declare each (for example) uniform in its own statement. As usual, to be able to declare the objects on the same line, they'll need to be of the same type.

```C++
dynamic_array(type, name)
```
Since flexible arrays inside unions are not valid C++, an SSBO can't contain an array of the form `type name[]`; this GLSL construct is replaced by this macro. With some compilers you can use the GLSL syntax, but this doesn't let you query the length of the array; using `dynamic_array(type, name)` you can call `name.length()` in the shader, just as you typically would in GLSL.

### global values and functions

single source gl also lets you use functions and variables declared outside of the shader scope.

```C++
glsl_function
inline glsl_function float test() {return .0f;}
glsl_global
static glsl_global uint random_seed = 0;
```

These two are straight forward, but very useful. `glsl_function` lets you write a function in the global scope, and makes it visible to both CPU and GPU side code. The system also supports includes, so you can place your functions in a header. Note that any specifiers before `glsl_function` are ignored, as the `inline` in the example above. `glsl_global` is basically the same, but introduces variables instead of functions. This is useful for global values such as mathematical constants and state required by global functions (GLSL doesn't have a static keyword, so for example random seeds have to be stored this way.)

```C++
return_type glsl_func(name)(arguments) {/*function body*/};
float glsl_func(twice)(float x) {return 2.f * x;};
```

`glsl_func` is almost the same as `glsl_function`, but is for functions inside the shader body. Since C++ doesn't support local functions, this actually maps to a lambda; notice the necessary semicolon after the function body. This is most convenient when you want to, for example, read from an SSBO in a specific way multiple times and want to wrap the read in a function -- you can't pass an SSBO to a function in GLSL and you won't have access to one on the global scope, so a local function is necessary. (Note that actually reading from an SSBO in a `glsl_func` requires the newest version of VS2022 and compiling as c++20, older ones will give an "internal compiler error"; other compilers are fine with it.)

```C++
arg_in(type)
arg_out(type)
arg_inout(type)
glsl_function void test(arg_in(float) a, arg_out(int) b, arg_inout(mat4) c) {}
```

These macros are used to wrap `out` and `inout` argument types for `glsl_function`s and `glsl_func`s; `arg_in` should not be necessary but is provided for completeness' sake. This form is required to allow using proper out/inout arguments on both the CPU and the GPU.

### wrapper types

```C++
struct OpenGL;
Opengl(width, height, title, fullscreen, show);
```
`OpenGL` is a RAII wrapper for an OpenGL context; constructing the object opens a context and makes it current, and . The constructor takes the parameters of the window: its size and title, if it's fullscreen, and if it should be shown at all. The last option is to support CLI programs where you don't want a window at all.

```C++
struct Buffer;
template<GLenum target> struct Texture;
```

`Buffer` and `Texture` are RAII wrappers for OpenGL buffers and textures. They store a single object at a time and destroy it when the lifetime ends (similar to `unique_ptr`), or the object is replaced. The object is automatically constructed if no arguments are given, and the objects are implicitly convertible to their underlying GLuint values; so for example, you can pass a `Buffer` to `glNamedBufferStorage` to set up its storage. The type is also used to deduce bindings, so using these classes is required for the shader system to work. If you wish to track your lifetimes manually or with some other system, you can construct a non-owning `Buffer` or `Texture` by just passing the `GLuint` to the constructor (or the `GLuint` and `true` to pass ownership to the class). The `target` in `Texture` refers to the texture target (such as `GL_TEXTURE_2D`) -- to write a generic function that can take in any type, you should use `Texture<>` which stores the target dynamically.

```C++
template<GLenum target>
Texture<> Level(const Texture<target>& t, int level);
template<GLenum target>
Texture<> Layer(const Texture<target>& t, int layer);
```

`Level` and `Layer` take the MIP level or the 2D layer of the given `Texture`, and return a corresponding dynamically-targeted texture. This is so it's possible to write a shader that operates on a 2D texture, and pass in a specific MIP level or a layer of a 3D texture.

```C++
template<typename T>
struct Attribute;
// to construct:
Attribute(const Buffer& b, int stride, int offset = 0, GLuint type = -1, bool normalized = false)
```

`Attribute` is an adapter for vertex buffers: it's where you define how the buffer is read to produce vertex inputs. The template argument `T` is the shader-side type of the attribute. The only things you can do with `Attribute` instances are construct them and bind them to shaders. In the constructor you specify the buffer to be read, and all of the information typically given to `glVertexAttribPointer`. The type of the attribute is typically determined by the template argument, but for example a vec3 attribute can be backed up by `GL_BYTE` data, so you can also give the type manually.

### misc

```C++
void useShader(const Shader& compute);
void useShader(const Shader& vertex, const Shader& fragment);
void useShader(const Shader& vertex, const Shader& geometry, const Shader& fragment);
void useShader(const Shader& vertex, const Shader& control, const Shader& evaluation, const Shader& fragment);
void useShader(const Shader& vertex, const Shader& geometry, const Shader& control, const Shader& evaluation, const Shader& fragment);
```
`useShader` basically replaces `glUseProgram()` and most of the binding code. You give it the shaders corresponding to the shader stages you require. The OpenGL side shader programs themselves are cached, so compilation only happens on the first call to that specific combination of shaders.

```C++
bool loop();
void swapBuffers();
void setTitle(const char* title);
void showWindow();
void hideWindow();

bool keyDown(uint vk_code);
bool keyHit(uint vk_code);
void resetHits();

ivec2 getMouse();
void setMouse(ivec2);

ivec2 windowSize();
```
These functions manage the window. Calling them might do something weird if there's no OpenGL context active. Going in order, `loop()` handles window messages and returns false if the program should quit (so your default main loop should be `while(loop())`). `swapBuffers()` presents the rendered frame from the default framebuffer on the screen. `setTitle()` changes the window title. `showWindow()` and `hideWindow()` make the window appear and disappear. `keyDown()` returns if the given key is currently held down, and `keyHit()` if it's been pressed down during this frame. `resetHits()` (automatically called by `loop()`) resets key hit status. `getMouse()` gets screen-relative mouse location in pixels (origin is top left of the window, x is to the right and y is down). `setMouse()` warps the pointer to the desired pixel (coordinates match `getMouse()`). `windowSize()` gets the current window resolution.

```C++
glsl_extension(name, behavior)
glsl_version(version)
```

These macros are used inside a shader to specify the required extensions and the GLSL version to compile against. The default is no extensions and GLSL 4.60.
