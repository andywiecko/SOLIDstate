#ifndef KITAEVHAMILTONIAN_H
#define KITAEVHAMILTONIAN_H

#include <iostream>
#include "Hamiltonian.h"

template <typename T>
class KitaevHamiltonian : public Operator<T>, public IHamiltonian
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