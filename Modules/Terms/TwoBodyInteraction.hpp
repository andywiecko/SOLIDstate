#ifndef TWOBODYINTERACTION_HPP
#define TWOBODYINTERACTION_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
#include "Terms.hpp"

class TwoBodyInteractionTermFermions : public ITerm
{
public:
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

class TwoBodyInteractionTermSpins : public ITerm
{
public:
	template <template<typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

template <template<typename> class T1, typename T2>
void TwoBodyInteractionTermFermions::FillElements(QuantumSystem<T1, T2> &qSystem)
{
    
	int k = qSystem.hilbertSpace.stateTotalIndex;
	bool N05option = qSystem.hamiltonian.termsEnabled.N05option;
    int j=0; // TODO adj sparse iteration!
	for (int i = 0; i < qSystem.hilbertSpace.baseState.size(); i++)
	{
		if (qSystem.hilbertSpace.baseState.TwoBodyInteraction(i,j))
			qSystem.hamiltonian.matrixElements(k, k) += qSystem.parameters['M'](i);
		if (N05option)
			qSystem.hamiltonian.matrixElements(k, k) -= 0.5 * qSystem.parameters['M'](i);
	}
    
}

template <template<typename> class T1, typename T2>
void TwoBodyInteractionTermSpins::FillElements(QuantumSystem<T1, T2> &qSystem)
{

}

#endif