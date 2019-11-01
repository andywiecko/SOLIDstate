/**
 * @file CreatePair.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Create Pair term implementation
 * @version 0.100.0
 * @date 2019-11-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "CreatePair.hpp"

namespace solid
{

template <template <typename> class T1, typename T2>
void CreatePairTermFermions::FillElements(QuantumSystem<T1, T2> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	BaseState baseState = qSystem.hilbertSpace.baseState;
	arma::SpMat<T2> delta = qSystem.parameters[label];
	auto start = delta.begin();
	auto end = delta.end();

	for (auto it = start; it != end; ++it)
	{
		int i = it.row();
		int j = it.col();
		T2 deltaij = delta(i, j);
		T2 Hij;

		if (baseState.CreatePairPossible(i, j))
		{

			BaseState createdPairState = baseState;
			createdPairState.CreatePair(i, j);
			int kCreatedPair = qSystem.hilbertSpace.GetStateIndexInNextParitySector(createdPairState);
			T2 sign = 1;//baseState.HopSign(i, j); //TODO
			Hij = sign * deltaij; //TODO
			qSystem.hamiltonian.matrixElements(k, kCreatedPair) += Hij;
            qSystem.hamiltonian.matrixElements(kCreatedPair,k) += Hij;
		}
	}
}

} // namespace solid