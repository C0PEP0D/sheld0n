#ifndef C0P_PARAM_INIT_OBJECTS_PARAPETERS_H
#define C0P_PARAM_INIT_OBJECTS_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std include
#include <vector>
// app include
#include "core/init/objects/object/core.h"
#include "core/init/objects/prop.h"
// FLAG: INCLUDE OBJECT BEGIN
#include "param/init/objects/tracers__e3_1o0/parameters.h"
#include "param/init/objects/tracers__e3_0o01/parameters.h"
#include "param/init/objects/tracers__e3_0o1/parameters.h"
#include "param/init/objects/tracers__e3_10o0/parameters.h"
#include "param/init/objects/tracers__e1_0o01/parameters.h"
#include "param/init/objects/tracers__e1_0o1/parameters.h"
#include "param/init/objects/tracers__e1_1o0/parameters.h"
#include "param/init/objects/tracers__e1_10o0/parameters.h"
#include "param/init/objects/tracers__e2_0o01/parameters.h"
#include "param/init/objects/tracers__e2_0o1/parameters.h"
#include "param/init/objects/tracers__e2_1o0/parameters.h"
#include "param/init/objects/tracers__e2_10o0/parameters.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct InitObjectsParameters {
	// make data
	std::vector<std::shared_ptr<InitInitStaticBase>> sInitsStatic;
	std::vector<std::shared_ptr<InitInitDynamicBase>> sInitsDynamic;
	std::vector<std::shared_ptr<InitInitManagerBase>> sInitsManager;
	InitObjectsParameters(std::shared_ptr<TypeObjectsParameters> sObjectsParameters) {
		// FLAG: MAKE OBJECT BEGIN
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE31O0Parameters, TracersE31O0Step>>(sObjectsParameters->sTracersE31O0Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE30O01Parameters, TracersE30O01Step>>(sObjectsParameters->sTracersE30O01Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE30O1Parameters, TracersE30O1Step>>(sObjectsParameters->sTracersE30O1Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE310O0Parameters, TracersE310O0Step>>(sObjectsParameters->sTracersE310O0Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE10O01Parameters, TracersE10O01Step>>(sObjectsParameters->sTracersE10O01Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE10O1Parameters, TracersE10O1Step>>(sObjectsParameters->sTracersE10O1Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE11O0Parameters, TracersE11O0Step>>(sObjectsParameters->sTracersE11O0Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE110O0Parameters, TracersE110O0Step>>(sObjectsParameters->sTracersE110O0Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE20O01Parameters, TracersE20O01Step>>(sObjectsParameters->sTracersE20O01Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE20O1Parameters, TracersE20O1Step>>(sObjectsParameters->sTracersE20O1Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE21O0Parameters, TracersE21O0Step>>(sObjectsParameters->sTracersE21O0Step));
		sInitsStatic.push_back(std::make_shared<InitInitStatic<InitTracersE210O0Parameters, TracersE210O0Step>>(sObjectsParameters->sTracersE210O0Step));
		// FLAG: MAKE OBJECT END
	}
};

}

#endif
