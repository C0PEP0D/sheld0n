#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferUs0O1Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O1Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferUs0O1Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferUs0O1Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep, SurferUs0O1Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferUs0O1Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
