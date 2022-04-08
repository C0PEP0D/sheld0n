#ifndef C0P_PARAM_FLOW_REVERSE_FLOW_JHTDB_FORCED_ISOTROPIC_TURBULENCE_PARAMETERS_H
#define C0P_PARAM_FLOW_REVERSE_FLOW_JHTDB_FORCED_ISOTROPIC_TURBULENCE_PARAMETERS_H
#pragma once

#include "core/env/flow/jhtdb/forced_isotropic_turbulence/prop.h"
#include <string>

namespace c0p {

struct FlowReverseFlowJhtdbForcedIsotropicTurbulenceParameters {
    std::string authtoken = "edu.jhu.pha.turbulence.testing-201406";
};

}

#endif
