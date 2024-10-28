#ifndef D0T_EQUATIONS_ADVECTION_H
#define D0T_EQUATIONS_ADVECTION_H
#pragma once

// std includes
#include <memory> // shared_ptr
#include <vector>
// module includes
#include "d0t/equation.h"

namespace d0t {

template<typename _tVariable, typename _tFlow>
class EquationAdvection : public Equation<_tVariable> {
	public:
		// base
		using tVariable = typename Equation<_tVariable>::tVariable;
		using tFlow = _tFlow;
		// derived 0
		using tPosition = typename tVariable::tPosition;
		static constexpr auto statePosition = tVariable::statePosition;
		static constexpr auto cStatePosition = tVariable::cStatePosition;
		// derived 1
		template<typename... Args> using tView = typename tPosition::tView<Args...>;
		using tStateVectorDynamic = typename tPosition::tStateVectorDynamic;
		using tSpaceVector = typename tPosition::tSpaceVector;
	public:
        static tStateVectorDynamic stateTemporalDerivative(const double* pState, const unsigned int stateSize, const double t) {
            tStateVectorDynamic output = tStateVectorDynamic::Zero(tVariable::Size);
            tView<tSpaceVector> dX = tVariable::position(output.data());
            dX = tFlow::getVelocity(tVariable::cPosition(pState).data(), t);
            return output;
        }
    // public:
        // std::vector<tSpaceVector> positions(const double* pState) const {
            // return { tPosition::cGet(cStatePosition(pState)) };
        // }
};

}

#endif
