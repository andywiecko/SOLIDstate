#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../Ensemble/Ensemble.hpp"
#include "../Ensemble/Canonical.hpp"
#include "../Ensemble/GrandCanonical.hpp"
#include "../Hamiltonian/KitaevHamiltonian.hpp"

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
