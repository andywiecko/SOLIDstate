#ifndef KITAEVHAMILTONIAN_H
#define KITAEVHAMILTONIAN_H

#include <iostream>
#include "Hamiltonian.h"

class KitaevHamiltonian : public Operator<mat>, public IHamiltonian
{
	public:

		virtual void FillElements()
		{
			int size = 8;
			matrixElements.set_size(size,size);
			matrixElements.fill(1.0);
		   
			std::cout << size << std::endl;
			//ParityGrandCanonical::SetSize();
			// terms
		}


};

#endif