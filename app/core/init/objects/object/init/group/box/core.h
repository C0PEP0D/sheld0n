#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_BOX_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_GROUP_BOX_CORE_H
#pragma once

// std includes
#include <execution>
#include <cmath> // ceilf, cbrtf
#include <vector>
// app includes
#include "core/init/objects/object/init/group/box/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep, template<typename> typename TypeInitInitMember>
class InitInitGroupBox : public InitInitInit<TypeObjectStep> {
    public:
        TypeParameters parameters;
    public:
        using InitInitInit<TypeObjectStep>::sObjectStep;
    public:
        InitInitGroupBox(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInit<TypeObjectStep>(p_sObjectStep) {
        }
    public:
        void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) override {
            // compute n
            const unsigned int n = int(std::ceil(std::pow(sObjectStep->memberIndexs.size(), 1.0/parameters.l.size())));
            std::vector<double> d(parameters.l.size());
            for(unsigned int i = 0; i < d.size(); i++) {
                d[i] = parameters.l[i] / (n-1);
            }
            // set member positions
            std::for_each(std::execution::seq, sObjectStep->memberIndexs.cbegin(), sObjectStep->memberIndexs.cend(), [this, state, n, d](const unsigned int& memberIndex){
                // get ijk
                unsigned int value = memberIndex;
                std::vector<unsigned int> ijk(parameters.l.size());
                for(unsigned int i = 0; i < ijk.size(); i++) {
                    const unsigned int divisor = std::pow(n, ijk.size() - i - 1);
                    ijk[i] = value / divisor;
                    value = value % divisor;
                }
                // compute and set position
                sObjectStep->sMemberStep->x(sObjectStep->memberState(state, memberIndex)) = parameters.origin;
                for(unsigned int i = 0; i < ijk.size(); i++) {
                    sObjectStep->sMemberStep->x(sObjectStep->memberState(state, memberIndex))[i] += ijk[i] * d[i];
                }
            });
        };
};

}

#endif
