#include "../Ensemble/Ensemble.h"
#include "Info.h"

void StandardMessages::Line()
{
	std::cout << "#####################################" << std::endl;
}

void StandardMessages::ShowSectors(std::vector<Sector> sectors)	
{
	Line();
	std::cout << "# Ensamble has " << sectors.size() <<" sectors:" << std::endl;
	for (int i=0;i<sectors.size();i++) 
  	{
		Sector sec = sectors[i];
		std::cout << "# sector with: L=" << sec.L << " N=" << sec.N << " (size=" << sec.size << ")" << std::endl;
	}
	Line();
}