#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_1O0__REORIENTATIONTIME_0O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_PASSIVE_SPHEROID_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_1O0__REORIENTATIONTIME_0O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_PASSIVE_SPHEROID_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/passive/spheroid/prop.h"

namespace c0p {

// Parameters of the step of spheroidal particle advected and rotated by a flow
struct SurferUs1O0Surftimeconst1O0Reorientationtime0O25GroupHomogeneousMemberAgentActivePassiveSpheroidStepParameters {
    // Proportion: fraction of the big axis over the small axis
    TypeScalar proportion = 1.0;
};

}

#endif
