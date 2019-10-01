#include "Modules/SOLIDstate.h"

#include <armadillo>
using namespace arma;

int main()
{
	Info info; int L=4;
	
	QuantumSystem<mat> qSystem;
	
	HilbertSpace space;
	
	Ensemble ensemble = Factory::GenerateGrandCanonicalEnsemble(L);
	//Ensemble ensemble = Factory::GenerateCanonicalEnsemble(L,2);
	info.ShowSectors(ensemble);
	space.ensemble = ensemble;
	

	qSystem.hilbertSpace = space;
	
	vec mu; mu.set_size(L); mu.fill(1);
	qSystem.parameters = mu;
	qSystem.parameters.t().print();

	qSystem.hilbertSpace.InitialBaseState();
	std::cout << qSystem.hilbertSpace.sectorIndex << "\t" << qSystem.hilbertSpace.stateIndex << " |" ;
	qSystem.hilbertSpace.baseState.t().print();
	
	qSystem.hamiltonian = Factory::CreateHamiltonian<mat>();
	int size = qSystem.hilbertSpace.ensemble.size;
	qSystem.hamiltonian.matrixElements.set_size(size,size);
	if (typeid(mat) == typeid(mat) )qSystem.hamiltonian.matrixElements.fill(0);

	MatrixElementFiller::Fill(qSystem);

	qSystem.hamiltonian.matrixElements.print();


 

	info.Time();
	return 0;
}