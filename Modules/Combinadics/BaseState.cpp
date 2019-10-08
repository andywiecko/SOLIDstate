#include "BaseState.hpp"
#include <armadillo>
using namespace arma;

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