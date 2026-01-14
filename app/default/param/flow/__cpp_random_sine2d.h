#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

#include <cmath> // fmod, sin
#include <vector>

namespace c0p {

struct Flow {

	inline static const double Velocity = 1.0;
	inline static const double Period = 1.0;
	
	inline static const std::vector<double> Phi0 = {
		3.448296944257913221e+00, 4.493667318642263986e+00, 3.787273988239316047e+00, 3.423602009535348323e+00, 2.661901610522321882e+00, 4.058272401214203740e+00, 2.749441536415439202e+00, 5.603175015853413043e+00, 6.054871697856187396e+00, 2.409234117248751250e+00, 4.974555126607196343e+00
	};
	inline static const std::vector<double> Phi1 = {
		3.323144788833375607e+00, 3.569129240088672272e+00, 5.815695198095265361e+00, 4.463327171489172573e-01, 5.474495357095673365e-01, 1.270359377317719085e-01, 5.231504780012940614e+00, 4.889303064250705155e+00, 5.466447546932162282e+00, 6.148840389253346750e+00, 5.021261348793251145e+00
	};

	// init

	static void init() {
		// nothing to do
	}

	// get

	static tSpaceVector getVelocity(const double* pX, const double t) {
		const double r = std::fmod(t/Period, 1.0);
		const unsigned int n = int(t/Period);
		if(r < 0.5) {
			return tSpaceVector({
				Velocity * std::sin(pX[1] + Phi1[n % Phi1.size()]),
				0.0
			});
		} else {
			return tSpaceVector({
				0.0,
				Velocity * std::sin(pX[0] + Phi0[n % Phi0.size()])
			});
		}
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		const double r = std::fmod(t/Period, 1.0);
		const unsigned int n = int(t/Period);
		
		tSpaceMatrix velocityGradients = tSpaceMatrix::Zero();
		
		if(r < 0.5) {
			velocityGradients(0, 1) = Velocity * std::cos(pX[1] + Phi1[n % Phi1.size()]);
		} else {
			velocityGradients(1, 0) = Velocity * std::cos(pX[0] + Phi0[n % Phi0.size()]);
		}
		return velocityGradients;
	};
	
	// prepare

	static void prepare(const double t) {
		// nothing to do
	}

	static void prepareVelocity(const double* pX, const double t) {
		// nothing to do
	}

	static void prepareVelocityGradients(const double* pX, const double t) {
		// nothing to do
	}
};

}

#endif
