#ifndef C0P_CORE_ENV_FLOW_FROZEN_CORE_H
#define C0P_CORE_ENV_FLOW_FROZEN_CORE_H
#pragma once

// Std includes
#include <vector>
#include <string>
#include <iostream> // cout, endl
#include <memory> // shared_ptr
// Lib includes
#include "fl0w/flow.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/frozen/prop.h"

namespace c0p {

template<typename TypeFlow>
using TypeFlowFrozen = fl0w::FlowFrozen<TypeFlow>;

template<typename TypeParameters, typename TypeFlow>
class BaseFlowFrozen : public TypeFlowFrozen<TypeFlow> {
	public:
		using Type = TypeFlowFrozen<TypeFlow>;
	public:
		TypeParameters parameters;
	public:
		BaseFlowFrozen() : Type(parameters.time) {
			Type::time = parameters.time;
		}

		void init(const TypeScalar& t) {
	   		Type::init(Type::time);
		}
		
		void update(const TypeScalar& t) {
		}

		void prepare(const TypeContainer<TypeSpaceVector>& positions, const TypeScalar& t) {
			Type::prepare(positions, Type::time);
		}

		void info() const {
			std::string separation(" -------------------- ");
			std::string space(" = ");
			std::cout << separation << "Flow Frozen" << std::endl;
		}

};

}

#endif
