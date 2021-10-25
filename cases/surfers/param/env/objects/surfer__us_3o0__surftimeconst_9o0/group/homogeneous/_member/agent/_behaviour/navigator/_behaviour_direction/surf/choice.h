#ifndef C0P_PARAM_OBJECTS_SURFER__US_3O0__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_3O0__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_3o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// behaviour time horizon choice
#include "param/env/objects/surfer__us_3o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep, SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>, SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>, SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
