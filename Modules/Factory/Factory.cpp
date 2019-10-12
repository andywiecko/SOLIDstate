#include <cmath>
#include <armadillo>

#include "Factory.hpp"

namespace solid
{

Ensemble Factory::GenerateCanonicalEnsemble(int _L, int _N)
{
	Canonical ensemble(_L,_N);
	ensemble.L=_L;
	ensemble.N=_N;
	ensemble.SetSize();
	ensemble.FillSectors();
	return ensemble;
}

Ensemble Factory::GenerateGrandCanonicalEnsemble(int _L)
{
	GrandCanonical ensemble(_L);
	ensemble.SetSize();
	ensemble.FillSectors();
	return ensemble;
}

Ensemble Factory::GenerateParityGrandCanonicalEnsemble(int _L,int _parity)
{
	ParityGrandCanonical ensemble(_L,_parity);
	ensemble.SetSize();
	ensemble.FillSectors();
	return ensemble;
}

template <class T,typename ... Targs> 
T Factory::GenerateEnsemble(Targs... Frags)
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

template <class T>
T Factory::CreateObservable(int L)
{
	T observable(L);
	return observable;
}

// TODO
// ugly!
// template initilizers
template Canonical Factory::GenerateEnsemble<Canonical>(int,int);
template GrandCanonical Factory::GenerateEnsemble<GrandCanonical>(int);
template ParityGrandCanonical Factory::GenerateEnsemble<ParityGrandCanonical>(int,int);
template KitaevHamiltonian<Mat,double> Factory::CreateHamiltonian<KitaevHamiltonian<Mat,double>>();
template ParticleNumberOperator<Mat,double> Factory::CreateObservable<ParticleNumberOperator<Mat,double>>(int);
//template KitaevHamiltonian<Mat,cx_double> Factory::CreateHamiltonian<Mat,cx_double>();
//template KitaevHamiltonian<SpMat,double> Factory::CreateHamiltonian<SpMat,double>();
//template KitaevHamiltonian<SpMat,cx_double> Factory::CreateHamiltonian<SpMat,cx_double>();

}