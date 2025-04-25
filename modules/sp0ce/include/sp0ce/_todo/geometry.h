#ifndef GEOMETRY_H
#define GEOMETRY_H
#pragma once

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <vector>

namespace geometry {

// Simple geometry

template<class T>
T normalized(const T& a) {
    T b = a;
    std::transform(std::begin(b), std::end(b), std::begin(b), std::bind(std::multiplies<double>(), std::placeholders::_1, 1.0/norm<T>(a)));
    return b;
}

template<class T>
const std::vector<T> orthonormalized(const std::vector<T>& basis) { // Gramm-Schmitt algorithm
    std::vector<T> b = basis;
    for (size_t i = 0; i < basis.size(); i++) {
        T proj(basis.size());
        std::fill(std::begin(proj), std::end(proj), 0.0);
        for(size_t j = 0; j < i; j++) {
            T singleProj(b[j].size());
            std::transform(std::begin(b[j]), std::end(b[j]), std::begin(singleProj), std::bind(std::multiplies<double>(), std::placeholders::_1, dot<T>(basis[i], b[j])));
        }
        std::transform(std::begin(basis[i]), std::end(basis[i]), std::begin(proj), std::begin(b[i]), std::minus<double>());
        b[i] = normalized<T>(b[i]);
    }
    return b;
}

template<class T>
std::vector<T> getRotatedBase(const T& axis, const double& angle) {
    using namespace std;
    const T e0 = {
        cos(angle) + pow(axis[0], 2) * (1 - cos(angle)),
        axis[1] * axis[0] * (1 - cos(angle)) + axis[2]*sin(angle),
        axis[2] * axis[0] * (1 - cos(angle)) - axis[1]*sin(angle)
    };
    const T e1 = {
        axis[0] * axis[1] * (1 - cos(angle)) - axis[2] * sin(angle),
        cos(angle) + pow(axis[1], 2) * (1 - cos(angle)),
        axis[2] * axis[1] * (1 - cos(angle)) + axis[0] * sin(angle)
    };
    const T e2 = {
        axis[0] * axis[2] * (1 - cos(angle)) + axis[1] * sin(angle),
        axis[1] * axis[2] * (1 - cos(angle)) - axis[0] * sin(angle),
        cos(angle) + pow(axis[2], 2) * (1 - cos(angle))
    };
    return {e0, e1, e2};
}

template<class T>
T rotate(const T& axis, const double& angle, const T& x) {
    using namespace std;
    const std::vector<T> base = getRotatedBase<T>(axis, angle);
    return base[0] * x[0] + base[1] * x[1] + base[2] * x[2];
}

// Surface and volume computation

template<class T>
double getTriangleSurface(const T& v0, const T& v1, const T& v2) {
    T diff(3);
    std::transform(std::begin(v1), std::end(v1), std::begin(v0), std::begin(diff), std::minus<double>());
    const double a = norm<T>(diff);
    std::transform(std::begin(v2), std::end(v2), std::begin(v1), std::begin(diff), std::minus<double>());
    const double b = norm<T>(diff);
    std::transform(std::begin(v0), std::end(v0), std::begin(v2), std::begin(diff), std::minus<double>());
    const double c = norm<T>(diff);
    const double p = 0.5 * (a + b + c);
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

template<class T>
double getTriangleSurface(const std::vector<T>& positions) {
    // TODO assert number of points
    return getTriangleSurface(positions[0], positions[1], positions[2]);
}

template<class T>
double getTetrahedreVolume(const T& v0, const T& v1, const T& v2, const T& v3) {
    const T x = v1 - v0;
    const T y = v2 - v0;
    const T z = v3 - v0;
    const double det = x[0]*y[1]*z[2] + x[1]*y[2]*z[0] + x[2]*y[0]*z[1] - x[2]*y[1]*z[0] - x[1]*y[0]*z[2] - x[0]*y[2]*z[1];
    return 1.0/6.0 * std::abs(det);
}

template<class T>
double getTetrahedreVolume(const std::vector<T>& positions) {
    // TODO assert number of points
    return getTetrahedreVolume(positions[0], positions[1], positions[2], positions[3]);
}

}

#endif
