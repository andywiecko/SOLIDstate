#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../Ensemble/Ensemble.hpp"
#include "../Ensemble/Canonical.hpp"
#include "../Ensemble/GrandCanonical.hpp"
#include "../Hamiltonian/KitaevHamiltonian.hpp"

namespace solid
{
	
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
	static T CreateHamiltonian();
};

} // namespace solid

#endif
