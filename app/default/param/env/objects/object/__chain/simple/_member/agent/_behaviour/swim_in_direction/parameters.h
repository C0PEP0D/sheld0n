#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/swim_in_direction/prop.h"

namespace c0p {

struct ObjectGroupHomogeneousMemberAgentBehaviourSwimInDirectionParameters {
    TypeSpaceVector targetDirection = {1.0, 0.0, 0.0};
};

}

#endif
