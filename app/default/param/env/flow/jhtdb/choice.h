#ifndef C0P_PARAM_FLOW_JHTDB_CHOICE_H
#define C0P_PARAM_FLOW_JHTDB_CHOICE_H
#pragma once

// choose your flow
#include "core/env/flow/jhtdb/forced_isotropic_turbulence/core.h"
#include "param/env/flow/jhtdb/forced_isotropic_turbulence/parameters.h"
namespace c0p {
    using FlowJhtdb = FlowJhtdbForcedIsotropicTurbulence<FlowJhtdbForcedIsotropicTurbulenceParameters>;
}

#endif
