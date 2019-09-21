#include<vector>

class Sector
{
	public:
		int L;
		int N;
		int size;
		Sector(int _L, int _N)
		{
			L = _L;
			N = _N;
			size = 0; // TODO binomial
		}

};

class IEnsemble
{
	public:
		virtual void SetSize() = 0;
		virtual void FillSectors() = 0;
		virtual ~IEnsemble(){}
};

class Ensemble
{
	public:
		int L;
		int size;
		std::vector<Sector> sectors;
		virtual ~Ensemble(){}
};

class ParityGrandCanonical : public Ensemble, public IEnsemble
{
	public:
		int parity;
		virtual void SetSize()
		{
			size = std::pow(2,L-1);	
		}
		virtual void FillSectors(){}
};

class GrandCanonical : public Ensemble, public IEnsemble
{
	public:
		virtual void SetSize()
		{
			size = std::pow(2,L);
		}
		virtual void FillSectors()
		{
			for (int N=0;N<L+1;N++)
			{
				Sector sector(L,N);
				sectors.push_back(sector);
			}
		}
};


