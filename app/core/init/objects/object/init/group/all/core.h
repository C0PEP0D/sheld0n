#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_ALL_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_ALL_CORE_H
#pragma once

// std includes
#include <execution>
// app includes
#include "core/init/objects/object/init/group/all/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitMember>
class InitInitGroupAll : public InitInitInit<TypeObjectStep> {
    public:
        TypeParameters parameters;
        TypeInitInitMember<typename TypeObjectStep::TypeMemberStep> initMember;
    public:
        using InitInitInit<TypeObjectStep>::sObjectStep;
    public:
        InitInitGroupAll(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInit<TypeObjectStep>(p_sObjectStep), initMember(sObjectStep->sMemberStep) {
        }
    public:
        void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) override {
            std::for_each(std::execution::par_unseq, sObjectStep->memberIndexs.cbegin(), sObjectStep->memberIndexs.cend(), [this, state](const unsigned int& memberIndex){ 
                initMember(sObjectStep->memberState(state, memberIndex));
            });
        };
};

}

#endif
