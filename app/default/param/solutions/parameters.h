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
#include "s0ve/ascii/double.h"
#include "l0ad/ascii/double.h"
#include "s0ve/bin/save.h"
#include "l0ad/bin/load.h"

// param
#include "param/flow/parameters.h"

// FLAG: INCLUDE EQUATION BEGIN
#include "param/solutions/passive_particles/parameters.h"
// FLAG: INCLUDE EQUATION END

namespace c0p {

struct SolutionsParameters {

	constexpr static const bool isSaveASCII = false;

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
		Flow::prepare(t);
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
		saveSolution(folder + "/" + _PassiveParticles::tParameters::name, pStateArray[0] + _PassiveParticles::tParameters::StateIndex, _PassiveParticles::tVariable::Size);
		// FLAG: SAVE STATIC EQUATION END
		// FLAG: SAVE DYNAMIC EQUATION BEGIN
		// FLAG: SAVE DYNAMIC EQUATION END
	}

	static void saveSolution(const std::string& filename, const double* data, const unsigned int size) {
		if(isSaveASCII) {
			s0ve::ascii::saveDouble(filename + ".txt", data, size);
		} else {
			s0ve::bin::save(filename + ".bin", data, size);
		}
	}

	static void load(const std::string& folder, std::vector<std::vector<double>>& stateArray) {
		allocate(stateArray);
		// FLAG: LOAD STATIC EQUATION BEGIN
		// l0ad::ascii::loadDouble(folder + "/" + _PassiveParticles::tParameters::name + ".txt", stateArray[0].data() + _PassiveParticles::tParameters::StateIndex, _PassiveParticles::tVariable::Size);
		loadStaticSolution(folder + "/" + _PassiveParticles::tParameters::name, stateArray[0].data() + _PassiveParticles::tParameters::StateIndex, _PassiveParticles::tVariable::Size);
		// FLAG: LOAD STATIC EQUATION END
		// FLAG: LOAD DYNAMIC EQUATION BEGIN
		// FLAG: LOAD DYNAMIC EQUATION END
	}

	static void loadStaticSolution(const std::string& filename, double* data, const unsigned int size) {
		if(isSaveASCII) {
			l0ad::ascii::loadDouble(filename + ".txt", data, size);
		} else {
			l0ad::bin::load(filename + ".bin", data, size);
		}
	}

	static void loadDynamicSolution(const std::string& filename, std::vector<double>& data) {
		if(isSaveASCII) {
			l0ad::ascii::loadVectorDouble(filename + ".txt", data);
		} else {
			l0ad::bin::loadVector(filename + ".bin", data);
		}
	}

	// ---------------- POST PROCESS

	static void post(const std::string& folder, const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t) {
		// FLAG: POST STATIC EQUATION BEGIN
		s0ve::ascii::saveMapToCsvDouble(folder + "/" + _PassiveParticles::tParameters::name + ".csv", _PassiveParticles::tParameters::post(pStateArray[0] + _PassiveParticles::tParameters::StateIndex, t), ",", "#");
		// FLAG: POST STATIC EQUATION END
		// FLAG: POST DYNAMIC EQUATION BEGIN
		// FLAG: POST DYNAMIC EQUATION END
	}
	
};

}

#endif
