#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_SWIMMING_DIRECTION_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SWIM_IN_DIRECTION_SWIMMING_DIRECTION_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CHOICE_H
#pragma once

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/swim_in_direction/swimming_direction/behaviour_direction/surf/behaviour_time_horizon/const/core.h"
#include "param/env/objects/object/group/homogeneous/_member/agent/_behaviour/swim_in_direction/swimming_direction/_behaviour_direction/surf/_behaviour_time_horizon/const/parameters.h"
namespace c0p {
    template<typename ObjectGroupHomogeneousMemberAgentActiveStep>
    using ObjectGroupHomogeneousMemberAgentBehaviourSwimInDirectionSwimmingDirectionBehaviourDirectionSurfBehaviourTimeHorizon = AgentBehaviourSwimInDirectionSwimmingDirectionBehaviourDirectionSurfBehaviourTimeHorizonConst<ObjectGroupHomogeneousMemberAgentBehaviourSwimInDirectionSwimmingDirectionBehaviourDirectionSurfBehaviourTimeHorizonConstParameters, ObjectGroupHomogeneousMemberAgentActiveStep>;
}

#endif
