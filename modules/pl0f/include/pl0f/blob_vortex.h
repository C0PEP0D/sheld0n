#ifndef PL0F_BLOB_VORTEX_H
#define PL0F_BLOB_VORTEX_H
#pragma once

// std includes
#include "pl0f/scalar_field.h"

namespace pl0f {

// TODO: splitting based on anisotropy ? (but then one must change the binTree to adapt to variable size points)

template<unsigned int _Dim, typename _tVector, typename _tMatrix, template<typename...> typename _tView>
struct BlobVortexFlow {
	public:
		static const unsigned int Dim = _Dim;
		static const unsigned int BlobStateSize = Dim + Dim * Dim + 1;
	
		using tVector = _tVector;
		using tMatrix = _tMatrix;
		template<typename ...Args>
		using tView = _tView<Args...>;

	public:
		const tVector meanVelocity;
		// scalar field
		using ScalarField = pl0f::ScalarField<Dim, tVector, tMatrix, tView>;
		inline static ScalarField* pVorticityField;

	public:
		BlobVortexFlow(
			const tVector p_meanVelocity
		) : meanVelocity(p_meanVelocity) {
			
		}

		BlobVortexFlow(
		) : meanVelocity(tVector::Zero()) {
			
		}

	public:
		void prepare(ScalarField* p_pVorticityField) {
			pVorticityField = p_pVorticityField;
		};

	public:
		tVector getVorticity(const double* pState, const unsigned int number, const double* pX) const {
			return pVorticityField->getScalar(pState, number, pX);
		};

		tVector getVelocity(const double* pX) const {
			tVector output = tVector::Zero();

			const tVector x = sp0ce::xPeriodic<tVector>(pX, pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());

			std::vector<std::array<int, Dim>> childrenIjkArray;
			for (auto [key, value] : pVorticityField->binTree.data[pVorticityField->binTree.data.size() - 1].ijkToIndexes) {
			    childrenIjkArray.push_back(key);
			}

			for(unsigned int i = pVorticityField->binTree.data.size() - 1; i > 0; --i) {
				const std::array<int, Dim> ijk = pVorticityField->binTree.data[i].positionToIjk(x.data());
				const std::vector<std::array<int, Dim>> neighborIjkArray = pVorticityField->binTree.data[i].ijkToNeighborIjk( ijk.data() );

				// compute
				std::vector<std::array<int, Dim>> newChildrenIjkArray;
				newChildrenIjkArray.reserve(childrenIjkArray.size());
				
				for(auto const& childIjk : childrenIjkArray) {
					auto iterator = pVorticityField->ijkToSuperIndex[i].find(childIjk);
					if(iterator != pVorticityField->ijkToSuperIndex[i].end()) {
						if(std::find(neighborIjkArray.begin(), neighborIjkArray.end(), childIjk) == neighborIjkArray.end()) {
							const unsigned int superIndex = iterator->second;
							const double* pSuperState = pVorticityField->superStateArray[i].data() + superIndex * BlobStateSize;
							const tView<const tVector> superX(pSuperState);
							const tView<const tMatrix> superS(pSuperState + Dim);
							const double superQ = pSuperState[Dim + Dim * Dim];

							Eigen::SelfAdjointEigenSolver<tMatrix> solver(superS);
							const tVector eigenValues = solver.eigenvalues();
							const tMatrix eigenVectors = solver.eigenvectors();

							double variance;
							tVector aX;
							tVector bX;

							if(eigenValues[0] > eigenValues[1]) {
								variance = eigenValues[1];
								const double d = std::sqrt(eigenValues[0] - eigenValues[1]);
								aX = superX - d * eigenVectors.col(0); // there is no 0.5 and this is intentional
								bX = superX + d * eigenVectors.col(0);
							} else {
								variance = eigenValues[0];
								const double d = std::sqrt(eigenValues[1] - eigenValues[0]);
								aX = superX - d * eigenVectors.col(1); // there is no 0.5 and this is intentional
								bX = superX + d * eigenVectors.col(1);
							}

							// a
							const tVector aR = sp0ce::abPeriodic<tVector, tView>(aX.data(), x.data(), pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());
							const double aRNorm = aR.norm();
							if(aRNorm > 0.0) {
								const double aRNorm2 = std::pow(aRNorm, 2);
								output += (0.5 / M_PI) * (1 - std::exp(-0.5 * aRNorm2 / variance)) / aRNorm2 * sp0ce::cross2d<tVector>(0.5 * superQ, aR.data()); // 0.5 q factor because of fake split
							}
							// b
							const tVector bR = sp0ce::abPeriodic<tVector, tView>(bX.data(), x.data(), pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());
							const double bRNorm = bR.norm();
							if(bRNorm > 0.0) {
								const double bRNorm2 = std::pow(bRNorm, 2);
								output += (0.5 / M_PI) * (1 - std::exp(-0.5 * bRNorm2 / variance)) / bRNorm2 * sp0ce::cross2d<tVector>(0.5 * superQ, bR.data()); // 0.5 q factor because of fake split
							}
						} else {
							const std::vector<std::array<int, Dim>>& neighborChildren = pVorticityField->binTree.data[i].ijkToChildrenIjk(childIjk.data());
							newChildrenIjkArray.insert(newChildrenIjkArray.end(), neighborChildren.begin(), neighborChildren.end());
						}
					}
				}
				childrenIjkArray = newChildrenIjkArray;
			}

			{ // i == 0
				const std::array<int, Dim> ijk = pVorticityField->binTree.data[0].positionToIjk(x.data());
				
				// compute
				for(auto const& childIjk : childrenIjkArray) {
					auto iterator = pVorticityField->ijkToSuperIndex[0].find(childIjk);
					if(iterator != pVorticityField->ijkToSuperIndex[0].end()) {
						const unsigned int superIndex = iterator->second;
						const double* pSuperState = pVorticityField->superStateArray[0].data() + superIndex * BlobStateSize;
						const tView<const tVector> superX(pSuperState);
						const tView<const tMatrix> superS(pSuperState + Dim);
						const double superQ = pSuperState[Dim + Dim * Dim];

						Eigen::SelfAdjointEigenSolver<tMatrix> solver(superS);
						const tVector eigenValues = solver.eigenvalues();
						const tMatrix eigenVectors = solver.eigenvectors();

						double variance;
						tVector aX;
						tVector bX;

						if(eigenValues[0] > eigenValues[1]) {
							variance = eigenValues[1];
							const double d = std::sqrt(eigenValues[0] - eigenValues[1]);
							aX = superX - d * eigenVectors.col(0); // there is no 0.5 and this is intentional
							bX = superX + d * eigenVectors.col(0);
						} else {
							variance = eigenValues[0];
							const double d = std::sqrt(eigenValues[1] - eigenValues[0]);
							aX = superX - d * eigenVectors.col(1); // there is no 0.5 and this is intentional
							bX = superX + d * eigenVectors.col(1);
						}

						// a
						const tVector aR = sp0ce::abPeriodic<tVector, tView>(aX.data(), x.data(), pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());
						const double aRNorm = aR.norm();
						if(aRNorm > 0.0) {
							const double aRNorm2 = std::pow(aRNorm, 2);
							output += (0.5 / M_PI) * (1 - std::exp(-0.5 * aRNorm2 / variance)) / aRNorm2 * sp0ce::cross2d<tVector>(0.5 * superQ, aR.data()); // 0.5 q factor because of fake split
						}
						// b
						const tVector bR = sp0ce::abPeriodic<tVector, tView>(bX.data(), x.data(), pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());
						const double bRNorm = bR.norm();
						if(bRNorm > 0.0) {
							const double bRNorm2 = std::pow(bRNorm, 2);
							output += (0.5 / M_PI) * (1 - std::exp(-0.5 * bRNorm2 / variance)) / bRNorm2 * sp0ce::cross2d<tVector>(0.5 * superQ, bR.data()); // 0.5 q factor because of fake split
						}
					}
				}
			}
			return meanVelocity + output;
		};

		tMatrix getVelocityGradients(const double* pX) const {
			tMatrix output = tMatrix::Zero();
			const tVector x = sp0ce::xPeriodic<tVector>(pX, pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());
			
			std::vector<std::array<int, Dim>> childrenIjkArray;
			for (auto [key, value] : pVorticityField->binTree.data[pVorticityField->binTree.data.size() - 1].ijkToIndexes) {
			    childrenIjkArray.push_back(key);
			}

			for(unsigned int i = pVorticityField->binTree.data.size() - 1; i > 0; --i) {
				const std::array<int, Dim> ijk = pVorticityField->binTree.data[i].positionToIjk(x.data());
				const std::vector<std::array<int, Dim>> neighborIjkArray = pVorticityField->binTree.data[i].ijkToNeighborIjk( ijk.data() );

				// compute
				std::vector<std::array<int, Dim>> newChildrenIjkArray;
				newChildrenIjkArray.reserve(childrenIjkArray.size());
				
				for(auto const& childIjk : childrenIjkArray) {
					auto iterator = pVorticityField->ijkToSuperIndex[i].find(childIjk);
					if(iterator != pVorticityField->ijkToSuperIndex[i].end()) {
						if(std::find(neighborIjkArray.begin(), neighborIjkArray.end(), childIjk) == neighborIjkArray.end()) {
							const unsigned int superIndex = iterator->second;
							const double* pSuperState = pVorticityField->superStateArray[i].data() + superIndex * BlobStateSize;
							const tView<const tVector> superX(pSuperState);
							const tView<const tMatrix> superS(pSuperState + Dim);
							const double superQ = pSuperState[Dim + Dim * Dim];

							Eigen::SelfAdjointEigenSolver<tMatrix> solver(superS);
							const tVector eigenValues = solver.eigenvalues();
							const tMatrix eigenVectors = solver.eigenvectors();

							double variance;
							tVector aX;
							tVector bX;

							if(eigenValues[0] > eigenValues[1]) {
								variance = eigenValues[1];
								const double d = std::sqrt(eigenValues[0] - eigenValues[1]);
								aX = superX - d * eigenVectors.col(0); // there is no 0.5 and this is intentional
								bX = superX + d * eigenVectors.col(0);
							} else {
								variance = eigenValues[0];
								const double d = std::sqrt(eigenValues[1] - eigenValues[0]);
								aX = superX - d * eigenVectors.col(1); // there is no 0.5 and this is intentional
								bX = superX + d * eigenVectors.col(1);
							}

							// a
							const tVector aR = sp0ce::abPeriodic<tVector, tView>(aX.data(), x.data(), pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());
							const double aRNorm = aR.norm();
							if(aRNorm > 0.0) {
								const double aRNorm2 = std::pow(aRNorm, 2);

								const double A = (0.5 * 0.5 * superQ / M_PI) * (1 - std::exp(-0.5 * aRNorm2 / variance)) / aRNorm2;
								const double Ap = (0.5 * 0.5 * superQ / M_PI) * ( 
									-2 * (1 - std::exp(-0.5 * aRNorm2 / variance)) / (aRNorm2 * aRNorm) +
									std::exp(-0.5 * aRNorm2 / variance) / (variance * aRNorm)
								);
								tMatrix J;
								J  << 0.0, -1.0,
									  1.0,  0.0;
								
								output += A * J + Ap * ((J * aR) * aR.transpose())  / aRNorm - A * J * (aR * aR.transpose()) / aRNorm;
							}
							// b
							const tVector bR = sp0ce::abPeriodic<tVector, tView>(bX.data(), x.data(), pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());
							const double bRNorm = bR.norm();
							if(bRNorm > 0.0) {
								const double bRNorm2 = std::pow(bRNorm, 2);
								
								const double A = (0.5 * 0.5 * superQ / M_PI) * (1 - std::exp(-0.5 * bRNorm2 / variance)) / bRNorm2;
								const double Ap = (0.5 * 0.5 * superQ / M_PI) * ( 
									-2 * (1 - std::exp(-0.5 * bRNorm2 / variance)) / (bRNorm2 * bRNorm) +
									std::exp(-0.5 * bRNorm2 / variance) / (variance * bRNorm)
								);
								tMatrix J;
								J  << 0.0, -1.0,
									  1.0,  0.0;
								
								output += A * J + Ap * ((J * bR) * bR.transpose())  / bRNorm - A * J * (bR * bR.transpose()) / bRNorm;
							}
						} else {
							const std::vector<std::array<int, Dim>>& neighborChildren = pVorticityField->binTree.data[i].ijkToChildrenIjk(childIjk.data());
							newChildrenIjkArray.insert(newChildrenIjkArray.end(), neighborChildren.begin(), neighborChildren.end());
						}
					}
				}
				childrenIjkArray = newChildrenIjkArray;
			}

			{ // i == 0
				const std::array<int, Dim> ijk = pVorticityField->binTree.data[0].positionToIjk(x.data());
				
				// compute
				for(auto const& childIjk : childrenIjkArray) {
					auto iterator = pVorticityField->ijkToSuperIndex[0].find(childIjk);
					if(iterator != pVorticityField->ijkToSuperIndex[0].end()) {
						const unsigned int superIndex = iterator->second;
						const double* pSuperState = pVorticityField->superStateArray[0].data() + superIndex * BlobStateSize;
						const tView<const tVector> superX(pSuperState);
						const tView<const tMatrix> superS(pSuperState + Dim);
						const double superQ = pSuperState[Dim + Dim * Dim];

						Eigen::SelfAdjointEigenSolver<tMatrix> solver(superS);
						const tVector eigenValues = solver.eigenvalues();
						const tMatrix eigenVectors = solver.eigenvectors();

						double variance;
						tVector aX;
						tVector bX;

						if(eigenValues[0] > eigenValues[1]) {
							variance = eigenValues[1];
							const double d = std::sqrt(eigenValues[0] - eigenValues[1]);
							aX = superX - d * eigenVectors.col(0); // there is no 0.5 and this is intentional
							bX = superX + d * eigenVectors.col(0);
						} else {
							variance = eigenValues[0];
							const double d = std::sqrt(eigenValues[1] - eigenValues[0]);
							aX = superX - d * eigenVectors.col(1); // there is no 0.5 and this is intentional
							bX = superX + d * eigenVectors.col(1);
						}

						// a
						const tVector aR = sp0ce::abPeriodic<tVector, tView>(aX.data(), x.data(), pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());
						const double aRNorm = aR.norm();
						if(aRNorm > 0.0) {
							const double aRNorm2 = std::pow(aRNorm, 2);

							const double A = (0.5 * 0.5 * superQ / M_PI) * (1 - std::exp(-0.5 * aRNorm2 / variance)) / aRNorm2;
							const double Ap = (0.5 * 0.5 * superQ / M_PI) * ( 
								-2 * (1 - std::exp(-0.5 * aRNorm2 / variance)) / (aRNorm2 * aRNorm) +
								std::exp(-0.5 * aRNorm2 / variance) / (variance * aRNorm)
							);
							tMatrix J;
							J  << 0.0, -1.0,
								  1.0,  0.0;
							
							output += A * J + Ap * ((J * aR) * aR.transpose())  / aRNorm - A * J * (aR * aR.transpose()) / aRNorm;
						}
						// b
						const tVector bR = sp0ce::abPeriodic<tVector, tView>(bX.data(), x.data(), pVorticityField->periodCenter.data(), pVorticityField->periodSize.data(), pVorticityField->isAxisPeriodic.data());
						const double bRNorm = bR.norm();
						if(bRNorm > 0.0) {
							const double bRNorm2 = std::pow(bRNorm, 2);
							
							const double A = (0.5 * 0.5 * superQ / M_PI) * (1 - std::exp(-0.5 * bRNorm2 / variance)) / bRNorm2;
							const double Ap = (0.5 * 0.5 * superQ / M_PI) * ( 
								-2 * (1 - std::exp(-0.5 * bRNorm2 / variance)) / (bRNorm2 * bRNorm) +
								std::exp(-0.5 * bRNorm2 / variance) / (variance * bRNorm)
							);
							tMatrix J;
							J  << 0.0, -1.0,
								  1.0,  0.0;
							
							output += A * J + Ap * ((J * bR) * bR.transpose())  / bRNorm - A * J * (bR * bR.transpose()) / bRNorm;
						}
					}
				}
						}

			return output;
		};
};

}

#endif
