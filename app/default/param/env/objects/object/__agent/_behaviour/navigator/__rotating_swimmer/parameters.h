#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_ROTATING_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_ROTATING_SWIMMER_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/rotating_swimmer/prop.h"

namespace c0p {

// Parameters of the step of a navigator that controls its swimming direction
// delayed by a finite reorientation time
struct ObjectAgentBehaviourNavigatorRotatingSwimmerParameters {
	// Max angular swimming velocity
    double maxSwimmingAngularVelocity = 1.0 / Parameters::cTime;
    // Characteristic time to reach the preferential direction in a uniform flow.
    TypeScalar time = 1.0 * Parameters::cTime;
};

}

#endif
