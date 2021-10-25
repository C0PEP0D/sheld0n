#ifndef C0P_PARAM_OBJECTS_OBJECT_POS_PAIR_BOTH_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_POS_PAIR_BOTH_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/pair/both/prop.h"
#include "param/init/objects/object/pos/pair/both/_a/choice.h"
#include "param/init/objects/object/pos/pair/both/_b/choice.h"

namespace c0p {

// Both pair members initialisation parameters
struct InitObjectPosPairBothParameters {
    // Initialisation choice for the pair member A
    // Should not be changed, the choice should be
    // done in the _a directory.
    template<typename TypeAStep>
    using TypeInitInitA = InitObjectPosPairBothA<TypeAStep>;;
    // Initialisation choice for the pair member B
    // Should not be changed, the choice should be
    // done in the _b directory.
    template<typename TypeBStep>
    using TypeInitInitB = InitObjectPosPairBothB<TypeAStep>;;
};

}

#endif
