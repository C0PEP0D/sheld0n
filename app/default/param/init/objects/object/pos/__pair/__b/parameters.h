#ifndef C0P_PARAM_OBJECTS_OBJECT_POS_PAIR_B_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_POS_PAIR_B_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/pair/b/prop.h"
#include "param/init/objects/object/pos/pair/b/_b/choice.h"

namespace c0p {

struct InitObjectPosPairBParameters {
    template<typename TypeBStep>
    using TypeInitInitB = InitObjectPosPairBB<TypeBStep>;;
};

}

#endif
