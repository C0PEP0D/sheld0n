#ifndef C0P_PARAM_OBJECTS_SURFER__US_9O0__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_9O0__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/accurate/core.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_2o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs9O0Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs9O0Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients = AgentBehaviourSensorVelocityGradientsAccurate<SurferUs9O0Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradientsAccurateParameters, SurferUs9O0Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif
