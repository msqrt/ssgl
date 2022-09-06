
#include <vector>
#include <fstream>
#include <charconv>
#include <filesystem>
#include <stdio.h>
#include <unordered_map>

#include "mesh.h"
#include "math_helpers.h"

struct ind_type { uint32_t position, uv, normal, material; };

bool operator==(const ind_type& a, const ind_type& b) {
	return a.position == b.position && a.uv == b.uv && a.normal == b.normal && a.material == b.material;
}

namespace std {
	template<>
	struct hash<ind_type> {
		size_t operator()(const ind_type& i) const {
			size_t result = 0;
			for (uint32_t k : {i.position, i.uv, i.normal, i.material}) {
				srnd(k); rnd();
				result ^= rnd_seed + 0x9e3779b9 + (result << 6) + (result >> 2);
			}
			return result;
		}
	};
}

void get_mesh(const char* filename, void* meshPtr, bool smooth_shaded) {
	
	using namespace std;
	
	struct binary_header {
		uint32_t position_count, uv_count, normal_count, material_count, triangle_count;
	};

	vector<vec3> positions;
	vector<vec2> uvs;
	vector<vec3> normals;
	vector<vec3> material_albedos;
	vector<ind_type> indices;
	
	filesystem::path path(filename);
	
	path.replace_extension(".bin");
	if (!filesystem::exists(path)) {

		path.replace_extension(".mtl");
		FILE* mtlFile = fopen(path.string().c_str(), "rb");
		fseek(mtlFile, 0, SEEK_END);
		const size_t mtlSize = size_t(ftell(mtlFile)) + 1;

		vector<char> mtlContents(mtlSize);
		mtlContents.back() = '\0';
		fseek(mtlFile, 0, SEEK_SET);
		fread(mtlContents.data(), 1, mtlSize - 1, mtlFile);
		fclose(mtlFile);

		vector<int> mtlNameIndices;
		vec3 color(1.f);
		int i = 0;
		while (i < mtlSize - 1) {
			if (mtlContents[i] == 'n') {
				i += 7; // skip "newmtl "
				while (mtlContents[i] == ' ' || mtlContents[i] == '\t') i++;

				if (mtlNameIndices.size() > 0)
					material_albedos.push_back(color);
				mtlNameIndices.push_back(i);
			}
			else if (mtlContents[i] == 'K' && mtlContents[i+1] == 'd')
				sscanf(mtlContents.data() + i + 2, " %g %g %g", color.data, color.data+1, color.data+2);
			while (i < mtlSize - 1 && mtlContents[i++] != '\n');
		}
		material_albedos.push_back(color);
	
		path.replace_extension(".obj");

		FILE* objFile = fopen(path.string().c_str(), "rb");
		fseek(objFile, 0, SEEK_END);
		const size_t objSize = size_t(ftell(objFile)) + 1;

		vector<char> objContents(objSize);
		objContents.back() = '\0';
		fseek(objFile, 0, SEEK_SET);
		fread(objContents.data(), 1, objSize - 1, objFile);
		fclose(objFile);

		int use_mtl_index = 0;
		i = 0;
		while (i<objSize-1) {
			if (objContents[i] == 'v') {
				i++;
				if (objContents[i] == ' ') {
					while (objContents[i++] != ' ');
					vec3 position;
					position.x = (float)atof(objContents.data() + i); while (objContents[i++] != ' ');
					position.y = (float)atof(objContents.data() + i); while (objContents[i++] != ' ');
					position.z = (float)atof(objContents.data() + i);
					positions.push_back(position);
				}
				else if (objContents[i] == 't') {
					i++; while (objContents[i++] != ' ');
					vec2 uv;
					uv.x = (float)atof(objContents.data() + i); while (objContents[i++] != ' ');
					uv.y = (float)atof(objContents.data() + i);
					uvs.push_back(uv);
				}
				else if (objContents[i] == 'n') {
					i++; while (objContents[i++] != ' ');
					vec3 normal;
					normal.x = (float)atof(objContents.data() + i); while (objContents[i++] != ' ');
					normal.y = (float)atof(objContents.data() + i); while (objContents[i++] != ' ');
					normal.z = (float)atof(objContents.data() + i);
					normals.push_back(normal);
				}
			}
			else if (objContents[i] == 'f') {
				i++;
				ind_type sweep_inds[3] = {0};
				for (int k = 0; k < 3; ++k) sweep_inds[k].material = use_mtl_index;
				int j = 0, write_index = 0;
				while (objContents[i] == ' ' || objContents[i] == '\t') i++;
				while(objContents[i]!='\n') {
					sweep_inds[write_index].position = atoi(objContents.data() + i)-1;
					while (objContents[i++] != '/') ;
					if (objContents[i] != '/')
						sweep_inds[write_index].uv = atoi(objContents.data() + i)-1;
					while (objContents[i++] != '/');
					sweep_inds[write_index].normal = atoi(objContents.data() + i)-1;

					//f 7579 / 4213 / 7701 7640 / 4214 / 7702 7581 / 4215 / 7703 7580 / 4216 / 7704

					while (objContents[i] != ' ' && objContents[i] != '\t' && objContents[i]!='\n') i++;
					
					if (j >= 2)
						for(int k = 0; k<3; ++k)
							indices.push_back(sweep_inds[k]);

					sweep_inds[1] = sweep_inds[2];
					j++; write_index = 2;

					while (objContents[i] == ' ' || objContents[i] == '\t') i++;
				}
			}
			else if (objContents[i] == 'u' && objContents[i+1] == 's') {
				use_mtl_index = -1;
				i += 7; // skip "usemtl "
				while (objContents[i] == ' ' || objContents[i] == '\t') i++;
				for (auto j: mtlNameIndices) {
					use_mtl_index++;
					int k = i;
					bool match = false;
					while (objContents[k] == mtlContents[j] && objContents[k] != '\0') {
						if (objContents[k] == ' ' || objContents[k] == '\t' || objContents[k] == '\n' || objContents[k] == '\0') {
							match = true;
							break;
						}
						k++; j++;
					}
					if (match) break;
				}
			}
			while (i < objSize - 1 && objContents[i] != '\n') i++;
			i++;
		}
		path.replace_extension(".bin");
		FILE* binFile = fopen(path.string().c_str(), "wb");
		binary_header header = { uint32_t(positions.size()), uint32_t(uvs.size()), uint32_t(normals.size()), uint32_t(material_albedos.size()), uint32_t(indices.size()) };
		fwrite(&header, sizeof(header), 1, binFile);
		fwrite(positions.data(), sizeof(positions[0]), positions.size(), binFile);
		fwrite(uvs.data(), sizeof(uvs[0]), uvs.size(), binFile);
		fwrite(normals.data(), sizeof(normals[0]), normals.size(), binFile);
		fwrite(material_albedos.data(), sizeof(material_albedos[0]), material_albedos.size(), binFile);
		fwrite(indices.data(), sizeof(indices[0]), indices.size(), binFile);
		fclose(binFile);
	}
	else {
		FILE* binFile = fopen(path.string().c_str(), "rb");
		binary_header header;
		fread(&header, sizeof(header), 1, binFile);
		positions.resize(header.position_count); uvs.resize(header.uv_count); normals.resize(header.normal_count);
		material_albedos.resize(header.material_count); indices.resize(header.triangle_count);
		fread(positions.data(), sizeof(positions[0]), positions.size(), binFile);
		fread(uvs.data(), sizeof(uvs[0]), uvs.size(), binFile);
		fread(normals.data(), sizeof(normals[0]), normals.size(), binFile);
		fread(material_albedos.data(), sizeof(material_albedos[0]), material_albedos.size(), binFile);
		fread(indices.data(), sizeof(indices[0]), indices.size(), binFile);
		fclose(binFile);
	}

	if (!smooth_shaded) {
		FlatMesh* mesh = (FlatMesh*)meshPtr;
		mesh->triangle_count = int(indices.size()/3);
#ifdef _WIN32
		mesh->triangles = (FlatMesh::triangle*)_aligned_malloc(mesh->triangle_count * sizeof(FlatMesh::triangle), 16);
#else											// see how the arguments are flipped? pretty funny joke by whoever defined these :)
		mesh->triangles = (FlatMesh::triangle*)aligned_alloc(16, mesh->triangle_count * sizeof(FlatMesh::triangle));
#endif
		for (int i = 0; i < mesh->triangle_count; ++i) {
			vec3 color = material_albedos[indices[i * 3].material];
			for (int j = 0; j < 3; ++j) {
				const auto ind = indices[i * 3 + j];
				vec3 position = positions[ind.position];
				
				mesh->triangles[i].vertices[j].position = _mm_setr_ps(position.x, position.y, position.z, 1.f);
				vec3 normal = normals[ind.normal];
				mesh->triangles[i].vertices[j].normal = _mm_setr_ps(normal.x, normal.y, normal.z, 1.f);
				mesh->triangles[i].vertices[j].color = _mm_setr_ps(color.r, color.g, color.b, 1.f);
			}
		}
	}
	else {
		Mesh* mesh = (Mesh*)meshPtr;
		mesh->triangle_count = int(indices.size() / 3);
		mesh->vertex_count = int(positions.size());

		std::unordered_map<ind_type, int> ind_to_vert;
		std::vector<Mesh::vertex> verts;
		std::vector<uint32_t> inds;

		for (ind_type i : indices) {
			if(i.position > mesh->vertex_count) continue;
			if (!ind_to_vert.count(i)) {
				ind_to_vert[i] = verts.size();
				verts.push_back({});
				verts.back().position = vec4(positions[i.position], 1.f);
				verts.back().normal = i.normal < normals.size() ? vec4(normals[i.normal], 1.f) : vec4(.0f);
				verts.back().uv = i.uv<uvs.size() ? uvs[i.uv] : vec2(.0f);
				verts.back().color = i.material < material_albedos.size() ? vec4(material_albedos[i.material], 1.f) : vec4(1.f);
			}
			inds.push_back(ind_to_vert[i]);
		}

		mesh->vertex_count = verts.size();
		mesh->verts = new Mesh::vertex[mesh->vertex_count];
		memcpy(mesh->verts, verts.data(), sizeof(Mesh::vertex)*verts.size());
		mesh->indices = new uint32_t[mesh->triangle_count * 3];
		memcpy(mesh->indices, inds.data(), sizeof(uint32_t)*inds.size());
	}
}

