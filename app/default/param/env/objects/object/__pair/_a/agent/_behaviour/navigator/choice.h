#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_PAIR_A_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_PAIR_A_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/object/group/homogeneous/_member/pair/_a/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/object/group/homogeneous/_member/pair/_a/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/object/group/homogeneous/_member/pair/_a/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/object/group/homogeneous/_member/pair/_a/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/local_axis_swimmer/core.h"
#include "param/env/objects/object/group/homogeneous/_member/pair/_a/agent/_behaviour/navigator/local_axis_swimmer/parameters.h"
namespace c0p {
    template<typename ObjectGroupHomogeneousMemberPairAAgentActiveStep>
    using ObjectGroupHomogeneousMemberPairAAgentBehaviourNavigator = AgentBehaviourNavigatorLocalAxisSwimmer<ObjectGroupHomogeneousMemberPairAAgentBehaviourNavigatorLocalAxisSwimmerParameters, ObjectGroupHomogeneousMemberPairAAgentActiveStep, ObjectGroupHomogeneousMemberPairAAgentBehaviourSensorDirection<ObjectGroupHomogeneousMemberPairAAgentActiveStep>, ObjectGroupHomogeneousMemberPairAAgentBehaviourSensorVelocityGradients<ObjectGroupHomogeneousMemberPairAAgentActiveStep>, ObjectGroupHomogeneousMemberPairAAgentBehaviourNavigatorBehaviourDirection<ObjectGroupHomogeneousMemberPairAAgentActiveStep>, ObjectGroupHomogeneousMemberPairAAgentBehaviourNavigatorBehaviourVelocity<ObjectGroupHomogeneousMemberPairAAgentActiveStep>>;
}

#endif
