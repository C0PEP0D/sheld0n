#ifndef C0P_PStrainRelativeRStrainRelativeM_INIT_OBJECTS_TRACERS__E3_10O0_POS_B_GROUP_MEMBER_PStrainRelativeIR_CHOICE_H
#define C0P_PStrainRelativeRStrainRelativeM_INIT_OBJECTS_TRACERS__E3_10O0_POS_B_GROUP_MEMBER_PStrainRelativeIR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE StrainRelativeUTOMStrainRelativeTICStrainRelativeLLY EDITED WHEN THE
// CHOOSE COMMStrainRelativeND IS USED

// choose your init
#include "core/init/objects/object/init/pair/strain_relative/core.h"
#include "param/init/objects/tracers__e3_10o0/pos_b/group/_member/pair/strain_relative/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitTracersE310O0PosBGroupMemberPair = InitInitPairStrainRelative<InitTracersE310O0PosBGroupMemberPairStrainRelativeParameters, TypeObjectStep>;
}

#endif
