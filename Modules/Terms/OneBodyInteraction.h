#ifndef ONEBODYINTERACTION_H
#define ONEBODYINTERACTION_H

#include "../QuantumSystem/QuantumSystem.h"
#include "Terms.h"

class OneBodyInteractionTermFermions : public ITerm
{
public:
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

class OneBodyInteractionTermSpins : public ITerm
{
public:
	template <template<typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

template <template<typename> class T1, typename T2>
void OneBodyInteractionTermFermions::FillElements(QuantumSystem<T1, T2> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	bool N05option = qSystem.hamiltonian.termsEnabled.N05option;
	for (int i = 0; i < qSystem.hilbertSpace.baseState.size(); i++)
	{
		if (qSystem.hilbertSpace.baseState.OneBodyInteraction(i))
			qSystem.hamiltonian.matrixElements(k, k) += qSystem.parameters['M'](i);
		if (N05option)
			qSystem.hamiltonian.matrixElements(k, k) -= 0.5 * qSystem.parameters['M'](i);
	}
}

template <template<typename> class T1, typename T2>
void OneBodyInteractionTermSpins::FillElements(QuantumSystem<T1, T2> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	for (int i = 0; i < qSystem.hilbertSpace.baseState.size(); i++)
	{
		if (qSystem.hilbertSpace.baseState.OneBodyInteraction(i))
			qSystem.hamiltonian.matrixElements(k, k) += qSystem.parameters['M'](i);
		else
			qSystem.hamiltonian.matrixElements(k, k) -= qSystem.parameters['M'](i);
	}
}

#endif