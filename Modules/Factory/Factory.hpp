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

	// returns selected ensemble
	template <class T,typename ... Targs> 
    static T CreateEnsemble(Targs...);

	// returns selected Hamiltonian
	template <class T>
	static T CreateHamiltonian();

	// returns selected Observable
	template <class T,typename ... Targs>
	static T CreateObservable(Targs ...);
};

} // namespace solid

#endif
