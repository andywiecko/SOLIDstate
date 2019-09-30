#ifndef KITAEVHAMILTONIAN_H
#define KITAEVHAMILTONIAN_H

#include <iostream>
#include "Hamiltonian.h"

class KitaevHamiltonian : public Operator<mat>, public IHamiltonian
{
	public:
		virtual void SelectTerms()
		{
			// Fermions are default, but it is good to stress out
			termsEnabled.particles = Particles::Fermions;
			termsEnabled.OneBodyInteraction = true;
		}
};

#endif