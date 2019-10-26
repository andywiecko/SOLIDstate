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

bool BaseState::Hop(int start, int stop)
{
	return (this->at(start) == 1 && this->at(stop) == 0 ? true : false);
}


int BaseState::HopSign(int start, int stop)
{
	// function calculates number of particles
	// between hopping start and stop sites:
	// |... start ... stop ...>
	//             ^
	//            How many particles here?
	// and then returns parity of such number
	int ret;
	if (start<stop)
		ret = accu(this->subvec(start+1,stop-1));
	else
		ret = accu(this->subvec(stop+1,start-1));
	return 1-2*(ret % 2);
}

void BaseState::MakeHop(int start, int stop)
{
	this->at(start) = 0;
	this->at(stop) = 1;
}

}