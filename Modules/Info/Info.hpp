/**
 * @file Info.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Info class header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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

/**
 * @brief static Info class
 * 
 * collection of miscellaneous functions,
 * used for debugging or obtaining information for the user.
 */
class Info : public StandardMessages,
			 public Timer,
			 public Version
{
public:
	/**
	 * @brief option isVerbose 
	 * 
	 * if it is selected, more information is presented on the screen
	 */
	static bool isVerbose;

	/**
	 * @brief starts the clock, and if isVerbose is selected, shows the version of solid and arma
	 */
	static void Start();

	/**
	 * @brief prints solid and arma versions
	 */
	static void PrintSoftwareVersion();
};

} // namespace solid

#endif