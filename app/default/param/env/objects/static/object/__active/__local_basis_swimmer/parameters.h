#ifndef C0P_PARAM_OBJECTS_OBJECT_ACTIVE_LOCAL_BASIS_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_ACTIVE_LOCAL_BASIS_SWIMMER_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/active/local_basis_swimmer/prop.h"

// parameters
#include "param/parameters.h"

namespace c0p {

// Parameters of the step of a swimmer that swims in the direction
// of its local axis that may rotate due to the surrounding flow
struct ObjectActiveLocalBasisSwimmerStepParameters {
    // Swimming velocity
    TypeScalar velocity = 1.0 * Parameters::cVelocity;
    // Swimming local axis
    TypeSpaceVector swimAxis = TypeSpaceVector({1.0, 0.0, 0.0});
    // Local axis that will align
    TypeSpaceVector alignAxis = TypeSpaceVector({1.0, 0.0, 0.0});
    // Preferred global direction
    TypeSpaceVector direction = TypeSpaceVector::Random().normalized();
    // Characteristic time to reach the prefered direction in a uniform flow.
    TypeScalar time = 1.0 * Parameters::cTime;
};

}

#endif
