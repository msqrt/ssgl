#pragma once

#include <cstdio>
#include "gl_helpers.h"

template<GLenum type, typename T>
struct Image {
    GLuint obj, level, layer;
    Image() : obj(0) { }
    template<GLenum target>
    Image(const Texture<target>& t) : obj(t), level(t.level), layer(t.layer) { }
    operator int() { return obj; }
    bool operator !=(const Image& other) {
        return obj != other.obj;
    }
};

#define IMAGEBASIC(name, sizetype, prefix, ...)\
inline sizetype imageSize(prefix##name image) { return {}; }\
inline prefix##vec4 imageLoad(prefix##name image, __VA_ARGS__) { return {}; }\
inline void imageStore(prefix##name image, __VA_ARGS__, prefix##vec4 data) { }\

#define IMAGEATOMIC(func, name, ...)\
inline int func(i##name, __VA_ARGS__, int data){ return {}; }\
inline uint func(u##name, __VA_ARGS__, uint data){ return {}; }

#define IMAGEDEF(name, glenum, sizetype, ...)\
using name = Image < glenum, float>;\
using i ## name = Image < glenum, int>;\
using u ## name = Image < glenum, uint>;\
IMAGEBASIC(name, sizetype, , __VA_ARGS__)\
IMAGEBASIC(name, sizetype, i, __VA_ARGS__)\
IMAGEBASIC(name, sizetype, u, __VA_ARGS__)\
IMAGEATOMIC(imageAtomicAdd, name, __VA_ARGS__)\
IMAGEATOMIC(imageAtomicMin, name, __VA_ARGS__)\
IMAGEATOMIC(imageAtomicMax, name, __VA_ARGS__)\
IMAGEATOMIC(imageAtomicAnd, name, __VA_ARGS__)\
IMAGEATOMIC(imageAtomicOr, name, __VA_ARGS__)\
IMAGEATOMIC(imageAtomicXor, name, __VA_ARGS__)\
IMAGEATOMIC(imageAtomicExchange, name, __VA_ARGS__)\
IMAGEATOMIC(imageAtomicCompSwap, name, __VA_ARGS__)

IMAGEDEF(image1D, GL_TEXTURE_1D, int, int P)
IMAGEDEF(image2D, GL_TEXTURE_2D, ivec2, ivec2 P)
IMAGEDEF(image3D, GL_TEXTURE_3D, ivec3, ivec3 P)
IMAGEDEF(imageCube, GL_TEXTURE_CUBE_MAP, ivec2, ivec3 P)
IMAGEDEF(image2DRect, GL_TEXTURE_RECTANGLE, ivec2, ivec2 P)
IMAGEDEF(image1DArray, GL_TEXTURE_1D_ARRAY, ivec2, ivec2 P)
IMAGEDEF(image2DArray, GL_TEXTURE_2D_ARRAY, ivec3, ivec3 P)
IMAGEDEF(imageCubeArray, GL_TEXTURE_CUBE_MAP_ARRAY, ivec3, ivec3 P)
IMAGEDEF(imageBuffer, GL_TEXTURE_BUFFER, int, int P)
IMAGEDEF(image2DMS, GL_TEXTURE_2D_MULTISAMPLE, ivec2, ivec2 P, int sample)
IMAGEDEF(image2DMSArray, GL_TEXTURE_2D_MULTISAMPLE_ARRAY, ivec3, ivec3 P, int sample)

inline int imageSamples(image2DMS image) { return 0; }
inline int imageSamples(iimage2DMS image) { return 0; }
inline int imageSamples(uimage2DMS image) { return 0; }
inline int imageSamples(image2DMSArray image) { return 0; }
inline int imageSamples(iimage2DMSArray image) { return 0; }
inline int imageSamples(uimage2DMSArray image) { return 0; }

#undef IMAGEBASIC
#undef IMAGEATOMIC
#undef IMAGEDEF

template<GLenum type, typename T, bool shadow = false>
struct Sampler {
    GLuint obj;
    Sampler() : obj(0) { }
    Sampler(uint64_t) : obj(0) { }
    template<GLuint target>
    Sampler(const Texture<target>& t) : obj(t) {}
    operator int() { return obj; }
    bool operator !=(const Sampler<type, T, shadow>& other) {
        return obj != other.obj;
    }
};

#define COMMA ,

#define SAMPLEFUNC(func, name, params)\
inline vec4 func(name sampler params) {return {};}\
inline ivec4 func(i##name sampler params) {return {};}\
inline uvec4 func(u##name sampler params) {return {};}

#define TEXFUNC(func, name, params)\
inline func(name sampler params) { return {}; }\
inline func(i##name sampler params) { return {}; }\
inline func(u##name sampler params) { return {}; }

#define MIPPABLE(name, glenum, sizetype)\
using name = Sampler<glenum, float, false>;\
using i ## name= Sampler<glenum, int, false>;\
using u ## name = Sampler<glenum, uint, false>;\
TEXFUNC(sizetype textureSize, name,COMMA int lod)\
TEXFUNC(int textureQueryLevels, name,)

#define UNMIPPABLE(name, glenum, sizetype)\
using name = Sampler<glenum, float, false>;\
using i ## name= Sampler<glenum, int, false>;\
using u ## name = Sampler<glenum, uint, false>;\
TEXFUNC(sizetype textureSize, name,)

MIPPABLE(sampler1D, GL_TEXTURE_1D, int)
MIPPABLE(sampler2D, GL_TEXTURE_2D, ivec2)
MIPPABLE(sampler3D, GL_TEXTURE_3D, ivec3)
MIPPABLE(samplerCube, GL_TEXTURE_CUBE_MAP, ivec2)
MIPPABLE(sampler1DArray, GL_TEXTURE_1D_ARRAY, ivec2)
MIPPABLE(sampler2DArray, GL_TEXTURE_2D_ARRAY, ivec3)
MIPPABLE(samplerCubeArray, GL_TEXTURE_CUBE_MAP_ARRAY, ivec3)

UNMIPPABLE(sampler2DRect, GL_TEXTURE_RECTANGLE, ivec2)
UNMIPPABLE(samplerBuffer, GL_TEXTURE_BUFFER, int)
UNMIPPABLE(sampler2DMS, GL_TEXTURE_2D_MULTISAMPLE, ivec2)
UNMIPPABLE(sampler2DMSArray, GL_TEXTURE_2D_MULTISAMPLE_ARRAY, ivec3)

inline int textureSamples(sampler2DMS image) { return 0; }
inline int textureSamples(isampler2DMS image) { return 0; }
inline int textureSamples(usampler2DMS image) { return 0; }
inline int textureSamples(sampler2DMSArray image) { return 0; }
inline int textureSamples(isampler2DMSArray image) { return 0; }
inline int textureSamples(usampler2DMSArray image) { return 0; }

#define MIPPABLE_SHADOW(name, glenum, sizetype)\
using name = Sampler<glenum, float, true>;\
inline sizetype textureSize(name sampler, int lod) {return {};}\
inline int textureQueryLevels(name sampler) {return 0;}

MIPPABLE_SHADOW(sampler1DShadow, GL_TEXTURE_1D, int)
MIPPABLE_SHADOW(sampler2DShadow, GL_TEXTURE_2D, ivec2)
MIPPABLE_SHADOW(samplerCubeShadow, GL_TEXTURE_CUBE_MAP, ivec2)
MIPPABLE_SHADOW(sampler1DArrayShadow, GL_TEXTURE_1D_ARRAY, ivec2)
MIPPABLE_SHADOW(sampler2DArrayShadow, GL_TEXTURE_2D_ARRAY, ivec3)
MIPPABLE_SHADOW(samplerCubeArrayShadow, GL_TEXTURE_CUBE_MAP_ARRAY, ivec3)
using sampler2DRectShadow = Sampler<GL_TEXTURE_RECTANGLE, float, true>;
inline ivec2 textureSize(sampler2DRectShadow sampler) { return {}; }


SAMPLEFUNC(texelFetch, sampler1D, COMMA int P COMMA int lod)
SAMPLEFUNC(texelFetch, sampler2D, COMMA ivec2 P COMMA int lod)
SAMPLEFUNC(texelFetch, sampler3D, COMMA ivec3 P COMMA int lod)
SAMPLEFUNC(texelFetch, sampler2DRect, COMMA ivec2 P)
SAMPLEFUNC(texelFetch, sampler1DArray, COMMA ivec2 P COMMA int lod)
SAMPLEFUNC(texelFetch, sampler2DArray, COMMA ivec3 P COMMA int lod)
SAMPLEFUNC(texelFetch, samplerBuffer, COMMA int P)
SAMPLEFUNC(texelFetch, sampler2DMS, COMMA ivec2 P COMMA int sample)
SAMPLEFUNC(texelFetch, sampler2DMSArray, COMMA ivec3 P COMMA int sample)

SAMPLEFUNC(texelFetchOffset, sampler1D, COMMA int P COMMA int lod COMMA int offset)
SAMPLEFUNC(texelFetchOffset, sampler2D, COMMA ivec2 P COMMA int lod COMMA ivec2 offset)
SAMPLEFUNC(texelFetchOffset, sampler3D, COMMA ivec3 P COMMA int lod COMMA ivec3 offset)
SAMPLEFUNC(texelFetchOffset, sampler2DRect, COMMA ivec2 P COMMA ivec2 offset)
SAMPLEFUNC(texelFetchOffset, sampler1DArray, COMMA ivec2 P COMMA int lod COMMA ivec2 offset)
SAMPLEFUNC(texelFetchOffset, sampler2DArray, COMMA ivec3 P COMMA int lod COMMA ivec3 offset)

SAMPLEFUNC(texture, sampler1D, COMMA float P COMMA float bias = .0f)
SAMPLEFUNC(texture, sampler2D, COMMA vec2 P COMMA float bias = .0f)
SAMPLEFUNC(texture, sampler3D, COMMA vec3 P COMMA float bias = .0f)
SAMPLEFUNC(texture, samplerCube, COMMA vec3 P COMMA float bias = .0f)
SAMPLEFUNC(texture, sampler1DArray, COMMA vec2 P COMMA float bias = .0f)
SAMPLEFUNC(texture, sampler2DArray, COMMA vec3 P COMMA float bias = .0f)
SAMPLEFUNC(texture, samplerCubeArray, COMMA vec4 P COMMA float bias = .0f)
SAMPLEFUNC(texture, sampler2DRect, COMMA vec2 P)
inline float texture(sampler1DShadow sampler, vec3 P, float bias = .0f) { return {}; } // ... why does this take in a vec3???
inline float texture(sampler2DShadow sampler, vec3 P, float bias = .0f) { return {}; }
inline float texture(samplerCubeShadow sampler, vec4 P, float bias = .0f) { return {}; }
inline float texture(sampler1DArrayShadow sampler, vec3 P, float bias = .0f) { return {}; }
inline float texture(sampler2DArrayShadow sampler, vec4 P, float bias = .0f) { return {}; }
inline float texture(sampler2DRectShadow sampler, vec3 P) { return {}; }
inline float texture(samplerCubeArrayShadow sampler, vec4 P, float compare) { return {}; }

SAMPLEFUNC(textureGather, sampler2D, COMMA vec2 P COMMA int comp = 0)
SAMPLEFUNC(textureGather, sampler2DArray, COMMA vec3 P COMMA int comp = 0)
SAMPLEFUNC(textureGather, samplerCube, COMMA vec3 P COMMA int comp = 0)
SAMPLEFUNC(textureGather, samplerCubeArray, COMMA vec4 P COMMA int comp = 0)
SAMPLEFUNC(textureGather, sampler2DRect, COMMA vec2 P COMMA int comp = 0)
inline float textureGather(sampler2DShadow sampler, vec2 P, float refZ) { return {}; }
inline float textureGather(sampler2DArrayShadow sampler, vec3 P, float refZ) { return {}; }
inline float textureGather(samplerCubeShadow sampler, vec3 P, float refZ) { return {}; }
inline float textureGather(samplerCubeArrayShadow sampler, vec4 P, float refZ) { return {}; }
inline float textureGather(sampler2DRectShadow sampler, vec2 P, float refZ) { return {}; }

SAMPLEFUNC(textureGatherOffset, sampler2D, COMMA vec2 P COMMA ivec2 offset COMMA int comp = 0)
SAMPLEFUNC(textureGatherOffset, sampler2DArray, COMMA vec3 P COMMA ivec2 offset COMMA int comp = 0)
SAMPLEFUNC(textureGatherOffset, sampler2DRect, COMMA vec2 P COMMA ivec2 offset COMMA int comp = 0)
inline float textureGatherOffset(sampler2DShadow sampler, vec2 P, float refZ, ivec2 offset) { return {}; }
inline float textureGatherOffset(sampler2DArrayShadow sampler, vec3 P, float refZ, ivec2 offset) { return {}; }
inline float textureGatherOffset(sampler2DRectShadow sampler, vec2 P, float refZ, ivec2 offset) { return {}; }


SAMPLEFUNC(textureGatherOffsets, sampler2D, COMMA vec2 P COMMA ivec2 offsets[4] COMMA int comp = 0)
SAMPLEFUNC(textureGatherOffsets, sampler2DArray, COMMA vec3 P COMMA ivec2 offsets[4] COMMA int comp = 0)
SAMPLEFUNC(textureGatherOffsets, sampler2DRect, COMMA vec2 P COMMA ivec2 offsets[4] COMMA int comp = 0)
inline float textureGatherOffsets(sampler2DShadow sampler, vec2 P, float refZ, ivec2 offsets[4]) { return {}; }
inline float textureGatherOffsets(sampler2DArrayShadow sampler, vec3 P, float refZ, ivec2 offsets[4]) { return {}; }
inline float textureGatherOffsets(sampler2DRectShadow sampler, vec2 P, float refZ, ivec2 offsets[4]) { return {}; }

SAMPLEFUNC(textureGrad, sampler1D, COMMA float P COMMA float dPdx COMMA float dPdy)
SAMPLEFUNC(textureGrad, sampler2D, COMMA vec2 P COMMA vec2 dPdx COMMA vec2 dPdy)
SAMPLEFUNC(textureGrad, sampler3D, COMMA vec3 P COMMA vec3 dPdx COMMA vec3 dPdy)
SAMPLEFUNC(textureGrad, samplerCube, COMMA vec3 P COMMA vec3 dPdx COMMA vec3 dPdy)
SAMPLEFUNC(textureGrad, sampler1DArray, COMMA vec2 P COMMA float dPdx COMMA float dPdy)
SAMPLEFUNC(textureGrad, sampler2DArray, COMMA vec3 P COMMA vec2 dPdx COMMA vec2 dPdy)
SAMPLEFUNC(textureGrad, samplerCubeArray, COMMA vec4 P COMMA vec3 dPdx COMMA vec3 dPdy)
SAMPLEFUNC(textureGrad, sampler2DRect, COMMA vec2 P COMMA vec2 dPdx COMMA vec2 dPdy)
inline float textureGrad(sampler1DShadow sampler, vec3 P, float dPdx, float dPdy) { return {}; }
inline float textureGrad(sampler2DShadow sampler, vec3 P, vec2 dPdx, vec2 dPdy) { return {}; }
inline float textureGrad(samplerCubeShadow sampler, vec4 P, vec3 dPdx, vec3 dPdy) { return {}; }
inline float textureGrad(sampler1DArrayShadow sampler, vec3 P, float dPdx, float dPdy) { return {}; }
inline float textureGrad(sampler2DArrayShadow sampler, vec4 P, vec2 dPdx, vec2 dPdy) { return {}; }
inline float textureGrad(sampler2DRectShadow sampler, vec3 P, vec2 dPdx, vec2 dPdy) { return {}; }

SAMPLEFUNC(textureGradOffset, sampler1D, COMMA float P COMMA float dPdx COMMA float dPdy COMMA int offset)
SAMPLEFUNC(textureGradOffset, sampler2D, COMMA vec2 P COMMA vec2 dPdx COMMA vec2 dPdy COMMA ivec2 offset)
SAMPLEFUNC(textureGradOffset, sampler3D, COMMA vec3 P COMMA vec3 dPdx COMMA vec3 dPdy COMMA ivec3 offset)
SAMPLEFUNC(textureGradOffset, sampler1DArray, COMMA vec2 P COMMA float dPdx COMMA float dPdy COMMA int offset)
SAMPLEFUNC(textureGradOffset, sampler2DArray, COMMA vec3 P COMMA vec2 dPdx COMMA vec2 dPdy COMMA ivec2 offset)
SAMPLEFUNC(textureGradOffset, sampler2DRect, COMMA vec2 P COMMA vec2 dPdx COMMA vec2 dPdy COMMA ivec2 offset)
inline float textureGradOffset(sampler1DShadow sampler, vec3 P, float dPdx, float dPdy, int offset) { return {}; }
inline float textureGradOffset(sampler2DShadow sampler, vec3 P, vec2 dPdx, vec2 dPdy, ivec2 offset) { return {}; }
inline float textureGradOffset(sampler1DArrayShadow sampler, vec3 P, float dPdx, float dPdy, int offset) { return {}; }
inline float textureGradOffset(sampler2DArrayShadow sampler, vec4 P, vec2 dPdx, vec2 dPdy, ivec2 offset) { return {}; }
inline float textureGradOffset(sampler2DRectShadow sampler, vec3 P, vec2 dPdx, vec2 dPdy, ivec2 offset) { return {}; }

SAMPLEFUNC(textureLod, sampler1D, COMMA float P COMMA float lod)
SAMPLEFUNC(textureLod, sampler2D, COMMA vec2 P COMMA float lod)
SAMPLEFUNC(textureLod, sampler3D, COMMA vec3 P COMMA float lod)
SAMPLEFUNC(textureLod, samplerCube, COMMA vec3 P COMMA float lod)
SAMPLEFUNC(textureLod, sampler1DArray, COMMA vec2 P COMMA float lod)
SAMPLEFUNC(textureLod, sampler2DArray, COMMA vec3 P COMMA float lod)
SAMPLEFUNC(textureLod, samplerCubeArray, COMMA vec4 P COMMA float lod)
inline float textureLod(sampler1DShadow sampler, vec3 P, float lod) { return {}; }
inline float textureLod(sampler2DShadow sampler, vec3 P, float lod) { return {}; }
inline float textureLod(sampler1DArrayShadow sampler, vec3 P, float lod) { return {}; }

SAMPLEFUNC(textureLodOffset, sampler1D, COMMA float P COMMA float lod COMMA int offset)
SAMPLEFUNC(textureLodOffset, sampler2D, COMMA vec2 P COMMA float lod COMMA ivec2 offset)
SAMPLEFUNC(textureLodOffset, sampler3D, COMMA vec3 P COMMA float lod COMMA ivec3 offset)
SAMPLEFUNC(textureLodOffset, sampler1DArray, COMMA vec2 P COMMA float lod COMMA int offset)
SAMPLEFUNC(textureLodOffset, sampler2DArray, COMMA vec3 P COMMA float lod COMMA ivec2 offset)
inline float textureLodOffset(sampler1DShadow sampler, vec3 P, float lod, int offset) { return {}; }
inline float textureLodOffset(sampler2DShadow sampler, vec3 P, float lod, ivec2 offset) { return {}; }
inline float textureLodOffset(sampler1DArrayShadow sampler, vec3 P, float lod, int offset) { return {}; }

SAMPLEFUNC(textureProjLod, sampler1D, COMMA vec2 P COMMA float lod)
SAMPLEFUNC(textureProjLod, sampler1D, COMMA vec4 P COMMA float lod)
SAMPLEFUNC(textureProjLod, sampler2D, COMMA vec3 P COMMA float lod)
SAMPLEFUNC(textureProjLod, sampler2D, COMMA vec4 P COMMA float lod)
SAMPLEFUNC(textureProjLod, sampler3D, COMMA vec4 P COMMA float lod)
inline float textureProjLod(sampler1DShadow sampler, vec4 P, float lod) { return {}; }
inline float textureProjLod(sampler2DShadow sampler, vec4 P, float lod) { return {}; }

SAMPLEFUNC(textureProjLodOffset, sampler1D, COMMA vec2 P COMMA float lod COMMA int offset)
SAMPLEFUNC(textureProjLodOffset, sampler1D, COMMA vec4 P COMMA float lod COMMA int offset)
SAMPLEFUNC(textureProjLodOffset, sampler2D, COMMA vec3 P COMMA float lod COMMA ivec2 offset)
SAMPLEFUNC(textureProjLodOffset, sampler2D, COMMA vec4 P COMMA float lod COMMA ivec2 offset)
SAMPLEFUNC(textureProjLodOffset, sampler3D, COMMA vec4 P COMMA float lod COMMA ivec3 offset)
inline float textureProjLodOffset(sampler1DShadow sampler, vec4 P, float lod, int offset) { return {}; }
inline float textureProjLodOffset(sampler2DShadow sampler, vec4 P, float lod, ivec2 offset) { return {}; }

SAMPLEFUNC(textureProj, sampler1D, COMMA vec2 P COMMA float bias = .0f)
SAMPLEFUNC(textureProj, sampler1D, COMMA vec4 P COMMA float bias = .0f)
SAMPLEFUNC(textureProj, sampler2D, COMMA vec3 P COMMA float bias = .0f)
SAMPLEFUNC(textureProj, sampler2D, COMMA vec4 P COMMA float bias = .0f)
SAMPLEFUNC(textureProj, sampler3D, COMMA vec4 P COMMA float bias = .0f)
SAMPLEFUNC(textureProj, sampler2DRect, COMMA vec3 P)
SAMPLEFUNC(textureProj, sampler2DRect, COMMA vec4 P)
inline float textureProj(sampler1DShadow sampler, vec4 P, float bias = .0f) { return {}; }
inline float textureProj(sampler2DShadow sampler, vec4 P, float bias = .0f) { return {}; }
inline float textureProj(sampler2DRectShadow sampler, vec4 P) { return {}; }

SAMPLEFUNC(textureOffset, sampler1D, COMMA float P COMMA int offset COMMA float bias = .0f)
SAMPLEFUNC(textureOffset, sampler2D, COMMA vec2 P COMMA ivec2 offset COMMA float bias = .0f)
SAMPLEFUNC(textureOffset, sampler3D, COMMA vec3 P COMMA ivec3 offset COMMA float bias = .0f)
SAMPLEFUNC(textureOffset, sampler1DArray, COMMA vec2 P COMMA int offset COMMA float bias = .0f)
SAMPLEFUNC(textureOffset, sampler2DArray, COMMA vec3 P COMMA ivec2 offset COMMA float bias = .0f)
SAMPLEFUNC(textureOffset, sampler2DRect, COMMA vec2 P COMMA ivec2 offset)
inline float textureOffset(sampler1DShadow sampler, vec3 P, int offset, float bias = .0f) { return {}; } // ... why does this take in a vec3???
inline float textureOffset(sampler2DShadow sampler, vec3 P, ivec2 offset, float bias = .0f) { return {}; }
inline float textureOffset(sampler1DArrayShadow sampler, vec3 P, int offset, float bias = .0f) { return {}; }
inline float textureOffset(sampler2DArrayShadow sampler, vec4 P, ivec2 offset, float bias = .0f) { return {}; }
inline float textureOffset(sampler2DRectShadow sampler, vec3 P, ivec2 offset) { return {}; }

SAMPLEFUNC(textureProjGrad, sampler1D, COMMA vec2 P COMMA float dPdx COMMA float dPdy)
SAMPLEFUNC(textureProjGrad, sampler1D, COMMA vec4 P COMMA float dPdx COMMA float dPdy)
SAMPLEFUNC(textureProjGrad, sampler2D, COMMA vec3 P COMMA vec2 dPdx COMMA vec2 dPdy)
SAMPLEFUNC(textureProjGrad, sampler2D, COMMA vec4 P COMMA vec2 dPdx COMMA vec2 dPdy)
SAMPLEFUNC(textureProjGrad, sampler3D, COMMA vec4 P COMMA vec3 dPdx COMMA vec3 dPdy)
SAMPLEFUNC(textureProjGrad, sampler2DRect, COMMA vec3 P COMMA vec2 dPdx COMMA vec2 dPdy)
SAMPLEFUNC(textureProjGrad, sampler2DRect, COMMA vec4 P COMMA vec2 dPdx COMMA vec2 dPdy)
inline float textureProjGrad(sampler1DShadow sampler, vec4 P, float dPdx, float dPdy) { return {}; }
inline float textureProjGrad(sampler2DShadow sampler, vec4 P, vec2 dPdx, vec2 dPdy) { return {}; }
inline float textureProjGrad(sampler2DRectShadow sampler, vec4 P, vec2 dPdx, vec2 dPdy) { return {}; }

SAMPLEFUNC(textureProjGradOffset, sampler1D, COMMA vec2 P COMMA float dPdx COMMA float dPdy COMMA int offset)
SAMPLEFUNC(textureProjGradOffset, sampler1D, COMMA vec4 P COMMA float dPdx COMMA float dPdy COMMA int offset)
SAMPLEFUNC(textureProjGradOffset, sampler2D, COMMA vec3 P COMMA vec2 dPdx COMMA vec2 dPdy COMMA ivec2 offset)
SAMPLEFUNC(textureProjGradOffset, sampler2D, COMMA vec4 P COMMA vec2 dPdx COMMA vec2 dPdy COMMA ivec2 offset)
SAMPLEFUNC(textureProjGradOffset, sampler3D, COMMA vec4 P COMMA vec3 dPdx COMMA vec3 dPdy COMMA ivec3 offset)
SAMPLEFUNC(textureProjGradOffset, sampler2DRect, COMMA vec3 P COMMA vec2 dPdx COMMA vec2 dPdy COMMA ivec2 offset)
SAMPLEFUNC(textureProjGradOffset, sampler2DRect, COMMA vec4 P COMMA vec2 dPdx COMMA vec2 dPdy COMMA ivec2 offset)
inline float textureProjGradOffset(sampler1DShadow sampler, vec4 P, float dPdx, float dPdy, int offset) { return {}; }
inline float textureProjGradOffset(sampler2DShadow sampler, vec4 P, vec2 dPdx, vec2 dPdy, ivec2 offset) { return {}; }
inline float textureProjGradOffset(sampler2DRectShadow sampler, vec4 P, vec2 dPdx, vec2 dPdy, ivec2 offset) { return {}; }

SAMPLEFUNC(textureProjOffset, sampler1D, COMMA vec2 P COMMA int offset COMMA float bias = .0f)
SAMPLEFUNC(textureProjOffset, sampler1D, COMMA vec4 P COMMA int offset COMMA float bias = .0f)
SAMPLEFUNC(textureProjOffset, sampler2D, COMMA vec3 P COMMA ivec2 offset COMMA float bias = .0f)
SAMPLEFUNC(textureProjOffset, sampler2D, COMMA vec4 P COMMA ivec2 offset COMMA float bias = .0f)
SAMPLEFUNC(textureProjOffset, sampler3D, COMMA vec4 P COMMA ivec3 offset COMMA float bias = .0f)
SAMPLEFUNC(textureProjOffset, sampler2DRect, COMMA vec3 P COMMA ivec2 offset)
SAMPLEFUNC(textureProjOffset, sampler2DRect, COMMA vec4 P COMMA ivec2 offset)
inline float textureProjOffset(sampler1DShadow sampler, vec4 P, int offset, float bias = .0f) { return {}; }
inline float textureProjOffset(sampler2DShadow sampler, vec4 P, ivec2 offset, float bias = .0f) { return {}; }
inline float textureProjOffset(sampler2DRectShadow sampler, vec4 P, ivec2 offset) { return {}; }

TEXFUNC(vec2 textureQueryLod, sampler1D, COMMA float P)
TEXFUNC(vec2 textureQueryLod, sampler2D, COMMA vec2 P)
TEXFUNC(vec2 textureQueryLod, sampler3D, COMMA vec3 P)
TEXFUNC(vec2 textureQueryLod, samplerCube, COMMA vec3 P)
TEXFUNC(vec2 textureQueryLod, sampler1DArray, COMMA float P)
TEXFUNC(vec2 textureQueryLod, sampler2DArray, COMMA vec2 P)
TEXFUNC(vec2 textureQueryLod, samplerCubeArray, COMMA vec3 P)
inline vec2 textureQueryLod(sampler1DShadow sampler, float P) { return {}; } // ... why does this take in a vec3???
inline vec2 textureQueryLod(sampler2DShadow sampler, vec2 P) { return {}; }
inline vec2 textureQueryLod(samplerCubeShadow sampler, vec3 P) { return {}; }
inline vec2 textureQueryLod(sampler1DArrayShadow sampler, float P) { return {}; }
inline vec2 textureQueryLod(sampler2DArrayShadow sampler, vec2 P) { return {}; }
inline vec2 textureQueryLod(samplerCubeArrayShadow sampler, vec3 P) { return {}; }

#undef COMMA
#undef SAMPLEFUNC
#undef TEXFUNC
#undef MIPPABLE
#undef UNMIPPABLE
#undef MIPPABLE_SHADOW

struct Target {
    GLuint obj, level, layer, type;
    Target() : obj(0) {}
    template<GLenum target>
    Target(const Texture<target>& t) : obj(t), level(t.level), layer(t.layer), type(t.target) { }
    operator int() { return obj; }
    bool operator !=(const Target& other) {
        return obj != other.obj;
    }
};

struct DepthTarget {
    GLuint obj, level, layer, type;
    template<GLenum target>
    DepthTarget(const Texture<target>& t) : obj(t), level(t.level), layer(t.layer), type(t.target) { }
    operator int() { return obj; }
    bool operator !=(const DepthTarget& other) {
        return obj != other.obj;
    }
};

struct UBO {
    GLuint obj;
    UBO(const Buffer& t) : obj(t) {}
    operator int() { return obj; };
    bool operator!=(const UBO& other) {
        return obj != other.obj;
    }
};
struct SSBO {
    GLuint obj;
    SSBO(const Buffer& t) : obj(t) {}
    operator int() { return obj; };
    bool operator!=(const SSBO& other) {
        return obj != other.obj;
    }
};

template<typename T>
struct Attribute {
    GLuint obj, stride, offset, type;
    bool normalized;
    Attribute(const Buffer& b, int stride, int offset = 0, GLuint type = -1, bool normalized = false)
        : obj(b), stride(stride), offset(offset), type(type), normalized(normalized)
    {
        if (this->type == -1) {
            if constexpr (glsl::same<glsl::Field<T>, float>)
                this->type = GL_FLOAT;
            else if constexpr (glsl::same<glsl::Field<T>, int>)
                this->type = GL_INT;
            else if constexpr (glsl::same<glsl::Field<T>, uint>)
                this->type = GL_UNSIGNED_INT;
            else
                printf("vertex attribute type not given and couldn't be deduced from T in Attribute<T>\n");
        }
    }

    operator int() { return obj; }
    bool operator!=(const Attribute& other) {
        return obj != other.obj || stride != other.stride || offset != other.offset || type != other.type || normalized != other.normalized;
    }
};
