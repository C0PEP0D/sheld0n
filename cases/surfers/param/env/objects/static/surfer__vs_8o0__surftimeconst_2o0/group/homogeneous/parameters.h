#ifndef C0P_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/static/surfer__vs_8o0__surftimeconst_2o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferVs8O0Surftimeconst2O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferVs8O0Surftimeconst2O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(8.0*8.0) * Parameters::cGroupSize;
};

}

#endif
