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
		const double step;
		std::map<
			std::array<int, Dim>, 
			std::vector<unsigned int>
		> ijkToIndexes;
		std::unordered_map<
			unsigned int,
			std::array<int, Dim>
		> indexToIjk;
	public:
		Bin(const double p_step) : step(p_step) {
			
		}
	public:
		void addIndex(const unsigned int index, const double* pPosition) {
			// compute ijk
			std::array<int, Dim> ijk = positionToIjk(pPosition);
			// update data
			auto itIjkToIndexes = ijkToIndexes.find(ijk);
			if(itIjkToIndexes != ijkToIndexes.end()) {
				itIjkToIndexes->second.push_back(index);
			} else {
				ijkToIndexes.emplace(ijk, std::vector<unsigned int>({ index }));
			}
			indexToIjk.emplace(index, ijk);
		}

		void clear() {
			ijkToIndexes.clear();
			indexToIjk.clear();
		}
	public:
		std::array<int, Dim> positionToIjk(const double* pPosition) const {
			std::array<int, Dim> ijk;
			for(std::size_t i = 0; i < Dim; ++i) {
				ijk[i] = int(pPosition[i]/step);
				if(pPosition[i] < 0.0) {
					ijk[i] -= 1;
				}
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
		
		void ijkToNeighborIjkAuxiliary(const int* pIjk, const unsigned int i, std::vector<std::array<int, Dim>>& output) const {
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

		std::vector<std::array<int, Dim>> ijkToSiblingIjk(const int* pIjk) const {
			std::array<int, Dim> ijkStart;
			std::array<int, Dim> ijkEnd;
			for(unsigned int j = 0; j < Dim; ++j) {
				if(pIjk[j] < 0) {
					ijkStart[j] = ((pIjk[j] - 1)/2) * 2;
					ijkEnd[j] = ((pIjk[j] - 1)/2 + 1) * 2;
				} else {
					ijkStart[j] = (pIjk[j]/2) * 2;
					ijkEnd[j] = (pIjk[j]/2 + 1) * 2;
				}
			}
			return getIjkInBetween(ijkStart.data(), ijkEnd.data());
		}

		std::vector<std::array<int, Dim>> getIjkInBetween(const int* pIjkStart, const int* pIjkEnd) const {
			std::vector<std::array<int, Dim>> output;
			getIjkInBetweenAuxiliary(pIjkStart, pIjkEnd, 0, output);
			return output;
		}

		void getIjkInBetweenAuxiliary(const int* pIjkStart, const int* pIjkEnd, const unsigned int i, std::vector<std::array<int, Dim>>& output) const {
			std::array<int, Dim> newIjk;
			for(unsigned int j = 0; j < Dim; ++j) {
				newIjk[j] = pIjkStart[j];
			}
			output.push_back(newIjk);
			// progress into graph
			for(unsigned int j = i; j < Dim; ++j) {
				std::array<int, Dim> newIjkStart = newIjk;
				newIjkStart[j] += 1;
				if(newIjkStart[j] < pIjkEnd[j]) {
					getIjkInBetweenAuxiliary(newIjkStart.data(), pIjkEnd, j, output);
				}
			}
		}
};

template<unsigned int _Dim> // Object type, Position type
class BinTree {
	public:
		static const unsigned int Dim = _Dim;
	public:
		const double step;
		std::vector<Bin<Dim>> data;
	public:
		BinTree(const double p_step) : step(p_step) {
			data.emplace_back(step);
		}
	public:
		void clear() {
			data.clear();
			data.emplace_back(step);
		}
		void addIndex(const unsigned int index, const double* pPosition) {
			// add in data
			for(unsigned int i = 0; i < data.size(); ++i) {
				data[i].addIndex(index, pPosition);
			}
			// push_back data
			while(data.back().ijkToIndexes.size() > std::pow(2, Dim)) {
				data.emplace_back(2 * data.back().step);
				for (auto const& [ijk, indexes] : (*(data.end() - 2)).ijkToIndexes) {
					std::array<int, Dim> newIjk = ijk;
					for(unsigned int i = 0; i < ijk.size(); ++i) {
						if(newIjk[i] < 0) {
							newIjk[i] = (newIjk[i] - 1) / 2;
						} else {
							newIjk[i] = newIjk[i] / 2;
						}
					}
					auto itIjkToIndexes = data.back().ijkToIndexes.find(newIjk);
					if(itIjkToIndexes != data.back().ijkToIndexes.end()) {
				    	itIjkToIndexes->second.insert(itIjkToIndexes->second.begin(), indexes.begin(), indexes.end());
				    } else {
				    	data.back().ijkToIndexes.emplace(newIjk, indexes);
				    }
				    for (auto const& _index : indexes) {
				    	data.back().indexToIjk.emplace(_index, newIjk);
				    }
				}
			}
		}
};

};

#endif
