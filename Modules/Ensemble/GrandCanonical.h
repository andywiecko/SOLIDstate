#ifndef GRANDCANONICAL_H
#define GRANDCANONICAL_H

#include <cmath>

class GrandCanonical : public Ensemble, public IEnsemble
{
public:
	virtual void SetSize()
	{
		size = std::pow(2, L);
	}
	virtual void FillSectors()
	{
		for (int N = 0; N < L + 1; N++)
		{
			Sector sector(L, N);
			sectors.push_back(sector);
		}
	}
};

#endif
