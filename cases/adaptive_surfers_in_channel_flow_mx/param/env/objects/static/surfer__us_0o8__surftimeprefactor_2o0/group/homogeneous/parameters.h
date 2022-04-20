#ifndef C0P_OBJECTS_SURFER__US_0O8__SURFTIMEPREFACTOR_2O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_0O8__SURFTIMEPREFACTOR_2O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/static/surfer__us_0o8__surftimeprefactor_2o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs0O8Surftimeprefactor2O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs0O8Surftimeprefactor2O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(0.8*0.8) * Parameters::cGroupSize;
};

}

#endif
