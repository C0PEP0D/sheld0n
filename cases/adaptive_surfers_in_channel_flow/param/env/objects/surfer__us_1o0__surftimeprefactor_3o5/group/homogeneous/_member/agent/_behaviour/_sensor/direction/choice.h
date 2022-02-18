#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/core.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_3o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs1O0Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs1O0Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourSensorDirection = AgentBehaviourSensorDirectionAccurate<SurferUs1O0Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourSensorDirectionAccurateParameters, SurferUs1O0Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>;
}

#endif