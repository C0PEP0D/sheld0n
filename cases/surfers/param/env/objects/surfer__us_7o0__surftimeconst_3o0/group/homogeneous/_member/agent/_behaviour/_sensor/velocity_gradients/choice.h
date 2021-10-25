#ifndef C0P_PARAM_OBJECTS_SURFER__US_7O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_7O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/accurate/core.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs7O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs7O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients = AgentBehaviourSensorVelocityGradientsAccurate<SurferUs7O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradientsAccurateParameters, SurferUs7O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif
