#include <cmath>
#include <armadillo>

#include "Factory.hpp"
#include "../Info/Info.hpp"
#include "../Observable/ParticleNumberOperator.hpp"
#include "../Observable/ParityOperator.hpp"

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