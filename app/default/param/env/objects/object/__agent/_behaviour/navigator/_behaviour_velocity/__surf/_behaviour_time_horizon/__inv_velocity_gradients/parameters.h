#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_BEHAVIOUR_TIME_HORIZON_INV_VELOCITY_GRADIENTS_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_BEHAVIOUR_TIME_HORIZON_INV_VELOCITY_GRADIENTS_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/surf/behaviour_time_horizon/inv_velocity_gradients/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of the behaviour that sets a time horizon proportial to
// the inverse of the measured flow velocity gradients norm
struct ObjectAgentBehaviourNavigatorBehaviourVelocitySurfBehaviourTimeHorizonInvVelocityGradientsParameters {
    const TypeScalar prefactor = 1.0;
    // Maximum value of the time horizon
    const TypeScalar max = 1e6;
};

}

#endif
