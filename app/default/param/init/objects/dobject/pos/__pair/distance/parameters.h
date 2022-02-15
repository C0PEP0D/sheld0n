#ifndef C0P_PARAM_OBJECTS_DOBJECT_POS_PAIR_DISTANCE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_DOBJECT_POS_PAIR_DISTANCE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/pair/distance/prop.h"

#include "param/parameters.h"

namespace c0p {

// Random initialisation of the position of the pair member B at a specific distance of the pair member A parameters
struct InitDobjectPosPairDistanceParameters {
    // Initial distance between A and B
    double distance = 1.0 * Parameters::cLength;
};

}

#endif
