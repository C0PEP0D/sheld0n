#ifndef C0P_PARAM_OBJECTS_SURFER__US_5O0__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_5O0__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/accurate/core.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs5O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs5O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients = AgentBehaviourSensorVelocityGradientsAccurate<SurferUs5O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradientsAccurateParameters, SurferUs5O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif
