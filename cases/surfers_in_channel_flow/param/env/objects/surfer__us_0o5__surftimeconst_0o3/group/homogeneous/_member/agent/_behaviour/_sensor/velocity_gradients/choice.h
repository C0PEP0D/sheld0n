#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O3_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O3_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/accurate/core.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o3/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs0O5Surftimeconst0O3GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O5Surftimeconst0O3GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients = AgentBehaviourSensorVelocityGradientsAccurate<SurferUs0O5Surftimeconst0O3GroupHomogeneousMemberAgentBehaviourSensorVelocityGradientsAccurateParameters, SurferUs0O5Surftimeconst0O3GroupHomogeneousMemberAgentActiveStep>;
}

#endif
