#ifndef PARITYGRANDCANONICAL_HPP
#define PARITYGRANDCANONICAL_HPP

#include <cmath>
namespace solid
{

class ParityGrandCanonical : public Ensemble, public IEnsemble
{
public:
	int parity = 0;
	ParityGrandCanonical(int _L,int _parity)
	{
		L=_L;
		parity = _parity; // TODO modulo
	}
	void SetSize()
	{
		size = std::pow(2, L - 1);
	}
	void FillSectors()
	{
		SetSize();
		for (int N = parity; N < L + 1; N += 2)
		{
			Sector sector(L, N);
			sectors.push_back(sector);
		}
	}
};

} // namespace solid

#endif