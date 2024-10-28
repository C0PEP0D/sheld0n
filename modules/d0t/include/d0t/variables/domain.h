#ifndef D0T_VARIABLES_DOMAIN_H
#define D0T_VARIABLES_DOMAIN_H
#pragma once

// std includes
#include <memory> // shared_ptr
#include <vector>
#include <algorithm> // lower_bound
// lib includes
#include "sp0ce/geometry.h"
#include "p0l/polynome.h"
// module includes
#include "d0t/variable.h"
#include "d0t/variables/border.h"
#include "d0t/variables/scalar.h"

namespace d0t {

template<typename _tVariableMember, double _Density, bool _IsClosed, unsigned int _CurveInterpolationOrder, unsigned int _ScalarInterpolationOrder>
class VariableDomain : public VariableGroups<
		VariableCurve<_tVariableMember, _Density, _IsClosed, _CurveInterpolationOrder>, 
		VariableGroupDynamic< VariableScalar<_tVariableMember::template tVector, _tVariableMember::template tView> >
	> {
	public:
		using tBase = VariableGroups<
			VariableCurve<_tVariableMember, _Density, _IsClosed, _CurveInterpolationOrder>, 
			VariableGroupDynamic< VariableScalar<_tVariableMember::template tVector, _tVariableMember::template tView> >
		>;
	public:
		using tBorder = VariableBorder<_tVariableMember, _Density, _IsClosed, _CurveInterpolationOrder>;
		using tVariableMeta = typename tBase::tVariableMeta;
		using tCurve = typename tBorder::tCurve;
	public:
		template<int _Size> using tVector = typename tBorder::tVector<_Size>;
		template<typename... Args> using tView = typename tBorder::tView<Args...>;
		using tStateVectorDynamic = typename tBorder::tStateVectorDynamic;
		using tVariableGroupMember = tBorder::tVariableGroupMember;
	public:
		constexpr static unsigned int Dim = tBorder::Dim;
		using tSpaceVector = typename tBorder::tSpaceVector;
	public:
		constexpr static double Density = tBorder::Density;
		constexpr static bool IsClosed = tBorder::IsClosed;
		constexpr static unsigned int CurveInterpolationOrder = tBorder::InterpolationOrder;
	public:
		using tMesh = tBorder::tMesh;
	public:
		constexpr static unsigned int ScalarInterpolationOrder = _ScalarInterpolationOrder;
	public:
		static std::vector<double> cScalarInterpolationPolynome(const std::vector<std::vector<double>>& states, const double* pX, const double* pN) {
			// create a line
			const tSpaceVector lineOrigin = tView<const tSpaceVector>(pX);
			const tSpaceVector lineDirection = tView<const tSpaceVector>(pN);
			const tSpaceVector linePoint = lineOrigin + lineDirection;
			// find line intersections
			std::vector<tSpaceVector> lineIntersections;
			std::vector<unsigned int> lineIntersectedCurveIndex;
			for (unsigned int curveIndex = 0; curveIndex < tBase::groupNumber(states.size()); curveIndex++) {
				for (unsigned int curvePointIndex = 0; curvePointIndex < tCurve::groupSize(tBase::cState(states, curveIndex).size()) - 1; curvePointIndex++) {
					const tSpaceVector intersection = sp0ce::lineSegment2DIntersection<tSpaceVector, tView>(lineOrigin.data(), linePoint.data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), curvePointIndex)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), curvePointIndex + 1)).data());
					if (not std::isnan(intersection[0])) {
						lineIntersections.push_back(intersection);
						lineIntersectedCurveIndex.push_back(curveIndex);
					}
				}
				if (IsClosed) {
					const tSpaceVector intersection = sp0ce::lineSegment2DIntersection<tSpaceVector, tView>(lineOrigin.data(), linePoint.data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), tCurve::groupSize(tBase::cState(states, curveIndex).size()) - 1)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), 0)).data());
					if (not std::isnan(intersection[0])) {
						lineIntersections.push_back(intersection);
						lineIntersectedCurveIndex.push_back(curveIndex);
					}
				}
			}
			if (lineIntersections.size() == 1) {
				return std::vector<double>(1, tBase::cStateMeta(states)[lineIntersectedCurveIndex.front()]);
			} else {
				// sort line intersections
				std::vector<double> lineDots(lineIntersections.size());
				for (unsigned int intersectionIndex = 0; intersectionIndex < lineIntersections.size(); intersectionIndex++) {
					lineDots[intersectionIndex] = sp0ce::dot<tSpaceVector::SizeAtCompileTime>(tSpaceVector(lineIntersections[intersectionIndex] - lineOrigin).data(), lineDirection.data());
				}
				std::vector<unsigned int> lineIntersectionsSortedIndex(lineIntersections.size());
				std::iota(lineIntersectionsSortedIndex.begin(), lineIntersectionsSortedIndex.end(), 0);
				std::sort(lineIntersectionsSortedIndex.begin(), lineIntersectionsSortedIndex.end(), [&lineDots](unsigned int indexA, unsigned int indexB) {return lineDots[indexA] < lineDots[indexB];});
				// init mesh data
				std::vector<double> scalars(lineIntersections.size());
				std::vector<std::vector<double>> axes(1, std::vector<double>(lineIntersections.size()));
				// compute polynome
				for (unsigned int unsortedIndex = 0; unsortedIndex < lineIntersections.size(); unsortedIndex++) {
					const unsigned int sortedIndex = lineIntersectionsSortedIndex[unsortedIndex];
					axes[0][unsortedIndex] = lineDots[sortedIndex];
					scalars[unsortedIndex] = tBase::cStateMeta(states)[lineIntersectedCurveIndex[sortedIndex]];
				}
				// INFO: careful here, the interpolation may fail if the axes are ill defined (for instance if there is a pair of equal values in axes)
				// interpolate for each coordinates
				return p0l::lagrange::interpolationMeshPoint<tMesh, double>(axes.data(), scalars.data(), 0.0, lineOrigin.data(), std::min(ScalarInterpolationOrder, (unsigned int)(lineIntersections.size() - 1)), false);
			}
		}

		static std::vector<tSpaceVector> cNormalInterpolationPolynome(const std::vector<std::vector<double>>& states, const double* pX, const double* pN) {
			// create a line
			const tSpaceVector lineOrigin = tView<const tSpaceVector>(pX);
			const tSpaceVector lineDirection = tView<const tSpaceVector>(pN);
			const tSpaceVector linePoint = lineOrigin + lineDirection;
			// find line intersections
			std::vector<tSpaceVector> lineIntersections;
			std::vector<tSpaceVector> lineIntersectedS0;
			std::vector<unsigned int> lineIntersectedCurveIndex;
			for (unsigned int curveIndex = 0; curveIndex < tBase::groupNumber(states.size()); curveIndex++) {
				for (unsigned int curvePointIndex = 0; curvePointIndex < tCurve::groupSize(tBase::cState(states, curveIndex).size()) - 1; curvePointIndex++) {
					const tSpaceVector intersection = sp0ce::lineSegment2DIntersection<tSpaceVector, tView>(lineOrigin.data(), linePoint.data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), curvePointIndex)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), curvePointIndex + 1)).data());
					if (not std::isnan(intersection[0])) {
						lineIntersections.push_back(intersection);
						lineIntersectedCurveIndex.push_back(curveIndex);
						// computing s0
						const tSpaceVector segment= tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), curvePointIndex + 1)) - tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), curvePointIndex));
						const double segmentNorm = segment.norm();
						const tSpaceVector segmentDirection = segment/segmentNorm;
						const double coef = (intersection - tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), curvePointIndex))).dot(segmentDirection) / segmentNorm;
						lineIntersectedS0.push_back(
							(1.0 - coef) * tCurve::cS(tBase::cState(states, curveIndex).data(), tBase::cState(states, curveIndex).size(), curvePointIndex) +
							coef * tCurve::cS(tBase::cState(states, curveIndex).data(), tBase::cState(states, curveIndex).size(), curvePointIndex + 1)
						);
					}
				}
				if (IsClosed) {
					const tSpaceVector intersection = sp0ce::lineSegment2DIntersection<tSpaceVector, tView>(lineOrigin.data(), linePoint.data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), tCurve::groupSize(tBase::cState(states, curveIndex).size()) - 1)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, curveIndex).data(), 0)).data());
					if (not std::isnan(intersection[0])) {
						lineIntersections.push_back(intersection);
						lineIntersectedCurveIndex.push_back(curveIndex);
					}
				}
			}
			if (lineIntersections.size() == 1) {
				return std::vector<double>(1, tBase::cStateMeta(states)[lineIntersectedCurveIndex.front()]);
			} else {
				// sort line intersections
				std::vector<double> lineDots(lineIntersections.size());
				for (unsigned int intersectionIndex = 0; intersectionIndex < lineIntersections.size(); intersectionIndex++) {
					lineDots[intersectionIndex] = sp0ce::dot<tSpaceVector::SizeAtCompileTime>(tSpaceVector(lineIntersections[intersectionIndex] - lineOrigin).data(), lineDirection.data());
				}
				std::vector<unsigned int> lineIntersectionsSortedIndex(lineIntersections.size());
				std::iota(lineIntersectionsSortedIndex.begin(), lineIntersectionsSortedIndex.end(), 0);
				std::sort(lineIntersectionsSortedIndex.begin(), lineIntersectionsSortedIndex.end(), [&lineDots](unsigned int indexA, unsigned int indexB) {return lineDots[indexA] < lineDots[indexB];});
				// init mesh data
				std::vector<tSpaceVector> normals(lineIntersections.size());
				std::vector<std::vector<double>> axes(1, std::vector<double>(lineIntersections.size()));
				// compute polynome
				for (unsigned int unsortedIndex = 0; unsortedIndex < lineIntersections.size(); unsortedIndex++) {
					const unsigned int sortedIndex = lineIntersectionsSortedIndex[unsortedIndex];
					axes[0][unsortedIndex] = lineDots[sortedIndex];
					normals[unsortedIndex] = tCurve::cNormalInterpolated(tBase::cState(states, lineIntersectedCurveIndex[sortedIndex]).data(), tBase::cState(states, lineIntersectedCurveIndex[sortedIndex]).size(), tCurve::cClosestS(tBase::cState(states, lineIntersectedCurveIndex[sortedIndex]).data(), tBase::cState(states, lineIntersectedCurveIndex[sortedIndex]).size(), lineIntersections[sortedIndex].data(), lineIntersectedS0[sortedIndex]));
				}
				// INFO: careful here, the interpolation may fail if the axes are ill defined (for instance if there is a pair of equal values in axes)
				// interpolate for each coordinates
				return p0l::lagrange::interpolationMeshPoint<tMesh, tSpaceVector>(axes.data(), normals.data(), 0.0, lineOrigin.data(), std::min(ScalarInterpolationOrder, (unsigned int)(lineIntersections.size() - 1)), false);
			}
		}
		
		static std::vector<tStateVectorDynamic> cStateInterpolationPolynome(const std::vector<std::vector<double>>& states, const double s, const double scalar) { // TODO: minimize the stateScalars computation
			// get separate isocontours
			//// init
			std::vector<std::vector<std::vector<double>>> isocontours; // TODO: AVOID DATA COPY USING POINTERS ?
			std::vector<double> isocontoursValues;
			//// getting isoscalars values
			unsigned int isocontourEndCurveIndex = 0;
			while(isocontourEndCurveIndex < tBase::groupNumber(states.size())) {
				const unsigned int isocontourBeginCurveIndex = isocontourEndCurveIndex;
				const double isocontourValue = tBase::cStateMeta(states)[isocontourBeginCurveIndex];
				// searching end of iso contour
				++isocontourEndCurveIndex;
				while(isocontourEndCurveIndex < tBase::groupNumber(states.size()) && tBase::cStateMeta(states)[isocontourEndCurveIndex] == isocontourValue) {
					++isocontourEndCurveIndex;
				}
				// copy data into iso contour data
				isocontours.emplace_back(std::vector<std::vector<double>>(1)); // 1 accounts for the meta state
				isocontours.back().insert(isocontours.back().end(), states.begin() + 1 + isocontourBeginCurveIndex, states.begin() + 1 + isocontourEndCurveIndex); // + 1 accounts for the meta state
				// save isocontour value
				isocontoursValues.emplace_back(isocontourValue);
			}
			// get start index (check p0l)
			unsigned int startIsocontourIndex = std::distance(isocontoursValues.begin(), std::lower_bound(isocontoursValues.begin(), isocontoursValues.end(), scalar));
			if(startIsocontourIndex <= (ScalarInterpolationOrder + 1)/2) {
				startIsocontourIndex = 0;
			} else {
				startIsocontourIndex -= (ScalarInterpolationOrder + 1)/2;
			}
			// compute polynome for each border
			std::vector<std::vector<tStateVectorDynamic>> isocontoursPolynomes(ScalarInterpolationOrder + 1);
			for (unsigned int isoContourIndex = 0; isoContourIndex < ScalarInterpolationOrder + 1; ++isoContourIndex) {
				typename tBorder::CurveSOutput curveSOutpout = tBorder::cCurveS(isocontours[startIsocontourIndex + isoContourIndex], s);
				// compute interpolation polynome
				isocontoursPolynomes[isoContourIndex] = tCurve::cStateInterpolationPolynome(tBorder::cState(isocontours[isoContourIndex], curveSOutpout.curveIndex).data(), tBorder::cState(isocontours[startIsocontourIndex + isoContourIndex], curveSOutpout.curveIndex).size(), curveSOutpout.curveS);
				// compute change of variable polynome
				std::vector<double> changeOfVariablePolynome = p0l::polynome::monome(1, 1.0, 0.0);
				p0l::polynome::substract(changeOfVariablePolynome, curveSOutpout.borderCurveS0);
				p0l::polynome::multiply(changeOfVariablePolynome, 1.0/(curveSOutpout.borderCurveS1 - curveSOutpout.borderCurveS0));
				// correct original polynome
				p0l::polynome::compose<tStateVectorDynamic, double>(isocontoursPolynomes[isoContourIndex], changeOfVariablePolynome.data(), changeOfVariablePolynome.size(), tStateVectorDynamic::Zero(tCurve::tVariableMember::Size));
				// TODO: RENAME S BY OFFSET OR COORDINATE, MAYBE DIFFER ORDER 1 FROM THE REST?
			}
			// compute polynome for each coefficient
			std::vector<std::vector<tStateVectorDynamic>> coeffsPolynomes(ScalarInterpolationOrder + 1);
			std::vector<std::vector<double>> isocontoursValuesReduced(1, std::vector<double>(isocontoursValues.begin() + startIsocontourIndex, isocontoursValues.begin() + startIsocontourIndex + ScalarInterpolationOrder + 1));
			for (unsigned int coeffIndex = 0; coeffIndex < ScalarInterpolationOrder + 1; ++coeffIndex) {
				std::vector<tStateVectorDynamic> coeffs(ScalarInterpolationOrder + 1);
				for (unsigned int polynomeIndex = 0; polynomeIndex < ScalarInterpolationOrder + 1; ++polynomeIndex) {
					coeffs[polynomeIndex] = isocontoursPolynomes[polynomeIndex][coeffIndex];
				}
				coeffsPolynomes[coeffIndex] = p0l::lagrange::interpolationMeshPoint<typename tCurve::tMesh, tStateVectorDynamic>(isocontoursValuesReduced.data(), coeffs.data(), tStateVectorDynamic::Zero(tCurve::tVariableMember::Size));
			}
			// compute 2D polynome
			std::vector<unsigned int> degreesOutput({0, 0});
			std::vector<tStateVectorDynamic> output(1, tStateVectorDynamic::Zero(tCurve::tVariableMember::Size));
			for (unsigned int i = 0; i < ScalarInterpolationOrder + 1; ++i) {
				for (unsigned int j = 0; j < ScalarInterpolationOrder + 1; ++j) {
					std::vector<tStateVectorDynamic> monome = p0l::polynome::multivariate::monome<tStateVectorDynamic>({i, j}, coeffsPolynomes[i][j], tStateVectorDynamic::Zero(tCurve::tVariableMember::Size));
					p0l::polynome::multivariate::add<tStateVectorDynamic, tStateVectorDynamic>(output, degreesOutput, monome.data(), {i, j}, tStateVectorDynamic::Zero(tCurve::tVariableMember::Size));
				}
			}
			return output;
		}

	public:
		static void constrain(std::vector<std::vector<double>>& states) {
			tVariableMeta::_constrain(states.front());
			// get separate isocontours
			//// init
			std::vector<std::vector<std::vector<double>>> isocontours; // TODO: AVOID DATA COPY USING POINTERS?
			std::vector<double> isocontoursValues;
			//// getting isoscalars values
			unsigned int isocontourEndCurveIndex = 0;
			while(isocontourEndCurveIndex < tBase::groupNumber(states.size())) {
				const unsigned int isocontourBeginCurveIndex = isocontourEndCurveIndex;
				const double isocontourValue = tBase::cStateMeta(states)[isocontourBeginCurveIndex];
				// searching end of iso contour
				++isocontourEndCurveIndex;
				while(isocontourEndCurveIndex < tBase::groupNumber(states.size()) && tBase::cStateMeta(states)[isocontourEndCurveIndex] == isocontourValue) {
					++isocontourEndCurveIndex;
				}
				// copy data into iso contour data
				isocontours.emplace_back(std::vector<std::vector<double>>(1)); // 1 accounts for the meta state
				isocontours.back().insert(isocontours.back().end(), states.begin() + 1 + isocontourBeginCurveIndex, states.begin() + 1 + isocontourEndCurveIndex); // + 1 accounts for the meta state
				// save isocontour value
				isocontoursValues.emplace_back(isocontourValue);
			}
			// constrain each borders
			for(unsigned int isocontourIndex = 0; isocontourIndex < isocontours.size(); ++isocontourIndex) {
				tBorder::constrain(isocontours[isocontourIndex]);
			}
			// TODO: add or remove interpolated borders based on density
			// updating data
			states.resize(1);
			tBase::stateMeta(states).clear();
			for(unsigned int isocontourIndex = 0; isocontourIndex < isocontours.size(); ++isocontourIndex) {
				for(unsigned int curveIndex = 1; curveIndex < isocontours[isocontourIndex].size(); ++curveIndex) { // + 1 accounts for the meta state
					states.emplace_back(isocontours[isocontourIndex][curveIndex]);
					tBase::stateMeta(states).emplace_back(isocontoursValues[isocontourIndex]);
				}
			}
		}
};

}

#endif
