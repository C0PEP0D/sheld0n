#ifndef SPACE_H
#define SPACE_H
#pragma once

#include <iostream>
#include <limits>
#include <map>
#include <vector>
#include <cmath>

// Source : https://en.wikipedia.org/wiki/Space_partitioning
// Source : https://en.wikipedia.org/wiki/Bin_(computational_geometry)
namespace space {
    template<class O, class V> // Object type, Position type
    class Bin {
        public:
            Bin();
            Bin(const V& d);
            virtual void add(const O& object, const V& x);
            std::vector<O> getNeighbours(const V& x) const;
            std::vector<std::vector<O>> getNeighbours(const std::vector<V>& x) const;
            virtual std::vector<std::vector<int>> getIjkNeighbours(const std::vector<int>& ijk) const;
            void clear();
        public:
            V d;
            std::map<std::vector<int>, std::vector<O>> data;
            std::vector<std::vector<int>> index;
    };

    template<class O, class V> // Object type, Position type
    class BinPeriodic : public Bin<O, V> {
        public:
            BinPeriodic();
            BinPeriodic(const V& d, const V& l);
            void add(const O& object, const V& x) override;
            std::vector<std::vector<int>> getIjkNeighbours(const std::vector<int>& ijk) const override;
        public:
            V l;
            using Bin<O, V>::d;
            using Bin<O, V>::data;
            using Bin<O, V>::index;
    };

    template<class O, class V>
    Bin<O, V>::Bin() { // TODO should be a default argument more than a defualt constructor
    }
    
    template<class O, class V>
    Bin<O, V>::Bin(const V& p_d) : d(p_d) {
    }

    template<class O, class V>
    void Bin<O, V>::add(const O& object, const V& x) {
        std::vector<int> ijk(d.size());
        for(std::size_t i = 0; i < d.size(); i++) {
            ijk[i] = int(x[i]/d[i]);
        }
        typename std::map<std::vector<int>, std::vector<O>>::iterator itData = data.find(ijk);
        if(itData != data.end()) {
            itData->second.push_back(object);
        } else {
            data.emplace(ijk, std::vector<O>(1, object));
            index.emplace_back(ijk);
        }
    }
    
    template<class O, class V>
    std::vector<O> Bin<O, V>::getNeighbours(const V& x) const {
        std::vector<O> neighbours;
        std::vector<int> ijk0(d.size());
        for(std::size_t i = 0; i < d.size(); i++) {
            ijk0[i] = int(x[i]/d[i]);
        }
        std::vector<std::vector<int>> ijkNeighbours = getIjkNeighbours(ijk0);
        // Adds the data of the ijk neighbours cells to the neighbours vector
        for(const std::vector<int>& ijk : ijkNeighbours) {
            auto itData = data.find(ijk);
            if(itData != data.end())
                neighbours.insert(neighbours.end(), itData->second.begin(), itData->second.end());
        }
        // Return the neighbours
        return neighbours;
    }

    template<class O, class V>
    std::vector<std::vector<O>> Bin<O, V>::getNeighbours(const std::vector<V>& x) const {
        std::vector<std::vector<O>> neighbours(x.size());
        for(std::size_t i = 0; i < x.size(); i++) { // TODO, STL algorithm
            neighbours[i] = getNeighbours(x[i]);
        }
        // Return the neighbours
        return neighbours;
    }

    template<class O, class V>
    std::vector<std::vector<int>> Bin<O, V>::getIjkNeighbours(const std::vector<int>& ijk) const {
        if(ijk.size() == 1) {
            std::vector<std::vector<int>> abc(3, std::vector<int>(1));
            for(int i = -1; i <= 1; i++) {
                abc[i+1][0] = ijk[0]+i;
            }
            return abc;
        } else {
            std::vector<std::vector<int>> abc;
            std::vector<std::vector<int>> recAbc = getIjkNeighbours(std::vector<int>(ijk.begin() + 1, ijk.end()));
            for(int i = -1; i <= 1; i++) {
                for(std::size_t j = 0; j < recAbc.size(); j++) {
                    abc.push_back(recAbc[j]);
                    abc[abc.size()-1].insert(abc[abc.size()-1].begin(), ijk[0]+i);
                }
            }
            return abc;
        }
    }
    
    template<class O, class V>
    void Bin<O, V>::clear() {
        data.clear();
        index.clear();
    }
    
    template<class O, class V>
    BinPeriodic<O, V>::BinPeriodic() { // TODO should be a default argument more than a defualt constructor
    }
    
    template<class O, class V>
    BinPeriodic<O, V>::BinPeriodic(const V& p_d, const V& p_l) : Bin<O, V>(p_d), l(p_l) {
    
    }

    template<class O, class V>
    void BinPeriodic<O, V>::add(const O& object, const V& x) {
        V xPeriodic = x;
        for(std::size_t i = 0; i < d.size(); i++) {
            xPeriodic[i] = std::fmod(0.5 * l[i] + xPeriodic[i], l[i]);
            if (xPeriodic[i] < 0.0)
               xPeriodic[i] += l[i];
            xPeriodic[i] -= 0.5 * l[i];
        }
        Bin<O, V>::add(object, xPeriodic);
    }
    
    template<class O, class V>
    std::vector<std::vector<int>> BinPeriodic<O, V>::getIjkNeighbours(const std::vector<int>& ijk) const {
        const int n = l[l.size() - ijk.size()]/d[d.size() - ijk.size()];
        if(ijk.size() == 1) {
            std::vector<std::vector<int>> abc(3, std::vector<int>(1));
            for(int i = -1; i <= 1; i++) {
                abc[i+1][0] = (n/2 + ijk.front()+i) % n;
                if(abc[i+1][0] < 0)
                    abc[i+1][0] += n;
                abc[i+1][0] -= n/2;
            }
            return abc;
        } else {
            std::vector<std::vector<int>> abc;
            std::vector<std::vector<int>> recAbc = getIjkNeighbours(std::vector<int>(ijk.begin() + 1, ijk.end()));
            for(int i = -1; i <= 1; i++) {
                for(std::size_t j = 0; j < recAbc.size(); j++) {
                    abc.push_back(recAbc[j]);
                    abc[abc.size()-1].insert(abc[abc.size()-1].begin(), (n/2 + ijk.front()+i) % n);
                    if(abc[abc.size()-1][0] < 0)
                        abc[abc.size()-1][0] += n;
                    abc[abc.size()-1][0] -= n/2;
                }
            }
            return abc;
        }
    }
};

#endif
