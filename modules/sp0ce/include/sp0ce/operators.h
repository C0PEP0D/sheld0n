#ifndef SP0CE_GEOMETRY_H
#define SP0CE_GEOMETRY_H
#pragma once

#include <cmath> // sqrt
#include <numeric> // inner_product

namespace sp0ce {

template<unsigned int Dim>
double dot(const double* pA, const double* pB) {
    return std::inner_product(pA, pA + Dim, pB, 0.0);
}

double cross2d(const double* pA, const double* pB) {
    return pA[0] * pB[1] - pA[1] * pB[0];
}

template<typename tSpaceVector>
tSpaceVector cross2d(const double w, const double* pB) {
    return tSpaceVector({
        -w*pB[1],
        w*pB[0]
    });
}

template<typename tSpaceVector>
tSpaceVector cross2d(const double* pA, const double w) {
    return tSpaceVector({
        pA[1]*w,
        -pA[0]*w
    });
}

template<typename tSpaceVector>
tSpaceVector cross3d(const double* pA, const double* pB) {
    return tSpaceVector({
        pA[1] * pB[2] - pA[2] * pB[1],
        pA[2] * pB[0] - pA[0] * pB[2],
        pA[0] * pB[1] - pA[1] * pB[0]
    });
}

template<unsigned int Dim>
double norm2(const double* pA) {
    return std::sqrt(dot<Dim>(pA, pA));
}

}

#endif
