#ifndef C0P_PARAM_OBJECTS_OBJECT_POS_PAIR_STRAIN_RELATIVE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_POS_PAIR_STRAIN_RELATIVE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/pair/strain_relative/prop.h"

#include "param/parameters.h"

namespace c0p {

// Random initialisation of the position of the pair member B at a specific position with respect of the position of the pair member A
struct InitObjectPosPairStrainRelativeParameters {
    // Relative position of B with respect to A
    TypeSpaceVector position = TypeSpaceVector::Random().normalized() * Parameters::cLength;
};

}

#endif
