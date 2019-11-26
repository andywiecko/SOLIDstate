/**
 * @file GrandCanonical.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Grand Canonical header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ENSEMBLE_GRANDCANONICAL_HPP
#define ENSEMBLE_GRANDCANONICAL_HPP

#include "Ensemble.hpp"
#include "Sector.hpp"
#include <cmath>

namespace solid
{

/**
 * @brief Ensemble: GrandCanonical (int L) with:
 * L -- sites
 */
class GrandCanonical : public Ensemble, public IEnsemble
{
public:

	/**
	 * @brief Construct a new GrandCanonical object
	 * 
	 * @param _L number of sites
	 */
	GrandCanonical(int _L);

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