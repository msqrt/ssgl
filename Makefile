CXX = g++
CFLAGS = -c -std=c++17 -I. -Iimpl -Iutils
GLSL_DEPS = impl/inline_glsl.h impl/glsl.h impl/shader_types.h impl/gl_helpers.h

all: program
	./program

obj:
	mkdir -p obj

obj/window.o: utils/window.cpp utils/window.h impl/glsl.h|obj
	$(CXX) $(CFLAGS) -o obj/window.o utils/window.cpp
obj/loadgl46.o: utils/loadgl46.cpp utils/loadgl46.h|obj
	$(CXX) $(CFLAGS) -o obj/loadgl46.o utils/loadgl46.cpp
obj/gl_helpers.o: impl/gl_helpers.cpp impl/gl_helpers.h|obj
	$(CXX) $(CFLAGS) -o obj/gl_helpers.o impl/gl_helpers.cpp
obj/inline_glsl.o: impl/inline_glsl.cpp $(GLSL_DEPS)|obj
	$(CXX) $(CFLAGS) -o obj/inline_glsl.o impl/inline_glsl.cpp
obj/main.o: main.cpp $(GLSL_DEPS)|obj
	$(CXX) $(CFLAGS) -o obj/main.o main.cpp
obj/mesh.o: utils/mesh.cpp utils/mesh.h impl/glsl.h|obj
	$(CXX) $(CFLAGS) -o obj/mesh.o utils/mesh.cpp

program: obj/window.o obj/loadgl46.o obj/gl_helpers.o obj/inline_glsl.o obj/main.o obj/mesh.o
	$(CXX) -o program obj/*.o -lm -ldl -lpthread -lX11 -lEGL -lGL -lpng
