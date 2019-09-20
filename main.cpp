#include "Modules/SOLIDstate.h"

int main()
{

	Operator<mat> ham = Factory::CreateHamiltonian();
	ham.matrixElements;
	ham.matrixElements.print();
	Sector sector(8,2);
	ham.sectors.push_back(sector);
	Sector sector2 = sector;
	std::cout << sector.N << std::endl;
	std::cout << ham.sectors[0].N << std::endl;
	return 0;
}
