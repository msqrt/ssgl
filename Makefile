CXX = g++
CFLAGS = -c -std=c++17 -I. -DHEADLESS
GLSL_DEPS = impl/inline_glsl.h impl/glsl.h impl/shader_types.h impl/gl_helpers.h
SSGL_DEPS = $(GLSL_DEPS) impl/ssgl.h impl/window.h math_helpers.h ggx.h

all: program
	./program

obj:
	mkdir -p obj

obj/window.o: utils/window.cpp utils/window.h utils/glsl.h|obj
	$(CXX) $(CFLAGS) -o obj/window.o utils/window.cpp
obj/loadgl46.o: utils/loadgl46.cpp utils/loadgl46.h|obj
	$(CXX) $(CFLAGS) -o obj/loadgl46.o utils/loadgl46.cpp
obj/gl_helpers.o: impl/gl_helpers.cpp impl/gl_helpers.h|obj
	$(CXX) $(CFLAGS) -o obj/gl_helpers.o impl/gl_helpers.cpp
obj/inline_glsl.o: impl/inline_glsl.cpp $(GLSL_DEPS)|obj
	$(CXX) $(CFLAGS) -o obj/inline_glsl.o impl/inline_glsl.cpp
obj/main.o: main.cpp $(SSGL_DEPS)|obj
	$(CXX) $(CFLAGS) -o obj/main.o main.cpp
obj/mesh.o: mesh.cpp utils/mesh.h impl/glsl.h|obj
	$(CXX) $(CFLAGS) -o obj/mesh.o utils/mesh.cpp

program: obj/window.o obj/loadgl46.o obj/gl_helpers.o obj/inline_glsl.o obj/main.o obj/mesh.o obj/simplify_test.o obj/test_file.o
	$(CXX) -o program obj/*.o -ldl -lpthread -lX11 -lEGL -lGL -lpng
