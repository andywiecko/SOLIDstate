#ifndef SECTOR_HPP
#define SECTOR_HPP

#include "../Combinadics/Binomials.hpp"

namespace solid
{
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
	// Sector with L sites and N particles
	Sector(int _L, int _N);
};



}

#endif