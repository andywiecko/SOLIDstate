/**
 * @file ParityGrandCanonical.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Parity Grand Canonical header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ENSEMBLE_PARITYGRANDCANONICAL_HPP
#define ENSEMBLE_PARITYGRANDCANONICAL_HPP

#include "Ensemble.hpp"
#include "Sector.hpp"
#include <cmath>
namespace solid
{

/**
 * @brief Ensemble: ParityGrandCanonical (int L, int parity) with:
 * L -- sites
 * parity -- parity Sector (even or odd number of particles)
 */
class ParityGrandCanonical : public Ensemble, public IEnsemble
{
public:
	/**
	 * @brief parity of the Ensemble
	 */
	int parity = 0;

	/**
	 * @brief Construct a new ParityGrandCanonical object
	 * 
	 * @param _L number of sites
	 * @param _parity parity of the Ensemble
	 */
	ParityGrandCanonical(int _L, int _parity);

	/**
	 * @brief Set the Size object
	 */
	void SetSize() override;

	/**
	 * @brief Filling Ensemble with selected sectors
	 */
	void FillSectors() override;
};

} // namespace solid

#endif