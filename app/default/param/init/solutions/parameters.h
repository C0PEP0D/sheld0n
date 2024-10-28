#ifndef C0P_PARAM_INIT_SOLUTIONS_PARAPETERS_H
#define C0P_PARAM_INIT_SOLUTIONS_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std include
#include <vector>
// app include
#include "core/init/solutions/prop.h"
// FLAG: INCLUDE EQUATION BEGIN
// #include "param/init/solutions/reactive_front/choice.h"
// FLAG: INCLUDE EQUATION END

namespace c0p {

struct InitSolutionsParameters {
	using tInitStatic = StaticInitComposed<
		// FLAG: DECLARE STATIC INIT BEGIN
		// FLAG: DECLARE STATIC INIT END
	>;

	static void setGroups() {
		// FLAG: DECLARE GROUPS INIT BEGIN
		// Init_ReactiveFront::set(SolutionsParameters::solutionReactiveFront.states);
		// FLAG: DECLARE GROUPS INIT END
	}
};

}

#endif
