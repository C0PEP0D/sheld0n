#ifndef C0P_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_2O25_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_2O25_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_2o25/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs2O0Surftimeprefactor2O25GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs2O0Surftimeprefactor2O25GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(2.0*2.0) * Parameters::cGroupSize;
};

}

#endif
