#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// behaviour time horizon choice
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentActiveStep, SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentActiveStep>, SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentActiveStep>, SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferUs0O5Surftimeconst0O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
