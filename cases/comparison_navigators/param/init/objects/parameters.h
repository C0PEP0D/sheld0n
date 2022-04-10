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
#include "param/init/objects/surfer__us_15o58__surftimeconst_1o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_0o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_2o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_4o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_5o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_6o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_7o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_8o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_9o0__reorientationtime_0o5/parameters.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_10o0__reorientationtime_0o5/parameters.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct InitObjectsParameters {
    // make data
    std::vector<std::shared_ptr<InitInitBase>> data;
    InitObjectsParameters(const TypeObjects& objects) {
        // FLAG: MAKE OBJECT BEGIN
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst1O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst1O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst1O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst0O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst0O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst0O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst2O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst2O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst2O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst3O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst3O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst3O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst4O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst4O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst4O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst5O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst5O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst5O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst6O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst6O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst6O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst7O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst7O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst8O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst8O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst8O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst9O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst9O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst9O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<InitInit<InitSurferUs15O58Surftimeconst10O0Reorientationtime0O5Parameters, SurferUs15O58Surftimeconst10O0Reorientationtime0O5Step>>(objects.parameters.sSurferUs15O58Surftimeconst10O0Reorientationtime0O5Step));
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
