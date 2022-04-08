#ifndef C0P_CORE_ENV_FLOW_JHTDB_FORCED_ISOTROPIC_TURBULENCE_CORE_H
#define C0P_CORE_ENV_FLOW_JHTDB_FORCED_ISOTROPIC_TURBULENCE_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
// Lib includes
#include "fl0w/jhtdb/forced_isotropic_turbulence.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/jhtdb/forced_isotropic_turbulence/prop.h"

namespace c0p {

using TypeFlowJhtdbForcedIsotropicTurbulence = fl0w::jhtdb::ForcedIsotropicTurbulence<TypeSpaceVector, TypeSpaceMatrix, TypeRef>;

template<typename TypeParameters>
class BaseFlowJhtdbForcedIsotropicTurbulence : public TypeFlowJhtdbForcedIsotropicTurbulence {
    public:
        using Type = TypeFlowJhtdbForcedIsotropicTurbulence;
    public:
        TypeParameters parameters;
    public:
        BaseFlowJhtdbForcedIsotropicTurbulence() : Type() {
            *Type::sAuthtoken = parameters.authtoken;
        }

        void init(const TypeScalar& t) {
        }
        
        void update(const TypeScalar& t) {
        }

        void prepare(const TypeContainer<TypeSpaceVector>& positions, const TypeScalar& t) {
            Type::prepareVelocities(positions, t);
            Type::prepareVelocityGradientss(positions, t);
        }

        void info() const {
            std::string separation(" -------------------- ");
            std::string space(" = ");
            std::cout << separation << "Flow JHTDB Forced isotropic turbulence" << std::endl;
            // Numerical parameters
            std::cout << "authorization token" << space << *Type::sAuthtoken << std::endl;
        }

};

}

#endif
