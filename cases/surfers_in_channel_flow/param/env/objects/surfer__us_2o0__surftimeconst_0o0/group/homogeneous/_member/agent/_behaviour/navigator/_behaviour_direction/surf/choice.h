#ifndef C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/surfer__us_2o0__surftimeconst_0o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_0o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferUs2O0Surftimeconst0O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs2O0Surftimeconst0O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferUs2O0Surftimeconst0O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferUs2O0Surftimeconst0O0GroupHomogeneousMemberAgentActiveStep, SurferUs2O0Surftimeconst0O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferUs2O0Surftimeconst0O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
