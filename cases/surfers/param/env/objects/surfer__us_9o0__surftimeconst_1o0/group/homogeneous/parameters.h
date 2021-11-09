#ifndef C0P_OBJECTS_SURFER__US_9O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_9O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_1o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs9O0Surftimeconst1O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs9O0Surftimeconst1O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(1.0*1.0) * Parameters::cGroupSize;
};

}

#endif
