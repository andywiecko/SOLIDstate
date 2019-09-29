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
        bool OneBodyInteraction(int site);
        bool TwoBodyInteraction(int site1, int site2);
        bool ThreeBodyInteraction(int site1, int site2, int site3);
        bool CreateParticle(int site1);
        bool CreatePair(int site1, int site2);
        bool CreateTriple(int site1, int site2, int site3);
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