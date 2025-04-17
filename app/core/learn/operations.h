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
		// TODO : SETUP RANDOM TARGET DIRECTION ?
	}

	template<typename DEVICE, typename SPEC>
	void initial_state(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, typename c0p::RLEnv<SPEC>::State& state) {
		state.solutions.init();
	}

	template<typename DEVICE, typename SPEC, typename RNG>
	void sample_initial_state(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, typename c0p::RLEnv<SPEC>::State& state, RNG& rng){
		state.solutions.init();
	}

	template<typename DEVICE, typename SPEC, typename ACTION_SPEC, typename RNG>
	typename SPEC::T step(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State& state, const Matrix<ACTION_SPEC>& action, typename c0p::RLEnv<SPEC>::State& nextState, RNG& rng) {
		// next environment
		nextState.solutions = state.solutions;
		// next agent
		using tAgentEquation = typename SPEC::PARAMETERS::tAgentEquation;
		c0p::tView<c0p::tStateVectorDynamic> nextAgentState(nextState.solutions.template stateStatic<typename tAgentEquation::tVariable>(), tAgentEquation::tVariable::Size);

		// act
		tAgentEquation::tParameters::act(action, nextAgentState.data());

		// simulation step
		nextState.solutions.step(SPEC::PARAMETERS::Dt / 128.0);
		nextState.t += SPEC::PARAMETERS::Dt;

		// return
		return SPEC::PARAMETERS::Dt;
	}

	template<typename DEVICE, typename SPEC, typename ACTION_SPEC, typename RNG>
	typename SPEC::T reward(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State& state, const Matrix<ACTION_SPEC>& action, const typename c0p::RLEnv<SPEC>::State& nextState, RNG& rng) {
		using tAgentEquation = typename SPEC::PARAMETERS::tAgentEquation;
		// get agent state
		const c0p::tView<const c0p::tStateVectorDynamic> agentState(state.solutions.template cStateStatic<typename tAgentEquation::tVariable>(), tAgentEquation::tVariable::Size);
		// get next agent state
		const c0p::tView<const c0p::tStateVectorDynamic> nextAgentState(nextState.solutions.template cStateStatic<typename tAgentEquation::tVariable>(), tAgentEquation::tVariable::Size);
		// observe
		return tAgentEquation::tParameters::reward(agentState.data(), nextAgentState.data());
	}

	template<typename DEVICE, typename SPEC, typename OBS_TYPE_SPEC, typename OBS_SPEC, typename RNG>
	void observe(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State& state, const c0p::RLEnvObservation<OBS_TYPE_SPEC>& rlEnvObservation, Matrix<OBS_SPEC>& observation, RNG& rng) {
		// get agent state
		using tAgentEquation = typename SPEC::PARAMETERS::tAgentEquation;
		const c0p::tView<const c0p::tStateVectorDynamic> agentState(state.solutions.template cStateStatic<typename tAgentEquation::tVariable>(), tAgentEquation::tVariable::Size);
		// observe
		tAgentEquation::tParameters::observe(agentState.data(), state.t, observation);
	}

	template<typename DEVICE, typename SPEC, typename RNG>
	bool terminated(DEVICE& device, const c0p::RLEnv<SPEC>& env, const typename c0p::RLEnv<SPEC>::Parameters& parameters, const typename c0p::RLEnv<SPEC>::State state, RNG& rng) {
		return false;
	}

}

#endif
