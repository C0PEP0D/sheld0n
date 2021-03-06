#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_PAIR_A_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_PAIR_A_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/static/object/group/homogeneous/_member/pair/_a/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/static/object/group/homogeneous/_member/pair/_a/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename ObjectGroupHomogeneousMemberPairAAgentActiveStep>
    using ObjectGroupHomogeneousMemberPairAAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<ObjectGroupHomogeneousMemberPairAAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, ObjectGroupHomogeneousMemberPairAAgentActiveStep, ObjectGroupHomogeneousMemberPairAAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<ObjectGroupHomogeneousMemberPairAAgentActiveStep>>;
}

#endif
