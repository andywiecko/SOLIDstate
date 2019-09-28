#ifndef FACTORY_H
#define FACTORY_H

#include "../Ensemble/Ensemble.h"
#include "../Ensemble/Canonical.h"
#include "../Ensemble/GrandCanonical.h"
#include "../Hamiltonian/KitaevHamiltonian.h"

class Factory
{
	
	public:
		static Ensemble GenerateCanonicalEnsemble(int _L, int _N)
		{
			Canonical ensemble;
			ensemble.L = _L;
			ensemble.N = _N;
			ensemble.SetSize();
			ensemble.FillSectors();
			return ensemble; 
		}
		
		static Ensemble GenerateGrandCanonicalEnsemble(int _L)
		{
			GrandCanonical ensemble;
			ensemble.L = _L;
			ensemble.SetSize();
			ensemble.FillSectors();
			return ensemble; 
		}
		
		
		static KitaevHamiltonian CreateHamiltonian()
		{
			KitaevHamiltonian ham;
			ham.FillElements();
			return  ham;
		}

		
};

#endif
