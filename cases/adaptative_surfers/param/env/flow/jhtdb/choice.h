#ifndef C0P_PARAM_FLOW_JHTDB_CHOICE_H
#define C0P_PARAM_FLOW_JHTDB_CHOICE_H
#pragma once

// choose your flow
#include "core/env/flow/jhtdb/simple/core.h"
#include "param/env/flow/jhtdb/simple/parameters.h"
namespace c0p {
    using FlowJhtdb = FlowJhtdbSimple<FlowJhtdbSimpleParameters>;
}

#endif
