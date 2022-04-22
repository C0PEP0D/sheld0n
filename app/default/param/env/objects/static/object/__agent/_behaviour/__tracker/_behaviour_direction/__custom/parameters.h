#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CUSTOM_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CUSTOM_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/custom/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of a custom behaviour
template<typename AgentActiveStep>
struct ObjectAgentBehaviourTrackerBehaviourDirectionCustomParameters {
	const double vorticityThreshold0 = 1.0 / Parameters::cTime / 3.0;
	const double vorticityThreshold1 = 1.0 / Parameters::cTime;
	// Function that returns the preferred swimming direction
	TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& position, const TypeSpaceMatrix& velocityGradients) const {
		const double vorticityThreshold0 = 1.0 / Parameters::cTime / 3.0;
    	const double vorticityThreshold1 = 1.0 / Parameters::cTime;
    	// Function that returns the preferred swimming direction
    	TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& position, const TypeSpaceMatrix& velocityGradients) const {
    		// Implements the behaviour of Alageshan et al 2020.
    		// extract vorticity from gradients
    		const TypeSpaceMatrix skewVelocityGradients = 0.5 * (velocityGradients - velocityGradients.transpose());
    		const TypeSpaceVector vorticity = 2.0 * TypeSpaceVector({-skewVelocityGradients(1, 2), skewVelocityGradients(0, 2), -skewVelocityGradients(0, 1)});
    		// build cartesian system
    		const TypeSpaceVector targetDirection = (position - stepActive.cX(pState)).normalized();
    		const TypeSpaceVector targetDirectionCrossVorticity = targetDirection.cross(vorticity).normalized();
    		const TypeSpaceVector targetDirectionPerp = targetDirection.cross(targetDirectionCrossVorticity).normalized();
    		// extract orientation axis
    		const TypeSpaceVector orientationAxis = stepActive.cAxis(pState);
    		// if no error
    		//const double x = orientationAxis.dot(targetDirectionPerp);
    		//const double y = orientationAxis.dot(-targetDirectionCrossVorticity);
    		//const double z = orientationAxis.dot(targetDirection);
    		// if error
    		const double x = orientationAxis.dot(targetDirectionCrossVorticity);
    		const double y = orientationAxis.dot(targetDirectionPerp);
    		const double z = orientationAxis.dot(targetDirection);
    		// extract the three scalars that define the state
    		const double vorticityNorm = vorticity.norm();
    		const double theta = std::atan(z / std::sqrt(x*x + y*y + z*z));
    		const double phi = std::atan2(y, x);
    		// define actions
    		std::vector<TypeSpaceVector> actions({
    			targetDirection,
    			-targetDirection,
    			targetDirectionCrossVorticity,
    			-targetDirectionCrossVorticity,
    			targetDirectionPerp,
    			-targetDirectionPerp
    		});
    		// compute state
    		int state = 0;
    		if(vorticityNorm < vorticityThreshold0) {
    			state = 1;
    		} else if (vorticityNorm <= vorticityThreshold1) {
    			if(theta < M_PI / 6.0) {
    				state = 2;
    			} else if (theta <= 5.0 / 6.0 * M_PI) {
    				if(phi < M_PI / 2.0) {
    					state = 6;
    				} else if(phi < M_PI) {
    					state = 7;
    				} else if(phi < 3.0/2.0 * M_PI) {
    					state = 8;
    				} else {
    					state = 9;
    				}
    			} else {
    				state = 3;
    			}
    		} else {
    			if(theta < M_PI / 6.0) {
    				state = 4;
    			} else if (theta <= 5.0 / 6.0 * M_PI) {
    				if(phi < M_PI / 2.0) {
    					state = 10;
    				} else if(phi < M_PI) {
    					state = 11;
    				} else if(phi < 3.0/2.0 * M_PI) {
    					state = 12;
    				} else {
    					state = 13;
    				}
    			} else {
    				state = 5;
    			}
    		}
    		// return action corresponding to state
    		switch (state) {
    	        case 1: return actions[0];
    	        case 2: return actions[0];
    	        case 3: return actions[0];
    	        case 4: return actions[5];
    	        case 5: return actions[0];
    	        case 6: return actions[0];
    	        case 7: return actions[5];
    	        case 8: return actions[4];
    	        case 9: return actions[0];
    	        case 10: return actions[2];
    	        case 11: return actions[0];
    	        case 12: return actions[2];
    	        case 13: return actions[0];
    	    }
    	}
	}
};

}

#endif
