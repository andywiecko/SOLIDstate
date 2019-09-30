#ifndef ONEBODYINTERACTION_H
#define ONEBODYINTERACTION_H

#include "../QuantumSystem/QuantumSystem.h"
#include "Terms.h"

class OneBodyInteractionTermFermions : public ITerm
{
	public:
		template<typename T>
		static void FillElements(QuantumSystem<T> &system);
};

class OneBodyInteractionTermSpins : public ITerm
{
	public:
		template<typename T>
		static void FillElements(QuantumSystem<T> &system);
};

template<typename T>
void OneBodyInteractionTermFermions::FillElements(QuantumSystem<T> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	bool N05option = qSystem.hamiltonian.termsEnabled.N05option;
	for(int i=0;i<qSystem.hilbertSpace.baseState.size();i++)
    {
        if (qSystem.hilbertSpace.baseState.OneBodyInteraction(i))
        	qSystem.hamiltonian.matrixElements(k,k) += qSystem.parameters(i);
		if (N05option)
			qSystem.hamiltonian.matrixElements(k,k) -= 0.5 * qSystem.parameters(i);
    }
}

template<typename T>
void OneBodyInteractionTermSpins::FillElements(QuantumSystem<T> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	for(int i=0;i<qSystem.hilbertSpace.baseState.size();i++)
    {
        if (qSystem.hilbertSpace.baseState.OneBodyInteraction(i))
        	qSystem.hamiltonian.matrixElements(k,k) += qSystem.parameters(i);
		else 
			qSystem.hamiltonian.matrixElements(k,k) -= qSystem.parameters(i);
    }
}


#endif