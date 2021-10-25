#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_PROP_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_PROP_H
#pragma once

// std includes
#include <tuple>
// lib includes
#include "sa0/agent.h"
// app include
#include "core/env/objects/object/prop.h"

namespace c0p {

template<typename AgentActiveStep, typename TypeBehaviour>
using TypeAgentStep = sl0::sa0::StepAgent<TypeVector, TypeRef, TypeView, AgentActiveStep, TypeBehaviour>;

}

#endif
