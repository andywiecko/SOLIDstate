/**
 * @file OneBodyInteraction.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief One Body Interaction header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TERMS_ONEBODYINTERACTION_HPP
#define TERMS_ONEBODYINTERACTION_HPP

#include "../../QuantumSystem/QuantumSystem.hpp"
#include "../Terms.hpp"
#include "../TermsTypeEnum.hpp"

namespace solid
{

/**
 * @brief class describes one body interaction term for Fermions particles
 * 
 * class is responsible for filling the following term:
 * \f[ 
 * \sum_i \mu_i \hat n_i
 * \f]
 */
class OneBodyInteractionTermFermions : public ITerm
{
public:
	/**
	 * @brief standard label of OneBodyInteractionTermFermions is M
	 */
	inline static const std::string label = "mu";
	static const TermsTypeEnum type = TermsTypeEnum::LocalDiagonal;
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

/**
 * @brief class describes one body interaction term for Spins particles
 * 
 * class is responsible for filling the following term:
 * \f[ 
 * \sum_i h_i S^z_i
 * \f]
 */
class OneBodyInteractionTermSpins : public ITerm
{
public:
	/**
	 * @brief standard label of OneBodyInteractionTermSpins is M
	 */
	inline static const std::string label = "mu";
	static const TermsTypeEnum type = TermsTypeEnum::LocalDiagonal;
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

} // namespace solid

#endif