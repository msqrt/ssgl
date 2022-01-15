#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <vector>

#ifndef NO_WIN32
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#else
#include <cstdint>
#endif

#include "glsl.h"
#include "shader_types.h"

#ifdef NO_WIN32
#include <filesystem>
#include <atomic>
#endif

namespace inline_glsl {
    
    struct SourceStore {
        std::vector<char> contents;
        std::vector<char*> glsl_mains;
        std::vector<char*> glsl_functions;
        std::vector<int> glsl_main_lines, glsl_begin_lines;
        std::vector<const char*> includes;
        char const* path;
        std::vector<uint> lines;
#ifndef NO_WIN32
        ULONGLONG currentUpdate = 0;
#else
        std::filesystem::file_time_type currentUpdate = {};
#endif
        uint iteration = 0;
        bool update(const char* path);
        ~SourceStore() {
            for (auto include : includes) delete[] include;
        }
    };

    static SourceStore store;

    // filled prior to invoking a program
    struct ShaderState {
        GLuint program;
        GLuint fbo;
        GLuint image_format, image_access;
        GLubyte texture_unit;
        GLubyte image_unit;
        GLint fbo_width, fbo_height;
        bool rebuilt, use_fbo;
    } static shader_state;

    struct Function {
        virtual void operator()(ShaderState&) = 0;
        virtual ~Function() {}
    };

    template<typename T>
    struct Specific : Function {
        T func;
        Specific(T func) : func(func) {}
        virtual void operator()(ShaderState& state) { func(state); }
    };

    struct Func {
        Function* func = nullptr;
        template<typename T>
        Func(T func) : func(new Specific<T>(func)) {}
        Func(Func&& other) : func(other.func) { other.func = nullptr; }
        void operator()(ShaderState& state) { (*func)(state); }
        ~Func() { if (func) delete func; }
    };

    using ShaderSetup = std::vector<Func>;
    inline ShaderSetup* current_callbacks;
    inline std::vector<const char*>* extensions;
    inline const char** version;

    inline void get_cache_name(char* result, const char* path, int line) {

        const char* path_name = path;
        while (*path_name != '\0') path_name++;
        while (*path_name != '\\' && *path_name != '/' && path_name > path)path_name--;
        if (path_name > path) path_name++;

        int i = 0;
        for (i = 0; i < 13; ++i)
            result[i] = "shader_cache/"[i];
        while (*path_name != '.' && *path_name != '\0')
            result[i++] = *path_name++;
        result[i++] = '_';

        i += sprintf(result+i, "%d", line);

        for (int j = 0; j < 6; ++j)
            result[i++] = ".glsl"[j];
    }

    struct ShaderStore {
        ShaderSetup callbacks;
        std::vector<const char*> extensions, include_files;
        const char* version;
        const char* path; int line;
        const char* cached = nullptr;
        uint nth_in_file, iteration = 0;
        long unique_id;
#ifndef NO_WIN32
        static long id_counter;
#else
		static std::atomic<long> id_counter;
#endif
        ShaderStore(const char* path, int line, SourceStore& store) : path(path), line(line) {
#ifndef NO_WIN32
            unique_id = InterlockedAdd(&id_counter, 1);
#else
            unique_id = id_counter++;
#endif
            FILE* test = fopen(path, "r");
            if (test) {
                fclose(test);
                store.update(path);
                include_files = store.includes;
                for (nth_in_file = 0; nth_in_file < store.glsl_main_lines.size() && store.glsl_main_lines[nth_in_file] != line; ++nth_in_file);
                //printf("glsl_main %d at line %d\n", nth_in_file, line);
            }
            else {
                char name_buffer[256];
                get_cache_name(name_buffer, path, line);
                FILE* file = fopen(name_buffer, "rb");
                fseek(file, 0, SEEK_END);
                size_t size = size_t(ftell(file)) + 1;
                char* cache = new char[size];
                cache[size - 1] = '\0';

                fseek(file, 0, SEEK_SET);
                fread(cache, 1, size - 1, file);
                fclose(file);

                while (*cache != '\0' && *cache != '\n') {
                    include_files.push_back(cache);
                    while (*cache != '\0' && *cache != ',') cache++;
                    if (*cache != '\0') {
                        *cache = '\0';
                        cache++;
                    }
                }

                cached = cache+1;
            }
        }

        bool update(SourceStore& store) {
            callbacks.clear();
            extensions.clear();
            version = nullptr;
            inline_glsl::current_callbacks = &callbacks;
            inline_glsl::extensions = &extensions;
            inline_glsl::version = &version;
            if (cached) return false;
            store.update(path);
            uint old_iteration = iteration;
            iteration = store.iteration;
            return old_iteration != iteration;
        }
        ~ShaderStore() { delete[] cached; }
    };

    struct Extension {
        const char* ext;
        Extension(const char* ext) : ext(ext) {}
        ~Extension() { inline_glsl::extensions->push_back(ext); }
    };
    struct Version {
        const char* version;
        Version(const char* version) : version(version) {}
        ~Version() { *inline_glsl::version = version; }
    };
}
struct Shader {
    uint unique_id = 0; bool changed = false;
    inline_glsl::ShaderStore* store = nullptr;
    Shader() {}
    Shader(inline_glsl::ShaderStore& shader, inline_glsl::SourceStore& source) {
        changed = shader.update(source);
        unique_id = shader.unique_id;
        store = &shader;
    }
};

namespace inline_glsl {
    struct Program {
        GLuint obj = 0, vao = 0, fbo = 0;
    };

    struct ProgramEntry {
        long ids[6] = { 0 };
        Program p;
    };

    static std::vector<ProgramEntry> programs;
    void useShader(const Shader& compute, const Shader& vertex, const Shader& geometry, const Shader& control, const Shader& evaluation, const Shader& fragment, std::vector<ProgramEntry>& programs, ShaderState& shader_state, SourceStore& store);


    template<typename T = UBO>
    struct ArgStore {
        const char* name;
        GLuint location;
        T item;
        ArgStore(const char* name, T i) : name(name), item(i) {
            //printf("retainer for %s\n", name);
        }
    };

    using glsl::same, glsl::Field, glsl::Rows;

    template<typename T>
    constexpr bool is_image = false;
    template<GLenum type, typename T>
    constexpr bool is_image<Image<type, T>> = true;

    struct Arg {
        template<typename V>
        void findLocation(ShaderState& shader_state, ArgStore<V>& store) {
            //printf("glGetUniformLocation(%s)\n", store.name);
            store.location = glGetUniformLocation(shader_state.program, store.name);
        }
        template<GLenum type, typename T, bool shadow>
        void findLocation(ShaderState& shader_state, ArgStore<Sampler<type, T, shadow>>& store) {
            //printf("glGetUniformLocation(%s)\n", store.name);
            store.location = glGetUniformLocation(shader_state.program, store.name);
            if (store.location != GL_INVALID_INDEX)
                glUniform1i(store.location, shader_state.texture_unit);
            if constexpr (shadow) {
                glTextureParameteri(store.item, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
                glTextureParameteri(store.item, GL_TEXTURE_COMPARE_FUNC, GL_LESS);
            }
        }
        template<GLenum type, typename T>
        void findLocation(ShaderState& shader_state, ArgStore<Image<type, T>>& store) {
            store.location = glGetUniformLocation(shader_state.program, store.name);
            if (store.location != GL_INVALID_INDEX)
                glUniform1i(store.location, shader_state.image_unit);
        }
        void findLocation(ShaderState& shader_state, ArgStore<SSBO>& store);
        void findLocation(ShaderState& shader_state, ArgStore<UBO>& store);
        template<typename U>
        void findLocation(ShaderState& shader_state, ArgStore<Attribute<U>>& store) {
            //printf("find location of vertex attribute '%s'\n", store.name);
            store.location = glGetAttribLocation(shader_state.program, store.name);
            if(store.location!= GL_INVALID_INDEX)
                glEnableVertexAttribArray(store.location);
        }
        void findLocation(ShaderState& shader_state, ArgStore<Target>& store);
        void findLocation(ShaderState& shader_state, ArgStore<DepthTarget>& store);

        void bind(ShaderState& shader_state, ArgStore<float>& store);
        void bind(ShaderState& shader_state, ArgStore<int>& store);
        void bind(ShaderState& shader_state, ArgStore<uint>& store);
        void bind(ShaderState& shader_state, ArgStore<vec2>& store);
        void bind(ShaderState& shader_state, ArgStore<ivec2>& store);
        void bind(ShaderState& shader_state, ArgStore<uvec2>& store);
        void bind(ShaderState& shader_state, ArgStore<vec3>& store);
        void bind(ShaderState& shader_state, ArgStore<ivec3>& store);
        void bind(ShaderState& shader_state, ArgStore<uvec3>& store);
        void bind(ShaderState& shader_state, ArgStore<vec4>& store);
        void bind(ShaderState& shader_state, ArgStore<ivec4>& store);
        void bind(ShaderState& shader_state, ArgStore<uvec4>& store);
        void bind(ShaderState& shader_state, ArgStore<mat2>& store);
        void bind(ShaderState& shader_state, ArgStore<mat3>& store);
        void bind(ShaderState& shader_state, ArgStore<mat4>& store);
        void bind(ShaderState& shader_state, ArgStore<mat3x2>& store);
        void bind(ShaderState& shader_state, ArgStore<mat4x2>& store);
        void bind(ShaderState& shader_state, ArgStore<mat2x3>& store);
        void bind(ShaderState& shader_state, ArgStore<mat4x3>& store);
        void bind(ShaderState& shader_state, ArgStore<mat2x4>& store);
        void bind(ShaderState& shader_state, ArgStore<mat3x4>& store);
        void bind(ShaderState& shader_state, ArgStore<SSBO>& store);
        void bind(ShaderState& shader_state, ArgStore<UBO>& store);
        template<typename U>
        void bind(ShaderState& shader_state, ArgStore<Attribute<U>>& store) {
            //printf("bind vertex attribute '%s'\n", store.name);
            glBindBuffer(GL_ARRAY_BUFFER, store.item);

            static_assert(same<Field<U>, float> || same<Field<U>, int> || same<Field<U>,uint>, "attribute base type not supported");
            if constexpr (same<Field<U>, float>)
                glVertexAttribPointer(store.location, Rows<U>, store.item.type, store.item.normalized, store.item.stride, (void*)(size_t)store.item.offset);
            else
                glVertexAttribIPointer(store.location, Rows<U>, store.item.type, store.item.stride, (void*)(size_t)store.item.offset);
        }

        void bind(ShaderState& shader_state, ArgStore<Target>& store);
        void bind(ShaderState& shader_state, ArgStore<DepthTarget>& store);

        template<GLenum type, typename T, bool shadow>
        void bind(ShaderState& shader_state, ArgStore<Sampler<type, T, shadow>>& store) {
            //printf("bind sampler2D '%s'\n", store.name);
            glBindTextureUnit(shader_state.texture_unit, store.item);
            shader_state.texture_unit++;
        }
        template<GLenum type, typename T>
        void bind(ShaderState& shader_state, ArgStore<Image<type, T>>& store, GLuint access, GLuint format) {
            //printf("bind image2D '%s'\n", store.name);
            if (access == 1) access = GL_READ_ONLY;
            else if (access == 2) access = GL_WRITE_ONLY;
            else access = GL_READ_WRITE;

            bool layered = store.item.layer == GL_INVALID_INDEX;
            GLint tex_format, tex_size, bind_size;
            glGetTextureLevelParameteriv(store.item, store.item.level, GL_TEXTURE_INTERNAL_FORMAT, &tex_format);
            glGetInternalformativ(type, tex_format, GL_IMAGE_TEXEL_SIZE, 1, &tex_size);
            glGetInternalformativ(type, format, GL_IMAGE_TEXEL_SIZE, 1, &bind_size);
            if (tex_size != bind_size) {
                printf("warning: texture and shader image have different texel sizes\n");
#ifndef NO_WIN32
                __debugbreak();
#endif
            }
            glBindImageTexture(shader_state.image_unit, store.item, store.item.level, layered, layered ? 0 : store.item.layer, access, format);
            shader_state.image_unit++;
        }

        Func func;
        template<typename U>
        Arg(volatile ArgStore<U>& store_, const U& j) : func([&, j, state = shader_state](ShaderState& shader_state) {
            ArgStore<U>& store = const_cast<ArgStore<U>&>(store_); // volatile is a legit keyword for images and buffers; the variable is not actually volatile so we cast it away
            bool update = store.item != U(j);
            if (shader_state.rebuilt) {
                findLocation(shader_state, store);
                update = true;
            }
            //if (update) {
            store.item = j;
            if (store.location != -1)
                if constexpr (!is_image<U>)
                    bind(shader_state, store);
                else
                    bind(shader_state, store, state.image_access, state.image_format);
            //}
            }) {}

            ~Arg() { current_callbacks->push_back(std::move(func)); }
    };
}

#define UNIQUE_(a, b) ___ ## a ## b
#define UNIQUE(a, b) UNIQUE_(a, b)

#define REPEAT1(m, a) m(a)
#define REPEAT2(m, a, b) m(a), m(b)
#define REPEAT3(m, a, b, c) m(a), m(b), m(c)
#define REPEAT4(m, a, b, c, d) m(a), m(b), m(c), m(d)
#define REPEAT5(m, a, b, c, d, e) m(a), m(b), m(c), m(d), m(e)
#define REPEAT6(m, a, b, c, d, e, f) m(a), m(b), m(c), m(d), m(e), m(f)
#define REPEAT7(m, a, b, c, d, e, f, g) m(a), m(b), m(c), m(d), m(e), m(f), m(g)
#define REPEAT8(m, a, b, c, d, e, f, g, h) m(a), m(b), m(c), m(d), m(e), m(f), m(g), m(h)

#define SELECT(a, b, c, d, e, f, g, h, macro, ...) macro
#define REPEAT(...) SELECT(__VA_ARGS__, REPEAT8, REPEAT7, REPEAT6, REPEAT5, REPEAT4, REPEAT3, REPEAT2, REPEAT1)


#define STORE(a) UNIQUE(a,0)(#a, a)
#define ARG(a) UNIQUE(a##_,0)(UNIQUE(a, 0), (decltype(UNIQUE(a,0).item))a)
#define SHADOW(a) a = {}

#define UNIFORM static inline_glsl::ArgStore<
#define BUFFER static inline_glsl::ArgStore<SSBO

#define uniform UNIFORM
#define buffer BUFFER

#define discard

#define FIRSTTYPE(a, ...) decltype(UNIQUE(a,0).item)

#define BIND(...) > REPEAT(__VA_ARGS__)(STORE, __VA_ARGS__); inline_glsl::Arg REPEAT(__VA_ARGS__)(ARG, __VA_ARGS__); FIRSTTYPE(__VA_ARGS__, 0) REPEAT(__VA_ARGS__)(SHADOW, __VA_ARGS__); inline_glsl::shader_state.image_access = 0
#define BIND_BLOCK(a)  > UNIQUE(a,0)(#a, a); inline_glsl::Arg UNIQUE(a##_,0)(UNIQUE(a,0), (decltype(UNIQUE(a,0).item))a); inline_glsl::shader_state.image_access = 0; union

// bind(uniform_1, uniform_2, ...)
#define bind(...) BIND(__VA_ARGS__)

// bind_block(ssbo/ubo) {...};
#define bind_block(a) BIND_BLOCK(a)

#define DECL_TARGET_(a) UNIQUE(a##_,0)(#a, a)
#define SELECT_TARGET_DECLARE_(...) REPEAT(__VA_ARGS__)(DECL_TARGET_, __VA_ARGS__)

#define DECL_TARGET(a) UNIQUE(a,0)(#a, a)
#define SELECT_TARGET_DECLARE(...) REPEAT(__VA_ARGS__)(DECL_TARGET, __VA_ARGS__)

#define TARGET_SETTER(a) UNIQUE(a##_,0)(UNIQUE(a, 0), Target(a))
#define SELECT_TARGET_SET(...) REPEAT(__VA_ARGS__)(TARGET_SETTER, __VA_ARGS__)

#define SET_ATTR(a) UNIQUE(a##_,0)(UNIQUE(a, 0), Attribute<decltype(UNIQUE(type, __LINE__))>(a))
#define SELECT_ATTRIB_SET(...) REPEAT(__VA_ARGS__)(SET_ATTR, __VA_ARGS__)


#define BIND_ATTRIBUTE(...) UNIQUE(type, __LINE__);(void)UNIQUE(type, __LINE__); static inline_glsl::ArgStore<Attribute<decltype(UNIQUE(type, __LINE__))>> SELECT_TARGET_DECLARE(__VA_ARGS__); inline_glsl::Arg SELECT_ATTRIB_SET(__VA_ARGS__); decltype(UNIQUE(type, __LINE__)) REPEAT(__VA_ARGS__)(SHADOW, __VA_ARGS__)
#define BIND_TARGET(...) UNIQUE(type, __LINE__);(void)UNIQUE(type, __LINE__); static inline_glsl::ArgStore<Target> SELECT_TARGET_DECLARE(__VA_ARGS__); inline_glsl::Arg SELECT_TARGET_SET(__VA_ARGS__);  decltype(UNIQUE(type, __LINE__)) REPEAT(__VA_ARGS__)(SHADOW, __VA_ARGS__)

// bind_attribute(attribute_1, attribute_2, ...)
#define bind_attribute(...) BIND_ATTRIBUTE(__VA_ARGS__)

// bind_target(texture_1, texture_2, ...)
#define bind_target(...) BIND_TARGET(__VA_ARGS__)

#define glsl_func(name) *UNIQUE(type, __LINE__); (void)(UNIQUE(type, __LINE__)); auto name = [&]

#define in
#define out

#define arg_in(type) type
#define arg_out(type) type&
#define arg_inout(type) type&

#define flat
#define noperspective
#define smooth

#define layout(...) __VA_ARGS__;

#define std140 0
#define std430 0

#define shared

#define glsl_extension(name, behavior) inline_glsl::Extension _##name("#extension " #name " : " #behavior "\n")
#define glsl_version(version) inline_glsl::Version glsl_version("#version " #version "\n")
#define glsl_subgroup(behavior) \
    glsl_extension(GL_KHR_shader_subgroup_basic, behavior);\
    glsl_extension(GL_KHR_shader_subgroup_vote, behavior);\
    glsl_extension(GL_KHR_shader_subgroup_ballot, behavior);\
    glsl_extension(GL_KHR_shader_subgroup_arithmetic, behavior);\
    glsl_extension(GL_KHR_shader_subgroup_shuffle, behavior);\
    glsl_extension(GL_KHR_shader_subgroup_shuffle_relative, behavior);\
    glsl_extension(GL_KHR_shader_subgroup_clustered, behavior);\
    glsl_extension(GL_KHR_shader_subgroup_quad, behavior)

inline unsigned location, binding, component, offset, vertices, max_vertices, primitive, invocations, local_size_x, local_size_y, local_size_z;
inline unsigned points, lines, lines_adjacency, triangles, triangles_adjacency, line_strip, triangle_strip;

#define IMAGE_FORMAT(a) inline_glsl::shader_state.image_format = a
template<typename T>
struct DynamicArray {
    T val;
    T& operator[](int){ return val; }
    int length() { return 0; }
};
#define dynamic_array(type, name) DynamicArray<type> name;

#define arg_layout(...)

#define r11f_g11f_b10f IMAGE_FORMAT(GL_R11F_G11F_B10F)
#define rgb10_a2 IMAGE_FORMAT(GL_RGB10_A2)
#define rgba32f IMAGE_FORMAT(GL_RGBA32F)
#define rgba16f IMAGE_FORMAT(GL_RGBA16F)
#define rgba16 IMAGE_FORMAT(GL_RGBA16)
#define rgba8 IMAGE_FORMAT(GL_RGBA8)
#define rg32f IMAGE_FORMAT(GL_RG32F)
#define rg16f IMAGE_FORMAT(GL_RG16F)
#define rg16 IMAGE_FORMAT(GL_RG16)
#define rg8 IMAGE_FORMAT(GL_RG8)
#define r32f IMAGE_FORMAT(GL_R32F)
#define r16f IMAGE_FORMAT(GL_R16F)
#define r16 IMAGE_FORMAT(GL_R16)
#define r8 IMAGE_FORMAT(GL_R8)
#define rgba16_snorm IMAGE_FORMAT(GL_RGBA16_SNORM)
#define rgba8_snorm IMAGE_FORMAT(GL_RGBA8_SNORM)
#define rg16_snorm IMAGE_FORMAT(GL_RG16_SNORM)
#define rg8_snorm IMAGE_FORMAT(GL_RG8_SNORM)
#define r16_snorm IMAGE_FORMAT(GL_R16_SNORM)
#define r8_snorm IMAGE_FORMAT(GL_R8_SNORM)

#define rgba32i IMAGE_FORMAT(GL_RGBA32I)
#define rgba16i IMAGE_FORMAT(GL_RGBA16I)
#define rgba8i IMAGE_FORMAT(GL_RGBA8I)
#define rg32i IMAGE_FORMAT(GL_RG32I)
#define rg16i IMAGE_FORMAT(GL_RG16I)
#define rg8i IMAGE_FORMAT(GL_RG8I)
#define r32i IMAGE_FORMAT(GL_R32I)
#define r16i IMAGE_FORMAT(GL_R16I)
#define r8i IMAGE_FORMAT(GL_R8I)


#define rgb10_a2ui IMAGE_FORMAT(GL_RGB10_A2UI)
#define rgba32ui IMAGE_FORMAT(GL_RGBA32UI)
#define rgba16ui IMAGE_FORMAT(GL_RGBA16UI)
#define rgba8ui IMAGE_FORMAT(GL_RGBA8UI)
#define rg32ui IMAGE_FORMAT(GL_RG32UI)
#define rg16ui IMAGE_FORMAT(GL_RG16UI)
#define rg8ui IMAGE_FORMAT(GL_RG8UI)
#define r32ui IMAGE_FORMAT(GL_R32UI)
#define r16ui IMAGE_FORMAT(GL_R16UI)
#define r8ui IMAGE_FORMAT(GL_R8UI)

#define READONLY inline_glsl::shader_state.image_access |= 1;
#define readonly READONLY
#define WRITEONLY inline_glsl::shader_state.image_access |= 2;
#define writeonly WRITEONLY

#define coherent
#define restrict

#define early_fragment_tests

#define glsl_function
#define glsl_global

#define EmitVertex()
#define EndPrimitive()
#define EmitStreamVertex()

#define GLSL_MAIN ();static inline_glsl::ShaderStore __s(__FILE__, __LINE__, inline_glsl::store); return Shader(__s, inline_glsl::store); if constexpr(false)
#define glsl_main() GLSL_MAIN

#define BIND_DEPTH(a) ();static inline_glsl::ArgStore<DepthTarget> UNIQUE(a,__LINE__)(#a, a); inline_glsl::Arg UNIQUE(a##_,__LINE__)(UNIQUE(a, __LINE__), DepthTarget(a))
// bind_depth(texture)
#define bind_depth(a) BIND_DEPTH(a)

static void useShader(const Shader& compute) {
    inline_glsl::useShader(compute, Shader{}, Shader{}, Shader{}, Shader{}, Shader{}, inline_glsl::programs, inline_glsl::shader_state, inline_glsl::store);
}
static void useShader(const Shader& vertex, const Shader& fragment) {
    inline_glsl::useShader(Shader{}, vertex, Shader{}, Shader{}, Shader{}, fragment, inline_glsl::programs, inline_glsl::shader_state, inline_glsl::store);
}
static void useShader(const Shader& vertex, const Shader& geometry, const Shader& fragment) {
    inline_glsl::useShader(Shader{}, vertex, geometry, Shader{}, Shader{}, fragment, inline_glsl::programs, inline_glsl::shader_state, inline_glsl::store);
}
static void useShader(const Shader& vertex, const Shader& control, const Shader& evaluation, const Shader& fragment) {
    inline_glsl::useShader(Shader{}, vertex, Shader{}, control, evaluation, fragment, inline_glsl::programs, inline_glsl::shader_state, inline_glsl::store);
}
static void useShader(const Shader& vertex, const Shader& geometry, const Shader& control, const Shader& evaluation, const Shader& fragment) {
    inline_glsl::useShader(Shader{}, vertex, geometry, control, evaluation, fragment, inline_glsl::programs, inline_glsl::shader_state, inline_glsl::store);
}

inline const Texture<> screen = {};
