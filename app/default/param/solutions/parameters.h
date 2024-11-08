#ifndef C0P_PARAM_SOLUTIONS_PARAMETERS_H
#define C0P_PARAM_SOLUTIONS_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std include
#include <filesystem>
//lib
#include "d0t/equation.h"
#include "s0ve/double.h"
#include "l0ad/ascii/double.h"

// FLAG: INCLUDE EQUATION BEGIN
// #include "param/solutions/source_of_points/parameters.h"
// #include "param/solutions/reactive_front/parameters.h"
 #include "param/solutions/passive_particles/parameters.h"
// FLAG: INCLUDE EQUATION END

namespace c0p {

struct SolutionsParameters {

	// ---------------- STATIC

	using tSolutionStatic = d0t::SolutionStatic<tSolver, 
		d0t::EquationComposed<
			// FLAG: DECLARE STATIC EQUATION BEGIN
			_PassiveParticles
			// FLAG: DECLARE STATIC EQUATION END
		>
	>;

	// ---------------- DYNAMIC

	// FLAG: DECLARE DYNAMIC EQUATION BEGIN
	// inline static d0t::SolutionDynamic<tSolver, _SourceOfPoints> solutionSourceOfPoints;
	// FLAG: DECLARE DYNAMIC EQUATION END

	static void stepDynamic(const double dt) {
		// FLAG: STEP DYNAMIC EQUATION BEGIN
		// solutionSourceOfPoints.step(dt);
		// FLAG: STEP DYNAMIC EQUATION END
	}

	static void saveDynamic(const std::string& folder) {
		// FLAG: SAVE DYNAMIC EQUATION BEGIN
		// if (not solutionSourceOfPoints.state.empty()) {
		//     s0ve::saveDouble(folder + "/" + _SourceOfPoints::tParameters::name + ".txt", solutionSourceOfPoints.state.data(), solutionSourceOfPoints.state.size());
		// }
		// FLAG: SAVE DYNAMIC EQUATION END
	}

	static void loadDynamic(const std::string& folder) {
		// FLAG: LOAD DYNAMIC EQUATION BEGIN
		// if(std::filesystem::exists(folder + "/" + _SourceOfPoints::tParameters::name + ".txt")) {
		//     l0ad::ascii::loadVectorDouble(folder + "/" + _SourceOfPoints::tParameters::name + ".txt", solutionSourceOfPoints.state);
		// }
		// FLAG: LOAD DYNAMIC EQUATION END
	}

	// ---------------- GROUPS

	// FLAG: DECLARE DYNAMIC EQUATION BEGIN
	// inline static d0t::SolutionGroups<tSolver, _ReactiveFront, _ReactiveFront::tParameters::tVariable> solutionReactiveFront;
	// FLAG: DECLARE DYNAMIC EQUATION END

	static void stepGroups(const double dt) {
		// FLAG: STEP DYNAMIC EQUATION BEGIN
		// solutionReactiveFront.step(dt);
		// FLAG: STEP DYNAMIC EQUATION END
	}

	static void saveGroups(const std::string& folder) {
		// FLAG: SAVE DYNAMIC EQUATION BEGIN
		// std::filesystem::create_directory(folder + "/" + _ReactiveFront::tParameters::name);
		// if (not _ReactiveFront::tParameters::tVariable::cStateMeta(solutionReactiveFront.states).empty()) {
		//     s0ve::saveDouble(folder + "/" + _ReactiveFront::tParameters::name + "/meta.txt", _ReactiveFront::tParameters::tVariable::cStateMeta(solutionReactiveFront.states).data(), _ReactiveFront::tParameters::tVariable::cStateMeta(solutionReactiveFront.states).size());
		// }
		// for(unsigned int groupIndex = 0; groupIndex < _ReactiveFront::tParameters::tVariable::groupNumber(solutionReactiveFront.states.size()); groupIndex++) {
		//     if (not _ReactiveFront::tParameters::tVariable::cState(solutionReactiveFront.states, groupIndex).empty()) {
		//         s0ve::saveDouble(folder + "/" + _ReactiveFront::tParameters::name + "/" + std::to_string(groupIndex) + ".txt", _ReactiveFront::tParameters::tVariable::cState(solutionReactiveFront.states, groupIndex).data(), _ReactiveFront::tParameters::tVariable::cState(solutionReactiveFront.states, groupIndex).size());
		//     }
		// }
		// FLAG: SAVE DYNAMIC EQUATION END
	}

	static void loadGroups(const std::string& folder) {
		// FLAG: LOAD DYNAMIC EQUATION BEGIN
		// unsigned int groupIndex = 0;
		// solutionReactiveFront.states.resize(1);
		// if(std::filesystem::exists(folder + "/" + _ReactiveFront::tParameters::name + "/meta.txt")) {
		//     l0ad::ascii::loadVectorDouble(folder + "/" + _ReactiveFront::tParameters::name + "/meta.txt", solutionReactiveFront.states.front());
		// }
		// while (std::filesystem::exists(folder + "/" + _ReactiveFront::tParameters::name + "/" + std::to_string(groupIndex) + ".txt")) {
		//     _ReactiveFront::tParameters::tVariable::pushBackGroup(solutionReactiveFront.states);
		//     l0ad::ascii::loadVectorDouble(folder + "/" + _ReactiveFront::tParameters::name + "/" + std::to_string(groupIndex) + ".txt", _ReactiveFront::tParameters::tVariable::state(solutionReactiveFront.states, groupIndex));
		//     groupIndex += 1;
		// }
		// FLAG: LOAD DYNAMIC EQUATION END
	}

	// ---------------- INIT

	static void initGroups() {
		// FLAG: DECLARE GROUPS INIT BEGIN
		// Init_ReactiveFront::set(SolutionsParameters::solutionReactiveFront.states);
		// FLAG: DECLARE GROUPS INIT END
	}

	// ---------------- POST

	static void postGroups(const double t) {
		// FLAG: DECLARE GROUPS INIT BEGIN
		// Init_ReactiveFront::set(SolutionsParameters::solutionReactiveFront.states);
		// FLAG: DECLARE GROUPS INIT END
	}
	
};

}

#endif
