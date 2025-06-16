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
		const double dx;
		const double sigma;
		const tVector meanVelocity;
		
		const tVector periodCenter;
		const tVector periodSize;
		std::array<bool, Dim> isAxisPeriodic;
		
		sp0ce::BinTree<Dim> binTree;
		// super
		std::vector<std::map<std::array<int, Dim>, unsigned int>> ijkToSuperIndex;
		std::vector<std::vector<double>> superVortexStateArray;

	public:
		PointVortexFlow(
			const double p_dx,
			const tVector p_meanVelocity,
			const tVector p_periodCenter,
			const tVector p_periodSize,
			const std::array<bool, Dim> p_isAxisPeriodic
		) : dx(p_dx), sigma(p_dx), meanVelocity(p_meanVelocity), binTree(p_dx), periodCenter(p_periodCenter), periodSize(p_periodSize), isAxisPeriodic(p_isAxisPeriodic) {
			
		}

		PointVortexFlow(
			const double p_dx,
			const tVector p_meanVelocity
		) : PointVortexFlow(p_dx, p_meanVelocity, tVector::Zero(), tVector::Zero(), std::array<bool, Dim>({false, false})) {
			
		}

		PointVortexFlow(
			const double p_dx
		) : PointVortexFlow(p_dx, tVector::Zero()) {
			
		}

	public:
		void prepare(const double* pState, const unsigned int number) {
			// binTree
			binTree.clear();
			for(unsigned int index = 0; index < number; ++index) {
				const tVector x = sp0ce::xPeriodic<tVector>(pState + index * VortexStateSize, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
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
				double superWAbs = 0.0;
				for (auto const& index : indexes) {
					const tVector x = sp0ce::xPeriodic<tVector>(pState + index * VortexStateSize, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
					const double w = pState[index * VortexStateSize + Dim];
					const double wAbs = std::abs(w);
					superW += w;
					superWAbs += wAbs;
					superX += wAbs * x;
				}
				if(superWAbs != 0.0) {
					superX /= superWAbs;
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
					double superWAbs = 0.0;
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
							superWAbs += std::abs(superVortexStateArray[i-1][subSuperIndex * VortexStateSize + Dim]);
							superX += std::abs(superVortexStateArray[i-1][subSuperIndex * VortexStateSize + Dim]) * tView<const tVector>(&(superVortexStateArray[i-1][subSuperIndex * VortexStateSize]));
						}
					}
					if(superWAbs != 0.0) {
						superX /= superWAbs;
					}
				}
			}
		};

	public:
		tVector getVelocity(const double* pX) const {
			tVector output = tVector::Zero();
			const tVector x = sp0ce::xPeriodic<tVector>(pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			for(int i = binTree.data.size() - 1; i > -1; --i) {
				const std::array<int, Dim> ijk = binTree.data[i].positionToIjk(x.data());
				// get siblingIjkArray (get all if at root)
				std::vector<std::array<int, Dim>> siblingIjkArray;
				if(i == binTree.data.size() - 1) {
					for (auto [key, value] : binTree.data[i].ijkToIndexes) {
					    siblingIjkArray.push_back(key);
					}
				} else {
					siblingIjkArray = binTree.data[i].ijkToSiblingIjk(ijk.data());
				}
				// compute
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
								output += sp0ce::cross2d<tVector>(superW, r.data()) * std::pow(1.0/rNorm, 2); // 2D
							} else {
								output += sp0ce::cross2d<tVector>(superW, r.data()) * std::pow(1.0/sigma, 2);
							}
						}
					}
					
				}
			}
			output *= 0.5; // 2D
			return meanVelocity + output;
		};

		tMatrix getVelocityGradients(const double* pX) const {
			tMatrix output = tMatrix::Zero();
			const tVector x = sp0ce::xPeriodic<tVector>(pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			for(int i = binTree.data.size() - 1; i > -1; --i) {
				const std::array<int, Dim> ijk = binTree.data[i].positionToIjk(x.data());
				// get siblingIjkArray (get all if at root)
				std::vector<std::array<int, Dim>> siblingIjkArray;
				if(i == binTree.data.size() - 1) {
					for (auto [key, value] : binTree.data[i].ijkToIndexes) {
					    siblingIjkArray.push_back(key);
					}
				} else {
					siblingIjkArray = binTree.data[i].ijkToSiblingIjk(ijk.data());
				}
				// compute
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
								output += std::pow(1.0/rNorm, 4) * (sp0ce::cross2d<tVector>(superW, r.data()) * r.transpose()); // 2D
							} else {
								output += sp0ce::cross2d<tVector>(superW, r.data()) * r.transpose() * std::pow(1.0/sigma, 2);
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
