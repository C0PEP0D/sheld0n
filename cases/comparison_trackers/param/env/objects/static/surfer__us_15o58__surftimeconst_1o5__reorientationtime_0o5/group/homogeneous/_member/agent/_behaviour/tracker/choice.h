#ifndef C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_1O5__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_TRACKER_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_1O5__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_TRACKER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/tracker/local_axis_swimmer/core.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/tracker/local_axis_swimmer/parameters.h"
// sensor choice
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/tracker/_behaviour_direction/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5/group/homogeneous/_member/agent/_behaviour/tracker/_behaviour_velocity/choice.h"
namespace c0p {
    template<typename SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourTracker = AgentBehaviourTrackerLocalAxisSwimmer<SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourTrackerLocalAxisSwimmerParameters, SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep, SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>, SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>, SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourTrackerBehaviourDirection<SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>, SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentBehaviourTrackerBehaviourVelocity<SurferUs15O58Surftimeconst1O5Reorientationtime0O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
