#ifndef C0P_CORE_LEARN_OPERATIONS_H
#define C0P_CORE_LEARN_OPERATIONS_H
#pragma once

#include <rl_tools/rl/environments/operations_generic.h>

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
		static_assert(ACTION_SPEC::ROWS == 1);
		static_assert(ACTION_SPEC::COLS == 1);

// 		using T = typename SPEC::T;
// 
// 		// send state to simulation
// 		c0p::tView<c0p::tStateVectorDynamic> agentState(c0p::Env::solutions.stateStatic<SPEC::PARAMETERS::tAgentEquation::tVariable>(), SPEC::PARAMETERS::tAgentEquation::tVariable::Size);
// 		agentState = state.state;
// 		// update simulation agent action
// 		SPEC::PARAMETERS::tAgentEquation::SwimmingDirection[0] = get(action, 0, 0);
// 		SPEC::PARAMETERS::tAgentEquation::SwimmingDirection[1] = get(action, 0, 1);
// 		// simulation step
// 		c0p::Env::solutions.step(SPEC::PARAMETERS::Dt);
// 		// set next step
// 		nextState.state = agentState;
		
		return SPEC::PARAMETERS::Dt;
	}

	template<typename DEVICE, typename SPEC, typename ACTION_SPEC, typename RNG>
	typename SPEC::T reward(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State& state, const Matrix<ACTION_SPEC>& action, const typename c0p::RLEnv<SPEC>::State& next_state, RNG& rng) {
		using T = typename SPEC::T;
		return 0.0;//state.state[1]; // TODO: or dot direction ? and normalize ?
	}

	template<typename DEVICE, typename SPEC, typename OBS_TYPE_SPEC, typename OBS_SPEC, typename RNG>
	void observe(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State& state, const c0p::RLEnvObservation<OBS_TYPE_SPEC>&, Matrix<OBS_SPEC>& observation, RNG& rng) {
		static_assert(OBS_SPEC::ROWS == 1);
		static_assert(OBS_SPEC::COLS == 1);
		
		using T = typename SPEC::T;
		
		// rl_tools::math::cos(device.math, state.theta)

		// TODO: put in the gradient
		
		// set(observation, 0, 1, 0.0);
		// set(observation, 0, 2, 0.0);
		// set(observation, 0, 3, 0.0);
		// set(observation, 0, 4, 0.0);
	}

	template<typename DEVICE, typename SPEC, typename RNG>
	bool terminated(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State state, RNG& rng) {
		using T = typename SPEC::T;
		return false;
	}

}

#endif
