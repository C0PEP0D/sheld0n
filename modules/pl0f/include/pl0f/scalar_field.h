#ifndef PL0F_SCALAR_FIELD_H
#define PL0F_SCALAR_FIELD_H
#pragma once

// std includes
#include "sp0ce/bin.h" // BinTree

namespace pl0f {

template<unsigned int _Dim, typename _tVector, typename _tMatrix, template<typename...> typename _tView>
struct ScalarField {
	public:
		static const unsigned int Dim = _Dim;
		static const unsigned int BlobStateSize = Dim + Dim * Dim + 1; // position, covariance matrix, quantity (scalar integral over volume)
	
		using tVector = _tVector;
		using tMatrix = _tMatrix;
		template<typename ...Args>
		using tView = _tView<Args...>;

	public:
		const double dx;
		const bool IsApproximatingWithBin;
		
		const tVector periodCenter;
		const tVector periodSize;
		std::array<bool, Dim> isAxisPeriodic;
		
		sp0ce::BinTree<Dim> binTree;
		// super
		std::vector<std::map<std::array<int, Dim>, unsigned int>> ijkToSuperIndex;
		std::vector<std::vector<double>> superStateArray;

	public:
		ScalarField(
			const double p_dx,
			const bool p_isApproximatingWithBin,
			const tVector p_periodCenter,
			const tVector p_periodSize,
			const std::array<bool, Dim> p_isAxisPeriodic
		) : dx(p_dx), binTree(p_dx), IsApproximatingWithBin(p_isApproximatingWithBin), periodCenter(p_periodCenter), periodSize(p_periodSize), isAxisPeriodic(p_isAxisPeriodic) {
			
		}

		ScalarField(const double p_dx, const bool p_isApproximatingWithBin) : ScalarField(p_dx, p_isApproximatingWithBin, tVector::Zero(), tVector::Zero(), std::array<bool, Dim>({false, false})) {
			
		}

	public:
		void prepare(const double* pState, const unsigned int number) {
			// fill tree
			binTree.clear();
			for(unsigned int index = 0; index < number; ++index) {
				const tVector x = sp0ce::xPeriodic<tVector>(pState + index * BlobStateSize, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
				binTree.addIndex(index, x.data());
			}

			// compute super blobs
			ijkToSuperIndex.clear();
			superStateArray.clear();
			// 0
			ijkToSuperIndex.emplace_back();
			superStateArray.emplace_back();
			for (auto const& [ijk, indexes] : binTree.data[0].ijkToIndexes) {
				// init
				ijkToSuperIndex[0][ijk] = ijkToSuperIndex[0].size();
				superStateArray[0].resize(ijkToSuperIndex[0].size() * BlobStateSize, 0.0);
				// output
				double* pSuperState = superStateArray[0].data() + superStateArray[0].size() - BlobStateSize;
				tView<tVector> superX(pSuperState);
				tView<tMatrix> superS(pSuperState + Dim);
				double& superQ = pSuperState[Dim + Dim * Dim];
				
				// x
				for (auto const& index : indexes) {

					const double* pMemberState = pState + BlobStateSize * index;

					const tView<const tVector> memberX(pMemberState);
					const tVector memberXPeriodic = sp0ce::xPeriodic<tVector>(memberX.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
					const tView<const tMatrix> memberS(pMemberState + Dim);
					const double memberQ = pMemberState[Dim + Dim * Dim];

					superX += memberQ * memberXPeriodic;
					superQ += memberQ;
				}
				superX /= superQ;
				// s
				for (auto const& index : indexes) {
					const double* pMemberState = pState + BlobStateSize * index;
									
					const tView<const tVector> memberX(pMemberState);
					const tVector memberXPeriodic = sp0ce::xPeriodic<tVector>(memberX.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
					const tView<const tMatrix> memberS(pMemberState + Dim);
					const double memberQ = pMemberState[Dim + Dim * Dim];

					const tVector r = memberXPeriodic - superX;
					superS += memberQ * (memberS + r * r.transpose());
				}
				superS /= superQ;
			}
			if(IsApproximatingWithBin) {
				// others
				for(unsigned int i = 1; i < binTree.data.size(); ++i) {
					ijkToSuperIndex.emplace_back();
					superStateArray.emplace_back();
					for (auto const& [ijk, indexes] : binTree.data[i].ijkToIndexes) {
						// init
						ijkToSuperIndex[i][ijk] = ijkToSuperIndex[i].size();
						superStateArray[i].resize(ijkToSuperIndex[i].size() * BlobStateSize, 0.0);
						
						// process
						double* pSuperState = superStateArray[i].data() + superStateArray[i].size() - BlobStateSize;
						tView<tVector> superX(pSuperState);
						tView<tMatrix> superS(pSuperState + Dim);
						double& superQ = pSuperState[Dim + Dim * Dim];
						
						// sub
						std::array<int, Dim> subIjkStart;
						std::array<int, Dim> subIjkEnd;
						for(unsigned int j = 0; j < Dim; ++j) {
							subIjkStart[j] = ijk[j] * 2;
							subIjkEnd[j] = (ijk[j] + 1) * 2;
						}
						// x
						for (auto const& subIjk : binTree.data[i-1].getIjkInBetween(subIjkStart.data(), subIjkEnd.data())) {
							auto iterator = ijkToSuperIndex[i-1].find(subIjk);
							if(iterator != ijkToSuperIndex[i-1].end()) {
								const unsigned int subIndex = iterator->second;
								const double* pSubState = superStateArray[i-1].data() + subIndex * BlobStateSize;
								const tView<const tVector> subX(pSubState);
								const tView<const tMatrix> subS(pSubState + Dim);
								const double subQ = pSubState[Dim + Dim * Dim];

								superX += subQ * subX;
								superQ += subQ;
							}
						}
						superX /= superQ;
						// s
						for (auto const& subIjk : binTree.data[i-1].getIjkInBetween(subIjkStart.data(), subIjkEnd.data())) {
							auto iterator = ijkToSuperIndex[i-1].find(subIjk);
							if(iterator != ijkToSuperIndex[i-1].end()) {
								const unsigned int subIndex = iterator->second;
								const double* pSubState = superStateArray[i-1].data() + subIndex * BlobStateSize;
								const tView<const tVector> subX(pSubState);
								const tView<const tMatrix> subS(pSubState + Dim);
								const double subQ = pSubState[Dim + Dim * Dim];

								const tVector r = subX - superX;
								superS += subQ * (subS + r * r.transpose());
							}
						}
						superS /= superQ;
					}
				}
			}
		};

	public:
		double getScalar(const double* pState, const unsigned int number, const double* pX) {
			// input
			const tVector x = sp0ce::xPeriodic<tVector>(pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			// output
			double output = 0.0;
			// compute
			if (IsApproximatingWithBin) {
				std::vector<std::array<int, Dim>> childrenIjkArray;
				for (auto [key, value] : binTree.data[binTree.data.size() - 1].ijkToIndexes) {
				    childrenIjkArray.push_back(key);
				}

				for(unsigned int i = binTree.data.size() - 1; i > 0; --i) {
					const std::array<int, Dim> ijk = binTree.data[i].positionToIjk(x.data());
					const std::vector<std::array<int, Dim>> neighborIjkArray = binTree.data[i].ijkToNeighborIjk( ijk.data() );
					
					// compute
					std::vector<std::array<int, Dim>> newChildrenIjkArray;
					newChildrenIjkArray.reserve(childrenIjkArray.size());
					
					for(auto const& childIjk : childrenIjkArray) {
						auto iterator = ijkToSuperIndex[i].find(childIjk);
						if(iterator != ijkToSuperIndex[i].end()) {
							if(std::find(neighborIjkArray.begin(), neighborIjkArray.end(), childIjk) == neighborIjkArray.end()) {
								const unsigned int superIndex = iterator->second;
								const double* pSuperState = superStateArray[i].data() + superIndex * BlobStateSize;
								const tView<const tVector> superX(pSuperState);
								const tView<const tMatrix> superS(pSuperState + Dim);
								const double superQ = pSuperState[Dim + Dim * Dim];
								
								const double superC = superQ / (std::pow(2.0 * M_PI, Dim/2.0) * std::sqrt(superS.determinant()));
								
								// compute
								const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
								// concentration
								output += superC * std::exp(-0.5 * r.transpose() * superS.inverse() * r);
							} else {
								const std::vector<std::array<int, Dim>>& neighborChildren = binTree.data[i].ijkToChildrenIjk(childIjk.data());
								newChildrenIjkArray.insert(newChildrenIjkArray.end(), neighborChildren.begin(), neighborChildren.end());
							}
						}
					}
					newChildrenIjkArray = newChildrenIjkArray;
				}

				{ // i == 0
					const std::array<int, Dim> ijk = binTree.data[0].positionToIjk(x.data());
					
					// compute
					for(auto const& childIjk : childrenIjkArray) {
						auto iterator = ijkToSuperIndex[0].find(childIjk);
						if(iterator != ijkToSuperIndex[0].end()) {
							const unsigned int superIndex = iterator->second;
							const double* pSuperState = superStateArray[0].data() + superIndex * BlobStateSize;
							const tView<const tVector> superX(pSuperState);
							const tView<const tMatrix> superS(pSuperState + Dim);
							const double superQ = pSuperState[Dim + Dim * Dim];
							
							const double superC = superQ / (std::pow(2.0 * M_PI, Dim/2.0) * std::sqrt(superS.determinant()));
							
							// compute
							const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
							// concentration
							output += superC * std::exp(-0.5 * r.transpose() * superS.inverse() * r);
						}
					}
				}
			} else {
				for(unsigned int index = 0; index < number; ++index) {
					// input
					const double* pMemberState = pState + BlobStateSize * index;
					const tView<const tVector> memberX(pMemberState);
					const tView<const tMatrix> memberS(pMemberState + Dim);
					const double memberQ = pMemberState[Dim + Dim * Dim];

					const double memberC = memberQ / (std::pow(2.0 * M_PI, Dim/2.0) * std::sqrt(memberS.determinant()));
					
					// compute
					const tVector r = sp0ce::abPeriodic<tVector, tView>(memberX.data(), x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
					// concentration
					output += memberC * std::exp(-0.5 * r.transpose() * memberS.inverse() * r);
				}
			}
			return output;
		}

		tVector getGradient(const double* pState, const unsigned int number, const double* pX) {
			// input
			const tVector x = sp0ce::xPeriodic<tVector>(pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			// output
			tVector output = tVector::Zero();
			//compute
			if (IsApproximatingWithBin) {
				std::vector<std::array<int, Dim>> childrenIjkArray;
				for (auto [key, value] : binTree.data[binTree.data.size() - 1].ijkToIndexes) {
				    childrenIjkArray.push_back(key);
				}

				for(unsigned int i = binTree.data.size() - 1; i > 0; --i) {
					const std::array<int, Dim> ijk = binTree.data[i].positionToIjk(x.data());
					const std::vector<std::array<int, Dim>> neighborIjkArray = binTree.data[i].ijkToNeighborIjk( ijk.data() );
					
					// compute
					std::vector<std::array<int, Dim>> newChildrenIjkArray;
					newChildrenIjkArray.reserve(childrenIjkArray.size());
					
					for(auto const& childIjk : childrenIjkArray) {
						auto iterator = ijkToSuperIndex[i].find(childIjk);
						if(iterator != ijkToSuperIndex[i].end()) {
							if(std::find(neighborIjkArray.begin(), neighborIjkArray.end(), childIjk) == neighborIjkArray.end()) {
								const unsigned int superIndex = iterator->second;
								const double* pSuperState = superStateArray[i].data() + superIndex * BlobStateSize;
								const tView<const tVector> superX(pSuperState);
								const tView<const tMatrix> superS(pSuperState + Dim);
								const double superQ = pSuperState[Dim + Dim * Dim];
								
								const double superC = superQ / (std::pow(2.0 * M_PI, Dim/2.0) * std::sqrt(superS.determinant()));
								const tMatrix superSInverse = superS.inverse();
								
								// compute
								const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
								// concentration
								output += -superC * superSInverse * r * std::exp(-0.5 * r.transpose() * superSInverse * r);
							} else {
								const std::vector<std::array<int, Dim>>& neighborChildren = binTree.data[i].ijkToChildrenIjk(childIjk.data());
								newChildrenIjkArray.insert(newChildrenIjkArray.end(), neighborChildren.begin(), neighborChildren.end());
							}
						}
					}
					newChildrenIjkArray = newChildrenIjkArray;
				}

				{ // i == 0
					const std::array<int, Dim> ijk = binTree.data[0].positionToIjk(x.data());
					
					// compute
					for(auto const& childIjk : childrenIjkArray) {
						auto iterator = ijkToSuperIndex[0].find(childIjk);
						if(iterator != ijkToSuperIndex[0].end()) {
							const unsigned int superIndex = iterator->second;
							const double* pSuperState = superStateArray[0].data() + superIndex * BlobStateSize;
							const tView<const tVector> superX(pSuperState);
							const tView<const tMatrix> superS(pSuperState + Dim);
							const double superQ = pSuperState[Dim + Dim * Dim];
							
							const double superC = superQ / (std::pow(2.0 * M_PI, Dim/2.0) * std::sqrt(superS.determinant()));
							const tMatrix superSInverse = superS.inverse();
															
							// compute
							const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
							// concentration
							output += -superC * superSInverse * r * std::exp(-0.5 * r.transpose() * superSInverse * r);
						}
					}
				}
			} else {
				for(unsigned int index = 0; index < number; ++index) {
					// input
					const double* pMemberState = pState + BlobStateSize * index;
					const tView<const tVector> memberX(pMemberState);
					const tView<const tMatrix> memberS(pMemberState + Dim);
					const double memberQ = pMemberState[Dim + Dim * Dim];

					const double memberC = memberQ / (std::pow(2.0 * M_PI, Dim/2.0) * std::sqrt(memberS.determinant()));
					const tMatrix memberSInverse = memberS.inverse();
					
					// compute
					const tVector r = sp0ce::abPeriodic<tVector, tView>(memberX.data(), x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
					// concentration
					output += -memberC * memberSInverse * r * std::exp(-0.5 * r.transpose() * memberSInverse * r);
				}
			}
			return output;
		}
};

}

#endif
