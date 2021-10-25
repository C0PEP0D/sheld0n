#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_CHOICE_H
#pragma once

#include "param/env/objects/object/group/homogeneous/_member/agent/_active/choice.h"
// choose your behaviour
#include "param/env/objects/object/group/homogeneous/_member/agent/_behaviour/swim_in_direction/swimming_direction/choice.h"
namespace c0p {
    template<typename ObjectGroupHomogeneousMemberAgentActiveStep>
    using ObjectGroupHomogeneousMemberAgentBehaviourSwimInDirection = ObjectGroupHomogeneousMemberAgentBehaviourSwimInDirectionSwimmingDirection<ObjectGroupHomogeneousMemberAgentActiveStep>;
}

#endif
