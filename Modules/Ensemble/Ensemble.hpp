#ifndef ENSEMBLE_HPP
#define ENSEMBLE_HPP

#include <vector>
#include "Sector.hpp"

namespace solid
{

/**
 * @brief interface for Ensamble class
 * 
 * Abstract class Containg two purely virtual functions
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
	 */
	std::vector<Sector> sectors;

	/**
	 * @brief Destroy the Ensemble object
	 */
	virtual ~Ensemble() {}
};

} // namespace solid

#endif