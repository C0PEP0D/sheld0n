#ifndef C0P_PARAM_FLOW_JHTDB_SIMPLE_PARAMETERS_H
#define C0P_PARAM_FLOW_JHTDB_SIMPLE_PARAMETERS_H
#pragma once

#include "core/env/flow/jhtdb/simple/prop.h"
#include <string>

namespace c0p {

struct FlowJhtdbSimpleParameters {
    std::string authtoken = "edu.jhu.pha.turbulence.testing-201406";
    std::string dataset = "isotropic1024coarse";
};

}

#endif
