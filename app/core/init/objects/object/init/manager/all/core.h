#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_MANAGER_ALL_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_MANAGER_ALL_CORE_H
#pragma once

// std includes
#include <execution>
// app includes
#include "core/init/objects/object/init/manager/all/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitManaged>
class InitInitManagerAll : public InitInitInitManager<TypeObjectStep> {
	public:
		TypeParameters parameters;
	public:
		using InitInitInitManager<TypeObjectStep>::sObjectStep;
	public:
		InitInitManagerAll(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitManager<TypeObjectStep>(p_sObjectStep) {
		}
	public:
		void operator()(std::vector<std::vector<double>>& states) override {
			std::for_each(std::execution::par_unseq, sObjectStep->managedIndexs.cbegin(), sObjectStep->managedIndexs.cend(), [this, &states](const unsigned int& managedIndex){
				TypeInitInitManaged<typename TypeObjectStep::TypeManagedStep> initManaged(sObjectStep->sManagedSteps[managedIndex]);
				initManaged(states[managedIndex]);
			});
		};
};

}

#endif
