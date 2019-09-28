#include "../Ensemble/Ensemble.h"
#include "Info.h"

void StandardMessages::Line()
{
	std::cout << "#####################################" << std::endl;
}

void StandardMessages::ShowSectors(Ensemble ensemble)	
{
	std::vector<Sector> sectors = ensemble.sectors;
	Line();
	std::cout << "# Ensamble has " << sectors.size() <<" sectors: (total size of " << ensemble.size <<  ")" << std::endl;
	for (int i=0;i<sectors.size();i++) 
  	{
		Sector sec = sectors[i];
		std::cout << "# sector with: L=" << sec.L << " N=" << sec.N << " (size of " << sec.size << ")" << std::endl;
	}
	Line();
}

Info::Info()
{
	Tic();

}