#include <cmath>
#include <armadillo>

#include "Factory.h"

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

template <template<typename> class T1, typename T2>
KitaevHamiltonian<T1,T2> Factory::CreateHamiltonian()
{
	KitaevHamiltonian<T1,T2> ham;
	ham.SelectTerms();
	return ham;
}

// TODO
// ugly!
// template initilizers
template KitaevHamiltonian<Mat,double> Factory::CreateHamiltonian<Mat,double>();
template KitaevHamiltonian<Mat,cx_double> Factory::CreateHamiltonian<Mat,cx_double>();
template KitaevHamiltonian<SpMat,double> Factory::CreateHamiltonian<SpMat,double>();
template KitaevHamiltonian<SpMat,cx_double> Factory::CreateHamiltonian<SpMat,cx_double>();