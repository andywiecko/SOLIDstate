#ifndef INFO_HPP
#define INFO_HPP

#include <iostream>
#include <vector>
#include <armadillo>

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
	arma::wall_clock timer;
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

class staticTimer
{
public:
	static arma::wall_clock timer;

};

class Info : public StandardMessages,
			 public Timer
{
public:
	Info();
};

} // namespace solid

#endif