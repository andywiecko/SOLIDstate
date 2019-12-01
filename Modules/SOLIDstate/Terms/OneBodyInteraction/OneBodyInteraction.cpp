/**
 * @file OneBodyInteraction.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief One Body Interaction implementation
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "OneBodyInteraction.hpp"
namespace solid
{
template <template<typename> class T1, typename T2>
void OneBodyInteractionTermFermions::FillElements(QuantumSystem<T1, T2> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	bool N05option = qSystem.hamiltonian.termsEnabled.N05option;
	BaseState baseState = qSystem.hilbertSpace.baseState;
    auto M = qSystem.parameters[label];
	T2 Hij = 0;

	auto start = M.begin();
	auto end = M.end();
	for (auto it = start; it != end; ++it)
	{
		int i = it.row();
		int j = it.col();
		if (i!=j) continue; // only diagonal!
		T2 Mii = M(i, j); 
		
		if (baseState.OneBodyInteraction(i))
			Hij += Mii;
		if (N05option)
			Hij -= 0.5 * Mii;
	}
	qSystem.hamiltonian.matrixElements(k, k) += Hij;
}

template <template<typename> class T1, typename T2>
void OneBodyInteractionTermSpins::FillElements(QuantumSystem<T1, T2> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	BaseState baseState = qSystem.hilbertSpace.baseState;
	auto M = qSystem.parameters[label];
	T2 Hij = 0;

	auto start = M.begin();
	auto end = M.end();
	for (auto it = start; it != end; ++it)
	{
		int i = it.row();
		int j = it.col();
		if (i!=j) continue; // only diagonal!
		T2 Mii = M(i, j); 
			
		if (baseState.OneBodyInteraction(i))
			Hij += Mii;
		else
			Hij -= Mii;
	}
	qSystem.hamiltonian.matrixElements(k, k) += Hij;
}

}