// std includes
#include <cmath>
#include <iostream>
// thirdparties includes
#include <Eigen/Dense>
// lib includes
#include "pl0f/flow.h"

using tScalar = double;
// linear Algebra
template<int Size>
using tVector = Eigen::Matrix<tScalar, Size, 1>;
// space
constexpr unsigned int Dim = 2;
using tSpaceVector = Eigen::Matrix<tScalar, Dim, 1>;
using tSpaceMatrix = Eigen::Matrix<tScalar, Dim, Dim>;
// ref and view
template<typename ...Args>
using tView = Eigen::Map<Args...>;

using tFlow = pl0f::PointVortexFlow<Dim, tSpaceVector, tSpaceMatrix, tView>;

const unsigned int n = 128;
const tScalar Step = 1.0;
const tScalar r0 = 16.0 * Step;
const tScalar w0 = 1.0;

int main () {
	// build data at random
	std::vector<tScalar> positionArray(n * Dim);
	std::vector<tScalar> vorticityArray(n);
	for(unsigned int index = 0; index < n; ++index) {
		tView<tSpaceVector> x(&(positionArray[index * Dim]));
		x = tSpaceVector::Random() * r0;
		vorticityArray[index] = tSpaceVector::Random()[0] * w0;
	}

	// flow
	tFlow flow(Step);
	flow.prepare(positionArray.data(), vorticityArray.data(), n);

	// query
	// // init
	tSpaceVector x;
	tSpaceVector u;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random();
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
	// // process
	x = tSpaceVector::Random() * r0;
	u = flow.getVelocity(x.data());
	std::cout << "u(" << x.transpose() << ") = " << u.transpose() <<std::endl;
}
