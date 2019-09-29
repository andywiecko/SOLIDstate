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

	BaseState state;
	state.set_size(6);
	state.fill(0);
	state(0) = 1;
	state(3) = 1;

	state.t().print();
	BaseStateNumberConverter converter;
	std::cout << converter.ToNumber(state);
	Sector sector(6,2);
	converter.ToBaseState(sector,3).t().print();
	info.Time();
	return 0;
}