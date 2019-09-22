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