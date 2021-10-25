#ifndef C0P_OBJECTS_OBJECT_CHAIN_SIMPLE_PARAMETERS_H
#define C0P_OBJECTS_OBJECT_CHAIN_SIMPLE_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/chain/simple/prop.h"
#include "param/env/objects/object/chain/simple/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of a filament of fixed size advected by the flow
struct ObjectChainSimpleStepParameters {
    // Chain member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = ObjectChainSimpleMemberStep;
    // Number of members in the chain
    static const unsigned int size = 1 * Parameters::cGroupSize;
    // Length of the chain
    double length = 1 * Parameters::cLength;
};

}

#endif
