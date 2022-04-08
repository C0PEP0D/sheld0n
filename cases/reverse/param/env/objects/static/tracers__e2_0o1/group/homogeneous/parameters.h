#ifndef C0P_OBJECTS_TRACERS__E2_0O1_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_TRACERS__E2_0O1_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/static/tracers__e2_0o1/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct TracersE20O1GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = TracersE20O1GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1 * Parameters::cGroupSize;
};

}

#endif
