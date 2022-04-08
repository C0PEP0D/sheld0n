#ifndef C0P_PARAM_OBJECTS_TRACERS__E2_1O0_POS_A_GROUP_MEMBER_PAIR_A_PARAMETERS_H
#define C0P_PARAM_OBJECTS_TRACERS__E2_1O0_POS_A_GROUP_MEMBER_PAIR_A_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/pair/a/prop.h"
#include "param/init/objects/tracers__e2_1o0/pos_a/group/_member/pair/a/_a/choice.h"

namespace c0p {

// Sole pair member A initialisation parameters
struct InitTracersE21O0PosAGroupMemberPairAParameters {
    // Initialisation choice for the pair member A
    // Should not be changed, the choice should be
    // done in the _a directory.
    template<typename TypeAStep>
    using TypeInitInitA = InitTracersE21O0PosAGroupMemberPairAA<TypeAStep>;;
};

}

#endif
