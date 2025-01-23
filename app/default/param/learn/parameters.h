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
#include <rl_tools/rl/loop/steps/extrack/operations_cpu.h>
#include <rl_tools/rl/loop/steps/evaluation/operations_generic.h>

namespace rlt = rl_tools;

namespace c0p {

// Run simulation parameters
struct LearnParameters {
	
	struct RLEnvParameters {
		// Run Parameters
		// // Fixed time step of the simulation.
		// // Should be greater than zero.
		static constexpr double Dt = 1.0/128.0;
		// Agent Parameters
		using tAgentEquation = _RlAgent;
		static constexpr unsigned int ObservationDim = DIM * DIM; // grad
		static constexpr unsigned int ActionDim = DIM; // direction
		// // TODO: SwimmingVelocity and TargetDirection for random setup ?
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
		static constexpr tIndex TOTAL_STEP_LIMIT = 1000000;
		static constexpr tIndex ACTOR_HIDDEN_DIM = 32;
		static constexpr tIndex CRITIC_HIDDEN_DIM = 32;
		static constexpr auto ACTOR_ACTIVATION_FUNCTION = rlt::nn::activation_functions::ActivationFunction::FAST_TANH;
		static constexpr auto CRITIC_ACTIVATION_FUNCTION = rlt::nn::activation_functions::ActivationFunction::FAST_TANH;
		static constexpr tIndex STEP_LIMIT = TOTAL_STEP_LIMIT/(ON_POLICY_RUNNER_STEPS_PER_ENV * N_ENVIRONMENTS) + 1;
		static constexpr tIndex EPISODE_STEP_LIMIT = tEnv::EPISODE_STEP_LIMIT;
		struct OPTIMIZER_PARAMETERS: rlt::nn::optimizers::adam::DEFAULT_PARAMETERS_TENSORFLOW<tScalar>{
			static constexpr tScalar ALPHA = 0.001;
		};
		static constexpr bool NORMALIZE_OBSERVATIONS = true;
		struct PPO_PARAMETERS: rlt::rl::algorithms::ppo::DefaultParameters<tScalar, tIndex, BATCH_SIZE>{
			static constexpr tScalar ACTION_ENTROPY_COEFFICIENT = 0.0;
			static constexpr tIndex N_EPOCHS = 1;
			static constexpr tScalar GAMMA = 0.9;
			static constexpr tScalar INITIAL_ACTION_STD = 2.0;
		};
	};
	using tLoopCoreConfig = rlt::rl::algorithms::ppo::loop::core::Config<tScalar, tIndex, tRng, tEnv, LoopCoreParameters>;
	// output setup
	using tLoopExtrackConfig = rlt::rl::loop::steps::extrack::Config<tLoopCoreConfig>; // Sets up the experiment tracking structure (https://docs.rl.tools/10-Experiment%20Tracking.html)
	template <typename tNext>
	struct tLoopEvalParameters: rlt::rl::loop::steps::evaluation::Parameters<tScalar, tIndex, tNext>{
	    static constexpr tIndex EVALUATION_INTERVAL = tLoopCoreConfig::CORE_PARAMETERS::STEP_LIMIT / 10;
	    static constexpr tIndex NUM_EVALUATION_EPISODES = 10;
	    static constexpr tIndex N_EVALUATIONS = tNext::CORE_PARAMETERS::STEP_LIMIT / EVALUATION_INTERVAL;
	};
	using tLoopEvaluationConfig = rlt::rl::loop::steps::evaluation::Config<tLoopExtrackConfig, tLoopEvalParameters<tLoopExtrackConfig>>; // Evaluates the policy in a fixed interval and logs the return
	using tLoopTimingConfig = rlt::rl::loop::steps::timing::Config<tLoopEvaluationConfig>;
	// core
	using tLoopConfig = tLoopTimingConfig;
	using tLoopState = typename tLoopConfig::template State<tLoopConfig>;
};

}

#endif
