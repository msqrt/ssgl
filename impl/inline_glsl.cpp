
#include "inline_glsl.h"
#ifdef _WIN32
#include <direct.h>
#endif

ivec2 windowSize();

namespace inline_glsl {
#ifdef _WIN32
    long ShaderStore::id_counter = 1; // 0 reserved for non-existing shaders
    inline ULONGLONG lastAccess(const char* path) {
        HANDLE file = CreateFileA(path, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        FILETIME writeTime;
        GetFileTime(file, nullptr, nullptr, &writeTime);
        CloseHandle(file);
        return ULARGE_INTEGER{ writeTime.dwLowDateTime, writeTime.dwHighDateTime }.QuadPart;
    }
#else
	std::atomic<long> ShaderStore::id_counter{1};
    inline auto lastAccess(const char* path) {
        return last_write_time(std::filesystem::path(path));
    }
#endif

    inline bool alphanum_(char input) {
        return 'a' <= input && input <= 'z' || 'A' <= input && input <= 'Z' || '0' <= input && input <= '9' || input == '_';
    }

    inline void remove_bind_calls(char* input) {
        char* output = input;
        bool inside = false;
        const char* needle = " bind";

        while (*input != '\0') {
            *output = *input;
            if (!alphanum_(*input)) {
                for (int i = 1;; i++) {
                    if (needle[i] == '\0') {
                        while (*input != '(' && *input != '\0') input++;
                        inside = true;
                        break;
                    }
                    if (input[i] != needle[i]) break;
                }
            }
            output++; input++;
            if (inside && *input == ')') {
                input++;
                inside = false;
            }
        }
        *output = '\0';
    }

    inline char* search(char* input, const char* needle, int& line) {
        while (*input != '\0') {
            if (*input == '\n') line++;
            for (int i = 0;; i++) {
                if (needle[i] == '\0') return input;
                else if (input[i] != needle[i]) break;
            }
            input++;
        }
        return input;
    }

    void remove_comments(char* source_in, uint* lines_in) {
        char* source_out = source_in;
        uint* lines_out = lines_in;
        bool multi_comment = false, single_comment = false;

        while(*source_in!='\0') {
            if (multi_comment) {
                if (*source_in == '\n') { // keep commented \ns to preserve lines
                    *(source_out++) = '\n';
                    *(lines_out++) = *lines_in;
                }
                else if (*source_in == '/' && *(source_in-1) == '*')
                    multi_comment = false;
            }
            else if (single_comment && *source_in == '\n') {
                *(source_out++) = '\n';
                *(lines_out++) = *lines_in;
                single_comment = false;
            }
            else {
                if (*source_in == '/') {
                    if (*(source_in+1) == '/')
                        single_comment = true;
                    else if (*(source_in + 1) == '*')
                        multi_comment = true;
                }
                if (!single_comment && !multi_comment) {
                    *(source_out++) = *source_in;
                    *(lines_out++) = *lines_in;
                }
            }
            source_in++;
            lines_in++;
        }
        *source_out = '\0';
        *lines_out = *lines_in;
    }

    void remove_float_suffixes(char* source_in, uint* lines_in) {
        char* source_out = source_in;
        uint* lines_out = lines_in;
        bool number = false;
        while (*source_in!='\0') {
            bool keep = true;
            if (number) {
                if (*source_in == 'f')
                    keep = number = false;
                if (!('0'<=*source_in && *source_in<='9') && *source_in != '.')
                    number = false;
            }
            if (!alphanum_(*source_in) && ('0' <= *(source_in+1) && *(source_in+1) <= '9'))
                number = true;
            if (keep) {
                *(source_out++) = *source_in;
                *(lines_out++) = *lines_in;
            }
            source_in++;
            lines_in++;
        }
        *source_out = '\0';
        *lines_out = *lines_in;
    }

    bool is_same(const char* a, const char* b) {
        while (*a == *b) {
            if (*a == '\0') return true;
            a++; b++;
        }
        return false;
    }
    
    bool SourceStore::update(const char* path) {
        this->path = path;

        auto latestUpdate = lastAccess(path);
        for (auto include : includes) {
            //printf("checking include %s\n", include);
            auto includeUpdate = lastAccess(include);
            if (includeUpdate > latestUpdate)
                latestUpdate = includeUpdate;
        }

        if (latestUpdate == currentUpdate)
            return false;

        FILE* file = fopen(path, "rb");
        if(!file) return false;
        
        fseek(file, 0, SEEK_END);
        size_t size = size_t(ftell(file)) + 1;
		if(size == 0) return false;

		iteration++;

        currentUpdate = latestUpdate;

        contents.resize(size);
        contents.back() = '\0';
        fseek(file, 0, SEEK_SET);
        fread(contents.data(), 1, contents.size() - 1, file);
        fclose(file);

        lines.resize(contents.size());
        int line = 1;
        for (int i = 0; i < contents.size(); ++i) {
            lines[i] = line;
            if (contents[i] == '\n') line++;
        }
        remove_comments(contents.data(), lines.data());
        remove_float_suffixes(contents.data(), lines.data());

        char* search = contents.data();

        for (auto a : includes) delete[] a;
        includes.clear();

        // add include files (absolutely beautiful code I know)
        while (true) {
            int dummy;
            //printf("%s", contents.data());
            search = inline_glsl::search(search, "#in", dummy);

            if (*search != '\0') {
                char* include_begin = search;
                while (*search != '\"' && *search != '<' && *search != '\0') search++;
                if (*search == '\"' || *search == '<') {
                    char* path = ++search;

                    while (*search != '\"' && *search != '>' && *search != '\0') search++;
                    int64_t path_length = search - path + 1;
                    char* filePath = new char[path_length];
                    for (int i = 0; path < search; ++i)
                        filePath[i] = *(path++);
                    filePath[path_length - 1] = '\0';
                    
                    search++;
                    int64_t begin_ind = include_begin - contents.data(), search_ind = search - contents.data();

                    bool already_included = false;
                    for (auto& a : includes)
                        if (is_same(a, filePath))
                            already_included = true;

                    if (!already_included && !is_same(filePath, "glext.h") && !is_same(filePath, "window.h") && !is_same(filePath, "loadgl46.h") && !is_same(filePath, "inline_glsl.h")) {

                        //printf("%s\n", filePath);
                        FILE* includeFile = fopen(filePath, "rb");
                        if (includeFile) {
							fseek(includeFile, 0, SEEK_END);
							size_t size = size_t(ftell(includeFile));
                            includes.push_back(filePath);
                            if(size>0) {
        	                    uint includeMask = uint(includes.size()) << 20;
    	                        if (includes.size() >= 4096)
	                                printf("too many includes, errors may be reported in incorrect files\n");

                    	        size_t copy_length = contents.size() - search_ind;
                	            contents.resize(contents.size() + size - (search_ind - begin_ind) - 1);
            	                lines.resize(contents.size());
        	                    memcpy(&contents[contents.size() - copy_length], &contents[search_ind], copy_length);
    	                        memcpy(&lines[lines.size() - copy_length], &lines[search_ind], copy_length * sizeof(int));
	
    	                        fseek(includeFile, 0, SEEK_SET);
	       	                    fread(&contents[begin_ind], 1, size, includeFile);
       	                    	fclose(includeFile);
	       	                    line = 1;
								for (int i = 0; i < size; ++i) {
                    	            lines[begin_ind + i] = includeMask | line;
                	                if (contents[begin_ind + i] == '\n') line++;
            	                }
        	                    remove_comments(contents.data(), lines.data());
    	                        remove_float_suffixes(contents.data(), lines.data());
	                        }
                        }
                        else delete[] filePath;
                    }
                    else delete[] filePath;
                    search = &contents[search_ind];
                }
                else
                    search++;
            }
            else break;
        }
        contents.resize(search + 1 - contents.data());
        lines.resize(contents.size());

        /*int lineBegin = 0;
        for (int i = 0; i < contents.size(); ++i) {
            if (contents[i] == '\n' || contents[i] == '\0') {
                printf("%d: %.*s", lines[lineBegin], i - lineBegin + 1, &contents[lineBegin]);
                lineBegin = i + 1;
            }
        }
        for (int i = 0; i < 5; ++i) {
            printf("%d, ", lines[lines.size() - 1 - i]);
        }*/

        glsl_mains.clear();
        glsl_main_lines.clear();
        glsl_functions.clear();
        
        search = contents.data();

        while (true) {
            search = inline_glsl::search(search, "glsl_main", line);
            if (*search != '\0') {
                glsl_mains.push_back(search);
                glsl_main_lines.push_back(lines[search-contents.data()]);
                search++;
            }
            else break;
        }
        search = contents.data();
        while (true) {
            search = inline_glsl::search(search + 1, "#define", line);
            if (*search != '\0') {
                glsl_functions.push_back(search);
                search++;
            }
            else break;
        }
        search = contents.data();
        while (true) {
            search = inline_glsl::search(search + 1, "glsl_global", line);
            if (*search != '\0') {
                glsl_functions.push_back(search + 11);
                search++;
            }
            else break;
        }
        search = contents.data();
        while (true) {
            search = inline_glsl::search(search + 1, "glsl_function", line);
            if (*search != '\0') {
                glsl_functions.push_back(search + 13);
                search++;
            }
            else break;
        }
        search = contents.data();
        while (true) {
            search = inline_glsl::search(search + 1, "glsl_func(", line);
            if (*search != '\0') {
                for (int i = 0; i < 3; ++i) {
                    char open = i < 2 ? '(' : '{', close = i < 2 ? ')' : '}';
                    while (*search != open && *search != '\0') search++;
                    int inside = 1;
                    while (inside > 0 && *(++search)!='\0') {
                        if (*search == open) inside++;
                        if (*search == close) inside--;
                    }
                }
                /*if (*(search + 1) != ';')
                    printf("wrong character..?\n");
                else
                    printf("semicolon removed!\n");*/
                *(search+1) = ' ';
            }
            else break;
        }

        glsl_begin_lines = glsl_main_lines;
        for (int i = 0; i < glsl_mains.size(); i++) {
            char*& c = glsl_mains[i];
            int inside = 1;
            char* k = c;
            while (inside > 0 && *k != '\0') {
                if (*k == '{') inside++;
                if (*k == '}') inside--;
                k++;
            }
            *(k - 1) = '\0';
            inside = 1;
            while (inside > 0 && c != contents.data()) {
                c--;
                if (*c == '}') inside++;
                if (*c == '{') inside--;
                if (*c == '\n') glsl_begin_lines[i]--;
            }
            c++;

            remove_bind_calls(c);
        }
        for (char* c : glsl_functions) {
            if (*c == '#') {
                while (*c != '\n' && *c != '\0') c++;
                *c = '\0';
                continue;
            }
            while (*c != ';' && *c != '{' && *c != '(' && *c != '\0') c++;
            if (*c == '{') {
                c++;
                // struct
                int inside = 1;
                while (inside>0 && *c != '\0') {
                    if (*c == '{') inside++;
                    if (*c == '}') inside--;
                    c++;
                }
            }
            if (*c == ';') *(c + 1) = '\0'; // variable
            else {
                // function
                c++;
                int inside = 1;
                while (inside > 0 && *c!='\0') {
                    if (*c == '(') inside++;
                    if (*c == ')') inside--;
                    c++;
                }
                while (*c != '{' && *c!=';' && *c != '\0') c++;
                if (*c == ';')
                    *(c+1) = '\0';
                else {
                    c++;
                    inside = 1;
                    while (inside > 0 && *c != '\0') {
                        if (*c == '{') inside++;
                        if (*c == '}') inside--;
                        c++;
                    }
                    *c = '\0';
                }
            }
        }
        for (const char* c : includes) {
            while (*c != '\"' && *c != '>' && *c != '\0') ++c;
            *const_cast<char*>(c) = '\0';
        }

        return true;
    }

    void write_line(char* target, int line, int file) {
        for (int i = 0; i < 7; ++i) target[i] = "\n#line "[i];
        sprintf(target + 7, "%u %u\n", line, file);
    }

    bool add_shader(GLuint program, GLenum type, const char* name, const Shader& shader_obj, SourceStore& store) {

        GLuint shader = glCreateShader(type);

        if (!shader_obj.store->cached) {

            const char* stub = "\
#extension GL_ARB_gpu_shader_int64 : enable\n\
#define glsl_main() main()\n\
#define glsl_func(a) a\n\
#define dynamic_array(t, a) t a[]\n\
#define arg_in(a) in a\n\
#define arg_out(a) out a\n\
#define arg_inout(a) inout a\n\
#define arg_layout layout\n\
#define glsl_extension(a,b) int _##a = 1\n\
#define glsl_version(a) int glsl_version = a\n\
#define glsl_subgroup(a) \n\
#define not_(a) not(a)\n";

            size_t extensions = shader_obj.store->extensions.size();
            size_t functions = store.glsl_functions.size();
            const char** sources = const_cast<const char**>(new char* [4 + extensions + 2 * functions]);

            sources[0] = shader_obj.store->version ? shader_obj.store->version : "#version 460\n";
            for (int i = 0; i < extensions; ++i)
                sources[1 + i] = shader_obj.store->extensions[i];
            sources[extensions + 1] = stub;

            uint mask = 0xffffffffu << 20u;
            for (int i = 0; i < functions; ++i) {
                char* k = new char[32];
                uint line_file = store.lines[store.glsl_functions[i] - store.contents.data()];
                write_line(k, line_file & ~mask, (line_file & mask) >> 20u);
                sources[i * 2 + 2 + extensions] = k;
                sources[i * 2 + 3 + extensions] = store.glsl_functions[i];
            }
            char* l = new char[32];
            write_line(l, store.glsl_begin_lines[shader_obj.store->nth_in_file], 0);
            sources[2 + 2 * functions + extensions] = l;
            sources[3 + 2 * functions + extensions] = store.glsl_mains[shader_obj.store->nth_in_file];

            //printf("source: \n");
            //for (int i = 0; i < 4 + extensions + 2 * store.glsl_functions.size(); ++i)
            //    printf("%s", sources[i]);

#ifdef _WIN32
            (void)_mkdir("shader_cache");
#else
            std::filesystem::create_directory("shader_cache");
#endif

            char cache_name[256];
            get_cache_name(cache_name, store.path, shader_obj.store->line);
            FILE* cache = fopen(cache_name, "wb");
            for (auto& include : store.includes) {
                int count = 0;
                while (include[count] != '\0') count++;
                fwrite(include, 1, count, cache);
                fwrite(",", 1, 1, cache);
            }
            fwrite("\n", 1, 1, cache);
            for (int i = 0; i < 4 + extensions + 2 * store.glsl_functions.size(); ++i) {
                int count = 0;
                while (sources[i][count] != '\0') count++;
                fwrite(sources[i], 1, count, cache);
            }
            fclose(cache);

            glShaderSource(shader, GLsizei(4 + extensions + 2 * functions), sources, nullptr);

            delete[] l;
            for (int i = 0; i < functions; ++i)
                delete[] const_cast<char*>(sources[i * 2 + 2 + extensions]);
            delete[] sources;
        }
        else
            glShaderSource(shader, 1, &shader_obj.store->cached, nullptr);
        
        glCompileShader(shader);
        GLint status;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if (status != GL_TRUE) {
            GLint length;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
            std::vector<char> info_log(length);
            glGetShaderInfoLog(shader, length, nullptr, info_log.data());
            const GLubyte* vendor = glGetString(GL_VENDOR);
            
            if(vendor[0] == 'N' && vendor[1] == 'V') // should be enough :^)
                for (int i = 0; i < info_log.size(); ++i) {
                    uint file_number, line_number;
                    if ((i==0||info_log[i-1] == '\n') && 2 == sscanf(info_log.data() + i, "%u(%u)", &file_number, &line_number)) {
                        int j = 0; while (i+j < info_log.size() && info_log[i+j] != ')') j++; j++;
                        
                        const char* path = (file_number == 0) ? shader_obj.store->path : shader_obj.store->include_files[file_number-1];
                        
                        int last_dir = 0;
                        for (int k = 0; path[k] != '\0'; k++)
                            if (path[k] == '\\' || path[k] == '/')
                                last_dir = k;
                        if(last_dir)
                            path += last_dir + 1;

                        int k = 0; while (path[k] != '\0')k++;
                        int t = int(ceil(log10(line_number)));
                        // ", line "
                        size_t copy_size = info_log.size() - i - j;
                        info_log.resize(info_log.size()-j+k+t+7);
                        memcpy(info_log.data() + i + k + t + 7, info_log.data() + i + j, copy_size);
                        for (int p = 0; p < k; ++p)
                            info_log[i + p] = path[p];
                        for (int p = 0; p < 7; ++p)
                            info_log[i + k + p] = ", line "[p];
                        info_log[i+k+7+sprintf(info_log.data() + i + k + 7, "%u", line_number)] = ' ';
                        i += k + t + 7;
                    }
                }
            // TODO: AMD, Intel, ...? some vendors may have different error reporting schemes for different generations?
            printf("\n%s failed: \n%s", name, info_log.data());
            glDeleteShader(shader);
            return false;
        }
        glAttachShader(program, shader);
        glDeleteShader(shader);
        return true;
    }

    // maybe make this O(log n) at some point
    inline Program& find_or_insert(int64_t ids[6], std::vector<ProgramEntry>& programs) {
        for (int i = 0; i < programs.size(); ++i) {
            for (int j = 0; j < 6; ++j) {
                if (programs[i].ids[j] != ids[j]) break;
                else if (j == 5) return programs[i].p;
            }
        }
        programs.resize(programs.size() + 1);
        size_t location = programs.size() - 1;
        programs[location].p = Program();
        for (int i = 0; i < 6; ++i)
            programs[location].ids[i] = (long)ids[i];
        return programs[location].p;
    }

    std::vector<GLenum> draw_buffers;

    void useShader(const Shader& compute, const Shader& vertex, const Shader& geometry, const Shader& control, const Shader& evaluation, const Shader& fragment, std::vector<ProgramEntry>& programs, ShaderState& shader_state, SourceStore& store) {

        int64_t ids[] = { compute.unique_id, vertex.unique_id, fragment.unique_id, geometry.unique_id, control.unique_id, evaluation.unique_id };
        Program& program = find_or_insert(ids, programs);

        shader_state.rebuilt = false;
        if (program.obj == 0 || compute.changed || vertex.changed || fragment.changed || geometry.changed || control.changed || evaluation.changed) {
            printf("compiling... ");
            GLuint newProgram = glCreateProgram();

            bool csuccess = !compute.unique_id || add_shader(newProgram, GL_COMPUTE_SHADER, "compute", compute, store);
            bool vsuccess = !vertex.unique_id || add_shader(newProgram, GL_VERTEX_SHADER, "vertex", vertex, store);
            bool gsuccess = !geometry.unique_id || add_shader(newProgram, GL_GEOMETRY_SHADER, "geometry", geometry, store);
            bool tsuccess = !control.unique_id || add_shader(newProgram, GL_TESS_CONTROL_SHADER, "control", control, store);
            bool esuccess = !evaluation.unique_id || add_shader(newProgram, GL_TESS_EVALUATION_SHADER, "evaluation", evaluation, store);
            bool fsuccess = !fragment.unique_id || add_shader(newProgram, GL_FRAGMENT_SHADER, "fragment", fragment, store);

            bool success = csuccess && vsuccess && gsuccess && tsuccess && esuccess && fsuccess;

            if (success) {
                glLinkProgram(newProgram);

                GLint status;
                glGetProgramiv(newProgram, GL_LINK_STATUS, &status);
                if (status != GL_TRUE) {
                    GLint length;
                    glGetProgramiv(newProgram, GL_INFO_LOG_LENGTH, &length);
                    std::vector<char> info_log(length);
                    glGetProgramInfoLog(newProgram, length, nullptr, info_log.data());
                    printf("\ncouldn't link shader: \n%s\n", info_log.data());
                    glDeleteProgram(newProgram);
                    success = false;
                }
            }
            else printf("\n");
            if (success) {
                printf("success! \n");
                if (program.obj != 0)
                    glDeleteProgram(program.obj);
                program.obj = newProgram;

                if (program.vao != 0)
                    glDeleteVertexArrays(1, &program.vao);
                glCreateVertexArrays(1, &program.vao);

                shader_state.rebuilt = true;
            }
        }

        glBindVertexArray(program.vao);

        glUseProgram(program.obj);

        if (draw_buffers.size() == 0) {
            GLint maxBuffers;
            glGetIntegerv(GL_MAX_DRAW_BUFFERS, &maxBuffers);
            draw_buffers.resize(maxBuffers);
        }
        for (auto& b : draw_buffers)
            b = GL_NONE;

        shader_state.fbo = program.fbo;
        shader_state.program = program.obj;
        shader_state.texture_unit = shader_state.image_unit = shader_state.fbo_width = shader_state.fbo_height = 0;

        shader_state.use_fbo = false;

        if (compute.unique_id) for (auto& f : compute.store->callbacks) f(shader_state);
        if (vertex.unique_id) for (auto& f : vertex.store->callbacks) f(shader_state);
        if (geometry.unique_id) for (auto& f : geometry.store->callbacks) f(shader_state);
        if (control.unique_id) for (auto& f : control.store->callbacks) f(shader_state);
        if (evaluation.unique_id) for (auto& f : evaluation.store->callbacks) f(shader_state);
        if (fragment.unique_id) for (auto& f : fragment.store->callbacks) f(shader_state);

        program.fbo = shader_state.fbo;

        if (shader_state.use_fbo) {
            glViewport(0, 0, shader_state.fbo_width, shader_state.fbo_height);
            //auto test = glCheckFramebufferStatus(GL_FRAMEBUFFER);
            //if (test != GL_FRAMEBUFFER_COMPLETE)
            //    printf("framebuffer status %X\n", test);

            glDrawBuffers(draw_buffers.size(), draw_buffers.data());
        }
        else {
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
            auto size = windowSize();
            glViewport(0, 0, size.x, size.y);
        }
    }

    void Arg::findLocation(ShaderState& shader_state, ArgStore<SSBO>& store) {
        //printf("find location of SSBO '%s'\n", store.name);
        store.location = glGetProgramResourceIndex(shader_state.program, GL_SHADER_STORAGE_BLOCK, store.name);
        if (store.location != GL_INVALID_INDEX)
            glShaderStorageBlockBinding(shader_state.program, store.location, store.location);
    }
    void Arg::findLocation(ShaderState& shader_state, ArgStore<UBO>& store) {
        //printf("find location of UBO '%s'\n", store.name);
        store.location = glGetProgramResourceIndex(shader_state.program, GL_UNIFORM_BLOCK, store.name);
        if (store.location != GL_INVALID_INDEX)
            glUniformBlockBinding(shader_state.program, store.location, store.location);
    }
    void Arg::findLocation(ShaderState& shader_state, ArgStore<Target>& store) {
        //printf("find location of color attachment '%s'\n", store.name);
        store.location = glGetProgramResourceIndex(shader_state.program, GL_PROGRAM_OUTPUT, store.name);
    }
    void Arg::findLocation(ShaderState& shader_state, ArgStore<DepthTarget>& store) {
        //printf("'location' of depth attachment '%s' is obvious\n", store.name);
    }

#undef bind
    void Arg::bind(ShaderState& shader_state, ArgStore<float>& store) {
        //printf("set uniform float '%s' to %g\n", store.name, store.item);
        glUniform1f(store.location, store.item);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<int>& store) {
        //printf("set uniform int '%s' to %i\n", store.name, store.item);
        glUniform1i(store.location, store.item);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<uint>& store) {
        //printf("set uniform uint '%s' to %ui\n", store.name, store.item);
        glUniform1ui(store.location, store.item);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<uint64_t>& store) {
        //printf("set uniform uint '%s' to %ui\n", store.name, store.item);
        glUniform1ui64(store.location, store.item);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<int64_t>& store) {
        //printf("set uniform uint '%s' to %ui\n", store.name, store.item);
        glUniform1i64(store.location, store.item);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<vec2>& store) {
        //printf("set uniform vec2 '%s'\n", store.name);
        glUniform2fv(store.location, 1, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<ivec2>& store) {
        //printf("set uniform ivec2 '%s'\n", store.name);
        glUniform2iv(store.location, 1, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<uvec2>& store) {
        //printf("set uniform uvec2 '%s'\n", store.name);
        glUniform2uiv(store.location, 1, (const GLuint*)store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<vec3>& store) {
        //printf("set uniform vec3 '%s'\n", store.name);
        glUniform3fv(store.location, 1, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<ivec3>& store) {
        //printf("set uniform ivec3 '%s'\n", store.name);
        glUniform3iv(store.location, 1, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<uvec3>& store) {
        //printf("set uniform uvec3 '%s'\n", store.name);
        glUniform3uiv(store.location, 1, (const GLuint*)store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<vec4>& store) {
        //printf("set uniform vec4 '%s'\n", store.name);
        glUniform4fv(store.location, 1, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<ivec4>& store) {
        //printf("set uniform ivec4 '%s'\n", store.name);
        glUniform4iv(store.location, 1, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<uvec4>& store) {
        //printf("set uniform uvec4 '%s'\n", store.name);
        glUniform4uiv(store.location, 1, (const GLuint*)store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<mat2>& store) {
        //printf("set uniform mat2 '%s'\n", store.name);
        glUniformMatrix2fv(store.location, 1, false, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<mat3>& store) {
        //printf("set uniform mat3 '%s'\n", store.name);
        glUniformMatrix3fv(store.location, 1, false, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<mat4>& store) {
        //printf("set uniform mat4 '%s'\n", store.name);
        glUniformMatrix4fv(store.location, 1, false, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<mat3x2>& store) {
        //printf("set uniform mat3x2 '%s'\n", store.name);
        glUniformMatrix3x2fv(store.location, 1, false, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<mat4x2>& store) {
        //printf("set uniform mat4x2 '%s'\n", store.name);
        glUniformMatrix4x2fv(store.location, 1, false, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<mat2x3>& store) {
        //printf("set uniform mat2x3 '%s'\n", store.name);
        glUniformMatrix2x3fv(store.location, 1, false, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<mat4x3>& store) {
        //printf("set uniform mat4x3 '%s'\n", store.name);
        glUniformMatrix4x3fv(store.location, 1, false, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<mat2x4>& store) {
        //printf("set uniform mat2x4 '%s'\n", store.name);
        glUniformMatrix2x4fv(store.location, 1, false, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<mat3x4>& store) {
        //printf("set uniform mat3x4 '%s'\n", store.name);
        glUniformMatrix3x4fv(store.location, 1, false, store.item.data);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<SSBO>& store) {
        //printf("bind SSBO '%s'\n", store.name);
        glBindBufferBase(GL_SHADER_STORAGE_BUFFER, store.location, store.item);
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<UBO>& store) {
        //printf("bind UBO '%s'\n", store.name);
        glBindBufferBase(GL_UNIFORM_BUFFER, store.location, store.item);
    }

    void set_fbo_size(GLuint texture, GLint level, ShaderState& state) {
        glGetTextureLevelParameteriv(texture, level, GL_TEXTURE_WIDTH, &state.fbo_width);
        glGetTextureLevelParameteriv(texture, level, GL_TEXTURE_HEIGHT, &state.fbo_height);
    }

    bool layered(GLenum type) {
        return type == GL_TEXTURE_2D_ARRAY || type == GL_TEXTURE_3D || type == GL_TEXTURE_CUBE_MAP || type == GL_TEXTURE_CUBE_MAP_ARRAY || type == GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
    }

    void Arg::bind(ShaderState& shader_state, ArgStore<Target>& store) {
        //printf("attach color '%s'\n", store.name);
        if (store.item == 0) return;
        if (shader_state.fbo == 0)
            glGenFramebuffers(1, &shader_state.fbo);
        if(!shader_state.use_fbo)
            glBindFramebuffer(GL_FRAMEBUFFER, shader_state.fbo);
        shader_state.use_fbo = true;
        if (shader_state.fbo_width == 0) set_fbo_size(store.item, store.item.level, shader_state);
        if (layered(store.item.type))
            glFramebufferTextureLayer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + store.location, store.item, store.item.level, store.item.layer);
        else
            glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + store.location, store.item, store.item.level);
        draw_buffers[store.location] = GL_COLOR_ATTACHMENT0 + store.location;
    }
    void Arg::bind(ShaderState& shader_state, ArgStore<DepthTarget>& store) {
        //printf("attach %s to depth\n", store.name);
        if (store.item == 0) return;
        if (shader_state.fbo == 0)
            glGenFramebuffers(1, &shader_state.fbo);
        if (!shader_state.use_fbo)
            glBindFramebuffer(GL_FRAMEBUFFER, shader_state.fbo);
        shader_state.use_fbo = true;
        if (shader_state.fbo_width == 0) set_fbo_size(store.item, store.item.level, shader_state);
        if (layered(store.item.type))
            glFramebufferTextureLayer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, store.item, store.item.level, store.item.layer);
        else
            glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, store.item, store.item.level);
    }
}
