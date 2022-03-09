#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_ALL_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_ALL_CORE_H
#pragma once

// std includes
#include <execution>
// app includes
#include "core/init/objects/object/init/group/all/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitMember>
class InitInitGroupAll : public InitInitInitStatic<TypeObjectStep> {
    public:
        TypeParameters parameters;
        TypeInitInitMember<typename TypeObjectStep::TypeMemberStep> initMember;
    public:
        using InitInitInitStatic<TypeObjectStep>::sObjectStep;
    public:
        InitInitGroupAll(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitStatic<TypeObjectStep>(p_sObjectStep), initMember(sObjectStep->sMemberStep) {
        }
    public:
    	using InitInitInitStatic<TypeObjectStep>::operator();
        void operator()(double* pState) override {
            std::for_each(std::execution::par_unseq, sObjectStep->memberIndexs.cbegin(), sObjectStep->memberIndexs.cend(), [this, pState](const unsigned int& memberIndex){ 
                initMember(sObjectStep->memberState(pState, memberIndex));
            });
        };
};

}

#endif
