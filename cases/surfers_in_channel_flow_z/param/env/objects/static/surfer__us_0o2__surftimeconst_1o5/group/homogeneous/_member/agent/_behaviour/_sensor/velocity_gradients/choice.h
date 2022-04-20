#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O2__SURFTIMECONST_1O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O2__SURFTIMECONST_1O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/accurate/core.h"
#include "param/env/objects/static/surfer__us_0o2__surftimeconst_1o5/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs0O2Surftimeconst1O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O2Surftimeconst1O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients = AgentBehaviourSensorVelocityGradientsAccurate<SurferUs0O2Surftimeconst1O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradientsAccurateParameters, SurferUs0O2Surftimeconst1O5GroupHomogeneousMemberAgentActiveStep>;
}

#endif
