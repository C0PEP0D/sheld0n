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
#include "param/init/objects/surfer__us_1o0__surftimeconst_1o0/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_1o0/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_1o0/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_1o0/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o0/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o025/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o05/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o1/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o2/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o4/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o6/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o8/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o0/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o025/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o05/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o1/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o2/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o4/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o6/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o8/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o0/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o025/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o05/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o1/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o2/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o4/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o6/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o8/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o0/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o025/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o05/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o1/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o2/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o4/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o6/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o8/parameters.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct InitObjectsParameters {
    // make data
    std::vector<std::shared_ptr<InitInitStaticBase>> sInitsStatic;
    std::vector<std::shared_ptr<InitInitDynamicBase>> sInitsDynamic;
    InitObjectsParameters(std::shared_ptr<TypeObjectsParameters> sObjectsParameters) {
        // FLAG: MAKE OBJECT BEGIN
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeconst1O0Parameters, SurferUs1O0Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst1O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeconst1O0Parameters, SurferUs0O1Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst1O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeconst1O0Parameters, SurferUs0O5Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst1O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeconst1O0Parameters, SurferUs2O0Surftimeconst1O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst1O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeconst0O0Parameters, SurferUs0O1Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeconst0O025Parameters, SurferUs0O1Surftimeconst0O025Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O025Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeconst0O05Parameters, SurferUs0O1Surftimeconst0O05Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O05Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeconst0O1Parameters, SurferUs0O1Surftimeconst0O1Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O1Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeconst0O2Parameters, SurferUs0O1Surftimeconst0O2Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O2Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeconst0O4Parameters, SurferUs0O1Surftimeconst0O4Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O4Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeconst0O6Parameters, SurferUs0O1Surftimeconst0O6Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O6Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeconst0O8Parameters, SurferUs0O1Surftimeconst0O8Step>>(sObjectsParameters->sSurferUs0O1Surftimeconst0O8Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeconst0O0Parameters, SurferUs0O5Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeconst0O025Parameters, SurferUs0O5Surftimeconst0O025Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O025Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeconst0O05Parameters, SurferUs0O5Surftimeconst0O05Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O05Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeconst0O1Parameters, SurferUs0O5Surftimeconst0O1Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O1Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeconst0O2Parameters, SurferUs0O5Surftimeconst0O2Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O2Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeconst0O4Parameters, SurferUs0O5Surftimeconst0O4Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O4Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeconst0O6Parameters, SurferUs0O5Surftimeconst0O6Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O6Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeconst0O8Parameters, SurferUs0O5Surftimeconst0O8Step>>(sObjectsParameters->sSurferUs0O5Surftimeconst0O8Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeconst0O0Parameters, SurferUs1O0Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeconst0O025Parameters, SurferUs1O0Surftimeconst0O025Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O025Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeconst0O05Parameters, SurferUs1O0Surftimeconst0O05Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O05Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeconst0O1Parameters, SurferUs1O0Surftimeconst0O1Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O1Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeconst0O2Parameters, SurferUs1O0Surftimeconst0O2Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O2Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeconst0O4Parameters, SurferUs1O0Surftimeconst0O4Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O4Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeconst0O6Parameters, SurferUs1O0Surftimeconst0O6Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O6Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeconst0O8Parameters, SurferUs1O0Surftimeconst0O8Step>>(sObjectsParameters->sSurferUs1O0Surftimeconst0O8Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeconst0O0Parameters, SurferUs2O0Surftimeconst0O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeconst0O025Parameters, SurferUs2O0Surftimeconst0O025Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O025Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeconst0O05Parameters, SurferUs2O0Surftimeconst0O05Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O05Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeconst0O1Parameters, SurferUs2O0Surftimeconst0O1Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O1Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeconst0O2Parameters, SurferUs2O0Surftimeconst0O2Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O2Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeconst0O4Parameters, SurferUs2O0Surftimeconst0O4Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O4Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeconst0O6Parameters, SurferUs2O0Surftimeconst0O6Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O6Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeconst0O8Parameters, SurferUs2O0Surftimeconst0O8Step>>(sObjectsParameters->sSurferUs2O0Surftimeconst0O8Step));
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
