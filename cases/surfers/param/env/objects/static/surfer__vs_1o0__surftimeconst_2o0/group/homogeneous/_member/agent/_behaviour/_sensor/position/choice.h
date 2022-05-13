#ifndef C0P_PARAM_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/position/accurate/core.h"
#include "param/env/objects/static/surfer__vs_1o0__surftimeconst_2o0/group/homogeneous/_member/agent/_behaviour/_sensor/position/accurate/parameters.h"
namespace c0p {
    template<typename SurferVs1O0Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>
    using SurferVs1O0Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourSensorPosition = AgentBehaviourSensorPositionAccurate<SurferVs1O0Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourSensorPositionAccurateParameters, SurferVs1O0Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif
