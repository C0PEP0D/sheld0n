#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_STRAIN_RELATIVE_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_STRAIN_RELATIVE_CORE_H
#pragma once

// app includes
#include "core/init/objects/object/init/pair/strain_relative/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class InitInitPairStrainRelative : public InitInitInitStatic<TypeObjectStep> {
    public:
        TypeParameters parameters;
    public:
        using InitInitInitStatic<TypeObjectStep>::sObjectStep;
    public:
        InitInitPairStrainRelative(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitStatic<TypeObjectStep>(p_sObjectStep) {
        }
    public:
        void operator()(double* pState) override {
        	const TypeSpaceVector xA = sObjectStep->sAStep->cX(sObjectStep->cAState(pState));
        	const TypeSpaceMatrix velocityGradients = sObjectStep->sAStep->sFlow->getVelocityGradients(xA, 0.0);
        	const TypeSpaceMatrix symVelocityGradients = 0.5 * (velocityGradients + velocityGradients.transpose());

			Eigen::SelfAdjointEigenSolver<TypeSpaceMatrix> eigenSolver;
        	eigenSolver.compute(symVelocityGradients, Eigen::ComputeEigenvectors);

            sObjectStep->sBStep->x(sObjectStep->bState(pState)) = xA + eigenSolver.eigenvectors() * parameters.position;
        };
};

}

#endif
