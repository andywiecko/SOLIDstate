#include "Sector.hpp"

namespace solid
{

extern Binomials binomials;

Sector::Sector(int _L, int _N)
{
    L = _L;
    N = _N;
    size = binomials.binom(_L, _N); // binoimial
}
} // namespace solid