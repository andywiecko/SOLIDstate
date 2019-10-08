#include "TwoBodyInteraction.hpp"

template <template<typename> class T1, typename T2>
void TwoBodyInteractionTermFermions::FillElements(QuantumSystem<T1, T2> &qSystem)
{
    
	int k = qSystem.hilbertSpace.stateTotalIndex;
	bool N05option = qSystem.hamiltonian.termsEnabled.N05option;
	BaseState baseState = qSystem.hilbertSpace.baseState;
    arma::SpMat<T2> V = qSystem.parameters['V'];
    auto start = V.begin();
    auto end = V.end();
    T2 Hij = 0;
	for (auto it=start;it!=end;++it ) 
	{
        int i = it.row();
        int j = it.col();
		if (baseState.TwoBodyInteraction(i,j))
            Hij += V(i,j);
		if (N05option)
		{
			if (baseState.OneBodyInteraction(i)) Hij -= 0.5*V(i,j);
			if (baseState.OneBodyInteraction(j)) Hij -= 0.5*V(i,j);
			Hij += 0.25 * V(i,j);
		}
	}
    qSystem.hamiltonian.matrixElements(k, k) += Hij;
}

template <template<typename> class T1, typename T2>
void TwoBodyInteractionTermSpins::FillElements(QuantumSystem<T1, T2> &qSystem)
{
	//TODO
}

template void TwoBodyInteractionTermFermions::FillElements<Mat,double>(QuantumSystem<Mat,double> &qSystem);
template void TwoBodyInteractionTermSpins::FillElements<Mat,double>(QuantumSystem<Mat,double> &qSystem);