#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O8__SURFTIMEPREFACTOR_1O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_INV_VELOCITY_GRADIENTS_SYMMETRIC_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O8__SURFTIMEPREFACTOR_1O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_BEHAVIOUR_TIME_HORIZON_INV_VELOCITY_GRADIENTS_SYMMETRIC_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/behaviour_time_horizon/inv_velocity_gradients_symmetric/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of the behaviour that sets a time horizon proportial to
// the inverse of the norm of the symmetric part of the measured flow 
// velocity gradients
struct SurferUs0O8Surftimeprefactor1O25GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizonInvVelocityGradientsSymmetricParameters {
    const TypeScalar prefactor = 1.25;
    // Maximum value of the time horizon
    const TypeScalar max = 1e6;
};

}

#endif
