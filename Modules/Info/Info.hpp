#ifndef INFO_HPP
#define INFO_HPP

#include <iostream>
#include <vector>
#include <armadillo>
#include <string>
#include "Version.hpp"

namespace solid
{

class StandardMessages
{
public:
	static void Line();
	static void ShowSectors(Ensemble ensemble);
	static void Message(std::string);
};

class Timer
{
public:
	static arma::wall_clock timer;
	static double timeInSec;
	static void Tic()
	{
		timer.tic();
	}
	static void Time(std::string message = "")
	{
		std::cout << "# [ " << timer.toc() << " ] " << message;
	}
};

class Info : public StandardMessages,
			 public Timer,
			 public Version
{
public:
	static bool isVerbose;
	static void Start()
	{
		if (isVerbose)
		{
			Line();
			Tic();
			PrintSoftwareVersion();
		}
	}
	
	static void PrintSoftwareVersion()
	{
		arma::arma_version aVersion;
		std::string armaVersion = aVersion.as_string();
		std::cout << "# armadillo  version: " << armaVersion << "\n";
		std::cout << "# solidstate version: " << solidVersion << "\n";
		Line();
	}
};




} // namespace solid

#endif