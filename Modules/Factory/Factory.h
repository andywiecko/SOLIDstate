
class Factory
{
	
	public:
		static Ensemble GenerateCanonicalEnsamble(int _L)
		{
			Canonical ensemble;
			ensemble.L = _L;
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
