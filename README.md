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
            dynamic_array(uint, result); // equivalent to uint result[];
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

Let's look at a few usage examples in more detail. We'll first go through the one given earlier, a simple compute shader.

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
            dynamic_array(uint, result); // equivalent to uint result[];
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

To set the scene, we first create two objects, of types `OpenGL` and `Buffer`. These are context objects that make life easier; `OpenGL` corresponds to an OpenGL context and a window, and `Buffer` to an OpenGL buffer object. The types are prepared such that we'll have access to the desired object while the objects are in scope, after which they're automatically discarded. C++ destroys objects in the first-in-last-out order, so `iota` will be released before `context`. This is great, as trying to release an OpenGL object after OpenGL itself would be a potential disaster.

Note that we can pass `iota` directly to any OpenGL function, such as `glNamedBufferData` and `glGetNamedBufferSubData` here, since `Buffer` is implicitly castable to `GLuint`. This is similar to calling `.get()` on a `std::unique_ptr`, but there's no real potential for confusion here so the cast is made implicit.

Then we get to the shader itself. Here, this is the lambda stored to `fill`. We want to capture everything by reference to avoid copying things. The full shader code is written inside the lambda, including the setup and declarations before `main`, which is renamed to `glsl_main` (to avoid confusion, as most C++ programs also contain a `main`).

The `layout (local_size_x = 256) in;` line is standard GLSL, it sets the local group size for compute shaders; there are three axes (`local_size_x`, `local_size_y`, `local_size_z`). Axes that are not set default to a size of 1.

The `buffer` definition is slightly non-standard; namely, the name of the buffer (`iota`) is wrapped in the `bind_block()` macro. This is the part that lets ssgl generate code that automatically binds the SSBO. We'll later see other variants of the `bind` macro; `bind_block` is used for SSBOs and UBOs, since their declarations are followed by a struct-like block that defines the contents.

The `dynamic_array(uint, result);` is a straight-up macro that maps to `uint result[];`. This is for two reasons: flexible arrays as union members are not legit C++ and thus not permitted by all compilers, and a flexible array doesn't have the `.length()` member that dynamic arrays in GLSL have. Using the `dynamic_array` macro bypasses both of these issues; the code compiles everywhere, and we can use `result.length()` to determine the length of the array.

As already mentioned, `glsl_main` is just the name we use for the `main` function of a GLSL shader to avoid name clashes with the C++ `main`. This statement is the only necessary one, it makes the lambda actually produce a `Shader` object when called.

`useShader` takes in all of the desired shaders, compiles them into a program and sets it as the current program. If you wish to edit any properties of the shader manually, you can do so between `useShader()` and your draw call. Notice that the argument of `useShader()` is **not** the lambda, but the `Shader` object returned by the lambda: we write `useShader(fill())`, not `useShader(fill)`. You could in principle get the `Shader` object first and pass that into `useShader`, but doing so has little benefit and doing certain operations between the two is not permitted, so calling the lambdas in the `useShader` argument list is the safest route.

The rest of the program is very standard; we dispatch a compute operation with the shader, read some results back, and print a subset to see that something actually happened.

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
