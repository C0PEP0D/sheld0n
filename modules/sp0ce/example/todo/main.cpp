// std includes
#include <memory> // shared_ptr
#include <cmath>
#include <iostream>
// thirdparties includes
#include <Eigen/Dense>
// lib includes
#include "s0s/runge_kutta_fehlberg.h"
// testing lib include
#include "d0t/variable.h"
#include "d0t/variables/vector.h"
#include "d0t/equation.h"
#include "d0t/equations/advection.h"
// simple includes
#include "flow.h"

using TypeScalar = double;
// linear Algebra
template<int Size>
using tVector = Eigen::Matrix<TypeScalar, Size, 1>;
// space
constexpr unsigned int Dim = 3;
using tSpaceVector = Eigen::Matrix<TypeScalar, Dim, 1>;
// ref and view
template<typename ...Args>
using tRef = Eigen::Ref<Args...>;
template<typename ...Args>
using tView = Eigen::Map<Args...>;
// solver
using tSolver = s0s::SolverRungeKuttaFehlberg<tVector<Eigen::Dynamic>, tView>;
// flow
using tFlow = Flow<tSpaceVector, tRef>;

// creating variable, equation and solution
class Point : public d0t::VariableComposed<d0t::VariableVector<tVector, Dim, tView>> {
	// public:
		// using tType = d0t::VariableComposed<d0t::VariableVector<tVector, Dim, tView>;
		// template<unsigned int Index>
		// using tType::tVariableComponent<Index>;
	public:
		using tPosition = tVariableComponent<0>::type;
		static constexpr auto statePosition = state<0>;
		static constexpr auto cStatePosition = cState<0>;
	public:
		using tStateVectorDynamic = typename tPosition::tStateVectorDynamic;
		using tSpaceVector = typename tPosition::tSpaceVector;
};
using tEquation = d0t::EquationAdvection<Point, tFlow>;
using tSolution = d0t::SolutionStatic<tSolver, tEquation>;

int main () { 
    tSpaceVector x0 = tSpaceVector::Constant(1.0);
    double dt = 1e-3;
    double tEnd = 1.0;
    unsigned int nt = std::round(tEnd / dt);
    // Create equation and solution
    std::shared_ptr<tEquation> sEquationAdvection = std::make_shared<tEquation>(std::make_shared<tFlow>());
    tSolution solution(sEquationAdvection);
    // Set initial state
    Point::tPosition::get(Point::statePosition(solution.state.data())) = x0;
    // Computation
    for(std::size_t i = 0; i < nt; i++) {
        solution.step(dt);
    }
    // out
    std::cout << "\n";
    std::cout << "Point advected following a an exponential flow, exp(" << solution.t << ") = " << "\n";
    std::cout << "\n";
    std::cout << "Point Final Position : " << "\n" << Point::tPosition::cGet(Point::statePosition(solution.state.data())) << "\n";
    std::cout << std::endl;
}
