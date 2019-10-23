#include "OneBodyInteraction.hpp"
namespace solid
{
template <template<typename> class T1, typename T2>
void OneBodyInteractionTermFermions::FillElements(QuantumSystem<T1, T2> &qSystem)
{
	int k = qSystem.hilbertSpace.stateTotalIndex;
	bool N05option = qSystem.hamiltonian.termsEnabled.N05option;
	BaseState baseState = qSystem.hilbertSpace.baseState;
    auto M = qSystem.parameters['M'];
	T2 Hij = 0;
	for (int i = 0; i < baseState.size(); i++)
	{
		T2 Mi = M(i);
		if (baseState.OneBodyInteraction(i))
			Hij += Mi;
		if (N05option)
			Hij -= 0.5 * Mi;
	}
	qSystem.hamiltonian.matrixElements(k, k) += Hij;
}

// TODO fix this mess!
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

}