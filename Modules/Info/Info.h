#ifndef INFO_H
#define INFO_H

#include <iostream>
#include <vector>
#include <armadillo>
using namespace arma;

class StandardMessages
{
public:
	void Line();
	void ShowSectors(Ensemble ensemble);
};

class Timer
{
public:
	wall_clock timer;
	double timeInSec;
	void Tic()
	{
		timer.tic();
	}
	void Toc()
	{
		timeInSec = timer.toc();
	}
	void Time()
	{
		Toc();
		std::cout << "[ " << timeInSec << " ]";
	}
};

class Info : public StandardMessages, public Timer
{
public:
	Info();
};

#endif