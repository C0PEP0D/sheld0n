#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_ON_OFF_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_ON_OFF_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/on_off/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of the behaviour that adapts swimming velocity to move as fast as possible
struct ObjectAgentBehaviourNavigatorBehaviourVelocityOnOffParameters {
	const double threshold = std::cos(0.5 * M_PI);
};

}

#endif
