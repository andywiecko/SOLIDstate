#include "Modules/SOLIDstate.h"

int main()
{

	Ensemble ensemble = Factory::GenerateGrandCanonicalEnsemble(8);

	std::cout << ensemble.size << std::endl;
	std::cout << ensemble.sectors[0].L << std::endl;
	std::cout << ensemble.sectors[0].N << std::endl;

	Info info;
	info.ShowSectors(ensemble.sectors);

	Operator<mat> ham = Factory::CreateHamiltonian();
	
	ham.matrixElements;
	ham.matrixElements.print();
	//int l;
	return 0;
}