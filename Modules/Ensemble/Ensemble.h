#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include<vector>

// contains information about number of sites and particles in the sector
class Sector
{
	public:
		// number of sites
		int L;
		// number of particles
		int N;
		// number of states in the sector (dimension of the subspace)
		int size;
		Sector(int _L, int _N);
};

// interface for Ensamble class
class IEnsemble
{
	public:
		virtual void SetSize() = 0;
		virtual void FillSectors() = 0;
		virtual ~IEnsemble(){}
};

// contains information about sectors of the Hilbert space
class Ensemble
{
	public:
		int L;
		// total size of the sectors
		int size;
		std::vector<Sector> sectors;
		virtual ~Ensemble(){}
};

#endif
