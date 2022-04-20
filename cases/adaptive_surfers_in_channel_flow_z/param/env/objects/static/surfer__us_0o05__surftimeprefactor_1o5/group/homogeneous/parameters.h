#ifndef C0P_OBJECTS_SURFER__US_0O05__SURFTIMEPREFACTOR_1O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_0O05__SURFTIMEPREFACTOR_1O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/static/surfer__us_0o05__surftimeprefactor_1o5/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs0O05Surftimeprefactor1O5GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs0O05Surftimeprefactor1O5GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(0.05*0.05) * Parameters::cGroupSize;
};

}

#endif
