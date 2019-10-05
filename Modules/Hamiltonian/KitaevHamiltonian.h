#ifndef KITAEVHAMILTONIAN_H
#define KITAEVHAMILTONIAN_H

#include <iostream>
#include "Hamiltonian.h"

template <template<typename> class T1,typename T2>
class KitaevHamiltonian : public Operator<T1,T2>, public IHamiltonian
{
public:
	virtual void SelectTerms()
	{
		// Fermions are default, but it is good to stress out
		this->termsEnabled.particles = Particles::Fermions;
		this->termsEnabled.OneBodyInteraction = true;
		//termsEnabled.N05option = true;
	}
};

#endif