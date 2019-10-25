/**
 * @file Canonical.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Canonical Ensemble header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef CANONICAL_HPP
#define CANONICAL_HPP

#include "Ensemble.hpp"
#include "Sector.hpp"
#include "../Combinadics/Binomials.hpp"

namespace solid
{

/**
 * @brief Ensemble: Canonical (int L, int N) with:
 * L -- sites
 * N -- particles
 */
class Canonical : public Ensemble, public IEnsemble
{
public:

	/**
	 * @brief number of particles 
	 */
	int N = 0;

	/**
	 * @brief Construct a new Canonical object
	 * 
	 * @param _L number os sites
	 * @param _N number of particles
	 */
	Canonical(int _L, int _N);

	/**
	 * @brief Set the Size object
	 */
	void SetSize() override;

	/**
	 * @brief Filling Ensemble with selected sector
	 */
	void FillSectors() override;
};

} // namespace solid

#endif
