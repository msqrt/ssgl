#pragma once

#include <string>

#include <GL/gl.h>
#include "glext.h"
#include "loadgl46.h"

// GPU timing object
struct TimeStamp {
	// todo: move construct, etc? might want map of string to stamp for global use
	GLint64 asynchronous;
	GLuint synchronousObject;
	mutable GLuint available = GL_FALSE;
	mutable GLint64 synchronous;
	TimeStamp() {
		// create GPU query
		glCreateQueries(GL_TIMESTAMP, 1, &synchronousObject);
		glQueryCounter(synchronousObject, GL_TIMESTAMP);
		// query CPU counter directly
		glGetInteger64v(GL_TIMESTAMP, &asynchronous);
	}
	void check() const {
		while (available == GL_FALSE) {
			glGetQueryObjectuiv(synchronousObject, GL_QUERY_RESULT_AVAILABLE, &available);
			if(available == GL_TRUE)
				glGetQueryObjecti64v(synchronousObject, GL_QUERY_RESULT, &synchronous);
		}
	}
	// latency between CPU call and GPU execution, in ms
	double latency() const {
		check();
		return double(synchronous - asynchronous)*1.0e-6;
	}
	~TimeStamp() {
		glDeleteQueries(1, &synchronousObject);
	}
};

// GPU time between two stamps, ms
inline double operator-(const TimeStamp& end, const TimeStamp& begin) {
	begin.check();
	end.check();
	return double(end.synchronous - begin.synchronous)*1.0e-6;
}

// GPU time between two stamps, ms
inline double gpuTime(const TimeStamp& begin, const TimeStamp& end) {
	return end - begin;
}

// CPU-side time between two stamps, ms
inline double cpuTime(const TimeStamp& begin, const TimeStamp& end) {
	return double(end.asynchronous - begin.asynchronous)*1.0e-6;
}
