#include "../Ensemble/Ensemble.hpp"
#include "Info.hpp"
namespace solid
{

void StandardMessages::Line()
{
	std::cout << std::string(50, '#') << std::endl;
}

void StandardMessages::ShowSectors(Ensemble ensemble)
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

void StandardMessages::Message(std::string text)
{
	std::cout << text << "\n";
}

void StandardMessages::vMessage(std::string text)
{
	if (Info::isVerbose)
		Message(text);
}

void Timer::Time(std::string message /*default =""*/)
{
	std::cout << "# [ " << timer.toc() << " ] " << message;
}

void Timer::vTime(std::string message /*default =""*/)
{
	if (Info::isVerbose)
		Time(message);
}

// TODO remove this global temp clockss
// do no use this
arma::wall_clock clockss;
arma::wall_clock Timer::timer = clockss;
bool Info::isVerbose = false;
} // namespace solid