#ifndef INFO_HPP
#define INFO_HPP

#include <iostream>
#include <vector>
#include <armadillo>
using namespace arma;

namespace solid
{

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

} // namespace solid

#endif