/**
 * @file Combinadics.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Combinadics implementation
 * @version 0.100.0
 * @date 2019-10-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Combinadics.hpp"

#include <vector>
#include <armadillo>
using namespace arma;

#include "../Combinadics/Binomials.hpp"

namespace solid
{
	
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

}