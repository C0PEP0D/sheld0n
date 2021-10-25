#ifndef C0P_OBJECTS_SURFER__US_15O0__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_15O0__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_6o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs15O0Surftimeconst6O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs15O0Surftimeconst6O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(15.0*15.0) * Parameters::cGroupSize;
};

}

#endif
