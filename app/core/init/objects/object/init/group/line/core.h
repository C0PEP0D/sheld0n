#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_LINE_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_LINE_CORE_H
#pragma once

// std includes
#include <execution>
// app includes
#include "core/init/objects/object/init/group/line/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitMember>
class InitInitGroupLine : public InitInitInit<TypeObjectStep> {
    public:
        TypeParameters parameters;
    public:
        using InitInitInit<TypeObjectStep>::sObjectStep;
    public:
        InitInitGroupLine(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInit<TypeObjectStep>(p_sObjectStep) {
        }
    public:
        void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) override {
            std::for_each(std::execution::seq, sObjectStep->memberIndexs.cbegin(), sObjectStep->memberIndexs.cend(), [this, state](const unsigned int& memberIndex){ 
                sObjectStep->sMemberStep->x(sObjectStep->memberState(state, memberIndex)) = parameters.origin + parameters.l * double(memberIndex) / double(sObjectStep->size());
            });
        };
};

}

#endif
