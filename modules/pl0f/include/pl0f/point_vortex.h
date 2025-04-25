#ifndef PL0F_POINT_VORTEX_H
#define PL0F_POINT_VORTEX_H
#pragma once

// std includes
#include "sp0ce/bin.h" // BinTree
#include "sp0ce/operators.h" // cross2d

namespace pl0f {

template<unsigned int _Dim, typename _tVector, typename _tMatrix, template<typename...> typename _tView>
struct PointVortexFlow {
	public:
		static const unsigned int Dim = _Dim;
		static const unsigned int VortexStateSize = Dim + 1;
	
		using tVector = _tVector;
		using tMatrix = _tMatrix;
		template<typename ...Args>
		using tView = _tView<Args...>;

	public:
		const double step;
		const double sigma;
		const tVector periodCenter;
		const tVector periodSize;
		std::array<bool, Dim> isAxisPeriodic;
		
		sp0ce::BinTree<Dim> binTree;
		// super
		std::vector<std::map<std::array<int, Dim>, unsigned int>> ijkToSuperIndex;
		std::vector<std::vector<double>> superVortexStateArray;

	public:
		PointVortexFlow(
			const double p_step, 
			const tVector p_periodCenter,
			const tVector p_periodSize,
			const std::array<bool, Dim> p_isAxisPeriodic
		) : step(p_step), sigma(p_step), binTree(p_step), periodCenter(p_periodCenter), periodSize(p_periodSize), isAxisPeriodic(p_isAxisPeriodic) {
			
		}

		PointVortexFlow(
			const double p_step
		) : step(p_step), sigma(p_step), binTree(p_step), periodCenter(tVector::Zero()), periodSize(tVector::Zero()), isAxisPeriodic({false}) {
			
		}

	public:
		void prepare(const double* pState, const unsigned int n) {
			// binTree
			binTree.clear();
			for(unsigned int index = 0; index < n; ++index) {
				const tView<const tVector> x(pState + index * VortexStateSize);
				const double& w = pState[index * VortexStateSize + Dim];
				binTree.addIndex(index, x.data());
			}
			// super
			ijkToSuperIndex.clear();
			superVortexStateArray.clear();
			// 0
			ijkToSuperIndex.emplace_back();
			superVortexStateArray.emplace_back();
			for (auto const& [ijk, indexes] : binTree.data[0].ijkToIndexes) {
				// init
				ijkToSuperIndex[0][ijk] = ijkToSuperIndex[0].size();
				superVortexStateArray[0].resize(ijkToSuperIndex[0].size() * VortexStateSize, 0.0);
				// process
				tView<tVector> superX(&(superVortexStateArray[0][superVortexStateArray[0].size() - VortexStateSize]));
				double& superW = superVortexStateArray[0].back();
				for (auto const& index : indexes) {
					const tView<const tVector> x(pState + index * VortexStateSize);
					const double w = pState[index * VortexStateSize + Dim];
					superW += w;
					superX += w * x;
				}
				if(superW != 0.0) {
					superX /= superW;
				}
			}
			// others
			for(unsigned int i = 1; i < binTree.data.size(); ++i) {
				ijkToSuperIndex.emplace_back();
				superVortexStateArray.emplace_back();
				for (auto const& [ijk, indexes] : binTree.data[i].ijkToIndexes) {
					// init
					ijkToSuperIndex[i][ijk] = ijkToSuperIndex[i].size();
					superVortexStateArray[i].resize(ijkToSuperIndex[i].size() * VortexStateSize, 0.0);
					
					// process
					tView<tVector> superX(&(superVortexStateArray[i][superVortexStateArray[i].size() - VortexStateSize]));
					double& superW = superVortexStateArray[i].back();
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
							superW += superVortexStateArray[i-1][subSuperIndex * VortexStateSize + Dim];
							superX += superVortexStateArray[i-1][subSuperIndex * VortexStateSize + Dim] * tView<const tVector>(&(superVortexStateArray[i-1][subSuperIndex * VortexStateSize]));
						}
					}
					if(superW != 0.0) {
						superX /= superW;
					}
				}
			}
		};

		tVector getVelocity(const double* pX) const {
			tVector output = tVector::Zero();
			const tVector x = sp0ce::xPeriodic<tVector>(pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			for(int i = binTree.data.size() - 1; i > -1; --i) {
				const std::array<int, Dim> ijk = binTree.data[i].positionToIjk(x.data());
				const std::vector<std::array<int, Dim>> siblingIjkArray = binTree.data[i].ijkToSiblingIjk(ijk.data());
				for(auto const& siblingIjk : siblingIjkArray) {
					if(siblingIjk != ijk) {
						auto iterator = ijkToSuperIndex[i].find(siblingIjk);
						if(iterator != ijkToSuperIndex[i].end()) {
							const unsigned int superIndex = iterator->second;
							const tView<const tVector> superX(&(superVortexStateArray[i][superIndex * VortexStateSize]));
							const double superW = superVortexStateArray[i][superIndex * VortexStateSize + Dim];

							const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
							const double rNorm = r.norm();
							if(rNorm > sigma) {
								output += sp0ce::cross2d<tVector>(superW, r.data()) * std::pow(sigma/rNorm, 2); // 2D
							} else {
								output += sp0ce::cross2d<tVector>(superW, r.data());
							}
						}
					}
					
				}
			}
			output *= 0.5; // 2D
			return output;
		};

		tMatrix getVelocityGradients(const double* pX) const {
			tMatrix output = tMatrix::Zero();
			const tVector x = sp0ce::xPeriodic<tVector>(pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			for(int i = binTree.data.size() - 1; i > -1; --i) {
				const std::array<int, Dim> ijk = binTree.data[i].positionToIjk(x.data());
				const std::vector<std::array<int, Dim>> siblingIjkArray = binTree.data[i].ijkToSiblingIjk(ijk.data());
				for(auto const& siblingIjk : siblingIjkArray) {
					if(siblingIjk != ijk) {
						auto iterator = ijkToSuperIndex[i].find(siblingIjk);
						if(iterator != ijkToSuperIndex[i].end()) {
							const unsigned int superIndex = iterator->second;
							const tView<const tVector> superX(&(superVortexStateArray[i][superIndex * VortexStateSize]));
							const double superW = superVortexStateArray[i][superIndex * VortexStateSize + Dim];

							tMatrix skewSuperW;
							skewSuperW << 0.0, superW,
							              -superW,  0.0;
							
							const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
							const double rNorm = r.norm();
							if(rNorm > sigma) {
								output += std::pow(sigma/rNorm, 4) * (sp0ce::cross2d<tVector>(superW, r.data()) * r.transpose()); // 2D
							} else {
								output += sp0ce::cross2d<tVector>(superW, r.data()) * r.transpose();
							}
						}
					}
					
				}
			}
			output *= 0.5; // 2D
			return output;
		};
};

}

#endif
