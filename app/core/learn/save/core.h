#ifndef C0P_CORE_LEARN_CORE_H
#define C0P_CORE_LEARN_CORE_H
#pragma once

// std includes
// lib includes
# include "core/learn/prop.h"

namespace c0p {

	template <typename tScalar, typename tIndex, typename tParameters>
	struct RLEnvSpec{
		using T = tScalar;
		using TI = tIndex;
		using PARAMETERS = tParameters;
	};

	template <typename tSpec>
	struct RLEnvState{
		static constexpr tSpec::TI DIM = tSpec::PARAMETERS::tAgentEquation::tVariable::Size;
		tVector<DIM> state;
	};

	template <typename tSpec>
	struct RLEnvObservation{
		static constexpr tSpec::TI DIM = tSpec::PARAMETERS::ObservationDim;
	};

	template <typename tSpec>
	struct RLEnv: rl_tools::rl::environments::Environment<typename tSpec::T, typename tSpec::TI>{
		using SPEC = tSpec;
		using T = typename SPEC::T;
		using TI = typename SPEC::TI;
		using Parameters = typename SPEC::PARAMETERS;
		using State = RLEnvState<SPEC>;
		using Observation = RLEnvObservation<SPEC>;
		using ObservationPrivileged = Observation;
		static constexpr TI OBSERVATION_DIM = SPEC::PARAMETERS::ObservationDim;
		static constexpr TI ACTION_DIM = SPEC::PARAMETERS::ActionDim;
		static constexpr TI EPISODE_STEP_LIMIT = 200;
	};

}

namespace rl_tools {

	template<typename DEVICE, typename SPEC>
	void malloc(DEVICE& device, c0p::RLEnv<SPEC>& env) {
		
	}

	template<typename DEVICE, typename SPEC>
	void free(DEVICE& device, c0p::RLEnv<SPEC>& env) {
		
	}

	template<typename DEVICE, typename SPEC>
	void init(DEVICE& device, c0p::RLEnv<SPEC>& env) {
		
	}

	template<typename DEVICE, typename SPEC>
	void initial_parameters(DEVICE& device, const c0p::RLEnv<SPEC>& env, typename c0p::RLEnv<SPEC>::Parameters& parameters) {

	}

	template<typename DEVICE, typename SPEC, typename RNG>
	void sample_initial_parameters(DEVICE& device, const c0p::RLEnv<SPEC>& env, typename c0p::RLEnv<SPEC>::Parameters& parameters, RNG& rng) {
		
	}

	template<typename DEVICE, typename SPEC>
	void initial_state(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, typename c0p::RLEnv<SPEC>::State& state) {

	}

	template<typename DEVICE, typename SPEC, typename RNG>
	void sample_initial_state(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, typename c0p::RLEnv<SPEC>::State& state, RNG& rng){
		// state.theta     = random::uniform_real_distribution(typename DEVICE::SPEC::RANDOM(), SPEC::PARAMETERS::INITIAL_STATE_MIN_ANGLE, SPEC::PARAMETERS::INITIAL_STATE_MAX_ANGLE, rng);
		// state.theta_dot = random::uniform_real_distribution(typename DEVICE::SPEC::RANDOM(), SPEC::PARAMETERS::INITIAL_STATE_MIN_SPEED, SPEC::PARAMETERS::INITIAL_STATE_MAX_SPEED, rng);
	}

	template<typename DEVICE, typename SPEC, typename ACTION_SPEC, typename RNG>
	typename SPEC::T step(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State& state, const Matrix<ACTION_SPEC>& action, typename c0p::RLEnv<SPEC>::State& nextState, RNG& rng) {

		// static_assert(ACTION_SPEC::ROWS == 1);
		// static_assert(ACTION_SPEC::COLS == 2);

		using T = typename SPEC::T;

		// send state to simulation
		c0p::tView<c0p::tStateVectorDynamic> simState(c0p::Env::solutions.stateStatic<SPEC::PARAMETERS::tAgentEquation::tVariable>(), SPEC::PARAMETERS::tAgentEquation::tVariable::Size);
		simState = state.state;
		// update simulation agent action
		SPEC::PARAMETERS::tAgentEquation::SwimmingDirection[0] = get(action, 0, 0);
		SPEC::PARAMETERS::tAgentEquation::SwimmingDirection[1] = get(action, 0, 1);
		// simulation step
		c0p::Env::solutions.step(SPEC::PARAMETERS::Dt);
		// set next step
		nextState.state = simState;
		
		return SPEC::PARAMETERS::Dt;
	}

	template<typename DEVICE, typename SPEC, typename ACTION_SPEC, typename RNG>
	typename SPEC::T reward(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State& state, const Matrix<ACTION_SPEC>& action, const typename c0p::RLEnv<SPEC>::State& next_state, RNG& rng) {
		using T = typename SPEC::T;
		return state.state[1]; // TODO: or dot direction ? and normalize ?
	}

	template<typename DEVICE, typename SPEC, typename OBS_TYPE_SPEC, typename OBS_SPEC, typename RNG>
	void observe(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State& state, const c0p::RLEnvObservation<OBS_TYPE_SPEC>&, Matrix<OBS_SPEC>& observation, RNG& rng) {
		// static_assert(OBS_SPEC::ROWS == 1);
		// static_assert(OBS_SPEC::COLS == 4);
		
		using T = typename SPEC::T;
		
		// rl_tools::math::cos(device.math, state.theta)

		// TODO: put in the gradient
		
		set(observation, 0, 1, 0.0);
		set(observation, 0, 2, 0.0);
		set(observation, 0, 3, 0.0);
		set(observation, 0, 4, 0.0);
	}

	template<typename DEVICE, typename SPEC, typename RNG>
	bool terminated(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State state, RNG& rng) {
		using T = typename SPEC::T;
		return false;
	}

}

namespace c0p {

	template<typename tParameters>
	struct Learn {
		static void run() {
			// declare
			typename tParameters::RLParameters::tDevice device;
			typename tParameters::RLParameters::tIndex seed = 0;
			typename tParameters::RLParameters::tLoopState ls;
			// // test
			// typename tParameters::RLParameters::tEnv test;
			// rlt::malloc(device, test);
			// init
			rlt::malloc(device, ls);
			// rlt::init(device, ls, seed);
			// // run
			// while(!rlt::step(device, ls)) {
			// }
		}
	};

}

#endif
