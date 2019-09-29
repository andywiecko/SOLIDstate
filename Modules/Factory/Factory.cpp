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

KitaevHamiltonian Factory::CreateHamiltonian()
{
	KitaevHamiltonian ham;
	ham.FillElements();
	return  ham;
}