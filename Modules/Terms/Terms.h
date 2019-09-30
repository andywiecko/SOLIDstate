#ifndef TERM_H
#define TERM_H

#include "../QuantumSystem/QuantumSystem.h"


class ITerm
{
	public:
		virtual void FillElements() = 0;
		virtual ~ITerm(){}
};

class OneBodyInteractionTerm : public ITerm
{
	public:
		template<typename T>
		static void FillElements(QuantumSystem<T> &system);
};

template<typename T>
void OneBodyInteractionTerm::FillElements(QuantumSystem<T> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	for(int i=0;i<qSystem.hilbertSpace.baseState.size();i++)
    {
        if (qSystem.hilbertSpace.baseState.OneBodyInteraction(i))
        qSystem.hamiltonian.matrixElements(k,k) += qSystem.parameters(i);
    }
}

#endif