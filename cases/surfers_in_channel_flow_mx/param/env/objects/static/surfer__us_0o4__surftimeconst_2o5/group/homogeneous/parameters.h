#ifndef C0P_OBJECTS_SURFER__US_0O4__SURFTIMECONST_2O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_0O4__SURFTIMECONST_2O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/static/surfer__us_0o4__surftimeconst_2o5/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs0O4Surftimeconst2O5GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs0O4Surftimeconst2O5GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(0.4*0.4) * Parameters::cGroupSize;
};

}

#endif
