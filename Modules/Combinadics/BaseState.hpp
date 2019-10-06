#ifndef BASESTATE_HPP
#define BASESTATE_HPP

#include <armadillo>
using namespace arma;

// typedef for state enumeration
// Hilbert space can be huge...
typedef long int statenumber;
// typedef for BaseState data container
typedef uvec baseStateContainer;

class BaseState : public baseStateContainer
{
public:
    // returns reversed BaseState
    BaseState Reverse();
    bool Hop(int start, int stop);
    bool CountParticles();
    bool OneBodyInteraction(int site);
    bool TwoBodyInteraction(int site1, int site2);
    bool ThreeBodyInteraction(int site1, int site2, int site3);
    bool CreateParticle(int site1);
    bool CreatePair(int site1, int site2);
    bool CreateTriple(int site1, int site2, int site3);
};

#endif