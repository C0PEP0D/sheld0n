#ifndef C0P_PARAM_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_2O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_2O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/static/surfer__vs_8o0__surftimeconst_2o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/static/surfer__vs_8o0__surftimeconst_2o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferVs8O0Surftimeconst2O5GroupHomogeneousMemberAgentActiveStep>
    using SurferVs8O0Surftimeconst2O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferVs8O0Surftimeconst2O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferVs8O0Surftimeconst2O5GroupHomogeneousMemberAgentActiveStep, SurferVs8O0Surftimeconst2O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferVs8O0Surftimeconst2O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
