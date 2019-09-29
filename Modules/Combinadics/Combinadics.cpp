#include "Combinadics.h"

// Combinadics -- combinatorial number system for states enumaration

#include <vector>
#include <armadillo>
using namespace arma;

typedef unsigned int binint;
typedef std::vector<binint> vecint;

void Binomials::FillBinomials(int L)
{
    vecint line1(1);
	vecint line2(2);
	vecint line3(3);
    // Pascal triangle
    line1[0] = 1;
	line2[0] = 1; line2[1] = 1;
	binomials.push_back(line1);
    binomials.push_back(line2);
    for (int i=2;i<L;i++)
	{
		vecint temp(i+1);
		for (int j=0;j<i+1;j++)
		{
			if (j==0 || j==i) temp[j] = 1;
			else
			{
				temp[j] = binomials[i-1][j-1]+binomials[i-1][j];
			}
		} 
    	binomials.push_back(temp); 
	}	

}

binint Binomials::binom(int L, int N)
{
    if (L < N) return 0;
	return binomials[L][N];
}

// global binomials 
// TODO move this to some class as static field
Binomials binomials;

BaseState BaseState::Reverse()
{
	BaseState ret;
	uword size = this->size();
	ret.set_size(size);
	for (uword i=0;i<size;i++)
	{
		ret(size-1-i) = this->at(i);
	}
	
	return ret;
}

bool BaseState::OneBodyInteraction(int site1)
{
	return (this->at(site1)==1 ? true : false);
}

statenumber BaseStateNumberConverter::ToNumber(BaseState state) 
{
	statenumber ret = 0;
	int k = 0;
	for (int i=0;i<state.size();i++)
		if (state(i) == 1) k++;

	
	BaseState temp = state.Reverse();
	
	for (int i=0;i<temp.size();i++)
	{
		if (temp(i) == 1)
		{
			ret += binomials.binom(temp.size()-1-i,k);
			k--;
		}
	}
	
	return ret;

}

BaseState BaseStateNumberConverter::ToBaseState(Sector sector, statenumber number)
{
	BaseState ret;
	ret.set_size(sector.L);
	ret.fill(0);
	statenumber Ntemp = number;
	int N = sector.N;
 
	for (int i=0;i<N;i++)
	{
		int n = N-i-1;
		
		while(binomials.binom(n,N-i)<=Ntemp)
		{
			n++;
		}

		if (binomials.binom(n,N-i)>Ntemp) n=n-1;

		ret(n) = 1;
		Ntemp -= binomials.binom(n,N-i);
		
	}
	return ret;
}