#ifndef C0P_PARAM_FLOW_JHTDB_CHOICE_H
#define C0P_PARAM_FLOW_JHTDB_CHOICE_H
#pragma once

// choose your flow
#include "core/env/flow/jhtdb/channel_flow/core.h"
#include "param/env/flow/jhtdb/channel_flow/parameters.h"
namespace c0p {
    using FlowJhtdb = FlowJhtdbChannelFlow<FlowJhtdbChannelFlowParameters>;
}

#endif
