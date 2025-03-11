#ifndef C0P_PARAM_LEARN_PARAMETERS_H
#define C0P_PARAM_LEARN_PARAMETERS_H
#pragma once

#include <rl_tools/operations/cpu_mux.h>
#include <rl_tools/nn/operations_cpu_mux.h>
#include <rl_tools/nn_models/operations_cpu.h>
#include "core/learn/env.h"
#include "core/learn/operations.h"
#include <rl_tools/rl/algorithms/ppo/loop/core/config.h>
#include <rl_tools/rl/algorithms/ppo/loop/core/operations_generic.h>
// output setup
#include <rl_tools/rl/loop/steps/evaluation/operations_generic.h>

namespace rlt = rl_tools;

namespace c0p {

// Run simulation parameters
struct LearnParameters {

	// Environnement
	
	struct RLEnvParameters {
		// Run Parameters
		// // Fixed time step of the simulation.
		// // Should be greater than zero.
		static constexpr double Dt = 1.0/128.0;
		static constexpr unsigned int EpisodeStepLimit = std::round(8*M_PI/Dt); // number of step befor simulation ends (equivalent to Nt)
		
		// Init Parameters
		static constexpr double INITIAL_STATE_MIN_X = -M_PI;
		static constexpr double INITIAL_STATE_MAX_X = M_PI;
		static constexpr double INITIAL_STATE_MIN_Y = -M_PI;
		static constexpr double INITIAL_STATE_MAX_Y = M_PI;
		// // Set initial state
		template<typename DEVICE, typename SPEC, typename RNG>
		static void sample_initial_state(DEVICE& device, const RLEnv<SPEC>& env, const typename RLEnv<SPEC>::Parameters& parameters, typename RLEnv<SPEC>::State& state, RNG& rng){
			state.state[0] = rlt::random::uniform_real_distribution(typename DEVICE::SPEC::RANDOM(), INITIAL_STATE_MIN_X, INITIAL_STATE_MAX_X, rng);
			state.state[1] = rlt::random::uniform_real_distribution(typename DEVICE::SPEC::RANDOM(), INITIAL_STATE_MIN_Y, INITIAL_STATE_MAX_Y, rng);
		}
		
		// Agent Parameters
		using tAgentEquation = _RlAgent;
		static constexpr unsigned int ObservationDim = DIM + DIM * DIM; // target direction + flow velocity gradients
		static constexpr unsigned int ActionDim = DIM; // swimming direction
		// // TODO: SwimmingVelocity and TargetDirection for random setup ?
		
		// Observation
		template<typename DEVICE, typename SPEC, typename OBS_TYPE_SPEC, typename OBS_SPEC, typename RNG>
		static void observe(DEVICE& device, const RLEnv<SPEC>& env, const typename RLEnv<SPEC>::Parameters& parameters, const typename RLEnv<SPEC>::State& state, const RLEnvObservation<OBS_TYPE_SPEC>&, rlt::Matrix<OBS_SPEC>& observation, RNG& rng) {
			const c0p::tView<const c0p::tSpaceVector> x(state.state.data());
			const c0p::tSpaceMatrix grad = c0p::Flow::getVelocityGradients(x.data(), 0.0); // TODO: replace 0.0 by t
	
			set(observation, 0, 0, SPEC::PARAMETERS::tAgentEquation::tParameters::TargetDirection[0]);
			set(observation, 0, 1, SPEC::PARAMETERS::tAgentEquation::tParameters::TargetDirection[1]); // Direction
			
			set(observation, 0, 2, grad(0, 0));
			set(observation, 0, 3, grad(0, 1));
			set(observation, 0, 4, grad(1, 0));
			set(observation, 0, 5, grad(1, 1));
		}
		
		// Step (Action)
		template<typename DEVICE, typename SPEC, typename ACTION_SPEC, typename RNG>
		static typename SPEC::T step(DEVICE& device, const RLEnv<SPEC>& env, const typename RLEnv<SPEC>::Parameters& parameters, const typename RLEnv<SPEC>::State& state, const rlt::Matrix<ACTION_SPEC>& action, typename RLEnv<SPEC>::State& nextState, RNG& rng) {
			// send state to simulation
			c0p::tView<c0p::tStateVectorDynamic> agentState(c0p::Env::solutions.stateStatic<typename SPEC::PARAMETERS::tAgentEquation::tVariable>(), SPEC::PARAMETERS::tAgentEquation::tVariable::Size);
			agentState = state.state;
			// update simulation agent action
			// NOTE : normalization of the swimming direction is directly performed in the solver.
			SPEC::PARAMETERS::tAgentEquation::tParameters::SwimmingDirection[0] = get(action, 0, 0);
			SPEC::PARAMETERS::tAgentEquation::tParameters::SwimmingDirection[1] = get(action, 0, 1);
			// simulation step
			c0p::Env::solutions.step(SPEC::PARAMETERS::Dt);
			// set next step
			nextState.state = agentState;
			return SPEC::PARAMETERS::Dt;
		}
		
		// Reward
		template<typename DEVICE, typename SPEC, typename ACTION_SPEC, typename RNG>
		static typename SPEC::T reward(DEVICE& device, const RLEnv<SPEC>& env, const typename RLEnv<SPEC>::Parameters& parameters, const typename RLEnv<SPEC>::State& state, const rlt::Matrix<ACTION_SPEC>& action, const typename RLEnv<SPEC>::State& next_state, RNG& rng) {
			// get target direction
			const c0p::tView<const c0p::tSpaceVector> z(SPEC::PARAMETERS::tAgentEquation::tParameters::TargetDirection.data());
			// return scalar product
			return (next_state.state - state.state).dot(z);
		}
	};

	using tDevice = rlt::devices::DEVICE_FACTORY<>;
	using tRng = decltype(rlt::random::default_engine(typename tDevice::SPEC::RANDOM{}));
	using tScalar = double;
	using tIndex = typename tDevice::index_t;
	using tEnv = RLEnv<RLEnvSpec<tScalar, tIndex, RLEnvParameters>>;

	struct LoopCoreParameters: rlt::rl::algorithms::ppo::loop::core::DefaultParameters<tScalar, tIndex, tEnv>{

		static constexpr tIndex N_ENVIRONMENTS = 8;
		static constexpr tIndex ON_POLICY_RUNNER_STEPS_PER_ENV = 128;
		static constexpr tIndex BATCH_SIZE = 128;
		static constexpr tIndex TOTAL_STEP_LIMIT = std::pow(2, 22);

		static constexpr tIndex ACTOR_HIDDEN_DIM = 32;
		static constexpr tIndex CRITIC_HIDDEN_DIM = 32;

		static constexpr auto ACTOR_ACTIVATION_FUNCTION = rlt::nn::activation_functions::ActivationFunction::FAST_TANH;
		static constexpr auto CRITIC_ACTIVATION_FUNCTION = rlt::nn::activation_functions::ActivationFunction::FAST_TANH;

		static constexpr tIndex STEP_LIMIT = TOTAL_STEP_LIMIT/(ON_POLICY_RUNNER_STEPS_PER_ENV * N_ENVIRONMENTS) + 1;
		static constexpr tIndex EPISODE_STEP_LIMIT = tEnv::EPISODE_STEP_LIMIT;

		struct OPTIMIZER_PARAMETERS: rlt::nn::optimizers::adam::DEFAULT_PARAMETERS_TENSORFLOW<tScalar> {
			static constexpr tScalar ALPHA = 0.001;
		};
		
		static constexpr bool NORMALIZE_OBSERVATIONS = true;
		struct PPO_PARAMETERS: rlt::rl::algorithms::ppo::DefaultParameters<tScalar, tIndex, BATCH_SIZE> {
			static constexpr tScalar ACTION_ENTROPY_COEFFICIENT = 0.0;
			static constexpr tIndex N_EPOCHS = 1;
			static constexpr tScalar GAMMA = 0.9;
			static constexpr tScalar INITIAL_ACTION_STD = 2.0;
		};
	};
	using tLoopCoreConfig = rlt::rl::algorithms::ppo::loop::core::Config<tScalar, tIndex, tRng, tEnv, LoopCoreParameters>;
	// output setup
	template <typename tNext>
	struct tLoopEvalParameters: rlt::rl::loop::steps::evaluation::Parameters<tScalar, tIndex, tNext>{
	    static constexpr tIndex EVALUATION_INTERVAL = tLoopCoreConfig::CORE_PARAMETERS::STEP_LIMIT / 10;
	    static constexpr tIndex NUM_EVALUATION_EPISODES = 10;
	    static constexpr tIndex N_EVALUATIONS = tNext::CORE_PARAMETERS::STEP_LIMIT / EVALUATION_INTERVAL;
	};
	using tLoopEvaluationConfig = rlt::rl::loop::steps::evaluation::Config<tLoopCoreConfig, tLoopEvalParameters<tLoopCoreConfig>>; // Evaluates the policy in a fixed interval and logs the return
	using tLoopTimingConfig = rlt::rl::loop::steps::timing::Config<tLoopEvaluationConfig>;
	// core
	using tLoopConfig = tLoopTimingConfig;
	using tLoopState = typename tLoopConfig::template State<tLoopConfig>;
};

}

#endif
