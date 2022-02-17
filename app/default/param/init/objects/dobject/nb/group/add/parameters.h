#ifndef C0P_PARAM_OBJECTS_DOBJECT_NB_GROUP_ADD_PARAMETERS_H
#define C0P_PARAM_OBJECTS_DOBJECT_NB_GROUP_ADD_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/group/add/prop.h"

#include "param/parameters.h"

namespace c0p {

// Add group members
struct InitDobjectNbGroupAddParameters {
	// Number of group members to add
    const unsigned int nb = 2;
};

}

#endif
