#ifndef C0P_CORE_SOLUTIONS_EQUATION_CUSTOM_CORE_H
#define C0P_CORE_SOLUTIONS_EQUATION_CUSTOM_CORE_H
#pragma once

// App includes
#include "core/solutions/core.h"
#include "core/solutions/equation/custom/prop.h"

namespace c0p {

template<typename _tParameters>
struct EquationCustom : public _tParameters::tEquation {
	using tParameters = _tParameters;
};

}

#endif
