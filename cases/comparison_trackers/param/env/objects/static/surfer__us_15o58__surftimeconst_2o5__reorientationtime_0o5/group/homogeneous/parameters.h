#ifndef C0P_OBJECTS_SURFER__US_15O58__SURFTIMECONST_2O5__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#define C0P_OBJECTS_SURFER__US_15O58__SURFTIMECONST_2O5__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/group/homogeneous/prop.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_2o5__reorientationtime_0o5/group/homogeneous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

struct SurferUs15O58Surftimeconst2O5Reorientationtime0O5GroupHomogeneousStepParameters {
    // Group member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = SurferUs15O58Surftimeconst2O5Reorientationtime0O5GroupHomogeneousMemberStep;
    // Group size
    static const unsigned int size = 1 * Parameters::cGroupSize;
};

}

#endif
