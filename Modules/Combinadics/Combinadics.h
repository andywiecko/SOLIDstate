#ifndef COMBINADICS_H
#define COMBINADICS_H

#include <vector>
#include <armadillo>
using namespace arma;
#include "../Ensemble/Ensemble.h"

// Binomials setting
const int binomialsNo = 30;
typedef unsigned int binint;
typedef std::vector< std::vector<binint> > binomialArray;

class Binomials
{
    public:
        // returns binomial L over N
        Binomials()
        {
            FillBinomials(binomialsNo);
        }
        binint binom(int L, int N);

    private:
        binomialArray binomials;
        void FillBinomials(int L);

};

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
        bool CreateParticle(int a1);
        bool CreatePair(int a1, int a2);
        bool CreateTriple(int a1, int a2, int a3);
};

class BaseStateNumberConverter
{
    public:
        // converts state to number
        static statenumber ToNumber(BaseState state);
        // converts number in sector to BaseState
        static BaseState ToBaseState(Sector sector, statenumber number);
        
};



#endif