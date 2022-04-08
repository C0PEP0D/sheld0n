#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <map>
#include <string>
// app includes
#include "core/init/objects/object/init/core.h"
#include "core/init/objects/object/prop.h"

namespace c0p {

class InitInitDynamicBase {
	public:
		InitInitDynamicBase() {
		}
	public:
		virtual void operator()(std::vector<double>& state) = 0;
};

class InitInitStaticBase : public InitInitDynamicBase {
	public:
		InitInitStaticBase() {
		}
	public:
		void operator()(std::vector<double>& state) override {
			operator()(state.data());
		}
	public:
		virtual void operator()(double* pState) = 0;
};

class InitInitManagerBase {
	public:
		InitInitManagerBase() {
		}
	public:
		virtual void operator()(std::vector<std::vector<double>>& states) = 0;
};

template<template<typename> typename TypeParameters, typename TypeObjectStep>
class InitInitStatic : public InitInitStaticBase {
	public:
		std::shared_ptr<TypeObjectStep> sObjectStep;
		TypeParameters<TypeObjectStep> parameters;
	public:
		InitInitStatic(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep), parameters(sObjectStep) {
		}
	public:
		void operator()(double* pState) override {
			for(const std::shared_ptr<InitInitInitStatic<TypeObjectStep>>& sInitObjectStep : parameters.sInits) {
				(*sInitObjectStep)(pState);
			}
		}
};

template<template<typename> typename TypeParameters, typename TypeObjectStep>
class InitInitDynamic : public InitInitDynamicBase {
	public:
		std::shared_ptr<TypeObjectStep> sObjectStep;
		TypeParameters<TypeObjectStep> parameters;
	public:
		InitInitDynamic(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep), parameters(sObjectStep) {
		}
	public:
		void operator()(std::vector<double>& state) override {
			// dynamic init
			(*parameters.sDynamicInit)(state);
			// static inits
			for(const std::shared_ptr<InitInitInitStatic<TypeObjectStep>>& sInitObjectStep : parameters.sInits) {
				(*sInitObjectStep)(state.data());
			}
		}
};

template<template<typename> typename TypeParameters, typename TypeObjectStep>
class InitInitManager : public InitInitManagerBase {
	public:
		std::shared_ptr<TypeObjectStep> sObjectStep;
		TypeParameters<TypeObjectStep> parameters;
	public:
		InitInitManager(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep), parameters(sObjectStep) {
		}
	public:
		void operator()(std::vector<std::vector<double>>& states) override {
			for(const std::shared_ptr<InitInitInitManager<TypeObjectStep>>& sInitObjectStep : parameters.sInits) {
				(*sInitObjectStep)(states);
			}
		}
};

}

#endif
