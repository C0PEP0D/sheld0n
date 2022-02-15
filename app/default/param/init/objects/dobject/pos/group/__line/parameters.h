#ifndef C0P_PARAM_OBJECTS_DOBJECT_POS_GROUP_LINE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_DOBJECT_POS_GROUP_LINE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/group/line/prop.h"

#include "param/parameters.h"

namespace c0p {

// Group member position initialisation on a line parameters
struct InitDobjectPosGroupLineParameters {
    // Origin of the line
    TypeSpaceVector origin = TypeSpaceVector::Constant(M_PI);
    // Length and direction of the line
    TypeSpaceVector l = 10.0 * Parameters::cLength * TypeSpaceVector::Random().normalized();
};

}

#endif
