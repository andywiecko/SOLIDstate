/**
 * @file TwoBodyInteraction.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Two Body Interaction class header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TWOBODYINTERACTION_HPP
#define TWOBODYINTERACTION_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
#include "../Combinadics/BaseState.hpp"
#include "Terms.hpp"
#include <armadillo>
namespace solid
{

/**
 * @brief class describes two body interaction term for Fermions particles
 * 
 * class is responsible for filling the following term:
 * \f[ 
 * \sum_i V_{ij} \hat n_i \hat n_j
 * \f]
 */
class TwoBodyInteractionTermFermions : public ITerm
{
public:
	/**
	 * @brief standard label of TwoBodyInteractionTermFermions is V
	 */
	inline static const std::string label = "V";
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

/**
 * @brief class describes two body interaction term for Spins particles
 * 
 * class is responsible for filling the following term:
 * \f[ 
 * \sum_i J_{ij} \hat S_i^z \hat S_j^z
 * \f]
 */
class TwoBodyInteractionTermSpins : public ITerm
{
public:
	/**
	 * @brief standard label of TwoBodyInteractionTermSpins is M
	 */
	inline static const std::string label = "V";
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

} // namespace solid

#endif