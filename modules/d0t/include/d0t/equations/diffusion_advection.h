#ifndef D0T_EQUATIONS_DIFFUSION_ADVECTION_H
#define D0T_EQUATIONS_DIFFUSION_ADVECTION_H
#pragma once

// std includes
#include <memory> // shared_ptr
#include <vector>
// module includes
#include "d0t/equation.h"
#include "p0l/polynome.h"

namespace d0t {

template<typename _tVariableDomain, typename _tFlow, double _Diffusivity>
class EquationDiffusionAdvection : public Equation<_tVariableDomain> {
    public:
        // base
        using tVariableDomain = typename Equation<_tVariableDomain>::tVariable;
        using tFlow = _tFlow;
        constexpr static double Diffusivity = _Diffusivity;
        // derived
        template<typename... Args> using tView = typename tVariableDomain::tView<Args...>;
        using tStateVectorDynamic = typename tVariableDomain::tStateVectorDynamic;
        using tSpaceVector = typename tVariableDomain::tSpaceVector;
    public:
        static std::vector<std::vector<double>> stateTemporalDerivative(const std::vector<std::vector<double>>& states, const double t) {
            std::vector<std::vector<double>> dStates(states.size());
            for (unsigned int index = 0; index < states.size(); ++index) {
                dStates[index].resize(states[index].size(), 0.0);
            }
            for (unsigned int curveIndex = 0; curveIndex < tVariableDomain::groupNumber(states.size()); ++curveIndex) {
                // create member indexs
                std::vector<unsigned int> memberIndexs(tVariableDomain::tCurve::groupSize(tVariableDomain::cState(states, curveIndex).size()));
                std::iota(memberIndexs.begin(), memberIndexs.end(), 0);
                // apply sub equation to each member of the group
                std::for_each(std::execution::par_unseq, memberIndexs.cbegin(), memberIndexs.cend(), [curveIndex, &dStates, states, t](const unsigned int memberIndex) {
                    // get data
                    const tView<const typename tVariableDomain::tCurve::tVariableMember::tStateVectorStatic> memberState(tVariableDomain::tCurve::cState(tVariableDomain::cState(states, curveIndex).data(), memberIndex));
                    tView<typename tVariableDomain::tCurve::tVariableMember::tStateVectorStatic> dMemberState(tVariableDomain::tCurve::state(tVariableDomain::state(dStates, curveIndex).data(), memberIndex));
                    const tView<const tSpaceVector> memberPosition = tVariableDomain::tCurve::tVariableMember::cPosition(memberState.data());
                    tView<tSpaceVector> dMemberPosition = tVariableDomain::tCurve::tVariableMember::position(dMemberState.data());
                    // equation
                    const double s = tVariableDomain::tCurve::cS(tVariableDomain::cState(states, curveIndex).data(), tVariableDomain::cState(states, curveIndex).size(), memberIndex);
                    const tSpaceVector x = tVariableDomain::tCurve::cPosition(tVariableDomain::cState(states, curveIndex).data(), memberIndex);
                    const tSpaceVector n = tVariableDomain::tCurve::cNormalInterpolated(tVariableDomain::cState(states, curveIndex).data(), tVariableDomain::cState(states, curveIndex).size(), s);
                    const tSpaceVector k = tVariableDomain::tCurve::cCurvatureInterpolated(tVariableDomain::cState(states, curveIndex).data(), tVariableDomain::cState(states, curveIndex).size(), s);
                    std::vector<double> scalarInterpolationPolynome = tVariableDomain::cScalarInterpolationPolynome(states, x.data(), n.data());
                    p0l::polynome::differentiate(scalarInterpolationPolynome);
                    const double dScalar = p0l::polynome::evaluation(scalarInterpolationPolynome.data(), scalarInterpolationPolynome.size(), 0.0);
                    p0l::polynome::differentiate(scalarInterpolationPolynome);
                    const double d2Scalar = p0l::polynome::evaluation(scalarInterpolationPolynome.data(), scalarInterpolationPolynome.size(), 0.0);
                    if (dScalar != 0.0) { // TODO: deal properly with singularity
                        dMemberPosition = tFlow::getVelocity(memberPosition.data(), t) + Diffusivity * ((d2Scalar / dScalar) * n + k);
                    } else {
                        dMemberPosition = tFlow::getVelocity(memberPosition.data(), t) + Diffusivity * k;
                    }
                });
            }
            return dStates;
        }
};

}

#endif
