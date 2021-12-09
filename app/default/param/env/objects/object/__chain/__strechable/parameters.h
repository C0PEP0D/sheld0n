#ifndef C0P_OBJECTS_OBJECT_CHAIN_STRECHABLE_PARAMETERS_H
#define C0P_OBJECTS_OBJECT_CHAIN_STRECHABLE_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/chain/strechable/prop.h"
#include "param/env/objects/object/chain/strechable/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of a filament of fixed size advected by the flow
struct ObjectChainStrechableStepParameters {
    // Chain member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = ObjectChainStrechableMemberStep;
    // Resolution of the chain
    const double dl = 1 * Parameters::cLength;
    // Interpolation order of the chain
    const unsigned int interpolationOrder = 4;
};

}

#endif
