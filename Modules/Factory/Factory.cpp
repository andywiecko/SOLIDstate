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

// TODO
// template initilizers
template Canonical Factory::CreateEnsemble<Canonical>(int, int);
template GrandCanonical Factory::CreateEnsemble<GrandCanonical>(int);
template ParityGrandCanonical Factory::CreateEnsemble<ParityGrandCanonical>(int, int);
template KitaevHamiltonian<Mat, double> Factory::CreateHamiltonian<KitaevHamiltonian<Mat, double>>();
template ParticleNumberOperator<Mat, double> Factory::CreateObservable<ParticleNumberOperator<Mat, double>>(int);
template ParityOperator<Mat, double> Factory::CreateObservable<ParityOperator<Mat, double>>(int);

} // namespace solid