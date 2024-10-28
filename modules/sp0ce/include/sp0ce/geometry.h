#ifndef SP0CE_GEOMETRY_H
#define SP0CE_GEOMETRY_H
#pragma once

#include <cmath> // sqrt, NAN, isnan
#include <numeric> // inner_product
#include <vector>

namespace sp0ce {

// vector operations

template<unsigned int Dim>
double dot(const double* pA, const double* pB) {
    return std::inner_product(pA, pA + Dim, pB, 0.0);
}

// template<typename tSpaceVector>
// tSpaceVector dot(const tSpaceVector* pBasis, const double* pA) {
    // tSpaceVector b;
    // for (unsigned int index = 0; index < tSpaceVector::SizeAtCompileTime; index++) {
        // b[index] = dot<tSpaceVector::SizeAtCompileTime>(pBasis[index].data(), pA);
    // }
    // return b;
// }

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

// intersections

template<typename tSpaceVector, template<typename...> typename tView>
tSpaceVector lineLine2DIntersection(const double* pA0, const double* pA1, const double* pB0, const double* pB1) {
	const tSpaceVector x = tView<const tSpaceVector>(pB0) - tView<const tSpaceVector>(pA0);
	const tSpaceVector dA = tView<const tSpaceVector>(pA1) - tView<const tSpaceVector>(pA0);
	const tSpaceVector dB = tView<const tSpaceVector>(pB1) - tView<const tSpaceVector>(pB0);
	const double dACrossDB = cross2d(dA.data(), dB.data());
	if (dACrossDB != 0.0) {
		const double xCrossDB = cross2d(x.data(), dB.data());
		return tView<const tSpaceVector>(pA0) + dA * xCrossDB / dACrossDB;
	} else {
		return tSpaceVector({NAN, NAN}); // Lines are parallel.
	}
}

template<typename tSpaceVector, template<typename...> typename tView>
tSpaceVector segmentSegment2DIntersection(const double* pA0, const double* pA1, const double* pB0, const double* pB1) {
	const tSpaceVector intersection = lineLine2DIntersection<tSpaceVector, tView>(pA0, pA1, pB0, pB1);
	if (std::isnan(intersection[0])) {
		return intersection; // Lines are parallel.
	} else {
		const tSpaceVector iA = intersection - tView<const tSpaceVector>(pA0);
		const tSpaceVector iB = intersection - tView<const tSpaceVector>(pB0);
		const tSpaceVector dA = tView<const tSpaceVector>(pA1) - tView<const tSpaceVector>(pA0);
		const tSpaceVector dB = tView<const tSpaceVector>(pB1) - tView<const tSpaceVector>(pB0);
		const double iADotDA = dot<tSpaceVector::SizeAtCompileTime>(iA.data(), dA.data());
		const double iBDotDB = dot<tSpaceVector::SizeAtCompileTime>(iB.data(), dB.data());
		if (((iADotDA >= 0) && (iADotDA) < dot<tSpaceVector::SizeAtCompileTime>(dA.data(), dA.data())) && ((iBDotDB >= 0) && (iBDotDB) < dot<tSpaceVector::SizeAtCompileTime>(dB.data(), dB.data()))) {
			return intersection;
		} else {
			return tSpaceVector({NAN, NAN}); // Intersection point is not within segments.
		}
	}
}

template<typename tSpaceVector, template<typename...> typename tView>
tSpaceVector raySegment2DIntersection(const double* pRayOrigin, const double* pRayDirection, const double* pSegmentPoint0, const double* pSegmentPoint1) {
	const tSpaceVector rayPoint = tView<const tSpaceVector>(pRayOrigin) + tView<const tSpaceVector>(pRayDirection);
	const tSpaceVector intersection = lineLine2DIntersection<tSpaceVector, tView>(pRayOrigin, rayPoint.data(), pSegmentPoint0, pSegmentPoint1);
	if (std::isnan(intersection[0])) {
		return intersection; // the ray is parallel to segment
	} else {
		const tSpaceVector rayOriginToIntersection = intersection - tView<const tSpaceVector>(pRayOrigin);
		const tSpaceVector segmentPoint0ToIntersection = intersection - tView<const tSpaceVector>(pSegmentPoint0);
		const tSpaceVector dSegment = tView<const tSpaceVector>(pSegmentPoint1) - tView<const tSpaceVector>(pSegmentPoint0);
		const double rayOriginToIntersectionDotRayDirection = dot<tSpaceVector::SizeAtCompileTime>(rayOriginToIntersection.data(), pRayDirection);
		const double segmentPoint0ToIntersectionDotDSegment = dot<tSpaceVector::SizeAtCompileTime>(segmentPoint0ToIntersection.data(), dSegment.data());
		if ((rayOriginToIntersectionDotRayDirection >= 0) && ((segmentPoint0ToIntersectionDotDSegment >= 0) && (segmentPoint0ToIntersectionDotDSegment) < dot<tSpaceVector::SizeAtCompileTime>(dSegment.data(), dSegment.data()))) {
			return intersection;
		} else {
			return tSpaceVector({NAN, NAN}); // the intersection point is not on the right side of the ray.
		}
	}
}

template<typename tSpaceVector, template<typename...> typename tView>
tSpaceVector lineSegment2DIntersection(const double* pLinePoint0, const double* pLinePoint1, const double* pSegmentPoint0, const double* pSegmentPoint1) {
	const tSpaceVector intersection = lineLine2DIntersection<tSpaceVector, tView>(pLinePoint0, pLinePoint1, pSegmentPoint0, pSegmentPoint1);
	if (std::isnan(intersection[0])) {
		return intersection; // the line is parallel to segment
	} else {
		const tSpaceVector segmentPoint0ToIntersection = intersection - tView<const tSpaceVector>(pSegmentPoint0);
		const tSpaceVector dSegment = tView<const tSpaceVector>(pSegmentPoint1) - tView<const tSpaceVector>(pSegmentPoint0);
		const double segmentPoint0ToIntersectionDotDSegment = dot<tSpaceVector::SizeAtCompileTime>(segmentPoint0ToIntersection.data(), dSegment.data());
		if ((segmentPoint0ToIntersectionDotDSegment >= 0) && ((segmentPoint0ToIntersectionDotDSegment) < dot<tSpaceVector::SizeAtCompileTime>(dSegment.data(), dSegment.data()))) {
			return intersection;
		} else {
			return tSpaceVector({NAN, NAN}); // the intersection point is not on the segment.
		}
	}
}

template<typename tSpaceVector>
struct PolygonIntersection {
	tSpaceVector point;
	unsigned int aIndex;
	unsigned int bIndex;
};

template<typename tSpaceVector, template<typename...> typename tView, bool IsClosed>
std::vector<PolygonIntersection<tSpaceVector>> polygon2DIntersections(const double* pA, const unsigned int size) {
	std::vector<PolygonIntersection<tSpaceVector>> intersections;
	for(unsigned int aIndex = 0; aIndex < size - tSpaceVector::SizeAtCompileTime; aIndex += tSpaceVector::SizeAtCompileTime) {
		for(unsigned int bIndex = aIndex + 2 * tSpaceVector::SizeAtCompileTime; bIndex < size - tSpaceVector::SizeAtCompileTime; bIndex += tSpaceVector::SizeAtCompileTime) {
			const tSpaceVector intersection = segmentSegment2DIntersection<tSpaceVector, tView>(pA[aIndex], pA[aIndex + tSpaceVector::SizeAtCompileTime], pA[bIndex], pA[bIndex + tSpaceVector::SizeAtCompileTime]);
			if(not std::isnan(intersection[0])) {
				intersections.push_back({intersection, aIndex/tSpaceVector::SizeAtCompileTime, bIndex/tSpaceVector::SizeAtCompileTime});
			}
		}
		if(IsClosed && aIndex < size - 2 * tSpaceVector::SizeAtCompileTime) {
			const tSpaceVector intersection = segmentSegment2DIntersection<tSpaceVector, tView>(pA[aIndex], pA[aIndex + tSpaceVector::SizeAtCompileTime], pA[size - tSpaceVector::SizeAtCompileTime], pA[0]);
			if(not std::isnan(intersection[0])) {
				intersections.push_back({intersection, aIndex/tSpaceVector::SizeAtCompileTime, (size - tSpaceVector::SizeAtCompileTime)/tSpaceVector::SizeAtCompileTime});
			}
		}
	}
	return intersections;
}

template<typename tSpaceVector, template<typename...> typename tView, bool IsClosedA, bool IsClosedB>
std::vector<PolygonIntersection<tSpaceVector>> polygon2DIntersections(const double* pA, unsigned int sizeA, const double* pB, unsigned int sizeB) {
	std::vector<PolygonIntersection<tSpaceVector>> intersections;
	for(unsigned int aIndex = 0; aIndex < sizeA - tSpaceVector::SizeAtCompileTime; aIndex += tSpaceVector::SizeAtCompileTime) {
		for(unsigned int bIndex = 0; bIndex < sizeB - tSpaceVector::SizeAtCompileTime; bIndex += tSpaceVector::SizeAtCompileTime) {
			const tSpaceVector intersection = segmentSegment2DIntersection<tSpaceVector, tView>(pA[aIndex], pA[aIndex + tSpaceVector::SizeAtCompileTime], pB[bIndex], pB[bIndex + tSpaceVector::SizeAtCompileTime]);
			if(not std::isnan(intersection[0])) {
				intersections.push_back({intersection, aIndex/tSpaceVector::SizeAtCompileTime, bIndex/tSpaceVector::SizeAtCompileTime});
			}
		}
		if(IsClosedB) {
			const tSpaceVector intersection = segmentSegment2DIntersection<tSpaceVector, tView>(pA[aIndex], pA[aIndex + tSpaceVector::SizeAtCompileTime], pB[sizeB - tSpaceVector::SizeAtCompileTime], pB[0]);
			if(not std::isnan(intersection[0])) {
				intersections.push_back({intersection, aIndex/tSpaceVector::SizeAtCompileTime, (sizeB - tSpaceVector::SizeAtCompileTime)/tSpaceVector::SizeAtCompileTime});
			}
		}
	}
	if (IsClosedA) {
		for(unsigned int bIndex = 0; bIndex < sizeB - tSpaceVector::SizeAtCompileTime; bIndex++) {
			const tSpaceVector intersection = segmentSegment2DIntersection<tSpaceVector, tView>(pA[sizeA - tSpaceVector::SizeAtCompileTime], pA[0], pB[bIndex], pB[bIndex + tSpaceVector::SizeAtCompileTime]);
			if(not std::isnan(intersection[0])) {
				intersections.push_back({intersection, (sizeA - tSpaceVector::SizeAtCompileTime)/tSpaceVector::SizeAtCompileTime, bIndex/tSpaceVector::SizeAtCompileTime});
			}
		}
		if(IsClosedB) {
			const tSpaceVector intersection = segmentSegment2DIntersection<tSpaceVector, tView>(pA[sizeA - tSpaceVector::SizeAtCompileTime], pA[0], pB[sizeB - tSpaceVector::SizeAtCompileTime], pB[0]);
			if(not std::isnan(intersection[0])) {
				intersections.push_back({intersection, (sizeA - tSpaceVector::SizeAtCompileTime)/tSpaceVector::SizeAtCompileTime, (sizeB - tSpaceVector::SizeAtCompileTime)/tSpaceVector::SizeAtCompileTime});
			}
		}
	}
	return intersections;
}

}

#endif
