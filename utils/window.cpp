
#include "window.h"

#ifndef _WIN32
#include <signal.h>
#endif

void APIENTRY glDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, void*) {

	// format the message nicely
	auto output = printf("OpenGL ");

	switch (type) {
	case GL_DEBUG_TYPE_ERROR:					printf("error");							break;
	case GL_DEBUG_TYPE_PORTABILITY:				printf("portability issue");				break;
	case GL_DEBUG_TYPE_PERFORMANCE:				printf("performance issue");				break;
	case GL_DEBUG_TYPE_OTHER:					printf("issue");							break;
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:		printf("undefined behavior");				break;
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:		printf("deprecated behavior");				break;
	default:									printf("issue(?)");							break;
	}
	switch (source) {
	case GL_DEBUG_SOURCE_API:																break;
	case GL_DEBUG_SOURCE_WINDOW_SYSTEM:			printf(" in the window system");			break;
	case GL_DEBUG_SOURCE_SHADER_COMPILER:		printf(" in the shader compiler");			break;
	case GL_DEBUG_SOURCE_THIRD_PARTY:			printf(" in third party code");				break;
	case GL_DEBUG_SOURCE_APPLICATION:			printf(" in this program");					break;
	case GL_DEBUG_SOURCE_OTHER:					printf(" in an undefined source");			break;
	default:									printf(" nowhere(?)");						break;
	}

	printf(", id %u:\n%.*s\n", id, length, message);
	// this is invaluable; you can directly see where any opengl error originated by checking the call stack at this breakpoint
	if (type == GL_DEBUG_TYPE_ERROR)
#ifdef _WIN32
		__debugbreak();
#else
		raise(SIGTRAP);
#endif
}

void setupDebug() {
	// enable debug output
	glEnable(GL_DEBUG_OUTPUT);
	// debug output from main thread: get the correct stack frame when breaking
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

	glDebugMessageCallback((GLDEBUGPROC)glDebugCallback, 0);

	// query everything about errors, deprecated and undefined things
	glDebugMessageControl(GL_DONT_CARE, GL_DEBUG_TYPE_ERROR, GL_DONT_CARE, 0, 0, GL_TRUE);
	glDebugMessageControl(GL_DONT_CARE, GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR, GL_DONT_CARE, 0, 0, GL_TRUE);
	glDebugMessageControl(GL_DONT_CARE, GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR, GL_DONT_CARE, 0, 0, GL_TRUE);

	// disable misc info. might want to check these from time to time!
	glDebugMessageControl(GL_DONT_CARE, GL_DEBUG_TYPE_OTHER, GL_DONT_CARE, 0, 0, GL_FALSE);
	glDebugMessageControl(GL_DONT_CARE, GL_DEBUG_TYPE_PERFORMANCE, GL_DONT_CARE, 0, 0, GL_FALSE);
}

#ifdef _WIN32

#include "wglext.h"

#pragma comment(lib, "opengl32.lib")

const int GL_WINDOW_ATTRIBUTES[] = {
	WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
	WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
	WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
	WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB, GL_TRUE,
	//WGL_SAMPLES_ARB, 8, // MSAA

	WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
	WGL_COLOR_BITS_ARB, 32,
	WGL_DEPTH_BITS_ARB, 24,
0 };

const int GL_CONTEXT_ATTRIBUTES[] = {
	WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
	WGL_CONTEXT_MINOR_VERSION_ARB, 6,
	WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
	//WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
0 };

HWND wnd = nullptr;
HDC dc;
HGLRC rc;

// update the frame onto screen
void swapBuffers() {
	SwapBuffers(dc);
}

void setTitle(const char* title) {
	SetWindowTextA(wnd, title);
}

ivec2 getMouse() {
	POINT mouse;
	GetCursorPos(&mouse);
	ScreenToClient(wnd, &mouse);
	return ivec2(mouse.x, mouse.y);
}

void setMouse(ivec2 p) {
	POINT p_{ p.x, p.y };
	ClientToScreen(wnd, &p_);
	SetCursorPos(p_.x, p_.y);
}

ivec2 windowSize() {
	RECT r;
	GetClientRect(wnd, &r);
	return { r.right - r.left, r.bottom - r.top };
}

WPARAM down[256]; int downptr = 0;
WPARAM hit[256]; int hitptr = 0;

bool keyDown(uint vk_code) {
	for (int i = 0; i < downptr; ++i)
		if (vk_code == down[i])
			return true;
	return false;
}

bool keyHit(uint vk_code) {
	for (int i = 0; i < hitptr; ++i)
		if (vk_code == hit[i])
			return true;
	return false;
}

void resetHits() {
	hitptr = 0;
}

inline WPARAM mapExtended(WPARAM wParam, LPARAM lParam) {
	int ext = (lParam>>24)&1;
	switch(wParam) {
		case VK_SHIFT: return MapVirtualKeyEx((lParam >> 16) & 0xFF, MAPVK_VSC_TO_VK_EX, GetKeyboardLayout(0));
		case VK_CONTROL: return VK_LCONTROL+ext;
		case VK_MENU: return VK_LMENU+ext;
		case VK_RETURN: return VK_RETURN + ext*(VK_SEPARATOR-VK_RETURN);
		default: return wParam;
	}
}

LRESULT CALLBACK wndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	case WM_SYSKEYDOWN:
	case WM_KEYDOWN:
		wParam = mapExtended(wParam, lParam);
		if (!keyDown((UINT)wParam))
			down[downptr++] = hit[hitptr++] = wParam; // todo: if mapNarrowed(wParam)!=wParam: also add mapNarrowed()
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);
		return 0;
	case WM_SYSKEYUP:
	case WM_KEYUP:
		wParam = mapExtended(wParam, lParam);
		for (int i = 0; i < downptr - 1; ++i) // todo: if mapNarrowed(wParam)!=wParam: also remove mapNarrowed()
			if (wParam == down[i]) {
				down[i] = down[downptr-1];
				break;
			}
		if (downptr > 0) downptr--;
		return 0;
	case WM_KILLFOCUS:
	//	hitptr = downptr = 0;
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

bool loop() {
	hitptr = 0;
	MSG msg;
	bool result = true;
	while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (msg.message == WM_QUIT) {
			result = false;
			break;
		}
	}
	return result;
}

void setupGL(int width, int height, const char* title, bool fullscreen, bool show) {

	if (glOpen()) return;

	WNDCLASSEX windowClass = { 0 };
	windowClass.cbSize = sizeof(windowClass);
	windowClass.hInstance = GetModuleHandle(nullptr);
	windowClass.lpszClassName = TEXT("classy class");
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	windowClass.style = CS_OWNDC;
	windowClass.lpfnWndProc = wndProc;
	RegisterClassEx(&windowClass);

	PIXELFORMATDESCRIPTOR formatDesc = { 0 };
	formatDesc.nVersion = 1;
	formatDesc.nSize = sizeof(formatDesc);
	formatDesc.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	formatDesc.iLayerType = PFD_MAIN_PLANE;
	formatDesc.iPixelType = PFD_TYPE_RGBA;
	formatDesc.cColorBits = 32;
	formatDesc.cDepthBits = 24;
	formatDesc.cStencilBits = 8;

	// create a temporary window to have a functional opengl context in order to get some extension function pointers
	HWND tempWnd = CreateWindow(TEXT("classy class"), TEXT("windy window"), WS_POPUP, 0, 0, width, height, nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
	HDC tempDC = GetDC(tempWnd);
	SetPixelFormat(tempDC, ChoosePixelFormat(tempDC, &formatDesc), &formatDesc);
	HGLRC tempRC = wglCreateContext(tempDC);
	wglMakeCurrent(tempDC, tempRC);

	// these are why we made the temporary context; can set more pixel format attributes (multisample, floating point etc.) and create debug/core/etc contexts
	auto wglChoosePixelFormat = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
	auto wglCreateContextAttribs = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");

	// adjust the window borders away, center the window
	RECT area = { 0, 0, width, height };
	const DWORD style = (fullscreen ? WS_POPUP : (WS_SYSMENU|WS_CAPTION|WS_MINIMIZEBOX)) | ((fullscreen||show)?WS_VISIBLE:0);
	if (fullscreen) {
		DEVMODE mode = { 0 };
		mode.dmSize = sizeof(mode);
		mode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | DM_BITSPERPEL;
		mode.dmPelsWidth = width; mode.dmPelsHeight = height;
		mode.dmBitsPerPel = 32;
		ChangeDisplaySettings(&mode, CDS_FULLSCREEN);
	}

	AdjustWindowRect(&area, style, false);
	int adjustedWidth = fullscreen ? width : area.right - area.left, adjustedHeight = fullscreen ? height : area.bottom - area.top;
	int centerX = (GetSystemMetrics(SM_CXSCREEN) - adjustedWidth) / 2, centerY = (GetSystemMetrics(SM_CYSCREEN) - adjustedHeight) / 2;
	if (fullscreen)
		centerX = centerY = 0;

	// create the final window and context
	dc = GetDC(wnd = CreateWindowA("classy class", title, style, centerX, centerY, adjustedWidth, adjustedHeight, nullptr, nullptr, GetModuleHandle(nullptr), nullptr));

	int format; UINT numFormats;
	wglChoosePixelFormat(dc, GL_WINDOW_ATTRIBUTES, nullptr, 1, &format, &numFormats);

	SetPixelFormat(dc, format, &formatDesc);

	rc = wglCreateContextAttribs(dc, 0, GL_CONTEXT_ATTRIBUTES);

	wglMakeCurrent(dc, rc);
	glViewport(0, 0, width, height);

	// release the temporary window and context
	wglDeleteContext(tempRC);
	ReleaseDC(tempWnd, tempDC);
	DestroyWindow(tempWnd);

	// what GL did we get?
	printf("gl  %s\non  %s\nby  %s\nsl  %s\n", glGetString(GL_VERSION), glGetString(GL_RENDERER), glGetString(GL_VENDOR), glGetString(GL_SHADING_LANGUAGE_VERSION));

	loadgl();

	setupDebug();
	glEnable(GL_FRAMEBUFFER_SRGB);
}

#include <crtdbg.h>
void closeGL() {
	if (!glOpen()) return;

	// release context, window
	ChangeDisplaySettings(nullptr, CDS_FULLSCREEN);
	wglMakeCurrent(0, 0);
	wglDeleteContext(rc);
	ReleaseDC(wnd, dc);
	DestroyWindow(wnd);
	wnd = nullptr;
	UnregisterClass(TEXT("classy class"), GetModuleHandle(nullptr));
	_CrtDumpMemoryLeaks();
}

bool glOpen() {
	return wnd != nullptr;
}

void showWindow() {
	ShowWindow(wnd, SW_SHOW);
}

void hideWindow() {
	ShowWindow(wnd, SW_HIDE);
}

#else

#ifdef HEADLESS
#define EGL_NO_X11
#define MESA_EGL_NO_X11_HEADERS
#else
#include <X11/Xlib.h>
Display* xdisplay = nullptr;
Window xwindow;
#endif

#include <EGL/egl.h>
#include <EGL/eglext.h>

#define GLAPIENTRY

#include <stdio.h>

EGLDisplay display;
EGLContext context;

EGLSurface surface = EGL_NO_SURFACE;

ivec2 windowsize{};

void setupGL(int width, int height, const char* title, bool fullscreen, bool show) {
	windowsize = ivec2(width, height);
#ifndef HEADLESS
	xdisplay = XOpenDisplay(nullptr);
	XSetWindowAttributes window_attributes = {0};
	window_attributes.event_mask = ExposureMask | PointerMotionMask | KeyPressMask;
	xwindow = XCreateWindow(xdisplay, DefaultRootWindow(xdisplay), 0, 0, width, height, 0, CopyFromParent, InputOutput, CopyFromParent, CWEventMask, &window_attributes);
	XStoreName(xdisplay, xwindow, title);
	XMapWindow(xdisplay, xwindow);
	display = eglGetDisplay((EGLNativeDisplayType)xdisplay);
#else
	display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
#endif
	EGLint major, minor;
	eglInitialize(display, &major, &minor);
	const EGLint config_attributes[] = {
		EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8,
		EGL_DEPTH_SIZE, 24, EGL_STENCIL_SIZE, 8,
		EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
#ifdef HEADLESS
		EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
#endif
		EGL_NONE
	};

	eglBindAPI(EGL_OPENGL_API);

	EGLConfig config; EGLint configCount;
	eglChooseConfig(display, config_attributes, &config, 1, &configCount);

	const EGLint context_attributes[] = {
		EGL_CONTEXT_MAJOR_VERSION, 4,
		EGL_CONTEXT_MINOR_VERSION, 6,
		EGL_CONTEXT_OPENGL_PROFILE_MASK, EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT,
		EGL_NONE
	};
	context = eglCreateContext(display, config, EGL_NO_CONTEXT, context_attributes);
#ifndef HEADLESS
	EGLint surface_attributes[] = {
		EGL_GL_COLORSPACE, EGL_GL_COLORSPACE_LINEAR,
		EGL_RENDER_BUFFER, EGL_BACK_BUFFER,
		EGL_NONE
	};
	surface = eglCreateWindowSurface(display, config, xwindow, surface_attributes);
#else
	EGLint surface_attributes[] = {
		//EGL_GL_COLORSPACE, EGL_GL_COLORSPACE_LINEAR,
		//EGL_TEXTURE_FORMAT, EGL_TEXTURE_RGBA,
		//EGL_TEXTURE_TARGET, EGL_TEXTURE_2D,
		EGL_WIDTH, width, EGL_HEIGHT, height,
		EGL_NONE
	};
	surface = eglCreatePbufferSurface(display, config, surface_attributes);
#endif
	eglMakeCurrent(display, surface, surface, context);
	loadgl();

	setupDebug();
	glEnable(GL_FRAMEBUFFER_SRGB);
}
void closeGL() {
	eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
	eglDestroySurface(display, surface);
	eglDestroyContext(display, context);
	eglTerminate(display);
#ifndef HEADLESS
	XDestroyWindow(xdisplay, xwindow);
	XCloseDisplay(xdisplay);
#endif
}
bool loop() {
#ifdef HEADLESS
	return false;
#else
	return true;
#endif
}
bool glOpen() {
	return surface!=EGL_NO_SURFACE;
}
void swapBuffers() {
	//printf("oh lord is it this\n");
	eglSwapBuffers(display, surface);
}
void setTitle(const char* title) {}
void showWindow() {}
void hideWindow() {}

int down[256]; int downptr = 0;
int hit[256]; int hitptr = 0;

bool keyDown(uint vk_code) {
	for (int i = 0; i < downptr; ++i)
		if (vk_code == down[i])
			return true;
	return false;
}

bool keyHit(uint vk_code) {
	for (int i = 0; i < hitptr; ++i)
		if (vk_code == hit[i])
			return true;
	return false;
}

void resetHits() {
	hitptr = 0;
}

ivec2 getMouse() { return {};}
void setMouse(ivec2) {}

ivec2 windowSize() {
	return windowsize;
}

#endif
