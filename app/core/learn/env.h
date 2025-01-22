#ifndef C0P_CORE_LEARN_ENV_H
#define C0P_CORE_LEARN_ENV_H
#pragma once

// std includes
// lib includes
// rl includes
#include <rl_tools/rl/environments/environments.h>

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
		typename tSpec::T x;
		typename tSpec::T y;
		// tVector<DIM> state;
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

#endif
