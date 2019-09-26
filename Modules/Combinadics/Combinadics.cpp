#include "Combinadics.h"

// Combinadics -- combinatorial number system for states enumaration

#include <vector>

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

binint Binomials::binom(int N, int K)
{
    if (N<K) return 0;
	return binomials[N][K];
}

Binomials binomials;


statenumber BaseStateNumberConverter::ToNumber(BaseState state) 
{
	statenumber ret = 0;
	int k = 0;
	for (int i=0;i<state.size();i++)
		if (state(i) == 1) k++;

	return ret;
}	
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
//	return ret;
/*
}
*/

BaseState BaseStateNumberConverter::ToBaseState(Sector sector, statenumber number)
{
	BaseState ret;
	ret.set_size(sector.L);
	ret.fill(0);
	statenumber Ntemp = sector.N;

	for (statenumber i=0;i<number;i++)
	{
		statenumber n = number-i-1;
		
		while(binomials.binom(n,number-i)<=Ntemp) n++;
		
		if (binomials.binom(n,number-i)>Ntemp) n=n-1;
		
		ret(n) = 1;
		Ntemp -= binomials.binom(n,number-i);
		
	}
	return ret;
}