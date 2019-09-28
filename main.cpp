#include "Modules/SOLIDstate.h"

int main()
{

	Info info;
	//info.Tic();

	HilbertSpace space;
	Ensemble ensemble = Factory::GenerateGrandCanonicalEnsemble(4);
	//Ensemble ensemble = Factory::GenerateCanonicalEnsemble(4,2);
	
	info.ShowSectors(ensemble);
	space.ensemble = ensemble;
	
	space.InitialBaseState();
	std::cout << space.sectorIndex << "\t" << space.stateIndex << " |" ;
	space.baseState.t().print();
	
	while(space.NextBaseState())
	{
		std::cout << space.sectorIndex << "\t" << space.stateIndex << " |";// << std::endl;
		space.baseState.t().print();
		// sector terms

		// inter-sector terms

	}

	info.Time();
	return 0;
}