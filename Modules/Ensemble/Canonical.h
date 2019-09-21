
class Canonical : public Ensemble, public IEnsemble
{
	public:
		int N = 0;
		virtual void SetSize()
		{
			size = 15; // TODO binomial
		}
		virtual void FillSectors()
		{
			Sector sector(L,N);
			sectors.push_back(sector);
		}
};

