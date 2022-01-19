# single source gl

single source gl (ssgl) lets you write GLSL shaders as C++ lambdas that automatically capture shader inputs and outputs. This unifies code, brings powerful C++ tools into shader development, and removes code that just passes objects around.

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
            // the GLSL dynamic array syntax ("uint result[];") is illegal in C++.
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

The other rationale for `dynamic_array` is that C++ flexible arrays don't have the `.length()` member that GLSL dynamic arrays do; in this example, you could call `result.length()` in the shader, but there's no way to make this work if we just wrote `uint result[];`.

If you wish to edit properties of the shader manually, you can do so between `useShader()` and your draw call.

You should **not** store the `Shader` object returned by a shader lambda: call the lambda every time you call `useShader()`. The values of the binds are updated by calling the lambda, so using the old `Shader` might mess things up when objects change names or names change objects.


### rotating rgb triangle

![](https://user-images.githubusercontent.com/1880715/150008489-79662388-f997-4f29-b10a-48279413fc9b.png)

This one is a classic OpenGL example. We'll use it to illustrate how vertex attributes and uniforms work.

```C++
#include "ssgl.h"
#include "gl_timing.h"

// get a 2D rotation matrix based on an angle (in radians)
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
```

Here the first thing to note is the function `get_rotation`, which constructs a basic rotation matrix from an angle. It's defined with the qualifier `glsl_function` which adds it to all shaders in the C++ file. Note that you can also call it from C++, as `glsl_function` does nothing on the C++ side. Includes are also followed by the shader parser, so you can define `glsl_function`s in a header file. In headers it might be useful to do `inline glsl_function`; the parser ignores anything before `glsl_function` so you can add any C++ qualifier in there.

The next new thing is `Attribute`, which defines a vertex attribute view into a buffer. The type defines how the attribute will look in the shader, and the arguments of the constructor (which are `(Buffer buffer, int stride, int offset, int type, bool normalized)`) set up how the attribute will be read from the buffer, just as you would with `glVertexAttribPointer`. Here, `buffer` is the vertex buffer we stored our vertex data in, `stride` is the size of the `Vertex` struct, `offset` is 0 for the first attribute and `sizeof(vec2)` for the second, as that's how many bytes we have to skip to land in the beginning of the first color value. `type` is deduced from the element type of the template argument (for example `float` for `vec2` and `uint` for ´uvec4´); if your data is, say, `int16_t`, you'll have to give `GL_SHORT` in the constructor. `normalized` dictates how non-float input data is mapped to a float type in a shader. So `Attribute<vec3>(b, 2, 0, GL_SHORT, true)` would give attribute values between -1.0 and 1.0, but with `normalize=false` the range would be 0.0 to 65536.0. This is exactly how `glVertexAttribPointer` works, `Attribute` is just a thin wrapper around it.

`TimeStamp` is a helper from `utils/gl_timing.h`. It lets you place timing events in code and measure elapsed cpu and gpu times between them; it's mainly useful for performance tuning, and has some overhead so should not be left in the final program. Here it's used just to show it off in context.

Uniform values are bound simply with `bind()`, and attributes with `bind_attribute()`. Try binding an `Attribute` with a mismatched type in the `in` statement (for example, `in vec3 bind_attribute(position)`); you'll get a compile time error.

Beyond the binds, there's relatively little special going on in the shaders. Notice how we use the `f` postfixes for floats; these get removed by the parser so no GLSL compiler gets confused. It's not strictly necessary but good practice to use the `f`s, since it keeps the C++ compiler from emitting loads of warnings about conversions between `float` and `double`.

An `out` parameter from the framgent shader could be bound to render to a texture with `bind_target()`; this is not necessary here, as we're writing to the screen. Incidentally, there's a special global texture with the name `screen` that you can pass in when you write a generic shader that needs to be able to write either to the screen or a texture. So you could use it here; try replacing `screen` with `bind_target(screen)`. Similarly, there's a `bind_depth()` macro you can use to declare a depth target, and a special variable `screen_depth` for the default depth target.

Then we do a drawcall, again giving the `Shader` objects returned by the shader lambdas to `useShader`. `swapBuffers` presents the image on the screen.

Note that shaders are hot reloadable! This is always active, and the reloading is done by simply saving the file. Try running the program, and while it's running, change `get_rotation(t)` to `get_rotation(-t)` and save `main.cpp`. The triangle should jump a bit and start rotating in the other direction.


## screenshots

Here are a few screenshots of how development can look. These were produced with Visual Studio 2019.

Here we see a development session working on a simple renderer with shadow mapping. Note how little supporting code is required to use features like render to texture, and how the IDE (here, Visual Studio) recognizes what's going on.

![](https://i.imgur.com/oYrj8oQ.png)

Since the code is C++ under the hood, IDE features like Intellisense work properly with shaders. GLSL vector types (including swizzles) and math functions are also available on the CPU side.

![](https://i.imgur.com/QnwMIau.png)

Functions are also supported, though they need to be tagged so that the system knows to include them in the shader.

![](https://i.imgur.com/KDyPcXR.png)

## reference

This is a listing of all the types and macros in single source gl.

### bind macros

The `bind` macros significantly reduce boiler plate code around drawcalls.

```
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

```
Shader wrapper(Buffer b) {
    return [&] {
        buffer bind_block(b) {/*whatever b contains*/};
        void glsl_main() {/*whatever you wanted to do with b*/}
    }();
}
```
which can now be set as the current shader with `useShader(wrapper(any_buffer))`, where `any_buffer` can indeed be any buffer you want. `wrapper` could also be a lambda. In fact, you could just add a redundant extra scope to your original shader function, but this looks somewhat confusing.

Note that some of the `bind` macros can take multiple arguments: this is purely a convenience feature, you can also declare each (for example) uniform in its own statement. As usual, to be able to declare the objects on the same line, they'll need to be of the same type.

```
dynamic_array(type, name)
```
Since flexible arrays inside unions are not valid C++, an SSBO can't contain an array of the form `type name[]`; this GLSL construct is replaced by this macro. With some compilers you can use the GLSL syntax, but this doesn't let you query the length of the array; using `dynamic_array(type, name)` you can call `name.length()` in the shader, just as you typically would in GLSL.

### global values and functions

single source gl also lets you use functions and variables declared outside of the shader scope.

```
glsl_function
inline glsl_function float test() {return .0f;}
glsl_global
static glsl_global uint random_seed = 0;
```

These two are straight forward, but very useful. `glsl_function` lets you write a function in the global scope, and makes it visible to both CPU and GPU side code. The system also supports includes, so you can place your functions in a header. Note that any specifiers before `glsl_function` are ignored, as the `inline` in the example above. `glsl_global` is basically the same, but introduces variables instead of functions. This is useful for global values such as mathematical constants and state required by global functions (GLSL doesn't have a static keyword, so for example random seeds have to be stored this way.)

```
return_type glsl_func(name)(arguments) {/*function body*/};
float glsl_func(twice)(float x) {return 2.f * x;};
```

`glsl_func` is almost the same as `glsl_function`, but is for functions inside the shader body. Since C++ doesn't support local functions, this actually maps to a lambda; notice the necessary semicolon after the function body. This is most convenient when you want to, for example, read from an SSBO in a specific way multiple times and want to wrap the read in a function -- you can't pass an SSBO to a function in GLSL and you won't have access to one on the global scope, so a local function is necessary. (Note that actually reading from an SSBO in a `glsl_func` requires the newest version of VS2022 and compiling as c++20, older ones will give an "internal compiler error"; other compilers are fine with it.)

```
arg_in(type)
arg_out(type)
arg_inout(type)
glsl_function void test(arg_in(float) a, arg_out(int) b, arg_inout(mat4) c) {}
```

These macros are used to wrap `out` and `inout` argument types for `glsl_function`s and `glsl_func`s; `arg_in` should not be necessary but is provided for completeness' sake. This form is required to allow using proper out/inout arguments on both the CPU and the GPU.

### wrapper types

```
struct OpenGL;
Opengl(width, height, title, fullscreen, show);
```
`OpenGL` is a RAII wrapper for an OpenGL context; constructing the object opens a context and makes it current, and . The constructor takes the parameters of the window: its size and title, if it's fullscreen, and if it should be shown at all. The last option is to support CLI programs where you don't want a window at all.

```
struct Buffer;
template<GLenum target> struct Texture;
```

`Buffer` and `Texture` are RAII wrappers for OpenGL buffers and textures. They store a single object at a time and destroy it when the lifetime ends (similar to `unique_ptr`), or the object is replaced. The object is automatically constructed if no arguments are given, and the objects are implicitly convertible to their underlying GLuint values; so for example, you can pass a `Buffer` to `glNamedBufferStorage` to set up its storage. The type is also used to deduce bindings, so using these classes is required for the shader system to work. If you wish to track your lifetimes manually or with some other system, you can construct a non-owning `Buffer` or `Texture` by just passing the `GLuint` to the constructor (or the `GLuint` and `true` to pass ownership to the class). The `target` in `Texture` refers to the texture target (such as `GL_TEXTURE_2D`) -- to write a generic function that can take in any type, you should use `Texture<>` which stores the target dynamically.

```
template<GLenum target>
Texture<> Level(const Texture<target>& t, int level);
template<GLenum target>
Texture<> Layer(const Texture<target>& t, int layer);
```

`Level` and `Layer` take the MIP level or the 2D layer of the given `Texture`, and return a corresponding dynamically-targeted texture. This is so it's possible to write a shader that operates on a 2D texture, and pass in a specific MIP level or a layer of a 3D texture.

```
template<typename T>
struct Attribute;
// to construct:
Attribute(const Buffer& b, int stride, int offset = 0, GLuint type = -1, bool normalized = false)
```

`Attribute` is an adapter for vertex buffers: it's where you define how the buffer is read to produce vertex inputs. The template argument `T` is the shader-side type of the attribute. The only things you can do with `Attribute` instances are construct them and bind them to shaders. In the constructor you specify the buffer to be read, and all of the information typically given to `glVertexAttribPointer`. The type of the attribute is typically determined by the template argument, but for example a vec3 attribute can be backed up by `GL_BYTE` data, so you can also give the type manually.

### misc

```
void useShader(const Shader& compute);
void useShader(const Shader& vertex, const Shader& fragment);
void useShader(const Shader& vertex, const Shader& geometry, const Shader& fragment);
void useShader(const Shader& vertex, const Shader& control, const Shader& evaluation, const Shader& fragment);
void useShader(const Shader& vertex, const Shader& geometry, const Shader& control, const Shader& evaluation, const Shader& fragment);
```
`useShader` basically replaces `glUseProgram()` and most of the binding code. You give it the shaders corresponding to the shader stages you require. The OpenGL side shader programs themselves are cached, so compilation only happens on the first call to that specific combination of shaders.

```
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

```
glsl_extension(name, behavior)
glsl_version(version)
```

These macros are used inside a shader to specify the required extensions and the GLSL version to compile against. The default is no extensions and GLSL 4.60.
