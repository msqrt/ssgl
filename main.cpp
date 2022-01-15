
#include "ssgl.h"
#include "math_helpers.h"

int main() {

    OpenGL context(1280, 720, "Triangle");
    
    while (loop()) {

        swapBuffers();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Sleep(5);
    }
    return 0;
}
