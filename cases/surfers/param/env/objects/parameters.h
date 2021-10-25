#ifndef C0P_PARAM_ENV_OBJECTS_PARAMETERS_H
#define C0P_PARAM_ENV_OBJECTS_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std includes
#include <memory>
// app includes
#include "core/env/objects/prop.h"
#include "core/env/objects/core.h"
#include "param/env/flow/choice.h"
// FLAG: INCLUDE OBJECT BEGIN
#include "param/env/objects/surfer__us_1o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/riser__us_1o0/choice.h"
#include "param/env/objects/riser__us_0o5/choice.h"
#include "param/env/objects/riser__us_1o5/choice.h"
#include "param/env/objects/riser__us_2o0/choice.h"
#include "param/env/objects/riser__us_2o5/choice.h"
#include "param/env/objects/riser__us_3o0/choice.h"
#include "param/env/objects/riser__us_3o5/choice.h"
#include "param/env/objects/riser__us_4o0/choice.h"
#include "param/env/objects/riser__us_4o5/choice.h"
#include "param/env/objects/riser__us_5o0/choice.h"
#include "param/env/objects/riser__us_6o0/choice.h"
#include "param/env/objects/riser__us_7o0/choice.h"
#include "param/env/objects/riser__us_8o0/choice.h"
#include "param/env/objects/riser__us_9o0/choice.h"
#include "param/env/objects/riser__us_10o0/choice.h"
#include "param/env/objects/riser__us_15o0/choice.h"
#include "param/env/objects/riser__us_20o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_1o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_20o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_2o5__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_3o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_10o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_0o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_2o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_3o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_4o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_5o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_6o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_7o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_8o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_9o0/choice.h"
#include "param/env/objects/surfer__us_9o0__surftimeconst_10o0/choice.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct ObjectsParameters {
    // FLAG: DECLARE OBJECT BEGIN
    std::shared_ptr<SurferUs1O0Surftimeconst1O0Step> sSurferUs1O0Surftimeconst1O0Step;
    unsigned int surfer__us_1o0__surftimeconst_1o0Index;
    std::shared_ptr<RiserUs1O0Step> sRiserUs1O0Step;
    unsigned int riser__us_1o0Index;
    std::shared_ptr<RiserUs0O5Step> sRiserUs0O5Step;
    unsigned int riser__us_0o5Index;
    std::shared_ptr<RiserUs1O5Step> sRiserUs1O5Step;
    unsigned int riser__us_1o5Index;
    std::shared_ptr<RiserUs2O0Step> sRiserUs2O0Step;
    unsigned int riser__us_2o0Index;
    std::shared_ptr<RiserUs2O5Step> sRiserUs2O5Step;
    unsigned int riser__us_2o5Index;
    std::shared_ptr<RiserUs3O0Step> sRiserUs3O0Step;
    unsigned int riser__us_3o0Index;
    std::shared_ptr<RiserUs3O5Step> sRiserUs3O5Step;
    unsigned int riser__us_3o5Index;
    std::shared_ptr<RiserUs4O0Step> sRiserUs4O0Step;
    unsigned int riser__us_4o0Index;
    std::shared_ptr<RiserUs4O5Step> sRiserUs4O5Step;
    unsigned int riser__us_4o5Index;
    std::shared_ptr<RiserUs5O0Step> sRiserUs5O0Step;
    unsigned int riser__us_5o0Index;
    std::shared_ptr<RiserUs6O0Step> sRiserUs6O0Step;
    unsigned int riser__us_6o0Index;
    std::shared_ptr<RiserUs7O0Step> sRiserUs7O0Step;
    unsigned int riser__us_7o0Index;
    std::shared_ptr<RiserUs8O0Step> sRiserUs8O0Step;
    unsigned int riser__us_8o0Index;
    std::shared_ptr<RiserUs9O0Step> sRiserUs9O0Step;
    unsigned int riser__us_9o0Index;
    std::shared_ptr<RiserUs10O0Step> sRiserUs10O0Step;
    unsigned int riser__us_10o0Index;
    std::shared_ptr<RiserUs15O0Step> sRiserUs15O0Step;
    unsigned int riser__us_15o0Index;
    std::shared_ptr<RiserUs20O0Step> sRiserUs20O0Step;
    unsigned int riser__us_20o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst1O0Step> sSurferUs0O5Surftimeconst1O0Step;
    unsigned int surfer__us_0o5__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst1O0Step> sSurferUs1O5Surftimeconst1O0Step;
    unsigned int surfer__us_1o5__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst1O0Step> sSurferUs2O0Surftimeconst1O0Step;
    unsigned int surfer__us_2o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst1O0Step> sSurferUs2O5Surftimeconst1O0Step;
    unsigned int surfer__us_2o5__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst1O0Step> sSurferUs3O0Surftimeconst1O0Step;
    unsigned int surfer__us_3o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst1O0Step> sSurferUs3O5Surftimeconst1O0Step;
    unsigned int surfer__us_3o5__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst1O0Step> sSurferUs4O0Surftimeconst1O0Step;
    unsigned int surfer__us_4o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst1O0Step> sSurferUs4O5Surftimeconst1O0Step;
    unsigned int surfer__us_4o5__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst1O0Step> sSurferUs5O0Surftimeconst1O0Step;
    unsigned int surfer__us_5o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst1O0Step> sSurferUs6O0Surftimeconst1O0Step;
    unsigned int surfer__us_6o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst1O0Step> sSurferUs7O0Surftimeconst1O0Step;
    unsigned int surfer__us_7o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst1O0Step> sSurferUs8O0Surftimeconst1O0Step;
    unsigned int surfer__us_8o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst1O0Step> sSurferUs9O0Surftimeconst1O0Step;
    unsigned int surfer__us_9o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst1O0Step> sSurferUs10O0Surftimeconst1O0Step;
    unsigned int surfer__us_10o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst1O0Step> sSurferUs15O0Surftimeconst1O0Step;
    unsigned int surfer__us_15o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst1O0Step> sSurferUs20O0Surftimeconst1O0Step;
    unsigned int surfer__us_20o0__surftimeconst_1o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst0O0Step> sSurferUs0O5Surftimeconst0O0Step;
    unsigned int surfer__us_0o5__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst2O0Step> sSurferUs0O5Surftimeconst2O0Step;
    unsigned int surfer__us_0o5__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst3O0Step> sSurferUs0O5Surftimeconst3O0Step;
    unsigned int surfer__us_0o5__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst4O0Step> sSurferUs0O5Surftimeconst4O0Step;
    unsigned int surfer__us_0o5__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst5O0Step> sSurferUs0O5Surftimeconst5O0Step;
    unsigned int surfer__us_0o5__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst6O0Step> sSurferUs0O5Surftimeconst6O0Step;
    unsigned int surfer__us_0o5__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst7O0Step> sSurferUs0O5Surftimeconst7O0Step;
    unsigned int surfer__us_0o5__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst8O0Step> sSurferUs0O5Surftimeconst8O0Step;
    unsigned int surfer__us_0o5__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst9O0Step> sSurferUs0O5Surftimeconst9O0Step;
    unsigned int surfer__us_0o5__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs0O5Surftimeconst10O0Step> sSurferUs0O5Surftimeconst10O0Step;
    unsigned int surfer__us_0o5__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst0O0Step> sSurferUs10O0Surftimeconst0O0Step;
    unsigned int surfer__us_10o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst2O0Step> sSurferUs10O0Surftimeconst2O0Step;
    unsigned int surfer__us_10o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst3O0Step> sSurferUs10O0Surftimeconst3O0Step;
    unsigned int surfer__us_10o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst4O0Step> sSurferUs10O0Surftimeconst4O0Step;
    unsigned int surfer__us_10o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst5O0Step> sSurferUs10O0Surftimeconst5O0Step;
    unsigned int surfer__us_10o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst6O0Step> sSurferUs10O0Surftimeconst6O0Step;
    unsigned int surfer__us_10o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst7O0Step> sSurferUs10O0Surftimeconst7O0Step;
    unsigned int surfer__us_10o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst8O0Step> sSurferUs10O0Surftimeconst8O0Step;
    unsigned int surfer__us_10o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst9O0Step> sSurferUs10O0Surftimeconst9O0Step;
    unsigned int surfer__us_10o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs10O0Surftimeconst10O0Step> sSurferUs10O0Surftimeconst10O0Step;
    unsigned int surfer__us_10o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst0O0Step> sSurferUs15O0Surftimeconst0O0Step;
    unsigned int surfer__us_15o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst2O0Step> sSurferUs15O0Surftimeconst2O0Step;
    unsigned int surfer__us_15o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst3O0Step> sSurferUs15O0Surftimeconst3O0Step;
    unsigned int surfer__us_15o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst4O0Step> sSurferUs15O0Surftimeconst4O0Step;
    unsigned int surfer__us_15o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst5O0Step> sSurferUs15O0Surftimeconst5O0Step;
    unsigned int surfer__us_15o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst6O0Step> sSurferUs15O0Surftimeconst6O0Step;
    unsigned int surfer__us_15o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst7O0Step> sSurferUs15O0Surftimeconst7O0Step;
    unsigned int surfer__us_15o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst8O0Step> sSurferUs15O0Surftimeconst8O0Step;
    unsigned int surfer__us_15o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst9O0Step> sSurferUs15O0Surftimeconst9O0Step;
    unsigned int surfer__us_15o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs15O0Surftimeconst10O0Step> sSurferUs15O0Surftimeconst10O0Step;
    unsigned int surfer__us_15o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst0O0Step> sSurferUs1O0Surftimeconst0O0Step;
    unsigned int surfer__us_1o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst2O0Step> sSurferUs1O0Surftimeconst2O0Step;
    unsigned int surfer__us_1o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst3O0Step> sSurferUs1O0Surftimeconst3O0Step;
    unsigned int surfer__us_1o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst4O0Step> sSurferUs1O0Surftimeconst4O0Step;
    unsigned int surfer__us_1o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst5O0Step> sSurferUs1O0Surftimeconst5O0Step;
    unsigned int surfer__us_1o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst6O0Step> sSurferUs1O0Surftimeconst6O0Step;
    unsigned int surfer__us_1o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst7O0Step> sSurferUs1O0Surftimeconst7O0Step;
    unsigned int surfer__us_1o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst8O0Step> sSurferUs1O0Surftimeconst8O0Step;
    unsigned int surfer__us_1o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst9O0Step> sSurferUs1O0Surftimeconst9O0Step;
    unsigned int surfer__us_1o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs1O0Surftimeconst10O0Step> sSurferUs1O0Surftimeconst10O0Step;
    unsigned int surfer__us_1o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst0O0Step> sSurferUs1O5Surftimeconst0O0Step;
    unsigned int surfer__us_1o5__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst2O0Step> sSurferUs1O5Surftimeconst2O0Step;
    unsigned int surfer__us_1o5__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst3O0Step> sSurferUs1O5Surftimeconst3O0Step;
    unsigned int surfer__us_1o5__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst4O0Step> sSurferUs1O5Surftimeconst4O0Step;
    unsigned int surfer__us_1o5__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst5O0Step> sSurferUs1O5Surftimeconst5O0Step;
    unsigned int surfer__us_1o5__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst6O0Step> sSurferUs1O5Surftimeconst6O0Step;
    unsigned int surfer__us_1o5__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst7O0Step> sSurferUs1O5Surftimeconst7O0Step;
    unsigned int surfer__us_1o5__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst8O0Step> sSurferUs1O5Surftimeconst8O0Step;
    unsigned int surfer__us_1o5__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst9O0Step> sSurferUs1O5Surftimeconst9O0Step;
    unsigned int surfer__us_1o5__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs1O5Surftimeconst10O0Step> sSurferUs1O5Surftimeconst10O0Step;
    unsigned int surfer__us_1o5__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst0O0Step> sSurferUs20O0Surftimeconst0O0Step;
    unsigned int surfer__us_20o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst2O0Step> sSurferUs20O0Surftimeconst2O0Step;
    unsigned int surfer__us_20o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst3O0Step> sSurferUs20O0Surftimeconst3O0Step;
    unsigned int surfer__us_20o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst4O0Step> sSurferUs20O0Surftimeconst4O0Step;
    unsigned int surfer__us_20o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst5O0Step> sSurferUs20O0Surftimeconst5O0Step;
    unsigned int surfer__us_20o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst6O0Step> sSurferUs20O0Surftimeconst6O0Step;
    unsigned int surfer__us_20o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst7O0Step> sSurferUs20O0Surftimeconst7O0Step;
    unsigned int surfer__us_20o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst8O0Step> sSurferUs20O0Surftimeconst8O0Step;
    unsigned int surfer__us_20o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst9O0Step> sSurferUs20O0Surftimeconst9O0Step;
    unsigned int surfer__us_20o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs20O0Surftimeconst10O0Step> sSurferUs20O0Surftimeconst10O0Step;
    unsigned int surfer__us_20o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst0O0Step> sSurferUs2O0Surftimeconst0O0Step;
    unsigned int surfer__us_2o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst2O0Step> sSurferUs2O0Surftimeconst2O0Step;
    unsigned int surfer__us_2o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst3O0Step> sSurferUs2O0Surftimeconst3O0Step;
    unsigned int surfer__us_2o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst4O0Step> sSurferUs2O0Surftimeconst4O0Step;
    unsigned int surfer__us_2o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst5O0Step> sSurferUs2O0Surftimeconst5O0Step;
    unsigned int surfer__us_2o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst6O0Step> sSurferUs2O0Surftimeconst6O0Step;
    unsigned int surfer__us_2o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst7O0Step> sSurferUs2O0Surftimeconst7O0Step;
    unsigned int surfer__us_2o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst8O0Step> sSurferUs2O0Surftimeconst8O0Step;
    unsigned int surfer__us_2o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst9O0Step> sSurferUs2O0Surftimeconst9O0Step;
    unsigned int surfer__us_2o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs2O0Surftimeconst10O0Step> sSurferUs2O0Surftimeconst10O0Step;
    unsigned int surfer__us_2o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst0O0Step> sSurferUs2O5Surftimeconst0O0Step;
    unsigned int surfer__us_2o5__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst2O0Step> sSurferUs2O5Surftimeconst2O0Step;
    unsigned int surfer__us_2o5__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst3O0Step> sSurferUs2O5Surftimeconst3O0Step;
    unsigned int surfer__us_2o5__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst4O0Step> sSurferUs2O5Surftimeconst4O0Step;
    unsigned int surfer__us_2o5__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst5O0Step> sSurferUs2O5Surftimeconst5O0Step;
    unsigned int surfer__us_2o5__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst6O0Step> sSurferUs2O5Surftimeconst6O0Step;
    unsigned int surfer__us_2o5__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst7O0Step> sSurferUs2O5Surftimeconst7O0Step;
    unsigned int surfer__us_2o5__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst8O0Step> sSurferUs2O5Surftimeconst8O0Step;
    unsigned int surfer__us_2o5__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst9O0Step> sSurferUs2O5Surftimeconst9O0Step;
    unsigned int surfer__us_2o5__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs2O5Surftimeconst10O0Step> sSurferUs2O5Surftimeconst10O0Step;
    unsigned int surfer__us_2o5__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst0O0Step> sSurferUs3O0Surftimeconst0O0Step;
    unsigned int surfer__us_3o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst2O0Step> sSurferUs3O0Surftimeconst2O0Step;
    unsigned int surfer__us_3o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst3O0Step> sSurferUs3O0Surftimeconst3O0Step;
    unsigned int surfer__us_3o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst4O0Step> sSurferUs3O0Surftimeconst4O0Step;
    unsigned int surfer__us_3o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst5O0Step> sSurferUs3O0Surftimeconst5O0Step;
    unsigned int surfer__us_3o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst6O0Step> sSurferUs3O0Surftimeconst6O0Step;
    unsigned int surfer__us_3o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst7O0Step> sSurferUs3O0Surftimeconst7O0Step;
    unsigned int surfer__us_3o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst8O0Step> sSurferUs3O0Surftimeconst8O0Step;
    unsigned int surfer__us_3o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst9O0Step> sSurferUs3O0Surftimeconst9O0Step;
    unsigned int surfer__us_3o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs3O0Surftimeconst10O0Step> sSurferUs3O0Surftimeconst10O0Step;
    unsigned int surfer__us_3o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst0O0Step> sSurferUs3O5Surftimeconst0O0Step;
    unsigned int surfer__us_3o5__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst2O0Step> sSurferUs3O5Surftimeconst2O0Step;
    unsigned int surfer__us_3o5__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst3O0Step> sSurferUs3O5Surftimeconst3O0Step;
    unsigned int surfer__us_3o5__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst4O0Step> sSurferUs3O5Surftimeconst4O0Step;
    unsigned int surfer__us_3o5__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst5O0Step> sSurferUs3O5Surftimeconst5O0Step;
    unsigned int surfer__us_3o5__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst6O0Step> sSurferUs3O5Surftimeconst6O0Step;
    unsigned int surfer__us_3o5__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst7O0Step> sSurferUs3O5Surftimeconst7O0Step;
    unsigned int surfer__us_3o5__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst8O0Step> sSurferUs3O5Surftimeconst8O0Step;
    unsigned int surfer__us_3o5__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst9O0Step> sSurferUs3O5Surftimeconst9O0Step;
    unsigned int surfer__us_3o5__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs3O5Surftimeconst10O0Step> sSurferUs3O5Surftimeconst10O0Step;
    unsigned int surfer__us_3o5__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst0O0Step> sSurferUs4O0Surftimeconst0O0Step;
    unsigned int surfer__us_4o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst2O0Step> sSurferUs4O0Surftimeconst2O0Step;
    unsigned int surfer__us_4o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst3O0Step> sSurferUs4O0Surftimeconst3O0Step;
    unsigned int surfer__us_4o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst4O0Step> sSurferUs4O0Surftimeconst4O0Step;
    unsigned int surfer__us_4o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst5O0Step> sSurferUs4O0Surftimeconst5O0Step;
    unsigned int surfer__us_4o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst6O0Step> sSurferUs4O0Surftimeconst6O0Step;
    unsigned int surfer__us_4o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst7O0Step> sSurferUs4O0Surftimeconst7O0Step;
    unsigned int surfer__us_4o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst8O0Step> sSurferUs4O0Surftimeconst8O0Step;
    unsigned int surfer__us_4o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst9O0Step> sSurferUs4O0Surftimeconst9O0Step;
    unsigned int surfer__us_4o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs4O0Surftimeconst10O0Step> sSurferUs4O0Surftimeconst10O0Step;
    unsigned int surfer__us_4o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst0O0Step> sSurferUs4O5Surftimeconst0O0Step;
    unsigned int surfer__us_4o5__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst2O0Step> sSurferUs4O5Surftimeconst2O0Step;
    unsigned int surfer__us_4o5__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst3O0Step> sSurferUs4O5Surftimeconst3O0Step;
    unsigned int surfer__us_4o5__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst4O0Step> sSurferUs4O5Surftimeconst4O0Step;
    unsigned int surfer__us_4o5__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst5O0Step> sSurferUs4O5Surftimeconst5O0Step;
    unsigned int surfer__us_4o5__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst6O0Step> sSurferUs4O5Surftimeconst6O0Step;
    unsigned int surfer__us_4o5__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst7O0Step> sSurferUs4O5Surftimeconst7O0Step;
    unsigned int surfer__us_4o5__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst8O0Step> sSurferUs4O5Surftimeconst8O0Step;
    unsigned int surfer__us_4o5__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst9O0Step> sSurferUs4O5Surftimeconst9O0Step;
    unsigned int surfer__us_4o5__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs4O5Surftimeconst10O0Step> sSurferUs4O5Surftimeconst10O0Step;
    unsigned int surfer__us_4o5__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst0O0Step> sSurferUs5O0Surftimeconst0O0Step;
    unsigned int surfer__us_5o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst2O0Step> sSurferUs5O0Surftimeconst2O0Step;
    unsigned int surfer__us_5o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst3O0Step> sSurferUs5O0Surftimeconst3O0Step;
    unsigned int surfer__us_5o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst4O0Step> sSurferUs5O0Surftimeconst4O0Step;
    unsigned int surfer__us_5o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst5O0Step> sSurferUs5O0Surftimeconst5O0Step;
    unsigned int surfer__us_5o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst6O0Step> sSurferUs5O0Surftimeconst6O0Step;
    unsigned int surfer__us_5o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst7O0Step> sSurferUs5O0Surftimeconst7O0Step;
    unsigned int surfer__us_5o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst8O0Step> sSurferUs5O0Surftimeconst8O0Step;
    unsigned int surfer__us_5o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst9O0Step> sSurferUs5O0Surftimeconst9O0Step;
    unsigned int surfer__us_5o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs5O0Surftimeconst10O0Step> sSurferUs5O0Surftimeconst10O0Step;
    unsigned int surfer__us_5o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst0O0Step> sSurferUs6O0Surftimeconst0O0Step;
    unsigned int surfer__us_6o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst2O0Step> sSurferUs6O0Surftimeconst2O0Step;
    unsigned int surfer__us_6o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst3O0Step> sSurferUs6O0Surftimeconst3O0Step;
    unsigned int surfer__us_6o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst4O0Step> sSurferUs6O0Surftimeconst4O0Step;
    unsigned int surfer__us_6o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst5O0Step> sSurferUs6O0Surftimeconst5O0Step;
    unsigned int surfer__us_6o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst6O0Step> sSurferUs6O0Surftimeconst6O0Step;
    unsigned int surfer__us_6o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst7O0Step> sSurferUs6O0Surftimeconst7O0Step;
    unsigned int surfer__us_6o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst8O0Step> sSurferUs6O0Surftimeconst8O0Step;
    unsigned int surfer__us_6o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst9O0Step> sSurferUs6O0Surftimeconst9O0Step;
    unsigned int surfer__us_6o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs6O0Surftimeconst10O0Step> sSurferUs6O0Surftimeconst10O0Step;
    unsigned int surfer__us_6o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst0O0Step> sSurferUs7O0Surftimeconst0O0Step;
    unsigned int surfer__us_7o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst2O0Step> sSurferUs7O0Surftimeconst2O0Step;
    unsigned int surfer__us_7o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst3O0Step> sSurferUs7O0Surftimeconst3O0Step;
    unsigned int surfer__us_7o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst4O0Step> sSurferUs7O0Surftimeconst4O0Step;
    unsigned int surfer__us_7o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst5O0Step> sSurferUs7O0Surftimeconst5O0Step;
    unsigned int surfer__us_7o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst6O0Step> sSurferUs7O0Surftimeconst6O0Step;
    unsigned int surfer__us_7o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst7O0Step> sSurferUs7O0Surftimeconst7O0Step;
    unsigned int surfer__us_7o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst8O0Step> sSurferUs7O0Surftimeconst8O0Step;
    unsigned int surfer__us_7o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst9O0Step> sSurferUs7O0Surftimeconst9O0Step;
    unsigned int surfer__us_7o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs7O0Surftimeconst10O0Step> sSurferUs7O0Surftimeconst10O0Step;
    unsigned int surfer__us_7o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst0O0Step> sSurferUs8O0Surftimeconst0O0Step;
    unsigned int surfer__us_8o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst2O0Step> sSurferUs8O0Surftimeconst2O0Step;
    unsigned int surfer__us_8o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst3O0Step> sSurferUs8O0Surftimeconst3O0Step;
    unsigned int surfer__us_8o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst4O0Step> sSurferUs8O0Surftimeconst4O0Step;
    unsigned int surfer__us_8o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst5O0Step> sSurferUs8O0Surftimeconst5O0Step;
    unsigned int surfer__us_8o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst6O0Step> sSurferUs8O0Surftimeconst6O0Step;
    unsigned int surfer__us_8o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst7O0Step> sSurferUs8O0Surftimeconst7O0Step;
    unsigned int surfer__us_8o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst8O0Step> sSurferUs8O0Surftimeconst8O0Step;
    unsigned int surfer__us_8o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst9O0Step> sSurferUs8O0Surftimeconst9O0Step;
    unsigned int surfer__us_8o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs8O0Surftimeconst10O0Step> sSurferUs8O0Surftimeconst10O0Step;
    unsigned int surfer__us_8o0__surftimeconst_10o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst0O0Step> sSurferUs9O0Surftimeconst0O0Step;
    unsigned int surfer__us_9o0__surftimeconst_0o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst2O0Step> sSurferUs9O0Surftimeconst2O0Step;
    unsigned int surfer__us_9o0__surftimeconst_2o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst3O0Step> sSurferUs9O0Surftimeconst3O0Step;
    unsigned int surfer__us_9o0__surftimeconst_3o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst4O0Step> sSurferUs9O0Surftimeconst4O0Step;
    unsigned int surfer__us_9o0__surftimeconst_4o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst5O0Step> sSurferUs9O0Surftimeconst5O0Step;
    unsigned int surfer__us_9o0__surftimeconst_5o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst6O0Step> sSurferUs9O0Surftimeconst6O0Step;
    unsigned int surfer__us_9o0__surftimeconst_6o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst7O0Step> sSurferUs9O0Surftimeconst7O0Step;
    unsigned int surfer__us_9o0__surftimeconst_7o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst8O0Step> sSurferUs9O0Surftimeconst8O0Step;
    unsigned int surfer__us_9o0__surftimeconst_8o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst9O0Step> sSurferUs9O0Surftimeconst9O0Step;
    unsigned int surfer__us_9o0__surftimeconst_9o0Index;
    std::shared_ptr<SurferUs9O0Surftimeconst10O0Step> sSurferUs9O0Surftimeconst10O0Step;
    unsigned int surfer__us_9o0__surftimeconst_10o0Index;
    // FLAG: DECLARE OBJECT END
    
    // construct data
    std::vector<std::shared_ptr<StepObject>> data;
    ObjectsParameters(std::shared_ptr<Flow> sFlow, Objects<ObjectsParameters>* pObjects) {
        // FLAG: MAKE OBJECT BEGIN
        // // surfer__us_1o0__surftimeconst_1o0
        sSurferUs1O0Surftimeconst1O0Step = std::make_shared<SurferUs1O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst1O0Step);
        surfer__us_1o0__surftimeconst_1o0Index = data.size() - 1;
        // // riser__us_1o0
        sRiserUs1O0Step = std::make_shared<RiserUs1O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs1O0Step);
        riser__us_1o0Index = data.size() - 1;
        // // riser__us_0o5
        sRiserUs0O5Step = std::make_shared<RiserUs0O5Step>(sFlow, pObjects);
        data.push_back(sRiserUs0O5Step);
        riser__us_0o5Index = data.size() - 1;
        // // riser__us_1o5
        sRiserUs1O5Step = std::make_shared<RiserUs1O5Step>(sFlow, pObjects);
        data.push_back(sRiserUs1O5Step);
        riser__us_1o5Index = data.size() - 1;
        // // riser__us_2o0
        sRiserUs2O0Step = std::make_shared<RiserUs2O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs2O0Step);
        riser__us_2o0Index = data.size() - 1;
        // // riser__us_2o5
        sRiserUs2O5Step = std::make_shared<RiserUs2O5Step>(sFlow, pObjects);
        data.push_back(sRiserUs2O5Step);
        riser__us_2o5Index = data.size() - 1;
        // // riser__us_3o0
        sRiserUs3O0Step = std::make_shared<RiserUs3O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs3O0Step);
        riser__us_3o0Index = data.size() - 1;
        // // riser__us_3o5
        sRiserUs3O5Step = std::make_shared<RiserUs3O5Step>(sFlow, pObjects);
        data.push_back(sRiserUs3O5Step);
        riser__us_3o5Index = data.size() - 1;
        // // riser__us_4o0
        sRiserUs4O0Step = std::make_shared<RiserUs4O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs4O0Step);
        riser__us_4o0Index = data.size() - 1;
        // // riser__us_4o5
        sRiserUs4O5Step = std::make_shared<RiserUs4O5Step>(sFlow, pObjects);
        data.push_back(sRiserUs4O5Step);
        riser__us_4o5Index = data.size() - 1;
        // // riser__us_5o0
        sRiserUs5O0Step = std::make_shared<RiserUs5O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs5O0Step);
        riser__us_5o0Index = data.size() - 1;
        // // riser__us_6o0
        sRiserUs6O0Step = std::make_shared<RiserUs6O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs6O0Step);
        riser__us_6o0Index = data.size() - 1;
        // // riser__us_7o0
        sRiserUs7O0Step = std::make_shared<RiserUs7O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs7O0Step);
        riser__us_7o0Index = data.size() - 1;
        // // riser__us_8o0
        sRiserUs8O0Step = std::make_shared<RiserUs8O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs8O0Step);
        riser__us_8o0Index = data.size() - 1;
        // // riser__us_9o0
        sRiserUs9O0Step = std::make_shared<RiserUs9O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs9O0Step);
        riser__us_9o0Index = data.size() - 1;
        // // riser__us_10o0
        sRiserUs10O0Step = std::make_shared<RiserUs10O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs10O0Step);
        riser__us_10o0Index = data.size() - 1;
        // // riser__us_15o0
        sRiserUs15O0Step = std::make_shared<RiserUs15O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs15O0Step);
        riser__us_15o0Index = data.size() - 1;
        // // riser__us_20o0
        sRiserUs20O0Step = std::make_shared<RiserUs20O0Step>(sFlow, pObjects);
        data.push_back(sRiserUs20O0Step);
        riser__us_20o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_1o0
        sSurferUs0O5Surftimeconst1O0Step = std::make_shared<SurferUs0O5Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst1O0Step);
        surfer__us_0o5__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_1o0
        sSurferUs1O5Surftimeconst1O0Step = std::make_shared<SurferUs1O5Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst1O0Step);
        surfer__us_1o5__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_1o0
        sSurferUs2O0Surftimeconst1O0Step = std::make_shared<SurferUs2O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst1O0Step);
        surfer__us_2o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_1o0
        sSurferUs2O5Surftimeconst1O0Step = std::make_shared<SurferUs2O5Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst1O0Step);
        surfer__us_2o5__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_1o0
        sSurferUs3O0Surftimeconst1O0Step = std::make_shared<SurferUs3O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst1O0Step);
        surfer__us_3o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_1o0
        sSurferUs3O5Surftimeconst1O0Step = std::make_shared<SurferUs3O5Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst1O0Step);
        surfer__us_3o5__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_1o0
        sSurferUs4O0Surftimeconst1O0Step = std::make_shared<SurferUs4O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst1O0Step);
        surfer__us_4o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_1o0
        sSurferUs4O5Surftimeconst1O0Step = std::make_shared<SurferUs4O5Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst1O0Step);
        surfer__us_4o5__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_1o0
        sSurferUs5O0Surftimeconst1O0Step = std::make_shared<SurferUs5O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst1O0Step);
        surfer__us_5o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_1o0
        sSurferUs6O0Surftimeconst1O0Step = std::make_shared<SurferUs6O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst1O0Step);
        surfer__us_6o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_1o0
        sSurferUs7O0Surftimeconst1O0Step = std::make_shared<SurferUs7O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst1O0Step);
        surfer__us_7o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_1o0
        sSurferUs8O0Surftimeconst1O0Step = std::make_shared<SurferUs8O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst1O0Step);
        surfer__us_8o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_1o0
        sSurferUs9O0Surftimeconst1O0Step = std::make_shared<SurferUs9O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst1O0Step);
        surfer__us_9o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_1o0
        sSurferUs10O0Surftimeconst1O0Step = std::make_shared<SurferUs10O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst1O0Step);
        surfer__us_10o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_1o0
        sSurferUs15O0Surftimeconst1O0Step = std::make_shared<SurferUs15O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst1O0Step);
        surfer__us_15o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_1o0
        sSurferUs20O0Surftimeconst1O0Step = std::make_shared<SurferUs20O0Surftimeconst1O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst1O0Step);
        surfer__us_20o0__surftimeconst_1o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_0o0
        sSurferUs0O5Surftimeconst0O0Step = std::make_shared<SurferUs0O5Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst0O0Step);
        surfer__us_0o5__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_2o0
        sSurferUs0O5Surftimeconst2O0Step = std::make_shared<SurferUs0O5Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst2O0Step);
        surfer__us_0o5__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_3o0
        sSurferUs0O5Surftimeconst3O0Step = std::make_shared<SurferUs0O5Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst3O0Step);
        surfer__us_0o5__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_4o0
        sSurferUs0O5Surftimeconst4O0Step = std::make_shared<SurferUs0O5Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst4O0Step);
        surfer__us_0o5__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_5o0
        sSurferUs0O5Surftimeconst5O0Step = std::make_shared<SurferUs0O5Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst5O0Step);
        surfer__us_0o5__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_6o0
        sSurferUs0O5Surftimeconst6O0Step = std::make_shared<SurferUs0O5Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst6O0Step);
        surfer__us_0o5__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_7o0
        sSurferUs0O5Surftimeconst7O0Step = std::make_shared<SurferUs0O5Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst7O0Step);
        surfer__us_0o5__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_8o0
        sSurferUs0O5Surftimeconst8O0Step = std::make_shared<SurferUs0O5Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst8O0Step);
        surfer__us_0o5__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_9o0
        sSurferUs0O5Surftimeconst9O0Step = std::make_shared<SurferUs0O5Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst9O0Step);
        surfer__us_0o5__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_0o5__surftimeconst_10o0
        sSurferUs0O5Surftimeconst10O0Step = std::make_shared<SurferUs0O5Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs0O5Surftimeconst10O0Step);
        surfer__us_0o5__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_0o0
        sSurferUs10O0Surftimeconst0O0Step = std::make_shared<SurferUs10O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst0O0Step);
        surfer__us_10o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_2o0
        sSurferUs10O0Surftimeconst2O0Step = std::make_shared<SurferUs10O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst2O0Step);
        surfer__us_10o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_3o0
        sSurferUs10O0Surftimeconst3O0Step = std::make_shared<SurferUs10O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst3O0Step);
        surfer__us_10o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_4o0
        sSurferUs10O0Surftimeconst4O0Step = std::make_shared<SurferUs10O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst4O0Step);
        surfer__us_10o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_5o0
        sSurferUs10O0Surftimeconst5O0Step = std::make_shared<SurferUs10O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst5O0Step);
        surfer__us_10o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_6o0
        sSurferUs10O0Surftimeconst6O0Step = std::make_shared<SurferUs10O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst6O0Step);
        surfer__us_10o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_7o0
        sSurferUs10O0Surftimeconst7O0Step = std::make_shared<SurferUs10O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst7O0Step);
        surfer__us_10o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_8o0
        sSurferUs10O0Surftimeconst8O0Step = std::make_shared<SurferUs10O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst8O0Step);
        surfer__us_10o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_9o0
        sSurferUs10O0Surftimeconst9O0Step = std::make_shared<SurferUs10O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst9O0Step);
        surfer__us_10o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_10o0__surftimeconst_10o0
        sSurferUs10O0Surftimeconst10O0Step = std::make_shared<SurferUs10O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs10O0Surftimeconst10O0Step);
        surfer__us_10o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_0o0
        sSurferUs15O0Surftimeconst0O0Step = std::make_shared<SurferUs15O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst0O0Step);
        surfer__us_15o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_2o0
        sSurferUs15O0Surftimeconst2O0Step = std::make_shared<SurferUs15O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst2O0Step);
        surfer__us_15o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_3o0
        sSurferUs15O0Surftimeconst3O0Step = std::make_shared<SurferUs15O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst3O0Step);
        surfer__us_15o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_4o0
        sSurferUs15O0Surftimeconst4O0Step = std::make_shared<SurferUs15O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst4O0Step);
        surfer__us_15o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_5o0
        sSurferUs15O0Surftimeconst5O0Step = std::make_shared<SurferUs15O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst5O0Step);
        surfer__us_15o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_6o0
        sSurferUs15O0Surftimeconst6O0Step = std::make_shared<SurferUs15O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst6O0Step);
        surfer__us_15o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_7o0
        sSurferUs15O0Surftimeconst7O0Step = std::make_shared<SurferUs15O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst7O0Step);
        surfer__us_15o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_8o0
        sSurferUs15O0Surftimeconst8O0Step = std::make_shared<SurferUs15O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst8O0Step);
        surfer__us_15o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_9o0
        sSurferUs15O0Surftimeconst9O0Step = std::make_shared<SurferUs15O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst9O0Step);
        surfer__us_15o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_15o0__surftimeconst_10o0
        sSurferUs15O0Surftimeconst10O0Step = std::make_shared<SurferUs15O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs15O0Surftimeconst10O0Step);
        surfer__us_15o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_0o0
        sSurferUs1O0Surftimeconst0O0Step = std::make_shared<SurferUs1O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst0O0Step);
        surfer__us_1o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_2o0
        sSurferUs1O0Surftimeconst2O0Step = std::make_shared<SurferUs1O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst2O0Step);
        surfer__us_1o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_3o0
        sSurferUs1O0Surftimeconst3O0Step = std::make_shared<SurferUs1O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst3O0Step);
        surfer__us_1o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_4o0
        sSurferUs1O0Surftimeconst4O0Step = std::make_shared<SurferUs1O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst4O0Step);
        surfer__us_1o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_5o0
        sSurferUs1O0Surftimeconst5O0Step = std::make_shared<SurferUs1O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst5O0Step);
        surfer__us_1o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_6o0
        sSurferUs1O0Surftimeconst6O0Step = std::make_shared<SurferUs1O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst6O0Step);
        surfer__us_1o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_7o0
        sSurferUs1O0Surftimeconst7O0Step = std::make_shared<SurferUs1O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst7O0Step);
        surfer__us_1o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_8o0
        sSurferUs1O0Surftimeconst8O0Step = std::make_shared<SurferUs1O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst8O0Step);
        surfer__us_1o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_9o0
        sSurferUs1O0Surftimeconst9O0Step = std::make_shared<SurferUs1O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst9O0Step);
        surfer__us_1o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_1o0__surftimeconst_10o0
        sSurferUs1O0Surftimeconst10O0Step = std::make_shared<SurferUs1O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O0Surftimeconst10O0Step);
        surfer__us_1o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_0o0
        sSurferUs1O5Surftimeconst0O0Step = std::make_shared<SurferUs1O5Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst0O0Step);
        surfer__us_1o5__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_2o0
        sSurferUs1O5Surftimeconst2O0Step = std::make_shared<SurferUs1O5Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst2O0Step);
        surfer__us_1o5__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_3o0
        sSurferUs1O5Surftimeconst3O0Step = std::make_shared<SurferUs1O5Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst3O0Step);
        surfer__us_1o5__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_4o0
        sSurferUs1O5Surftimeconst4O0Step = std::make_shared<SurferUs1O5Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst4O0Step);
        surfer__us_1o5__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_5o0
        sSurferUs1O5Surftimeconst5O0Step = std::make_shared<SurferUs1O5Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst5O0Step);
        surfer__us_1o5__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_6o0
        sSurferUs1O5Surftimeconst6O0Step = std::make_shared<SurferUs1O5Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst6O0Step);
        surfer__us_1o5__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_7o0
        sSurferUs1O5Surftimeconst7O0Step = std::make_shared<SurferUs1O5Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst7O0Step);
        surfer__us_1o5__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_8o0
        sSurferUs1O5Surftimeconst8O0Step = std::make_shared<SurferUs1O5Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst8O0Step);
        surfer__us_1o5__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_9o0
        sSurferUs1O5Surftimeconst9O0Step = std::make_shared<SurferUs1O5Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst9O0Step);
        surfer__us_1o5__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_1o5__surftimeconst_10o0
        sSurferUs1O5Surftimeconst10O0Step = std::make_shared<SurferUs1O5Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs1O5Surftimeconst10O0Step);
        surfer__us_1o5__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_0o0
        sSurferUs20O0Surftimeconst0O0Step = std::make_shared<SurferUs20O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst0O0Step);
        surfer__us_20o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_2o0
        sSurferUs20O0Surftimeconst2O0Step = std::make_shared<SurferUs20O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst2O0Step);
        surfer__us_20o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_3o0
        sSurferUs20O0Surftimeconst3O0Step = std::make_shared<SurferUs20O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst3O0Step);
        surfer__us_20o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_4o0
        sSurferUs20O0Surftimeconst4O0Step = std::make_shared<SurferUs20O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst4O0Step);
        surfer__us_20o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_5o0
        sSurferUs20O0Surftimeconst5O0Step = std::make_shared<SurferUs20O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst5O0Step);
        surfer__us_20o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_6o0
        sSurferUs20O0Surftimeconst6O0Step = std::make_shared<SurferUs20O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst6O0Step);
        surfer__us_20o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_7o0
        sSurferUs20O0Surftimeconst7O0Step = std::make_shared<SurferUs20O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst7O0Step);
        surfer__us_20o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_8o0
        sSurferUs20O0Surftimeconst8O0Step = std::make_shared<SurferUs20O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst8O0Step);
        surfer__us_20o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_9o0
        sSurferUs20O0Surftimeconst9O0Step = std::make_shared<SurferUs20O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst9O0Step);
        surfer__us_20o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_20o0__surftimeconst_10o0
        sSurferUs20O0Surftimeconst10O0Step = std::make_shared<SurferUs20O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs20O0Surftimeconst10O0Step);
        surfer__us_20o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_0o0
        sSurferUs2O0Surftimeconst0O0Step = std::make_shared<SurferUs2O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst0O0Step);
        surfer__us_2o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_2o0
        sSurferUs2O0Surftimeconst2O0Step = std::make_shared<SurferUs2O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst2O0Step);
        surfer__us_2o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_3o0
        sSurferUs2O0Surftimeconst3O0Step = std::make_shared<SurferUs2O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst3O0Step);
        surfer__us_2o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_4o0
        sSurferUs2O0Surftimeconst4O0Step = std::make_shared<SurferUs2O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst4O0Step);
        surfer__us_2o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_5o0
        sSurferUs2O0Surftimeconst5O0Step = std::make_shared<SurferUs2O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst5O0Step);
        surfer__us_2o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_6o0
        sSurferUs2O0Surftimeconst6O0Step = std::make_shared<SurferUs2O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst6O0Step);
        surfer__us_2o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_7o0
        sSurferUs2O0Surftimeconst7O0Step = std::make_shared<SurferUs2O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst7O0Step);
        surfer__us_2o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_8o0
        sSurferUs2O0Surftimeconst8O0Step = std::make_shared<SurferUs2O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst8O0Step);
        surfer__us_2o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_9o0
        sSurferUs2O0Surftimeconst9O0Step = std::make_shared<SurferUs2O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst9O0Step);
        surfer__us_2o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_2o0__surftimeconst_10o0
        sSurferUs2O0Surftimeconst10O0Step = std::make_shared<SurferUs2O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O0Surftimeconst10O0Step);
        surfer__us_2o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_0o0
        sSurferUs2O5Surftimeconst0O0Step = std::make_shared<SurferUs2O5Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst0O0Step);
        surfer__us_2o5__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_2o0
        sSurferUs2O5Surftimeconst2O0Step = std::make_shared<SurferUs2O5Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst2O0Step);
        surfer__us_2o5__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_3o0
        sSurferUs2O5Surftimeconst3O0Step = std::make_shared<SurferUs2O5Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst3O0Step);
        surfer__us_2o5__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_4o0
        sSurferUs2O5Surftimeconst4O0Step = std::make_shared<SurferUs2O5Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst4O0Step);
        surfer__us_2o5__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_5o0
        sSurferUs2O5Surftimeconst5O0Step = std::make_shared<SurferUs2O5Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst5O0Step);
        surfer__us_2o5__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_6o0
        sSurferUs2O5Surftimeconst6O0Step = std::make_shared<SurferUs2O5Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst6O0Step);
        surfer__us_2o5__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_7o0
        sSurferUs2O5Surftimeconst7O0Step = std::make_shared<SurferUs2O5Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst7O0Step);
        surfer__us_2o5__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_8o0
        sSurferUs2O5Surftimeconst8O0Step = std::make_shared<SurferUs2O5Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst8O0Step);
        surfer__us_2o5__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_9o0
        sSurferUs2O5Surftimeconst9O0Step = std::make_shared<SurferUs2O5Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst9O0Step);
        surfer__us_2o5__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_2o5__surftimeconst_10o0
        sSurferUs2O5Surftimeconst10O0Step = std::make_shared<SurferUs2O5Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs2O5Surftimeconst10O0Step);
        surfer__us_2o5__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_0o0
        sSurferUs3O0Surftimeconst0O0Step = std::make_shared<SurferUs3O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst0O0Step);
        surfer__us_3o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_2o0
        sSurferUs3O0Surftimeconst2O0Step = std::make_shared<SurferUs3O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst2O0Step);
        surfer__us_3o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_3o0
        sSurferUs3O0Surftimeconst3O0Step = std::make_shared<SurferUs3O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst3O0Step);
        surfer__us_3o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_4o0
        sSurferUs3O0Surftimeconst4O0Step = std::make_shared<SurferUs3O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst4O0Step);
        surfer__us_3o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_5o0
        sSurferUs3O0Surftimeconst5O0Step = std::make_shared<SurferUs3O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst5O0Step);
        surfer__us_3o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_6o0
        sSurferUs3O0Surftimeconst6O0Step = std::make_shared<SurferUs3O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst6O0Step);
        surfer__us_3o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_7o0
        sSurferUs3O0Surftimeconst7O0Step = std::make_shared<SurferUs3O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst7O0Step);
        surfer__us_3o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_8o0
        sSurferUs3O0Surftimeconst8O0Step = std::make_shared<SurferUs3O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst8O0Step);
        surfer__us_3o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_9o0
        sSurferUs3O0Surftimeconst9O0Step = std::make_shared<SurferUs3O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst9O0Step);
        surfer__us_3o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_3o0__surftimeconst_10o0
        sSurferUs3O0Surftimeconst10O0Step = std::make_shared<SurferUs3O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O0Surftimeconst10O0Step);
        surfer__us_3o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_0o0
        sSurferUs3O5Surftimeconst0O0Step = std::make_shared<SurferUs3O5Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst0O0Step);
        surfer__us_3o5__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_2o0
        sSurferUs3O5Surftimeconst2O0Step = std::make_shared<SurferUs3O5Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst2O0Step);
        surfer__us_3o5__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_3o0
        sSurferUs3O5Surftimeconst3O0Step = std::make_shared<SurferUs3O5Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst3O0Step);
        surfer__us_3o5__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_4o0
        sSurferUs3O5Surftimeconst4O0Step = std::make_shared<SurferUs3O5Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst4O0Step);
        surfer__us_3o5__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_5o0
        sSurferUs3O5Surftimeconst5O0Step = std::make_shared<SurferUs3O5Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst5O0Step);
        surfer__us_3o5__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_6o0
        sSurferUs3O5Surftimeconst6O0Step = std::make_shared<SurferUs3O5Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst6O0Step);
        surfer__us_3o5__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_7o0
        sSurferUs3O5Surftimeconst7O0Step = std::make_shared<SurferUs3O5Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst7O0Step);
        surfer__us_3o5__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_8o0
        sSurferUs3O5Surftimeconst8O0Step = std::make_shared<SurferUs3O5Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst8O0Step);
        surfer__us_3o5__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_9o0
        sSurferUs3O5Surftimeconst9O0Step = std::make_shared<SurferUs3O5Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst9O0Step);
        surfer__us_3o5__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_3o5__surftimeconst_10o0
        sSurferUs3O5Surftimeconst10O0Step = std::make_shared<SurferUs3O5Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs3O5Surftimeconst10O0Step);
        surfer__us_3o5__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_0o0
        sSurferUs4O0Surftimeconst0O0Step = std::make_shared<SurferUs4O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst0O0Step);
        surfer__us_4o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_2o0
        sSurferUs4O0Surftimeconst2O0Step = std::make_shared<SurferUs4O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst2O0Step);
        surfer__us_4o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_3o0
        sSurferUs4O0Surftimeconst3O0Step = std::make_shared<SurferUs4O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst3O0Step);
        surfer__us_4o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_4o0
        sSurferUs4O0Surftimeconst4O0Step = std::make_shared<SurferUs4O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst4O0Step);
        surfer__us_4o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_5o0
        sSurferUs4O0Surftimeconst5O0Step = std::make_shared<SurferUs4O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst5O0Step);
        surfer__us_4o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_6o0
        sSurferUs4O0Surftimeconst6O0Step = std::make_shared<SurferUs4O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst6O0Step);
        surfer__us_4o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_7o0
        sSurferUs4O0Surftimeconst7O0Step = std::make_shared<SurferUs4O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst7O0Step);
        surfer__us_4o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_8o0
        sSurferUs4O0Surftimeconst8O0Step = std::make_shared<SurferUs4O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst8O0Step);
        surfer__us_4o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_9o0
        sSurferUs4O0Surftimeconst9O0Step = std::make_shared<SurferUs4O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst9O0Step);
        surfer__us_4o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_4o0__surftimeconst_10o0
        sSurferUs4O0Surftimeconst10O0Step = std::make_shared<SurferUs4O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O0Surftimeconst10O0Step);
        surfer__us_4o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_0o0
        sSurferUs4O5Surftimeconst0O0Step = std::make_shared<SurferUs4O5Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst0O0Step);
        surfer__us_4o5__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_2o0
        sSurferUs4O5Surftimeconst2O0Step = std::make_shared<SurferUs4O5Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst2O0Step);
        surfer__us_4o5__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_3o0
        sSurferUs4O5Surftimeconst3O0Step = std::make_shared<SurferUs4O5Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst3O0Step);
        surfer__us_4o5__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_4o0
        sSurferUs4O5Surftimeconst4O0Step = std::make_shared<SurferUs4O5Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst4O0Step);
        surfer__us_4o5__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_5o0
        sSurferUs4O5Surftimeconst5O0Step = std::make_shared<SurferUs4O5Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst5O0Step);
        surfer__us_4o5__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_6o0
        sSurferUs4O5Surftimeconst6O0Step = std::make_shared<SurferUs4O5Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst6O0Step);
        surfer__us_4o5__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_7o0
        sSurferUs4O5Surftimeconst7O0Step = std::make_shared<SurferUs4O5Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst7O0Step);
        surfer__us_4o5__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_8o0
        sSurferUs4O5Surftimeconst8O0Step = std::make_shared<SurferUs4O5Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst8O0Step);
        surfer__us_4o5__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_9o0
        sSurferUs4O5Surftimeconst9O0Step = std::make_shared<SurferUs4O5Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst9O0Step);
        surfer__us_4o5__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_4o5__surftimeconst_10o0
        sSurferUs4O5Surftimeconst10O0Step = std::make_shared<SurferUs4O5Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs4O5Surftimeconst10O0Step);
        surfer__us_4o5__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_0o0
        sSurferUs5O0Surftimeconst0O0Step = std::make_shared<SurferUs5O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst0O0Step);
        surfer__us_5o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_2o0
        sSurferUs5O0Surftimeconst2O0Step = std::make_shared<SurferUs5O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst2O0Step);
        surfer__us_5o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_3o0
        sSurferUs5O0Surftimeconst3O0Step = std::make_shared<SurferUs5O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst3O0Step);
        surfer__us_5o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_4o0
        sSurferUs5O0Surftimeconst4O0Step = std::make_shared<SurferUs5O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst4O0Step);
        surfer__us_5o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_5o0
        sSurferUs5O0Surftimeconst5O0Step = std::make_shared<SurferUs5O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst5O0Step);
        surfer__us_5o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_6o0
        sSurferUs5O0Surftimeconst6O0Step = std::make_shared<SurferUs5O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst6O0Step);
        surfer__us_5o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_7o0
        sSurferUs5O0Surftimeconst7O0Step = std::make_shared<SurferUs5O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst7O0Step);
        surfer__us_5o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_8o0
        sSurferUs5O0Surftimeconst8O0Step = std::make_shared<SurferUs5O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst8O0Step);
        surfer__us_5o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_9o0
        sSurferUs5O0Surftimeconst9O0Step = std::make_shared<SurferUs5O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst9O0Step);
        surfer__us_5o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_5o0__surftimeconst_10o0
        sSurferUs5O0Surftimeconst10O0Step = std::make_shared<SurferUs5O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs5O0Surftimeconst10O0Step);
        surfer__us_5o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_0o0
        sSurferUs6O0Surftimeconst0O0Step = std::make_shared<SurferUs6O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst0O0Step);
        surfer__us_6o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_2o0
        sSurferUs6O0Surftimeconst2O0Step = std::make_shared<SurferUs6O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst2O0Step);
        surfer__us_6o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_3o0
        sSurferUs6O0Surftimeconst3O0Step = std::make_shared<SurferUs6O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst3O0Step);
        surfer__us_6o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_4o0
        sSurferUs6O0Surftimeconst4O0Step = std::make_shared<SurferUs6O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst4O0Step);
        surfer__us_6o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_5o0
        sSurferUs6O0Surftimeconst5O0Step = std::make_shared<SurferUs6O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst5O0Step);
        surfer__us_6o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_6o0
        sSurferUs6O0Surftimeconst6O0Step = std::make_shared<SurferUs6O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst6O0Step);
        surfer__us_6o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_7o0
        sSurferUs6O0Surftimeconst7O0Step = std::make_shared<SurferUs6O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst7O0Step);
        surfer__us_6o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_8o0
        sSurferUs6O0Surftimeconst8O0Step = std::make_shared<SurferUs6O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst8O0Step);
        surfer__us_6o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_9o0
        sSurferUs6O0Surftimeconst9O0Step = std::make_shared<SurferUs6O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst9O0Step);
        surfer__us_6o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_6o0__surftimeconst_10o0
        sSurferUs6O0Surftimeconst10O0Step = std::make_shared<SurferUs6O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs6O0Surftimeconst10O0Step);
        surfer__us_6o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_0o0
        sSurferUs7O0Surftimeconst0O0Step = std::make_shared<SurferUs7O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst0O0Step);
        surfer__us_7o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_2o0
        sSurferUs7O0Surftimeconst2O0Step = std::make_shared<SurferUs7O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst2O0Step);
        surfer__us_7o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_3o0
        sSurferUs7O0Surftimeconst3O0Step = std::make_shared<SurferUs7O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst3O0Step);
        surfer__us_7o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_4o0
        sSurferUs7O0Surftimeconst4O0Step = std::make_shared<SurferUs7O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst4O0Step);
        surfer__us_7o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_5o0
        sSurferUs7O0Surftimeconst5O0Step = std::make_shared<SurferUs7O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst5O0Step);
        surfer__us_7o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_6o0
        sSurferUs7O0Surftimeconst6O0Step = std::make_shared<SurferUs7O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst6O0Step);
        surfer__us_7o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_7o0
        sSurferUs7O0Surftimeconst7O0Step = std::make_shared<SurferUs7O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst7O0Step);
        surfer__us_7o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_8o0
        sSurferUs7O0Surftimeconst8O0Step = std::make_shared<SurferUs7O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst8O0Step);
        surfer__us_7o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_9o0
        sSurferUs7O0Surftimeconst9O0Step = std::make_shared<SurferUs7O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst9O0Step);
        surfer__us_7o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_7o0__surftimeconst_10o0
        sSurferUs7O0Surftimeconst10O0Step = std::make_shared<SurferUs7O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs7O0Surftimeconst10O0Step);
        surfer__us_7o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_0o0
        sSurferUs8O0Surftimeconst0O0Step = std::make_shared<SurferUs8O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst0O0Step);
        surfer__us_8o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_2o0
        sSurferUs8O0Surftimeconst2O0Step = std::make_shared<SurferUs8O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst2O0Step);
        surfer__us_8o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_3o0
        sSurferUs8O0Surftimeconst3O0Step = std::make_shared<SurferUs8O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst3O0Step);
        surfer__us_8o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_4o0
        sSurferUs8O0Surftimeconst4O0Step = std::make_shared<SurferUs8O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst4O0Step);
        surfer__us_8o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_5o0
        sSurferUs8O0Surftimeconst5O0Step = std::make_shared<SurferUs8O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst5O0Step);
        surfer__us_8o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_6o0
        sSurferUs8O0Surftimeconst6O0Step = std::make_shared<SurferUs8O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst6O0Step);
        surfer__us_8o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_7o0
        sSurferUs8O0Surftimeconst7O0Step = std::make_shared<SurferUs8O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst7O0Step);
        surfer__us_8o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_8o0
        sSurferUs8O0Surftimeconst8O0Step = std::make_shared<SurferUs8O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst8O0Step);
        surfer__us_8o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_9o0
        sSurferUs8O0Surftimeconst9O0Step = std::make_shared<SurferUs8O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst9O0Step);
        surfer__us_8o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_8o0__surftimeconst_10o0
        sSurferUs8O0Surftimeconst10O0Step = std::make_shared<SurferUs8O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs8O0Surftimeconst10O0Step);
        surfer__us_8o0__surftimeconst_10o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_0o0
        sSurferUs9O0Surftimeconst0O0Step = std::make_shared<SurferUs9O0Surftimeconst0O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst0O0Step);
        surfer__us_9o0__surftimeconst_0o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_2o0
        sSurferUs9O0Surftimeconst2O0Step = std::make_shared<SurferUs9O0Surftimeconst2O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst2O0Step);
        surfer__us_9o0__surftimeconst_2o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_3o0
        sSurferUs9O0Surftimeconst3O0Step = std::make_shared<SurferUs9O0Surftimeconst3O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst3O0Step);
        surfer__us_9o0__surftimeconst_3o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_4o0
        sSurferUs9O0Surftimeconst4O0Step = std::make_shared<SurferUs9O0Surftimeconst4O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst4O0Step);
        surfer__us_9o0__surftimeconst_4o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_5o0
        sSurferUs9O0Surftimeconst5O0Step = std::make_shared<SurferUs9O0Surftimeconst5O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst5O0Step);
        surfer__us_9o0__surftimeconst_5o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_6o0
        sSurferUs9O0Surftimeconst6O0Step = std::make_shared<SurferUs9O0Surftimeconst6O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst6O0Step);
        surfer__us_9o0__surftimeconst_6o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_7o0
        sSurferUs9O0Surftimeconst7O0Step = std::make_shared<SurferUs9O0Surftimeconst7O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst7O0Step);
        surfer__us_9o0__surftimeconst_7o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_8o0
        sSurferUs9O0Surftimeconst8O0Step = std::make_shared<SurferUs9O0Surftimeconst8O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst8O0Step);
        surfer__us_9o0__surftimeconst_8o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_9o0
        sSurferUs9O0Surftimeconst9O0Step = std::make_shared<SurferUs9O0Surftimeconst9O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst9O0Step);
        surfer__us_9o0__surftimeconst_9o0Index = data.size() - 1;
        // // surfer__us_9o0__surftimeconst_10o0
        sSurferUs9O0Surftimeconst10O0Step = std::make_shared<SurferUs9O0Surftimeconst10O0Step>(sFlow, pObjects);
        data.push_back(sSurferUs9O0Surftimeconst10O0Step);
        surfer__us_9o0__surftimeconst_10o0Index = data.size() - 1;
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
