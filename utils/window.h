
#pragma once

#ifdef _WIN32

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#endif
#include <stdio.h>

#define GL_GLEXT_LEGACY
#include <GL/gl.h>
#undef GL_VERSION_1_3
#include "glext.h"
#include "loadgl46.h"

void setupGL(int width, int height, const char* title, bool fullscreen, bool show);
void closeGL();
bool loop();
bool glOpen();
void swapBuffers();
void setTitle(const char* title);
void showWindow();
void hideWindow();

#include "glsl.h"

bool keyDown(uint vk_code);
bool keyHit(uint vk_code);
void resetHits();

ivec2 getMouse();
void setMouse(ivec2);

ivec2 windowSize();

// todo: make this a true class? or use some kind of "finally" for the close?
// possible reasoning: don't really want singleton, but don't really want to support multiple contexts either
// why not just global functions: to be nice, we want to free all RAII objects before closing the GL context, so this has to be RAII as well
struct OpenGL {
	OpenGL(
		int width, int height,
		const char* title = "",
		bool fullscreen = false,
		bool show = true)
	{
		if (glOpen()) return;
		isOwning = true;
		setupGL(width, height, title, fullscreen, show);
	}
	~OpenGL() {
		if(isOwning)
			closeGL();
	}
	bool isOwning = false;
};
