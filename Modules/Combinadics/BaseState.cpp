/**
 * @file BaseState.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief BaseState implementation
 * @version 0.100.0
 * @date 2019-10-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "BaseState.hpp"
#include <armadillo>
using namespace arma;

namespace solid
{

BaseState BaseState::Reverse()
{
	BaseState ret;
	uword size = this->size();
	ret.set_size(size);
	for (uword i = 0; i < size; i++)
	{
		ret(size - 1 - i) = this->at(i);
	}

	return ret;
}

bool BaseState::OneBodyInteraction(int site1)
{
	return (this->at(site1) == 1 ? true : false);
}

bool BaseState::TwoBodyInteraction(int site1, int site2)
{
	return (this->at(site1) == 1 && this->at(site2) == 1 ? true : false);
}

}