#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_ADD_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_ADD_CORE_H
#pragma once

// std includes
#include <execution>
// app includes
#include "core/init/objects/object/init/group/add/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitMember>
class InitInitGroupAdd : public InitInitInitDynamic<TypeObjectStep> {
    public:
        TypeParameters parameters;
    public:
        using InitInitInitDynamic<TypeObjectStep>::sObjectStep;
    public:
        InitInitGroupAdd(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitDynamic<TypeObjectStep>(p_sObjectStep) {
        }
    public:
        void operator()(std::vector<double>& state) override {
            for(unsigned int memberIndex = 0; memberIndex < parameters.nb; memberIndex++) {
                sObjectStep->addMember(state);
            }
        };
};

}

#endif
