#ifndef GRANDCANONICAL_HPP
#define GRANDCANONICAL_HPP

#include "Ensemble.hpp"
#include <cmath>
namespace solid
{

// Ensemble: GrandCanonical (int L) with:
// L -- sites
class GrandCanonical : public Ensemble, public IEnsemble
{
public:
	GrandCanonical(int _L)
	{
		L = _L;
	}
	void SetSize()
	{
		size = std::pow(2, L);
	}
	void FillSectors()
	{
		for (int N = 0; N < L + 1; N++)
		{
			Sector sector(L, N);
			sectors.push_back(sector);
		}
	}
};

} // namespace solid

#endif