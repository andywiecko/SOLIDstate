/**
 * @file StandardMessages.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Standard Messages implementation
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include "StandardMessages.hpp"
#include "Info.hpp"

namespace solid
{

void StandardMessages::Line()
{
	std::cout << std::string(50, '#') // handy string initialization
			  << std::endl;
}

void StandardMessages::ShowSectors(Ensemble &ensemble)
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

void StandardMessages::Eigenmessage(std::string name, int number, std::string target, double tol)
{

	std::string message = "";
	message += "starting " + name;
	message += " with options:";
	message += " noe=" + std::to_string(number) + ";";
	message += " tar=" + target + ";";
	message += " tol=" + std::to_string(tol) + ";...";
	Info::vTime(message);
}

template <template <typename> class T1, typename T2>
void StandardMessages::ShowSectors(QuantumSystem<T1, T2> &qSystem)
{
	ShowSectors(qSystem.hilbertSpace.ensemble);
}

template <template <typename> class T1, typename T2>
void StandardMessages::ShowParameters(QuantumSystem<T1, T2> &qSystem)
{
	for (auto const &[key, value] : qSystem.parameters)
	{
		typename arma::SpMat<T2>::const_iterator it = value.begin();
		typename arma::SpMat<T2>::const_iterator it_end = value.end();
		Info::Line();
		std::cout << "# " + key + ": (row) (col) (val)\n";
		for (; it != it_end; ++it)
		{
			std::cout << "# " << it.row() << "\t" << it.col() << "\t" << (*it) << "\n";
		}
	}
	Info::Line();
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

template void StandardMessages::ShowSectors(QuantumSystem<arma::Mat, double> &);
template void StandardMessages::ShowSectors(QuantumSystem<arma::Mat, arma::cx_double> &);
template void StandardMessages::ShowSectors(QuantumSystem<arma::SpMat, double> &);
template void StandardMessages::ShowSectors(QuantumSystem<arma::SpMat, arma::cx_double> &);

template void StandardMessages::ShowParameters(QuantumSystem<arma::Mat, double> &);
template void StandardMessages::ShowParameters(QuantumSystem<arma::Mat, arma::cx_double> &);
template void StandardMessages::ShowParameters(QuantumSystem<arma::SpMat, double> &);
template void StandardMessages::ShowParameters(QuantumSystem<arma::SpMat, arma::cx_double> &);

} // namespace solid