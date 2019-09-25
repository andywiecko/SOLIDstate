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
        Binomials()
        {
            FillBinomials(binomialsNo);
        }
        binint binom(int N, int K);

    private:
        binomialArray binomials;
        void FillBinomials(int L);

};

typedef long int statenumber;

class BaseState : public uvec
{
    public:
        bool Hop(int start, int stop);
        bool CountParticles();
        bool CreateParticle(int a1);
        bool CreatePair(int a1, int a2);
        bool CreateTriple(int a1, int a2, int a3);
};

class BaseStateNumberConverter
{
    public:
        statenumber ToNumber(BaseState state);
        BaseState ToBaseState(Sector sector, statenumber number);
        
};

statenumber BaseStateNumberConverter::ToNumber(BaseState state) 
{
	statenumber ret = 0;
	int k = 0;
	for (int i=0;i<state.size();i++)
		if (state(i) == 1) k++;
	
	/*
	//std::string temp = reverse(state);
	
	for (int i=0;i<temp.size();i++)
	{
		if (temp[i] == '1')
		{
			ret += binomial(temp.size()-1-i,k);
			k--;
		}
	}
	*/
	return ret;

}


#endif