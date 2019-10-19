#include <iostream>
#include "StandardMessages.hpp"
#include "Info.hpp"

namespace solid
{
    void StandardMessages::Line()
{
	std::cout << std::string(50, '#') << std::endl;
}

void StandardMessages::ShowSectors(Ensemble & ensemble)
{
	std::vector<Sector> sectors = ensemble.sectors;
	Line();
	std::cout << "# Ensamble has " << sectors.size() << " sectors: (total size of " << ensemble.size << ")" << std::endl;
	for (int i = 0; i < sectors.size(); i++)
	{
		Sector sec = sectors[i];
		std::cout << "# sector with: L=" << sec.L << " N=" << sec.N << " (size of " << sec.size << ")" << std::endl;
	}
	Line();
}

template <template <typename> class T1, typename T2>
void StandardMessages::ShowSectors(QuantumSystem<T1,T2> & qSystem)
{
	ShowSectors(qSystem.hilbertSpace.ensemble);
}

void StandardMessages::Message(std::string text)
{
	std::cout << text << "\n";
}

void StandardMessages::vMessage(std::string text)
{
	if (Info::isVerbose)
		Message(text);
}

template void StandardMessages::ShowSectors(QuantumSystem<Mat,double>&);

}