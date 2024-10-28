#ifndef C0P_CORE_INIT_SOLUTIONS_PROP_H
#define C0P_CORE_INIT_SOLUTIONS_PROP_H
#pragma once

// app include
// // objects
#include "param/env/solutions/parameters.h"
#include "core/env/solutions/core.h"
// // init
#include "core/init/prop.h"

namespace c0p {

template<unsigned int Index, typename tInit, typename... tInits>
struct StaticInitComponent : StaticInitComponent<Index - 1, tInits...> { 
};

template<typename tInit, typename... tInits>
struct StaticInitComponent<0, tInit, tInits...> {
   using type = tInit;
};

template<typename... tInits>
class StaticInitComposed {
	public:
		static const unsigned int Number = sizeof...(tInits);
	public:
		template<unsigned int Index> using tStaticInitComponent = StaticInitComponent<Index, tInits...>;
    public:
    	template<unsigned int Index = 0>
    	static void set(Solutions<SolutionsParameters>::tSolutionStatic& solutionsStatic) {
    		using tStaticEquation = typename Solutions<SolutionsParameters>::tSolutionStatic::tEquation;
    		using tStaticVariable = typename Solutions<SolutionsParameters>::tSolutionStatic::tEquation::tVariable;
    		if constexpr(Index < tStaticEquation::Number) {
        		tStaticInitComponent<Index>::type::set(tStaticVariable::template state<Index>(solutionsStatic.state.data()));
        		// recursion
        		set<Index+1>(solutionsStatic);
        	}
        }
};

}

#endif
