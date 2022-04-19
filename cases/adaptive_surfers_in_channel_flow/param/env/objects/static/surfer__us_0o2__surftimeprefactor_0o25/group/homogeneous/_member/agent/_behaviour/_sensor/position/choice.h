#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_0O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_0O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/position/accurate/core.h"
#include "param/env/objects/static/surfer__us_0o2__surftimeprefactor_0o25/group/homogeneous/_member/agent/_behaviour/_sensor/position/accurate/parameters.h"
namespace c0p {
    template<typename SurferUs0O2Surftimeprefactor0O25GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O2Surftimeprefactor0O25GroupHomogeneousMemberAgentBehaviourSensorPosition = AgentBehaviourSensorPositionAccurate<SurferUs0O2Surftimeprefactor0O25GroupHomogeneousMemberAgentBehaviourSensorPositionAccurateParameters, SurferUs0O2Surftimeprefactor0O25GroupHomogeneousMemberAgentActiveStep>;
}

#endif