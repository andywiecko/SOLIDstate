#ifndef ENSEMBLE_HPP
#define ENSEMBLE_HPP

#include <vector>
#include "Sector.hpp"

namespace solid
{
	


// interface for Ensamble class
class IEnsemble
{
public:
	virtual void SetSize() = 0;
	virtual void FillSectors() = 0;
	virtual ~IEnsemble() {}
};

// contains information about sectors of the Hilbert space
class Ensemble
{
public:
	int L;
	// total size of the sectors
	int size;
	std::vector<Sector> sectors;
	virtual ~Ensemble() {}
};

} // namespace solid

#endif