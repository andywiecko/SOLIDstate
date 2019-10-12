#ifndef CANONICAL_HPP
#define CANONICAL_HPP

#include "../Combinadics/Binomials.hpp"

namespace solid
{

extern Binomials binomials;

class Canonical : public Ensemble, public IEnsemble
{
public:
	int N = 0;
	Canonical(int _L, int _N)
	{
		int L = _L;
		int N = _N;
	}
	void SetSize()
	{
		size = binomials.binom(L, N); // TODO binomial
	}
	void FillSectors()
	{
		Sector sector(L, N);
		sectors.push_back(sector);
	}
};

} // namespace solid

#endif
