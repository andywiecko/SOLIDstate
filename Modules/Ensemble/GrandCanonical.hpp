#ifndef GRANDCANONICAL_HPP
#define GRANDCANONICAL_HPP

#include <cmath>
namespace solid
{
	
class GrandCanonical : public Ensemble, public IEnsemble
{
public:
	GrandCanonical(int _L)
	{
		L=_L;
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