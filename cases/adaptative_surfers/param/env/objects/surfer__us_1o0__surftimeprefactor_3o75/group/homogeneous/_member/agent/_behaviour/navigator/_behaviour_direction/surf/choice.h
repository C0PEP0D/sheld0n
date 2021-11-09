#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_3O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_3O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_3o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_3o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferUs1O0Surftimeprefactor3O75GroupHomogeneousMemberAgentActiveStep>
    using SurferUs1O0Surftimeprefactor3O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferUs1O0Surftimeprefactor3O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferUs1O0Surftimeprefactor3O75GroupHomogeneousMemberAgentActiveStep, SurferUs1O0Surftimeprefactor3O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferUs1O0Surftimeprefactor3O75GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
