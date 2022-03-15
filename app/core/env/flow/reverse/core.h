#ifndef C0P_CORE_ENV_FLOW_REVERSE_CORE_H
#define C0P_CORE_ENV_FLOW_REVERSE_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
// Lib includes
#include "fl0w/flow.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/reverse/prop.h"

namespace c0p {

template<typename TypeFlow>
using TypeFlowReverse = fl0w::FlowReverse<TypeFlow>;

template<typename TypeParameters, typename TypeFlow>
class BaseFlowReverse : public TypeFlowReverse<TypeFlow> {
    public:
        using Type = TypeFlowReverse<TypeFlow>;
    public:
        TypeParameters parameters;
    public:
        BaseFlowReverse() : Type(parameters.time) {
        	Type::time = parameters.time;
        }

        void init(const TypeScalar& t) {
        	Type::init(Type::time - t);
        }
        
        void update(const TypeScalar& t) {
        	Type::update(Type::time - t);
        }

        void prepare(const TypeContainer<TypeSpaceVector>& positions, const TypeScalar& t) {
        	Type::prepare(positions, Type::time - t);
        }

        void info() const {
            std::string separation(" -------------------- ");
            std::string space(" = ");
            std::cout << separation << "Flow Reverse" << std::endl;
        }

};

}

#endif
