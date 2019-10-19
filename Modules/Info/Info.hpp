#ifndef INFO_HPP
#define INFO_HPP

#include <iostream>
#include <vector>
#include <armadillo>
#include <string>

#include "../Ensemble/Ensemble.hpp"
#include "Version.hpp"
#include "Timer.hpp"
#include "StandardMessages.hpp"

namespace solid
{

class Info : public StandardMessages,
			 public Timer,
			 public Version
{
public:
	static bool isVerbose;
	
	static void Start();
	static void PrintSoftwareVersion();

};

} // namespace solid

#endif