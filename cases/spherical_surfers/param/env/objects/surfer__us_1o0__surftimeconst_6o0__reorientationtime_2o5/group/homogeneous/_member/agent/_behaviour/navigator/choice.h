#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_6O0__REORIENTATIONTIME_2O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_6O0__REORIENTATIONTIME_2O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_1o0__surftimeconst_6o0__reorientationtime_2o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_6o0__reorientationtime_2o5/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_1o0__surftimeconst_6o0__reorientationtime_2o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_6o0__reorientationtime_2o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/local_axis_swimmer/core.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_6o0__reorientationtime_2o5/group/homogeneous/_member/agent/_behaviour/navigator/local_axis_swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorLocalAxisSwimmer<SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentBehaviourNavigatorLocalAxisSwimmerParameters, SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentActiveStep, SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentActiveStep>, SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentActiveStep>, SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentActiveStep>, SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs1O0Surftimeconst6O0Reorientationtime2O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
