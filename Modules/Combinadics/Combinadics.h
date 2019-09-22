#ifndef COMBINADICS_H
#define COMBINADICS_H

#include <vector>

// Binomials setting
const int binomialsNo = 30;
typedef unsigned int binint;
typedef std::vector< std::vector<binint> > binomialArray;

class Binomials
{
    public:
        Binomials()
        {
            FillBinomials(binomialsNo);
        }
        binint binom(int N, int K);

    private:
        binomialArray binomials;
        void FillBinomials(int L);

};

#endif