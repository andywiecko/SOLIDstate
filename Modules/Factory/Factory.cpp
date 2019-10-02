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

template <class T>
KitaevHamiltonian<T> Factory::CreateHamiltonian()
{
	KitaevHamiltonian<T> ham;
	ham.SelectTerms();
	return ham;
}

// TODO
// ugly!
// template initilizers
template KitaevHamiltonian<mat> Factory::CreateHamiltonian<mat>();
template KitaevHamiltonian<cx_mat> Factory::CreateHamiltonian<cx_mat>();
template KitaevHamiltonian<sp_mat> Factory::CreateHamiltonian<sp_mat>();
template KitaevHamiltonian<sp_cx_mat> Factory::CreateHamiltonian<sp_cx_mat>();