#ifndef C0P_CORE_ENV_FLOW_TAYLOR_GREEN_VORTEX_SIMPLE_CORE_H
#define C0P_CORE_ENV_FLOW_TAYLOR_GREEN_VORTEX_SIMPLE_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
// Lib includes
#include "fl0w/taylor_green_vortex.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/taylor_green_vortex/simple/prop.h"

namespace c0p {

using TypeFlowTaylorGreenVortexSimple = fl0w::TaylorGreenVortex<TypeSpaceVector, TypeSpaceMatrix, TypeRef>;

template<typename TypeParameters>
class FlowTaylorGreenVortexSimple : public TypeFlowTaylorGreenVortexSimple {
    public:
        using Type = TypeFlowTaylorGreenVortexSimple;
    public:
        TypeParameters parameters;
    public:
        FlowTaylorGreenVortexSimple() {
        }

        void init(const TypeScalar& t) {
        }
        
        void update(const TypeScalar& t) {
        }

        void prepare(const TypeContainer<TypeSpaceVector>& positions, const TypeScalar& t) {
        }

        void info() const {
            std::string separation(" -------------------- ");
            std::string space(" = ");
            std::cout << separation << "TAYLOR GREEN VORTEX FLOW" << std::endl;
        }

};

}

#endif
