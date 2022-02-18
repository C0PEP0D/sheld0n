#ifndef C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/behaviour_time_horizon/inv_velocity_gradients_symmetric/core.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_0o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/inv_velocity_gradients_symmetric/parameters.h"
namespace c0p {
    template<typename SurferUs2O0Surftimeprefactor0O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs2O0Surftimeprefactor0O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon = AgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonInvVelocityGradientsSymmetric<SurferUs2O0Surftimeprefactor0O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonInvVelocityGradientsSymmetricParameters, SurferUs2O0Surftimeprefactor0O5GroupHomogeneousMemberAgentActiveStep>;
}

#endif