#ifndef C0P_PARAM_OBJECTS_TRACERS__E2_10O0_POS_B_GROUP_MEMBER_PAIR_STRAIN_RELATIVE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_TRACERS__E2_10O0_POS_B_GROUP_MEMBER_PAIR_STRAIN_RELATIVE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/pair/strain_relative/prop.h"

#include "param/parameters.h"

namespace c0p {

// Random initialisation of the position of the pair member B at a specific position with respect of the position of the pair member A
struct InitTracersE210O0PosBGroupMemberPairStrainRelativeParameters {
    // Relative position of B with respect to A
    TypeSpaceVector position = 10.0 * TypeSpaceVector({0.0, 1.0, 0.0}) * Parameters::cLength;
};

}

#endif
