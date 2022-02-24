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
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_1o0/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_1o0/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_1o0/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_1o0/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_0o0/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_0o25/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_0o5/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_0o75/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_1o25/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_1o5/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_1o75/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_2o0/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_2o25/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_2o5/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_2o75/parameters.h"
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_3o0/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_0o0/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_0o25/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_0o5/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_0o75/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_1o25/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_1o5/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_1o75/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_2o0/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_2o25/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_2o5/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_2o75/parameters.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_3o0/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_0o0/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_0o25/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_0o5/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_0o75/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_1o25/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_1o5/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_1o75/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_2o0/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_2o25/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_2o5/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_2o75/parameters.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_3o0/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_0o0/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_0o25/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_0o5/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_0o75/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_1o25/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_1o5/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_1o75/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_2o0/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_2o25/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_2o5/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_2o75/parameters.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_3o0/parameters.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct InitObjectsParameters {
    // make data
    std::vector<std::shared_ptr<InitInitStaticBase>> sInitsStatic;
    std::vector<std::shared_ptr<InitInitDynamicBase>> sInitsDynamic;
    InitObjectsParameters(std::shared_ptr<TypeObjectsParameters> sObjectsParameters) {
        // FLAG: MAKE OBJECT BEGIN
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor1O0Parameters, SurferUs1O0Surftimeprefactor1O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor1O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor1O0Parameters, SurferUs0O1Surftimeprefactor1O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor1O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor1O0Parameters, SurferUs0O5Surftimeprefactor1O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor1O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor1O0Parameters, SurferUs2O0Surftimeprefactor1O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor1O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor0O0Parameters, SurferUs1O0Surftimeprefactor0O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor0O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor0O25Parameters, SurferUs1O0Surftimeprefactor0O25Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor0O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor0O5Parameters, SurferUs1O0Surftimeprefactor0O5Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor0O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor0O75Parameters, SurferUs1O0Surftimeprefactor0O75Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor0O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor1O25Parameters, SurferUs1O0Surftimeprefactor1O25Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor1O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor1O5Parameters, SurferUs1O0Surftimeprefactor1O5Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor1O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor1O75Parameters, SurferUs1O0Surftimeprefactor1O75Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor1O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor2O0Parameters, SurferUs1O0Surftimeprefactor2O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor2O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor2O25Parameters, SurferUs1O0Surftimeprefactor2O25Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor2O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor2O5Parameters, SurferUs1O0Surftimeprefactor2O5Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor2O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor2O75Parameters, SurferUs1O0Surftimeprefactor2O75Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor2O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs1O0Surftimeprefactor3O0Parameters, SurferUs1O0Surftimeprefactor3O0Step>>(sObjectsParameters->sSurferUs1O0Surftimeprefactor3O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor0O0Parameters, SurferUs0O1Surftimeprefactor0O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor0O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor0O25Parameters, SurferUs0O1Surftimeprefactor0O25Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor0O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor0O5Parameters, SurferUs0O1Surftimeprefactor0O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor0O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor0O75Parameters, SurferUs0O1Surftimeprefactor0O75Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor0O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor1O25Parameters, SurferUs0O1Surftimeprefactor1O25Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor1O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor1O5Parameters, SurferUs0O1Surftimeprefactor1O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor1O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor1O75Parameters, SurferUs0O1Surftimeprefactor1O75Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor1O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor2O0Parameters, SurferUs0O1Surftimeprefactor2O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor2O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor2O25Parameters, SurferUs0O1Surftimeprefactor2O25Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor2O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor2O5Parameters, SurferUs0O1Surftimeprefactor2O5Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor2O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor2O75Parameters, SurferUs0O1Surftimeprefactor2O75Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor2O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O1Surftimeprefactor3O0Parameters, SurferUs0O1Surftimeprefactor3O0Step>>(sObjectsParameters->sSurferUs0O1Surftimeprefactor3O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor0O0Parameters, SurferUs0O5Surftimeprefactor0O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor0O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor0O25Parameters, SurferUs0O5Surftimeprefactor0O25Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor0O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor0O5Parameters, SurferUs0O5Surftimeprefactor0O5Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor0O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor0O75Parameters, SurferUs0O5Surftimeprefactor0O75Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor0O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor1O25Parameters, SurferUs0O5Surftimeprefactor1O25Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor1O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor1O5Parameters, SurferUs0O5Surftimeprefactor1O5Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor1O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor1O75Parameters, SurferUs0O5Surftimeprefactor1O75Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor1O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor2O0Parameters, SurferUs0O5Surftimeprefactor2O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor2O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor2O25Parameters, SurferUs0O5Surftimeprefactor2O25Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor2O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor2O5Parameters, SurferUs0O5Surftimeprefactor2O5Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor2O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor2O75Parameters, SurferUs0O5Surftimeprefactor2O75Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor2O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs0O5Surftimeprefactor3O0Parameters, SurferUs0O5Surftimeprefactor3O0Step>>(sObjectsParameters->sSurferUs0O5Surftimeprefactor3O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor0O0Parameters, SurferUs2O0Surftimeprefactor0O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor0O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor0O25Parameters, SurferUs2O0Surftimeprefactor0O25Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor0O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor0O5Parameters, SurferUs2O0Surftimeprefactor0O5Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor0O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor0O75Parameters, SurferUs2O0Surftimeprefactor0O75Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor0O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor1O25Parameters, SurferUs2O0Surftimeprefactor1O25Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor1O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor1O5Parameters, SurferUs2O0Surftimeprefactor1O5Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor1O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor1O75Parameters, SurferUs2O0Surftimeprefactor1O75Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor1O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor2O0Parameters, SurferUs2O0Surftimeprefactor2O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor2O0Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor2O25Parameters, SurferUs2O0Surftimeprefactor2O25Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor2O25Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor2O5Parameters, SurferUs2O0Surftimeprefactor2O5Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor2O5Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor2O75Parameters, SurferUs2O0Surftimeprefactor2O75Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor2O75Step));
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitSurferUs2O0Surftimeprefactor3O0Parameters, SurferUs2O0Surftimeprefactor3O0Step>>(sObjectsParameters->sSurferUs2O0Surftimeprefactor3O0Step));
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
