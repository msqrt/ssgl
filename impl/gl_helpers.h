#pragma once

#define GL_GLEXT_LEGACY
#include <GL/gl.h>
#undef GL_VERSION_1_3
#include "glext.h"

#include "loadgl46.h"

#include <vector>
// RAII lifetime handlers for GLuint-based buffers and textures; in principle, very close to unique pointers (with GLuint playing the role of a raw pointer).

struct Buffer {
public:
	void destroy() { if (object != 0 && owning) { glDeleteBuffers(1, &object); object = 0; } }
	Buffer() : owning(true) { glCreateBuffers(1, &object); }
	Buffer(size_t size, void* data = nullptr, bool immutable = false, GLenum usage_or_flags = GL_STATIC_DRAW) : owning(true) {
		glCreateBuffers(1, &object);
		if(immutable)
			glNamedBufferStorage(object, size, data, usage_or_flags);
		else
			glNamedBufferData(object, size, data, usage_or_flags);
	}
	template<typename T>
	Buffer(const std::vector<T>& v, bool immutable = false, GLenum usage_or_flags = GL_STATIC_DRAW) : owning(true) {
		glCreateBuffers(1, &object);
		if(immutable)
			glNamedBufferStorage(object, v.size()*sizeof(T), v.data(), usage_or_flags);
		else
			glNamedBufferData(object, v.size()*sizeof(T), v.data(), usage_or_flags);
	}
	template<typename T>
	operator std::vector<T>() const {
		GLint64 size;
		glGetNamedBufferParameteri64v(object, GL_BUFFER_SIZE, &size);
		if (size % sizeof(T)) printf("warning: buffer and vector types don't align");
		std::vector<T> result(size/sizeof(T));
		glGetNamedBufferSubData(object, 0, result.size()*sizeof(T), result.data());
		return result;
	}
	~Buffer() { destroy(); }
	Buffer(const Buffer& other) : object(other.object), owning(false) { }
	Buffer(GLuint object, bool owning = false) : object(object), owning(owning) { }
	Buffer(Buffer&& other) : object(other.object), owning(other.owning) { other.owning = false; }
	auto& operator=(const Buffer& other) { object = other.object; owning = false; return *this; }
	auto& operator=(Buffer&& other) { object = other.object; owning = other.owning; other.owning = false; return *this; }
	operator GLuint() const { return object; }
	operator bool() const { return object != 0; }
private:
	GLuint object = 0; bool owning;
};

template<GLenum target = GL_INVALID_INDEX> struct Texture;

template<>
struct Texture<GL_INVALID_INDEX> {
public:
	void destroy() {
		if (handle != 0) glMakeTextureHandleNonResident(handle);
		if (object && owning) { glDeleteTextures(1, &object); object = 0; }
	}
	Texture() : object(0), target(GL_INVALID_INDEX) {}
	Texture(GLuint target, bool owning = false) : target(target), owning(owning) { glCreateTextures(target, 1, &object); }
	~Texture() { if (object != 0 && owning) destroy(); }
	template<GLenum T>
	Texture(const Texture<T>& other) : object(other.object), level(other.level), layer(other.layer), target(other.target), owning(false) { }
	Texture(GLuint object, GLuint target, bool owning = false) : object(object), target(target), owning(owning) { }
	template<GLenum T>
	Texture(Texture<T>&& other) : object(other.object), level(other.level), layer(other.layer), target(other.target), owning(other.owning) { other.owning = false; }
	template<GLenum T>
	auto& operator=(const Texture<T>& other) {
		destroy();
		object = other.object; level = other.level; layer = other.layer; target = other.target;
		owning = false;
		return *this;
	}
	template<GLenum T>
	auto& operator=(Texture<T>&& other) {
		destroy();
		object = other.object; level = other.level; layer = other.layer; target = other.target;
		owning = other.owning;
		other.owning = false;
		return *this;
	}
	operator GLuint() const { return object; }
	operator bool() const { return object != 0; }
	GLuint level = 0, layer = GL_INVALID_INDEX, target;
	GLuint64 getBindless() {
		if (handle == 0) {
			handle = glGetTextureHandle(object);
			glMakeTextureHandleResident(handle);
		}
		return handle;
	}
private:
	GLuint object; bool owning; GLuint64 handle = 0;
};

template<GLenum T>
struct Texture {
public:
	void destroy() {
		if (handle != 0) glMakeTextureHandleNonResident(handle);
		if (object && owning) { glDeleteTextures(1, &object); object = 0; }
	}
	Texture() : owning(true) { glCreateTextures(T, 1, &object); }
	~Texture() { destroy(); }
	Texture(GLuint other, bool owning = false) : object(other), owning(owning) {}
	Texture(const Texture& other) : object(other.object), owning(false) { }
	Texture(Texture&& other) : object(other.object), owning(other.owning) { other.owning = false; }
	Texture& operator=(const Texture& other) { destroy(); object = other.object; owning = false; return *this; }
	Texture& operator=(Texture&& other) { destroy(); object = other.object; owning = other.owning; other.owning = false; return *this; }
	operator GLuint() const { return object; }
	operator bool() const { return object != 0; }
	static constexpr GLuint level = 0, layer = GL_INVALID_INDEX;
	friend Texture<>;
	static constexpr GLuint target = T;
	GLuint64 getBindless() {
		if (handle == 0) {
			handle = glGetTextureHandle(object);
			glMakeTextureHandleResident(handle);
		}
		return handle;
	}
private:
	GLuint object = 0; bool owning; GLuint64 handle = 0;
};

template<GLenum target>
Texture<> Level(const Texture<target>& t, int level) {
	Texture<> result(t);
	result.level = level;
	return result;
}

template<GLenum target>
Texture<> Layer(const Texture<target>& t, int layer) {
	Texture<> result(t);
	result.layer = layer;
	return result;
}

Texture<GL_TEXTURE_2D> loadImage(const char* path);
Texture<GL_TEXTURE_2D> loadImage(const wchar_t* path);
