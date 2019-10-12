#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../Ensemble/Ensemble.hpp"
#include "../Ensemble/Canonical.hpp"
#include "../Ensemble/GrandCanonical.hpp"
#include "../Ensemble/ParityGrandCanonical.hpp"
#include "../Hamiltonian/KitaevHamiltonian.hpp"
#include "../Observable/Observable.hpp"

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

	// returns ParityGrandCanonial ensemble
	static Ensemble GenerateParityGrandCanonicalEnsemble(int _L,int _parity);

	template <class T,typename ... Targs> 
    static T GenerateEnsemble(Targs...);

	// returns desired Hamiltonian
	template <class T>
	static T CreateHamiltonian();

	// returns desired Observable
	template <class T>
	static T CreateObservable(int L);
};

} // namespace solid

#endif
