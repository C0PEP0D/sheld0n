#ifndef C0P_CORE_ENV_FLOW_KINEMATIC_SIMPLE_CORE_H
#define C0P_CORE_ENV_FLOW_KINEMATIC_SIMPLE_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
// Lib includes
#include "fl0w/kinematic.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/kinematic/simple/prop.h"

namespace c0p {

using TypeFlowKinematicSimple = fl0w::kinematic::Kinematic<TypeSpaceVector, TypeSpaceMatrix, TypeRef, TypeContainer>;

template<typename TypeParameters>
class BaseFlowKinematicSimple {
    public:
        using Type = TypeFlowKinematicSimple;
        std::shared_ptr<Type> sData; // Fluid

        TypeParameters parameters;

        BaseFlowKinematicSimple() {
            sData = std::make_shared<Type>();
            sData->sRandomGenerator->setSeed(parameters.seed);
            *sData->sNk = parameters.nk; // number of fourier modes
            *sData->sK0 = parameters.k0; // Komogorov constant
            sData->createFromDissipationRate(parameters.nu, parameters.eps, parameters.l);
            sData->sOGen->lambda = parameters.lambda;
            sData->init();
        }

        void init(const TypeScalar& t) {
        }
        
        void update(const TypeScalar& t) {
        }

        void info() const {
            std::string separation(" -------------------- ");
            std::string space(" = ");
            std::cout << separation << "KINEMATIC FLOW" << std::endl;
            // Numerical parameters
            std::cout << "seed" << space << parameters.seed << std::endl;
            std::cout << "nk" << space << *sData->sNk << std::endl;
            // Physical parameters
            std::cout << "eta" << space << sData->eta << std::endl;
            std::cout << "tauEta" << space << sData->tauEta << std::endl;
            std::cout << "uEta" << space << sData->uEta << std::endl;
        }

};

}

#endif
