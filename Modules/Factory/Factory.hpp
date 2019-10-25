/**
 * @file Factory.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Factory header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../Ensemble/Ensemble.hpp"
#include "../Ensemble/Canonical.hpp"
#include "../Ensemble/GrandCanonical.hpp"
#include "../Ensemble/ParityGrandCanonical.hpp"
#include "../Hamiltonian/KitaevHamiltonian.hpp"
#include "../Observable/Observable.hpp"
#include "../Observable/ParticleNumberOperator.hpp"
#include "../Observable/ParityOperator.hpp"

namespace solid
{

// produces Ensembles, Hamiltonians, ...

/**
 * @brief produces stuff
 * 
 * Factory of all diffrent template objects:
 * * Ensembles
 * * Hamiltonians
 * * Observables
 */
class Factory
{
public:
	/**
	 * @brief Create a Ensemble object
	 * 
	 * @tparam T Ensemble
	 * @tparam Targs Ensemble additional arguments (e.g. L, N, ...)
	 * @return T Ensemble
	 */
	template <class T, typename... Targs>
	static T CreateEnsemble(Targs...);

	/**
	 * @brief Create a Hamiltonian object
	 * 
	 * @tparam T Hamiltonian
	 * @return T Hamiltonian
	 */
	template <class T>
	static T CreateHamiltonian();

	/**
	 * @brief Create an Observable object
	 * 
	 * @tparam T Obserbable
	 * @tparam Targs Observable additional arguments (e.g. site number,...)
	 * @return T Observable
	 */
	template <class T, typename... Targs>
	static T CreateObservable(Targs...);
};

} // namespace solid

#endif
