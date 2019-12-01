/**
 * @file Info.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Info class implementation
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "../Ensemble/Ensemble.hpp"
#include "Info.hpp"
namespace solid
{

void Info::Start()
{
	Tic();
	if (isVerbose)
	{
		Line();
		PrintSoftwareVersion();
	}
}

void Info::PrintSoftwareVersion()
{
	arma::arma_version aVersion;
	std::string armaVersion = aVersion.as_string();
	std::cout << "# armadillo  version: " << armaVersion << "\n";
	std::cout << "# solidstate version: " << solidVersion << "\n";
	Line();
}

// TODO remove this global temp clockss
// do not use this
arma::wall_clock clockss;
arma::wall_clock Timer::timer = clockss;
bool Info::isVerbose = false;

} // namespace solid