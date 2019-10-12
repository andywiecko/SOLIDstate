#ifndef CANONICAL_HPP
#define CANONICAL_HPP

#include "../Combinadics/Binomials.hpp"

namespace solid
{

// export global binomials
extern Binomials binomials;

// Ensemble: Canonical (int L, int N) with:
// L -- sites
// N -- particles
class Canonical : public Ensemble, public IEnsemble
{
public:
	int N = 0;
	Canonical(int _L, int _N)
	{
		L = _L;
		N = _N;
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
