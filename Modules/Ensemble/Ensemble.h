#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include<vector>

class Sector
{
	public:
		int L;
		int N;
		int size;
		Sector(int _L, int _N);
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

#endif
