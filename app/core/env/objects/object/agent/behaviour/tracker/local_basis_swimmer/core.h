#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_LOCAL_BASIS_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_LOCAL_BASIS_SWIMMER_CORE_H
#pragma once

// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/agent/behaviour/tracker/local_axis_swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeSensorPosition, typename TypeSensorVelocityGradients, typename TypeBehaviourDirection, typename TypeBehaviourVelocity>
class AgentBehaviourTrackerLocalBasisSwimmer : public sl0::sa0::Behaviour<AgentActiveStep> {
	public:
		using Type = sl0::sa0::Behaviour<AgentActiveStep>;
		using TypeStateVectorDynamic = typename AgentActiveStep::TypeStateVectorDynamic;
	public:
		TypeParameters parameters;
		// sensors
		TypeSensorPosition sensorPosition;
		TypeSensorVelocityGradients sensorVelocityGradients;
		// sub behaviours
		TypeBehaviourDirection behaviourDirection;
		TypeBehaviourVelocity behaviourVelocity;
	public:
		AgentBehaviourTrackerLocalBasisSwimmer(std::shared_ptr<Objects> sObjects) : sensorPosition(sObjects) {
		}
	public:
		TypeContainer<TypeSpaceVector> positions(const double* pState, const AgentActiveStep& stepActive) const override {
			TypeContainer<TypeSpaceVector> result;
			// sensors
			const TypeContainer<TypeSpaceVector> positionsSensorPosition = sensorPosition.positions(pState, stepActive);
			result.insert(result.end(), positionsSensorPosition.begin(), positionsSensorPosition.end());
			const TypeContainer<TypeSpaceVector> positionsSensorVelocityGradients = sensorVelocityGradients.positions(pState, stepActive);
			result.insert(result.end(), positionsSensorVelocityGradients.begin(), positionsSensorVelocityGradients.end());
			// sub behaviours
			const TypeContainer<TypeSpaceVector> positionsBehaviourDirection = behaviourDirection.positions(pState, stepActive);
			result.insert(result.end(), positionsBehaviourDirection.begin(), positionsBehaviourDirection.end());
			const TypeContainer<TypeSpaceVector> positionsBehaviourVelocity = behaviourVelocity.positions(pState, stepActive);
			result.insert(result.end(), positionsBehaviourVelocity.begin(), positionsBehaviourVelocity.end());
			// return
			return result;
		}
	public:
		void operator()(const double* pState, const double& t, const AgentActiveStep& stepActive) const override {
			const TypeSpaceVector position = sensorPosition(pState, t, stepActive);
			const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(pState, t, stepActive);
			auto sAxis0 = stepActive.cAxis(pState, 0);
			auto sAxis1 = stepActive.cAxis(pState, 1);
			auto sAxis2 = stepActive.cAxis2(pState);
			const TypeSpaceVector swimmingDirection = stepActive.cBasis(pState) * stepActive.parameters.swimAxis;
			stepActive.sStepBasisOrient->globalDirection = behaviourDirection(pState, t, stepActive, position, velocityGradients).normalized();
			stepActive.sStepLocalBasisSwim->velocity = behaviourVelocity(pState, t, stepActive, position, velocityGradients, swimmingDirection) * stepActive.parameters.velocity;
		}
};


}

#endif
