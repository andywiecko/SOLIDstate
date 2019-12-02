/**
 * @file GrandCanonical.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Grand Canonical Ensemble implementation
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "GrandCanonical.hpp"

namespace solid
{

GrandCanonical::GrandCanonical(int _L)
{
    L = _L;
}

void GrandCanonical::SetSize()
{
    size = std::pow(2, L);
}

void GrandCanonical::FillSectors()
{
    for (int N = 0; N < L + 1; N++)
    {
        Sector sector(L, N);
        sectors.push_back(sector);
    }
}

} // namespace solid