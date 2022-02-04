#ifndef C0P_OBJECTS_PAGENT_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_PAGENT_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/pagent/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct PagentGroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = PagentGroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1 * Parameters::cGroupSize;
};

}

#endif
