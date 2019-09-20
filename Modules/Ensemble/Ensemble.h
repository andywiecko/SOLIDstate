class IEnsamble
{
	public:
		int L;
		virtual int SetSize() = 0;
		virtual ~IEnsamble(){}
};

class Canonical : public IEnsamble
{
	public:
		int N;
		virtual int SetSize()
		{
			return 0; // todo binomial (L,N)
		}
};

class ParityGrandCanonical : public IEnsamble
{
	public:
		int parity;
		virtual int SetSize()
		{
			return std::pow(2,L-1);	
		}
};

class CompleteCanonical : public IEnsamble
{
	public:
		virtual int SetSize()
		{
			return std::pow(2,L);
		}
};

class Sector
{
	public:
		int L;
		int N;
		Sector(int _L, int _N)
		{
			L = _L;
			N = _N;
		}

};
