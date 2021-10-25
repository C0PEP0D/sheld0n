#ifndef C0P_PARAM_OBJECTS_OBJECT_POS_PAIR_A_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_POS_PAIR_A_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/pair/a/prop.h"
#include "param/init/objects/object/pos/pair/a/_a/choice.h"

namespace c0p {

// Sole pair member A initialisation parameters
struct InitObjectPosPairAParameters {
    // Initialisation choice for the pair member A
    // Should not be changed, the choice should be
    // done in the _a directory.
    template<typename TypeAStep>
    using TypeInitInitA = InitObjectPosPairAA<TypeAStep>;;
};

}

#endif
