#ifndef SPACE_H
#define SPACE_H
#pragma once

#include <iostream>
#include <limits>
#include <map>
#include <vector>
#include <cmath> // round

// Source : https://en.wikipedia.org/wiki/Space_partitioning
// Source : https://en.wikipedia.org/wiki/Bin_(computational_geometry)
namespace sp0ce {

template<unsigned int _Dim> // Object type, Position type
class Bin {
	public:
		static const unsigned int Dim = _Dim;
	public:
		Bin(const double p_step) : step(p_step) {
			
		}
	public:
		virtual void addIndex(const double* pPosition, const unsigned int index) {
			// compute ijk
			std::array<int, Dim> ijk = positionToIjk(pPosition);
			// update data
			auto itIjkToIndexes = ijkToIndexes.find(ijk);
			if(itIjkToIndexes != ijkToIndexes.end()) {
				itIjkToIndexes->second.push_back(index);
			} else {
				ijkToIndexes.emplace(ijk, { index });
			}
			indexToIjk.emplace(index, ijk);
		}

		virtual void addIndexes(const double* pPosition, const unsigned int* pIndexes, const unsigned int number) {
			// compute ijk
			std::array<int, Dim> ijk = positionToIjk(pPosition);
			// update data
			auto itIjkToIndexes = ijkToIndexes.find(ijk);
			if(itIjkToIndexes != ijkToIndexes.end()) {
				itIjkToIndexes->second.push_back(index); // TODO: replace by indexes
			} else {
				ijkToIndexes.emplace(ijk, { index }); // TODO: replace by indexes
			}
			indexToIjk.emplace(index, ijk);
		}

		std::array<int, Dim> positionToIjk(const double* pPosition) const {
			std::array<int, Dim> ijk;
			for(std::size_t i = 0; i < Dim; ++i) {
				ijk[i] = int(std::round(pPosition[i]/step));
			}
			return ijk;
		}

		std::array<double, Dim> ijkToPosition(const int* pIjk) const {
			std::array<double, Dim> output;
			for(unsigned int i = 0; i < Dim; ++i) {
				output[i] = pIjk[i] * step;
			}
			return output;
		}

		std::vector<std::array<int, Dim>> ijkToNeighborIjk(const int* pIjk) const {
			std::vector<std::array<int, Dim>> output;
			ijkToNeighborIjkAuxiliary(pIjk, 0, output);
			return output;
		}

		void clear() {
			ijkToIndexes.clear();
			indexToIjk.clear();
		}

	public:
		virtual void ijkToNeighborIjkAuxiliary(const int* pIjk, const unsigned int i, std::vector<std::array<int, Dim>>& output) const {
			for(int j = -1; j < 1; ++j) {
				// newIjk
				std::array<int, Dim> newIjk;
				for(unsigned int k = 0; k < Dim; ++k) {
					newIjk[k] = pIjk[k];
				}
				newIjk[i] += j;
				// output
				if(i == Dim) {
					output.push_back(newIjk);
				} else {
					ijkToNeighborIjkAuxiliary(newIjk.data(), i + 1, output);
				}
			}
		}

	public:
		const double step;
		std::map<
			std::array<int, Dim>, 
			std::vector<unsigned int>
		> ijkToIndexes;
		std::map<
			unsigned int,
			std::array<int, Dim>
		> indexToIjk;
};

template<unsigned int _Dim, double _Step> // Object type, Position type
class BinTree {
	public:
		static const unsigned int Dim = _Dim;
		static constexpr double Step = _Step;
	public:
		BinTree() {
			data.emplace_back(Step);
		}
	public:
		void addIndex(const double* pPosition, const unsigned int index) {
			// add in data
			for(unsigned int i = 0; i < data.size(); ++i) {
				data[i].addIndex(pPosition, index);
			}
			// push_back data
			while(data.back().ijkToIndexes.size() > 1) {
				data.emplace_back(2 * data.back().step);
				for() { // TODO: iterate over map (data.end() - 2).ijkToIndexes
					// TODO: add indexes to position
				}
			}
		}
	public:
		std::vector<Bin<Dim>> data;
};


// 	template<class O, class V> // Object type, Position type
// 	class BinPeriodic : public Bin<O, V> {
// 		public:
// 			BinPeriodic();
// 			BinPeriodic(const V& d, const V& l);
// 			void add(const O& object, const V& x) override;
// 			std::vector<std::vector<int>> getIjkNeighbours(const std::vector<int>& ijk) const override;
// 		public:
// 			V l;
// 			using Bin<O, V>::d;
// 			using Bin<O, V>::data;
// 			using Bin<O, V>::index;
// 	};
// 
// 	template<class O, class V>
// 	BinPeriodic<O, V>::BinPeriodic() { // TODO should be a default argument more than a defualt constructor
// 	}
// 	
// 	template<class O, class V>
// 	BinPeriodic<O, V>::BinPeriodic(const V& p_d, const V& p_l) : Bin<O, V>(p_d), l(p_l) {
// 	
// 	}
// 
// 	template<class O, class V>
// 	void BinPeriodic<O, V>::add(const O& object, const V& x) {
// 		V xPeriodic = x;
// 		for(std::size_t i = 0; i < d.size(); i++) {
// 			xPeriodic[i] = std::fmod(0.5 * l[i] + xPeriodic[i], l[i]);
// 			if (xPeriodic[i] < 0.0)
// 			   xPeriodic[i] += l[i];
// 			xPeriodic[i] -= 0.5 * l[i];
// 		}
// 		Bin<O, V>::add(object, xPeriodic);
// 	}
// 	
// 	template<class O, class V>
// 	std::vector<std::vector<int>> BinPeriodic<O, V>::getIjkNeighbours(const std::vector<int>& ijk) const {
// 		const int n = l[l.size() - ijk.size()]/d[d.size() - ijk.size()];
// 		if(ijk.size() == 1) {
// 			std::vector<std::vector<int>> abc(3, std::vector<int>(1));
// 			for(int i = -1; i <= 1; i++) {
// 				abc[i+1][0] = (n/2 + ijk.front()+i) % n;
// 				if(abc[i+1][0] < 0)
// 					abc[i+1][0] += n;
// 				abc[i+1][0] -= n/2;
// 			}
// 			return abc;
// 		} else {
// 			std::vector<std::vector<int>> abc;
// 			std::vector<std::vector<int>> recAbc = getIjkNeighbours(std::vector<int>(ijk.begin() + 1, ijk.end()));
// 			for(int i = -1; i <= 1; i++) {
// 				for(std::size_t j = 0; j < recAbc.size(); j++) {
// 					abc.push_back(recAbc[j]);
// 					abc[abc.size()-1].insert(abc[abc.size()-1].begin(), (n/2 + ijk.front()+i) % n);
// 					if(abc[abc.size()-1][0] < 0)
// 						abc[abc.size()-1][0] += n;
// 					abc[abc.size()-1][0] -= n/2;
// 				}
// 			}
// 			return abc;
// 		}
// 	}
};

#endif
