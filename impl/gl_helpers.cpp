
#ifdef _WIN32
#include <Windows.h>

#include "gl_helpers.h"

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
#include <locale>
#include <codecvt>

Texture<GL_TEXTURE_2D> loadImage(const wchar_t* path) {
	using namespace Gdiplus;
	ULONG_PTR token;
	GdiplusStartupInput startupInput;
	GdiplusStartup(&token, &startupInput, nullptr);

	Texture<GL_TEXTURE_2D> result;
	// new scope so RAII objects are released before gdi+ shutdown
	{
		Image image(path);
		image.RotateFlip(RotateNoneFlipY);
		const Rect r(0, 0, image.GetWidth(), image.GetHeight());
		BitmapData data;
		((Bitmap*)&image)->LockBits(&r, ImageLockModeRead, PixelFormat32bppARGB, &data);

		glBindTexture(GL_TEXTURE_2D, result);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image.GetWidth(), image.GetHeight(), 0, GL_BGRA, GL_UNSIGNED_BYTE, data.Scan0);
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		((Bitmap*)&image)->UnlockBits(&data);
	}
	GdiplusShutdown(token);
	return result;
}

Texture<GL_TEXTURE_2D> loadImage(const char* path) {
	wchar_t str[1024];
	MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, path, -1, str, 1024);
	return loadImage(str);
}
#else

#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include <png.h>
#include <setjmp.h>
#include "gl_helpers.h"

Texture<GL_TEXTURE_2D> loadImage(const wchar_t* path) {}
Texture<GL_TEXTURE_2D> loadImage(const char* path) {
    unsigned char header[8];

    FILE* fp = fopen(path, "rb");
    fread(header, 1, 8, fp);
    assert(!png_sig_cmp(header, 0, 8));

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    png_infop info = png_create_info_struct(png);

    setjmp(png_jmpbuf(png));
    
	png_init_io(png, fp);
    png_set_sig_bytes(png, 8);

    png_read_info(png, info);

    int width = png_get_image_width(png, info);
    int height = png_get_image_height(png, info);
    png_byte color_type = png_get_color_type(png, info);
    png_byte bit_depth = png_get_bit_depth(png, info);
	assert(bit_depth == 8); // let's just support this

    int number_of_passes = png_set_interlace_handling(png);
    png_read_update_info(png, info);


	setjmp(png_jmpbuf(png));

    png_bytep* row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
	size_t stride = png_get_rowbytes(png, info);
    for (int i = 0; i < height; i++)
        row_pointers[i] = (png_byte*)malloc(stride);

    png_read_image(png, row_pointers);

	unsigned char* contiguous = (unsigned char*)malloc(stride * height);

	for (int i = 0; i < height; i++)
		memcpy(contiguous + stride * (height-1-i), row_pointers[i], stride);

	GLenum format = GL_INVALID_ENUM, order;
	if (PNG_COLOR_TYPE_GRAY == color_type) { format = GL_R8; order = GL_RED; }
	if (PNG_COLOR_TYPE_RGB == color_type) { format = GL_RGB8; order = GL_RGB; }
	if (PNG_COLOR_TYPE_RGB_ALPHA == color_type) { format = GL_RGBA8; order = GL_RGBA; }
	assert(format != GL_INVALID_ENUM);

	Texture<GL_TEXTURE_2D> result;
	glBindTexture(GL_TEXTURE_2D, result);
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, order, GL_UNSIGNED_BYTE, contiguous);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	free(row_pointers);
    fclose(fp);

	return result;
}
#endif

