#ifndef SP0CE_GEOMETRY_H
#define SP0CE_GEOMETRY_H
#pragma once

#include <cmath> // sqrt, fmod
#include <numeric> // inner_product

namespace sp0ce {

template<unsigned int Dim>
double dot(const double* pA, const double* pB) {
	return std::inner_product(pA, pA + Dim, pB, 0.0);
}

double cross2d(const double* pA, const double* pB) {
	return pA[0] * pB[1] - pA[1] * pB[0];
}

template<typename tVector>
tVector cross2d(const double w, const double* pB) {
	return tVector({
		-w*pB[1],
		w*pB[0]
	});
}

template<typename tVector>
tVector cross2d(const double* pA, const double w) {
	return tVector({
		pA[1]*w,
		-pA[0]*w
	});
}

template<typename tVector>
tVector cross3d(const double* pA, const double* pB) {
	return tVector({
		pA[1] * pB[2] - pA[2] * pB[1],
		pA[2] * pB[0] - pA[0] * pB[2],
		pA[0] * pB[1] - pA[1] * pB[0]
	});
}

template<unsigned int Dim>
double norm2(const double* pA) {
	return std::sqrt(dot<Dim>(pA, pA));
}

template<typename tVector>
tVector xToPeriodic(const double* pX, const double* pCenter, const double* pSize) {
	const unsigned int Dim = tVector::RowsAtCompileTime;
	// compute periodic x
	tVector x;
	for(std::size_t i = 0; i < Dim; ++i) {
		x[i] = std::fmod(pX[i] - pCenter[i] - 0.5 * size[i], pSize[i]);
		if (x[i] < 0.0) {
			x[i] += pSize[i];
		}
		x[i] += pCenter[i] + 0.5 * pSize[i];
	}
	return x;
}

template<typename tVector, template<typename ...> typename tView>
tVector abPeriodic(const double* pA, const double* pB, const double* pCenter, const double* pSize) {
	const tVector a = xToPeriodic(pA, pCenter, pSize);
	const tVector b = xToPeriodic(pB, pCenter, pSize);
	const tVector ab = b - a;
	//  minimum image distance
	const unsigned int Dim = tVector::RowsAtCompileTime;
	for(std::size_t i = 0; i < Dim; ++i) {
		if (ab[i] > 0.5 * pSize[i]) {
            ab[i] -= pSize[i];
        } else if (ab[i] < -0.5 * pSize[i]) {
            ab[i] += pSize[i];
        }
	}
	return ab;
}

}

#endif
