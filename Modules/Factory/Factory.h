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
	template <template<typename> class T1, typename T2>
	static KitaevHamiltonian<T1,T2> CreateHamiltonian();
};

#endif
