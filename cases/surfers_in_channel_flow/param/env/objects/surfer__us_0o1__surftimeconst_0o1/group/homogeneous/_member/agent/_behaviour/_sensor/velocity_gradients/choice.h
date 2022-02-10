#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O1_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O1_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/accurate/core.h"
#include "param/env/objects/surfer__us_0o1__surftimeconst_0o1/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs0O1Surftimeconst0O1GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O1Surftimeconst0O1GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients = AgentBehaviourSensorVelocityGradientsAccurate<SurferUs0O1Surftimeconst0O1GroupHomogeneousMemberAgentBehaviourSensorVelocityGradientsAccurateParameters, SurferUs0O1Surftimeconst0O1GroupHomogeneousMemberAgentActiveStep>;
}

#endif
