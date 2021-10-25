#ifndef C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_ACTIVE_PASSIVE_SPHEROID_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_ACTIVE_PASSIVE_SPHEROID_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/passive/spheroid/prop.h"

namespace c0p {

// Parameters of a spheroid that can be advected and rotated by the flow
struct ObjectPairAAgentActivePassiveSpheroidStepParameters {
    // Proportion: fraction of the big axis avec the small axis
    TypeScalar proportion = 1.0;
};

}

#endif
