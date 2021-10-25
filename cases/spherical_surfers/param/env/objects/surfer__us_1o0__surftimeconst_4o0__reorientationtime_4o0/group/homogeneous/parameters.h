#ifndef C0P_OBJECTS_SURFER__US_1O0__SURFTIMECONST_4O0__REORIENTATIONTIME_4O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_1O0__SURFTIMECONST_4O0__REORIENTATIONTIME_4O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_4o0__reorientationtime_4o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs1O0Surftimeconst4O0Reorientationtime4O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs1O0Surftimeconst4O0Reorientationtime4O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1 * Parameters::cGroupSize;
};

}

#endif
