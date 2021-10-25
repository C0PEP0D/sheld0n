#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_3O0__REORIENTATIONTIME_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_3O0__REORIENTATIONTIME_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_1o0__surftimeconst_3o0__reorientationtime_1o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_3o0__reorientationtime_1o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// behaviour time horizon choice
#include "param/env/objects/surfer__us_1o0__surftimeconst_3o0__reorientationtime_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_3o0__reorientationtime_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentActiveStep, SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferUs1O0Surftimeconst3O0Reorientationtime1O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
