#pragma once


#include <immintrin.h>

void get_mesh(const char* filename, void* mesh, bool smooth_shaded);

struct FlatMesh {
	struct vertex {
		__m128 position, normal, color;
	};
	struct triangle {
		vertex vertices[3];
	} *triangles = nullptr;
	int triangle_count = 0;

	FlatMesh(const char* filename) {
		get_mesh(filename, this, false);
	}
	~FlatMesh() {
#ifdef _WIN32
		_aligned_free(triangles);
#else
		free(triangles);
#endif
	}
};

#include "glsl.h"

struct Mesh {
	struct vertex {
		vec4 position, normal, color;
		vec2 uv;
	} *verts = nullptr;
	uint32_t* indices = nullptr;
	int vertex_count = 0, triangle_count = 0;

	Mesh(const char* filename) {
		get_mesh(filename, this, true);
	}
	~Mesh() { delete[] verts;  delete[] indices; }
};
