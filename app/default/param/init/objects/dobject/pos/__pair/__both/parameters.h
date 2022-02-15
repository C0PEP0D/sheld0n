#ifndef C0P_PARAM_OBJECTS_DOBJECT_POS_PAIR_BOTH_PARAMETERS_H
#define C0P_PARAM_OBJECTS_DOBJECT_POS_PAIR_BOTH_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/pair/both/prop.h"
#include "param/init/objects/dobject/pos/pair/both/_a/choice.h"
#include "param/init/objects/dobject/pos/pair/both/_b/choice.h"

namespace c0p {

// Both pair members initialisation parameters
struct InitDobjectPosPairBothParameters {
    // Initialisation choice for the pair member A
    // Should not be changed, the choice should be
    // done in the _a directory.
    template<typename TypeAStep>
    using TypeInitInitA = InitDobjectPosPairBothA<TypeAStep>;;
    // Initialisation choice for the pair member B
    // Should not be changed, the choice should be
    // done in the _b directory.
    template<typename TypeBStep>
    using TypeInitInitB = InitDobjectPosPairBothB<TypeAStep>;;
};

}

#endif
