#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O4__SURFTIMEPREFACTOR_1O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O4__SURFTIMEPREFACTOR_1O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/behaviour_time_horizon/inv_velocity_gradients_symmetric/core.h"
#include "param/env/objects/static/surfer__us_0o4__surftimeprefactor_1o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/inv_velocity_gradients_symmetric/parameters.h"
namespace c0p {
    template<typename SurferUs0O4Surftimeprefactor1O75GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O4Surftimeprefactor1O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon = AgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonInvVelocityGradientsSymmetric<SurferUs0O4Surftimeprefactor1O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonInvVelocityGradientsSymmetricParameters, SurferUs0O4Surftimeprefactor1O75GroupHomogeneousMemberAgentActiveStep>;
}

#endif
