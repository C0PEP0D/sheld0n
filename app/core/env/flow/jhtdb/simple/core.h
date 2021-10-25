#ifndef C0P_CORE_ENV_FLOW_JHTDB_SIMPLE_CORE_H
#define C0P_CORE_ENV_FLOW_JHTDB_SIMPLE_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
// Lib includes
#include "fl0w/jhtdb.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/jhtdb/simple/prop.h"

namespace c0p {

using TypeFlowJhtdbSimple = fl0w::JHTDB<TypeSpaceVector, TypeSpaceMatrix, TypeRef>;

template<typename TypeParameters>
class FlowJhtdbSimple : public TypeFlowJhtdbSimple {
    public:
        using Type = TypeFlowJhtdbSimple;
    public:
        TypeParameters parameters;
    public:
        FlowJhtdbSimple() : Type() {
            *sAuthtoken = parameters.authtoken;
            Type::selectDataset(parameters.dataset);
        }

        void init(const TypeScalar& t) {
        }
        
        void update(const TypeScalar& t) {
        }

        void prepare(const TypeContainer<TypeSpaceVector>& positions, const TypeScalar& t) {
            Type::prepareVelocities(positions, t);
            Type::prepareJacobians(positions, t);
        }

        void info() const {
            std::string separation(" -------------------- ");
            std::string space(" = ");
            std::cout << separation << "JHTDB Simple FLOW" << std::endl;
            // Numerical parameters
            std::cout << "dataset" << space << *Type::sDataset << std::endl;
        }

};

}

#endif
