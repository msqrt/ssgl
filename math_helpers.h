#pragma once

#include "inline_glsl.h"

inline glsl_global const float pi = 3.14159265358979323f;

// see Song Ho Ahns page for derivations and details
inline glsl_function mat4 perspective(float fov_rad, float width_over_height, float near_plane = .1f, float far_plane = 10.f) {
    mat4 result = mat4(1.f);
    result[0].x = 1.f / (width_over_height * tan(fov_rad*.5f));
    result[1].y = 1.f / tan(fov_rad * .5f);
    result[2].zw = vec2(-(far_plane + near_plane) / (far_plane - near_plane), -1.f);
    result[3].zw = vec2(-2.f * far_plane * near_plane / (far_plane - near_plane), .0f);
    return result;
}
inline glsl_function mat4 ortho(float size, float width_over_height, float near_plane = .0f, float far_plane = 10.f) {
    mat4 result = mat4(1.f);
    result[0].x = 1.f / (width_over_height * size * .5f);
    result[1].y = 1.f / (size * .5f);
    result[2].z = -2.f / (far_plane - near_plane);
    result[3].z = -(far_plane + near_plane) / (far_plane - near_plane);
    return result;
}
inline glsl_function mat4 lookAt(vec3 camera_position, vec3 camera_target, vec3 up = vec3(.0f, 1.f, .0f)) {
    mat4 result = mat4(1.f);
    result[2].xyz = normalize(camera_position - camera_target);
    result[0].xyz = normalize(cross(up, result[2].xyz));
    result[1].xyz = cross(result[2].xyz, result[0].xyz);
    result[3].xyz = camera_position;
    return result;
}

// Jarzynski and Olano, 2020
static glsl_global uint rnd_seed = 0;
inline glsl_function uint rnd_uint() {
    uint x = rnd_seed;
    rnd_seed = rnd_seed * 747796405u + 2891336453u;
    return ((x >> ((x >> 28u) + 4u)) ^ x) * 277803737u;
}
inline glsl_function float rnd() {
    return float(rnd_uint())/float(0xffffffffu);
}
inline glsl_function void srnd(uint seed) {
    rnd_seed = seed; rnd();
}

// Duff, 2017
inline glsl_function mat3 basis(vec3 n){
    float sign = uintBitsToFloat((floatBitsToUint(n.z)&(1u<<31u))|floatBitsToUint(1.f));
    const float a = -1.0f / (sign + n.z);
    const float b = n.x * n.y * a;
    return mat3(
        vec3(1.0f + sign * n.x * n.x * a, sign * b, -sign * n.x),
        vec3(b, sign + n.y * n.y * a, -n.y),
        n);
}

// as per the sRGB standard
inline glsl_function vec3 srgb_to_linear(vec3 x) {
    return mix(x / 12.92f, pow((x + .055f) / 1.055f, vec3(2.4f)), step(.04045f, x));
}

inline glsl_function vec3 linear_to_srgb(vec3 x) {
    return mix(x * 12.92f, pow(x, vec3(1.f/2.4f))*1.055f - .055f, step(.0031308f, x));
}

// convert floating points to uints and back, preserving order.
// mostly useful for performing atomicMax/Min on floats (map float to sortable uint -> uint atomic -> map result back to float).
inline glsl_function uint convert_sortable(float f) {
    uint result = ~floatBitsToUint(f);
    return result ^ (0x7fffffff * (result >> 31));
}

inline glsl_function float convert_sortable(uint f) {
    return uintBitsToFloat(~(f ^ (0x7fffffff * (f >> 31))));
}