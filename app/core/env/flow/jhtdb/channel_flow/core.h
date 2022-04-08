#ifndef C0P_CORE_ENV_FLOW_JHTDB_CHANNEL_FLOW_CORE_H
#define C0P_CORE_ENV_FLOW_JHTDB_CHANNEL_FLOW_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
// Lib includes
#include "fl0w/jhtdb/channel_flow.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/jhtdb/channel_flow/prop.h"

namespace c0p {

using TypeFlowJhtdbChannelFlow = fl0w::jhtdb::ChannelFlow<TypeSpaceVector, TypeSpaceMatrix, TypeRef>;

template<typename TypeParameters>
class BaseFlowJhtdbChannelFlow : public TypeFlowJhtdbChannelFlow {
    public:
        using Type = TypeFlowJhtdbChannelFlow;
    public:
        TypeParameters parameters;
    public:
        BaseFlowJhtdbChannelFlow() : Type() {
            *sAuthtoken = parameters.authtoken;
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
            std::cout << separation << "Flow JHTDB Channel flow" << std::endl;
            // Numerical parameters
            std::cout << "authorization token" << space << *Type::sAuthtoken << std::endl;
        }

};

}

#endif
