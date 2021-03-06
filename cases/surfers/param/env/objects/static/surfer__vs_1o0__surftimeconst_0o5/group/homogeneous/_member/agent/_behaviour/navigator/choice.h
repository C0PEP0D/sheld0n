#ifndef C0P_PARAM_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/static/surfer__vs_1o0__surftimeconst_0o5/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
// sensor choice
#include "param/env/objects/static/surfer__vs_1o0__surftimeconst_0o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/static/surfer__vs_1o0__surftimeconst_0o5/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/static/surfer__vs_1o0__surftimeconst_0o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/static/surfer__vs_1o0__surftimeconst_0o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
namespace c0p {
    template<typename SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentActiveStep>
    using SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentActiveStep, SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentActiveStep>, SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentActiveStep>, SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentActiveStep>, SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferVs1O0Surftimeconst0O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
