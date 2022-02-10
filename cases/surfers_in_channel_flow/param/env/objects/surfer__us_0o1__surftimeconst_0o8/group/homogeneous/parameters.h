#ifndef C0P_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O8_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O8_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/surfer__us_0o1__surftimeconst_0o8/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs0O1Surftimeconst0O8GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs0O1Surftimeconst0O8GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(0.1*0.1) * Parameters::cGroupSize;
};

}

#endif
