#ifndef D0T_EQUATIONS_G_H
#define D0T_EQUATIONS_G_H
#pragma once

// std includes
#include <memory> // shared_ptr
#include <vector>
// module includes
#include "d0t/equation.h"

namespace d0t {

template<typename _tVariableBorder, typename _tFlow, double _LocalBurningVelocity>
class EquationG : public Equation<_tVariableBorder> {
	public:
		// base
		using tVariableBorder = typename Equation<_tVariableBorder>::tVariable;
		using tFlow = _tFlow;
		constexpr static double LocalBurningVelocity = _LocalBurningVelocity;
		// derived
		template<typename... Args> using tView = typename tVariableBorder::tView<Args...>;
		using tStateVectorDynamic = typename tVariableBorder::tStateVectorDynamic;
		using tSpaceVector = typename tVariableBorder::tSpaceVector;
	public:
		static std::vector<std::vector<double>> stateTemporalDerivative(const std::vector<std::vector<double>>& states, const double t) {
			std::vector<std::vector<double>> dStates(states.size());
			for (unsigned int index = 0; index < states.size(); ++index) {
				dStates[index].resize(states[index].size(), 0.0);
			}
			for (unsigned int curveIndex = 0; curveIndex < tVariableBorder::groupNumber(states.size()); ++curveIndex) {
				// create member indexs
				std::vector<unsigned int> memberIndexs(tVariableBorder::tCurve::groupSize(tVariableBorder::cState(states, curveIndex).size()));
				std::iota(memberIndexs.begin(), memberIndexs.end(), 0);
				// apply sub equation to each member of the group
				std::for_each(std::execution::par_unseq, memberIndexs.cbegin(), memberIndexs.cend(), [curveIndex, &dStates, states, t](const unsigned int memberIndex){
					// get data
					const tView<const typename tVariableBorder::tCurve::tVariableMember::tStateVectorStatic> memberState(tVariableBorder::tCurve::cState(tVariableBorder::cState(states, curveIndex).data(), memberIndex));
					tView<typename tVariableBorder::tCurve::tVariableMember::tStateVectorStatic> dMemberState(tVariableBorder::tCurve::state(tVariableBorder::state(dStates, curveIndex).data(), memberIndex));
					const tView<const tSpaceVector> memberPosition = tVariableBorder::tCurve::tVariableMember::cPosition(memberState.data());
					tView<tSpaceVector> dMemberPosition = tVariableBorder::tCurve::tVariableMember::position(dMemberState.data());
					// equation
					dMemberPosition = tFlow::getVelocity(memberPosition.data(), t) + LocalBurningVelocity * tVariableBorder::tCurve::cNormalInterpolated(tVariableBorder::cState(states, curveIndex).data(), tVariableBorder::cState(states, curveIndex).size(), tVariableBorder::tCurve::cS(tVariableBorder::cState(states, curveIndex).data(), tVariableBorder::cState(states, curveIndex).size(), memberIndex));
				});
			}
			return dStates;
		}
};

}

#endif
