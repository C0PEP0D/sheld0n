// Std includes
#include <array>
#include <bits/c++config.h>
#include <memory>
#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <filesystem> // Carefull, this is c++17
// Thirdparties includes
#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>
// Lib includes
#include "s0s/solver.h"
#include "sl0/point.h"
#include "sl0/memory.h"
#include "sa0/actuator/point.h"
#include "sa0/behaviour.h"
#include "sa0/agent.h"
#include "sa0/sensor/computer.h"
#include "sa0/sensor/point.h"
#include "sa0/sensor/average.h"
#include "fl0w/kinematic.h"

const unsigned int MEMORY_N = 10;
const unsigned int N = 3;

using TypeScalar = double;
using TypeVector = Eigen::Matrix<TypeScalar, N, 1>;
using TypeMatrix = Eigen::Matrix<TypeScalar, N, N>;
template<typename ...Args>
using TypeView = Eigen::Map<Args...>;
template<typename A, template<typename ...Args> class B, typename C>
using TypeSolver = s0s::SolverRungeKuttaFehlberg<A, B, C>;
using TypeFlow = fl0w::kinematic::Kinematic<TypeVector, TypeMatrix, std::vector>;

// Point
using TypeState = TypeVector;
template<typename TypeState>
using TypeStepObject = sl0::StepPoint<TypeState, TypeView, TypeVector, TypeFlow>;

// Actuators
template<typename TypeState>
using TypeStepSwim = sl0::sa0::StepSwim<TypeState, TypeStepObject<TypeState>, TypeVector>;
template<typename TypeState>
using TypeStepActuators = sl0::sa0::StepActuators<TypeState, TypeStepObject<TypeState>, std::vector>;

// Memory Object
using TypeStateMemory = Eigen::Matrix<TypeScalar, (N + 1) * MEMORY_N, 1>;
template<typename ...Args>
using TypeContainer = std::vector<Args...>;
template<typename TypeStateMemory>
using TypeStepMemory = sl0::StepMemory<TypeStateMemory, TypeView, TypeContainer, TypeStepActuators, TypeState>;

// Sensors TODO problem with sensors
using TypeSensorDirection = sl0::sa0::SensorDirection<TypeVector, std::vector<double>, TypeStateMemory, TypeStepMemory<TypeStateMemory>>;
using TypeSensorJacobian = sl0::sa0::SensorJacobian<TypeMatrix, std::vector<double>, TypeStateMemory, TypeStepMemory<TypeStateMemory>, TypeVector, TypeFlow>;
using TypeSensorAverageJacobian = sl0::sa0::SensorAverage<sl0::sa0::SensorJacobian, TypeMatrix, std::vector<double>, TypeStateMemory, TypeStepMemory<TypeStateMemory>, TypeState, TypeStepObject<TypeState>, TypeVector, TypeFlow>;

// Observation
using TypeObservation = std::tuple<TypeVector, TypeMatrix>;
//using TypeObservers = std::tuple<TypeSensorDirection, TypeSensorAverageJacobian>;
using TypeObservers = std::tuple<TypeSensorDirection, TypeSensorJacobian>;

// Behaviour
using TypeBehaviour = sl0::sa0::BehaviourSwim<TypeObservation, TypeStepSwim<TypeState>>;
// // Define custom behaviour based on direction
class BehaviourCustomDir : public TypeBehaviour {
    public:
        using TypeBehaviour::TypeBehaviour;
        void act(const TypeObservation& observation) const override {
            // Get sensed data
            const auto dir = std::get<0>(observation);
            // Set velocity direction
            sStepSwim->velocity = dir;
        };
    public:
        using TypeBehaviour::sStepSwim;
};
// // Define custom behaviour based on jacobian and direction
class BehaviourCustomJac : public TypeBehaviour {
    public:
        using TypeBehaviour::TypeBehaviour;
        void act(const TypeObservation& observation) const override {
            // Get sensed data
            const auto dir = std::get<0>(observation);
            const auto jac = std::get<1>(observation);
            // Set velocity direction
            sStepSwim->velocity = ((((jac * T).exp() - TypeMatrix::Identity()) * jac.inverse()).transpose() * dir).normalized();
        };
    public:
        using TypeBehaviour::sStepSwim;
        double T;
};
// // Define custom behaviour based on jacobian and direction
class BehaviourCustomJacT : public TypeBehaviour {
    public:
        using TypeBehaviour::TypeBehaviour;
        void act(const TypeObservation& observation) const override {
            // Get sensed data
            const auto dir = std::get<0>(observation);
            const auto jac = std::get<1>(observation);
            // Compute T
            double T = alpha / jac.norm();
            // Set velocity direction
            sStepSwim->velocity = ((((jac * T).exp() - TypeMatrix::Identity()) * jac.inverse()).transpose() * dir).normalized();
        };
    public:
        using TypeBehaviour::sStepSwim;
        double alpha;
};

// Agent
using TypeStepAgent = sl0::sa0::StepAgent<TypeStateMemory, TypeStepMemory, BehaviourCustomJac, TypeObservers, TypeObservation>;
using TypeAgent = sl0::Object<TypeStateMemory, TypeView, TypeSolver, TypeStepAgent>;
// Define your agent
class AgentCustom : public TypeAgent {
    public:
        using TypeAgent::TypeAgent;
    public:
        void init() override {
            TypeAgent::init();
            // Sensors
            // // Direction
            std::get<0>(step.observers).direction << 1.0, 0.0, 0.0;
            // // Jacobian
            std::get<1>(step.observers).sFlow = TypeAgent::step.stepObject.sFlow;
        }
    public:
        // Sensors
        using TypeAgent::step;
};

class Environnement {
    public:
        // Parameters declaration
        // // Random
        std::size_t seed;
        // // Time
        std::size_t nt;
        double dt;
        double t;
        // Flow
        std::size_t nk;
        double k0;
        double nu;
        double eps;
        double l;
        double lambda; // Pulsation generator parameter
        // // Agents
        double sizeRatio;
        TypeVector proportions;
        double velocity;
        double T;
        double Te;
        //double alpha;
        // Macro params
        std::size_t na;
        double ra;
        // // Save
        std::size_t nsave;

        // Parameter initialisation
        void init() {
            std::string separation(" -------------------- ");
            std::string space(" = ");

            // --------------------------------------------- Random
            seed = 0; // Must be defined before the defineFluid call
            
            // --------------------------------------------- Fluid
            // Numerical
            nk = 100;
            // Physical
            k0 = 1.6; // Komogorov constant
            nu = 1e-6; // Kinematic viscosity
            eps = 1e-5; // Dissipation rate
            l = 1e-2; // Scale of "the biggest eddys"
            // Time
            lambda = 0.4; // should be arround 0.4, 0.0 means a frozen flow

            initFlow(); // Let's define the flow here so that we can use it's properties to define the rest

            // --------------------------------------------- Agent
            // Particle
            sizeRatio = 1.0;
            proportions = {sizeRatio, 1.0, 1.0};
            // Active
            velocity = 1.0 * sFlow->uEta;
            T = 0.5 * sFlow->tauEta;
            Te = 0.2 * sFlow->tauEta;
            //alpha = 1.0;
            // --------------------------------------------- Simulation
            // Agents
            na = 100; // Number of agents
            ra = 100.0 * sFlow->l; // Agents initial distribution radius
            // Time
            nt = 1000; // Number of time steps
            dt = 0.1 * sFlow->tauEta; // Time step
            // Save Parameters
            nsave = 100; // Number of frame saved
            
            initAgents(); // Let's now define the agents

            // --------------------------------------------- Init Save
            // Create dir
            std::filesystem::create_directory("time");

        }

        // // Environnement
        std::shared_ptr<TypeFlow> sFlow; // Fluid
        std::vector<AgentCustom> agents; // Agents
        
        void initFlow() {
            sFlow = std::make_shared<TypeFlow>();
            sFlow->sRandomGenerator->setSeed(seed);
            *sFlow->sNk = nk; // number of fourier modes
            *sFlow->sK0 = k0; // Komogorov constant
            sFlow->createFromDissipationRate(nu, eps, l);
            sFlow->sOGen->lambda = lambda;
            sFlow->init();
        }
        
        void initAgents() {
            // TODO TODO TODO THIS IS A BIG PROBLEM TODO TODO TODO
            // TODO DYNAMIC ASSIGNEMENT PROBLEM TODO REALY DEAL WITH IT MAN TODO
            agents.resize(na);
            // Init each agent
            for(auto& agent : agents) {
                // Step
                agent.step.stepObject.sFlow = sFlow;
                // Memory
                agent.step.Te = Te;
                // Actuators
                agent.step.behaviour.sStepSwim = std::make_shared<TypeStepSwim<TypeState>>();
                agent.step.stepObject.stepActuators.push_back(agent.step.behaviour.sStepSwim);
                agent.step.behaviour.sStepSwim->intensity = velocity;
                // Behaviour
                agent.step.behaviour.T = T;
            }
            for(auto& agent : agents) {
                // Init
                agent.init(); // TODO carefull, if the vector of agents is resized then, the memory changes and the solver x may not point to the right value
                // State
                agent.state.fill(0.0);
                // Time
                agent.solver.t = 0.0;
                agent.solver.dt = dt;
            }
        }
        
        void print() {
            std::string separation(" -------------------- ");
            std::string space(" = ");
            
            std::cout << separation << "Random Parameters" << std::endl;
            std::cout << "seed" << space << seed << std::endl;
            std::cout << separation << "Main Parameters" << std::endl;
            // Fluid
            // Numerical parameters
            std::cout << "nk" << space << *sFlow->sNk << std::endl;
            // Physical parameters
            std::cout << "eta" << space << sFlow->eta << std::endl;
            std::cout << "tauEta" << space << sFlow->tauEta << std::endl;
            std::cout << "uEta" << space << sFlow->uEta << std::endl;
            // Util
            std::cout << "l/eta" << space << sFlow->l / sFlow->eta << std::endl;
            // Time
            std::cout << separation << "Agents Parameters" << std::endl;
            // Agents
            std::cout << "number of agents" << space << na << std::endl;
            // // Particle properties
            std::cout << "particle size ratio" << space << sizeRatio << std::endl;
            std::cout << "agent velocity" << space << velocity << std::endl;
            std::cout << separation << "Saving Parameters" << std::endl;
            std::cout << "number of frame saved" << space << nsave << std::endl;
        }

        void saveTxt() {
            // Create this time directory
            std::ostringstream ss;
            ss << "time/" << agents[0].solver.t;
            std::filesystem::create_directory(ss.str());
            // Open file
            ss << "/agents.txt";
            std::ofstream file(ss.str());
            std::ostream_iterator<std::string> oiterator(file, " ");
            // Write
            for(auto& a : agents) {
                for(auto& v : a.state) {
                    file << v << " ";
                }
                file << "\n";
            }
            // Close file
            file.close();
        }

        void loadTxt(const double& t) {
            // Create this time directory
            std::ostringstream ss;
            ss << "time/" << t << "/agents.txt";
            std::ifstream file(ss.str());
            // Write
            for(auto& a : agents) {
                for(auto& v : a.state) {
                    file >> v;
                }
                a.solver.t = t;
            }
            // Close file
            file.close();
        }

        //void save() {
        //    // Create this time directory
        //    std::filesystem::create_directory("time/0.0");
        //    // Open file
        //    auto file = std::fstream("time/0.0/agents.bin", std::ios::out | std::ios::binary);
        //    // Write
        //    for(auto& a : agents) {
        //        file.write(reinterpret_cast<char*>(a.state.data()), a.state.size() * sizeof(a.state.data()));
        //    }
        //    // Close file
        //    file.close();

        //}
        
        // Declaration
        Environnement() {
            init();
            print();
        }
};
