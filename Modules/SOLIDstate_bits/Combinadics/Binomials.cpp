/**
 * @file Binomials.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Binomials implementation
 * @version 0.100.0
 * @date 2019-10-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Binomials.hpp"

#include <vector>

namespace solid
{

// typedef for binomials container
typedef unsigned int binint;
// typedef for binomials container
typedef std::vector<binint> vecint;

void Binomials::FillBinomials(int L)
{
	vecint line1(1);
	vecint line2(2);
	vecint line3(3);
	// Pascal triangle
	line1[0] = 1;
	line2[0] = 1;
	line2[1] = 1;
	binomials.push_back(line1);
	binomials.push_back(line2);
	for (int i = 2; i < L; i++)
	{
		vecint temp(i + 1);
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0 || j == i)
				temp[j] = 1;
			else
			{
				temp[j] = binomials[i - 1][j - 1] + binomials[i - 1][j];
			}
		}
		binomials.push_back(temp);
	}
}

binint Binomials::binom(int L, int N)
{
	if (L < N)
		return 0;
	return binomials[L][N];
}

// TODO move this to some class as static field
/// global binomials array
Binomials binomials;
} // namespace solid