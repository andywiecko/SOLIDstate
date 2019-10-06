#ifndef CANONICAL_HPP
#define CANONICAL_HPP

#include "../Combinadics/Binomials.hpp"
extern Binomials binomials;

class Canonical : public Ensemble, public IEnsemble
{
public:
	int N = 0;
	virtual void SetSize()
	{
		size = binomials.binom(L, N); // TODO binomial
	}
	virtual void FillSectors()
	{
		Sector sector(L, N);
		sectors.push_back(sector);
	}
};

#endif
