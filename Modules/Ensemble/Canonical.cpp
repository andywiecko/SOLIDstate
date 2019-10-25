/**
 * @file Canonical.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Canonical Ensemble implementation
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Canonical.hpp"

namespace solid
{

/**
 * @brief exporting global binomials
 * 
 */
extern Binomials binomials;

Canonical::Canonical(int _L, int _N)
{
    L = _L;
    N = _N;
}

void Canonical::SetSize()
{
    size = binomials.binom(L, N);
}

void Canonical::FillSectors()
{
    Sector sector(L, N);
    sectors.push_back(sector);
}

} // namespace solid