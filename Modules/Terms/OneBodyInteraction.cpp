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
	for (int i = 0; i < baseState.size(); i++)
	{
		T2 Mi = M(i,i);
		if (baseState.OneBodyInteraction(i))
			Hij += Mi;
		if (N05option)
			Hij -= 0.5 * Mi;
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
	for (int i = 0; i < baseState.size(); i++)
	{
		T2 Mi = M(i,i);
		if (baseState.OneBodyInteraction(i))
			Hij += Mi;
		else
			Hij -= Mi;
	}
	qSystem.hamiltonian.matrixElements(k, k) += Hij;
}

}