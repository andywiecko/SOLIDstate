/**
 * @file CreatePair.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Create Pair term header
 * @version 0.100.0
 * @date 2019-11-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CREATEPAIR_HPP
#define CREATEPAIR_HPP

#include <string>
#include "../../QuantumSystem/QuantumSystem.hpp"
#include "../Terms.hpp"
#include "../TermsTypeEnum.hpp"

namespace solid
{

/**
 * @brief class describes pairing term for Fermions particles
 * 
 * class is responsible for filling the following term:
 * \f[ 
 * \sum_{ij}  \left(\Delta_{ij} a^\dagger_i a_j^\dagger + \mathrm{H.c.}\right)
 * \f]
 */
class CreatePairTermFermions : public ITerm
{
public:
	/**
	 * @brief standard label of CreatePairTermFermions is delta 
	 */
	inline static const std::string label = "delta";
	static const TermsTypeEnum type = TermsTypeEnum::NonlocalNondiagonal;
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

} // namespace solid

#endif