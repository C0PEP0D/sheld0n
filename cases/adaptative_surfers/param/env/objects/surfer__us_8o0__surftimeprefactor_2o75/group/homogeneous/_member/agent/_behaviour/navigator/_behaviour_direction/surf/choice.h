#ifndef C0P_PARAM_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_2O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_2O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_8o0__surftimeprefactor_2o75/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeprefactor_2o75/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// behaviour time horizon choice
#include "param/env/objects/surfer__us_8o0__surftimeprefactor_2o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/_behaviour_time_horizon/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/core.h"
#include "param/env/objects/surfer__us_8o0__surftimeprefactor_2o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/surf/exp/parameters.h"
namespace c0p {
    template<typename SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep>
    using SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurf = AgentBehaviourNavigatorBehaviourDirectionSurfExp<SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfExpParameters, SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep, SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep>, SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep>, SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionSurfBehaviourTimeHorizon<SurferUs8O0Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
