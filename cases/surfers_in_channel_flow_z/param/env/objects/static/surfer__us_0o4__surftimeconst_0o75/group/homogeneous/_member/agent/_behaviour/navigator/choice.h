#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O4__SURFTIMECONST_0O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O4__SURFTIMECONST_0O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/static/surfer__us_0o4__surftimeconst_0o75/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/static/surfer__us_0o4__surftimeconst_0o75/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/static/surfer__us_0o4__surftimeconst_0o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/static/surfer__us_0o4__surftimeconst_0o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/static/surfer__us_0o4__surftimeconst_0o75/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentActiveStep, SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentActiveStep>, SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentActiveStep>, SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentActiveStep>, SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs0O4Surftimeconst0O75GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
