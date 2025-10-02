#ifndef C0P_CORE_ENV_PROP_H
#define C0P_CORE_ENV_PROP_H
#pragma once

// thirdparties includes
#include <Eigen/Dense>
// std
#include <random>
#include <mutex>
#include <charconv>   // std::from_chars
#include <cctype>   // std::isdigit
// lib includes
#include "s0s/runge_kutta_fehlberg.h"
#include "d0t/variables/vector.h"
// app includes
#include "param/parameters.h"

namespace c0p {

// Type Declarations

using tScalar = double;
// Algebra
template<const int ...Args>
using tMatrix = Eigen::Matrix<tScalar, Args...>;
template<const int Size>
using tVector = tMatrix<Size, 1>;
template<typename ...Args>
using tView = Eigen::Map<Args...>;
using tStateVectorDynamic = tVector<Eigen::Dynamic>;
using tMatrixDynamic = tMatrix<Eigen::Dynamic, Eigen::Dynamic>;
// Solver
using tSolver = s0s::SolverRungeKuttaFehlberg<tStateVectorDynamic, tView>;

template<const int ...Args>
void set(tMatrix<Args...>& m, const unsigned int i, const unsigned int j, const tScalar v) {
	m(i, j) = v;
}

template<const int ...Args>
void set(tMatrix<Args...>& m, const char* cstr) {
	const char* ptr = cstr;
	unsigned int index = 0;

	while (not std::isdigit(*ptr) && *ptr != '.' && *ptr != '-' && *ptr != '\0') ptr++;
	
	while (*ptr != '\0') {
		double value;
		auto result = std::from_chars(ptr, ptr + std::strlen(ptr), value);

		if (result.ec != std::errc()) {
			std::cerr << "Failed to parse matrix!\n";
			break;
		}

		m.template reshaped<Eigen::RowMajor>()[index] = value;
		ptr = result.ptr;

		while (not std::isdigit(*ptr) && *ptr != '.' && *ptr != '-' && *ptr != '\0') ptr++;
		index++;
	}
}

inline std::mutex printMutex;
template <typename T>
void print(const T& v) {
	printMutex.lock();
	std::cout << v << std::endl;
	printMutex.unlock();
}

namespace rand0m {
	inline std::random_device device;
	inline std::default_random_engine engine(device());
	// distribution
	inline std::normal_distribution<> standardNormalDistribution(0.0, 1.0);
	inline std::uniform_real_distribution<> uniformRealDistribution(-1.0, 1.0);

	inline void seed(unsigned int p_seed) {
		engine.seed(p_seed);
		std::srand(p_seed);
	}
}

}

#endif
