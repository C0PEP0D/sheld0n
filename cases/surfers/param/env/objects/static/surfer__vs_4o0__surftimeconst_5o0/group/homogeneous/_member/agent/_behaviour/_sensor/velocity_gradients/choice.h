#ifndef C0P_PARAM_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/accurate/core.h"
#include "param/env/objects/static/surfer__vs_4o0__surftimeconst_5o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/accurate/parameters.h"
namespace c0p {
    template<typename SurferVs4O0Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep>
    using SurferVs4O0Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients = AgentBehaviourSensorVelocityGradientsAccurate<SurferVs4O0Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradientsAccurateParameters, SurferVs4O0Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif
