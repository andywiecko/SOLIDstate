/**
 * @file Hop.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Hop term implementation
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Hop.hpp"

namespace solid
{

template <template <typename> class T1, typename T2>
void HopTermFermions::FillElements(QuantumSystem<T1, T2> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	BaseState baseState = qSystem.hilbertSpace.baseState;
	arma::SpMat<T2> t = qSystem.parameters[label];
	auto start = t.begin();
	auto end = t.end();

	for (auto it = start; it != end; ++it)
	{
		int i = it.row();
		int j = it.col();
		T2 tij = t(i, j);
		T2 Hij;

		if (baseState.Hop(i, j))
		{

			BaseState hoppedState = baseState;
			hoppedState.MakeHop(i, j);
			int kHopped = qSystem.hilbertSpace.GetStateIndexInCurrentSector(hoppedState);

			T2 sign = baseState.HopSign(i, j);
			Hij = sign * tij;
			qSystem.hamiltonian.matrixElements(k, kHopped) += Hij;
		}
	}
}

} // namespace solid