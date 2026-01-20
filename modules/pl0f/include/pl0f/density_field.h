#ifndef PL0F_DENSITY_FIELD_H
#define PL0F_DENSITY_FIELD_H
#pragma once

// std includes
#include "sp0ce/bin.h" // BinTree

namespace pl0f {

template<unsigned int _Dim, typename _tVector, typename _tMatrix, template<typename...> typename _tView>
struct DensityField {
	public:
		static const unsigned int Dim = _Dim;
		static const unsigned int BlobStateSize = 2 * Dim + 2 * Dim * Dim + 1; // position, velocity, covariance matrix, its temporal derivative, mass
	
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
		DensityField(
			const double p_dx,
			const bool p_isApproximatingWithBin,
			const tVector p_periodCenter,
			const tVector p_periodSize,
			const std::array<bool, Dim> p_isAxisPeriodic
		) : dx(p_dx), binTree(p_dx), IsApproximatingWithBin(p_isApproximatingWithBin), periodCenter(p_periodCenter), periodSize(p_periodSize), isAxisPeriodic(p_isAxisPeriodic) {
			
		}

		DensityField(const double p_dx, const bool p_isApproximatingWithBin) : DensityField(p_dx, p_isApproximatingWithBin, tVector::Zero(), tVector::Zero(), std::array<bool, Dim>({false, false})) {
			
		}

	public:
		void prepare(const double* pState, const unsigned int number) {
			// prepare
			prepare0(pState, number);
			// continue
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
						tView<tVector> superV(pSuperState + Dim);
						tView<tMatrix> superS(pSuperState + 2 * Dim);
						tView<tMatrix> superDS(pSuperState + 2 * Dim + Dim * Dim);
						double& superQ = pSuperState[2 * (Dim + Dim * Dim)];

						double superQAbs = 0.0;
						
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
								const tView<const tVector> subV(pSubState + Dim);
								const tView<const tMatrix> subS(pSubState + 2 * Dim);
								const tView<const tMatrix> subDS(pSubState + 2 * Dim + Dim * Dim);
								const double subQ = pSubState[2 * (Dim + Dim * Dim)];

								const double subQAbs = std::abs(subQ);

								superX += subQAbs * subX;
								superV += subQAbs * subV;
								superDS += subQAbs * subDS; // FIXME: this is not correct I believe (should be similar to S)
								superQ += subQ;
								superQAbs += subQAbs;
							}
						}
						if(superQAbs > 0.0) {
							superX /= superQAbs;
							superV /= superQAbs;
							superDS /= superQAbs; // FIXME: this is not correct I believe (should be similar to S)
						}
						// s
						for (auto const& subIjk : binTree.data[i-1].getIjkInBetween(subIjkStart.data(), subIjkEnd.data())) {
							auto iterator = ijkToSuperIndex[i-1].find(subIjk);
							if(iterator != ijkToSuperIndex[i-1].end()) {
								const unsigned int subIndex = iterator->second;
								const double* pSubState = superStateArray[i-1].data() + subIndex * BlobStateSize;
								const tView<const tVector> subX(pSubState);
								const tView<const tVector> subV(pSubState + Dim);
								const tView<const tMatrix> subS(pSubState + 2 * Dim);
								const tView<const tMatrix> subDS(pSubState + 2 * Dim + Dim * Dim);
								const double subQ = pSubState[2 * (Dim + Dim * Dim)];

								const double subQAbs = std::abs(subQ);

								const tVector r = subX - superX;
								superS += subQAbs * (subS + r * r.transpose());
							}
						}
						if(superQAbs > 0.0) {
							superS /= superQAbs;
						};
					}
				}
			}
			// clear
			for(unsigned int i = 1; i < binTree.data.size(); ++i) {
				binTree.data[i].clear();
			}
		};

		void prepare0(const double* pState, const unsigned int number) {
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
				tView<tVector> superV(pSuperState + Dim);
				tView<tMatrix> superS(pSuperState + 2 * Dim);
				tView<tMatrix> superDS(pSuperState + 2 * Dim + Dim * Dim);
				double& superQ = pSuperState[2 * (Dim + Dim * Dim)];

				double superQAbs = 0.0;
				
				// x
				for (auto const& index : indexes) {

					const double* pMemberState = pState + BlobStateSize * index;

					const tView<const tVector> memberX(pMemberState);
					const tView<const tVector> memberV(pMemberState + Dim);
					const tView<const tMatrix> memberS(pMemberState + 2 * Dim);
					const tView<const tMatrix> memberDS(pMemberState + 2 * Dim + Dim * Dim);
					const double memberQ = pMemberState[2 * (Dim + Dim * Dim)];

					const tVector memberXPeriodic = sp0ce::xPeriodic<tVector>(memberX.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
					const double memberQAbs = std::abs(memberQ);

					superX += memberQAbs * memberXPeriodic;
					superV += memberQAbs * memberV;
					superDS += memberQAbs * memberDS; // FIXME: this is not correct I believe (should be similar to S)
					superQ += memberQ;
					superQAbs += memberQAbs;
				}
				if(superQAbs > 0.0) {
					superX /= superQAbs;
					superV /= superQAbs;
					superDS /= superQAbs; // FIXME: this is not correct I believe (should be similar to S)
				}
				// s
				for (auto const& index : indexes) {
					const double* pMemberState = pState + BlobStateSize * index;
									
					const tView<const tVector> memberX(pMemberState);
					const tView<const tVector> memberV(pMemberState + Dim);
					const tView<const tMatrix> memberS(pMemberState + 2 * Dim);
					const tView<const tMatrix> memberDS(pMemberState + 2 * Dim + Dim * Dim);
					const double memberQ = pMemberState[2 * (Dim + Dim * Dim)];

					const tVector memberXPeriodic = sp0ce::xPeriodic<tVector>(memberX.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
					const double memberQAbs = std::abs(memberQ);

					const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), memberXPeriodic.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
					superS += memberQAbs * (memberS + r * r.transpose());
				}
				if(superQAbs > 0.0) {
					superS /= superQAbs;
				};
			}
			// clear
			binTree.data[0].clear();
		}

	public:
		template <typename tOut, typename tFunc>
		tOut _get(const double* pState, const unsigned int number, const double* pX, tFunc func, const tOut& zero) {
			// input
			const tVector x = sp0ce::xPeriodic<tVector>(pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			// output
			tOut output = zero;
			// compute
			if (IsApproximatingWithBin) {
				std::vector<std::array<int, Dim>> childrenIjkArray;
				for (auto [ijk, indexes] : ijkToSuperIndex[ijkToSuperIndex.size() - 1]) {
				    childrenIjkArray.push_back(ijk);
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
								output += func(pSuperState, x.data());
							} else {
								const std::vector<std::array<int, Dim>>& neighborChildren = binTree.data[i].ijkToChildrenIjk(childIjk.data());
								newChildrenIjkArray.insert(newChildrenIjkArray.end(), neighborChildren.begin(), neighborChildren.end());
							}
						}
					}
					childrenIjkArray = newChildrenIjkArray;
				}

				{ // i == 0
					const std::array<int, Dim> ijk = binTree.data[0].positionToIjk(x.data());
					
					// compute
					for(auto const& childIjk : childrenIjkArray) {
						auto iterator = ijkToSuperIndex[0].find(childIjk);
						if(iterator != ijkToSuperIndex[0].end()) {
							const unsigned int superIndex = iterator->second;
							const double* pSuperState = superStateArray[0].data() + superIndex * BlobStateSize;
							output += func(pSuperState, x.data());
						}
					}
				}
			} else {
				for(unsigned int index = 0; index < number; ++index) {
					// input
					const double* pMemberState = pState + BlobStateSize * index;
					output += func(pMemberState, x.data());
				}
			}
			return output;
		}

		double _density(const double* pSuperState, const double* pX) {
			const tView<const tVector> superX(pSuperState);
			const tView<const tVector> superV(pSuperState + Dim);
			const tView<const tMatrix> superS(pSuperState + 2 * Dim);
			const tView<const tMatrix> superDS(pSuperState + 2 * Dim + Dim * Dim);
			const double superQ = pSuperState[2 * (Dim + Dim * Dim)];
			
			const double superC = superQ / (std::pow(2.0 * M_PI, Dim/2.0) * std::sqrt(superS.determinant()));

			const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			return superC * std::exp(-0.5 * r.transpose() * superS.inverse() * r);
		}
		
		double getDensity(const double* pState, const unsigned int number, const double* pX) {
			return _get<double>(pState, number, pX, [this](const double* _pState, const double* _pX) {
				return _density(_pState, _pX); 
			}, 0.0);
		}

		tVector _gradient(const double* pSuperState, const double* pX) {
			const tView<const tVector> superX(pSuperState);
			const tView<const tVector> superV(pSuperState + Dim);
			const tView<const tMatrix> superS(pSuperState + 2 * Dim);
			const tView<const tMatrix> superDS(pSuperState + 2 * Dim + Dim * Dim);
			const double superQ = pSuperState[2 * (Dim + Dim * Dim)];
			
			const double superC = superQ / (std::pow(2.0 * M_PI, Dim/2.0) * std::sqrt(superS.determinant()));
			const tMatrix superSInverse = superS.inverse();
			
			// compute
			const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			// concentration
			return -superC * superSInverse * r * std::exp(-0.5 * r.transpose() * superSInverse * r);
		}

		tVector getGradient(const double* pState, const unsigned int number, const double* pX) {
			return _get<tVector>(pState, number, pX, [this](const double* _pState, const double* _pX) {
				return _gradient(_pState, _pX); 
			}, tVector::Zero());
		}

		tVector _velocity(const double* pSuperState, const double* pX) {
			const tView<const tVector> superX(pSuperState);
			const tView<const tVector> superV(pSuperState + Dim);
			const tView<const tMatrix> superS(pSuperState + 2 * Dim);
			const tView<const tMatrix> superDS(pSuperState + 2 * Dim + Dim * Dim);
			const double superQ = pSuperState[2 * (Dim + Dim * Dim)];
			
			const double superC = superQ / (std::pow(2.0 * M_PI, Dim/2.0) * std::sqrt(superS.determinant()));

			const tVector r = sp0ce::abPeriodic<tVector, tView>(superX.data(), pX, periodCenter.data(), periodSize.data(), isAxisPeriodic.data());
			
			return superC * std::exp(-0.5 * r.transpose() * superS.inverse() * r) * superV;
		}

		tVector getVelocity(const double* pState, const unsigned int number, const double* pX) {
			return _get<tVector>(pState, number, pX, [this](const double* _pState, const double* _pX) {
				return _velocity(_pState, _pX); 
			}, tVector::Zero());
		}
};

}

#endif
