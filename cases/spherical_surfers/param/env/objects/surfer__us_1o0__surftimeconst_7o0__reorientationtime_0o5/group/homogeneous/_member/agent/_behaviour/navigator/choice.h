#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_7O0__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_7O0__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/surfer__us_1o0__surftimeconst_7o0__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_7o0__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/local_axis_swimmer/core.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_7o0__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/navigator/local_axis_swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs1O0Surftimeconst7O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs1O0Surftimeconst7O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorLocalAxisSwimmer<SurferUs1O0Surftimeconst7O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourNavigatorLocalAxisSwimmerParameters, SurferUs1O0Surftimeconst7O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep, SurferUs1O0Surftimeconst7O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs1O0Surftimeconst7O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>, SurferUs1O0Surftimeconst7O0Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs1O0Surftimeconst7O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
