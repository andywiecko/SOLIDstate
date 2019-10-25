/**
 * @file KitaevHamiltonian.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Kitaev Hamiltonian header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef KITAEVHAMILTONIAN_HPP
#define KITAEVHAMILTONIAN_HPP

#include "Hamiltonian.hpp"

namespace solid
{

template <template <typename> class T1, typename T2>
class KitaevHamiltonian : public Operator<T1, T2>, public IHamiltonian
{
	using Operator<T1, T2>::termsEnabled;

public:
	void SelectTerms()
	{
		// Fermions are default, but it is good to stress out
		termsEnabled.particles = Particles::Fermions;
		termsEnabled.OneBodyInteraction = true;
		termsEnabled.TwoBodyInteraction = true;
		//termsEnabled.N05option = true;
	}
};

} // namespace solid

#endif