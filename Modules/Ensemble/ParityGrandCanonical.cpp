/**
 * @file ParityGrandCanonical.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Parity Grand Canonical implementation
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "ParityGrandCanonical.hpp"

namespace solid
{

ParityGrandCanonical::ParityGrandCanonical(int _L, int _parity)
{
    L = _L;
    parity = _parity; // TODO modulo
}

void ParityGrandCanonical::SetSize()
{
    size = std::pow(2, L - 1);
}

void ParityGrandCanonical::FillSectors()
{
    SetSize();
    for (int N = parity; N < L + 1; N += 2)
    {
        Sector sector(L, N);
        sectors.push_back(sector);
    }
}

} // namespace solid