#ifndef C0P_OBJECTS_SURFER__US_4O5__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_4O5__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_9o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs4O5Surftimeconst9O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs4O5Surftimeconst9O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(4.5*4.5) * Parameters::cGroupSize;
};

}

#endif
