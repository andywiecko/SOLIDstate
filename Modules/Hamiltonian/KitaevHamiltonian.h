#ifndef KITAEVHAMILTONIAN_H
#define KITAEVHAMILTONIAN_H

#include <iostream>
#include "Hamiltonian.h"

class KitaevHamiltonian : public Operator<mat>, public IHamiltonian
{
	public:

		virtual void FillElements()
		{
			
			// terms
		}


};

#endif