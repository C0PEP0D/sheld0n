#ifndef C0P_CORE_ENV_CORE_H
#define C0P_CORE_ENV_CORE_H
#pragma once

// app includes
#include "core/env/prop.h"
#include "param/env/flow/choice.h"
#include "core/env/solutions/core.h"
#include "param/env/solutions/parameters.h"

namespace c0p {

template<typename tParameters>
class Env {
	public:
		Solutions<SolutionsParameters> solutions;
	public:
		Env() {
		}
};

}

#endif
