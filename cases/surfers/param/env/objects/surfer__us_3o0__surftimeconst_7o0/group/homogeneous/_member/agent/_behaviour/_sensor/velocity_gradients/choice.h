#ifndef C0P_PARAM_OBJECTS_SURFER__US_3O0__SURFTIMECONST_7O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_3O0__SURFTIMECONST_7O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/accurate/core.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_7o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs3O0Surftimeconst7O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs3O0Surftimeconst7O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients = AgentBehaviourSensorVelocityGradientsAccurate<SurferUs3O0Surftimeconst7O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradientsAccurateParameters, SurferUs3O0Surftimeconst7O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif
