#ifndef C0P_PARAM_SOLUTIONS_PARAMETERS_H
#define C0P_PARAM_SOLUTIONS_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std include
#include <filesystem>
#include <tuple>
// lib
#include "d0t/equation.h"
#include "s0ve/double.h"
#include "l0ad/ascii/double.h"
// param
#include "param/flow/parameters.h"

// FLAG: INCLUDE EQUATION BEGIN
// #include "param/solutions/source_of_points/parameters.h"
// #include "param/solutions/reactive_front/parameters.h"
#include "param/solutions/passive_particles/parameters.h"
// FLAG: INCLUDE EQUATION END

namespace c0p {

struct SolutionsParameters {

	// ---------------- INIT

	static void allocate(std::vector<std::vector<double>>& stateArray) {
		// init static StateIndex
		unsigned int stateIndex = 0;
		// FLAG: STATE INDEX STATIC EQUATION BEGIN
		_PassiveParticles::tParameters::StateIndex = stateIndex;
		stateIndex += _PassiveParticles::tVariable::Size;
		// FLAG: STATE INDEX STATIC EQUATION END
		stateArray.resize(1);
		stateArray[0].resize(stateIndex);
		stateIndex = 1;
		// FLAG: STATE INDEX DYNAMIC EQUATION BEGIN
		// FLAG: STATE INDEX DYNAMIC EQUATION END
		stateArray.resize(stateIndex);
	}

	static void init(std::vector<std::vector<double>>& stateArray) {
		allocate(stateArray);
		// get pointers
		std::vector<double*> pStateArray(stateArray.size());
		std::vector<unsigned int> stateSizeArray(stateArray.size());
		for(unsigned int index = 0; index < stateArray.size(); ++index) {
			pStateArray[index] = stateArray[index].data();
			stateSizeArray[index] = stateArray[index].size();
		}
		// FLAG: INIT STATIC EQUATION BEGIN
		_PassiveParticles::tParameters::init(pStateArray[0] + _PassiveParticles::tParameters::StateIndex);
		// FLAG: INIT STATIC EQUATION END
		// FLAG: INIT DYNAMIC EQUATION BEGIN
		// FLAG: INIT DYNAMIC EQUATION END
	}
	
	// ---------------- PREPARE

	static void prepare(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t) {
		// FLAG: PREPARE STATIC EQUATION BEGIN
		_PassiveParticles::prepare(pStateArray[0] + _PassiveParticles::tParameters::StateIndex, _PassiveParticles::tVariable::Size, t);
		// FLAG: PREPARE STATIC EQUATION END
		// FLAG: PREPARE DYNAMIC EQUATION BEGIN
		// FLAG: PREPARE DYNAMIC EQUATION END
	}

	// ---------------- TEMPORAL DERIVATIVE

	static std::vector<std::vector<double>> stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t) {
		std::vector<std::vector<double>> output(arraySize);
		for(unsigned int index = 0; index < output.size(); ++index) {
			output[index].resize(pStateSize[index]);
		}
		// FLAG: STATE TEMPORAL DERIVATIVE STATIC EQUATION BEGIN
		// tView<tStateVectorDynamic>(output[0].data() + _PassiveParticles::tParameters::StateIndex, _PassiveParticles::tVariable::Size) = _PassiveParticles::stateTemporalDerivative(pStateArray[0] + _PassiveParticles::tParameters::StateIndex, _PassiveParticles::tVariable::Size, t);
		tView<tStateVectorDynamic>(output[0].data() + _PassiveParticles::tParameters::StateIndex, _PassiveParticles::tVariable::Size) = _PassiveParticles::stateTemporalDerivative(pStateArray, pStateSize, arraySize, t);
		// FLAG: STATE TEMPORAL DERIVATIVE STATIC EQUATION END
		// FLAG: STATE TEMPORAL DERIVATIVE DYNAMIC EQUATION BEGIN
		// FLAG: STATE TEMPORAL DERIVATIVE DYNAMIC EQUATION END
		return output;
	}

	// ---------------- CONSTRAIN
	
	static void constrain(std::vector<std::vector<double>>& stateArray, const double t) {
		// FLAG: CONSTRAIN STATIC EQUATION BEGIN
		_PassiveParticles::tVariable::constrain(stateArray, t, _PassiveParticles::tParameters::StateIndex);
		// FLAG: CONSTRAIN STATIC EQUATION END
		// FLAG: CONSTRAIN DYNAMIC EQUATION BEGIN
		// FLAG: CONSTRAIN DYNAMIC EQUATION END
	}

	// ---------------- SAVE & LOAD

	static void save(const std::string& folder, const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize) {
		// FLAG: SAVE STATIC EQUATION BEGIN
		s0ve::saveDouble(folder + "/" + _PassiveParticles::tParameters::name + ".txt", pStateArray[0] + _PassiveParticles::tParameters::StateIndex, _PassiveParticles::tVariable::Size);
		// FLAG: SAVE STATIC EQUATION END
		// FLAG: SAVE DYNAMIC EQUATION BEGIN
		// FLAG: SAVE DYNAMIC EQUATION END
	}

	static void load(const std::string& folder, std::vector<std::vector<double>>& stateArray) {
		allocate(stateArray);
		// FLAG: LOAD STATIC EQUATION BEGIN
		l0ad::ascii::loadDouble(folder + "/" + _PassiveParticles::tParameters::name + ".txt", stateArray[0].data() + _PassiveParticles::tParameters::StateIndex, _PassiveParticles::tVariable::Size);
		// FLAG: LOAD STATIC EQUATION END
		// FLAG: LOAD DYNAMIC EQUATION BEGIN
		// FLAG: LOAD DYNAMIC EQUATION END
	}

	// ---------------- POST PROCESS

	static void post(const std::string& folder, const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t) {
		// FLAG: POST STATIC EQUATION BEGIN
		s0ve::saveMapToCsvDouble(folder + "/" + _PassiveParticles::tParameters::name + ".csv", _PassiveParticles::tParameters::post(pStateArray[0] + _PassiveParticles::tParameters::StateIndex, t), ",", "#");
		// FLAG: POST STATIC EQUATION END
		// FLAG: POST DYNAMIC EQUATION BEGIN
		// FLAG: POST DYNAMIC EQUATION END
	}

// 	// ---------------- GROUPS
// 
// 	// FLAG: DECLARE DYNAMIC EQUATION BEGIN
// 	// inline static d0t::SolutionGroups<tSolver, _ReactiveFront, _ReactiveFront::tParameters::tVariable> solutionReactiveFront;
// 	// FLAG: DECLARE DYNAMIC EQUATION END
// 
// 	static void stepGroups(const double dt) {
// 		// FLAG: STEP DYNAMIC EQUATION BEGIN
// 		// solutionReactiveFront.step(dt);
// 		// FLAG: STEP DYNAMIC EQUATION END
// 	}
// 
// 	static void saveGroups(const std::string& folder) {
// 		// FLAG: SAVE DYNAMIC EQUATION BEGIN
// 		// std::filesystem::create_directory(folder + "/" + _ReactiveFront::tParameters::name);
// 		// if (not _ReactiveFront::tParameters::tVariable::cStateMeta(solutionReactiveFront.states).empty()) {
// 		//     s0ve::saveDouble(folder + "/" + _ReactiveFront::tParameters::name + "/meta.txt", _ReactiveFront::tParameters::tVariable::cStateMeta(solutionReactiveFront.states).data(), _ReactiveFront::tParameters::tVariable::cStateMeta(solutionReactiveFront.states).size());
// 		// }
// 		// for(unsigned int groupIndex = 0; groupIndex < _ReactiveFront::tParameters::tVariable::groupNumber(solutionReactiveFront.states.size()); groupIndex++) {
// 		//     if (not _ReactiveFront::tParameters::tVariable::cState(solutionReactiveFront.states, groupIndex).empty()) {
// 		//         s0ve::saveDouble(folder + "/" + _ReactiveFront::tParameters::name + "/" + std::to_string(groupIndex) + ".txt", _ReactiveFront::tParameters::tVariable::cState(solutionReactiveFront.states, groupIndex).data(), _ReactiveFront::tParameters::tVariable::cState(solutionReactiveFront.states, groupIndex).size());
// 		//     }
// 		// }
// 		// FLAG: SAVE DYNAMIC EQUATION END
// 	}
// 
// 	static void loadGroups(const std::string& folder) {
// 		// FLAG: LOAD DYNAMIC EQUATION BEGIN
// 		// unsigned int groupIndex = 0;
// 		// solutionReactiveFront.states.resize(1);
// 		// if(std::filesystem::exists(folder + "/" + _ReactiveFront::tParameters::name + "/meta.txt")) {
// 		//     l0ad::ascii::loadVectorDouble(folder + "/" + _ReactiveFront::tParameters::name + "/meta.txt", solutionReactiveFront.states.front());
// 		// }
// 		// while (std::filesystem::exists(folder + "/" + _ReactiveFront::tParameters::name + "/" + std::to_string(groupIndex) + ".txt")) {
// 		//     _ReactiveFront::tParameters::tVariable::pushBackGroup(solutionReactiveFront.states);
// 		//     l0ad::ascii::loadVectorDouble(folder + "/" + _ReactiveFront::tParameters::name + "/" + std::to_string(groupIndex) + ".txt", _ReactiveFront::tParameters::tVariable::state(solutionReactiveFront.states, groupIndex));
// 		//     groupIndex += 1;
// 		// }
// 		// FLAG: LOAD DYNAMIC EQUATION END
// 	}
// 
// 	// ---------------- INIT
// 
// 	static void initGroups() {
// 		// FLAG: DECLARE GROUPS INIT BEGIN
// 		// Init_ReactiveFront::set(SolutionsParameters::solutionReactiveFront.states);
// 		// FLAG: DECLARE GROUPS INIT END
// 	}
// 
// 	// ---------------- POST
// 
// 	static void postGroups(const double t) {
// 		// FLAG: DECLARE GROUPS INIT BEGIN
// 		// Init_ReactiveFront::set(SolutionsParameters::solutionReactiveFront.states);
// 		// FLAG: DECLARE GROUPS INIT END
// 	}
	
};

}

#endif
