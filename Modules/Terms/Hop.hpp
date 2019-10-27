/**
 * @file Hop.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Hop term class header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef HOP_HPP
#define HOP_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
#include "Terms.hpp"
namespace solid
{

/**
 * @brief class describes hopping term for Fermions particles
 * 
 * class is responsible for filling the following term:
 * \f[ 
 * \sum_{ij}  \left(t_{ij} a^\dagger_i a_j + \mathrm{H.c.}\right)
 * \f]
 */
class HopTermFermions : public ITerm
{
public:
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

}

#endif