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
	
	vec mu; mu.set_size(L); mu.fill(0);
	mu(0) = 1.0;
	mu(1) = 1.0;
	mu(2) = 1.0;
	mu(3) = 1.0;
	qSystem.parameters = mu;
	qSystem.parameters.t().print();


	qSystem.hilbertSpace.InitialBaseState();
	std::cout << qSystem.hilbertSpace.sectorIndex << "\t" << qSystem.hilbertSpace.stateIndex << " |" ;
	qSystem.hilbertSpace.baseState.t().print();
	
	//qSystem.hilbertSpace.baseState.t().print();

	qSystem.hamiltonian = Factory::CreateHamiltonian();
	int size = qSystem.hilbertSpace.ensemble.size;
	qSystem.hamiltonian.matrixElements.set_size(size,size);
	qSystem.hamiltonian.matrixElements.fill(0);
	//qSystem.hamiltonian.matrixElements.print();

	MatrixElementFiller::Fill(qSystem);

	qSystem.hamiltonian.matrixElements.print();

	//ham.matrixElements.set_size(qSystem.hilbertSpace.ensemble.size,qSystem.hilbertSpace.ensemble.size);
	//ham.matrixElements.fill(0);
	//ham.matrixElements.print();

 

	info.Time();
	return 0;
}