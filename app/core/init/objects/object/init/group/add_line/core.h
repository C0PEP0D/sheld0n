#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_ADD_LINE_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_ADD_LINE_CORE_H
#pragma once

// std includes
#include <execution>
// app includes
#include "core/init/objects/object/init/group/add_line/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitMember>
class InitInitGroupAddLine : public InitInitInitDynamic<TypeObjectStep> {
    public:
        TypeParameters parameters;
    public:
        using InitInitInitDynamic<TypeObjectStep>::sObjectStep;
    public:
        InitInitGroupAddLine(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitDynamic<TypeObjectStep>(p_sObjectStep) {
        }
    public:
        void operator()(std::vector<double>& state) override {
            const unsigned int membersNumber = std::ceil(parameters.l.norm() / sObjectStep->dl) + 1;
            const TypeSpaceVector dl = parameters.l / (membersNumber - 1);
            for(unsigned int memberIndex = 0; memberIndex < membersNumber; memberIndex++) {
                sObjectStep->addMember(state);
                sObjectStep->sMemberStep->x(sObjectStep->memberState(state.data(), memberIndex)) = parameters.origin + memberIndex * dl;
                sObjectStep->sMemberStep->axis(sObjectStep->memberState(state.data(), memberIndex)) = TypeSpaceVector({0.0, 1.0, 0.0}); // TMP
            }
        };
};

}

#endif
