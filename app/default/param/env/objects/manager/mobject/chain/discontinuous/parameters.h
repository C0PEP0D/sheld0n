#ifndef C0P_OBJECTS_MOBJECT_CHAIN_DISCONTINUOUS_PARAMETERS_H
#define C0P_OBJECTS_MOBJECT_CHAIN_DISCONTINUOUS_PARAMETERS_H
#pragma once

// include std
#include <vector>
// include lib
#include "core/env/objects/object/chain/discontinuous/prop.h"
#include "param/env/objects/manager/mobject/chain/discontinuous/_member/choice.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of a filament of fixed size advected by the flow
struct MobjectChainDiscontinuousStepParameters {
    // Chain member step
    // Should not be changed. Member step choice
    // should be done in the _member directory.
    using TypeMemberStep = MobjectChainDiscontinuousMemberStep;
    // Resolution of the chain
    const double dl = 1 * Parameters::cLength;
    // Interpolation order of the chain
    const unsigned int interpolationOrder = 4;
};

}

#endif
