#ifndef C0P_PARAM_OBJECTS_MOBJECT_NB_MANAGER_ADD_PARAMETERS_H
#define C0P_PARAM_OBJECTS_MOBJECT_NB_MANAGER_ADD_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/manager/add/prop.h"

#include "param/parameters.h"

namespace c0p {

// Add group members
struct InitMobjectNbManagerAddParameters {
	// Number of group members to add
    const unsigned int nb = 1;
};

}

#endif
