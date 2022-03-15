#ifndef C0P_CORE_ENV_FLOW_ANALYTIC_TAYLOR_GREEN_VORTEX_CORE_H
#define C0P_CORE_ENV_FLOW_ANALYTIC_TAYLOR_GREEN_VORTEX_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
// Lib includes
#include "fl0w/analytic/taylor_green_vortex.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/analytic/taylor_green_vortex/prop.h"

namespace c0p {

using TypeFlowAnalyticTaylorGreenVortex = fl0w::analytic::TaylorGreenVortex<TypeSpaceVector, TypeSpaceMatrix, TypeRef>;

template<typename TypeParameters>
class BaseFlowAnalyticTaylorGreenVortex : public TypeFlowAnalyticTaylorGreenVortex {
    public:
        using Type = TypeFlowAnalyticTaylorGreenVortex;
    public:
        TypeParameters parameters;
    public:
        BaseFlowAnalyticTaylorGreenVortex() {
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
            std::cout << separation << "Flow Analytic Taylor Green Vortex" << std::endl;
        }

};

}

#endif
