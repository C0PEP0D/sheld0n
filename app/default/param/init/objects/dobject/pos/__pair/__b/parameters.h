#ifndef C0P_PARAM_OBJECTS_DOBJECT_POS_PAIR_B_PARAMETERS_H
#define C0P_PARAM_OBJECTS_DOBJECT_POS_PAIR_B_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/pair/b/prop.h"
#include "param/init/objects/dobject/pos/pair/b/_b/choice.h"

namespace c0p {

struct InitDobjectPosPairBParameters {
    template<typename TypeBStep>
    using TypeInitInitB = InitDobjectPosPairBB<TypeBStep>;;
};

}

#endif
