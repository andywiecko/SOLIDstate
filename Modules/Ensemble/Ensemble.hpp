/**
 * @file Ensemble.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Ensemble interface and parent class header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ENSEMBLE_HPP
#define ENSEMBLE_HPP

#include <vector>
#include "Sector.hpp"

namespace solid
{

/**
 * @brief interface for Ensemble class
 * 
 * Abstract class containg two purely virtual functions
 */
class IEnsemble
{
public:
	/**
	 * @brief Set the Size object
	 * 
	 * Purely virtual function to override
	 * for IEnsemble implementation
	 */
	virtual void SetSize() = 0;

	/**
	 * @brief Filling Ensemble with selected sector
	 * 
	 * Purely virtual function to override
	 * for IEnsemble implementation
	 */
	virtual void FillSectors() = 0;

	/**
	 * @brief Destroy the IEnsemble object
	 */
	virtual ~IEnsemble() {}
};

/**
 * @brief Ensemble parent class
 * 
 * contains information about sectors of the Hilbert space
 */
class Ensemble
{
public:
	/**
	 * @brief number of sites
	 */
	int L;

	/**
	 * @brief total size of the sectors
	 */
	int size;
	/**
	 * @brief contains vector of Sectors
	 * 
	 * @note Sector should be inserted in ascending order
	 *       within number of particles N
	 */
	std::vector<Sector> sectors;

	/**
	 * @brief Destroy the Ensemble object
	 */
	virtual ~Ensemble() {}
};

} // namespace solid

#endif