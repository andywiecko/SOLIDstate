#ifndef FACTORY_H
#define FACTORY_H

#include "../Ensemble/Ensemble.h"
#include "../Ensemble/Canonical.h"
#include "../Ensemble/GrandCanonical.h"
#include "../Hamiltonian/KitaevHamiltonian.h"

// produces Ensembles, Hamiltonians, ...
class Factory
{
	public:
		// returns Canonial ensemble
		static Ensemble GenerateCanonicalEnsemble(int _L, int _N);

		// returns GrandCanonial ensemble
		static Ensemble GenerateGrandCanonicalEnsemble(int _L);
				
		// returns Kitaev Hamiltonian
		template <class T>
		static KitaevHamiltonian<T> CreateHamiltonian();
};

#endif
