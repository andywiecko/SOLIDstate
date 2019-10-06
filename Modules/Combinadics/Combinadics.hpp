#ifndef COMBINADICS_HPP
#define COMBINADICS_HPP

#include <vector>
#include <armadillo>
using namespace arma;
#include "../Ensemble/Ensemble.hpp"
#include "BaseState.hpp"

class BaseStateNumberConverter
{
public:
    // converts state to number
    static statenumber ToNumber(BaseState state);
    // converts number in sector to BaseState
    static BaseState ToBaseState(Sector sector, statenumber number);
};

#endif