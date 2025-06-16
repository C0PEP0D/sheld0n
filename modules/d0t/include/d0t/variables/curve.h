#ifndef D0T_VARIABLES_CURVE_H
#define D0T_VARIABLES_CURVE_H
#pragma once

// std includes
#include <memory> // shared_ptr
#include <vector>
// other modules includes
#include "p0l/lagrange.h"
#include "p0l/polynome.h"
#include "m0sh/non_uniform.h"
#include "s0s/gradient_descent.h"
// module includes
#include "d0t/variable.h"

// TODO: compute length using integration

namespace d0t {

template<typename _tVariableMember, unsigned int _Density, bool _IsClosed, unsigned int _InterpolationOrder>
class VariableCurve : public VariableGroupDynamic<_tVariableMember> {
	public:
		using tBase = VariableGroupDynamic<_tVariableMember>;
	public:
		template<int _Size> using tVector = typename tBase::tVector<_Size>;
		template<typename... Args> using tView = typename tBase::tView<Args...>;
		using tStateVectorDynamic = typename tBase::tStateVectorDynamic;
		using tBase::MinSize;
		using tVariableMember = typename tBase::tVariableMember;
		using tVariableMeta = typename tBase::tVariableMeta;
	public:
		constexpr static unsigned int VariableMemberSize = tVariableMember::Size;
		constexpr static unsigned int Dim = tVariableMember::Dim;
		using tSpaceVector = typename tVariableMember::tSpaceVector;
	public:
		constexpr static double Density = _Density;
		constexpr static bool IsClosed = _IsClosed;
		constexpr static unsigned int InterpolationOrder = _InterpolationOrder;
	public:
		using tScalar = tVector<1>;
		using tMesh = m0sh::NonUniform<tScalar, tView, 1>;
	
	public:
		static tView<tSpaceVector> position(const double* pState, const unsigned int index) {
			return tView<tSpaceVector>(tBase::state(pState, index));
		}

		static const tSpaceVector cPosition(const double* pState, const unsigned int index) {
			return tView<const tSpaceVector>(tBase::cState(pState, index));
		}

	public:
		static std::vector<tStateVectorDynamic> cStateInterpolationPolynome(const double* pState, const unsigned int stateSize, const double s) { // TODO: minimize the stateScalars computation
			// interpolation data
			std::vector<tStateVectorDynamic> states(tBase::groupSize(stateSize), tStateVectorDynamic(VariableMemberSize));
			for(unsigned int index = 0; index < tBase::groupSize(stateSize); index++) {
				states[index] = tView<const tStateVectorDynamic>(tBase::cState(pState, index), VariableMemberSize, 1);
			}
			// axes
			std::vector<std::vector<double>> axes(1, std::vector<double>(tBase::groupSize(stateSize) + int(IsClosed)));
			double length = 0.0;
			axes[0][0] = 0.0;
			for(unsigned int index = 1; index < tBase::groupSize(stateSize); index++){
				const tSpaceVector x1 = cPosition(pState, index);
				const tSpaceVector x0 = cPosition(pState, index - 1);
				length += (x1 - x0).norm();
				axes[0][index] = length;
			}
			if(IsClosed) {
				const tSpaceVector x1 = cPosition(pState, 0);
				const tSpaceVector x0 = cPosition(pState, tBase::groupSize(stateSize) - 1);
				length += (x1 - x0).norm();
				axes[0][tBase::groupSize(stateSize)] = length;
			}
			for(unsigned int index = 1; index < axes[0].size(); index++) {
				axes[0][index] /= length;
			}
			// interpolate for each coordinates
			return p0l::lagrange::interpolationMeshPoint<tMesh, tStateVectorDynamic>(axes.data(), states.data(), tStateVectorDynamic::Zero(VariableMemberSize), &s, InterpolationOrder, IsClosed);
		}
	
		static tStateVectorDynamic cStateInterpolated(const double* pState, const unsigned int stateSize, const double s) { // TODO: minimize the stateScalars computation
			const std::vector<tStateVectorDynamic> interpolationPolynome = cStateInterpolationPolynome(pState, stateSize, s);
			return p0l::polynome::evaluation(interpolationPolynome.data(), interpolationPolynome.size(), s);
		}
		
		static tSpaceVector cPositionInterpolated(const double* pState, const unsigned int stateSize, const double s) {
			return tVariableMember::cPosition(cStateInterpolated(pState, stateSize, s).data());
		}
		
		static const tSpaceVector cTangentInterpolated(const double* pState, const unsigned int stateSize, const double s) {
			std::vector<tStateVectorDynamic> interpolationPolynome = cStateInterpolationPolynome(pState, stateSize, s);
			p0l::polynome::differentiate(interpolationPolynome);
			const tSpaceVector positionDerivative = tVariableMember::cPosition(p0l::polynome::evaluation(interpolationPolynome.data(), interpolationPolynome.size(), s).data());
			return positionDerivative / positionDerivative.norm();
		}
		
		static const tSpaceVector cNormalInterpolated(const double* pState, const unsigned int stateSize, const double p_s) {
			const tSpaceVector tangent = cTangentInterpolated(pState, stateSize, p_s);
			return tSpaceVector({tangent[1], -tangent[0]}); // TODO: Careful this only works in 2D ...
		}

		static const tSpaceVector cCurvatureInterpolated(const double* pState, const unsigned int stateSize, const double s) {
			std::vector<tStateVectorDynamic> interpolationPolynome = cStateInterpolationPolynome(pState, stateSize, s);
			// tangent
			p0l::polynome::differentiate(interpolationPolynome);
			const tSpaceVector positionDerivative = tVariableMember::cPosition(p0l::polynome::evaluation(interpolationPolynome.data(), interpolationPolynome.size(), s).data());
			// curvature (should be colinear to normal)
			p0l::polynome::differentiate(interpolationPolynome);
			return tVariableMember::cPosition(p0l::polynome::evaluation(interpolationPolynome.data(), interpolationPolynome.size(), s).data()) / positionDerivative.norm();
		}

	public:
		static double cS(const double* pState, const unsigned int stateSize, const unsigned int memberIndex) { // TODO: compute length using integral
			if (memberIndex > 0) {
				double lengthIndex = 0.0;
				double length = 0.0;
				for(std::size_t index = 1; index < tBase::groupSize(stateSize); index++){ 
					const tSpaceVector x1 = cPosition(pState, index);
					const tSpaceVector x0 = cPosition(pState, index - 1);
					length += (x1 - x0).norm();
					if (index == memberIndex) {
						lengthIndex = length;
					}
				}
				if(IsClosed) {
					const tSpaceVector x1 = cPosition(pState, 0);
					const tSpaceVector x0 = cPosition(pState, tBase::groupSize(stateSize) - 1);
					length += (x1 - x0).norm();
				}
				return lengthIndex / length;
			} else {
				return 0.0;
			}
		}

		static double cClosestS(const double* pState, const unsigned int stateSize, const double* pX, const double s0) { // TODO: deal with s0 = NAN -> find closest s0 with closest to polygon
			const std::vector<tStateVectorDynamic> stateInterpolationPolynome = cStateInterpolationPolynome(pState, stateSize, s0);
			// compute position polynomes
			std::vector<std::vector<tScalar>> positionPolynomes(Dim, std::vector<double>(stateInterpolationPolynome.size()));
			for (unsigned int j = 0; j < stateInterpolationPolynome.size(); ++j) {
				const tSpaceVector position = tVariableMember::cPosition(stateInterpolationPolynome[j].data());
				for (unsigned int i = 0; i < Dim; ++i) {
					positionPolynomes[i][j] = position[i];
				}
			}
			for (unsigned int i = 0; i < Dim; ++i) {
				p0l::polynome::substract(positionPolynomes[i], pX[i]);
			}
			// compute distance polynome
			std::vector<tScalar> squaredDistancePolynome = positionPolynomes[0];
			p0l::polynome::multiply(squaredDistancePolynome, positionPolynomes[0].data(), positionPolynomes[0].size(), 0.0);
			for (unsigned int i = 1; i < Dim; ++i) {
				std::vector<tScalar> subPolynome = positionPolynomes[i];
				p0l::polynome::multiply(subPolynome, positionPolynomes[i].data(), positionPolynomes[0].size(), 0.0);
				// add 
				p0l::polynome::add(squaredDistancePolynome, subPolynome.data(), subPolynome.size(), 0.0);
			}
			// compute gradient
			p0l::polynome::differentiate(squaredDistancePolynome);
			// just solve
			tScalar s(s0);
			s0s::SolverGradientDescent<tScalar, tView>::solve(
				[&squaredDistancePolynome](const double* pS, const unsigned int sSize){ return p0l::polynome::evaluation(squaredDistancePolynome.data(), squaredDistancePolynome.size(), *pS); },
				s.data(),
				1,
				1e-6 // TODO: tolerance should be a numeric parameter
			);
			return s;
		}
	
		static double cLength(const double* pState, const unsigned int stateSize) { // TODO: compute length using integral
			double length = 0.0;
			for(std::size_t index = 1; index < tBase::groupSize(stateSize); index++){ 
				const tSpaceVector x1 = cPosition(pState, index);
				const tSpaceVector x0 = cPosition(pState, index - 1);
				length += (x1 - x0).norm();
			}
			if(IsClosed) {
				const tSpaceVector x1 = cPosition(pState, 0);
				const tSpaceVector x0 = cPosition(pState, tBase::groupSize(stateSize) - 1);
				length += (x1 - x0).norm();
			}
			return length;
		}
		
	public:
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int stateIndex) {
			tBase::_constrain(stateArray, t, stateIndex);
			//input
			std::vector<double>& _state = stateArray[stateIndex];
			// interpolation data
			std::vector<tStateVectorDynamic> states(tBase::groupSize(_state.size()), tStateVectorDynamic(VariableMemberSize));
			for(unsigned int index = 0; index < tBase::groupSize(_state.size()); index++) {
				states[index] = tView<const tStateVectorDynamic>(tBase::cState(_state.data(), index), VariableMemberSize, 1);
			}
			// axes
			std::vector<std::vector<double>> axes(1, std::vector<double>(tBase::groupSize(_state.size()) + int(IsClosed)));
			double length = 0.0;
			axes[0][0] = 0.0;
			for(unsigned int index = 1; index < tBase::groupSize(_state.size()); index++){
				const tSpaceVector x1 = cPosition(_state.data(), index);
				const tSpaceVector x0 = cPosition(_state.data(), index - 1);
				length += (x1 - x0).norm();
				axes[0][index] = length;
			}
			if(IsClosed) {
				const tSpaceVector x1 = cPosition(_state.data(), 0);
				const tSpaceVector x0 = cPosition(_state.data(), tBase::groupSize(_state.size()) - 1);
				length += (x1 - x0).norm();
				axes[0][tBase::groupSize(_state.size())] = length;
			}
			for(unsigned int index = 1; index < axes[0].size(); index++) {
				axes[0][index] /= length;
			}
			// update size
			const unsigned int newSize = std::max((unsigned int)(std::ceil(length * Density) + int(!IsClosed)), InterpolationOrder + 1);
			const double newDs = 1.0 / (newSize - int(!IsClosed));
			// manage data
			const int difference = newSize - tBase::groupSize(_state.size());
			if(difference < 0) {
				for(int i = -1; i >= difference; i--) {
					tBase::popBackMember(_state);
				}
			} else if(difference > 0) {
				for(int i = 0; i < difference; i++) {
					tBase::pushBackMember(_state);
				}
			}
			// interpolation
			std::vector<unsigned int> memberIndexs(newSize);
			std::iota(memberIndexs.begin(), memberIndexs.end(), 0);
			std::for_each(std::execution::par_unseq, memberIndexs.cbegin(), memberIndexs.cend(), [&_state, axes, states, newDs](const unsigned int& memberIndex){
				const double s = memberIndex * newDs;
				std::vector<tStateVectorDynamic> interpolationPolynome = p0l::lagrange::interpolationMeshPoint<tMesh, tStateVectorDynamic>(axes.data(), states.data(), tStateVectorDynamic::Zero(VariableMemberSize), &s, InterpolationOrder, IsClosed);
				tView<tStateVectorDynamic>(tBase::state(_state.data(), memberIndex), VariableMemberSize) = p0l::polynome::evaluation(interpolationPolynome.data(), interpolationPolynome.size(), s);
			});
		}
};

}

#endif
