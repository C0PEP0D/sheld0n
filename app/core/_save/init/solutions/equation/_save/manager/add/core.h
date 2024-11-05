#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_MANAGER_ADD_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_MANAGER_ADD_CORE_H
#pragma once

// std includes
#include <execution>
// app includes
#include "core/init/objects/object/init/manager/add/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitManaged>
class InitInitManagerAdd : public InitInitInitManager<TypeObjectStep> {
	public:
		TypeParameters parameters;
	public:
		using InitInitInitManager<TypeObjectStep>::sObjectStep;
	public:
		InitInitManagerAdd(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitManager<TypeObjectStep>(p_sObjectStep) {
		}
	public:
		void operator()(std::vector<std::vector<double>>& states) override {
			for(unsigned int managedIndex = 0; managedIndex < parameters.nb; managedIndex++) {
				// add
				sObjectStep->addManaged(states);
				// and init
				TypeInitInitManaged<typename TypeObjectStep::TypeManagedStep> initManaged(sObjectStep->sManagedSteps[managedIndex]);
				initManaged(states[managedIndex]);
			}
		};
};

}

#endif
