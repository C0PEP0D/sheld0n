#ifndef C0P_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_0O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_0O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/static/surfer__us_0o2__surftimeprefactor_0o5/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs0O2Surftimeprefactor0O5GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs0O2Surftimeprefactor0O5GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1/(0.2*0.2) * Parameters::cGroupSize;
};

}

#endif
