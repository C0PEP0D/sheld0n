#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O8_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O8_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o8/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o8/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o8/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o8/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o8/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentActiveStep, SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentActiveStep>, SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentActiveStep>, SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentActiveStep>, SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs0O5Surftimeconst0O8GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
