#include <cmath>
#include <armadillo>

#include "Factory.hpp"
#include "../Info/Info.hpp"

namespace solid
{

template <class T,typename ... Targs> 
T Factory::CreateEnsemble(Targs... Frags)
{
	Info::Time("creating ensemble...");
	T ensemble(Frags...);
	ensemble.SetSize();
	ensemble.FillSectors();
	Info::Message("done!");
	return ensemble;
}

template <class T>
T Factory::CreateHamiltonian()
{
	Info::Time("creating hamiltonian...");
	T ham;
	ham.SelectTerms();
	Info::Message("done!");
	return ham;
}

template <class T,typename ... Targs>
T Factory::CreateObservable(Targs... Frags)
{
	Info::Time("creating observable...");
	T observable(Frags...);
	Info::Message("done!");
	return observable;
}

// TODO
// template initilizers
template Canonical Factory::CreateEnsemble<Canonical>(int,int);
template GrandCanonical Factory::CreateEnsemble<GrandCanonical>(int);
template ParityGrandCanonical Factory::CreateEnsemble<ParityGrandCanonical>(int,int);
template KitaevHamiltonian<Mat,double> Factory::CreateHamiltonian<KitaevHamiltonian<Mat,double>>();
template ParticleNumberOperator<Mat,double> Factory::CreateObservable<ParticleNumberOperator<Mat,double>>(int);

}