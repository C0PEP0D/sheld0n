#ifndef D0T_VARIABLE_H
#define D0T_VARIABLE_H
#pragma once

// std includes
#include "sp0ce/bin.h" // BinTree
#include "sp0ce/operators.h" // cross2d

namespace pl0f {

template<unsigned int Dim, typename tVector, typename tMatrix, template<typename...> typename tView>
struct PointVortexFlow {

	public:
		const double step;
		const double sigma;
		
		sp0ce::BinTree<Dim> binTree;

		// super
		std::vector<std::map<std::array<int, Dim>, unsigned int>> ijkToSuperIndex;
		std::vector<std::vector<double>> superPositionArray;
		std::vector<std::vector<double>> superVorticityArray;

	public:
		PointVortexFlow(const double p_step) : step(p_step), sigma(p_step), binTree(p_step) {
			
		}
	
		void prepare(const double* pPosition, const double* pVorticity, const unsigned int n) {
			binTree.clear();
			for(unsigned int index = 0; index < n; ++index) {
				binTree.addIndex(index, &(pPosition[index * Dim]));
			}
			// super
			ijkToSuperIndex.clear();
			superPositionArray.clear();
			superVorticityArray.clear();
			// 0
			ijkToSuperIndex.emplace_back();
			superPositionArray.emplace_back();
			superVorticityArray.emplace_back();
			for (auto const& [ijk, indexes] : binTree.data[0].ijkToIndexes) {
				// init
				ijkToSuperIndex[0][ijk] = superVorticityArray[0].size();
				superVorticityArray[0].push_back(0.0);
				superPositionArray[0].resize(superVorticityArray[0].size() * Dim, 0.0);
				// process
				tView<tVector> superPosition(&(superPositionArray[0][superPositionArray[0].size() - Dim]));
				for (auto const& index : indexes) {
					superVorticityArray[0].back() += pVorticity[index];
					superPosition += pVorticity[index] * tView<const tVector>(&(pPosition[index]));
				}
				if(superVorticityArray[0].back() != 0.0) {
					superPosition /= superVorticityArray[0].back();
				}
			}
			// others
			for(unsigned int i = 1; i < binTree.data.size(); ++i) {
				ijkToSuperIndex.emplace_back();
				superPositionArray.emplace_back();
				superVorticityArray.emplace_back();
				for (auto const& [ijk, indexes] : binTree.data[i].ijkToIndexes) {
					// init
					ijkToSuperIndex[i][ijk] = superVorticityArray[i].size();
					superVorticityArray[i].push_back(0.0);
					superPositionArray[i].resize(superVorticityArray[i].size() * Dim, 0.0);
					// process
					tView<tVector> superPosition(&(superPositionArray[i][superPositionArray[i].size() - Dim]));
					// sub
					std::array<int, Dim> subIjkStart;
					std::array<int, Dim> subIjkEnd;
					for(unsigned int j = 0; j < Dim; ++j) {
						subIjkStart[j] = ijk[j] * 2;
						subIjkEnd[j] = (ijk[j] + 1) * 2;
					}
					for (auto const& subIjk : binTree.data[i-1].getIjkInBetween(subIjkStart.data(), subIjkEnd.data())) {
						auto iterator = ijkToSuperIndex[i-1].find(subIjk);
						if(iterator != ijkToSuperIndex[i-1].end()) {
							const unsigned int subSuperIndex = iterator->second;
							superVorticityArray[i].back() += superVorticityArray[i-1][subSuperIndex];
							superPosition += superVorticityArray[i-1][subSuperIndex] * tView<const tVector>(&(superPositionArray[i-1][subSuperIndex * Dim]));
						}
					}
					if(superVorticityArray[i].back() != 0.0) {
						superPosition /= superVorticityArray[i].back();
					}
				}
			}
		};

		tVector getVelocity(const double* pX) const {
			tVector output = tVector::Zero();
			const tView<const tVector> x(pX);
			for(int i = binTree.data.size() - 1; i > -1; --i) {
				const std::array<int, Dim> ijk = binTree.data[i].positionToIjk(pX);
				const std::vector<std::array<int, Dim>> siblingIjkArray = binTree.data[i].ijkToSiblingIjk(ijk.data());
				for(auto const& siblingIjk : siblingIjkArray) {
					if(siblingIjk != ijk) {
						auto iterator = ijkToSuperIndex[i].find(siblingIjk);
						if(iterator != ijkToSuperIndex[i].end()) {
							const unsigned int siblingIndex = iterator->second;
							const tVector r = x - tView<const tVector>(&(superPositionArray[i][siblingIndex * Dim]));
							const double rNorm = r.norm();
							if(rNorm > sigma) {
								output += sp0ce::cross2d<tVector>(superVorticityArray[i][siblingIndex], r.data()) * std::pow(sigma/rNorm, 2); // 2D
							} else {
								output += sp0ce::cross2d<tVector>(superVorticityArray[i][siblingIndex], r.data());
							}
						}
					}
					
				}
			}
			output *= 0.5; // 2D
			return output;
		};

		tMatrix getVelocityGradients(const double* pX, const double t) const {
			return tMatrix::Zero;
		};
};

}

#endif
