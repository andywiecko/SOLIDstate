#ifndef COMBINADICS_H
#define COMBINADICS_H

#include <vector>
#include <armadillo>
using namespace arma;
#include "../Ensemble/Ensemble.h"
#include "BaseState.h"

class BaseStateNumberConverter
{
    public:
        // converts state to number
        static statenumber ToNumber(BaseState state);
        // converts number in sector to BaseState
        static BaseState ToBaseState(Sector sector, statenumber number);
        
};

#endif