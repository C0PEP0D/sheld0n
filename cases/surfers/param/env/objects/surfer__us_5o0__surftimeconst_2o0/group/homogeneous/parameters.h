#ifndef C0P_OBJECTS_SURFER__US_5O0__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_5O0__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_2o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs5O0Surftimeconst2O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs5O0Surftimeconst2O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(5.0*5.0) * Parameters::cGroupSize;
};

}

#endif
