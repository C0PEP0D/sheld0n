#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_5O0__REORIENTATIONTIME_4O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_5O0__REORIENTATIONTIME_4O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/surfer__us_1o0__surftimeconst_5o0__reorientationtime_4o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_5o0__reorientationtime_4o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferUs1O0Surftimeconst5O0Reorientationtime4O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs1O0Surftimeconst5O0Reorientationtime4O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferUs1O0Surftimeconst5O0Reorientationtime4O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferUs1O0Surftimeconst5O0Reorientationtime4O0GroupHomogeneousMemberAgentActiveStep, SurferUs1O0Surftimeconst5O0Reorientationtime4O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferUs1O0Surftimeconst5O0Reorientationtime4O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif