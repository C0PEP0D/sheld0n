#ifndef C0P_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_0O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_0O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/static/surfer__vs_4o0__surftimeconst_0o5/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferVs4O0Surftimeconst0O5GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferVs4O0Surftimeconst0O5GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(4.0*4.0) * Parameters::cGroupSize;
};

}

#endif
