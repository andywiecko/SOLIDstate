/**
 * @file Factory.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Factory implementation
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <cmath>
#include <armadillo>

#include "Factory.hpp"
#include "../Info/Info.hpp"

namespace solid
{

template <class T, typename... Targs>
T Factory::CreateEnsemble(Targs... Frags)
{
	Info::vTime("creating ensemble...");
	T ensemble(Frags...);
	ensemble.SetSize();
	ensemble.FillSectors();
	Info::vMessage("done!");
	return ensemble;
}

template <class T>
T Factory::CreateHamiltonian()
{
	Info::vTime("creating hamiltonian...");
	T ham;
	ham.SelectTerms();
	Info::vMessage("done!");
	return ham;
}

template <class T, typename... Targs>
T Factory::CreateObservable(Targs... Frags)
{
	Info::vTime("creating observable...");
	T observable(Frags...);
	Info::vMessage("done!");
	return observable;
}

} // namespace solid