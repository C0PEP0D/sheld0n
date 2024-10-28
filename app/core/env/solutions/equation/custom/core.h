#ifndef C0P_CORE_ENV_SOLUTIONS_EQUATION_CUSTOM_CORE_H
#define C0P_CORE_ENV_SOLUTIONS_EQUATION_CUSTOM_CORE_H
#pragma once

// App includes
#include "core/env/solutions/core.h"
#include "core/env/solutions/equation/custom/prop.h"

namespace c0p {

template<typename _tParameters>
struct EquationCustom : public _tParameters::tEquation {
	using tParameters = _tParameters;
};

}

#endif
