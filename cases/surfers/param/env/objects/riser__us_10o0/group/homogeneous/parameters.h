#ifndef C0P_OBJECTS_RISER__US_10O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_RISER__US_10O0_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/riser__us_10o0/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct RiserUs10O0GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = RiserUs10O0GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(1.0*1.0) * Parameters::cGroupSize;
};

}

#endif
