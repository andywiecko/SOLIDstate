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
	static void Line();
	static void ShowSectors(Ensemble ensemble);
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
	static void Time()
	{
		std::cout << "# [ " << timer.toc() << " ] ";
	}
};

class Info : public StandardMessages,
			 public Timer
{

};

} // namespace solid

#endif