
class Factory
{
	
	public:
		static KitaevHamiltonian CreateHamiltonian()
		{
			KitaevHamiltonian ham;
			ham.FillElements();
			return  ham;
		}


};
