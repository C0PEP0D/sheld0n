#ifndef C0P_OBJECTS_SURFER__US_3O5__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_3O5__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_2o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs3O5Surftimeconst2O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(3.5*3.5) * Parameters::cGroupSize;
};

}

#endif
