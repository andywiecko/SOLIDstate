#include <cmath>
#include <armadillo>

#include "Factory.hpp"

namespace solid
{

template <class T,typename ... Targs> 
T Factory::CreateEnsemble(Targs... Frags)
{
	T ensemble(Frags...);
	ensemble.SetSize();
	ensemble.FillSectors();
	return ensemble;
}

template <class T>
T Factory::CreateHamiltonian()
{
	T ham;
	std::cout << "selecting terms..." << std::endl;
	ham.SelectTerms();
	return ham;
}

template <class T,typename ... Targs>
T Factory::CreateObservable(Targs... Frags)
{
	T observable(Frags...);
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