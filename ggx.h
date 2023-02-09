#pragma once

#include "inline_glsl.h"

// Schlick, 1994, Fresnel, 1823
inline glsl_function float schlick_fresnel(float ior, vec3 out_dir, vec3 half_vector) {
    float R0 = (1.f - ior) / (1.f + ior);
    return mix(R0 * R0, 1.f, pow(1.f - abs(dot(out_dir, half_vector)), 5.f));
}

// Tokuyoshi, 2021
inline glsl_function float tokuyoshi_G1(vec3 v, vec3 half_vector, float alpha_x, float alpha_y) {
    if (dot(v, half_vector) < .0f) return .0f;
    return 2.f * abs(v.z) / (v.z + sqrt(alpha_x * alpha_x * v.x * v.x + alpha_y * alpha_y * v.y * v.y + v.z * v.z));
}

// Smith, 1967
inline glsl_function float smith_G1(vec3 v, vec3 half_vector, float alpha_x, float alpha_y) {
    if (dot(v, half_vector) < .0f) return .0f;
    const float lambda = .5f * (-1.f + sqrt(1.f + (alpha_x * alpha_x * v.x * v.x + alpha_y * alpha_y * v.y * v.y) / (v.z * v.z)));
    return 1.f / (1.f + lambda);
}

// Walter, 2007
inline glsl_function float D(vec3 n, float alpha_x, float alpha_y) {
    const float denom = (n.x * n.x) / (alpha_x * alpha_x) + (n.y * n.y) / (alpha_y * alpha_y) + n.z * n.z;
    return 1.f / (pi * alpha_x * alpha_y * denom * denom);
}

// Cook and Torrance, 1982
inline glsl_function float GGX(vec3 in_dir, vec3 out_dir, float alpha_x, float alpha_y, float ior) {
    const vec3 half_vector = normalize(in_dir + out_dir);
    const float fresnel = schlick_fresnel(ior, out_dir, half_vector);
    const float distribution = D(half_vector, alpha_x, alpha_y);
    const float view_mask = smith_G1(in_dir, half_vector, alpha_x, alpha_y);
    const float light_mask = smith_G1(out_dir, half_vector, alpha_x, alpha_y);
    const float normalization = 4.f * dot(in_dir, half_vector) * dot(out_dir, half_vector);
    return fresnel * distribution * view_mask * light_mask / normalization;
}

// Heitz, 2018
inline glsl_function vec3 sampleGGX(vec3 Ve, float alpha_x, float alpha_y, float U1, float U2) {
    vec3 Vh = normalize(vec3(alpha_x * Ve.x, alpha_y * Ve.y, Ve.z));
    float lensq = Vh.x * Vh.x + Vh.y * Vh.y;
    vec3 T1 = lensq > .0f ? vec3(-Vh.y, Vh.x, .0f) / sqrt(lensq) : vec3(1.f, 0.f, 0.f);
    vec3 T2 = cross(Vh, T1);
    float r = sqrt(U1);
    float phi = 2.f * pi * U2;
    float t1 = r * cos(phi);
    float t2 = r * sin(phi);
    float s = 0.5f * (1.0f + Vh.z);
    t2 = (1.0f - s) * sqrt(1.0f - t1 * t1) + s * t2;
    vec3 Nh = t1 * T1 + t2 * T2 + sqrt(max(.0f, 1.f - t1 * t1 - t2 * t2)) * Vh;
    vec3 Ne = normalize(vec3(alpha_x * Nh.x, alpha_y * Nh.y, max(.0f, Nh.z)));
    return Ne;
}

inline glsl_function float probGGX(vec3 Ve, vec3 Ne, float alpha_x, float alpha_y) {
    float dot_ = dot(Ve, Ne);
    if (dot_ <= .0f) return .0f;
    return tokuyoshi_G1(Ve, Ne, alpha_x, alpha_y) * D(Ne, alpha_x, alpha_y) / (4.f * dot_);
}
