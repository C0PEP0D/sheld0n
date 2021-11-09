#ifndef C0P_OBJECTS_SURFER__US_10O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_10O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_3o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs10O0Surftimeconst3O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs10O0Surftimeconst3O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(1.0*1.0) * Parameters::cGroupSize;
};

}

#endif
