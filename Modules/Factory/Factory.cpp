#include <cmath>
#include <armadillo>

#include "Factory.hpp"

Ensemble Factory::GenerateCanonicalEnsemble(int _L, int _N)
{
	Canonical ensemble;
	ensemble.L = _L;
	ensemble.N = _N;
	ensemble.SetSize();
	ensemble.FillSectors();
	return ensemble;
}

Ensemble Factory::GenerateGrandCanonicalEnsemble(int _L)
{
	GrandCanonical ensemble;
	ensemble.L = _L;
	ensemble.SetSize();
	ensemble.FillSectors();
	return ensemble;
}

template <class T>
T Factory::CreateHamiltonian()
{
	T ham;
	ham.SelectTerms();
	return ham;
}

// TODO
// ugly!
// template initilizers
template KitaevHamiltonian<Mat,double> Factory::CreateHamiltonian<KitaevHamiltonian<Mat,double>>();
//template KitaevHamiltonian<Mat,cx_double> Factory::CreateHamiltonian<Mat,cx_double>();
//template KitaevHamiltonian<SpMat,double> Factory::CreateHamiltonian<SpMat,double>();
//template KitaevHamiltonian<SpMat,cx_double> Factory::CreateHamiltonian<SpMat,cx_double>();