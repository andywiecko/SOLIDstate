#ifndef COMBINADICS_H
#define COMBINADICS_H

#include <vector>

// Binomials setting
const int binomialsNo = 30;
typedef long int binint;
typedef std::vector< std::vector<binint> > binomialArray;

class Binomials
{
    public:
        binomialArray binomials;
        Binomials()
        {
            FillBinomials(binomialsNo);
        }
        binint binom(int N, int K);

    private:
        void FillBinomials(int L);

};

#endif