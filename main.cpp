#include "Modules/SOLIDstate.h"

int main()
{

	Ensemble ensemble = Factory::GenerateGrandCanonicalEnsemble(4);

	std::cout << ensemble.size << std::endl;
	std::cout << ensemble.sectors[0].L << std::endl;
	std::cout << ensemble.sectors[0].N << std::endl;

	Info info;
	info.ShowSectors(ensemble.sectors);

	Binomials binomials;
	std::cout << binomials.binom(6,0) << std::endl;

	Operator<mat> ham = Factory::CreateHamiltonian();
	
	ham.matrixElements;
	ham.matrixElements.print();
	//int l;

	HilbertSpace space;
	space.ensemble = ensemble;
	
	space.InitialBaseState();
	std::cout << space.sectorIndex << "\t" << space.stateIndex << " |" ;
	space.baseState.t().print();
	
	while(space.NextBaseState())
	{
		std::cout << space.sectorIndex << "\t" << space.stateIndex << " |";// << std::endl;
		space.baseState.t().print();
	}

	
	return 0;
}