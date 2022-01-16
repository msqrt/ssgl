
#ifdef _WIN32
#include <Windows.h>
#endif

#define GL_GLEXT_LEGACY
#include <GL/gl.h>
#undef GL_VERSION_1_3
#include "glext.h"
#include "loadgl46.h"

PFNGLDRAWRANGEELEMENTSPROC ptr_glDrawRangeElements = nullptr; void  glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) { ptr_glDrawRangeElements(mode, start, end, count, type, indices); }
PFNGLTEXIMAGE3DPROC ptr_glTexImage3D = nullptr; void  glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) { ptr_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
PFNGLTEXSUBIMAGE3DPROC ptr_glTexSubImage3D = nullptr; void  glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) { ptr_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
PFNGLCOPYTEXSUBIMAGE3DPROC ptr_glCopyTexSubImage3D = nullptr; void  glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { ptr_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }
PFNGLACTIVETEXTUREPROC ptr_glActiveTexture = nullptr; void  glActiveTexture(GLenum texture) { ptr_glActiveTexture(texture); }
PFNGLSAMPLECOVERAGEPROC ptr_glSampleCoverage = nullptr; void  glSampleCoverage(GLfloat value, GLboolean invert) { ptr_glSampleCoverage(value, invert); }
PFNGLCOMPRESSEDTEXIMAGE3DPROC ptr_glCompressedTexImage3D = nullptr; void  glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) { ptr_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
PFNGLCOMPRESSEDTEXIMAGE2DPROC ptr_glCompressedTexImage2D = nullptr; void  glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) { ptr_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
PFNGLCOMPRESSEDTEXIMAGE1DPROC ptr_glCompressedTexImage1D = nullptr; void  glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) { ptr_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data); }
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC ptr_glCompressedTexSubImage3D = nullptr; void  glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) { ptr_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC ptr_glCompressedTexSubImage2D = nullptr; void  glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) { ptr_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC ptr_glCompressedTexSubImage1D = nullptr; void  glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) { ptr_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data); }
PFNGLGETCOMPRESSEDTEXIMAGEPROC ptr_glGetCompressedTexImage = nullptr; void  glGetCompressedTexImage(GLenum target, GLint level, void *img) { ptr_glGetCompressedTexImage(target, level, img); }
PFNGLCLIENTACTIVETEXTUREPROC ptr_glClientActiveTexture = nullptr; void  glClientActiveTexture(GLenum texture) { ptr_glClientActiveTexture(texture); }
PFNGLMULTITEXCOORD1DPROC ptr_glMultiTexCoord1d = nullptr; void  glMultiTexCoord1d(GLenum target, GLdouble s) { ptr_glMultiTexCoord1d(target, s); }
PFNGLMULTITEXCOORD1DVPROC ptr_glMultiTexCoord1dv = nullptr; void  glMultiTexCoord1dv(GLenum target, const GLdouble *v) { ptr_glMultiTexCoord1dv(target, v); }
PFNGLMULTITEXCOORD1FPROC ptr_glMultiTexCoord1f = nullptr; void  glMultiTexCoord1f(GLenum target, GLfloat s) { ptr_glMultiTexCoord1f(target, s); }
PFNGLMULTITEXCOORD1FVPROC ptr_glMultiTexCoord1fv = nullptr; void  glMultiTexCoord1fv(GLenum target, const GLfloat *v) { ptr_glMultiTexCoord1fv(target, v); }
PFNGLMULTITEXCOORD1IPROC ptr_glMultiTexCoord1i = nullptr; void  glMultiTexCoord1i(GLenum target, GLint s) { ptr_glMultiTexCoord1i(target, s); }
PFNGLMULTITEXCOORD1IVPROC ptr_glMultiTexCoord1iv = nullptr; void  glMultiTexCoord1iv(GLenum target, const GLint *v) { ptr_glMultiTexCoord1iv(target, v); }
PFNGLMULTITEXCOORD1SPROC ptr_glMultiTexCoord1s = nullptr; void  glMultiTexCoord1s(GLenum target, GLshort s) { ptr_glMultiTexCoord1s(target, s); }
PFNGLMULTITEXCOORD1SVPROC ptr_glMultiTexCoord1sv = nullptr; void  glMultiTexCoord1sv(GLenum target, const GLshort *v) { ptr_glMultiTexCoord1sv(target, v); }
PFNGLMULTITEXCOORD2DPROC ptr_glMultiTexCoord2d = nullptr; void  glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) { ptr_glMultiTexCoord2d(target, s, t); }
PFNGLMULTITEXCOORD2DVPROC ptr_glMultiTexCoord2dv = nullptr; void  glMultiTexCoord2dv(GLenum target, const GLdouble *v) { ptr_glMultiTexCoord2dv(target, v); }
PFNGLMULTITEXCOORD2FPROC ptr_glMultiTexCoord2f = nullptr; void  glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) { ptr_glMultiTexCoord2f(target, s, t); }
PFNGLMULTITEXCOORD2FVPROC ptr_glMultiTexCoord2fv = nullptr; void  glMultiTexCoord2fv(GLenum target, const GLfloat *v) { ptr_glMultiTexCoord2fv(target, v); }
PFNGLMULTITEXCOORD2IPROC ptr_glMultiTexCoord2i = nullptr; void  glMultiTexCoord2i(GLenum target, GLint s, GLint t) { ptr_glMultiTexCoord2i(target, s, t); }
PFNGLMULTITEXCOORD2IVPROC ptr_glMultiTexCoord2iv = nullptr; void  glMultiTexCoord2iv(GLenum target, const GLint *v) { ptr_glMultiTexCoord2iv(target, v); }
PFNGLMULTITEXCOORD2SPROC ptr_glMultiTexCoord2s = nullptr; void  glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) { ptr_glMultiTexCoord2s(target, s, t); }
PFNGLMULTITEXCOORD2SVPROC ptr_glMultiTexCoord2sv = nullptr; void  glMultiTexCoord2sv(GLenum target, const GLshort *v) { ptr_glMultiTexCoord2sv(target, v); }
PFNGLMULTITEXCOORD3DPROC ptr_glMultiTexCoord3d = nullptr; void  glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) { ptr_glMultiTexCoord3d(target, s, t, r); }
PFNGLMULTITEXCOORD3DVPROC ptr_glMultiTexCoord3dv = nullptr; void  glMultiTexCoord3dv(GLenum target, const GLdouble *v) { ptr_glMultiTexCoord3dv(target, v); }
PFNGLMULTITEXCOORD3FPROC ptr_glMultiTexCoord3f = nullptr; void  glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) { ptr_glMultiTexCoord3f(target, s, t, r); }
PFNGLMULTITEXCOORD3FVPROC ptr_glMultiTexCoord3fv = nullptr; void  glMultiTexCoord3fv(GLenum target, const GLfloat *v) { ptr_glMultiTexCoord3fv(target, v); }
PFNGLMULTITEXCOORD3IPROC ptr_glMultiTexCoord3i = nullptr; void  glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) { ptr_glMultiTexCoord3i(target, s, t, r); }
PFNGLMULTITEXCOORD3IVPROC ptr_glMultiTexCoord3iv = nullptr; void  glMultiTexCoord3iv(GLenum target, const GLint *v) { ptr_glMultiTexCoord3iv(target, v); }
PFNGLMULTITEXCOORD3SPROC ptr_glMultiTexCoord3s = nullptr; void  glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) { ptr_glMultiTexCoord3s(target, s, t, r); }
PFNGLMULTITEXCOORD3SVPROC ptr_glMultiTexCoord3sv = nullptr; void  glMultiTexCoord3sv(GLenum target, const GLshort *v) { ptr_glMultiTexCoord3sv(target, v); }
PFNGLMULTITEXCOORD4DPROC ptr_glMultiTexCoord4d = nullptr; void  glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) { ptr_glMultiTexCoord4d(target, s, t, r, q); }
PFNGLMULTITEXCOORD4DVPROC ptr_glMultiTexCoord4dv = nullptr; void  glMultiTexCoord4dv(GLenum target, const GLdouble *v) { ptr_glMultiTexCoord4dv(target, v); }
PFNGLMULTITEXCOORD4FPROC ptr_glMultiTexCoord4f = nullptr; void  glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) { ptr_glMultiTexCoord4f(target, s, t, r, q); }
PFNGLMULTITEXCOORD4FVPROC ptr_glMultiTexCoord4fv = nullptr; void  glMultiTexCoord4fv(GLenum target, const GLfloat *v) { ptr_glMultiTexCoord4fv(target, v); }
PFNGLMULTITEXCOORD4IPROC ptr_glMultiTexCoord4i = nullptr; void  glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) { ptr_glMultiTexCoord4i(target, s, t, r, q); }
PFNGLMULTITEXCOORD4IVPROC ptr_glMultiTexCoord4iv = nullptr; void  glMultiTexCoord4iv(GLenum target, const GLint *v) { ptr_glMultiTexCoord4iv(target, v); }
PFNGLMULTITEXCOORD4SPROC ptr_glMultiTexCoord4s = nullptr; void  glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) { ptr_glMultiTexCoord4s(target, s, t, r, q); }
PFNGLMULTITEXCOORD4SVPROC ptr_glMultiTexCoord4sv = nullptr; void  glMultiTexCoord4sv(GLenum target, const GLshort *v) { ptr_glMultiTexCoord4sv(target, v); }
PFNGLLOADTRANSPOSEMATRIXFPROC ptr_glLoadTransposeMatrixf = nullptr; void  glLoadTransposeMatrixf(const GLfloat *m) { ptr_glLoadTransposeMatrixf(m); }
PFNGLLOADTRANSPOSEMATRIXDPROC ptr_glLoadTransposeMatrixd = nullptr; void  glLoadTransposeMatrixd(const GLdouble *m) { ptr_glLoadTransposeMatrixd(m); }
PFNGLMULTTRANSPOSEMATRIXFPROC ptr_glMultTransposeMatrixf = nullptr; void  glMultTransposeMatrixf(const GLfloat *m) { ptr_glMultTransposeMatrixf(m); }
PFNGLMULTTRANSPOSEMATRIXDPROC ptr_glMultTransposeMatrixd = nullptr; void  glMultTransposeMatrixd(const GLdouble *m) { ptr_glMultTransposeMatrixd(m); }
PFNGLBLENDFUNCSEPARATEPROC ptr_glBlendFuncSeparate = nullptr; void  glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) { ptr_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
PFNGLMULTIDRAWARRAYSPROC ptr_glMultiDrawArrays = nullptr; void  glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) { ptr_glMultiDrawArrays(mode, first, count, drawcount); }
PFNGLMULTIDRAWELEMENTSPROC ptr_glMultiDrawElements = nullptr; void  glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) { ptr_glMultiDrawElements(mode, count, type, indices, drawcount); }
PFNGLPOINTPARAMETERFPROC ptr_glPointParameterf = nullptr; void  glPointParameterf(GLenum pname, GLfloat param) { ptr_glPointParameterf(pname, param); }
PFNGLPOINTPARAMETERFVPROC ptr_glPointParameterfv = nullptr; void  glPointParameterfv(GLenum pname, const GLfloat *params) { ptr_glPointParameterfv(pname, params); }
PFNGLPOINTPARAMETERIPROC ptr_glPointParameteri = nullptr; void  glPointParameteri(GLenum pname, GLint param) { ptr_glPointParameteri(pname, param); }
PFNGLPOINTPARAMETERIVPROC ptr_glPointParameteriv = nullptr; void  glPointParameteriv(GLenum pname, const GLint *params) { ptr_glPointParameteriv(pname, params); }
PFNGLFOGCOORDFPROC ptr_glFogCoordf = nullptr; void  glFogCoordf(GLfloat coord) { ptr_glFogCoordf(coord); }
PFNGLFOGCOORDFVPROC ptr_glFogCoordfv = nullptr; void  glFogCoordfv(const GLfloat *coord) { ptr_glFogCoordfv(coord); }
PFNGLFOGCOORDDPROC ptr_glFogCoordd = nullptr; void  glFogCoordd(GLdouble coord) { ptr_glFogCoordd(coord); }
PFNGLFOGCOORDDVPROC ptr_glFogCoorddv = nullptr; void  glFogCoorddv(const GLdouble *coord) { ptr_glFogCoorddv(coord); }
PFNGLFOGCOORDPOINTERPROC ptr_glFogCoordPointer = nullptr; void  glFogCoordPointer(GLenum type, GLsizei stride, const void *pointer) { ptr_glFogCoordPointer(type, stride, pointer); }
PFNGLSECONDARYCOLOR3BPROC ptr_glSecondaryColor3b = nullptr; void  glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) { ptr_glSecondaryColor3b(red, green, blue); }
PFNGLSECONDARYCOLOR3BVPROC ptr_glSecondaryColor3bv = nullptr; void  glSecondaryColor3bv(const GLbyte *v) { ptr_glSecondaryColor3bv(v); }
PFNGLSECONDARYCOLOR3DPROC ptr_glSecondaryColor3d = nullptr; void  glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) { ptr_glSecondaryColor3d(red, green, blue); }
PFNGLSECONDARYCOLOR3DVPROC ptr_glSecondaryColor3dv = nullptr; void  glSecondaryColor3dv(const GLdouble *v) { ptr_glSecondaryColor3dv(v); }
PFNGLSECONDARYCOLOR3FPROC ptr_glSecondaryColor3f = nullptr; void  glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) { ptr_glSecondaryColor3f(red, green, blue); }
PFNGLSECONDARYCOLOR3FVPROC ptr_glSecondaryColor3fv = nullptr; void  glSecondaryColor3fv(const GLfloat *v) { ptr_glSecondaryColor3fv(v); }
PFNGLSECONDARYCOLOR3IPROC ptr_glSecondaryColor3i = nullptr; void  glSecondaryColor3i(GLint red, GLint green, GLint blue) { ptr_glSecondaryColor3i(red, green, blue); }
PFNGLSECONDARYCOLOR3IVPROC ptr_glSecondaryColor3iv = nullptr; void  glSecondaryColor3iv(const GLint *v) { ptr_glSecondaryColor3iv(v); }
PFNGLSECONDARYCOLOR3SPROC ptr_glSecondaryColor3s = nullptr; void  glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) { ptr_glSecondaryColor3s(red, green, blue); }
PFNGLSECONDARYCOLOR3SVPROC ptr_glSecondaryColor3sv = nullptr; void  glSecondaryColor3sv(const GLshort *v) { ptr_glSecondaryColor3sv(v); }
PFNGLSECONDARYCOLOR3UBPROC ptr_glSecondaryColor3ub = nullptr; void  glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) { ptr_glSecondaryColor3ub(red, green, blue); }
PFNGLSECONDARYCOLOR3UBVPROC ptr_glSecondaryColor3ubv = nullptr; void  glSecondaryColor3ubv(const GLubyte *v) { ptr_glSecondaryColor3ubv(v); }
PFNGLSECONDARYCOLOR3UIPROC ptr_glSecondaryColor3ui = nullptr; void  glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) { ptr_glSecondaryColor3ui(red, green, blue); }
PFNGLSECONDARYCOLOR3UIVPROC ptr_glSecondaryColor3uiv = nullptr; void  glSecondaryColor3uiv(const GLuint *v) { ptr_glSecondaryColor3uiv(v); }
PFNGLSECONDARYCOLOR3USPROC ptr_glSecondaryColor3us = nullptr; void  glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) { ptr_glSecondaryColor3us(red, green, blue); }
PFNGLSECONDARYCOLOR3USVPROC ptr_glSecondaryColor3usv = nullptr; void  glSecondaryColor3usv(const GLushort *v) { ptr_glSecondaryColor3usv(v); }
PFNGLSECONDARYCOLORPOINTERPROC ptr_glSecondaryColorPointer = nullptr; void  glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) { ptr_glSecondaryColorPointer(size, type, stride, pointer); }
PFNGLWINDOWPOS2DPROC ptr_glWindowPos2d = nullptr; void  glWindowPos2d(GLdouble x, GLdouble y) { ptr_glWindowPos2d(x, y); }
PFNGLWINDOWPOS2DVPROC ptr_glWindowPos2dv = nullptr; void  glWindowPos2dv(const GLdouble *v) { ptr_glWindowPos2dv(v); }
PFNGLWINDOWPOS2FPROC ptr_glWindowPos2f = nullptr; void  glWindowPos2f(GLfloat x, GLfloat y) { ptr_glWindowPos2f(x, y); }
PFNGLWINDOWPOS2FVPROC ptr_glWindowPos2fv = nullptr; void  glWindowPos2fv(const GLfloat *v) { ptr_glWindowPos2fv(v); }
PFNGLWINDOWPOS2IPROC ptr_glWindowPos2i = nullptr; void  glWindowPos2i(GLint x, GLint y) { ptr_glWindowPos2i(x, y); }
PFNGLWINDOWPOS2IVPROC ptr_glWindowPos2iv = nullptr; void  glWindowPos2iv(const GLint *v) { ptr_glWindowPos2iv(v); }
PFNGLWINDOWPOS2SPROC ptr_glWindowPos2s = nullptr; void  glWindowPos2s(GLshort x, GLshort y) { ptr_glWindowPos2s(x, y); }
PFNGLWINDOWPOS2SVPROC ptr_glWindowPos2sv = nullptr; void  glWindowPos2sv(const GLshort *v) { ptr_glWindowPos2sv(v); }
PFNGLWINDOWPOS3DPROC ptr_glWindowPos3d = nullptr; void  glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) { ptr_glWindowPos3d(x, y, z); }
PFNGLWINDOWPOS3DVPROC ptr_glWindowPos3dv = nullptr; void  glWindowPos3dv(const GLdouble *v) { ptr_glWindowPos3dv(v); }
PFNGLWINDOWPOS3FPROC ptr_glWindowPos3f = nullptr; void  glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) { ptr_glWindowPos3f(x, y, z); }
PFNGLWINDOWPOS3FVPROC ptr_glWindowPos3fv = nullptr; void  glWindowPos3fv(const GLfloat *v) { ptr_glWindowPos3fv(v); }
PFNGLWINDOWPOS3IPROC ptr_glWindowPos3i = nullptr; void  glWindowPos3i(GLint x, GLint y, GLint z) { ptr_glWindowPos3i(x, y, z); }
PFNGLWINDOWPOS3IVPROC ptr_glWindowPos3iv = nullptr; void  glWindowPos3iv(const GLint *v) { ptr_glWindowPos3iv(v); }
PFNGLWINDOWPOS3SPROC ptr_glWindowPos3s = nullptr; void  glWindowPos3s(GLshort x, GLshort y, GLshort z) { ptr_glWindowPos3s(x, y, z); }
PFNGLWINDOWPOS3SVPROC ptr_glWindowPos3sv = nullptr; void  glWindowPos3sv(const GLshort *v) { ptr_glWindowPos3sv(v); }
PFNGLBLENDCOLORPROC ptr_glBlendColor = nullptr; void  glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { ptr_glBlendColor(red, green, blue, alpha); }
PFNGLBLENDEQUATIONPROC ptr_glBlendEquation = nullptr; void  glBlendEquation(GLenum mode) { ptr_glBlendEquation(mode); }
PFNGLGENQUERIESPROC ptr_glGenQueries = nullptr; void  glGenQueries(GLsizei n, GLuint *ids) { ptr_glGenQueries(n, ids); }
PFNGLDELETEQUERIESPROC ptr_glDeleteQueries = nullptr; void  glDeleteQueries(GLsizei n, const GLuint *ids) { ptr_glDeleteQueries(n, ids); }
PFNGLISQUERYPROC ptr_glIsQuery = nullptr; GLboolean  glIsQuery(GLuint id) { return ptr_glIsQuery(id); }
PFNGLBEGINQUERYPROC ptr_glBeginQuery = nullptr; void  glBeginQuery(GLenum target, GLuint id) { ptr_glBeginQuery(target, id); }
PFNGLENDQUERYPROC ptr_glEndQuery = nullptr; void  glEndQuery(GLenum target) { ptr_glEndQuery(target); }
PFNGLGETQUERYIVPROC ptr_glGetQueryiv = nullptr; void  glGetQueryiv(GLenum target, GLenum pname, GLint *params) { ptr_glGetQueryiv(target, pname, params); }
PFNGLGETQUERYOBJECTIVPROC ptr_glGetQueryObjectiv = nullptr; void  glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params) { ptr_glGetQueryObjectiv(id, pname, params); }
PFNGLGETQUERYOBJECTUIVPROC ptr_glGetQueryObjectuiv = nullptr; void  glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) { ptr_glGetQueryObjectuiv(id, pname, params); }
PFNGLBINDBUFFERPROC ptr_glBindBuffer = nullptr; void  glBindBuffer(GLenum target, GLuint buffer) { ptr_glBindBuffer(target, buffer); }
PFNGLDELETEBUFFERSPROC ptr_glDeleteBuffers = nullptr; void  glDeleteBuffers(GLsizei n, const GLuint *buffers) { ptr_glDeleteBuffers(n, buffers); }
PFNGLGENBUFFERSPROC ptr_glGenBuffers = nullptr; void  glGenBuffers(GLsizei n, GLuint *buffers) { ptr_glGenBuffers(n, buffers); }
PFNGLISBUFFERPROC ptr_glIsBuffer = nullptr; GLboolean  glIsBuffer(GLuint buffer) { return ptr_glIsBuffer(buffer); }
PFNGLBUFFERDATAPROC ptr_glBufferData = nullptr; void  glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) { ptr_glBufferData(target, size, data, usage); }
PFNGLBUFFERSUBDATAPROC ptr_glBufferSubData = nullptr; void  glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) { ptr_glBufferSubData(target, offset, size, data); }
PFNGLGETBUFFERSUBDATAPROC ptr_glGetBufferSubData = nullptr; void  glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data) { ptr_glGetBufferSubData(target, offset, size, data); }
PFNGLMAPBUFFERPROC ptr_glMapBuffer = nullptr; void * glMapBuffer(GLenum target, GLenum access) { return ptr_glMapBuffer(target, access); }
PFNGLUNMAPBUFFERPROC ptr_glUnmapBuffer = nullptr; GLboolean  glUnmapBuffer(GLenum target) { return ptr_glUnmapBuffer(target); }
PFNGLGETBUFFERPARAMETERIVPROC ptr_glGetBufferParameteriv = nullptr; void  glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) { ptr_glGetBufferParameteriv(target, pname, params); }
PFNGLGETBUFFERPOINTERVPROC ptr_glGetBufferPointerv = nullptr; void  glGetBufferPointerv(GLenum target, GLenum pname, void **params) { ptr_glGetBufferPointerv(target, pname, params); }
PFNGLBLENDEQUATIONSEPARATEPROC ptr_glBlendEquationSeparate = nullptr; void  glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { ptr_glBlendEquationSeparate(modeRGB, modeAlpha); }
PFNGLDRAWBUFFERSPROC ptr_glDrawBuffers = nullptr; void  glDrawBuffers(GLsizei n, const GLenum *bufs) { ptr_glDrawBuffers(n, bufs); }
PFNGLSTENCILOPSEPARATEPROC ptr_glStencilOpSeparate = nullptr; void  glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { ptr_glStencilOpSeparate(face, sfail, dpfail, dppass); }
PFNGLSTENCILFUNCSEPARATEPROC ptr_glStencilFuncSeparate = nullptr; void  glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { ptr_glStencilFuncSeparate(face, func, ref, mask); }
PFNGLSTENCILMASKSEPARATEPROC ptr_glStencilMaskSeparate = nullptr; void  glStencilMaskSeparate(GLenum face, GLuint mask) { ptr_glStencilMaskSeparate(face, mask); }
PFNGLATTACHSHADERPROC ptr_glAttachShader = nullptr; void  glAttachShader(GLuint program, GLuint shader) { ptr_glAttachShader(program, shader); }
PFNGLBINDATTRIBLOCATIONPROC ptr_glBindAttribLocation = nullptr; void  glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) { ptr_glBindAttribLocation(program, index, name); }
PFNGLCOMPILESHADERPROC ptr_glCompileShader = nullptr; void  glCompileShader(GLuint shader) { ptr_glCompileShader(shader); }
PFNGLCREATEPROGRAMPROC ptr_glCreateProgram = nullptr; GLuint  glCreateProgram(void) { return ptr_glCreateProgram(); }
PFNGLCREATESHADERPROC ptr_glCreateShader = nullptr; GLuint  glCreateShader(GLenum type) { return ptr_glCreateShader(type); }
PFNGLDELETEPROGRAMPROC ptr_glDeleteProgram = nullptr; void  glDeleteProgram(GLuint program) { ptr_glDeleteProgram(program); }
PFNGLDELETESHADERPROC ptr_glDeleteShader = nullptr; void  glDeleteShader(GLuint shader) { ptr_glDeleteShader(shader); }
PFNGLDETACHSHADERPROC ptr_glDetachShader = nullptr; void  glDetachShader(GLuint program, GLuint shader) { ptr_glDetachShader(program, shader); }
PFNGLDISABLEVERTEXATTRIBARRAYPROC ptr_glDisableVertexAttribArray = nullptr; void  glDisableVertexAttribArray(GLuint index) { ptr_glDisableVertexAttribArray(index); }
PFNGLENABLEVERTEXATTRIBARRAYPROC ptr_glEnableVertexAttribArray = nullptr; void  glEnableVertexAttribArray(GLuint index) { ptr_glEnableVertexAttribArray(index); }
PFNGLGETACTIVEATTRIBPROC ptr_glGetActiveAttrib = nullptr; void  glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { ptr_glGetActiveAttrib(program, index, bufSize, length, size, type, name); }
PFNGLGETACTIVEUNIFORMPROC ptr_glGetActiveUniform = nullptr; void  glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { ptr_glGetActiveUniform(program, index, bufSize, length, size, type, name); }
PFNGLGETATTACHEDSHADERSPROC ptr_glGetAttachedShaders = nullptr; void  glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) { ptr_glGetAttachedShaders(program, maxCount, count, shaders); }
PFNGLGETATTRIBLOCATIONPROC ptr_glGetAttribLocation = nullptr; GLint  glGetAttribLocation(GLuint program, const GLchar *name) { return ptr_glGetAttribLocation(program, name); }
PFNGLGETPROGRAMIVPROC ptr_glGetProgramiv = nullptr; void  glGetProgramiv(GLuint program, GLenum pname, GLint *params) { ptr_glGetProgramiv(program, pname, params); }
PFNGLGETPROGRAMINFOLOGPROC ptr_glGetProgramInfoLog = nullptr; void  glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { ptr_glGetProgramInfoLog(program, bufSize, length, infoLog); }
PFNGLGETSHADERIVPROC ptr_glGetShaderiv = nullptr; void  glGetShaderiv(GLuint shader, GLenum pname, GLint *params) { ptr_glGetShaderiv(shader, pname, params); }
PFNGLGETSHADERINFOLOGPROC ptr_glGetShaderInfoLog = nullptr; void  glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { ptr_glGetShaderInfoLog(shader, bufSize, length, infoLog); }
PFNGLGETSHADERSOURCEPROC ptr_glGetShaderSource = nullptr; void  glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) { ptr_glGetShaderSource(shader, bufSize, length, source); }
PFNGLGETUNIFORMLOCATIONPROC ptr_glGetUniformLocation = nullptr; GLint  glGetUniformLocation(GLuint program, const GLchar *name) { return ptr_glGetUniformLocation(program, name); }
PFNGLGETUNIFORMFVPROC ptr_glGetUniformfv = nullptr; void  glGetUniformfv(GLuint program, GLint location, GLfloat *params) { ptr_glGetUniformfv(program, location, params); }
PFNGLGETUNIFORMIVPROC ptr_glGetUniformiv = nullptr; void  glGetUniformiv(GLuint program, GLint location, GLint *params) { ptr_glGetUniformiv(program, location, params); }
PFNGLGETVERTEXATTRIBDVPROC ptr_glGetVertexAttribdv = nullptr; void  glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) { ptr_glGetVertexAttribdv(index, pname, params); }
PFNGLGETVERTEXATTRIBFVPROC ptr_glGetVertexAttribfv = nullptr; void  glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { ptr_glGetVertexAttribfv(index, pname, params); }
PFNGLGETVERTEXATTRIBIVPROC ptr_glGetVertexAttribiv = nullptr; void  glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) { ptr_glGetVertexAttribiv(index, pname, params); }
PFNGLGETVERTEXATTRIBPOINTERVPROC ptr_glGetVertexAttribPointerv = nullptr; void  glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) { ptr_glGetVertexAttribPointerv(index, pname, pointer); }
PFNGLISPROGRAMPROC ptr_glIsProgram = nullptr; GLboolean  glIsProgram(GLuint program) { return ptr_glIsProgram(program); }
PFNGLISSHADERPROC ptr_glIsShader = nullptr; GLboolean  glIsShader(GLuint shader) { return ptr_glIsShader(shader); }
PFNGLLINKPROGRAMPROC ptr_glLinkProgram = nullptr; void  glLinkProgram(GLuint program) { ptr_glLinkProgram(program); }
PFNGLSHADERSOURCEPROC ptr_glShaderSource = nullptr; void  glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) { ptr_glShaderSource(shader, count, string, length); }
PFNGLUSEPROGRAMPROC ptr_glUseProgram = nullptr; void  glUseProgram(GLuint program) { ptr_glUseProgram(program); }
PFNGLUNIFORM1FPROC ptr_glUniform1f = nullptr; void  glUniform1f(GLint location, GLfloat v0) { ptr_glUniform1f(location, v0); }
PFNGLUNIFORM2FPROC ptr_glUniform2f = nullptr; void  glUniform2f(GLint location, GLfloat v0, GLfloat v1) { ptr_glUniform2f(location, v0, v1); }
PFNGLUNIFORM3FPROC ptr_glUniform3f = nullptr; void  glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { ptr_glUniform3f(location, v0, v1, v2); }
PFNGLUNIFORM4FPROC ptr_glUniform4f = nullptr; void  glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { ptr_glUniform4f(location, v0, v1, v2, v3); }
PFNGLUNIFORM1IPROC ptr_glUniform1i = nullptr; void  glUniform1i(GLint location, GLint v0) { ptr_glUniform1i(location, v0); }
PFNGLUNIFORM2IPROC ptr_glUniform2i = nullptr; void  glUniform2i(GLint location, GLint v0, GLint v1) { ptr_glUniform2i(location, v0, v1); }
PFNGLUNIFORM3IPROC ptr_glUniform3i = nullptr; void  glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) { ptr_glUniform3i(location, v0, v1, v2); }
PFNGLUNIFORM4IPROC ptr_glUniform4i = nullptr; void  glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { ptr_glUniform4i(location, v0, v1, v2, v3); }
PFNGLUNIFORM1FVPROC ptr_glUniform1fv = nullptr; void  glUniform1fv(GLint location, GLsizei count, const GLfloat *value) { ptr_glUniform1fv(location, count, value); }
PFNGLUNIFORM2FVPROC ptr_glUniform2fv = nullptr; void  glUniform2fv(GLint location, GLsizei count, const GLfloat *value) { ptr_glUniform2fv(location, count, value); }
PFNGLUNIFORM3FVPROC ptr_glUniform3fv = nullptr; void  glUniform3fv(GLint location, GLsizei count, const GLfloat *value) { ptr_glUniform3fv(location, count, value); }
PFNGLUNIFORM4FVPROC ptr_glUniform4fv = nullptr; void  glUniform4fv(GLint location, GLsizei count, const GLfloat *value) { ptr_glUniform4fv(location, count, value); }
PFNGLUNIFORM1IVPROC ptr_glUniform1iv = nullptr; void  glUniform1iv(GLint location, GLsizei count, const GLint *value) { ptr_glUniform1iv(location, count, value); }
PFNGLUNIFORM2IVPROC ptr_glUniform2iv = nullptr; void  glUniform2iv(GLint location, GLsizei count, const GLint *value) { ptr_glUniform2iv(location, count, value); }
PFNGLUNIFORM3IVPROC ptr_glUniform3iv = nullptr; void  glUniform3iv(GLint location, GLsizei count, const GLint *value) { ptr_glUniform3iv(location, count, value); }
PFNGLUNIFORM4IVPROC ptr_glUniform4iv = nullptr; void  glUniform4iv(GLint location, GLsizei count, const GLint *value) { ptr_glUniform4iv(location, count, value); }
PFNGLUNIFORMMATRIX2FVPROC ptr_glUniformMatrix2fv = nullptr; void  glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glUniformMatrix2fv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX3FVPROC ptr_glUniformMatrix3fv = nullptr; void  glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glUniformMatrix3fv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX4FVPROC ptr_glUniformMatrix4fv = nullptr; void  glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glUniformMatrix4fv(location, count, transpose, value); }
PFNGLVALIDATEPROGRAMPROC ptr_glValidateProgram = nullptr; void  glValidateProgram(GLuint program) { ptr_glValidateProgram(program); }
PFNGLVERTEXATTRIB1DPROC ptr_glVertexAttrib1d = nullptr; void  glVertexAttrib1d(GLuint index, GLdouble x) { ptr_glVertexAttrib1d(index, x); }
PFNGLVERTEXATTRIB1DVPROC ptr_glVertexAttrib1dv = nullptr; void  glVertexAttrib1dv(GLuint index, const GLdouble *v) { ptr_glVertexAttrib1dv(index, v); }
PFNGLVERTEXATTRIB1FPROC ptr_glVertexAttrib1f = nullptr; void  glVertexAttrib1f(GLuint index, GLfloat x) { ptr_glVertexAttrib1f(index, x); }
PFNGLVERTEXATTRIB1FVPROC ptr_glVertexAttrib1fv = nullptr; void  glVertexAttrib1fv(GLuint index, const GLfloat *v) { ptr_glVertexAttrib1fv(index, v); }
PFNGLVERTEXATTRIB1SPROC ptr_glVertexAttrib1s = nullptr; void  glVertexAttrib1s(GLuint index, GLshort x) { ptr_glVertexAttrib1s(index, x); }
PFNGLVERTEXATTRIB1SVPROC ptr_glVertexAttrib1sv = nullptr; void  glVertexAttrib1sv(GLuint index, const GLshort *v) { ptr_glVertexAttrib1sv(index, v); }
PFNGLVERTEXATTRIB2DPROC ptr_glVertexAttrib2d = nullptr; void  glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) { ptr_glVertexAttrib2d(index, x, y); }
PFNGLVERTEXATTRIB2DVPROC ptr_glVertexAttrib2dv = nullptr; void  glVertexAttrib2dv(GLuint index, const GLdouble *v) { ptr_glVertexAttrib2dv(index, v); }
PFNGLVERTEXATTRIB2FPROC ptr_glVertexAttrib2f = nullptr; void  glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) { ptr_glVertexAttrib2f(index, x, y); }
PFNGLVERTEXATTRIB2FVPROC ptr_glVertexAttrib2fv = nullptr; void  glVertexAttrib2fv(GLuint index, const GLfloat *v) { ptr_glVertexAttrib2fv(index, v); }
PFNGLVERTEXATTRIB2SPROC ptr_glVertexAttrib2s = nullptr; void  glVertexAttrib2s(GLuint index, GLshort x, GLshort y) { ptr_glVertexAttrib2s(index, x, y); }
PFNGLVERTEXATTRIB2SVPROC ptr_glVertexAttrib2sv = nullptr; void  glVertexAttrib2sv(GLuint index, const GLshort *v) { ptr_glVertexAttrib2sv(index, v); }
PFNGLVERTEXATTRIB3DPROC ptr_glVertexAttrib3d = nullptr; void  glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { ptr_glVertexAttrib3d(index, x, y, z); }
PFNGLVERTEXATTRIB3DVPROC ptr_glVertexAttrib3dv = nullptr; void  glVertexAttrib3dv(GLuint index, const GLdouble *v) { ptr_glVertexAttrib3dv(index, v); }
PFNGLVERTEXATTRIB3FPROC ptr_glVertexAttrib3f = nullptr; void  glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) { ptr_glVertexAttrib3f(index, x, y, z); }
PFNGLVERTEXATTRIB3FVPROC ptr_glVertexAttrib3fv = nullptr; void  glVertexAttrib3fv(GLuint index, const GLfloat *v) { ptr_glVertexAttrib3fv(index, v); }
PFNGLVERTEXATTRIB3SPROC ptr_glVertexAttrib3s = nullptr; void  glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) { ptr_glVertexAttrib3s(index, x, y, z); }
PFNGLVERTEXATTRIB3SVPROC ptr_glVertexAttrib3sv = nullptr; void  glVertexAttrib3sv(GLuint index, const GLshort *v) { ptr_glVertexAttrib3sv(index, v); }
PFNGLVERTEXATTRIB4NBVPROC ptr_glVertexAttrib4Nbv = nullptr; void  glVertexAttrib4Nbv(GLuint index, const GLbyte *v) { ptr_glVertexAttrib4Nbv(index, v); }
PFNGLVERTEXATTRIB4NIVPROC ptr_glVertexAttrib4Niv = nullptr; void  glVertexAttrib4Niv(GLuint index, const GLint *v) { ptr_glVertexAttrib4Niv(index, v); }
PFNGLVERTEXATTRIB4NSVPROC ptr_glVertexAttrib4Nsv = nullptr; void  glVertexAttrib4Nsv(GLuint index, const GLshort *v) { ptr_glVertexAttrib4Nsv(index, v); }
PFNGLVERTEXATTRIB4NUBPROC ptr_glVertexAttrib4Nub = nullptr; void  glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) { ptr_glVertexAttrib4Nub(index, x, y, z, w); }
PFNGLVERTEXATTRIB4NUBVPROC ptr_glVertexAttrib4Nubv = nullptr; void  glVertexAttrib4Nubv(GLuint index, const GLubyte *v) { ptr_glVertexAttrib4Nubv(index, v); }
PFNGLVERTEXATTRIB4NUIVPROC ptr_glVertexAttrib4Nuiv = nullptr; void  glVertexAttrib4Nuiv(GLuint index, const GLuint *v) { ptr_glVertexAttrib4Nuiv(index, v); }
PFNGLVERTEXATTRIB4NUSVPROC ptr_glVertexAttrib4Nusv = nullptr; void  glVertexAttrib4Nusv(GLuint index, const GLushort *v) { ptr_glVertexAttrib4Nusv(index, v); }
PFNGLVERTEXATTRIB4BVPROC ptr_glVertexAttrib4bv = nullptr; void  glVertexAttrib4bv(GLuint index, const GLbyte *v) { ptr_glVertexAttrib4bv(index, v); }
PFNGLVERTEXATTRIB4DPROC ptr_glVertexAttrib4d = nullptr; void  glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { ptr_glVertexAttrib4d(index, x, y, z, w); }
PFNGLVERTEXATTRIB4DVPROC ptr_glVertexAttrib4dv = nullptr; void  glVertexAttrib4dv(GLuint index, const GLdouble *v) { ptr_glVertexAttrib4dv(index, v); }
PFNGLVERTEXATTRIB4FPROC ptr_glVertexAttrib4f = nullptr; void  glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { ptr_glVertexAttrib4f(index, x, y, z, w); }
PFNGLVERTEXATTRIB4FVPROC ptr_glVertexAttrib4fv = nullptr; void  glVertexAttrib4fv(GLuint index, const GLfloat *v) { ptr_glVertexAttrib4fv(index, v); }
PFNGLVERTEXATTRIB4IVPROC ptr_glVertexAttrib4iv = nullptr; void  glVertexAttrib4iv(GLuint index, const GLint *v) { ptr_glVertexAttrib4iv(index, v); }
PFNGLVERTEXATTRIB4SPROC ptr_glVertexAttrib4s = nullptr; void  glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) { ptr_glVertexAttrib4s(index, x, y, z, w); }
PFNGLVERTEXATTRIB4SVPROC ptr_glVertexAttrib4sv = nullptr; void  glVertexAttrib4sv(GLuint index, const GLshort *v) { ptr_glVertexAttrib4sv(index, v); }
PFNGLVERTEXATTRIB4UBVPROC ptr_glVertexAttrib4ubv = nullptr; void  glVertexAttrib4ubv(GLuint index, const GLubyte *v) { ptr_glVertexAttrib4ubv(index, v); }
PFNGLVERTEXATTRIB4UIVPROC ptr_glVertexAttrib4uiv = nullptr; void  glVertexAttrib4uiv(GLuint index, const GLuint *v) { ptr_glVertexAttrib4uiv(index, v); }
PFNGLVERTEXATTRIB4USVPROC ptr_glVertexAttrib4usv = nullptr; void  glVertexAttrib4usv(GLuint index, const GLushort *v) { ptr_glVertexAttrib4usv(index, v); }
PFNGLVERTEXATTRIBPOINTERPROC ptr_glVertexAttribPointer = nullptr; void  glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) { ptr_glVertexAttribPointer(index, size, type, normalized, stride, pointer); }
PFNGLUNIFORMMATRIX2X3FVPROC ptr_glUniformMatrix2x3fv = nullptr; void  glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glUniformMatrix2x3fv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX3X2FVPROC ptr_glUniformMatrix3x2fv = nullptr; void  glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glUniformMatrix3x2fv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX2X4FVPROC ptr_glUniformMatrix2x4fv = nullptr; void  glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glUniformMatrix2x4fv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX4X2FVPROC ptr_glUniformMatrix4x2fv = nullptr; void  glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glUniformMatrix4x2fv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX3X4FVPROC ptr_glUniformMatrix3x4fv = nullptr; void  glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glUniformMatrix3x4fv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX4X3FVPROC ptr_glUniformMatrix4x3fv = nullptr; void  glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glUniformMatrix4x3fv(location, count, transpose, value); }
PFNGLCOLORMASKIPROC ptr_glColorMaski = nullptr; void  glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) { ptr_glColorMaski(index, r, g, b, a); }
PFNGLGETBOOLEANI_VPROC ptr_glGetBooleani_v = nullptr; void  glGetBooleani_v(GLenum target, GLuint index, GLboolean *data) { ptr_glGetBooleani_v(target, index, data); }
PFNGLGETINTEGERI_VPROC ptr_glGetIntegeri_v = nullptr; void  glGetIntegeri_v(GLenum target, GLuint index, GLint *data) { ptr_glGetIntegeri_v(target, index, data); }
PFNGLENABLEIPROC ptr_glEnablei = nullptr; void  glEnablei(GLenum target, GLuint index) { ptr_glEnablei(target, index); }
PFNGLDISABLEIPROC ptr_glDisablei = nullptr; void  glDisablei(GLenum target, GLuint index) { ptr_glDisablei(target, index); }
PFNGLISENABLEDIPROC ptr_glIsEnabledi = nullptr; GLboolean  glIsEnabledi(GLenum target, GLuint index) { return ptr_glIsEnabledi(target, index); }
PFNGLBEGINTRANSFORMFEEDBACKPROC ptr_glBeginTransformFeedback = nullptr; void  glBeginTransformFeedback(GLenum primitiveMode) { ptr_glBeginTransformFeedback(primitiveMode); }
PFNGLENDTRANSFORMFEEDBACKPROC ptr_glEndTransformFeedback = nullptr; void  glEndTransformFeedback(void) { ptr_glEndTransformFeedback(); }
PFNGLBINDBUFFERRANGEPROC ptr_glBindBufferRange = nullptr; void  glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { ptr_glBindBufferRange(target, index, buffer, offset, size); }
PFNGLBINDBUFFERBASEPROC ptr_glBindBufferBase = nullptr; void  glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { ptr_glBindBufferBase(target, index, buffer); }
PFNGLTRANSFORMFEEDBACKVARYINGSPROC ptr_glTransformFeedbackVaryings = nullptr; void  glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) { ptr_glTransformFeedbackVaryings(program, count, varyings, bufferMode); }
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC ptr_glGetTransformFeedbackVarying = nullptr; void  glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) { ptr_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
PFNGLCLAMPCOLORPROC ptr_glClampColor = nullptr; void  glClampColor(GLenum target, GLenum clamp) { ptr_glClampColor(target, clamp); }
PFNGLBEGINCONDITIONALRENDERPROC ptr_glBeginConditionalRender = nullptr; void  glBeginConditionalRender(GLuint id, GLenum mode) { ptr_glBeginConditionalRender(id, mode); }
PFNGLENDCONDITIONALRENDERPROC ptr_glEndConditionalRender = nullptr; void  glEndConditionalRender(void) { ptr_glEndConditionalRender(); }
PFNGLVERTEXATTRIBIPOINTERPROC ptr_glVertexAttribIPointer = nullptr; void  glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) { ptr_glVertexAttribIPointer(index, size, type, stride, pointer); }
PFNGLGETVERTEXATTRIBIIVPROC ptr_glGetVertexAttribIiv = nullptr; void  glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) { ptr_glGetVertexAttribIiv(index, pname, params); }
PFNGLGETVERTEXATTRIBIUIVPROC ptr_glGetVertexAttribIuiv = nullptr; void  glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) { ptr_glGetVertexAttribIuiv(index, pname, params); }
PFNGLVERTEXATTRIBI1IPROC ptr_glVertexAttribI1i = nullptr; void  glVertexAttribI1i(GLuint index, GLint x) { ptr_glVertexAttribI1i(index, x); }
PFNGLVERTEXATTRIBI2IPROC ptr_glVertexAttribI2i = nullptr; void  glVertexAttribI2i(GLuint index, GLint x, GLint y) { ptr_glVertexAttribI2i(index, x, y); }
PFNGLVERTEXATTRIBI3IPROC ptr_glVertexAttribI3i = nullptr; void  glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) { ptr_glVertexAttribI3i(index, x, y, z); }
PFNGLVERTEXATTRIBI4IPROC ptr_glVertexAttribI4i = nullptr; void  glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) { ptr_glVertexAttribI4i(index, x, y, z, w); }
PFNGLVERTEXATTRIBI1UIPROC ptr_glVertexAttribI1ui = nullptr; void  glVertexAttribI1ui(GLuint index, GLuint x) { ptr_glVertexAttribI1ui(index, x); }
PFNGLVERTEXATTRIBI2UIPROC ptr_glVertexAttribI2ui = nullptr; void  glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) { ptr_glVertexAttribI2ui(index, x, y); }
PFNGLVERTEXATTRIBI3UIPROC ptr_glVertexAttribI3ui = nullptr; void  glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) { ptr_glVertexAttribI3ui(index, x, y, z); }
PFNGLVERTEXATTRIBI4UIPROC ptr_glVertexAttribI4ui = nullptr; void  glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) { ptr_glVertexAttribI4ui(index, x, y, z, w); }
PFNGLVERTEXATTRIBI1IVPROC ptr_glVertexAttribI1iv = nullptr; void  glVertexAttribI1iv(GLuint index, const GLint *v) { ptr_glVertexAttribI1iv(index, v); }
PFNGLVERTEXATTRIBI2IVPROC ptr_glVertexAttribI2iv = nullptr; void  glVertexAttribI2iv(GLuint index, const GLint *v) { ptr_glVertexAttribI2iv(index, v); }
PFNGLVERTEXATTRIBI3IVPROC ptr_glVertexAttribI3iv = nullptr; void  glVertexAttribI3iv(GLuint index, const GLint *v) { ptr_glVertexAttribI3iv(index, v); }
PFNGLVERTEXATTRIBI4IVPROC ptr_glVertexAttribI4iv = nullptr; void  glVertexAttribI4iv(GLuint index, const GLint *v) { ptr_glVertexAttribI4iv(index, v); }
PFNGLVERTEXATTRIBI1UIVPROC ptr_glVertexAttribI1uiv = nullptr; void  glVertexAttribI1uiv(GLuint index, const GLuint *v) { ptr_glVertexAttribI1uiv(index, v); }
PFNGLVERTEXATTRIBI2UIVPROC ptr_glVertexAttribI2uiv = nullptr; void  glVertexAttribI2uiv(GLuint index, const GLuint *v) { ptr_glVertexAttribI2uiv(index, v); }
PFNGLVERTEXATTRIBI3UIVPROC ptr_glVertexAttribI3uiv = nullptr; void  glVertexAttribI3uiv(GLuint index, const GLuint *v) { ptr_glVertexAttribI3uiv(index, v); }
PFNGLVERTEXATTRIBI4UIVPROC ptr_glVertexAttribI4uiv = nullptr; void  glVertexAttribI4uiv(GLuint index, const GLuint *v) { ptr_glVertexAttribI4uiv(index, v); }
PFNGLVERTEXATTRIBI4BVPROC ptr_glVertexAttribI4bv = nullptr; void  glVertexAttribI4bv(GLuint index, const GLbyte *v) { ptr_glVertexAttribI4bv(index, v); }
PFNGLVERTEXATTRIBI4SVPROC ptr_glVertexAttribI4sv = nullptr; void  glVertexAttribI4sv(GLuint index, const GLshort *v) { ptr_glVertexAttribI4sv(index, v); }
PFNGLVERTEXATTRIBI4UBVPROC ptr_glVertexAttribI4ubv = nullptr; void  glVertexAttribI4ubv(GLuint index, const GLubyte *v) { ptr_glVertexAttribI4ubv(index, v); }
PFNGLVERTEXATTRIBI4USVPROC ptr_glVertexAttribI4usv = nullptr; void  glVertexAttribI4usv(GLuint index, const GLushort *v) { ptr_glVertexAttribI4usv(index, v); }
PFNGLGETUNIFORMUIVPROC ptr_glGetUniformuiv = nullptr; void  glGetUniformuiv(GLuint program, GLint location, GLuint *params) { ptr_glGetUniformuiv(program, location, params); }
PFNGLBINDFRAGDATALOCATIONPROC ptr_glBindFragDataLocation = nullptr; void  glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name) { ptr_glBindFragDataLocation(program, color, name); }
PFNGLGETFRAGDATALOCATIONPROC ptr_glGetFragDataLocation = nullptr; GLint  glGetFragDataLocation(GLuint program, const GLchar *name) { return ptr_glGetFragDataLocation(program, name); }
PFNGLUNIFORM1UIPROC ptr_glUniform1ui = nullptr; void  glUniform1ui(GLint location, GLuint v0) { ptr_glUniform1ui(location, v0); }
PFNGLUNIFORM2UIPROC ptr_glUniform2ui = nullptr; void  glUniform2ui(GLint location, GLuint v0, GLuint v1) { ptr_glUniform2ui(location, v0, v1); }
PFNGLUNIFORM3UIPROC ptr_glUniform3ui = nullptr; void  glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { ptr_glUniform3ui(location, v0, v1, v2); }
PFNGLUNIFORM4UIPROC ptr_glUniform4ui = nullptr; void  glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { ptr_glUniform4ui(location, v0, v1, v2, v3); }
PFNGLUNIFORM1UIVPROC ptr_glUniform1uiv = nullptr; void  glUniform1uiv(GLint location, GLsizei count, const GLuint *value) { ptr_glUniform1uiv(location, count, value); }
PFNGLUNIFORM2UIVPROC ptr_glUniform2uiv = nullptr; void  glUniform2uiv(GLint location, GLsizei count, const GLuint *value) { ptr_glUniform2uiv(location, count, value); }
PFNGLUNIFORM3UIVPROC ptr_glUniform3uiv = nullptr; void  glUniform3uiv(GLint location, GLsizei count, const GLuint *value) { ptr_glUniform3uiv(location, count, value); }
PFNGLUNIFORM4UIVPROC ptr_glUniform4uiv = nullptr; void  glUniform4uiv(GLint location, GLsizei count, const GLuint *value) { ptr_glUniform4uiv(location, count, value); }
PFNGLTEXPARAMETERIIVPROC ptr_glTexParameterIiv = nullptr; void  glTexParameterIiv(GLenum target, GLenum pname, const GLint *params) { ptr_glTexParameterIiv(target, pname, params); }
PFNGLTEXPARAMETERIUIVPROC ptr_glTexParameterIuiv = nullptr; void  glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params) { ptr_glTexParameterIuiv(target, pname, params); }
PFNGLGETTEXPARAMETERIIVPROC ptr_glGetTexParameterIiv = nullptr; void  glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params) { ptr_glGetTexParameterIiv(target, pname, params); }
PFNGLGETTEXPARAMETERIUIVPROC ptr_glGetTexParameterIuiv = nullptr; void  glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params) { ptr_glGetTexParameterIuiv(target, pname, params); }
PFNGLCLEARBUFFERIVPROC ptr_glClearBufferiv = nullptr; void  glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) { ptr_glClearBufferiv(buffer, drawbuffer, value); }
PFNGLCLEARBUFFERUIVPROC ptr_glClearBufferuiv = nullptr; void  glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) { ptr_glClearBufferuiv(buffer, drawbuffer, value); }
PFNGLCLEARBUFFERFVPROC ptr_glClearBufferfv = nullptr; void  glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) { ptr_glClearBufferfv(buffer, drawbuffer, value); }
PFNGLCLEARBUFFERFIPROC ptr_glClearBufferfi = nullptr; void  glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { ptr_glClearBufferfi(buffer, drawbuffer, depth, stencil); }
PFNGLGETSTRINGIPROC ptr_glGetStringi = nullptr; const GLubyte * glGetStringi(GLenum name, GLuint index) { return ptr_glGetStringi(name, index); }
PFNGLISRENDERBUFFERPROC ptr_glIsRenderbuffer = nullptr; GLboolean  glIsRenderbuffer(GLuint renderbuffer) { return ptr_glIsRenderbuffer(renderbuffer); }
PFNGLBINDRENDERBUFFERPROC ptr_glBindRenderbuffer = nullptr; void  glBindRenderbuffer(GLenum target, GLuint renderbuffer) { ptr_glBindRenderbuffer(target, renderbuffer); }
PFNGLDELETERENDERBUFFERSPROC ptr_glDeleteRenderbuffers = nullptr; void  glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) { ptr_glDeleteRenderbuffers(n, renderbuffers); }
PFNGLGENRENDERBUFFERSPROC ptr_glGenRenderbuffers = nullptr; void  glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) { ptr_glGenRenderbuffers(n, renderbuffers); }
PFNGLRENDERBUFFERSTORAGEPROC ptr_glRenderbufferStorage = nullptr; void  glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { ptr_glRenderbufferStorage(target, internalformat, width, height); }
PFNGLGETRENDERBUFFERPARAMETERIVPROC ptr_glGetRenderbufferParameteriv = nullptr; void  glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) { ptr_glGetRenderbufferParameteriv(target, pname, params); }
PFNGLISFRAMEBUFFERPROC ptr_glIsFramebuffer = nullptr; GLboolean  glIsFramebuffer(GLuint framebuffer) { return ptr_glIsFramebuffer(framebuffer); }
PFNGLBINDFRAMEBUFFERPROC ptr_glBindFramebuffer = nullptr; void  glBindFramebuffer(GLenum target, GLuint framebuffer) { ptr_glBindFramebuffer(target, framebuffer); }
PFNGLDELETEFRAMEBUFFERSPROC ptr_glDeleteFramebuffers = nullptr; void  glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) { ptr_glDeleteFramebuffers(n, framebuffers); }
PFNGLGENFRAMEBUFFERSPROC ptr_glGenFramebuffers = nullptr; void  glGenFramebuffers(GLsizei n, GLuint *framebuffers) { ptr_glGenFramebuffers(n, framebuffers); }
PFNGLCHECKFRAMEBUFFERSTATUSPROC ptr_glCheckFramebufferStatus = nullptr; GLenum  glCheckFramebufferStatus(GLenum target) { return ptr_glCheckFramebufferStatus(target); }
PFNGLFRAMEBUFFERTEXTURE1DPROC ptr_glFramebufferTexture1D = nullptr; void  glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { ptr_glFramebufferTexture1D(target, attachment, textarget, texture, level); }
PFNGLFRAMEBUFFERTEXTURE2DPROC ptr_glFramebufferTexture2D = nullptr; void  glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { ptr_glFramebufferTexture2D(target, attachment, textarget, texture, level); }
PFNGLFRAMEBUFFERTEXTURE3DPROC ptr_glFramebufferTexture3D = nullptr; void  glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) { ptr_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset); }
PFNGLFRAMEBUFFERRENDERBUFFERPROC ptr_glFramebufferRenderbuffer = nullptr; void  glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { ptr_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC ptr_glGetFramebufferAttachmentParameteriv = nullptr; void  glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) { ptr_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
PFNGLGENERATEMIPMAPPROC ptr_glGenerateMipmap = nullptr; void  glGenerateMipmap(GLenum target) { ptr_glGenerateMipmap(target); }
PFNGLBLITFRAMEBUFFERPROC ptr_glBlitFramebuffer = nullptr; void  glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { ptr_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC ptr_glRenderbufferStorageMultisample = nullptr; void  glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { ptr_glRenderbufferStorageMultisample(target, samples, internalformat, width, height); }
PFNGLFRAMEBUFFERTEXTURELAYERPROC ptr_glFramebufferTextureLayer = nullptr; void  glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) { ptr_glFramebufferTextureLayer(target, attachment, texture, level, layer); }
PFNGLMAPBUFFERRANGEPROC ptr_glMapBufferRange = nullptr; void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { return ptr_glMapBufferRange(target, offset, length, access); }
PFNGLFLUSHMAPPEDBUFFERRANGEPROC ptr_glFlushMappedBufferRange = nullptr; void  glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { ptr_glFlushMappedBufferRange(target, offset, length); }
PFNGLBINDVERTEXARRAYPROC ptr_glBindVertexArray = nullptr; void  glBindVertexArray(GLuint array) { ptr_glBindVertexArray(array); }
PFNGLDELETEVERTEXARRAYSPROC ptr_glDeleteVertexArrays = nullptr; void  glDeleteVertexArrays(GLsizei n, const GLuint *arrays) { ptr_glDeleteVertexArrays(n, arrays); }
PFNGLGENVERTEXARRAYSPROC ptr_glGenVertexArrays = nullptr; void  glGenVertexArrays(GLsizei n, GLuint *arrays) { ptr_glGenVertexArrays(n, arrays); }
PFNGLISVERTEXARRAYPROC ptr_glIsVertexArray = nullptr; GLboolean  glIsVertexArray(GLuint array) { return ptr_glIsVertexArray(array); }
PFNGLDRAWARRAYSINSTANCEDPROC ptr_glDrawArraysInstanced = nullptr; void  glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) { ptr_glDrawArraysInstanced(mode, first, count, instancecount); }
PFNGLDRAWELEMENTSINSTANCEDPROC ptr_glDrawElementsInstanced = nullptr; void  glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) { ptr_glDrawElementsInstanced(mode, count, type, indices, instancecount); }
PFNGLTEXBUFFERPROC ptr_glTexBuffer = nullptr; void  glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) { ptr_glTexBuffer(target, internalformat, buffer); }
PFNGLPRIMITIVERESTARTINDEXPROC ptr_glPrimitiveRestartIndex = nullptr; void  glPrimitiveRestartIndex(GLuint index) { ptr_glPrimitiveRestartIndex(index); }
PFNGLCOPYBUFFERSUBDATAPROC ptr_glCopyBufferSubData = nullptr; void  glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { ptr_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); }
PFNGLGETUNIFORMINDICESPROC ptr_glGetUniformIndices = nullptr; void  glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) { ptr_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); }
PFNGLGETACTIVEUNIFORMSIVPROC ptr_glGetActiveUniformsiv = nullptr; void  glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) { ptr_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); }
PFNGLGETACTIVEUNIFORMNAMEPROC ptr_glGetActiveUniformName = nullptr; void  glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) { ptr_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName); }
PFNGLGETUNIFORMBLOCKINDEXPROC ptr_glGetUniformBlockIndex = nullptr; GLuint  glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) { return ptr_glGetUniformBlockIndex(program, uniformBlockName); }
PFNGLGETACTIVEUNIFORMBLOCKIVPROC ptr_glGetActiveUniformBlockiv = nullptr; void  glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) { ptr_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); }
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC ptr_glGetActiveUniformBlockName = nullptr; void  glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) { ptr_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); }
PFNGLUNIFORMBLOCKBINDINGPROC ptr_glUniformBlockBinding = nullptr; void  glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) { ptr_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); }
PFNGLDRAWELEMENTSBASEVERTEXPROC ptr_glDrawElementsBaseVertex = nullptr; void  glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) { ptr_glDrawElementsBaseVertex(mode, count, type, indices, basevertex); }
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC ptr_glDrawRangeElementsBaseVertex = nullptr; void  glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) { ptr_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex); }
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC ptr_glDrawElementsInstancedBaseVertex = nullptr; void  glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) { ptr_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex); }
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC ptr_glMultiDrawElementsBaseVertex = nullptr; void  glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) { ptr_glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex); }
PFNGLPROVOKINGVERTEXPROC ptr_glProvokingVertex = nullptr; void  glProvokingVertex(GLenum mode) { ptr_glProvokingVertex(mode); }
PFNGLFENCESYNCPROC ptr_glFenceSync = nullptr; GLsync  glFenceSync(GLenum condition, GLbitfield flags) { return ptr_glFenceSync(condition, flags); }
PFNGLISSYNCPROC ptr_glIsSync = nullptr; GLboolean  glIsSync(GLsync sync) { return ptr_glIsSync(sync); }
PFNGLDELETESYNCPROC ptr_glDeleteSync = nullptr; void  glDeleteSync(GLsync sync) { ptr_glDeleteSync(sync); }
PFNGLCLIENTWAITSYNCPROC ptr_glClientWaitSync = nullptr; GLenum  glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { return ptr_glClientWaitSync(sync, flags, timeout); }
PFNGLWAITSYNCPROC ptr_glWaitSync = nullptr; void  glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { ptr_glWaitSync(sync, flags, timeout); }
PFNGLGETINTEGER64VPROC ptr_glGetInteger64v = nullptr; void  glGetInteger64v(GLenum pname, GLint64 *data) { ptr_glGetInteger64v(pname, data); }
PFNGLGETSYNCIVPROC ptr_glGetSynciv = nullptr; void  glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values) { ptr_glGetSynciv(sync, pname, bufSize, length, values); }
PFNGLGETINTEGER64I_VPROC ptr_glGetInteger64i_v = nullptr; void  glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data) { ptr_glGetInteger64i_v(target, index, data); }
PFNGLGETBUFFERPARAMETERI64VPROC ptr_glGetBufferParameteri64v = nullptr; void  glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) { ptr_glGetBufferParameteri64v(target, pname, params); }
PFNGLFRAMEBUFFERTEXTUREPROC ptr_glFramebufferTexture = nullptr; void  glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) { ptr_glFramebufferTexture(target, attachment, texture, level); }
PFNGLTEXIMAGE2DMULTISAMPLEPROC ptr_glTexImage2DMultisample = nullptr; void  glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { ptr_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
PFNGLTEXIMAGE3DMULTISAMPLEPROC ptr_glTexImage3DMultisample = nullptr; void  glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { ptr_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
PFNGLGETMULTISAMPLEFVPROC ptr_glGetMultisamplefv = nullptr; void  glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) { ptr_glGetMultisamplefv(pname, index, val); }
PFNGLSAMPLEMASKIPROC ptr_glSampleMaski = nullptr; void  glSampleMaski(GLuint maskNumber, GLbitfield mask) { ptr_glSampleMaski(maskNumber, mask); }
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC ptr_glBindFragDataLocationIndexed = nullptr; void  glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) { ptr_glBindFragDataLocationIndexed(program, colorNumber, index, name); }
PFNGLGETFRAGDATAINDEXPROC ptr_glGetFragDataIndex = nullptr; GLint  glGetFragDataIndex(GLuint program, const GLchar *name) { return ptr_glGetFragDataIndex(program, name); }
PFNGLGENSAMPLERSPROC ptr_glGenSamplers = nullptr; void  glGenSamplers(GLsizei count, GLuint *samplers) { ptr_glGenSamplers(count, samplers); }
PFNGLDELETESAMPLERSPROC ptr_glDeleteSamplers = nullptr; void  glDeleteSamplers(GLsizei count, const GLuint *samplers) { ptr_glDeleteSamplers(count, samplers); }
PFNGLISSAMPLERPROC ptr_glIsSampler = nullptr; GLboolean  glIsSampler(GLuint sampler) { return ptr_glIsSampler(sampler); }
PFNGLBINDSAMPLERPROC ptr_glBindSampler = nullptr; void  glBindSampler(GLuint unit, GLuint sampler) { ptr_glBindSampler(unit, sampler); }
PFNGLSAMPLERPARAMETERIPROC ptr_glSamplerParameteri = nullptr; void  glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) { ptr_glSamplerParameteri(sampler, pname, param); }
PFNGLSAMPLERPARAMETERIVPROC ptr_glSamplerParameteriv = nullptr; void  glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param) { ptr_glSamplerParameteriv(sampler, pname, param); }
PFNGLSAMPLERPARAMETERFPROC ptr_glSamplerParameterf = nullptr; void  glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { ptr_glSamplerParameterf(sampler, pname, param); }
PFNGLSAMPLERPARAMETERFVPROC ptr_glSamplerParameterfv = nullptr; void  glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param) { ptr_glSamplerParameterfv(sampler, pname, param); }
PFNGLSAMPLERPARAMETERIIVPROC ptr_glSamplerParameterIiv = nullptr; void  glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param) { ptr_glSamplerParameterIiv(sampler, pname, param); }
PFNGLSAMPLERPARAMETERIUIVPROC ptr_glSamplerParameterIuiv = nullptr; void  glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param) { ptr_glSamplerParameterIuiv(sampler, pname, param); }
PFNGLGETSAMPLERPARAMETERIVPROC ptr_glGetSamplerParameteriv = nullptr; void  glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params) { ptr_glGetSamplerParameteriv(sampler, pname, params); }
PFNGLGETSAMPLERPARAMETERIIVPROC ptr_glGetSamplerParameterIiv = nullptr; void  glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params) { ptr_glGetSamplerParameterIiv(sampler, pname, params); }
PFNGLGETSAMPLERPARAMETERFVPROC ptr_glGetSamplerParameterfv = nullptr; void  glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params) { ptr_glGetSamplerParameterfv(sampler, pname, params); }
PFNGLGETSAMPLERPARAMETERIUIVPROC ptr_glGetSamplerParameterIuiv = nullptr; void  glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params) { ptr_glGetSamplerParameterIuiv(sampler, pname, params); }
PFNGLQUERYCOUNTERPROC ptr_glQueryCounter = nullptr; void  glQueryCounter(GLuint id, GLenum target) { ptr_glQueryCounter(id, target); }
PFNGLGETQUERYOBJECTI64VPROC ptr_glGetQueryObjecti64v = nullptr; void  glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params) { ptr_glGetQueryObjecti64v(id, pname, params); }
PFNGLGETQUERYOBJECTUI64VPROC ptr_glGetQueryObjectui64v = nullptr; void  glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params) { ptr_glGetQueryObjectui64v(id, pname, params); }
PFNGLVERTEXATTRIBDIVISORPROC ptr_glVertexAttribDivisor = nullptr; void  glVertexAttribDivisor(GLuint index, GLuint divisor) { ptr_glVertexAttribDivisor(index, divisor); }
PFNGLVERTEXATTRIBP1UIPROC ptr_glVertexAttribP1ui = nullptr; void  glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { ptr_glVertexAttribP1ui(index, type, normalized, value); }
PFNGLVERTEXATTRIBP1UIVPROC ptr_glVertexAttribP1uiv = nullptr; void  glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { ptr_glVertexAttribP1uiv(index, type, normalized, value); }
PFNGLVERTEXATTRIBP2UIPROC ptr_glVertexAttribP2ui = nullptr; void  glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { ptr_glVertexAttribP2ui(index, type, normalized, value); }
PFNGLVERTEXATTRIBP2UIVPROC ptr_glVertexAttribP2uiv = nullptr; void  glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { ptr_glVertexAttribP2uiv(index, type, normalized, value); }
PFNGLVERTEXATTRIBP3UIPROC ptr_glVertexAttribP3ui = nullptr; void  glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { ptr_glVertexAttribP3ui(index, type, normalized, value); }
PFNGLVERTEXATTRIBP3UIVPROC ptr_glVertexAttribP3uiv = nullptr; void  glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { ptr_glVertexAttribP3uiv(index, type, normalized, value); }
PFNGLVERTEXATTRIBP4UIPROC ptr_glVertexAttribP4ui = nullptr; void  glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { ptr_glVertexAttribP4ui(index, type, normalized, value); }
PFNGLVERTEXATTRIBP4UIVPROC ptr_glVertexAttribP4uiv = nullptr; void  glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { ptr_glVertexAttribP4uiv(index, type, normalized, value); }
PFNGLVERTEXP2UIPROC ptr_glVertexP2ui = nullptr; void  glVertexP2ui(GLenum type, GLuint value) { ptr_glVertexP2ui(type, value); }
PFNGLVERTEXP2UIVPROC ptr_glVertexP2uiv = nullptr; void  glVertexP2uiv(GLenum type, const GLuint *value) { ptr_glVertexP2uiv(type, value); }
PFNGLVERTEXP3UIPROC ptr_glVertexP3ui = nullptr; void  glVertexP3ui(GLenum type, GLuint value) { ptr_glVertexP3ui(type, value); }
PFNGLVERTEXP3UIVPROC ptr_glVertexP3uiv = nullptr; void  glVertexP3uiv(GLenum type, const GLuint *value) { ptr_glVertexP3uiv(type, value); }
PFNGLVERTEXP4UIPROC ptr_glVertexP4ui = nullptr; void  glVertexP4ui(GLenum type, GLuint value) { ptr_glVertexP4ui(type, value); }
PFNGLVERTEXP4UIVPROC ptr_glVertexP4uiv = nullptr; void  glVertexP4uiv(GLenum type, const GLuint *value) { ptr_glVertexP4uiv(type, value); }
PFNGLTEXCOORDP1UIPROC ptr_glTexCoordP1ui = nullptr; void  glTexCoordP1ui(GLenum type, GLuint coords) { ptr_glTexCoordP1ui(type, coords); }
PFNGLTEXCOORDP1UIVPROC ptr_glTexCoordP1uiv = nullptr; void  glTexCoordP1uiv(GLenum type, const GLuint *coords) { ptr_glTexCoordP1uiv(type, coords); }
PFNGLTEXCOORDP2UIPROC ptr_glTexCoordP2ui = nullptr; void  glTexCoordP2ui(GLenum type, GLuint coords) { ptr_glTexCoordP2ui(type, coords); }
PFNGLTEXCOORDP2UIVPROC ptr_glTexCoordP2uiv = nullptr; void  glTexCoordP2uiv(GLenum type, const GLuint *coords) { ptr_glTexCoordP2uiv(type, coords); }
PFNGLTEXCOORDP3UIPROC ptr_glTexCoordP3ui = nullptr; void  glTexCoordP3ui(GLenum type, GLuint coords) { ptr_glTexCoordP3ui(type, coords); }
PFNGLTEXCOORDP3UIVPROC ptr_glTexCoordP3uiv = nullptr; void  glTexCoordP3uiv(GLenum type, const GLuint *coords) { ptr_glTexCoordP3uiv(type, coords); }
PFNGLTEXCOORDP4UIPROC ptr_glTexCoordP4ui = nullptr; void  glTexCoordP4ui(GLenum type, GLuint coords) { ptr_glTexCoordP4ui(type, coords); }
PFNGLTEXCOORDP4UIVPROC ptr_glTexCoordP4uiv = nullptr; void  glTexCoordP4uiv(GLenum type, const GLuint *coords) { ptr_glTexCoordP4uiv(type, coords); }
PFNGLMULTITEXCOORDP1UIPROC ptr_glMultiTexCoordP1ui = nullptr; void  glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) { ptr_glMultiTexCoordP1ui(texture, type, coords); }
PFNGLMULTITEXCOORDP1UIVPROC ptr_glMultiTexCoordP1uiv = nullptr; void  glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint *coords) { ptr_glMultiTexCoordP1uiv(texture, type, coords); }
PFNGLMULTITEXCOORDP2UIPROC ptr_glMultiTexCoordP2ui = nullptr; void  glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) { ptr_glMultiTexCoordP2ui(texture, type, coords); }
PFNGLMULTITEXCOORDP2UIVPROC ptr_glMultiTexCoordP2uiv = nullptr; void  glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint *coords) { ptr_glMultiTexCoordP2uiv(texture, type, coords); }
PFNGLMULTITEXCOORDP3UIPROC ptr_glMultiTexCoordP3ui = nullptr; void  glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) { ptr_glMultiTexCoordP3ui(texture, type, coords); }
PFNGLMULTITEXCOORDP3UIVPROC ptr_glMultiTexCoordP3uiv = nullptr; void  glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint *coords) { ptr_glMultiTexCoordP3uiv(texture, type, coords); }
PFNGLMULTITEXCOORDP4UIPROC ptr_glMultiTexCoordP4ui = nullptr; void  glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) { ptr_glMultiTexCoordP4ui(texture, type, coords); }
PFNGLMULTITEXCOORDP4UIVPROC ptr_glMultiTexCoordP4uiv = nullptr; void  glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint *coords) { ptr_glMultiTexCoordP4uiv(texture, type, coords); }
PFNGLNORMALP3UIPROC ptr_glNormalP3ui = nullptr; void  glNormalP3ui(GLenum type, GLuint coords) { ptr_glNormalP3ui(type, coords); }
PFNGLNORMALP3UIVPROC ptr_glNormalP3uiv = nullptr; void  glNormalP3uiv(GLenum type, const GLuint *coords) { ptr_glNormalP3uiv(type, coords); }
PFNGLCOLORP3UIPROC ptr_glColorP3ui = nullptr; void  glColorP3ui(GLenum type, GLuint color) { ptr_glColorP3ui(type, color); }
PFNGLCOLORP3UIVPROC ptr_glColorP3uiv = nullptr; void  glColorP3uiv(GLenum type, const GLuint *color) { ptr_glColorP3uiv(type, color); }
PFNGLCOLORP4UIPROC ptr_glColorP4ui = nullptr; void  glColorP4ui(GLenum type, GLuint color) { ptr_glColorP4ui(type, color); }
PFNGLCOLORP4UIVPROC ptr_glColorP4uiv = nullptr; void  glColorP4uiv(GLenum type, const GLuint *color) { ptr_glColorP4uiv(type, color); }
PFNGLSECONDARYCOLORP3UIPROC ptr_glSecondaryColorP3ui = nullptr; void  glSecondaryColorP3ui(GLenum type, GLuint color) { ptr_glSecondaryColorP3ui(type, color); }
PFNGLSECONDARYCOLORP3UIVPROC ptr_glSecondaryColorP3uiv = nullptr; void  glSecondaryColorP3uiv(GLenum type, const GLuint *color) { ptr_glSecondaryColorP3uiv(type, color); }
PFNGLMINSAMPLESHADINGPROC ptr_glMinSampleShading = nullptr; void  glMinSampleShading(GLfloat value) { ptr_glMinSampleShading(value); }
PFNGLBLENDEQUATIONIPROC ptr_glBlendEquationi = nullptr; void  glBlendEquationi(GLuint buf, GLenum mode) { ptr_glBlendEquationi(buf, mode); }
PFNGLBLENDEQUATIONSEPARATEIPROC ptr_glBlendEquationSeparatei = nullptr; void  glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) { ptr_glBlendEquationSeparatei(buf, modeRGB, modeAlpha); }
PFNGLBLENDFUNCIPROC ptr_glBlendFunci = nullptr; void  glBlendFunci(GLuint buf, GLenum src, GLenum dst) { ptr_glBlendFunci(buf, src, dst); }
PFNGLBLENDFUNCSEPARATEIPROC ptr_glBlendFuncSeparatei = nullptr; void  glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { ptr_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha); }
PFNGLDRAWARRAYSINDIRECTPROC ptr_glDrawArraysIndirect = nullptr; void  glDrawArraysIndirect(GLenum mode, const void *indirect) { ptr_glDrawArraysIndirect(mode, indirect); }
PFNGLDRAWELEMENTSINDIRECTPROC ptr_glDrawElementsIndirect = nullptr; void  glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect) { ptr_glDrawElementsIndirect(mode, type, indirect); }
PFNGLUNIFORM1DPROC ptr_glUniform1d = nullptr; void  glUniform1d(GLint location, GLdouble x) { ptr_glUniform1d(location, x); }
PFNGLUNIFORM2DPROC ptr_glUniform2d = nullptr; void  glUniform2d(GLint location, GLdouble x, GLdouble y) { ptr_glUniform2d(location, x, y); }
PFNGLUNIFORM3DPROC ptr_glUniform3d = nullptr; void  glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) { ptr_glUniform3d(location, x, y, z); }
PFNGLUNIFORM4DPROC ptr_glUniform4d = nullptr; void  glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { ptr_glUniform4d(location, x, y, z, w); }
PFNGLUNIFORM1DVPROC ptr_glUniform1dv = nullptr; void  glUniform1dv(GLint location, GLsizei count, const GLdouble *value) { ptr_glUniform1dv(location, count, value); }
PFNGLUNIFORM2DVPROC ptr_glUniform2dv = nullptr; void  glUniform2dv(GLint location, GLsizei count, const GLdouble *value) { ptr_glUniform2dv(location, count, value); }
PFNGLUNIFORM3DVPROC ptr_glUniform3dv = nullptr; void  glUniform3dv(GLint location, GLsizei count, const GLdouble *value) { ptr_glUniform3dv(location, count, value); }
PFNGLUNIFORM4DVPROC ptr_glUniform4dv = nullptr; void  glUniform4dv(GLint location, GLsizei count, const GLdouble *value) { ptr_glUniform4dv(location, count, value); }
PFNGLUNIFORMMATRIX2DVPROC ptr_glUniformMatrix2dv = nullptr; void  glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glUniformMatrix2dv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX3DVPROC ptr_glUniformMatrix3dv = nullptr; void  glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glUniformMatrix3dv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX4DVPROC ptr_glUniformMatrix4dv = nullptr; void  glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glUniformMatrix4dv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX2X3DVPROC ptr_glUniformMatrix2x3dv = nullptr; void  glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glUniformMatrix2x3dv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX2X4DVPROC ptr_glUniformMatrix2x4dv = nullptr; void  glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glUniformMatrix2x4dv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX3X2DVPROC ptr_glUniformMatrix3x2dv = nullptr; void  glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glUniformMatrix3x2dv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX3X4DVPROC ptr_glUniformMatrix3x4dv = nullptr; void  glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glUniformMatrix3x4dv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX4X2DVPROC ptr_glUniformMatrix4x2dv = nullptr; void  glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glUniformMatrix4x2dv(location, count, transpose, value); }
PFNGLUNIFORMMATRIX4X3DVPROC ptr_glUniformMatrix4x3dv = nullptr; void  glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glUniformMatrix4x3dv(location, count, transpose, value); }
PFNGLGETUNIFORMDVPROC ptr_glGetUniformdv = nullptr; void  glGetUniformdv(GLuint program, GLint location, GLdouble *params) { ptr_glGetUniformdv(program, location, params); }
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC ptr_glGetSubroutineUniformLocation = nullptr; GLint  glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name) { return ptr_glGetSubroutineUniformLocation(program, shadertype, name); }
PFNGLGETSUBROUTINEINDEXPROC ptr_glGetSubroutineIndex = nullptr; GLuint  glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name) { return ptr_glGetSubroutineIndex(program, shadertype, name); }
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC ptr_glGetActiveSubroutineUniformiv = nullptr; void  glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values) { ptr_glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values); }
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC ptr_glGetActiveSubroutineUniformName = nullptr; void  glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name) { ptr_glGetActiveSubroutineUniformName(program, shadertype, index, bufsize, length, name); }
PFNGLGETACTIVESUBROUTINENAMEPROC ptr_glGetActiveSubroutineName = nullptr; void  glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name) { ptr_glGetActiveSubroutineName(program, shadertype, index, bufsize, length, name); }
PFNGLUNIFORMSUBROUTINESUIVPROC ptr_glUniformSubroutinesuiv = nullptr; void  glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices) { ptr_glUniformSubroutinesuiv(shadertype, count, indices); }
PFNGLGETUNIFORMSUBROUTINEUIVPROC ptr_glGetUniformSubroutineuiv = nullptr; void  glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params) { ptr_glGetUniformSubroutineuiv(shadertype, location, params); }
PFNGLGETPROGRAMSTAGEIVPROC ptr_glGetProgramStageiv = nullptr; void  glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values) { ptr_glGetProgramStageiv(program, shadertype, pname, values); }
PFNGLPATCHPARAMETERIPROC ptr_glPatchParameteri = nullptr; void  glPatchParameteri(GLenum pname, GLint value) { ptr_glPatchParameteri(pname, value); }
PFNGLPATCHPARAMETERFVPROC ptr_glPatchParameterfv = nullptr; void  glPatchParameterfv(GLenum pname, const GLfloat *values) { ptr_glPatchParameterfv(pname, values); }
PFNGLBINDTRANSFORMFEEDBACKPROC ptr_glBindTransformFeedback = nullptr; void  glBindTransformFeedback(GLenum target, GLuint id) { ptr_glBindTransformFeedback(target, id); }
PFNGLDELETETRANSFORMFEEDBACKSPROC ptr_glDeleteTransformFeedbacks = nullptr; void  glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids) { ptr_glDeleteTransformFeedbacks(n, ids); }
PFNGLGENTRANSFORMFEEDBACKSPROC ptr_glGenTransformFeedbacks = nullptr; void  glGenTransformFeedbacks(GLsizei n, GLuint *ids) { ptr_glGenTransformFeedbacks(n, ids); }
PFNGLISTRANSFORMFEEDBACKPROC ptr_glIsTransformFeedback = nullptr; GLboolean  glIsTransformFeedback(GLuint id) { return ptr_glIsTransformFeedback(id); }
PFNGLPAUSETRANSFORMFEEDBACKPROC ptr_glPauseTransformFeedback = nullptr; void  glPauseTransformFeedback(void) { ptr_glPauseTransformFeedback(); }
PFNGLRESUMETRANSFORMFEEDBACKPROC ptr_glResumeTransformFeedback = nullptr; void  glResumeTransformFeedback(void) { ptr_glResumeTransformFeedback(); }
PFNGLDRAWTRANSFORMFEEDBACKPROC ptr_glDrawTransformFeedback = nullptr; void  glDrawTransformFeedback(GLenum mode, GLuint id) { ptr_glDrawTransformFeedback(mode, id); }
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC ptr_glDrawTransformFeedbackStream = nullptr; void  glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) { ptr_glDrawTransformFeedbackStream(mode, id, stream); }
PFNGLBEGINQUERYINDEXEDPROC ptr_glBeginQueryIndexed = nullptr; void  glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) { ptr_glBeginQueryIndexed(target, index, id); }
PFNGLENDQUERYINDEXEDPROC ptr_glEndQueryIndexed = nullptr; void  glEndQueryIndexed(GLenum target, GLuint index) { ptr_glEndQueryIndexed(target, index); }
PFNGLGETQUERYINDEXEDIVPROC ptr_glGetQueryIndexediv = nullptr; void  glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params) { ptr_glGetQueryIndexediv(target, index, pname, params); }
PFNGLRELEASESHADERCOMPILERPROC ptr_glReleaseShaderCompiler = nullptr; void  glReleaseShaderCompiler(void) { ptr_glReleaseShaderCompiler(); }
PFNGLSHADERBINARYPROC ptr_glShaderBinary = nullptr; void  glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length) { ptr_glShaderBinary(count, shaders, binaryformat, binary, length); }
PFNGLGETSHADERPRECISIONFORMATPROC ptr_glGetShaderPrecisionFormat = nullptr; void  glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) { ptr_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision); }
PFNGLDEPTHRANGEFPROC ptr_glDepthRangef = nullptr; void  glDepthRangef(GLfloat n, GLfloat f) { ptr_glDepthRangef(n, f); }
PFNGLCLEARDEPTHFPROC ptr_glClearDepthf = nullptr; void  glClearDepthf(GLfloat d) { ptr_glClearDepthf(d); }
PFNGLGETPROGRAMBINARYPROC ptr_glGetProgramBinary = nullptr; void  glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) { ptr_glGetProgramBinary(program, bufSize, length, binaryFormat, binary); }
PFNGLPROGRAMBINARYPROC ptr_glProgramBinary = nullptr; void  glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) { ptr_glProgramBinary(program, binaryFormat, binary, length); }
PFNGLPROGRAMPARAMETERIPROC ptr_glProgramParameteri = nullptr; void  glProgramParameteri(GLuint program, GLenum pname, GLint value) { ptr_glProgramParameteri(program, pname, value); }
PFNGLUSEPROGRAMSTAGESPROC ptr_glUseProgramStages = nullptr; void  glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) { ptr_glUseProgramStages(pipeline, stages, program); }
PFNGLACTIVESHADERPROGRAMPROC ptr_glActiveShaderProgram = nullptr; void  glActiveShaderProgram(GLuint pipeline, GLuint program) { ptr_glActiveShaderProgram(pipeline, program); }
PFNGLCREATESHADERPROGRAMVPROC ptr_glCreateShaderProgramv = nullptr; GLuint  glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings) { return ptr_glCreateShaderProgramv(type, count, strings); }
PFNGLBINDPROGRAMPIPELINEPROC ptr_glBindProgramPipeline = nullptr; void  glBindProgramPipeline(GLuint pipeline) { ptr_glBindProgramPipeline(pipeline); }
PFNGLDELETEPROGRAMPIPELINESPROC ptr_glDeleteProgramPipelines = nullptr; void  glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) { ptr_glDeleteProgramPipelines(n, pipelines); }
PFNGLGENPROGRAMPIPELINESPROC ptr_glGenProgramPipelines = nullptr; void  glGenProgramPipelines(GLsizei n, GLuint *pipelines) { ptr_glGenProgramPipelines(n, pipelines); }
PFNGLISPROGRAMPIPELINEPROC ptr_glIsProgramPipeline = nullptr; GLboolean  glIsProgramPipeline(GLuint pipeline) { return ptr_glIsProgramPipeline(pipeline); }
PFNGLGETPROGRAMPIPELINEIVPROC ptr_glGetProgramPipelineiv = nullptr; void  glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) { ptr_glGetProgramPipelineiv(pipeline, pname, params); }
PFNGLPROGRAMUNIFORM1IPROC ptr_glProgramUniform1i = nullptr; void  glProgramUniform1i(GLuint program, GLint location, GLint v0) { ptr_glProgramUniform1i(program, location, v0); }
PFNGLPROGRAMUNIFORM1IVPROC ptr_glProgramUniform1iv = nullptr; void  glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) { ptr_glProgramUniform1iv(program, location, count, value); }
PFNGLPROGRAMUNIFORM1FPROC ptr_glProgramUniform1f = nullptr; void  glProgramUniform1f(GLuint program, GLint location, GLfloat v0) { ptr_glProgramUniform1f(program, location, v0); }
PFNGLPROGRAMUNIFORM1FVPROC ptr_glProgramUniform1fv = nullptr; void  glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { ptr_glProgramUniform1fv(program, location, count, value); }
PFNGLPROGRAMUNIFORM1DPROC ptr_glProgramUniform1d = nullptr; void  glProgramUniform1d(GLuint program, GLint location, GLdouble v0) { ptr_glProgramUniform1d(program, location, v0); }
PFNGLPROGRAMUNIFORM1DVPROC ptr_glProgramUniform1dv = nullptr; void  glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { ptr_glProgramUniform1dv(program, location, count, value); }
PFNGLPROGRAMUNIFORM1UIPROC ptr_glProgramUniform1ui = nullptr; void  glProgramUniform1ui(GLuint program, GLint location, GLuint v0) { ptr_glProgramUniform1ui(program, location, v0); }
PFNGLPROGRAMUNIFORM1UIVPROC ptr_glProgramUniform1uiv = nullptr; void  glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { ptr_glProgramUniform1uiv(program, location, count, value); }
PFNGLPROGRAMUNIFORM2IPROC ptr_glProgramUniform2i = nullptr; void  glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) { ptr_glProgramUniform2i(program, location, v0, v1); }
PFNGLPROGRAMUNIFORM2IVPROC ptr_glProgramUniform2iv = nullptr; void  glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) { ptr_glProgramUniform2iv(program, location, count, value); }
PFNGLPROGRAMUNIFORM2FPROC ptr_glProgramUniform2f = nullptr; void  glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) { ptr_glProgramUniform2f(program, location, v0, v1); }
PFNGLPROGRAMUNIFORM2FVPROC ptr_glProgramUniform2fv = nullptr; void  glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { ptr_glProgramUniform2fv(program, location, count, value); }
PFNGLPROGRAMUNIFORM2DPROC ptr_glProgramUniform2d = nullptr; void  glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) { ptr_glProgramUniform2d(program, location, v0, v1); }
PFNGLPROGRAMUNIFORM2DVPROC ptr_glProgramUniform2dv = nullptr; void  glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { ptr_glProgramUniform2dv(program, location, count, value); }
PFNGLPROGRAMUNIFORM2UIPROC ptr_glProgramUniform2ui = nullptr; void  glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) { ptr_glProgramUniform2ui(program, location, v0, v1); }
PFNGLPROGRAMUNIFORM2UIVPROC ptr_glProgramUniform2uiv = nullptr; void  glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { ptr_glProgramUniform2uiv(program, location, count, value); }
PFNGLPROGRAMUNIFORM3IPROC ptr_glProgramUniform3i = nullptr; void  glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) { ptr_glProgramUniform3i(program, location, v0, v1, v2); }
PFNGLPROGRAMUNIFORM3IVPROC ptr_glProgramUniform3iv = nullptr; void  glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) { ptr_glProgramUniform3iv(program, location, count, value); }
PFNGLPROGRAMUNIFORM3FPROC ptr_glProgramUniform3f = nullptr; void  glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { ptr_glProgramUniform3f(program, location, v0, v1, v2); }
PFNGLPROGRAMUNIFORM3FVPROC ptr_glProgramUniform3fv = nullptr; void  glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { ptr_glProgramUniform3fv(program, location, count, value); }
PFNGLPROGRAMUNIFORM3DPROC ptr_glProgramUniform3d = nullptr; void  glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) { ptr_glProgramUniform3d(program, location, v0, v1, v2); }
PFNGLPROGRAMUNIFORM3DVPROC ptr_glProgramUniform3dv = nullptr; void  glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { ptr_glProgramUniform3dv(program, location, count, value); }
PFNGLPROGRAMUNIFORM3UIPROC ptr_glProgramUniform3ui = nullptr; void  glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) { ptr_glProgramUniform3ui(program, location, v0, v1, v2); }
PFNGLPROGRAMUNIFORM3UIVPROC ptr_glProgramUniform3uiv = nullptr; void  glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { ptr_glProgramUniform3uiv(program, location, count, value); }
PFNGLPROGRAMUNIFORM4IPROC ptr_glProgramUniform4i = nullptr; void  glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { ptr_glProgramUniform4i(program, location, v0, v1, v2, v3); }
PFNGLPROGRAMUNIFORM4IVPROC ptr_glProgramUniform4iv = nullptr; void  glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) { ptr_glProgramUniform4iv(program, location, count, value); }
PFNGLPROGRAMUNIFORM4FPROC ptr_glProgramUniform4f = nullptr; void  glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { ptr_glProgramUniform4f(program, location, v0, v1, v2, v3); }
PFNGLPROGRAMUNIFORM4FVPROC ptr_glProgramUniform4fv = nullptr; void  glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { ptr_glProgramUniform4fv(program, location, count, value); }
PFNGLPROGRAMUNIFORM4DPROC ptr_glProgramUniform4d = nullptr; void  glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) { ptr_glProgramUniform4d(program, location, v0, v1, v2, v3); }
PFNGLPROGRAMUNIFORM4DVPROC ptr_glProgramUniform4dv = nullptr; void  glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { ptr_glProgramUniform4dv(program, location, count, value); }
PFNGLPROGRAMUNIFORM4UIPROC ptr_glProgramUniform4ui = nullptr; void  glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { ptr_glProgramUniform4ui(program, location, v0, v1, v2, v3); }
PFNGLPROGRAMUNIFORM4UIVPROC ptr_glProgramUniform4uiv = nullptr; void  glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { ptr_glProgramUniform4uiv(program, location, count, value); }
PFNGLPROGRAMUNIFORMMATRIX2FVPROC ptr_glProgramUniformMatrix2fv = nullptr; void  glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glProgramUniformMatrix2fv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX3FVPROC ptr_glProgramUniformMatrix3fv = nullptr; void  glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glProgramUniformMatrix3fv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX4FVPROC ptr_glProgramUniformMatrix4fv = nullptr; void  glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glProgramUniformMatrix4fv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX2DVPROC ptr_glProgramUniformMatrix2dv = nullptr; void  glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glProgramUniformMatrix2dv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX3DVPROC ptr_glProgramUniformMatrix3dv = nullptr; void  glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glProgramUniformMatrix3dv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX4DVPROC ptr_glProgramUniformMatrix4dv = nullptr; void  glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glProgramUniformMatrix4dv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC ptr_glProgramUniformMatrix2x3fv = nullptr; void  glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glProgramUniformMatrix2x3fv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC ptr_glProgramUniformMatrix3x2fv = nullptr; void  glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glProgramUniformMatrix3x2fv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC ptr_glProgramUniformMatrix2x4fv = nullptr; void  glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glProgramUniformMatrix2x4fv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC ptr_glProgramUniformMatrix4x2fv = nullptr; void  glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glProgramUniformMatrix4x2fv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC ptr_glProgramUniformMatrix3x4fv = nullptr; void  glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glProgramUniformMatrix3x4fv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC ptr_glProgramUniformMatrix4x3fv = nullptr; void  glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ptr_glProgramUniformMatrix4x3fv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC ptr_glProgramUniformMatrix2x3dv = nullptr; void  glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glProgramUniformMatrix2x3dv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC ptr_glProgramUniformMatrix3x2dv = nullptr; void  glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glProgramUniformMatrix3x2dv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC ptr_glProgramUniformMatrix2x4dv = nullptr; void  glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glProgramUniformMatrix2x4dv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC ptr_glProgramUniformMatrix4x2dv = nullptr; void  glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glProgramUniformMatrix4x2dv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC ptr_glProgramUniformMatrix3x4dv = nullptr; void  glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glProgramUniformMatrix3x4dv(program, location, count, transpose, value); }
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC ptr_glProgramUniformMatrix4x3dv = nullptr; void  glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { ptr_glProgramUniformMatrix4x3dv(program, location, count, transpose, value); }
PFNGLVALIDATEPROGRAMPIPELINEPROC ptr_glValidateProgramPipeline = nullptr; void  glValidateProgramPipeline(GLuint pipeline) { ptr_glValidateProgramPipeline(pipeline); }
PFNGLGETPROGRAMPIPELINEINFOLOGPROC ptr_glGetProgramPipelineInfoLog = nullptr; void  glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { ptr_glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog); }
PFNGLVERTEXATTRIBL1DPROC ptr_glVertexAttribL1d = nullptr; void  glVertexAttribL1d(GLuint index, GLdouble x) { ptr_glVertexAttribL1d(index, x); }
PFNGLVERTEXATTRIBL2DPROC ptr_glVertexAttribL2d = nullptr; void  glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) { ptr_glVertexAttribL2d(index, x, y); }
PFNGLVERTEXATTRIBL3DPROC ptr_glVertexAttribL3d = nullptr; void  glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { ptr_glVertexAttribL3d(index, x, y, z); }
PFNGLVERTEXATTRIBL4DPROC ptr_glVertexAttribL4d = nullptr; void  glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { ptr_glVertexAttribL4d(index, x, y, z, w); }
PFNGLVERTEXATTRIBL1DVPROC ptr_glVertexAttribL1dv = nullptr; void  glVertexAttribL1dv(GLuint index, const GLdouble *v) { ptr_glVertexAttribL1dv(index, v); }
PFNGLVERTEXATTRIBL2DVPROC ptr_glVertexAttribL2dv = nullptr; void  glVertexAttribL2dv(GLuint index, const GLdouble *v) { ptr_glVertexAttribL2dv(index, v); }
PFNGLVERTEXATTRIBL3DVPROC ptr_glVertexAttribL3dv = nullptr; void  glVertexAttribL3dv(GLuint index, const GLdouble *v) { ptr_glVertexAttribL3dv(index, v); }
PFNGLVERTEXATTRIBL4DVPROC ptr_glVertexAttribL4dv = nullptr; void  glVertexAttribL4dv(GLuint index, const GLdouble *v) { ptr_glVertexAttribL4dv(index, v); }
PFNGLVERTEXATTRIBLPOINTERPROC ptr_glVertexAttribLPointer = nullptr; void  glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) { ptr_glVertexAttribLPointer(index, size, type, stride, pointer); }
PFNGLGETVERTEXATTRIBLDVPROC ptr_glGetVertexAttribLdv = nullptr; void  glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params) { ptr_glGetVertexAttribLdv(index, pname, params); }
PFNGLVIEWPORTARRAYVPROC ptr_glViewportArrayv = nullptr; void  glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v) { ptr_glViewportArrayv(first, count, v); }
PFNGLVIEWPORTINDEXEDFPROC ptr_glViewportIndexedf = nullptr; void  glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) { ptr_glViewportIndexedf(index, x, y, w, h); }
PFNGLVIEWPORTINDEXEDFVPROC ptr_glViewportIndexedfv = nullptr; void  glViewportIndexedfv(GLuint index, const GLfloat *v) { ptr_glViewportIndexedfv(index, v); }
PFNGLSCISSORARRAYVPROC ptr_glScissorArrayv = nullptr; void  glScissorArrayv(GLuint first, GLsizei count, const GLint *v) { ptr_glScissorArrayv(first, count, v); }
PFNGLSCISSORINDEXEDPROC ptr_glScissorIndexed = nullptr; void  glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) { ptr_glScissorIndexed(index, left, bottom, width, height); }
PFNGLSCISSORINDEXEDVPROC ptr_glScissorIndexedv = nullptr; void  glScissorIndexedv(GLuint index, const GLint *v) { ptr_glScissorIndexedv(index, v); }
PFNGLDEPTHRANGEARRAYVPROC ptr_glDepthRangeArrayv = nullptr; void  glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v) { ptr_glDepthRangeArrayv(first, count, v); }
PFNGLDEPTHRANGEINDEXEDPROC ptr_glDepthRangeIndexed = nullptr; void  glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) { ptr_glDepthRangeIndexed(index, n, f); }
PFNGLGETFLOATI_VPROC ptr_glGetFloati_v = nullptr; void  glGetFloati_v(GLenum target, GLuint index, GLfloat *data) { ptr_glGetFloati_v(target, index, data); }
PFNGLGETDOUBLEI_VPROC ptr_glGetDoublei_v = nullptr; void  glGetDoublei_v(GLenum target, GLuint index, GLdouble *data) { ptr_glGetDoublei_v(target, index, data); }
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC ptr_glDrawArraysInstancedBaseInstance = nullptr; void  glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) { ptr_glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance); }
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC ptr_glDrawElementsInstancedBaseInstance = nullptr; void  glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance) { ptr_glDrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance); }
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC ptr_glDrawElementsInstancedBaseVertexBaseInstance = nullptr; void  glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) { ptr_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance); }
PFNGLGETINTERNALFORMATIVPROC ptr_glGetInternalformativ = nullptr; void  glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params) { ptr_glGetInternalformativ(target, internalformat, pname, bufSize, params); }
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC ptr_glGetActiveAtomicCounterBufferiv = nullptr; void  glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params) { ptr_glGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params); }
PFNGLBINDIMAGETEXTUREPROC ptr_glBindImageTexture = nullptr; void  glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) { ptr_glBindImageTexture(unit, texture, level, layered, layer, access, format); }
PFNGLMEMORYBARRIERPROC ptr_glMemoryBarrier = nullptr; void  glMemoryBarrier(GLbitfield barriers) { ptr_glMemoryBarrier(barriers); }
PFNGLTEXSTORAGE1DPROC ptr_glTexStorage1D = nullptr; void  glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) { ptr_glTexStorage1D(target, levels, internalformat, width); }
PFNGLTEXSTORAGE2DPROC ptr_glTexStorage2D = nullptr; void  glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { ptr_glTexStorage2D(target, levels, internalformat, width, height); }
PFNGLTEXSTORAGE3DPROC ptr_glTexStorage3D = nullptr; void  glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { ptr_glTexStorage3D(target, levels, internalformat, width, height, depth); }
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC ptr_glDrawTransformFeedbackInstanced = nullptr; void  glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) { ptr_glDrawTransformFeedbackInstanced(mode, id, instancecount); }
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC ptr_glDrawTransformFeedbackStreamInstanced = nullptr; void  glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) { ptr_glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount); }
PFNGLCLEARBUFFERDATAPROC ptr_glClearBufferData = nullptr; void  glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data) { ptr_glClearBufferData(target, internalformat, format, type, data); }
PFNGLCLEARBUFFERSUBDATAPROC ptr_glClearBufferSubData = nullptr; void  glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) { ptr_glClearBufferSubData(target, internalformat, offset, size, format, type, data); }
PFNGLDISPATCHCOMPUTEPROC ptr_glDispatchCompute = nullptr; void  glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) { ptr_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z); }
PFNGLDISPATCHCOMPUTEINDIRECTPROC ptr_glDispatchComputeIndirect = nullptr; void  glDispatchComputeIndirect(GLintptr indirect) { ptr_glDispatchComputeIndirect(indirect); }
PFNGLCOPYIMAGESUBDATAPROC ptr_glCopyImageSubData = nullptr; void  glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) { ptr_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth); }
PFNGLFRAMEBUFFERPARAMETERIPROC ptr_glFramebufferParameteri = nullptr; void  glFramebufferParameteri(GLenum target, GLenum pname, GLint param) { ptr_glFramebufferParameteri(target, pname, param); }
PFNGLGETFRAMEBUFFERPARAMETERIVPROC ptr_glGetFramebufferParameteriv = nullptr; void  glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) { ptr_glGetFramebufferParameteriv(target, pname, params); }
PFNGLGETINTERNALFORMATI64VPROC ptr_glGetInternalformati64v = nullptr; void  glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params) { ptr_glGetInternalformati64v(target, internalformat, pname, bufSize, params); }
PFNGLINVALIDATETEXSUBIMAGEPROC ptr_glInvalidateTexSubImage = nullptr; void  glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) { ptr_glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth); }
PFNGLINVALIDATETEXIMAGEPROC ptr_glInvalidateTexImage = nullptr; void  glInvalidateTexImage(GLuint texture, GLint level) { ptr_glInvalidateTexImage(texture, level); }
PFNGLINVALIDATEBUFFERSUBDATAPROC ptr_glInvalidateBufferSubData = nullptr; void  glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) { ptr_glInvalidateBufferSubData(buffer, offset, length); }
PFNGLINVALIDATEBUFFERDATAPROC ptr_glInvalidateBufferData = nullptr; void  glInvalidateBufferData(GLuint buffer) { ptr_glInvalidateBufferData(buffer); }
PFNGLINVALIDATEFRAMEBUFFERPROC ptr_glInvalidateFramebuffer = nullptr; void  glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments) { ptr_glInvalidateFramebuffer(target, numAttachments, attachments); }
PFNGLINVALIDATESUBFRAMEBUFFERPROC ptr_glInvalidateSubFramebuffer = nullptr; void  glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) { ptr_glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height); }
PFNGLMULTIDRAWARRAYSINDIRECTPROC ptr_glMultiDrawArraysIndirect = nullptr; void  glMultiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride) { ptr_glMultiDrawArraysIndirect(mode, indirect, drawcount, stride); }
PFNGLMULTIDRAWELEMENTSINDIRECTPROC ptr_glMultiDrawElementsIndirect = nullptr; void  glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride) { ptr_glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride); }
PFNGLGETPROGRAMINTERFACEIVPROC ptr_glGetProgramInterfaceiv = nullptr; void  glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params) { ptr_glGetProgramInterfaceiv(program, programInterface, pname, params); }
PFNGLGETPROGRAMRESOURCEINDEXPROC ptr_glGetProgramResourceIndex = nullptr; GLuint  glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name) { return ptr_glGetProgramResourceIndex(program, programInterface, name); }
PFNGLGETPROGRAMRESOURCENAMEPROC ptr_glGetProgramResourceName = nullptr; void  glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) { ptr_glGetProgramResourceName(program, programInterface, index, bufSize, length, name); }
PFNGLGETPROGRAMRESOURCEIVPROC ptr_glGetProgramResourceiv = nullptr; void  glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params) { ptr_glGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params); }
PFNGLGETPROGRAMRESOURCELOCATIONPROC ptr_glGetProgramResourceLocation = nullptr; GLint  glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name) { return ptr_glGetProgramResourceLocation(program, programInterface, name); }
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC ptr_glGetProgramResourceLocationIndex = nullptr; GLint  glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar *name) { return ptr_glGetProgramResourceLocationIndex(program, programInterface, name); }
PFNGLSHADERSTORAGEBLOCKBINDINGPROC ptr_glShaderStorageBlockBinding = nullptr; void  glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) { ptr_glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding); }
PFNGLTEXBUFFERRANGEPROC ptr_glTexBufferRange = nullptr; void  glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) { ptr_glTexBufferRange(target, internalformat, buffer, offset, size); }
PFNGLTEXSTORAGE2DMULTISAMPLEPROC ptr_glTexStorage2DMultisample = nullptr; void  glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { ptr_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
PFNGLTEXSTORAGE3DMULTISAMPLEPROC ptr_glTexStorage3DMultisample = nullptr; void  glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { ptr_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
PFNGLTEXTUREVIEWPROC ptr_glTextureView = nullptr; void  glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) { ptr_glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers); }
PFNGLBINDVERTEXBUFFERPROC ptr_glBindVertexBuffer = nullptr; void  glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { ptr_glBindVertexBuffer(bindingindex, buffer, offset, stride); }
PFNGLVERTEXATTRIBFORMATPROC ptr_glVertexAttribFormat = nullptr; void  glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { ptr_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset); }
PFNGLVERTEXATTRIBIFORMATPROC ptr_glVertexAttribIFormat = nullptr; void  glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { ptr_glVertexAttribIFormat(attribindex, size, type, relativeoffset); }
PFNGLVERTEXATTRIBLFORMATPROC ptr_glVertexAttribLFormat = nullptr; void  glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { ptr_glVertexAttribLFormat(attribindex, size, type, relativeoffset); }
PFNGLVERTEXATTRIBBINDINGPROC ptr_glVertexAttribBinding = nullptr; void  glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) { ptr_glVertexAttribBinding(attribindex, bindingindex); }
PFNGLVERTEXBINDINGDIVISORPROC ptr_glVertexBindingDivisor = nullptr; void  glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) { ptr_glVertexBindingDivisor(bindingindex, divisor); }
PFNGLDEBUGMESSAGECONTROLPROC ptr_glDebugMessageControl = nullptr; void  glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) { ptr_glDebugMessageControl(source, type, severity, count, ids, enabled); }
PFNGLDEBUGMESSAGEINSERTPROC ptr_glDebugMessageInsert = nullptr; void  glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) { ptr_glDebugMessageInsert(source, type, id, severity, length, buf); }
PFNGLDEBUGMESSAGECALLBACKPROC ptr_glDebugMessageCallback = nullptr; void  glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam) { ptr_glDebugMessageCallback(callback, userParam); }
PFNGLGETDEBUGMESSAGELOGPROC ptr_glGetDebugMessageLog = nullptr; GLuint  glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) { return ptr_glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog); }
PFNGLPUSHDEBUGGROUPPROC ptr_glPushDebugGroup = nullptr; void  glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) { ptr_glPushDebugGroup(source, id, length, message); }
PFNGLPOPDEBUGGROUPPROC ptr_glPopDebugGroup = nullptr; void  glPopDebugGroup(void) { ptr_glPopDebugGroup(); }
PFNGLOBJECTLABELPROC ptr_glObjectLabel = nullptr; void  glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label) { ptr_glObjectLabel(identifier, name, length, label); }
PFNGLGETOBJECTLABELPROC ptr_glGetObjectLabel = nullptr; void  glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) { ptr_glGetObjectLabel(identifier, name, bufSize, length, label); }
PFNGLOBJECTPTRLABELPROC ptr_glObjectPtrLabel = nullptr; void  glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label) { ptr_glObjectPtrLabel(ptr, length, label); }
PFNGLGETOBJECTPTRLABELPROC ptr_glGetObjectPtrLabel = nullptr; void  glGetObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) { ptr_glGetObjectPtrLabel(ptr, bufSize, length, label); }
PFNGLBUFFERSTORAGEPROC ptr_glBufferStorage = nullptr; void  glBufferStorage(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags) { ptr_glBufferStorage(target, size, data, flags); }
PFNGLCLEARTEXIMAGEPROC ptr_glClearTexImage = nullptr; void  glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void *data) { ptr_glClearTexImage(texture, level, format, type, data); }
PFNGLCLEARTEXSUBIMAGEPROC ptr_glClearTexSubImage = nullptr; void  glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data) { ptr_glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data); }
PFNGLBINDBUFFERSBASEPROC ptr_glBindBuffersBase = nullptr; void  glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers) { ptr_glBindBuffersBase(target, first, count, buffers); }
PFNGLBINDBUFFERSRANGEPROC ptr_glBindBuffersRange = nullptr; void  glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes) { ptr_glBindBuffersRange(target, first, count, buffers, offsets, sizes); }
PFNGLBINDTEXTURESPROC ptr_glBindTextures = nullptr; void  glBindTextures(GLuint first, GLsizei count, const GLuint *textures) { ptr_glBindTextures(first, count, textures); }
PFNGLBINDSAMPLERSPROC ptr_glBindSamplers = nullptr; void  glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers) { ptr_glBindSamplers(first, count, samplers); }
PFNGLBINDIMAGETEXTURESPROC ptr_glBindImageTextures = nullptr; void  glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures) { ptr_glBindImageTextures(first, count, textures); }
PFNGLBINDVERTEXBUFFERSPROC ptr_glBindVertexBuffers = nullptr; void  glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) { ptr_glBindVertexBuffers(first, count, buffers, offsets, strides); }
PFNGLCLIPCONTROLPROC ptr_glClipControl = nullptr; void  glClipControl(GLenum origin, GLenum depth) { ptr_glClipControl(origin, depth); }
PFNGLCREATETRANSFORMFEEDBACKSPROC ptr_glCreateTransformFeedbacks = nullptr; void  glCreateTransformFeedbacks(GLsizei n, GLuint *ids) { ptr_glCreateTransformFeedbacks(n, ids); }
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC ptr_glTransformFeedbackBufferBase = nullptr; void  glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) { ptr_glTransformFeedbackBufferBase(xfb, index, buffer); }
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC ptr_glTransformFeedbackBufferRange = nullptr; void  glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { ptr_glTransformFeedbackBufferRange(xfb, index, buffer, offset, size); }
PFNGLGETTRANSFORMFEEDBACKIVPROC ptr_glGetTransformFeedbackiv = nullptr; void  glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint *param) { ptr_glGetTransformFeedbackiv(xfb, pname, param); }
PFNGLGETTRANSFORMFEEDBACKI_VPROC ptr_glGetTransformFeedbacki_v = nullptr; void  glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint *param) { ptr_glGetTransformFeedbacki_v(xfb, pname, index, param); }
PFNGLGETTRANSFORMFEEDBACKI64_VPROC ptr_glGetTransformFeedbacki64_v = nullptr; void  glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 *param) { ptr_glGetTransformFeedbacki64_v(xfb, pname, index, param); }
PFNGLCREATEBUFFERSPROC ptr_glCreateBuffers = nullptr; void  glCreateBuffers(GLsizei n, GLuint *buffers) { ptr_glCreateBuffers(n, buffers); }
PFNGLNAMEDBUFFERSTORAGEPROC ptr_glNamedBufferStorage = nullptr; void  glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) { ptr_glNamedBufferStorage(buffer, size, data, flags); }
PFNGLNAMEDBUFFERDATAPROC ptr_glNamedBufferData = nullptr; void  glNamedBufferData(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) { ptr_glNamedBufferData(buffer, size, data, usage); }
PFNGLNAMEDBUFFERSUBDATAPROC ptr_glNamedBufferSubData = nullptr; void  glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) { ptr_glNamedBufferSubData(buffer, offset, size, data); }
PFNGLCOPYNAMEDBUFFERSUBDATAPROC ptr_glCopyNamedBufferSubData = nullptr; void  glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { ptr_glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size); }
PFNGLCLEARNAMEDBUFFERDATAPROC ptr_glClearNamedBufferData = nullptr; void  glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) { ptr_glClearNamedBufferData(buffer, internalformat, format, type, data); }
PFNGLCLEARNAMEDBUFFERSUBDATAPROC ptr_glClearNamedBufferSubData = nullptr; void  glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) { ptr_glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data); }
PFNGLMAPNAMEDBUFFERPROC ptr_glMapNamedBuffer = nullptr; void * glMapNamedBuffer(GLuint buffer, GLenum access) { return ptr_glMapNamedBuffer(buffer, access); }
PFNGLMAPNAMEDBUFFERRANGEPROC ptr_glMapNamedBufferRange = nullptr; void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) { return ptr_glMapNamedBufferRange(buffer, offset, length, access); }
PFNGLUNMAPNAMEDBUFFERPROC ptr_glUnmapNamedBuffer = nullptr; GLboolean  glUnmapNamedBuffer(GLuint buffer) { return ptr_glUnmapNamedBuffer(buffer); }
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC ptr_glFlushMappedNamedBufferRange = nullptr; void  glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) { ptr_glFlushMappedNamedBufferRange(buffer, offset, length); }
PFNGLGETNAMEDBUFFERPARAMETERIVPROC ptr_glGetNamedBufferParameteriv = nullptr; void  glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint *params) { ptr_glGetNamedBufferParameteriv(buffer, pname, params); }
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC ptr_glGetNamedBufferParameteri64v = nullptr; void  glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 *params) { ptr_glGetNamedBufferParameteri64v(buffer, pname, params); }
PFNGLGETNAMEDBUFFERPOINTERVPROC ptr_glGetNamedBufferPointerv = nullptr; void  glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void **params) { ptr_glGetNamedBufferPointerv(buffer, pname, params); }
PFNGLGETNAMEDBUFFERSUBDATAPROC ptr_glGetNamedBufferSubData = nullptr; void  glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) { ptr_glGetNamedBufferSubData(buffer, offset, size, data); }
PFNGLCREATEFRAMEBUFFERSPROC ptr_glCreateFramebuffers = nullptr; void  glCreateFramebuffers(GLsizei n, GLuint *framebuffers) { ptr_glCreateFramebuffers(n, framebuffers); }
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC ptr_glNamedFramebufferRenderbuffer = nullptr; void  glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { ptr_glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer); }
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC ptr_glNamedFramebufferParameteri = nullptr; void  glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) { ptr_glNamedFramebufferParameteri(framebuffer, pname, param); }
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC ptr_glNamedFramebufferTexture = nullptr; void  glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) { ptr_glNamedFramebufferTexture(framebuffer, attachment, texture, level); }
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC ptr_glNamedFramebufferTextureLayer = nullptr; void  glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) { ptr_glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer); }
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC ptr_glNamedFramebufferDrawBuffer = nullptr; void  glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) { ptr_glNamedFramebufferDrawBuffer(framebuffer, buf); }
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC ptr_glNamedFramebufferDrawBuffers = nullptr; void  glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum *bufs) { ptr_glNamedFramebufferDrawBuffers(framebuffer, n, bufs); }
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC ptr_glNamedFramebufferReadBuffer = nullptr; void  glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) { ptr_glNamedFramebufferReadBuffer(framebuffer, src); }
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC ptr_glInvalidateNamedFramebufferData = nullptr; void  glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments) { ptr_glInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments); }
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC ptr_glInvalidateNamedFramebufferSubData = nullptr; void  glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) { ptr_glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height); }
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC ptr_glClearNamedFramebufferiv = nullptr; void  glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value) { ptr_glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value); }
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC ptr_glClearNamedFramebufferuiv = nullptr; void  glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value) { ptr_glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value); }
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC ptr_glClearNamedFramebufferfv = nullptr; void  glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value) { ptr_glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value); }
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC ptr_glClearNamedFramebufferfi = nullptr; void  glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { ptr_glClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil); }
PFNGLBLITNAMEDFRAMEBUFFERPROC ptr_glBlitNamedFramebuffer = nullptr; void  glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { ptr_glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC ptr_glCheckNamedFramebufferStatus = nullptr; GLenum  glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) { return ptr_glCheckNamedFramebufferStatus(framebuffer, target); }
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC ptr_glGetNamedFramebufferParameteriv = nullptr; void  glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint *param) { ptr_glGetNamedFramebufferParameteriv(framebuffer, pname, param); }
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC ptr_glGetNamedFramebufferAttachmentParameteriv = nullptr; void  glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) { ptr_glGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params); }
PFNGLCREATERENDERBUFFERSPROC ptr_glCreateRenderbuffers = nullptr; void  glCreateRenderbuffers(GLsizei n, GLuint *renderbuffers) { ptr_glCreateRenderbuffers(n, renderbuffers); }
PFNGLNAMEDRENDERBUFFERSTORAGEPROC ptr_glNamedRenderbufferStorage = nullptr; void  glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) { ptr_glNamedRenderbufferStorage(renderbuffer, internalformat, width, height); }
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC ptr_glNamedRenderbufferStorageMultisample = nullptr; void  glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { ptr_glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height); }
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC ptr_glGetNamedRenderbufferParameteriv = nullptr; void  glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint *params) { ptr_glGetNamedRenderbufferParameteriv(renderbuffer, pname, params); }
PFNGLCREATETEXTURESPROC ptr_glCreateTextures = nullptr; void  glCreateTextures(GLenum target, GLsizei n, GLuint *textures) { ptr_glCreateTextures(target, n, textures); }
PFNGLTEXTUREBUFFERPROC ptr_glTextureBuffer = nullptr; void  glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) { ptr_glTextureBuffer(texture, internalformat, buffer); }
PFNGLTEXTUREBUFFERRANGEPROC ptr_glTextureBufferRange = nullptr; void  glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) { ptr_glTextureBufferRange(texture, internalformat, buffer, offset, size); }
PFNGLTEXTURESTORAGE1DPROC ptr_glTextureStorage1D = nullptr; void  glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) { ptr_glTextureStorage1D(texture, levels, internalformat, width); }
PFNGLTEXTURESTORAGE2DPROC ptr_glTextureStorage2D = nullptr; void  glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { ptr_glTextureStorage2D(texture, levels, internalformat, width, height); }
PFNGLTEXTURESTORAGE3DPROC ptr_glTextureStorage3D = nullptr; void  glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { ptr_glTextureStorage3D(texture, levels, internalformat, width, height, depth); }
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC ptr_glTextureStorage2DMultisample = nullptr; void  glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { ptr_glTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations); }
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC ptr_glTextureStorage3DMultisample = nullptr; void  glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { ptr_glTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations); }
PFNGLTEXTURESUBIMAGE1DPROC ptr_glTextureSubImage1D = nullptr; void  glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) { ptr_glTextureSubImage1D(texture, level, xoffset, width, format, type, pixels); }
PFNGLTEXTURESUBIMAGE2DPROC ptr_glTextureSubImage2D = nullptr; void  glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { ptr_glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels); }
PFNGLTEXTURESUBIMAGE3DPROC ptr_glTextureSubImage3D = nullptr; void  glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) { ptr_glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC ptr_glCompressedTextureSubImage1D = nullptr; void  glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) { ptr_glCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data); }
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC ptr_glCompressedTextureSubImage2D = nullptr; void  glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) { ptr_glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data); }
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC ptr_glCompressedTextureSubImage3D = nullptr; void  glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) { ptr_glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
PFNGLCOPYTEXTURESUBIMAGE1DPROC ptr_glCopyTextureSubImage1D = nullptr; void  glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { ptr_glCopyTextureSubImage1D(texture, level, xoffset, x, y, width); }
PFNGLCOPYTEXTURESUBIMAGE2DPROC ptr_glCopyTextureSubImage2D = nullptr; void  glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { ptr_glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height); }
PFNGLCOPYTEXTURESUBIMAGE3DPROC ptr_glCopyTextureSubImage3D = nullptr; void  glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { ptr_glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height); }
PFNGLTEXTUREPARAMETERFPROC ptr_glTextureParameterf = nullptr; void  glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) { ptr_glTextureParameterf(texture, pname, param); }
PFNGLTEXTUREPARAMETERFVPROC ptr_glTextureParameterfv = nullptr; void  glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat *param) { ptr_glTextureParameterfv(texture, pname, param); }
PFNGLTEXTUREPARAMETERIPROC ptr_glTextureParameteri = nullptr; void  glTextureParameteri(GLuint texture, GLenum pname, GLint param) { ptr_glTextureParameteri(texture, pname, param); }
PFNGLTEXTUREPARAMETERIIVPROC ptr_glTextureParameterIiv = nullptr; void  glTextureParameterIiv(GLuint texture, GLenum pname, const GLint *params) { ptr_glTextureParameterIiv(texture, pname, params); }
PFNGLTEXTUREPARAMETERIUIVPROC ptr_glTextureParameterIuiv = nullptr; void  glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint *params) { ptr_glTextureParameterIuiv(texture, pname, params); }
PFNGLTEXTUREPARAMETERIVPROC ptr_glTextureParameteriv = nullptr; void  glTextureParameteriv(GLuint texture, GLenum pname, const GLint *param) { ptr_glTextureParameteriv(texture, pname, param); }
PFNGLGENERATETEXTUREMIPMAPPROC ptr_glGenerateTextureMipmap = nullptr; void  glGenerateTextureMipmap(GLuint texture) { ptr_glGenerateTextureMipmap(texture); }
PFNGLBINDTEXTUREUNITPROC ptr_glBindTextureUnit = nullptr; void  glBindTextureUnit(GLuint unit, GLuint texture) { ptr_glBindTextureUnit(unit, texture); }
PFNGLGETTEXTUREIMAGEPROC ptr_glGetTextureImage = nullptr; void  glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { ptr_glGetTextureImage(texture, level, format, type, bufSize, pixels); }
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC ptr_glGetCompressedTextureImage = nullptr; void  glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void *pixels) { ptr_glGetCompressedTextureImage(texture, level, bufSize, pixels); }
PFNGLGETTEXTURELEVELPARAMETERFVPROC ptr_glGetTextureLevelParameterfv = nullptr; void  glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat *params) { ptr_glGetTextureLevelParameterfv(texture, level, pname, params); }
PFNGLGETTEXTURELEVELPARAMETERIVPROC ptr_glGetTextureLevelParameteriv = nullptr; void  glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint *params) { ptr_glGetTextureLevelParameteriv(texture, level, pname, params); }
PFNGLGETTEXTUREPARAMETERFVPROC ptr_glGetTextureParameterfv = nullptr; void  glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat *params) { ptr_glGetTextureParameterfv(texture, pname, params); }
PFNGLGETTEXTUREPARAMETERIIVPROC ptr_glGetTextureParameterIiv = nullptr; void  glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint *params) { ptr_glGetTextureParameterIiv(texture, pname, params); }
PFNGLGETTEXTUREPARAMETERIUIVPROC ptr_glGetTextureParameterIuiv = nullptr; void  glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint *params) { ptr_glGetTextureParameterIuiv(texture, pname, params); }
PFNGLGETTEXTUREPARAMETERIVPROC ptr_glGetTextureParameteriv = nullptr; void  glGetTextureParameteriv(GLuint texture, GLenum pname, GLint *params) { ptr_glGetTextureParameteriv(texture, pname, params); }
PFNGLCREATEVERTEXARRAYSPROC ptr_glCreateVertexArrays = nullptr; void  glCreateVertexArrays(GLsizei n, GLuint *arrays) { ptr_glCreateVertexArrays(n, arrays); }
PFNGLDISABLEVERTEXARRAYATTRIBPROC ptr_glDisableVertexArrayAttrib = nullptr; void  glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) { ptr_glDisableVertexArrayAttrib(vaobj, index); }
PFNGLENABLEVERTEXARRAYATTRIBPROC ptr_glEnableVertexArrayAttrib = nullptr; void  glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) { ptr_glEnableVertexArrayAttrib(vaobj, index); }
PFNGLVERTEXARRAYELEMENTBUFFERPROC ptr_glVertexArrayElementBuffer = nullptr; void  glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) { ptr_glVertexArrayElementBuffer(vaobj, buffer); }
PFNGLVERTEXARRAYVERTEXBUFFERPROC ptr_glVertexArrayVertexBuffer = nullptr; void  glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { ptr_glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride); }
PFNGLVERTEXARRAYVERTEXBUFFERSPROC ptr_glVertexArrayVertexBuffers = nullptr; void  glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) { ptr_glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides); }
PFNGLVERTEXARRAYATTRIBBINDINGPROC ptr_glVertexArrayAttribBinding = nullptr; void  glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) { ptr_glVertexArrayAttribBinding(vaobj, attribindex, bindingindex); }
PFNGLVERTEXARRAYATTRIBFORMATPROC ptr_glVertexArrayAttribFormat = nullptr; void  glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { ptr_glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset); }
PFNGLVERTEXARRAYATTRIBIFORMATPROC ptr_glVertexArrayAttribIFormat = nullptr; void  glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { ptr_glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset); }
PFNGLVERTEXARRAYATTRIBLFORMATPROC ptr_glVertexArrayAttribLFormat = nullptr; void  glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { ptr_glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset); }
PFNGLVERTEXARRAYBINDINGDIVISORPROC ptr_glVertexArrayBindingDivisor = nullptr; void  glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) { ptr_glVertexArrayBindingDivisor(vaobj, bindingindex, divisor); }
PFNGLGETVERTEXARRAYIVPROC ptr_glGetVertexArrayiv = nullptr; void  glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint *param) { ptr_glGetVertexArrayiv(vaobj, pname, param); }
PFNGLGETVERTEXARRAYINDEXEDIVPROC ptr_glGetVertexArrayIndexediv = nullptr; void  glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint *param) { ptr_glGetVertexArrayIndexediv(vaobj, index, pname, param); }
PFNGLGETVERTEXARRAYINDEXED64IVPROC ptr_glGetVertexArrayIndexed64iv = nullptr; void  glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param) { ptr_glGetVertexArrayIndexed64iv(vaobj, index, pname, param); }
PFNGLCREATESAMPLERSPROC ptr_glCreateSamplers = nullptr; void  glCreateSamplers(GLsizei n, GLuint *samplers) { ptr_glCreateSamplers(n, samplers); }
PFNGLCREATEPROGRAMPIPELINESPROC ptr_glCreateProgramPipelines = nullptr; void  glCreateProgramPipelines(GLsizei n, GLuint *pipelines) { ptr_glCreateProgramPipelines(n, pipelines); }
PFNGLCREATEQUERIESPROC ptr_glCreateQueries = nullptr; void  glCreateQueries(GLenum target, GLsizei n, GLuint *ids) { ptr_glCreateQueries(target, n, ids); }
PFNGLGETQUERYBUFFEROBJECTI64VPROC ptr_glGetQueryBufferObjecti64v = nullptr; void  glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { ptr_glGetQueryBufferObjecti64v(id, buffer, pname, offset); }
PFNGLGETQUERYBUFFEROBJECTIVPROC ptr_glGetQueryBufferObjectiv = nullptr; void  glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { ptr_glGetQueryBufferObjectiv(id, buffer, pname, offset); }
PFNGLGETQUERYBUFFEROBJECTUI64VPROC ptr_glGetQueryBufferObjectui64v = nullptr; void  glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { ptr_glGetQueryBufferObjectui64v(id, buffer, pname, offset); }
PFNGLGETQUERYBUFFEROBJECTUIVPROC ptr_glGetQueryBufferObjectuiv = nullptr; void  glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { ptr_glGetQueryBufferObjectuiv(id, buffer, pname, offset); }
PFNGLMEMORYBARRIERBYREGIONPROC ptr_glMemoryBarrierByRegion = nullptr; void  glMemoryBarrierByRegion(GLbitfield barriers) { ptr_glMemoryBarrierByRegion(barriers); }
PFNGLGETTEXTURESUBIMAGEPROC ptr_glGetTextureSubImage = nullptr; void  glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { ptr_glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels); }
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC ptr_glGetCompressedTextureSubImage = nullptr; void  glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels) { ptr_glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels); }
PFNGLGETGRAPHICSRESETSTATUSPROC ptr_glGetGraphicsResetStatus = nullptr; GLenum  glGetGraphicsResetStatus(void) { return ptr_glGetGraphicsResetStatus(); }
PFNGLGETNCOMPRESSEDTEXIMAGEPROC ptr_glGetnCompressedTexImage = nullptr; void  glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void *pixels) { ptr_glGetnCompressedTexImage(target, lod, bufSize, pixels); }
PFNGLGETNTEXIMAGEPROC ptr_glGetnTexImage = nullptr; void  glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { ptr_glGetnTexImage(target, level, format, type, bufSize, pixels); }
PFNGLGETNUNIFORMDVPROC ptr_glGetnUniformdv = nullptr; void  glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble *params) { ptr_glGetnUniformdv(program, location, bufSize, params); }
PFNGLGETNUNIFORMFVPROC ptr_glGetnUniformfv = nullptr; void  glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params) { ptr_glGetnUniformfv(program, location, bufSize, params); }
PFNGLGETNUNIFORMIVPROC ptr_glGetnUniformiv = nullptr; void  glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params) { ptr_glGetnUniformiv(program, location, bufSize, params); }
PFNGLGETNUNIFORMUIVPROC ptr_glGetnUniformuiv = nullptr; void  glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params) { ptr_glGetnUniformuiv(program, location, bufSize, params); }
PFNGLREADNPIXELSPROC ptr_glReadnPixels = nullptr; void  glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) { ptr_glReadnPixels(x, y, width, height, format, type, bufSize, data); }
PFNGLGETNMAPDVPROC ptr_glGetnMapdv = nullptr; void  glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v) { ptr_glGetnMapdv(target, query, bufSize, v); }
PFNGLGETNMAPFVPROC ptr_glGetnMapfv = nullptr; void  glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v) { ptr_glGetnMapfv(target, query, bufSize, v); }
PFNGLGETNMAPIVPROC ptr_glGetnMapiv = nullptr; void  glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint *v) { ptr_glGetnMapiv(target, query, bufSize, v); }
PFNGLGETNPIXELMAPFVPROC ptr_glGetnPixelMapfv = nullptr; void  glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat *values) { ptr_glGetnPixelMapfv(map, bufSize, values); }
PFNGLGETNPIXELMAPUIVPROC ptr_glGetnPixelMapuiv = nullptr; void  glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint *values) { ptr_glGetnPixelMapuiv(map, bufSize, values); }
PFNGLGETNPIXELMAPUSVPROC ptr_glGetnPixelMapusv = nullptr; void  glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort *values) { ptr_glGetnPixelMapusv(map, bufSize, values); }
PFNGLGETNPOLYGONSTIPPLEPROC ptr_glGetnPolygonStipple = nullptr; void  glGetnPolygonStipple(GLsizei bufSize, GLubyte *pattern) { ptr_glGetnPolygonStipple(bufSize, pattern); }
PFNGLGETNCOLORTABLEPROC ptr_glGetnColorTable = nullptr; void  glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table) { ptr_glGetnColorTable(target, format, type, bufSize, table); }
PFNGLGETNCONVOLUTIONFILTERPROC ptr_glGetnConvolutionFilter = nullptr; void  glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image) { ptr_glGetnConvolutionFilter(target, format, type, bufSize, image); }
PFNGLGETNSEPARABLEFILTERPROC ptr_glGetnSeparableFilter = nullptr; void  glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span) { ptr_glGetnSeparableFilter(target, format, type, rowBufSize, row, columnBufSize, column, span); }
PFNGLGETNHISTOGRAMPROC ptr_glGetnHistogram = nullptr; void  glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) { ptr_glGetnHistogram(target, reset, format, type, bufSize, values); }
PFNGLGETNMINMAXPROC ptr_glGetnMinmax = nullptr; void  glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) { ptr_glGetnMinmax(target, reset, format, type, bufSize, values); }
PFNGLTEXTUREBARRIERPROC ptr_glTextureBarrier = nullptr; void  glTextureBarrier(void) { ptr_glTextureBarrier(); }
PFNGLSPECIALIZESHADERPROC ptr_glSpecializeShader = nullptr; void  glSpecializeShader(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue) { ptr_glSpecializeShader(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue); }
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC ptr_glMultiDrawArraysIndirectCount = nullptr; void  glMultiDrawArraysIndirectCount(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) { ptr_glMultiDrawArraysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride); }
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC ptr_glMultiDrawElementsIndirectCount = nullptr; void  glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) { ptr_glMultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride); }
PFNGLPOLYGONOFFSETCLAMPPROC ptr_glPolygonOffsetClamp = nullptr; void  glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) { ptr_glPolygonOffsetClamp(factor, units, clamp); }
PFNGLGETTEXTUREHANDLEARBPROC ptr_glGetTextureHandle = nullptr; GLuint64  glGetTextureHandle(GLuint texture) { return ptr_glGetTextureHandle(texture); }
PFNGLGETTEXTURESAMPLERHANDLEARBPROC ptr_glGetTextureSamplerHandle = nullptr; GLuint64  glGetTextureSamplerHandle(GLuint texture, GLuint sampler) { return ptr_glGetTextureSamplerHandle(texture, sampler); }
PFNGLMAKETEXTUREHANDLERESIDENTARBPROC ptr_glMakeTextureHandleResident = nullptr; void  glMakeTextureHandleResident(GLuint64 handle) { ptr_glMakeTextureHandleResident(handle); }
PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC ptr_glMakeTextureHandleNonResident = nullptr; void  glMakeTextureHandleNonResident(GLuint64 handle) { ptr_glMakeTextureHandleNonResident(handle); }
PFNGLGETIMAGEHANDLEARBPROC ptr_glGetImageHandle = nullptr; GLuint64  glGetImageHandle(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) { return ptr_glGetImageHandle(texture, level, layered, layer, format); }
PFNGLMAKEIMAGEHANDLERESIDENTARBPROC ptr_glMakeImageHandleResident = nullptr; void  glMakeImageHandleResident(GLuint64 handle, GLenum access) { ptr_glMakeImageHandleResident(handle, access); }
PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC ptr_glMakeImageHandleNonResident = nullptr; void  glMakeImageHandleNonResident(GLuint64 handle) { ptr_glMakeImageHandleNonResident(handle); }
PFNGLUNIFORMHANDLEUI64ARBPROC ptr_glUniformHandleui64 = nullptr; void  glUniformHandleui64(GLint location, GLuint64 value) { ptr_glUniformHandleui64(location, value); }
PFNGLUNIFORMHANDLEUI64VARBPROC ptr_glUniformHandleui64v = nullptr; void  glUniformHandleui64v(GLint location, GLsizei count, const GLuint64 *value) { ptr_glUniformHandleui64v(location, count, value); }
PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC ptr_glProgramUniformHandleui64 = nullptr; void  glProgramUniformHandleui64(GLuint program, GLint location, GLuint64 value) { ptr_glProgramUniformHandleui64(program, location, value); }
PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC ptr_glProgramUniformHandleui64v = nullptr; void  glProgramUniformHandleui64v(GLuint program, GLint location, GLsizei count, const GLuint64 *values) { ptr_glProgramUniformHandleui64v(program, location, count, values); }
PFNGLISTEXTUREHANDLERESIDENTARBPROC ptr_glIsTextureHandleResident = nullptr; GLboolean  glIsTextureHandleResident(GLuint64 handle) { return ptr_glIsTextureHandleResident(handle); }
PFNGLISIMAGEHANDLERESIDENTARBPROC ptr_glIsImageHandleResident = nullptr; GLboolean  glIsImageHandleResident(GLuint64 handle) { return ptr_glIsImageHandleResident(handle); }
PFNGLVERTEXATTRIBL1UI64ARBPROC ptr_glVertexAttribL1ui64 = nullptr; void  glVertexAttribL1ui64(GLuint index, GLuint64EXT x) { ptr_glVertexAttribL1ui64(index, x); }
PFNGLVERTEXATTRIBL1UI64VARBPROC ptr_glVertexAttribL1ui64v = nullptr; void  glVertexAttribL1ui64v(GLuint index, const GLuint64EXT *v) { ptr_glVertexAttribL1ui64v(index, v); }
PFNGLGETVERTEXATTRIBLUI64VARBPROC ptr_glGetVertexAttribLui64v = nullptr; void  glGetVertexAttribLui64v(GLuint index, GLenum pname, GLuint64EXT *params) { ptr_glGetVertexAttribLui64v(index, pname, params); }

#ifndef _WIN32
#define wglGetProcAddress eglGetProcAddress
#include <stdio.h>
#include <EGL/egl.h>
const char* TEXT(const char* t) {return t;}
int MB_OK = 0;
void MessageBox(int, const char* text, const char* title, int) {printf("%s\n", text);} 
#endif

int loadgl() {
	int result = 0;

	ptr_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)wglGetProcAddress("glDrawRangeElements");
	if(!ptr_glDrawRangeElements) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.2, function \"glDrawRangeElements\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexImage3D = (PFNGLTEXIMAGE3DPROC)wglGetProcAddress("glTexImage3D");
	if(!ptr_glTexImage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.2, function \"glTexImage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)wglGetProcAddress("glTexSubImage3D");
	if(!ptr_glTexSubImage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.2, function \"glTexSubImage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)wglGetProcAddress("glCopyTexSubImage3D");
	if(!ptr_glCopyTexSubImage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.2, function \"glCopyTexSubImage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
	if(!ptr_glActiveTexture) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glActiveTexture\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)wglGetProcAddress("glSampleCoverage");
	if(!ptr_glSampleCoverage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glSampleCoverage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)wglGetProcAddress("glCompressedTexImage3D");
	if(!ptr_glCompressedTexImage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glCompressedTexImage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)wglGetProcAddress("glCompressedTexImage2D");
	if(!ptr_glCompressedTexImage2D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glCompressedTexImage2D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)wglGetProcAddress("glCompressedTexImage1D");
	if(!ptr_glCompressedTexImage1D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glCompressedTexImage1D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)wglGetProcAddress("glCompressedTexSubImage3D");
	if(!ptr_glCompressedTexSubImage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glCompressedTexSubImage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)wglGetProcAddress("glCompressedTexSubImage2D");
	if(!ptr_glCompressedTexSubImage2D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glCompressedTexSubImage2D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)wglGetProcAddress("glCompressedTexSubImage1D");
	if(!ptr_glCompressedTexSubImage1D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glCompressedTexSubImage1D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)wglGetProcAddress("glGetCompressedTexImage");
	if(!ptr_glGetCompressedTexImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glGetCompressedTexImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)wglGetProcAddress("glClientActiveTexture");
	if(!ptr_glClientActiveTexture) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glClientActiveTexture\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)wglGetProcAddress("glMultiTexCoord1d");
	if(!ptr_glMultiTexCoord1d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord1d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)wglGetProcAddress("glMultiTexCoord1dv");
	if(!ptr_glMultiTexCoord1dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord1dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)wglGetProcAddress("glMultiTexCoord1f");
	if(!ptr_glMultiTexCoord1f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord1f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)wglGetProcAddress("glMultiTexCoord1fv");
	if(!ptr_glMultiTexCoord1fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord1fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)wglGetProcAddress("glMultiTexCoord1i");
	if(!ptr_glMultiTexCoord1i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord1i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)wglGetProcAddress("glMultiTexCoord1iv");
	if(!ptr_glMultiTexCoord1iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord1iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)wglGetProcAddress("glMultiTexCoord1s");
	if(!ptr_glMultiTexCoord1s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord1s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)wglGetProcAddress("glMultiTexCoord1sv");
	if(!ptr_glMultiTexCoord1sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord1sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)wglGetProcAddress("glMultiTexCoord2d");
	if(!ptr_glMultiTexCoord2d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord2d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)wglGetProcAddress("glMultiTexCoord2dv");
	if(!ptr_glMultiTexCoord2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)wglGetProcAddress("glMultiTexCoord2f");
	if(!ptr_glMultiTexCoord2f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord2f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)wglGetProcAddress("glMultiTexCoord2fv");
	if(!ptr_glMultiTexCoord2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)wglGetProcAddress("glMultiTexCoord2i");
	if(!ptr_glMultiTexCoord2i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord2i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)wglGetProcAddress("glMultiTexCoord2iv");
	if(!ptr_glMultiTexCoord2iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord2iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)wglGetProcAddress("glMultiTexCoord2s");
	if(!ptr_glMultiTexCoord2s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord2s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)wglGetProcAddress("glMultiTexCoord2sv");
	if(!ptr_glMultiTexCoord2sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord2sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)wglGetProcAddress("glMultiTexCoord3d");
	if(!ptr_glMultiTexCoord3d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord3d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)wglGetProcAddress("glMultiTexCoord3dv");
	if(!ptr_glMultiTexCoord3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)wglGetProcAddress("glMultiTexCoord3f");
	if(!ptr_glMultiTexCoord3f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord3f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)wglGetProcAddress("glMultiTexCoord3fv");
	if(!ptr_glMultiTexCoord3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)wglGetProcAddress("glMultiTexCoord3i");
	if(!ptr_glMultiTexCoord3i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord3i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)wglGetProcAddress("glMultiTexCoord3iv");
	if(!ptr_glMultiTexCoord3iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord3iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)wglGetProcAddress("glMultiTexCoord3s");
	if(!ptr_glMultiTexCoord3s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord3s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)wglGetProcAddress("glMultiTexCoord3sv");
	if(!ptr_glMultiTexCoord3sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord3sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)wglGetProcAddress("glMultiTexCoord4d");
	if(!ptr_glMultiTexCoord4d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord4d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)wglGetProcAddress("glMultiTexCoord4dv");
	if(!ptr_glMultiTexCoord4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)wglGetProcAddress("glMultiTexCoord4f");
	if(!ptr_glMultiTexCoord4f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord4f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)wglGetProcAddress("glMultiTexCoord4fv");
	if(!ptr_glMultiTexCoord4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)wglGetProcAddress("glMultiTexCoord4i");
	if(!ptr_glMultiTexCoord4i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord4i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)wglGetProcAddress("glMultiTexCoord4iv");
	if(!ptr_glMultiTexCoord4iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord4iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)wglGetProcAddress("glMultiTexCoord4s");
	if(!ptr_glMultiTexCoord4s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord4s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)wglGetProcAddress("glMultiTexCoord4sv");
	if(!ptr_glMultiTexCoord4sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultiTexCoord4sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)wglGetProcAddress("glLoadTransposeMatrixf");
	if(!ptr_glLoadTransposeMatrixf) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glLoadTransposeMatrixf\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)wglGetProcAddress("glLoadTransposeMatrixd");
	if(!ptr_glLoadTransposeMatrixd) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glLoadTransposeMatrixd\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)wglGetProcAddress("glMultTransposeMatrixf");
	if(!ptr_glMultTransposeMatrixf) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultTransposeMatrixf\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)wglGetProcAddress("glMultTransposeMatrixd");
	if(!ptr_glMultTransposeMatrixd) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.3, function \"glMultTransposeMatrixd\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)wglGetProcAddress("glBlendFuncSeparate");
	if(!ptr_glBlendFuncSeparate) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glBlendFuncSeparate\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)wglGetProcAddress("glMultiDrawArrays");
	if(!ptr_glMultiDrawArrays) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glMultiDrawArrays\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)wglGetProcAddress("glMultiDrawElements");
	if(!ptr_glMultiDrawElements) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glMultiDrawElements\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPointParameterf = (PFNGLPOINTPARAMETERFPROC)wglGetProcAddress("glPointParameterf");
	if(!ptr_glPointParameterf) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glPointParameterf\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)wglGetProcAddress("glPointParameterfv");
	if(!ptr_glPointParameterfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glPointParameterfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPointParameteri = (PFNGLPOINTPARAMETERIPROC)wglGetProcAddress("glPointParameteri");
	if(!ptr_glPointParameteri) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glPointParameteri\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)wglGetProcAddress("glPointParameteriv");
	if(!ptr_glPointParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glPointParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFogCoordf = (PFNGLFOGCOORDFPROC)wglGetProcAddress("glFogCoordf");
	if(!ptr_glFogCoordf) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glFogCoordf\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFogCoordfv = (PFNGLFOGCOORDFVPROC)wglGetProcAddress("glFogCoordfv");
	if(!ptr_glFogCoordfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glFogCoordfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFogCoordd = (PFNGLFOGCOORDDPROC)wglGetProcAddress("glFogCoordd");
	if(!ptr_glFogCoordd) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glFogCoordd\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFogCoorddv = (PFNGLFOGCOORDDVPROC)wglGetProcAddress("glFogCoorddv");
	if(!ptr_glFogCoorddv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glFogCoorddv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)wglGetProcAddress("glFogCoordPointer");
	if(!ptr_glFogCoordPointer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glFogCoordPointer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)wglGetProcAddress("glSecondaryColor3b");
	if(!ptr_glSecondaryColor3b) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3b\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)wglGetProcAddress("glSecondaryColor3bv");
	if(!ptr_glSecondaryColor3bv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3bv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)wglGetProcAddress("glSecondaryColor3d");
	if(!ptr_glSecondaryColor3d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)wglGetProcAddress("glSecondaryColor3dv");
	if(!ptr_glSecondaryColor3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)wglGetProcAddress("glSecondaryColor3f");
	if(!ptr_glSecondaryColor3f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)wglGetProcAddress("glSecondaryColor3fv");
	if(!ptr_glSecondaryColor3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)wglGetProcAddress("glSecondaryColor3i");
	if(!ptr_glSecondaryColor3i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)wglGetProcAddress("glSecondaryColor3iv");
	if(!ptr_glSecondaryColor3iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)wglGetProcAddress("glSecondaryColor3s");
	if(!ptr_glSecondaryColor3s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)wglGetProcAddress("glSecondaryColor3sv");
	if(!ptr_glSecondaryColor3sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)wglGetProcAddress("glSecondaryColor3ub");
	if(!ptr_glSecondaryColor3ub) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3ub\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)wglGetProcAddress("glSecondaryColor3ubv");
	if(!ptr_glSecondaryColor3ubv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3ubv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)wglGetProcAddress("glSecondaryColor3ui");
	if(!ptr_glSecondaryColor3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)wglGetProcAddress("glSecondaryColor3uiv");
	if(!ptr_glSecondaryColor3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)wglGetProcAddress("glSecondaryColor3us");
	if(!ptr_glSecondaryColor3us) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3us\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)wglGetProcAddress("glSecondaryColor3usv");
	if(!ptr_glSecondaryColor3usv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColor3usv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)wglGetProcAddress("glSecondaryColorPointer");
	if(!ptr_glSecondaryColorPointer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glSecondaryColorPointer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos2d = (PFNGLWINDOWPOS2DPROC)wglGetProcAddress("glWindowPos2d");
	if(!ptr_glWindowPos2d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos2d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)wglGetProcAddress("glWindowPos2dv");
	if(!ptr_glWindowPos2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos2f = (PFNGLWINDOWPOS2FPROC)wglGetProcAddress("glWindowPos2f");
	if(!ptr_glWindowPos2f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos2f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)wglGetProcAddress("glWindowPos2fv");
	if(!ptr_glWindowPos2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos2i = (PFNGLWINDOWPOS2IPROC)wglGetProcAddress("glWindowPos2i");
	if(!ptr_glWindowPos2i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos2i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)wglGetProcAddress("glWindowPos2iv");
	if(!ptr_glWindowPos2iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos2iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos2s = (PFNGLWINDOWPOS2SPROC)wglGetProcAddress("glWindowPos2s");
	if(!ptr_glWindowPos2s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos2s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)wglGetProcAddress("glWindowPos2sv");
	if(!ptr_glWindowPos2sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos2sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos3d = (PFNGLWINDOWPOS3DPROC)wglGetProcAddress("glWindowPos3d");
	if(!ptr_glWindowPos3d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos3d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)wglGetProcAddress("glWindowPos3dv");
	if(!ptr_glWindowPos3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos3f = (PFNGLWINDOWPOS3FPROC)wglGetProcAddress("glWindowPos3f");
	if(!ptr_glWindowPos3f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos3f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)wglGetProcAddress("glWindowPos3fv");
	if(!ptr_glWindowPos3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos3i = (PFNGLWINDOWPOS3IPROC)wglGetProcAddress("glWindowPos3i");
	if(!ptr_glWindowPos3i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos3i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)wglGetProcAddress("glWindowPos3iv");
	if(!ptr_glWindowPos3iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos3iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos3s = (PFNGLWINDOWPOS3SPROC)wglGetProcAddress("glWindowPos3s");
	if(!ptr_glWindowPos3s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos3s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)wglGetProcAddress("glWindowPos3sv");
	if(!ptr_glWindowPos3sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glWindowPos3sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlendColor = (PFNGLBLENDCOLORPROC)wglGetProcAddress("glBlendColor");
	if(!ptr_glBlendColor) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glBlendColor\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlendEquation = (PFNGLBLENDEQUATIONPROC)wglGetProcAddress("glBlendEquation");
	if(!ptr_glBlendEquation) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.4, function \"glBlendEquation\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenQueries = (PFNGLGENQUERIESPROC)wglGetProcAddress("glGenQueries");
	if(!ptr_glGenQueries) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glGenQueries\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteQueries = (PFNGLDELETEQUERIESPROC)wglGetProcAddress("glDeleteQueries");
	if(!ptr_glDeleteQueries) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glDeleteQueries\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsQuery = (PFNGLISQUERYPROC)wglGetProcAddress("glIsQuery");
	if(!ptr_glIsQuery) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glIsQuery\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBeginQuery = (PFNGLBEGINQUERYPROC)wglGetProcAddress("glBeginQuery");
	if(!ptr_glBeginQuery) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glBeginQuery\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glEndQuery = (PFNGLENDQUERYPROC)wglGetProcAddress("glEndQuery");
	if(!ptr_glEndQuery) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glEndQuery\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryiv = (PFNGLGETQUERYIVPROC)wglGetProcAddress("glGetQueryiv");
	if(!ptr_glGetQueryiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glGetQueryiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)wglGetProcAddress("glGetQueryObjectiv");
	if(!ptr_glGetQueryObjectiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glGetQueryObjectiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)wglGetProcAddress("glGetQueryObjectuiv");
	if(!ptr_glGetQueryObjectuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glGetQueryObjectuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	if(!ptr_glBindBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glBindBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
	if(!ptr_glDeleteBuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glDeleteBuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	if(!ptr_glGenBuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glGenBuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsBuffer = (PFNGLISBUFFERPROC)wglGetProcAddress("glIsBuffer");
	if(!ptr_glIsBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glIsBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	if(!ptr_glBufferData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glBufferData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
	if(!ptr_glBufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glBufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)wglGetProcAddress("glGetBufferSubData");
	if(!ptr_glGetBufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glGetBufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMapBuffer = (PFNGLMAPBUFFERPROC)wglGetProcAddress("glMapBuffer");
	if(!ptr_glMapBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glMapBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)wglGetProcAddress("glUnmapBuffer");
	if(!ptr_glUnmapBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glUnmapBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetBufferParameteriv");
	if(!ptr_glGetBufferParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glGetBufferParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)wglGetProcAddress("glGetBufferPointerv");
	if(!ptr_glGetBufferPointerv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 1.5, function \"glGetBufferPointerv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)wglGetProcAddress("glBlendEquationSeparate");
	if(!ptr_glBlendEquationSeparate) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glBlendEquationSeparate\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawBuffers = (PFNGLDRAWBUFFERSPROC)wglGetProcAddress("glDrawBuffers");
	if(!ptr_glDrawBuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glDrawBuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)wglGetProcAddress("glStencilOpSeparate");
	if(!ptr_glStencilOpSeparate) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glStencilOpSeparate\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)wglGetProcAddress("glStencilFuncSeparate");
	if(!ptr_glStencilFuncSeparate) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glStencilFuncSeparate\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)wglGetProcAddress("glStencilMaskSeparate");
	if(!ptr_glStencilMaskSeparate) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glStencilMaskSeparate\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	if(!ptr_glAttachShader) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glAttachShader\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
	if(!ptr_glBindAttribLocation) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glBindAttribLocation\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	if(!ptr_glCompileShader) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glCompileShader\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	if(!ptr_glCreateProgram) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glCreateProgram\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	if(!ptr_glCreateShader) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glCreateShader\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
	if(!ptr_glDeleteProgram) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glDeleteProgram\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
	if(!ptr_glDeleteShader) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glDeleteShader\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
	if(!ptr_glDetachShader) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glDetachShader\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glDisableVertexAttribArray");
	if(!ptr_glDisableVertexAttribArray) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glDisableVertexAttribArray\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
	if(!ptr_glEnableVertexAttribArray) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glEnableVertexAttribArray\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)wglGetProcAddress("glGetActiveAttrib");
	if(!ptr_glGetActiveAttrib) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetActiveAttrib\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)wglGetProcAddress("glGetActiveUniform");
	if(!ptr_glGetActiveUniform) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetActiveUniform\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)wglGetProcAddress("glGetAttachedShaders");
	if(!ptr_glGetAttachedShaders) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetAttachedShaders\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
	if(!ptr_glGetAttribLocation) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetAttribLocation\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	if(!ptr_glGetProgramiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetProgramiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
	if(!ptr_glGetProgramInfoLog) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetProgramInfoLog\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	if(!ptr_glGetShaderiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetShaderiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	if(!ptr_glGetShaderInfoLog) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetShaderInfoLog\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)wglGetProcAddress("glGetShaderSource");
	if(!ptr_glGetShaderSource) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetShaderSource\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	if(!ptr_glGetUniformLocation) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetUniformLocation\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetUniformfv = (PFNGLGETUNIFORMFVPROC)wglGetProcAddress("glGetUniformfv");
	if(!ptr_glGetUniformfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetUniformfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetUniformiv = (PFNGLGETUNIFORMIVPROC)wglGetProcAddress("glGetUniformiv");
	if(!ptr_glGetUniformiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetUniformiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)wglGetProcAddress("glGetVertexAttribdv");
	if(!ptr_glGetVertexAttribdv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetVertexAttribdv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)wglGetProcAddress("glGetVertexAttribfv");
	if(!ptr_glGetVertexAttribfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetVertexAttribfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)wglGetProcAddress("glGetVertexAttribiv");
	if(!ptr_glGetVertexAttribiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetVertexAttribiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)wglGetProcAddress("glGetVertexAttribPointerv");
	if(!ptr_glGetVertexAttribPointerv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glGetVertexAttribPointerv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsProgram = (PFNGLISPROGRAMPROC)wglGetProcAddress("glIsProgram");
	if(!ptr_glIsProgram) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glIsProgram\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsShader = (PFNGLISSHADERPROC)wglGetProcAddress("glIsShader");
	if(!ptr_glIsShader) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glIsShader\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	if(!ptr_glLinkProgram) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glLinkProgram\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	if(!ptr_glShaderSource) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glShaderSource\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	if(!ptr_glUseProgram) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUseProgram\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
	if(!ptr_glUniform1f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform1f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform2f = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");
	if(!ptr_glUniform2f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform2f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform3f = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
	if(!ptr_glUniform3f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform3f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform4f = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
	if(!ptr_glUniform4f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform4f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	if(!ptr_glUniform1i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform1i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform2i = (PFNGLUNIFORM2IPROC)wglGetProcAddress("glUniform2i");
	if(!ptr_glUniform2i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform2i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform3i = (PFNGLUNIFORM3IPROC)wglGetProcAddress("glUniform3i");
	if(!ptr_glUniform3i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform3i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform4i = (PFNGLUNIFORM4IPROC)wglGetProcAddress("glUniform4i");
	if(!ptr_glUniform4i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform4i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform1fv = (PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv");
	if(!ptr_glUniform1fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform1fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform2fv = (PFNGLUNIFORM2FVPROC)wglGetProcAddress("glUniform2fv");
	if(!ptr_glUniform2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
	if(!ptr_glUniform3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
	if(!ptr_glUniform4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform1iv = (PFNGLUNIFORM1IVPROC)wglGetProcAddress("glUniform1iv");
	if(!ptr_glUniform1iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform1iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform2iv = (PFNGLUNIFORM2IVPROC)wglGetProcAddress("glUniform2iv");
	if(!ptr_glUniform2iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform2iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform3iv = (PFNGLUNIFORM3IVPROC)wglGetProcAddress("glUniform3iv");
	if(!ptr_glUniform3iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform3iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform4iv = (PFNGLUNIFORM4IVPROC)wglGetProcAddress("glUniform4iv");
	if(!ptr_glUniform4iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniform4iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)wglGetProcAddress("glUniformMatrix2fv");
	if(!ptr_glUniformMatrix2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniformMatrix2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");
	if(!ptr_glUniformMatrix3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniformMatrix3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
	if(!ptr_glUniformMatrix4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glUniformMatrix4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
	if(!ptr_glValidateProgram) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glValidateProgram\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)wglGetProcAddress("glVertexAttrib1d");
	if(!ptr_glVertexAttrib1d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib1d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)wglGetProcAddress("glVertexAttrib1dv");
	if(!ptr_glVertexAttrib1dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib1dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)wglGetProcAddress("glVertexAttrib1f");
	if(!ptr_glVertexAttrib1f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib1f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)wglGetProcAddress("glVertexAttrib1fv");
	if(!ptr_glVertexAttrib1fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib1fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)wglGetProcAddress("glVertexAttrib1s");
	if(!ptr_glVertexAttrib1s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib1s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)wglGetProcAddress("glVertexAttrib1sv");
	if(!ptr_glVertexAttrib1sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib1sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)wglGetProcAddress("glVertexAttrib2d");
	if(!ptr_glVertexAttrib2d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib2d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)wglGetProcAddress("glVertexAttrib2dv");
	if(!ptr_glVertexAttrib2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)wglGetProcAddress("glVertexAttrib2f");
	if(!ptr_glVertexAttrib2f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib2f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)wglGetProcAddress("glVertexAttrib2fv");
	if(!ptr_glVertexAttrib2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)wglGetProcAddress("glVertexAttrib2s");
	if(!ptr_glVertexAttrib2s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib2s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)wglGetProcAddress("glVertexAttrib2sv");
	if(!ptr_glVertexAttrib2sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib2sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)wglGetProcAddress("glVertexAttrib3d");
	if(!ptr_glVertexAttrib3d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib3d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)wglGetProcAddress("glVertexAttrib3dv");
	if(!ptr_glVertexAttrib3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)wglGetProcAddress("glVertexAttrib3f");
	if(!ptr_glVertexAttrib3f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib3f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)wglGetProcAddress("glVertexAttrib3fv");
	if(!ptr_glVertexAttrib3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)wglGetProcAddress("glVertexAttrib3s");
	if(!ptr_glVertexAttrib3s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib3s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)wglGetProcAddress("glVertexAttrib3sv");
	if(!ptr_glVertexAttrib3sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib3sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)wglGetProcAddress("glVertexAttrib4Nbv");
	if(!ptr_glVertexAttrib4Nbv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4Nbv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)wglGetProcAddress("glVertexAttrib4Niv");
	if(!ptr_glVertexAttrib4Niv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4Niv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)wglGetProcAddress("glVertexAttrib4Nsv");
	if(!ptr_glVertexAttrib4Nsv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4Nsv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)wglGetProcAddress("glVertexAttrib4Nub");
	if(!ptr_glVertexAttrib4Nub) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4Nub\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)wglGetProcAddress("glVertexAttrib4Nubv");
	if(!ptr_glVertexAttrib4Nubv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4Nubv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)wglGetProcAddress("glVertexAttrib4Nuiv");
	if(!ptr_glVertexAttrib4Nuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4Nuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)wglGetProcAddress("glVertexAttrib4Nusv");
	if(!ptr_glVertexAttrib4Nusv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4Nusv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)wglGetProcAddress("glVertexAttrib4bv");
	if(!ptr_glVertexAttrib4bv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4bv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)wglGetProcAddress("glVertexAttrib4d");
	if(!ptr_glVertexAttrib4d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)wglGetProcAddress("glVertexAttrib4dv");
	if(!ptr_glVertexAttrib4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)wglGetProcAddress("glVertexAttrib4f");
	if(!ptr_glVertexAttrib4f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)wglGetProcAddress("glVertexAttrib4fv");
	if(!ptr_glVertexAttrib4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)wglGetProcAddress("glVertexAttrib4iv");
	if(!ptr_glVertexAttrib4iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)wglGetProcAddress("glVertexAttrib4s");
	if(!ptr_glVertexAttrib4s) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4s\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)wglGetProcAddress("glVertexAttrib4sv");
	if(!ptr_glVertexAttrib4sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)wglGetProcAddress("glVertexAttrib4ubv");
	if(!ptr_glVertexAttrib4ubv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4ubv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)wglGetProcAddress("glVertexAttrib4uiv");
	if(!ptr_glVertexAttrib4uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)wglGetProcAddress("glVertexAttrib4usv");
	if(!ptr_glVertexAttrib4usv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttrib4usv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
	if(!ptr_glVertexAttribPointer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.0, function \"glVertexAttribPointer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)wglGetProcAddress("glUniformMatrix2x3fv");
	if(!ptr_glUniformMatrix2x3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.1, function \"glUniformMatrix2x3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)wglGetProcAddress("glUniformMatrix3x2fv");
	if(!ptr_glUniformMatrix3x2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.1, function \"glUniformMatrix3x2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)wglGetProcAddress("glUniformMatrix2x4fv");
	if(!ptr_glUniformMatrix2x4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.1, function \"glUniformMatrix2x4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)wglGetProcAddress("glUniformMatrix4x2fv");
	if(!ptr_glUniformMatrix4x2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.1, function \"glUniformMatrix4x2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)wglGetProcAddress("glUniformMatrix3x4fv");
	if(!ptr_glUniformMatrix3x4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.1, function \"glUniformMatrix3x4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)wglGetProcAddress("glUniformMatrix4x3fv");
	if(!ptr_glUniformMatrix4x3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 2.1, function \"glUniformMatrix4x3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glColorMaski = (PFNGLCOLORMASKIPROC)wglGetProcAddress("glColorMaski");
	if(!ptr_glColorMaski) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glColorMaski\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)wglGetProcAddress("glGetBooleani_v");
	if(!ptr_glGetBooleani_v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetBooleani_v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)wglGetProcAddress("glGetIntegeri_v");
	if(!ptr_glGetIntegeri_v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetIntegeri_v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glEnablei = (PFNGLENABLEIPROC)wglGetProcAddress("glEnablei");
	if(!ptr_glEnablei) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glEnablei\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDisablei = (PFNGLDISABLEIPROC)wglGetProcAddress("glDisablei");
	if(!ptr_glDisablei) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glDisablei\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsEnabledi = (PFNGLISENABLEDIPROC)wglGetProcAddress("glIsEnabledi");
	if(!ptr_glIsEnabledi) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glIsEnabledi\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)wglGetProcAddress("glBeginTransformFeedback");
	if(!ptr_glBeginTransformFeedback) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glBeginTransformFeedback\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)wglGetProcAddress("glEndTransformFeedback");
	if(!ptr_glEndTransformFeedback) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glEndTransformFeedback\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)wglGetProcAddress("glBindBufferRange");
	if(!ptr_glBindBufferRange) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glBindBufferRange\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)wglGetProcAddress("glBindBufferBase");
	if(!ptr_glBindBufferBase) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glBindBufferBase\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)wglGetProcAddress("glTransformFeedbackVaryings");
	if(!ptr_glTransformFeedbackVaryings) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glTransformFeedbackVaryings\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)wglGetProcAddress("glGetTransformFeedbackVarying");
	if(!ptr_glGetTransformFeedbackVarying) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetTransformFeedbackVarying\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClampColor = (PFNGLCLAMPCOLORPROC)wglGetProcAddress("glClampColor");
	if(!ptr_glClampColor) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glClampColor\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)wglGetProcAddress("glBeginConditionalRender");
	if(!ptr_glBeginConditionalRender) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glBeginConditionalRender\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)wglGetProcAddress("glEndConditionalRender");
	if(!ptr_glEndConditionalRender) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glEndConditionalRender\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)wglGetProcAddress("glVertexAttribIPointer");
	if(!ptr_glVertexAttribIPointer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribIPointer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)wglGetProcAddress("glGetVertexAttribIiv");
	if(!ptr_glGetVertexAttribIiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetVertexAttribIiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)wglGetProcAddress("glGetVertexAttribIuiv");
	if(!ptr_glGetVertexAttribIuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetVertexAttribIuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)wglGetProcAddress("glVertexAttribI1i");
	if(!ptr_glVertexAttribI1i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI1i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)wglGetProcAddress("glVertexAttribI2i");
	if(!ptr_glVertexAttribI2i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI2i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)wglGetProcAddress("glVertexAttribI3i");
	if(!ptr_glVertexAttribI3i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI3i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)wglGetProcAddress("glVertexAttribI4i");
	if(!ptr_glVertexAttribI4i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI4i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)wglGetProcAddress("glVertexAttribI1ui");
	if(!ptr_glVertexAttribI1ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI1ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)wglGetProcAddress("glVertexAttribI2ui");
	if(!ptr_glVertexAttribI2ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI2ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)wglGetProcAddress("glVertexAttribI3ui");
	if(!ptr_glVertexAttribI3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)wglGetProcAddress("glVertexAttribI4ui");
	if(!ptr_glVertexAttribI4ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI4ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)wglGetProcAddress("glVertexAttribI1iv");
	if(!ptr_glVertexAttribI1iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI1iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)wglGetProcAddress("glVertexAttribI2iv");
	if(!ptr_glVertexAttribI2iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI2iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)wglGetProcAddress("glVertexAttribI3iv");
	if(!ptr_glVertexAttribI3iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI3iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)wglGetProcAddress("glVertexAttribI4iv");
	if(!ptr_glVertexAttribI4iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI4iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)wglGetProcAddress("glVertexAttribI1uiv");
	if(!ptr_glVertexAttribI1uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI1uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)wglGetProcAddress("glVertexAttribI2uiv");
	if(!ptr_glVertexAttribI2uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI2uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)wglGetProcAddress("glVertexAttribI3uiv");
	if(!ptr_glVertexAttribI3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)wglGetProcAddress("glVertexAttribI4uiv");
	if(!ptr_glVertexAttribI4uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI4uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)wglGetProcAddress("glVertexAttribI4bv");
	if(!ptr_glVertexAttribI4bv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI4bv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)wglGetProcAddress("glVertexAttribI4sv");
	if(!ptr_glVertexAttribI4sv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI4sv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)wglGetProcAddress("glVertexAttribI4ubv");
	if(!ptr_glVertexAttribI4ubv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI4ubv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)wglGetProcAddress("glVertexAttribI4usv");
	if(!ptr_glVertexAttribI4usv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glVertexAttribI4usv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)wglGetProcAddress("glGetUniformuiv");
	if(!ptr_glGetUniformuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetUniformuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)wglGetProcAddress("glBindFragDataLocation");
	if(!ptr_glBindFragDataLocation) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glBindFragDataLocation\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)wglGetProcAddress("glGetFragDataLocation");
	if(!ptr_glGetFragDataLocation) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetFragDataLocation\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform1ui = (PFNGLUNIFORM1UIPROC)wglGetProcAddress("glUniform1ui");
	if(!ptr_glUniform1ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glUniform1ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform2ui = (PFNGLUNIFORM2UIPROC)wglGetProcAddress("glUniform2ui");
	if(!ptr_glUniform2ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glUniform2ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform3ui = (PFNGLUNIFORM3UIPROC)wglGetProcAddress("glUniform3ui");
	if(!ptr_glUniform3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glUniform3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform4ui = (PFNGLUNIFORM4UIPROC)wglGetProcAddress("glUniform4ui");
	if(!ptr_glUniform4ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glUniform4ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform1uiv = (PFNGLUNIFORM1UIVPROC)wglGetProcAddress("glUniform1uiv");
	if(!ptr_glUniform1uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glUniform1uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform2uiv = (PFNGLUNIFORM2UIVPROC)wglGetProcAddress("glUniform2uiv");
	if(!ptr_glUniform2uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glUniform2uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform3uiv = (PFNGLUNIFORM3UIVPROC)wglGetProcAddress("glUniform3uiv");
	if(!ptr_glUniform3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glUniform3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform4uiv = (PFNGLUNIFORM4UIVPROC)wglGetProcAddress("glUniform4uiv");
	if(!ptr_glUniform4uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glUniform4uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)wglGetProcAddress("glTexParameterIiv");
	if(!ptr_glTexParameterIiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glTexParameterIiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)wglGetProcAddress("glTexParameterIuiv");
	if(!ptr_glTexParameterIuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glTexParameterIuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)wglGetProcAddress("glGetTexParameterIiv");
	if(!ptr_glGetTexParameterIiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetTexParameterIiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)wglGetProcAddress("glGetTexParameterIuiv");
	if(!ptr_glGetTexParameterIuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetTexParameterIuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)wglGetProcAddress("glClearBufferiv");
	if(!ptr_glClearBufferiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glClearBufferiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)wglGetProcAddress("glClearBufferuiv");
	if(!ptr_glClearBufferuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glClearBufferuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)wglGetProcAddress("glClearBufferfv");
	if(!ptr_glClearBufferfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glClearBufferfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)wglGetProcAddress("glClearBufferfi");
	if(!ptr_glClearBufferfi) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glClearBufferfi\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetStringi = (PFNGLGETSTRINGIPROC)wglGetProcAddress("glGetStringi");
	if(!ptr_glGetStringi) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetStringi\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)wglGetProcAddress("glIsRenderbuffer");
	if(!ptr_glIsRenderbuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glIsRenderbuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
	if(!ptr_glBindRenderbuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glBindRenderbuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");
	if(!ptr_glDeleteRenderbuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glDeleteRenderbuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
	if(!ptr_glGenRenderbuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGenRenderbuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
	if(!ptr_glRenderbufferStorage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glRenderbufferStorage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetRenderbufferParameteriv");
	if(!ptr_glGetRenderbufferParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetRenderbufferParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)wglGetProcAddress("glIsFramebuffer");
	if(!ptr_glIsFramebuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glIsFramebuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
	if(!ptr_glBindFramebuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glBindFramebuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
	if(!ptr_glDeleteFramebuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glDeleteFramebuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
	if(!ptr_glGenFramebuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGenFramebuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
	if(!ptr_glCheckFramebufferStatus) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glCheckFramebufferStatus\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)wglGetProcAddress("glFramebufferTexture1D");
	if(!ptr_glFramebufferTexture1D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glFramebufferTexture1D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");
	if(!ptr_glFramebufferTexture2D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glFramebufferTexture2D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)wglGetProcAddress("glFramebufferTexture3D");
	if(!ptr_glFramebufferTexture3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glFramebufferTexture3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
	if(!ptr_glFramebufferRenderbuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glFramebufferRenderbuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferAttachmentParameteriv");
	if(!ptr_glGetFramebufferAttachmentParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGetFramebufferAttachmentParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
	if(!ptr_glGenerateMipmap) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGenerateMipmap\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)wglGetProcAddress("glBlitFramebuffer");
	if(!ptr_glBlitFramebuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glBlitFramebuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glRenderbufferStorageMultisample");
	if(!ptr_glRenderbufferStorageMultisample) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glRenderbufferStorageMultisample\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)wglGetProcAddress("glFramebufferTextureLayer");
	if(!ptr_glFramebufferTextureLayer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glFramebufferTextureLayer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)wglGetProcAddress("glMapBufferRange");
	if(!ptr_glMapBufferRange) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glMapBufferRange\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)wglGetProcAddress("glFlushMappedBufferRange");
	if(!ptr_glFlushMappedBufferRange) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glFlushMappedBufferRange\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
	if(!ptr_glBindVertexArray) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glBindVertexArray\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
	if(!ptr_glDeleteVertexArrays) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glDeleteVertexArrays\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
	if(!ptr_glGenVertexArrays) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glGenVertexArrays\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsVertexArray = (PFNGLISVERTEXARRAYPROC)wglGetProcAddress("glIsVertexArray");
	if(!ptr_glIsVertexArray) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.0, function \"glIsVertexArray\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)wglGetProcAddress("glDrawArraysInstanced");
	if(!ptr_glDrawArraysInstanced) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glDrawArraysInstanced\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)wglGetProcAddress("glDrawElementsInstanced");
	if(!ptr_glDrawElementsInstanced) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glDrawElementsInstanced\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexBuffer = (PFNGLTEXBUFFERPROC)wglGetProcAddress("glTexBuffer");
	if(!ptr_glTexBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glTexBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)wglGetProcAddress("glPrimitiveRestartIndex");
	if(!ptr_glPrimitiveRestartIndex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glPrimitiveRestartIndex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)wglGetProcAddress("glCopyBufferSubData");
	if(!ptr_glCopyBufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glCopyBufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)wglGetProcAddress("glGetUniformIndices");
	if(!ptr_glGetUniformIndices) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glGetUniformIndices\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)wglGetProcAddress("glGetActiveUniformsiv");
	if(!ptr_glGetActiveUniformsiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glGetActiveUniformsiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)wglGetProcAddress("glGetActiveUniformName");
	if(!ptr_glGetActiveUniformName) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glGetActiveUniformName\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)wglGetProcAddress("glGetUniformBlockIndex");
	if(!ptr_glGetUniformBlockIndex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glGetUniformBlockIndex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)wglGetProcAddress("glGetActiveUniformBlockiv");
	if(!ptr_glGetActiveUniformBlockiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glGetActiveUniformBlockiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)wglGetProcAddress("glGetActiveUniformBlockName");
	if(!ptr_glGetActiveUniformBlockName) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glGetActiveUniformBlockName\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)wglGetProcAddress("glUniformBlockBinding");
	if(!ptr_glUniformBlockBinding) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.1, function \"glUniformBlockBinding\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawElementsBaseVertex");
	if(!ptr_glDrawElementsBaseVertex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glDrawElementsBaseVertex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawRangeElementsBaseVertex");
	if(!ptr_glDrawRangeElementsBaseVertex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glDrawRangeElementsBaseVertex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)wglGetProcAddress("glDrawElementsInstancedBaseVertex");
	if(!ptr_glDrawElementsInstancedBaseVertex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glDrawElementsInstancedBaseVertex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glMultiDrawElementsBaseVertex");
	if(!ptr_glMultiDrawElementsBaseVertex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glMultiDrawElementsBaseVertex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)wglGetProcAddress("glProvokingVertex");
	if(!ptr_glProvokingVertex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glProvokingVertex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFenceSync = (PFNGLFENCESYNCPROC)wglGetProcAddress("glFenceSync");
	if(!ptr_glFenceSync) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glFenceSync\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsSync = (PFNGLISSYNCPROC)wglGetProcAddress("glIsSync");
	if(!ptr_glIsSync) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glIsSync\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteSync = (PFNGLDELETESYNCPROC)wglGetProcAddress("glDeleteSync");
	if(!ptr_glDeleteSync) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glDeleteSync\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)wglGetProcAddress("glClientWaitSync");
	if(!ptr_glClientWaitSync) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glClientWaitSync\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glWaitSync = (PFNGLWAITSYNCPROC)wglGetProcAddress("glWaitSync");
	if(!ptr_glWaitSync) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glWaitSync\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetInteger64v = (PFNGLGETINTEGER64VPROC)wglGetProcAddress("glGetInteger64v");
	if(!ptr_glGetInteger64v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glGetInteger64v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetSynciv = (PFNGLGETSYNCIVPROC)wglGetProcAddress("glGetSynciv");
	if(!ptr_glGetSynciv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glGetSynciv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)wglGetProcAddress("glGetInteger64i_v");
	if(!ptr_glGetInteger64i_v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glGetInteger64i_v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)wglGetProcAddress("glGetBufferParameteri64v");
	if(!ptr_glGetBufferParameteri64v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glGetBufferParameteri64v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glFramebufferTexture");
	if(!ptr_glFramebufferTexture) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glFramebufferTexture\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexImage2DMultisample");
	if(!ptr_glTexImage2DMultisample) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glTexImage2DMultisample\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTexImage3DMultisample");
	if(!ptr_glTexImage3DMultisample) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glTexImage3DMultisample\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)wglGetProcAddress("glGetMultisamplefv");
	if(!ptr_glGetMultisamplefv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glGetMultisamplefv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSampleMaski = (PFNGLSAMPLEMASKIPROC)wglGetProcAddress("glSampleMaski");
	if(!ptr_glSampleMaski) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.2, function \"glSampleMaski\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)wglGetProcAddress("glBindFragDataLocationIndexed");
	if(!ptr_glBindFragDataLocationIndexed) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glBindFragDataLocationIndexed\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)wglGetProcAddress("glGetFragDataIndex");
	if(!ptr_glGetFragDataIndex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glGetFragDataIndex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenSamplers = (PFNGLGENSAMPLERSPROC)wglGetProcAddress("glGenSamplers");
	if(!ptr_glGenSamplers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glGenSamplers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)wglGetProcAddress("glDeleteSamplers");
	if(!ptr_glDeleteSamplers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glDeleteSamplers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsSampler = (PFNGLISSAMPLERPROC)wglGetProcAddress("glIsSampler");
	if(!ptr_glIsSampler) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glIsSampler\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindSampler = (PFNGLBINDSAMPLERPROC)wglGetProcAddress("glBindSampler");
	if(!ptr_glBindSampler) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glBindSampler\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)wglGetProcAddress("glSamplerParameteri");
	if(!ptr_glSamplerParameteri) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glSamplerParameteri\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)wglGetProcAddress("glSamplerParameteriv");
	if(!ptr_glSamplerParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glSamplerParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)wglGetProcAddress("glSamplerParameterf");
	if(!ptr_glSamplerParameterf) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glSamplerParameterf\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)wglGetProcAddress("glSamplerParameterfv");
	if(!ptr_glSamplerParameterfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glSamplerParameterfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glSamplerParameterIiv");
	if(!ptr_glSamplerParameterIiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glSamplerParameterIiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glSamplerParameterIuiv");
	if(!ptr_glSamplerParameterIuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glSamplerParameterIuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)wglGetProcAddress("glGetSamplerParameteriv");
	if(!ptr_glGetSamplerParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glGetSamplerParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glGetSamplerParameterIiv");
	if(!ptr_glGetSamplerParameterIiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glGetSamplerParameterIiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)wglGetProcAddress("glGetSamplerParameterfv");
	if(!ptr_glGetSamplerParameterfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glGetSamplerParameterfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glGetSamplerParameterIuiv");
	if(!ptr_glGetSamplerParameterIuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glGetSamplerParameterIuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glQueryCounter = (PFNGLQUERYCOUNTERPROC)wglGetProcAddress("glQueryCounter");
	if(!ptr_glQueryCounter) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glQueryCounter\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)wglGetProcAddress("glGetQueryObjecti64v");
	if(!ptr_glGetQueryObjecti64v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glGetQueryObjecti64v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)wglGetProcAddress("glGetQueryObjectui64v");
	if(!ptr_glGetQueryObjectui64v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glGetQueryObjectui64v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)wglGetProcAddress("glVertexAttribDivisor");
	if(!ptr_glVertexAttribDivisor) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexAttribDivisor\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)wglGetProcAddress("glVertexAttribP1ui");
	if(!ptr_glVertexAttribP1ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexAttribP1ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)wglGetProcAddress("glVertexAttribP1uiv");
	if(!ptr_glVertexAttribP1uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexAttribP1uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)wglGetProcAddress("glVertexAttribP2ui");
	if(!ptr_glVertexAttribP2ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexAttribP2ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)wglGetProcAddress("glVertexAttribP2uiv");
	if(!ptr_glVertexAttribP2uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexAttribP2uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)wglGetProcAddress("glVertexAttribP3ui");
	if(!ptr_glVertexAttribP3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexAttribP3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)wglGetProcAddress("glVertexAttribP3uiv");
	if(!ptr_glVertexAttribP3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexAttribP3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)wglGetProcAddress("glVertexAttribP4ui");
	if(!ptr_glVertexAttribP4ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexAttribP4ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)wglGetProcAddress("glVertexAttribP4uiv");
	if(!ptr_glVertexAttribP4uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexAttribP4uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexP2ui = (PFNGLVERTEXP2UIPROC)wglGetProcAddress("glVertexP2ui");
	if(!ptr_glVertexP2ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexP2ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)wglGetProcAddress("glVertexP2uiv");
	if(!ptr_glVertexP2uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexP2uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexP3ui = (PFNGLVERTEXP3UIPROC)wglGetProcAddress("glVertexP3ui");
	if(!ptr_glVertexP3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexP3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)wglGetProcAddress("glVertexP3uiv");
	if(!ptr_glVertexP3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexP3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexP4ui = (PFNGLVERTEXP4UIPROC)wglGetProcAddress("glVertexP4ui");
	if(!ptr_glVertexP4ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexP4ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)wglGetProcAddress("glVertexP4uiv");
	if(!ptr_glVertexP4uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glVertexP4uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)wglGetProcAddress("glTexCoordP1ui");
	if(!ptr_glTexCoordP1ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glTexCoordP1ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)wglGetProcAddress("glTexCoordP1uiv");
	if(!ptr_glTexCoordP1uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glTexCoordP1uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)wglGetProcAddress("glTexCoordP2ui");
	if(!ptr_glTexCoordP2ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glTexCoordP2ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)wglGetProcAddress("glTexCoordP2uiv");
	if(!ptr_glTexCoordP2uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glTexCoordP2uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)wglGetProcAddress("glTexCoordP3ui");
	if(!ptr_glTexCoordP3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glTexCoordP3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)wglGetProcAddress("glTexCoordP3uiv");
	if(!ptr_glTexCoordP3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glTexCoordP3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)wglGetProcAddress("glTexCoordP4ui");
	if(!ptr_glTexCoordP4ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glTexCoordP4ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)wglGetProcAddress("glTexCoordP4uiv");
	if(!ptr_glTexCoordP4uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glTexCoordP4uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)wglGetProcAddress("glMultiTexCoordP1ui");
	if(!ptr_glMultiTexCoordP1ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glMultiTexCoordP1ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)wglGetProcAddress("glMultiTexCoordP1uiv");
	if(!ptr_glMultiTexCoordP1uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glMultiTexCoordP1uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)wglGetProcAddress("glMultiTexCoordP2ui");
	if(!ptr_glMultiTexCoordP2ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glMultiTexCoordP2ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)wglGetProcAddress("glMultiTexCoordP2uiv");
	if(!ptr_glMultiTexCoordP2uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glMultiTexCoordP2uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)wglGetProcAddress("glMultiTexCoordP3ui");
	if(!ptr_glMultiTexCoordP3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glMultiTexCoordP3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)wglGetProcAddress("glMultiTexCoordP3uiv");
	if(!ptr_glMultiTexCoordP3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glMultiTexCoordP3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)wglGetProcAddress("glMultiTexCoordP4ui");
	if(!ptr_glMultiTexCoordP4ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glMultiTexCoordP4ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)wglGetProcAddress("glMultiTexCoordP4uiv");
	if(!ptr_glMultiTexCoordP4uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glMultiTexCoordP4uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNormalP3ui = (PFNGLNORMALP3UIPROC)wglGetProcAddress("glNormalP3ui");
	if(!ptr_glNormalP3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glNormalP3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNormalP3uiv = (PFNGLNORMALP3UIVPROC)wglGetProcAddress("glNormalP3uiv");
	if(!ptr_glNormalP3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glNormalP3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glColorP3ui = (PFNGLCOLORP3UIPROC)wglGetProcAddress("glColorP3ui");
	if(!ptr_glColorP3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glColorP3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glColorP3uiv = (PFNGLCOLORP3UIVPROC)wglGetProcAddress("glColorP3uiv");
	if(!ptr_glColorP3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glColorP3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glColorP4ui = (PFNGLCOLORP4UIPROC)wglGetProcAddress("glColorP4ui");
	if(!ptr_glColorP4ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glColorP4ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glColorP4uiv = (PFNGLCOLORP4UIVPROC)wglGetProcAddress("glColorP4uiv");
	if(!ptr_glColorP4uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glColorP4uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)wglGetProcAddress("glSecondaryColorP3ui");
	if(!ptr_glSecondaryColorP3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glSecondaryColorP3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)wglGetProcAddress("glSecondaryColorP3uiv");
	if(!ptr_glSecondaryColorP3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 3.3, function \"glSecondaryColorP3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)wglGetProcAddress("glMinSampleShading");
	if(!ptr_glMinSampleShading) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glMinSampleShading\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)wglGetProcAddress("glBlendEquationi");
	if(!ptr_glBlendEquationi) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glBlendEquationi\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)wglGetProcAddress("glBlendEquationSeparatei");
	if(!ptr_glBlendEquationSeparatei) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glBlendEquationSeparatei\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlendFunci = (PFNGLBLENDFUNCIPROC)wglGetProcAddress("glBlendFunci");
	if(!ptr_glBlendFunci) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glBlendFunci\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)wglGetProcAddress("glBlendFuncSeparatei");
	if(!ptr_glBlendFuncSeparatei) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glBlendFuncSeparatei\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)wglGetProcAddress("glDrawArraysIndirect");
	if(!ptr_glDrawArraysIndirect) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glDrawArraysIndirect\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)wglGetProcAddress("glDrawElementsIndirect");
	if(!ptr_glDrawElementsIndirect) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glDrawElementsIndirect\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform1d = (PFNGLUNIFORM1DPROC)wglGetProcAddress("glUniform1d");
	if(!ptr_glUniform1d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniform1d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform2d = (PFNGLUNIFORM2DPROC)wglGetProcAddress("glUniform2d");
	if(!ptr_glUniform2d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniform2d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform3d = (PFNGLUNIFORM3DPROC)wglGetProcAddress("glUniform3d");
	if(!ptr_glUniform3d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniform3d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform4d = (PFNGLUNIFORM4DPROC)wglGetProcAddress("glUniform4d");
	if(!ptr_glUniform4d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniform4d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform1dv = (PFNGLUNIFORM1DVPROC)wglGetProcAddress("glUniform1dv");
	if(!ptr_glUniform1dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniform1dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform2dv = (PFNGLUNIFORM2DVPROC)wglGetProcAddress("glUniform2dv");
	if(!ptr_glUniform2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniform2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform3dv = (PFNGLUNIFORM3DVPROC)wglGetProcAddress("glUniform3dv");
	if(!ptr_glUniform3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniform3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniform4dv = (PFNGLUNIFORM4DVPROC)wglGetProcAddress("glUniform4dv");
	if(!ptr_glUniform4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniform4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)wglGetProcAddress("glUniformMatrix2dv");
	if(!ptr_glUniformMatrix2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformMatrix2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)wglGetProcAddress("glUniformMatrix3dv");
	if(!ptr_glUniformMatrix3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformMatrix3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)wglGetProcAddress("glUniformMatrix4dv");
	if(!ptr_glUniformMatrix4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformMatrix4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)wglGetProcAddress("glUniformMatrix2x3dv");
	if(!ptr_glUniformMatrix2x3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformMatrix2x3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)wglGetProcAddress("glUniformMatrix2x4dv");
	if(!ptr_glUniformMatrix2x4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformMatrix2x4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)wglGetProcAddress("glUniformMatrix3x2dv");
	if(!ptr_glUniformMatrix3x2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformMatrix3x2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)wglGetProcAddress("glUniformMatrix3x4dv");
	if(!ptr_glUniformMatrix3x4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformMatrix3x4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)wglGetProcAddress("glUniformMatrix4x2dv");
	if(!ptr_glUniformMatrix4x2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformMatrix4x2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)wglGetProcAddress("glUniformMatrix4x3dv");
	if(!ptr_glUniformMatrix4x3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformMatrix4x3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetUniformdv = (PFNGLGETUNIFORMDVPROC)wglGetProcAddress("glGetUniformdv");
	if(!ptr_glGetUniformdv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGetUniformdv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)wglGetProcAddress("glGetSubroutineUniformLocation");
	if(!ptr_glGetSubroutineUniformLocation) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGetSubroutineUniformLocation\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)wglGetProcAddress("glGetSubroutineIndex");
	if(!ptr_glGetSubroutineIndex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGetSubroutineIndex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)wglGetProcAddress("glGetActiveSubroutineUniformiv");
	if(!ptr_glGetActiveSubroutineUniformiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGetActiveSubroutineUniformiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)wglGetProcAddress("glGetActiveSubroutineUniformName");
	if(!ptr_glGetActiveSubroutineUniformName) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGetActiveSubroutineUniformName\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)wglGetProcAddress("glGetActiveSubroutineName");
	if(!ptr_glGetActiveSubroutineName) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGetActiveSubroutineName\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)wglGetProcAddress("glUniformSubroutinesuiv");
	if(!ptr_glUniformSubroutinesuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glUniformSubroutinesuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)wglGetProcAddress("glGetUniformSubroutineuiv");
	if(!ptr_glGetUniformSubroutineuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGetUniformSubroutineuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)wglGetProcAddress("glGetProgramStageiv");
	if(!ptr_glGetProgramStageiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGetProgramStageiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)wglGetProcAddress("glPatchParameteri");
	if(!ptr_glPatchParameteri) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glPatchParameteri\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)wglGetProcAddress("glPatchParameterfv");
	if(!ptr_glPatchParameterfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glPatchParameterfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)wglGetProcAddress("glBindTransformFeedback");
	if(!ptr_glBindTransformFeedback) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glBindTransformFeedback\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)wglGetProcAddress("glDeleteTransformFeedbacks");
	if(!ptr_glDeleteTransformFeedbacks) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glDeleteTransformFeedbacks\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)wglGetProcAddress("glGenTransformFeedbacks");
	if(!ptr_glGenTransformFeedbacks) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGenTransformFeedbacks\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)wglGetProcAddress("glIsTransformFeedback");
	if(!ptr_glIsTransformFeedback) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glIsTransformFeedback\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)wglGetProcAddress("glPauseTransformFeedback");
	if(!ptr_glPauseTransformFeedback) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glPauseTransformFeedback\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)wglGetProcAddress("glResumeTransformFeedback");
	if(!ptr_glResumeTransformFeedback) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glResumeTransformFeedback\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)wglGetProcAddress("glDrawTransformFeedback");
	if(!ptr_glDrawTransformFeedback) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glDrawTransformFeedback\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)wglGetProcAddress("glDrawTransformFeedbackStream");
	if(!ptr_glDrawTransformFeedbackStream) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glDrawTransformFeedbackStream\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)wglGetProcAddress("glBeginQueryIndexed");
	if(!ptr_glBeginQueryIndexed) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glBeginQueryIndexed\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)wglGetProcAddress("glEndQueryIndexed");
	if(!ptr_glEndQueryIndexed) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glEndQueryIndexed\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)wglGetProcAddress("glGetQueryIndexediv");
	if(!ptr_glGetQueryIndexediv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.0, function \"glGetQueryIndexediv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)wglGetProcAddress("glReleaseShaderCompiler");
	if(!ptr_glReleaseShaderCompiler) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glReleaseShaderCompiler\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glShaderBinary = (PFNGLSHADERBINARYPROC)wglGetProcAddress("glShaderBinary");
	if(!ptr_glShaderBinary) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glShaderBinary\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)wglGetProcAddress("glGetShaderPrecisionFormat");
	if(!ptr_glGetShaderPrecisionFormat) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glGetShaderPrecisionFormat\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDepthRangef = (PFNGLDEPTHRANGEFPROC)wglGetProcAddress("glDepthRangef");
	if(!ptr_glDepthRangef) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glDepthRangef\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearDepthf = (PFNGLCLEARDEPTHFPROC)wglGetProcAddress("glClearDepthf");
	if(!ptr_glClearDepthf) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glClearDepthf\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)wglGetProcAddress("glGetProgramBinary");
	if(!ptr_glGetProgramBinary) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glGetProgramBinary\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramBinary = (PFNGLPROGRAMBINARYPROC)wglGetProcAddress("glProgramBinary");
	if(!ptr_glProgramBinary) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramBinary\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)wglGetProcAddress("glProgramParameteri");
	if(!ptr_glProgramParameteri) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramParameteri\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)wglGetProcAddress("glUseProgramStages");
	if(!ptr_glUseProgramStages) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glUseProgramStages\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)wglGetProcAddress("glActiveShaderProgram");
	if(!ptr_glActiveShaderProgram) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glActiveShaderProgram\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)wglGetProcAddress("glCreateShaderProgramv");
	if(!ptr_glCreateShaderProgramv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glCreateShaderProgramv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)wglGetProcAddress("glBindProgramPipeline");
	if(!ptr_glBindProgramPipeline) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glBindProgramPipeline\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)wglGetProcAddress("glDeleteProgramPipelines");
	if(!ptr_glDeleteProgramPipelines) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glDeleteProgramPipelines\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)wglGetProcAddress("glGenProgramPipelines");
	if(!ptr_glGenProgramPipelines) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glGenProgramPipelines\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)wglGetProcAddress("glIsProgramPipeline");
	if(!ptr_glIsProgramPipeline) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glIsProgramPipeline\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)wglGetProcAddress("glGetProgramPipelineiv");
	if(!ptr_glGetProgramPipelineiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glGetProgramPipelineiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)wglGetProcAddress("glProgramUniform1i");
	if(!ptr_glProgramUniform1i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform1i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)wglGetProcAddress("glProgramUniform1iv");
	if(!ptr_glProgramUniform1iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform1iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)wglGetProcAddress("glProgramUniform1f");
	if(!ptr_glProgramUniform1f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform1f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)wglGetProcAddress("glProgramUniform1fv");
	if(!ptr_glProgramUniform1fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform1fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)wglGetProcAddress("glProgramUniform1d");
	if(!ptr_glProgramUniform1d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform1d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)wglGetProcAddress("glProgramUniform1dv");
	if(!ptr_glProgramUniform1dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform1dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)wglGetProcAddress("glProgramUniform1ui");
	if(!ptr_glProgramUniform1ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform1ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)wglGetProcAddress("glProgramUniform1uiv");
	if(!ptr_glProgramUniform1uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform1uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)wglGetProcAddress("glProgramUniform2i");
	if(!ptr_glProgramUniform2i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform2i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)wglGetProcAddress("glProgramUniform2iv");
	if(!ptr_glProgramUniform2iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform2iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)wglGetProcAddress("glProgramUniform2f");
	if(!ptr_glProgramUniform2f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform2f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)wglGetProcAddress("glProgramUniform2fv");
	if(!ptr_glProgramUniform2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)wglGetProcAddress("glProgramUniform2d");
	if(!ptr_glProgramUniform2d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform2d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)wglGetProcAddress("glProgramUniform2dv");
	if(!ptr_glProgramUniform2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)wglGetProcAddress("glProgramUniform2ui");
	if(!ptr_glProgramUniform2ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform2ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)wglGetProcAddress("glProgramUniform2uiv");
	if(!ptr_glProgramUniform2uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform2uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)wglGetProcAddress("glProgramUniform3i");
	if(!ptr_glProgramUniform3i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform3i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)wglGetProcAddress("glProgramUniform3iv");
	if(!ptr_glProgramUniform3iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform3iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)wglGetProcAddress("glProgramUniform3f");
	if(!ptr_glProgramUniform3f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform3f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)wglGetProcAddress("glProgramUniform3fv");
	if(!ptr_glProgramUniform3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)wglGetProcAddress("glProgramUniform3d");
	if(!ptr_glProgramUniform3d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform3d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)wglGetProcAddress("glProgramUniform3dv");
	if(!ptr_glProgramUniform3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)wglGetProcAddress("glProgramUniform3ui");
	if(!ptr_glProgramUniform3ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform3ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)wglGetProcAddress("glProgramUniform3uiv");
	if(!ptr_glProgramUniform3uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform3uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)wglGetProcAddress("glProgramUniform4i");
	if(!ptr_glProgramUniform4i) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform4i\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)wglGetProcAddress("glProgramUniform4iv");
	if(!ptr_glProgramUniform4iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform4iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)wglGetProcAddress("glProgramUniform4f");
	if(!ptr_glProgramUniform4f) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform4f\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)wglGetProcAddress("glProgramUniform4fv");
	if(!ptr_glProgramUniform4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)wglGetProcAddress("glProgramUniform4d");
	if(!ptr_glProgramUniform4d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform4d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)wglGetProcAddress("glProgramUniform4dv");
	if(!ptr_glProgramUniform4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)wglGetProcAddress("glProgramUniform4ui");
	if(!ptr_glProgramUniform4ui) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform4ui\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)wglGetProcAddress("glProgramUniform4uiv");
	if(!ptr_glProgramUniform4uiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniform4uiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)wglGetProcAddress("glProgramUniformMatrix2fv");
	if(!ptr_glProgramUniformMatrix2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)wglGetProcAddress("glProgramUniformMatrix3fv");
	if(!ptr_glProgramUniformMatrix3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)wglGetProcAddress("glProgramUniformMatrix4fv");
	if(!ptr_glProgramUniformMatrix4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)wglGetProcAddress("glProgramUniformMatrix2dv");
	if(!ptr_glProgramUniformMatrix2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)wglGetProcAddress("glProgramUniformMatrix3dv");
	if(!ptr_glProgramUniformMatrix3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)wglGetProcAddress("glProgramUniformMatrix4dv");
	if(!ptr_glProgramUniformMatrix4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)wglGetProcAddress("glProgramUniformMatrix2x3fv");
	if(!ptr_glProgramUniformMatrix2x3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix2x3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)wglGetProcAddress("glProgramUniformMatrix3x2fv");
	if(!ptr_glProgramUniformMatrix3x2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix3x2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)wglGetProcAddress("glProgramUniformMatrix2x4fv");
	if(!ptr_glProgramUniformMatrix2x4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix2x4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)wglGetProcAddress("glProgramUniformMatrix4x2fv");
	if(!ptr_glProgramUniformMatrix4x2fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix4x2fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)wglGetProcAddress("glProgramUniformMatrix3x4fv");
	if(!ptr_glProgramUniformMatrix3x4fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix3x4fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)wglGetProcAddress("glProgramUniformMatrix4x3fv");
	if(!ptr_glProgramUniformMatrix4x3fv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix4x3fv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)wglGetProcAddress("glProgramUniformMatrix2x3dv");
	if(!ptr_glProgramUniformMatrix2x3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix2x3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)wglGetProcAddress("glProgramUniformMatrix3x2dv");
	if(!ptr_glProgramUniformMatrix3x2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix3x2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)wglGetProcAddress("glProgramUniformMatrix2x4dv");
	if(!ptr_glProgramUniformMatrix2x4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix2x4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)wglGetProcAddress("glProgramUniformMatrix4x2dv");
	if(!ptr_glProgramUniformMatrix4x2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix4x2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)wglGetProcAddress("glProgramUniformMatrix3x4dv");
	if(!ptr_glProgramUniformMatrix3x4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix3x4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)wglGetProcAddress("glProgramUniformMatrix4x3dv");
	if(!ptr_glProgramUniformMatrix4x3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glProgramUniformMatrix4x3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)wglGetProcAddress("glValidateProgramPipeline");
	if(!ptr_glValidateProgramPipeline) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glValidateProgramPipeline\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)wglGetProcAddress("glGetProgramPipelineInfoLog");
	if(!ptr_glGetProgramPipelineInfoLog) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glGetProgramPipelineInfoLog\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)wglGetProcAddress("glVertexAttribL1d");
	if(!ptr_glVertexAttribL1d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glVertexAttribL1d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)wglGetProcAddress("glVertexAttribL2d");
	if(!ptr_glVertexAttribL2d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glVertexAttribL2d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)wglGetProcAddress("glVertexAttribL3d");
	if(!ptr_glVertexAttribL3d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glVertexAttribL3d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)wglGetProcAddress("glVertexAttribL4d");
	if(!ptr_glVertexAttribL4d) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glVertexAttribL4d\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)wglGetProcAddress("glVertexAttribL1dv");
	if(!ptr_glVertexAttribL1dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glVertexAttribL1dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)wglGetProcAddress("glVertexAttribL2dv");
	if(!ptr_glVertexAttribL2dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glVertexAttribL2dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)wglGetProcAddress("glVertexAttribL3dv");
	if(!ptr_glVertexAttribL3dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glVertexAttribL3dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)wglGetProcAddress("glVertexAttribL4dv");
	if(!ptr_glVertexAttribL4dv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glVertexAttribL4dv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)wglGetProcAddress("glVertexAttribLPointer");
	if(!ptr_glVertexAttribLPointer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glVertexAttribLPointer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)wglGetProcAddress("glGetVertexAttribLdv");
	if(!ptr_glGetVertexAttribLdv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glGetVertexAttribLdv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)wglGetProcAddress("glViewportArrayv");
	if(!ptr_glViewportArrayv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glViewportArrayv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)wglGetProcAddress("glViewportIndexedf");
	if(!ptr_glViewportIndexedf) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glViewportIndexedf\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)wglGetProcAddress("glViewportIndexedfv");
	if(!ptr_glViewportIndexedfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glViewportIndexedfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glScissorArrayv = (PFNGLSCISSORARRAYVPROC)wglGetProcAddress("glScissorArrayv");
	if(!ptr_glScissorArrayv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glScissorArrayv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)wglGetProcAddress("glScissorIndexed");
	if(!ptr_glScissorIndexed) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glScissorIndexed\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)wglGetProcAddress("glScissorIndexedv");
	if(!ptr_glScissorIndexedv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glScissorIndexedv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)wglGetProcAddress("glDepthRangeArrayv");
	if(!ptr_glDepthRangeArrayv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glDepthRangeArrayv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)wglGetProcAddress("glDepthRangeIndexed");
	if(!ptr_glDepthRangeIndexed) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glDepthRangeIndexed\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetFloati_v = (PFNGLGETFLOATI_VPROC)wglGetProcAddress("glGetFloati_v");
	if(!ptr_glGetFloati_v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glGetFloati_v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)wglGetProcAddress("glGetDoublei_v");
	if(!ptr_glGetDoublei_v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.1, function \"glGetDoublei_v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)wglGetProcAddress("glDrawArraysInstancedBaseInstance");
	if(!ptr_glDrawArraysInstancedBaseInstance) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glDrawArraysInstancedBaseInstance\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)wglGetProcAddress("glDrawElementsInstancedBaseInstance");
	if(!ptr_glDrawElementsInstancedBaseInstance) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glDrawElementsInstancedBaseInstance\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)wglGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	if(!ptr_glDrawElementsInstancedBaseVertexBaseInstance) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glDrawElementsInstancedBaseVertexBaseInstance\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)wglGetProcAddress("glGetInternalformativ");
	if(!ptr_glGetInternalformativ) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glGetInternalformativ\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)wglGetProcAddress("glGetActiveAtomicCounterBufferiv");
	if(!ptr_glGetActiveAtomicCounterBufferiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glGetActiveAtomicCounterBufferiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)wglGetProcAddress("glBindImageTexture");
	if(!ptr_glBindImageTexture) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glBindImageTexture\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)wglGetProcAddress("glMemoryBarrier");
	if(!ptr_glMemoryBarrier) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glMemoryBarrier\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)wglGetProcAddress("glTexStorage1D");
	if(!ptr_glTexStorage1D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glTexStorage1D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)wglGetProcAddress("glTexStorage2D");
	if(!ptr_glTexStorage2D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glTexStorage2D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)wglGetProcAddress("glTexStorage3D");
	if(!ptr_glTexStorage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glTexStorage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)wglGetProcAddress("glDrawTransformFeedbackInstanced");
	if(!ptr_glDrawTransformFeedbackInstanced) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glDrawTransformFeedbackInstanced\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)wglGetProcAddress("glDrawTransformFeedbackStreamInstanced");
	if(!ptr_glDrawTransformFeedbackStreamInstanced) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.2, function \"glDrawTransformFeedbackStreamInstanced\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)wglGetProcAddress("glClearBufferData");
	if(!ptr_glClearBufferData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glClearBufferData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)wglGetProcAddress("glClearBufferSubData");
	if(!ptr_glClearBufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glClearBufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)wglGetProcAddress("glDispatchCompute");
	if(!ptr_glDispatchCompute) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glDispatchCompute\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)wglGetProcAddress("glDispatchComputeIndirect");
	if(!ptr_glDispatchComputeIndirect) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glDispatchComputeIndirect\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)wglGetProcAddress("glCopyImageSubData");
	if(!ptr_glCopyImageSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glCopyImageSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)wglGetProcAddress("glFramebufferParameteri");
	if(!ptr_glFramebufferParameteri) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glFramebufferParameteri\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferParameteriv");
	if(!ptr_glGetFramebufferParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetFramebufferParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)wglGetProcAddress("glGetInternalformati64v");
	if(!ptr_glGetInternalformati64v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetInternalformati64v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)wglGetProcAddress("glInvalidateTexSubImage");
	if(!ptr_glInvalidateTexSubImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glInvalidateTexSubImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)wglGetProcAddress("glInvalidateTexImage");
	if(!ptr_glInvalidateTexImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glInvalidateTexImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)wglGetProcAddress("glInvalidateBufferSubData");
	if(!ptr_glInvalidateBufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glInvalidateBufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)wglGetProcAddress("glInvalidateBufferData");
	if(!ptr_glInvalidateBufferData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glInvalidateBufferData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)wglGetProcAddress("glInvalidateFramebuffer");
	if(!ptr_glInvalidateFramebuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glInvalidateFramebuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)wglGetProcAddress("glInvalidateSubFramebuffer");
	if(!ptr_glInvalidateSubFramebuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glInvalidateSubFramebuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)wglGetProcAddress("glMultiDrawArraysIndirect");
	if(!ptr_glMultiDrawArraysIndirect) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glMultiDrawArraysIndirect\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)wglGetProcAddress("glMultiDrawElementsIndirect");
	if(!ptr_glMultiDrawElementsIndirect) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glMultiDrawElementsIndirect\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)wglGetProcAddress("glGetProgramInterfaceiv");
	if(!ptr_glGetProgramInterfaceiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetProgramInterfaceiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)wglGetProcAddress("glGetProgramResourceIndex");
	if(!ptr_glGetProgramResourceIndex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetProgramResourceIndex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)wglGetProcAddress("glGetProgramResourceName");
	if(!ptr_glGetProgramResourceName) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetProgramResourceName\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)wglGetProcAddress("glGetProgramResourceiv");
	if(!ptr_glGetProgramResourceiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetProgramResourceiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)wglGetProcAddress("glGetProgramResourceLocation");
	if(!ptr_glGetProgramResourceLocation) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetProgramResourceLocation\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)wglGetProcAddress("glGetProgramResourceLocationIndex");
	if(!ptr_glGetProgramResourceLocationIndex) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetProgramResourceLocationIndex\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)wglGetProcAddress("glShaderStorageBlockBinding");
	if(!ptr_glShaderStorageBlockBinding) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glShaderStorageBlockBinding\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)wglGetProcAddress("glTexBufferRange");
	if(!ptr_glTexBufferRange) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glTexBufferRange\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexStorage2DMultisample");
	if(!ptr_glTexStorage2DMultisample) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glTexStorage2DMultisample\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTexStorage3DMultisample");
	if(!ptr_glTexStorage3DMultisample) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glTexStorage3DMultisample\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureView = (PFNGLTEXTUREVIEWPROC)wglGetProcAddress("glTextureView");
	if(!ptr_glTextureView) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glTextureView\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)wglGetProcAddress("glBindVertexBuffer");
	if(!ptr_glBindVertexBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glBindVertexBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)wglGetProcAddress("glVertexAttribFormat");
	if(!ptr_glVertexAttribFormat) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glVertexAttribFormat\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)wglGetProcAddress("glVertexAttribIFormat");
	if(!ptr_glVertexAttribIFormat) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glVertexAttribIFormat\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)wglGetProcAddress("glVertexAttribLFormat");
	if(!ptr_glVertexAttribLFormat) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glVertexAttribLFormat\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)wglGetProcAddress("glVertexAttribBinding");
	if(!ptr_glVertexAttribBinding) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glVertexAttribBinding\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)wglGetProcAddress("glVertexBindingDivisor");
	if(!ptr_glVertexBindingDivisor) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glVertexBindingDivisor\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)wglGetProcAddress("glDebugMessageControl");
	if(!ptr_glDebugMessageControl) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glDebugMessageControl\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)wglGetProcAddress("glDebugMessageInsert");
	if(!ptr_glDebugMessageInsert) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glDebugMessageInsert\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)wglGetProcAddress("glDebugMessageCallback");
	if(!ptr_glDebugMessageCallback) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glDebugMessageCallback\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)wglGetProcAddress("glGetDebugMessageLog");
	if(!ptr_glGetDebugMessageLog) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetDebugMessageLog\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)wglGetProcAddress("glPushDebugGroup");
	if(!ptr_glPushDebugGroup) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glPushDebugGroup\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)wglGetProcAddress("glPopDebugGroup");
	if(!ptr_glPopDebugGroup) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glPopDebugGroup\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glObjectLabel = (PFNGLOBJECTLABELPROC)wglGetProcAddress("glObjectLabel");
	if(!ptr_glObjectLabel) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glObjectLabel\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)wglGetProcAddress("glGetObjectLabel");
	if(!ptr_glGetObjectLabel) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetObjectLabel\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)wglGetProcAddress("glObjectPtrLabel");
	if(!ptr_glObjectPtrLabel) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glObjectPtrLabel\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)wglGetProcAddress("glGetObjectPtrLabel");
	if(!ptr_glGetObjectPtrLabel) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.3, function \"glGetObjectPtrLabel\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBufferStorage = (PFNGLBUFFERSTORAGEPROC)wglGetProcAddress("glBufferStorage");
	if(!ptr_glBufferStorage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.4, function \"glBufferStorage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)wglGetProcAddress("glClearTexImage");
	if(!ptr_glClearTexImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.4, function \"glClearTexImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)wglGetProcAddress("glClearTexSubImage");
	if(!ptr_glClearTexSubImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.4, function \"glClearTexSubImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)wglGetProcAddress("glBindBuffersBase");
	if(!ptr_glBindBuffersBase) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.4, function \"glBindBuffersBase\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)wglGetProcAddress("glBindBuffersRange");
	if(!ptr_glBindBuffersRange) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.4, function \"glBindBuffersRange\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindTextures = (PFNGLBINDTEXTURESPROC)wglGetProcAddress("glBindTextures");
	if(!ptr_glBindTextures) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.4, function \"glBindTextures\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindSamplers = (PFNGLBINDSAMPLERSPROC)wglGetProcAddress("glBindSamplers");
	if(!ptr_glBindSamplers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.4, function \"glBindSamplers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)wglGetProcAddress("glBindImageTextures");
	if(!ptr_glBindImageTextures) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.4, function \"glBindImageTextures\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)wglGetProcAddress("glBindVertexBuffers");
	if(!ptr_glBindVertexBuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.4, function \"glBindVertexBuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClipControl = (PFNGLCLIPCONTROLPROC)wglGetProcAddress("glClipControl");
	if(!ptr_glClipControl) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glClipControl\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC)wglGetProcAddress("glCreateTransformFeedbacks");
	if(!ptr_glCreateTransformFeedbacks) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCreateTransformFeedbacks\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)wglGetProcAddress("glTransformFeedbackBufferBase");
	if(!ptr_glTransformFeedbackBufferBase) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTransformFeedbackBufferBase\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)wglGetProcAddress("glTransformFeedbackBufferRange");
	if(!ptr_glTransformFeedbackBufferRange) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTransformFeedbackBufferRange\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC)wglGetProcAddress("glGetTransformFeedbackiv");
	if(!ptr_glGetTransformFeedbackiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTransformFeedbackiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)wglGetProcAddress("glGetTransformFeedbacki_v");
	if(!ptr_glGetTransformFeedbacki_v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTransformFeedbacki_v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)wglGetProcAddress("glGetTransformFeedbacki64_v");
	if(!ptr_glGetTransformFeedbacki64_v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTransformFeedbacki64_v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateBuffers = (PFNGLCREATEBUFFERSPROC)wglGetProcAddress("glCreateBuffers");
	if(!ptr_glCreateBuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCreateBuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC)wglGetProcAddress("glNamedBufferStorage");
	if(!ptr_glNamedBufferStorage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedBufferStorage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)wglGetProcAddress("glNamedBufferData");
	if(!ptr_glNamedBufferData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedBufferData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glNamedBufferSubData");
	if(!ptr_glNamedBufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedBufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glCopyNamedBufferSubData");
	if(!ptr_glCopyNamedBufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCopyNamedBufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC)wglGetProcAddress("glClearNamedBufferData");
	if(!ptr_glClearNamedBufferData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glClearNamedBufferData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glClearNamedBufferSubData");
	if(!ptr_glClearNamedBufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glClearNamedBufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC)wglGetProcAddress("glMapNamedBuffer");
	if(!ptr_glMapNamedBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glMapNamedBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC)wglGetProcAddress("glMapNamedBufferRange");
	if(!ptr_glMapNamedBufferRange) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glMapNamedBufferRange\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC)wglGetProcAddress("glUnmapNamedBuffer");
	if(!ptr_glUnmapNamedBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glUnmapNamedBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)wglGetProcAddress("glFlushMappedNamedBufferRange");
	if(!ptr_glFlushMappedNamedBufferRange) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glFlushMappedNamedBufferRange\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetNamedBufferParameteriv");
	if(!ptr_glGetNamedBufferParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetNamedBufferParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)wglGetProcAddress("glGetNamedBufferParameteri64v");
	if(!ptr_glGetNamedBufferParameteri64v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetNamedBufferParameteri64v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC)wglGetProcAddress("glGetNamedBufferPointerv");
	if(!ptr_glGetNamedBufferPointerv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetNamedBufferPointerv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC)wglGetProcAddress("glGetNamedBufferSubData");
	if(!ptr_glGetNamedBufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetNamedBufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC)wglGetProcAddress("glCreateFramebuffers");
	if(!ptr_glCreateFramebuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCreateFramebuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glNamedFramebufferRenderbuffer");
	if(!ptr_glNamedFramebufferRenderbuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedFramebufferRenderbuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)wglGetProcAddress("glNamedFramebufferParameteri");
	if(!ptr_glNamedFramebufferParameteri) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedFramebufferParameteri\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glNamedFramebufferTexture");
	if(!ptr_glNamedFramebufferTexture) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedFramebufferTexture\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)wglGetProcAddress("glNamedFramebufferTextureLayer");
	if(!ptr_glNamedFramebufferTextureLayer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedFramebufferTextureLayer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)wglGetProcAddress("glNamedFramebufferDrawBuffer");
	if(!ptr_glNamedFramebufferDrawBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedFramebufferDrawBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)wglGetProcAddress("glNamedFramebufferDrawBuffers");
	if(!ptr_glNamedFramebufferDrawBuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedFramebufferDrawBuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)wglGetProcAddress("glNamedFramebufferReadBuffer");
	if(!ptr_glNamedFramebufferReadBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedFramebufferReadBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)wglGetProcAddress("glInvalidateNamedFramebufferData");
	if(!ptr_glInvalidateNamedFramebufferData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glInvalidateNamedFramebufferData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)wglGetProcAddress("glInvalidateNamedFramebufferSubData");
	if(!ptr_glInvalidateNamedFramebufferSubData) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glInvalidateNamedFramebufferSubData\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)wglGetProcAddress("glClearNamedFramebufferiv");
	if(!ptr_glClearNamedFramebufferiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glClearNamedFramebufferiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)wglGetProcAddress("glClearNamedFramebufferuiv");
	if(!ptr_glClearNamedFramebufferuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glClearNamedFramebufferuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)wglGetProcAddress("glClearNamedFramebufferfv");
	if(!ptr_glClearNamedFramebufferfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glClearNamedFramebufferfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)wglGetProcAddress("glClearNamedFramebufferfi");
	if(!ptr_glClearNamedFramebufferfi) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glClearNamedFramebufferfi\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC)wglGetProcAddress("glBlitNamedFramebuffer");
	if(!ptr_glBlitNamedFramebuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glBlitNamedFramebuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckNamedFramebufferStatus");
	if(!ptr_glCheckNamedFramebufferStatus) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCheckNamedFramebufferStatus\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetNamedFramebufferParameteriv");
	if(!ptr_glGetNamedFramebufferParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetNamedFramebufferParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)wglGetProcAddress("glGetNamedFramebufferAttachmentParameteriv");
	if(!ptr_glGetNamedFramebufferAttachmentParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetNamedFramebufferAttachmentParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC)wglGetProcAddress("glCreateRenderbuffers");
	if(!ptr_glCreateRenderbuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCreateRenderbuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glNamedRenderbufferStorage");
	if(!ptr_glNamedRenderbufferStorage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedRenderbufferStorage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glNamedRenderbufferStorageMultisample");
	if(!ptr_glNamedRenderbufferStorageMultisample) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glNamedRenderbufferStorageMultisample\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetNamedRenderbufferParameteriv");
	if(!ptr_glGetNamedRenderbufferParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetNamedRenderbufferParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateTextures = (PFNGLCREATETEXTURESPROC)wglGetProcAddress("glCreateTextures");
	if(!ptr_glCreateTextures) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCreateTextures\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureBuffer = (PFNGLTEXTUREBUFFERPROC)wglGetProcAddress("glTextureBuffer");
	if(!ptr_glTextureBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC)wglGetProcAddress("glTextureBufferRange");
	if(!ptr_glTextureBufferRange) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureBufferRange\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC)wglGetProcAddress("glTextureStorage1D");
	if(!ptr_glTextureStorage1D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureStorage1D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC)wglGetProcAddress("glTextureStorage2D");
	if(!ptr_glTextureStorage2D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureStorage2D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC)wglGetProcAddress("glTextureStorage3D");
	if(!ptr_glTextureStorage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureStorage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTextureStorage2DMultisample");
	if(!ptr_glTextureStorage2DMultisample) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureStorage2DMultisample\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTextureStorage3DMultisample");
	if(!ptr_glTextureStorage3DMultisample) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureStorage3DMultisample\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC)wglGetProcAddress("glTextureSubImage1D");
	if(!ptr_glTextureSubImage1D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureSubImage1D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)wglGetProcAddress("glTextureSubImage2D");
	if(!ptr_glTextureSubImage2D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureSubImage2D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC)wglGetProcAddress("glTextureSubImage3D");
	if(!ptr_glTextureSubImage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureSubImage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)wglGetProcAddress("glCompressedTextureSubImage1D");
	if(!ptr_glCompressedTextureSubImage1D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCompressedTextureSubImage1D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)wglGetProcAddress("glCompressedTextureSubImage2D");
	if(!ptr_glCompressedTextureSubImage2D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCompressedTextureSubImage2D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)wglGetProcAddress("glCompressedTextureSubImage3D");
	if(!ptr_glCompressedTextureSubImage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCompressedTextureSubImage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)wglGetProcAddress("glCopyTextureSubImage1D");
	if(!ptr_glCopyTextureSubImage1D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCopyTextureSubImage1D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)wglGetProcAddress("glCopyTextureSubImage2D");
	if(!ptr_glCopyTextureSubImage2D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCopyTextureSubImage2D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)wglGetProcAddress("glCopyTextureSubImage3D");
	if(!ptr_glCopyTextureSubImage3D) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCopyTextureSubImage3D\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC)wglGetProcAddress("glTextureParameterf");
	if(!ptr_glTextureParameterf) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureParameterf\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC)wglGetProcAddress("glTextureParameterfv");
	if(!ptr_glTextureParameterfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureParameterfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC)wglGetProcAddress("glTextureParameteri");
	if(!ptr_glTextureParameteri) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureParameteri\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC)wglGetProcAddress("glTextureParameterIiv");
	if(!ptr_glTextureParameterIiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureParameterIiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC)wglGetProcAddress("glTextureParameterIuiv");
	if(!ptr_glTextureParameterIuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureParameterIuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC)wglGetProcAddress("glTextureParameteriv");
	if(!ptr_glTextureParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC)wglGetProcAddress("glGenerateTextureMipmap");
	if(!ptr_glGenerateTextureMipmap) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGenerateTextureMipmap\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC)wglGetProcAddress("glBindTextureUnit");
	if(!ptr_glBindTextureUnit) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glBindTextureUnit\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)wglGetProcAddress("glGetTextureImage");
	if(!ptr_glGetTextureImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTextureImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)wglGetProcAddress("glGetCompressedTextureImage");
	if(!ptr_glGetCompressedTextureImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetCompressedTextureImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)wglGetProcAddress("glGetTextureLevelParameterfv");
	if(!ptr_glGetTextureLevelParameterfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTextureLevelParameterfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)wglGetProcAddress("glGetTextureLevelParameteriv");
	if(!ptr_glGetTextureLevelParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTextureLevelParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC)wglGetProcAddress("glGetTextureParameterfv");
	if(!ptr_glGetTextureParameterfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTextureParameterfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC)wglGetProcAddress("glGetTextureParameterIiv");
	if(!ptr_glGetTextureParameterIiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTextureParameterIiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC)wglGetProcAddress("glGetTextureParameterIuiv");
	if(!ptr_glGetTextureParameterIuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTextureParameterIuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC)wglGetProcAddress("glGetTextureParameteriv");
	if(!ptr_glGetTextureParameteriv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTextureParameteriv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)wglGetProcAddress("glCreateVertexArrays");
	if(!ptr_glCreateVertexArrays) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCreateVertexArrays\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)wglGetProcAddress("glDisableVertexArrayAttrib");
	if(!ptr_glDisableVertexArrayAttrib) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glDisableVertexArrayAttrib\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)wglGetProcAddress("glEnableVertexArrayAttrib");
	if(!ptr_glEnableVertexArrayAttrib) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glEnableVertexArrayAttrib\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)wglGetProcAddress("glVertexArrayElementBuffer");
	if(!ptr_glVertexArrayElementBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glVertexArrayElementBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)wglGetProcAddress("glVertexArrayVertexBuffer");
	if(!ptr_glVertexArrayVertexBuffer) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glVertexArrayVertexBuffer\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)wglGetProcAddress("glVertexArrayVertexBuffers");
	if(!ptr_glVertexArrayVertexBuffers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glVertexArrayVertexBuffers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)wglGetProcAddress("glVertexArrayAttribBinding");
	if(!ptr_glVertexArrayAttribBinding) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glVertexArrayAttribBinding\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)wglGetProcAddress("glVertexArrayAttribFormat");
	if(!ptr_glVertexArrayAttribFormat) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glVertexArrayAttribFormat\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)wglGetProcAddress("glVertexArrayAttribIFormat");
	if(!ptr_glVertexArrayAttribIFormat) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glVertexArrayAttribIFormat\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)wglGetProcAddress("glVertexArrayAttribLFormat");
	if(!ptr_glVertexArrayAttribLFormat) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glVertexArrayAttribLFormat\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)wglGetProcAddress("glVertexArrayBindingDivisor");
	if(!ptr_glVertexArrayBindingDivisor) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glVertexArrayBindingDivisor\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC)wglGetProcAddress("glGetVertexArrayiv");
	if(!ptr_glGetVertexArrayiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetVertexArrayiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)wglGetProcAddress("glGetVertexArrayIndexediv");
	if(!ptr_glGetVertexArrayIndexediv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetVertexArrayIndexediv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)wglGetProcAddress("glGetVertexArrayIndexed64iv");
	if(!ptr_glGetVertexArrayIndexed64iv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetVertexArrayIndexed64iv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateSamplers = (PFNGLCREATESAMPLERSPROC)wglGetProcAddress("glCreateSamplers");
	if(!ptr_glCreateSamplers) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCreateSamplers\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC)wglGetProcAddress("glCreateProgramPipelines");
	if(!ptr_glCreateProgramPipelines) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCreateProgramPipelines\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glCreateQueries = (PFNGLCREATEQUERIESPROC)wglGetProcAddress("glCreateQueries");
	if(!ptr_glCreateQueries) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glCreateQueries\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)wglGetProcAddress("glGetQueryBufferObjecti64v");
	if(!ptr_glGetQueryBufferObjecti64v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetQueryBufferObjecti64v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC)wglGetProcAddress("glGetQueryBufferObjectiv");
	if(!ptr_glGetQueryBufferObjectiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetQueryBufferObjectiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)wglGetProcAddress("glGetQueryBufferObjectui64v");
	if(!ptr_glGetQueryBufferObjectui64v) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetQueryBufferObjectui64v\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)wglGetProcAddress("glGetQueryBufferObjectuiv");
	if(!ptr_glGetQueryBufferObjectuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetQueryBufferObjectuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)wglGetProcAddress("glMemoryBarrierByRegion");
	if(!ptr_glMemoryBarrierByRegion) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glMemoryBarrierByRegion\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC)wglGetProcAddress("glGetTextureSubImage");
	if(!ptr_glGetTextureSubImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetTextureSubImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)wglGetProcAddress("glGetCompressedTextureSubImage");
	if(!ptr_glGetCompressedTextureSubImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetCompressedTextureSubImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)wglGetProcAddress("glGetGraphicsResetStatus");
	if(!ptr_glGetGraphicsResetStatus) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetGraphicsResetStatus\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)wglGetProcAddress("glGetnCompressedTexImage");
	if(!ptr_glGetnCompressedTexImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnCompressedTexImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnTexImage = (PFNGLGETNTEXIMAGEPROC)wglGetProcAddress("glGetnTexImage");
	if(!ptr_glGetnTexImage) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnTexImage\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnUniformdv = (PFNGLGETNUNIFORMDVPROC)wglGetProcAddress("glGetnUniformdv");
	if(!ptr_glGetnUniformdv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnUniformdv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)wglGetProcAddress("glGetnUniformfv");
	if(!ptr_glGetnUniformfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnUniformfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)wglGetProcAddress("glGetnUniformiv");
	if(!ptr_glGetnUniformiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnUniformiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)wglGetProcAddress("glGetnUniformuiv");
	if(!ptr_glGetnUniformuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnUniformuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glReadnPixels = (PFNGLREADNPIXELSPROC)wglGetProcAddress("glReadnPixels");
	if(!ptr_glReadnPixels) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glReadnPixels\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnMapdv = (PFNGLGETNMAPDVPROC)wglGetProcAddress("glGetnMapdv");
	if(!ptr_glGetnMapdv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnMapdv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnMapfv = (PFNGLGETNMAPFVPROC)wglGetProcAddress("glGetnMapfv");
	if(!ptr_glGetnMapfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnMapfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnMapiv = (PFNGLGETNMAPIVPROC)wglGetProcAddress("glGetnMapiv");
	if(!ptr_glGetnMapiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnMapiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnPixelMapfv = (PFNGLGETNPIXELMAPFVPROC)wglGetProcAddress("glGetnPixelMapfv");
	if(!ptr_glGetnPixelMapfv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnPixelMapfv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnPixelMapuiv = (PFNGLGETNPIXELMAPUIVPROC)wglGetProcAddress("glGetnPixelMapuiv");
	if(!ptr_glGetnPixelMapuiv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnPixelMapuiv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnPixelMapusv = (PFNGLGETNPIXELMAPUSVPROC)wglGetProcAddress("glGetnPixelMapusv");
	if(!ptr_glGetnPixelMapusv) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnPixelMapusv\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnPolygonStipple = (PFNGLGETNPOLYGONSTIPPLEPROC)wglGetProcAddress("glGetnPolygonStipple");
	if(!ptr_glGetnPolygonStipple) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnPolygonStipple\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnColorTable = (PFNGLGETNCOLORTABLEPROC)wglGetProcAddress("glGetnColorTable");
	if(!ptr_glGetnColorTable) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnColorTable\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnConvolutionFilter = (PFNGLGETNCONVOLUTIONFILTERPROC)wglGetProcAddress("glGetnConvolutionFilter");
	if(!ptr_glGetnConvolutionFilter) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnConvolutionFilter\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnSeparableFilter = (PFNGLGETNSEPARABLEFILTERPROC)wglGetProcAddress("glGetnSeparableFilter");
	if(!ptr_glGetnSeparableFilter) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnSeparableFilter\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnHistogram = (PFNGLGETNHISTOGRAMPROC)wglGetProcAddress("glGetnHistogram");
	if(!ptr_glGetnHistogram) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnHistogram\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetnMinmax = (PFNGLGETNMINMAXPROC)wglGetProcAddress("glGetnMinmax");
	if(!ptr_glGetnMinmax) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glGetnMinmax\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glTextureBarrier = (PFNGLTEXTUREBARRIERPROC)wglGetProcAddress("glTextureBarrier");
	if(!ptr_glTextureBarrier) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.5, function \"glTextureBarrier\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glSpecializeShader = (PFNGLSPECIALIZESHADERPROC)wglGetProcAddress("glSpecializeShader");
	if(!ptr_glSpecializeShader) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.6, function \"glSpecializeShader\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)wglGetProcAddress("glMultiDrawArraysIndirectCount");
	if(!ptr_glMultiDrawArraysIndirectCount) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.6, function \"glMultiDrawArraysIndirectCount\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)wglGetProcAddress("glMultiDrawElementsIndirectCount");
	if(!ptr_glMultiDrawElementsIndirectCount) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.6, function \"glMultiDrawElementsIndirectCount\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC)wglGetProcAddress("glPolygonOffsetClamp");
	if(!ptr_glPolygonOffsetClamp) { MessageBox(0, TEXT("Couldn't load OpenGL core version 4.6, function \"glPolygonOffsetClamp\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureHandle = (PFNGLGETTEXTUREHANDLEARBPROC)wglGetProcAddress("glGetTextureHandleARB");
	if(!ptr_glGetTextureHandle) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glGetTextureHandleARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetTextureSamplerHandle = (PFNGLGETTEXTURESAMPLERHANDLEARBPROC)wglGetProcAddress("glGetTextureSamplerHandleARB");
	if(!ptr_glGetTextureSamplerHandle) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glGetTextureSamplerHandleARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMakeTextureHandleResident = (PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)wglGetProcAddress("glMakeTextureHandleResidentARB");
	if(!ptr_glMakeTextureHandleResident) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glMakeTextureHandleResidentARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMakeTextureHandleNonResident = (PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)wglGetProcAddress("glMakeTextureHandleNonResidentARB");
	if(!ptr_glMakeTextureHandleNonResident) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glMakeTextureHandleNonResidentARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetImageHandle = (PFNGLGETIMAGEHANDLEARBPROC)wglGetProcAddress("glGetImageHandleARB");
	if(!ptr_glGetImageHandle) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glGetImageHandleARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMakeImageHandleResident = (PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)wglGetProcAddress("glMakeImageHandleResidentARB");
	if(!ptr_glMakeImageHandleResident) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glMakeImageHandleResidentARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glMakeImageHandleNonResident = (PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)wglGetProcAddress("glMakeImageHandleNonResidentARB");
	if(!ptr_glMakeImageHandleNonResident) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glMakeImageHandleNonResidentARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformHandleui64 = (PFNGLUNIFORMHANDLEUI64ARBPROC)wglGetProcAddress("glUniformHandleui64ARB");
	if(!ptr_glUniformHandleui64) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glUniformHandleui64ARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glUniformHandleui64v = (PFNGLUNIFORMHANDLEUI64VARBPROC)wglGetProcAddress("glUniformHandleui64vARB");
	if(!ptr_glUniformHandleui64v) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glUniformHandleui64vARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformHandleui64 = (PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)wglGetProcAddress("glProgramUniformHandleui64ARB");
	if(!ptr_glProgramUniformHandleui64) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glProgramUniformHandleui64ARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glProgramUniformHandleui64v = (PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)wglGetProcAddress("glProgramUniformHandleui64vARB");
	if(!ptr_glProgramUniformHandleui64v) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glProgramUniformHandleui64vARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsTextureHandleResident = (PFNGLISTEXTUREHANDLERESIDENTARBPROC)wglGetProcAddress("glIsTextureHandleResidentARB");
	if(!ptr_glIsTextureHandleResident) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glIsTextureHandleResidentARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glIsImageHandleResident = (PFNGLISIMAGEHANDLERESIDENTARBPROC)wglGetProcAddress("glIsImageHandleResidentARB");
	if(!ptr_glIsImageHandleResident) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glIsImageHandleResidentARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL1ui64 = (PFNGLVERTEXATTRIBL1UI64ARBPROC)wglGetProcAddress("glVertexAttribL1ui64ARB");
	if(!ptr_glVertexAttribL1ui64) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glVertexAttribL1ui64ARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glVertexAttribL1ui64v = (PFNGLVERTEXATTRIBL1UI64VARBPROC)wglGetProcAddress("glVertexAttribL1ui64vARB");
	if(!ptr_glVertexAttribL1ui64v) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glVertexAttribL1ui64vARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	ptr_glGetVertexAttribLui64v = (PFNGLGETVERTEXATTRIBLUI64VARBPROC)wglGetProcAddress("glGetVertexAttribLui64vARB");
	if(!ptr_glGetVertexAttribLui64v) { MessageBox(0, TEXT("Couldn't load OpenGL extension bindless_texture, function \"glGetVertexAttribLui64vARB\" is missing."), TEXT("OpenGL function missing"), MB_OK); result = -1; }

	return result; 
}
