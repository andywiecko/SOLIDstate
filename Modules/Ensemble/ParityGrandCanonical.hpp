#ifndef PARITYGRANDCANONICAL_HPP
#define PARITYGRANDCANONICAL_HPP

#include <cmath>

class ParityGrandCanonical : public Ensemble, public IEnsemble
{
public:
	int parity;
	virtual void SetSize()
	{
		size = std::pow(2, L - 1);
	}
	virtual void FillSectors() {}
};

#endif