#include "Combinadics.h"

// Combinadics -- combinatorial number system for states enumaration

#include <vector>
#include <armadillo>
using namespace arma;

#include "../Combinadics/Binomials.h"
extern Binomials binomials;

statenumber BaseStateNumberConverter::ToNumber(BaseState state)
{
	statenumber ret = 0;
	int k = 0;
	for (int i = 0; i < state.size(); i++)
		if (state(i) == 1)
			k++;

	BaseState temp = state.Reverse();

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp(i) == 1)
		{
			ret += binomials.binom(temp.size() - 1 - i, k);
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

	for (int i = 0; i < N; i++)
	{
		int n = N - i - 1;

		while (binomials.binom(n, N - i) <= Ntemp)
		{
			n++;
		}

		if (binomials.binom(n, N - i) > Ntemp)
			n = n - 1;

		ret(n) = 1;
		Ntemp -= binomials.binom(n, N - i);
	}
	return ret;
}