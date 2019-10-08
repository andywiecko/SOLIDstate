#ifndef KITAEVHAMILTONIAN_HPP
#define KITAEVHAMILTONIAN_HPP

#include <iostream>
#include "Hamiltonian.hpp"

template <template<typename> class T1,typename T2>
class KitaevHamiltonian : public Operator<T1,T2>, public IHamiltonian
{
	using Operator<T1,T2>::termsEnabled;
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

#endif