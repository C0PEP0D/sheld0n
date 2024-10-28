#ifndef D0T_VARIABLES_BORDER_H
#define D0T_VARIABLES_BORDER_H
#pragma once

// std includes
#include <memory> // shared_ptr
#include <vector>
// lib includes
#include "sp0ce/geometry.h"
// module includes
#include "d0t/variable.h"
#include "d0t/variables/curve.h"

namespace d0t {

template<typename _tVariableMember, double _Density, bool _IsClosed, unsigned int _InterpolationOrder>
class VariableBorder : public VariableGroups<VariableCurve<_tVariableMember, _Density, _IsClosed, _InterpolationOrder>> {
	public:
		using tBase = VariableGroups<
			VariableCurve<_tVariableMember, _Density, _IsClosed, _InterpolationOrder>
		>;
		// using tBase = VariableGroups<
		// 	VariableCurve<_tVariableMember, _Density, _IsClosed, _InterpolationOrder>, 
		// 	VariableGroupDynamic< VariableScalar<_tVariableMember::template tVector, _tVariableMember::template tView> > // TODO: continue that, keep track of s, TODO that remove inheritance ?
		// >;
	public:
		using tVariableGroup = typename tBase::tVariableGroup;
		using tVariableMeta = typename tBase::tVariableMeta;
		using tCurve = tVariableGroup;
	public:
		template<int _Size> using tVector = typename tVariableGroup::tVector<_Size>;
		   template<typename... Args> using tView = typename tVariableGroup::tView<Args...>;
		   using tStateVectorDynamic = typename tVariableGroup::tStateVectorDynamic;
		   using tVariableGroupMember = tVariableGroup::tVariableMember;
	   public:
		   constexpr static unsigned int Dim = tVariableGroup::Dim;
		   using tSpaceVector = typename tVariableGroup::tSpaceVector;
	   public:
		   constexpr static double Density = tVariableGroup::Density;
		   constexpr static bool IsClosed = tVariableGroup::IsClosed;
		   constexpr static unsigned int InterpolationOrder = tVariableGroup::InterpolationOrder;
	   public:
		   using tScalar = typename tVariableGroup::tScalar;
		using tMesh = typename tVariableGroup::tMesh;
	public:
		struct CurveSOutput {
			double borderS;
			unsigned int curveIndex;
			double borderCurveS0;
			double borderCurveS1;
			// actual output
			double curveS;
		};
	public:
		static CurveSOutput cCurveS(const std::vector<std::vector<double>>& states, const double s) { // TODO: better s0 computation (saving breakdowns)
			// interpolation data
			double length = 0.0;
			std::vector<double> s0(tBase::groupNumber(states.size()) + 1);
			for (unsigned int index = 0; index < tBase::groupNumber(states.size()); ++index) {
				s0[index] = length;
				length += tCurve::cLength(tBase::cState(states, index).data(), tBase::cState(states, index).size());
			}
			unsigned int curveIndex = tBase::groupNumber(states.size()) - 1;
			for (unsigned int index = 1; index < tBase::groupNumber(states.size()); ++index) {
				s0[index] /= length;
				if (s0[index] > s) {
					curveIndex = index - 1;
				}
			}
			s0[tBase::groupNumber(states.size())] = 1.0;
			// interpolate for each coordinates
			return {s, curveIndex, s0[curveIndex], s0[curveIndex + 1], (s0[curveIndex] - s) / (s0[curveIndex + 1] - s0[curveIndex])};
		}
	public:
		static void constrain(std::vector<std::vector<double>>& states) {
			tBase::_constrain(states);
			// TODO: checking **not self** intersections
			// checking **self** intersections
			for (int curveIndex = tBase::groupNumber(states.size()) - 1; curveIndex > -1; curveIndex--) {
				std::vector<std::vector<double>> curveStateBrokenDown = _breakDownCurve(tBase::cState(states, curveIndex));
				if (curveStateBrokenDown.size() > 1) {
					// update states
					tBase::eraseGroup(states, curveIndex);
					tBase::insertGroups(states, curveStateBrokenDown);
				}
			}
			// checking validity of curves
			std::vector<bool> isCurvePartValid(tBase::groupNumber(states.size()), true);
			std::vector<bool> isCurvePartChecked(tBase::groupNumber(states.size()), false);
			for (int curveIndex = tBase::groupNumber(states.size()) - 1; curveIndex > -1; curveIndex--) {
				if (not isCurvePartChecked[curveIndex]) {
					if (tCurve::groupSize(tBase::cState(states, curveIndex).size()) > InterpolationOrder) {
						// create a line
						const tSpaceVector lineOrigin = tCurve::cPositionInterpolated(tBase::cState(states, curveIndex).data(), tBase::cState(states, curveIndex).size(), 0.5);
						const tSpaceVector lineDirection = tCurve::cNormalInterpolated(tBase::cState(states, curveIndex).data(), tBase::cState(states, curveIndex).size(), 0.5);
						const tSpaceVector linePoint = lineOrigin + lineDirection;
						// find line intersections
						std::vector<tSpaceVector> lineIntersections;
						std::vector<unsigned int> lineIntersectionsSegmentIndex;
						std::vector<unsigned int> lineIntersectedCurvePartsIndex;
						for (unsigned int otherCurvePartIndex = 0; otherCurvePartIndex < tBase::groupNumber(states.size()); otherCurvePartIndex++) {
							for (unsigned int otherCurvePartPointIndex = 0; otherCurvePartPointIndex < tCurve::groupSize(tBase::cState(states, otherCurvePartIndex).size()) - 1; otherCurvePartPointIndex++) {
								const tSpaceVector intersection = sp0ce::lineSegment2DIntersection<tSpaceVector, tView>(lineOrigin.data(), linePoint.data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, otherCurvePartIndex).data(), otherCurvePartPointIndex)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, otherCurvePartIndex).data(), otherCurvePartPointIndex + 1)).data());
								   if (not std::isnan(intersection[0])) {
									   lineIntersections.push_back(intersection);
									   lineIntersectedCurvePartsIndex.push_back(otherCurvePartIndex);
									   lineIntersectionsSegmentIndex.push_back(otherCurvePartPointIndex);
								   }
							   }
							   if (IsClosed) {
								   const tSpaceVector intersection = sp0ce::lineSegment2DIntersection<tSpaceVector, tView>(lineOrigin.data(), linePoint.data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, otherCurvePartIndex).data(), tCurve::groupSize(tBase::cState(states, otherCurvePartIndex).size()) - 1)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, otherCurvePartIndex).data(), 0)).data());
								   if (not std::isnan(intersection[0])) {
									   lineIntersections.push_back(intersection);
									   lineIntersectedCurvePartsIndex.push_back(otherCurvePartIndex);
									   lineIntersectionsSegmentIndex.push_back(tCurve::groupSize(tBase::cState(states, otherCurvePartIndex).size()) - 1);
								   }
							   }
						}
						// sort line intersections
						std::vector<double> lineDots(lineIntersections.size());
						for (unsigned int intersectionIndex = 0; intersectionIndex < lineIntersections.size(); intersectionIndex++) {
							lineDots[intersectionIndex] = sp0ce::dot<tSpaceVector::SizeAtCompileTime>(tSpaceVector(lineIntersections[intersectionIndex] - lineOrigin).data(), lineDirection.data());
						}
						std::vector<unsigned int> lineIntersectionsSortedIndex(lineIntersections.size());
						std::iota(lineIntersectionsSortedIndex.begin(), lineIntersectionsSortedIndex.end(), 0);
						std::sort(lineIntersectionsSortedIndex.begin(), lineIntersectionsSortedIndex.end(), [&lineDots](unsigned int indexA, unsigned int indexB) {return lineDots[indexA] < lineDots[indexB];});
						// validity check
						bool hasValidityCheckStarted = false;
						bool previousValidSign;
						for (int unsortedIndex = lineIntersections.size() - 1; unsortedIndex > -1; unsortedIndex--) {
							const unsigned int sortedIndex = lineIntersectionsSortedIndex[unsortedIndex];
							const unsigned int otherCurvePartIndex = lineIntersectedCurvePartsIndex[sortedIndex];
							if (tCurve::groupSize(tBase::cState(states, otherCurvePartIndex).size()) > InterpolationOrder) {
								if (isCurvePartValid[otherCurvePartIndex]) {
									if (isCurvePartChecked[otherCurvePartIndex]) {
										if (hasValidityCheckStarted) {
											previousValidSign = not previousValidSign;
										} else {
											previousValidSign = std::signbit(1.0);
											hasValidityCheckStarted = true;
										}
									} else {
										const tSpaceVector intersection = lineIntersections[sortedIndex];
										const unsigned int otherCurvePartPointIndex = lineIntersectionsSegmentIndex[sortedIndex];
										const tSpaceVector segementDirection = tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, otherCurvePartIndex).data(), (otherCurvePartPointIndex + 1) % tCurve::groupSize(tBase::cState(states, otherCurvePartIndex).size()))) - tCurve::tVariableMember::cPosition(tCurve::cState(tBase::cState(states, otherCurvePartIndex).data(), otherCurvePartPointIndex)); // careful this is not normalized
										const tSpaceVector segmentNormal({segementDirection[1], -segementDirection[0]}); // careful this is not normalized
										const double segmentNormalDotLineDirection = sp0ce::dot<tSpaceVector::SizeAtCompileTime>(segmentNormal.data(), lineDirection.data());
										if (not hasValidityCheckStarted) {
											if(segmentNormalDotLineDirection >= 0.0) {
												previousValidSign = std::signbit(segmentNormalDotLineDirection);
												hasValidityCheckStarted = true;
											} else {
												isCurvePartValid[otherCurvePartIndex] = false;
											}
										} else {
											if (std::signbit(segmentNormalDotLineDirection) != previousValidSign) {
												previousValidSign = std::signbit(segmentNormalDotLineDirection);
											} else {
												isCurvePartValid[otherCurvePartIndex] = false;
											}
										}
										isCurvePartChecked[otherCurvePartIndex] = true;
									}
								}
							} else {
								isCurvePartValid[otherCurvePartIndex] = false;
								isCurvePartChecked[otherCurvePartIndex] = true;
							}
						}
					} else {
						isCurvePartValid[curveIndex] = false;
						isCurvePartChecked[curveIndex] = true;
					}
				}
			}
			// erase all non valid curves
			for (int curveIndex = tBase::groupNumber(states.size()) - 1; curveIndex > -1; curveIndex--) {
				if(not isCurvePartValid[curveIndex]) {
					tBase::eraseGroup(states, curveIndex);
				}
			}
		}

		static std::vector<std::vector<double>> _breakDownCurve(const std::vector<double>& curveState) {
			// computing first intersection
			tSpaceVector intersection = tSpaceVector::Constant(NAN);
			unsigned int aIndex = 0;
			unsigned int bIndex = 1;
			   for(aIndex = 0; std::isnan(intersection[0]) && aIndex < tCurve::groupSize(curveState.size()) - 1; aIndex++) {
				   for(bIndex = aIndex + 2; std::isnan(intersection[0]) && bIndex < tCurve::groupSize(curveState.size()) - 1; bIndex++) {
					   intersection = sp0ce::segmentSegment2DIntersection<tSpaceVector, tView>(tCurve::tVariableMember::cPosition(tCurve::cState(curveState.data(), aIndex)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(curveState.data(), aIndex + 1)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(curveState.data(), bIndex)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(curveState.data(), bIndex + 1)).data());
				   }
				   if(IsClosed && std::isnan(intersection[0]) && aIndex > 0 && aIndex < (tCurve::groupSize(curveState.size()) - 2)) {
					   bIndex = tCurve::groupSize(curveState.size()) - 1;
					   intersection = sp0ce::segmentSegment2DIntersection<tSpaceVector, tView>(tCurve::tVariableMember::cPosition(tCurve::cState(curveState.data(), aIndex)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(curveState.data(), aIndex + 1)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(curveState.data(), bIndex)).data(), tCurve::tVariableMember::cPosition(tCurve::cState(curveState.data(), 0)).data());
				   }
			   }
			   // breaking down the curve
			   if (not std::isnan(intersection[0])) {
				   aIndex -= 1;
				   bIndex -= 1;
				   // curve A
				   std::vector<double> curveStateA;
				   curveStateA.insert(curveStateA.end(), curveState.begin(), curveState.begin() + (aIndex + 1) * tCurve::tVariableMember::Size);
				   curveStateA.insert(curveStateA.end(), curveState.begin() + (bIndex + 1) * tCurve::tVariableMember::Size, curveState.end());
				   // curve B
				   std::vector<double> curveStateB;
				   curveStateB.insert(curveStateB.end(), curveState.begin() + (aIndex + 1) * tCurve::tVariableMember::Size, curveState.begin() + (bIndex + 1) * tCurve::tVariableMember::Size);
				   // recursion
				   std::vector<std::vector<double>> curveStatesA = _breakDownCurve(curveStateA);
				   std::vector<std::vector<double>> curveStatesB = _breakDownCurve(curveStateB);
				   //output
				   std::vector<std::vector<double>> output;
				   output.insert(output.end(), curveStatesA.begin(), curveStatesA.end());
				   output.insert(output.end(), curveStatesB.begin(), curveStatesB.end());
				   return output;
			   } else {
				   //output
				   return std::vector<std::vector<double>>(1, curveState);
			   }
		}
};

}

#endif
