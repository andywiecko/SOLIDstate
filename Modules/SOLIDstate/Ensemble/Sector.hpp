/**
 * @file Sector.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Sector header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ENSEMBLE_SECTOR_HPP
#define ENSEMBLE_SECTOR_HPP

#include "../Combinadics/Binomials.hpp"

namespace solid
{

/**
 * @brief contains information about number of sites and particles in the sector
 */
class Sector
{
public:
	/**
	 * @brief number of sites
	 */
	int L;

	/**
	 * @brief number of particles
	 */
	int N;

	/**
	 * @brief number of states in the sector (dimension of the subspace)
	 */
	int size;

	/**
	 * @brief Construct a new Sector object
	 * 
	 * @param _L sites
	 * @param _N particles
	 */
	Sector(int _L, int _N);
};

} // namespace solid

#endif