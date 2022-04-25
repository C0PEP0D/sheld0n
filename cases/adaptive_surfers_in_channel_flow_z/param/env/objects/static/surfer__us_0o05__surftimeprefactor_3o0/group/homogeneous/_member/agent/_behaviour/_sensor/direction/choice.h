#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O05__SURFTIMEPREFACTOR_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O05__SURFTIMEPREFACTOR_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/core.h"
#include "param/env/objects/static/surfer__us_0o05__surftimeprefactor_3o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs0O05Surftimeprefactor3O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O05Surftimeprefactor3O0GroupHomogeneousMemberAgentBehaviourSensorDirection = AgentBehaviourSensorDirectionAccurate<SurferUs0O05Surftimeprefactor3O0GroupHomogeneousMemberAgentBehaviourSensorDirectionAccurateParameters, SurferUs0O05Surftimeprefactor3O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif