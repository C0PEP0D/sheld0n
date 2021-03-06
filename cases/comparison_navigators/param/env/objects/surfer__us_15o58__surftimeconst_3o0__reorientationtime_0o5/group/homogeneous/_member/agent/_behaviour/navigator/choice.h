#ifndef C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_3O0__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_3O0__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/local_axis_swimmer/core.h"
#include "param/env/objects/surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/navigator/local_axis_swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorLocalAxisSwimmer<SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourNavigatorLocalAxisSwimmerParameters, SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep, SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>, SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>, SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>, SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs15O58Surftimeconst3O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
