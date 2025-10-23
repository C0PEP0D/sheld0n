#ifndef C0P_CORE_SOLUTIONS_CORE_H
#define C0P_CORE_SOLUTIONS_CORE_H
#pragma once

// std includes
#include <string>
#include <memory>
#include <execution>
#include <iomanip>
// lib includes
#include "d0t/equation.h"

namespace c0p {

template<typename tParameters>
class Solutions {
	public:
		Solutions() : t(0.0) {
		}
	public:

		// ---------------- INIT

		void init() {
			tParameters::init(stateArray);
		}

		// ---------------- STEP
	
		void step(const double dt) {
			// build solver input
			std::vector<double*> pStateArray(stateArray.size());
			std::vector<unsigned int> stateSizeArray(stateArray.size());
			for(unsigned int index = 0; index < stateArray.size(); ++index) {
				pStateArray[index] = stateArray[index].data();
				stateSizeArray[index] = stateArray[index].size();
			}
			// call solver
			tSolver::step(
				[](const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t) {
					tParameters::prepare(pStateArray, pStateSize, arraySize, t); // prepare
					return tParameters::stateTemporalDerivative(pStateArray, pStateSize, arraySize, t); // execute
				}, pStateArray.data(), stateSizeArray.data(), pStateArray.size(), t, dt
			);
			// increment time
			t += dt;
			// constrain variables
			tParameters::prepare(pStateArray.data(), stateSizeArray.data(), pStateArray.size(), t);
			tParameters::constrain(stateArray, t);
		}

		// ---------------- SAVE & LOAD

		void save(const std::string& folder) {
			// build input input
			std::vector<double*> pStateArray(stateArray.size());
			std::vector<unsigned int> stateSizeArray(stateArray.size());
			for(unsigned int index = 0; index < stateArray.size(); ++index) {
				pStateArray[index] = stateArray[index].data();
				stateSizeArray[index] = stateArray[index].size();
			}
			// send
			tParameters::save(folder, pStateArray.data(), stateSizeArray.data(), pStateArray.size());
		}
	
		void load(const std::string& folder) {
			tParameters::load(folder, stateArray);
		}
		
		// ---------------- POST

		void post(const std::string& folder, const double& t) {
			// build input input
			std::vector<double*> pStateArray(stateArray.size());
			std::vector<unsigned int> stateSizeArray(stateArray.size());
			for(unsigned int index = 0; index < stateArray.size(); ++index) {
				pStateArray[index] = stateArray[index].data();
				stateSizeArray[index] = stateArray[index].size();
			}
			// send
			tParameters::post(folder, pStateArray.data(), stateSizeArray.data(), pStateArray.size(), t);
		}
		
	public:
		double t;
		std::vector<std::vector<double>> stateArray;
};

}

#endif
