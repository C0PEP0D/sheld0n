#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O025_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O025_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour time horizon choice
#include "param/env/objects/surfer__us_0o1__surftimeconst_0o025/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/surfer__us_0o1__surftimeconst_0o025/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferUs0O1Surftimeconst0O025GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O1Surftimeconst0O025GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferUs0O1Surftimeconst0O025GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferUs0O1Surftimeconst0O025GroupHomogeneousMemberAgentActiveStep, SurferUs0O1Surftimeconst0O025GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferUs0O1Surftimeconst0O025GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
