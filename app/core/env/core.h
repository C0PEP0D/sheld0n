#ifndef C0P_CORE_ENV_CORE_H
#define C0P_CORE_ENV_CORE_H
#pragma once

// std includes
#include <memory>
#include <map>
// lib includes
#include "s0ve/double.h"
#include "l0ad/ascii/double.h"
// app includes
#include "core/env/prop.h"
#include "param/env/flow/choice.h"

namespace c0p {

template<typename Parameters, typename Objects>
class Env {
    public:
        Parameters parameters;
        std::shared_ptr<Flow> sFlow;
        Objects objects;

        Env() : parameters(), sFlow(std::make_shared<Flow>()), objects(sFlow) {
        }
};

}

#endif
