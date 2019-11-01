/**
 * @file Combinadics.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Combinadics header
 * @version 0.100.0
 * @date 2019-10-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef COMBINADICS_HPP
#define COMBINADICS_HPP

#include <vector>
#include <armadillo>

#include "../Ensemble/Sector.hpp"
#include "BaseState.hpp"

namespace solid
{

/**
 * @brief Converting BaseState into Number and vice versa
 * It uses combinadics -- [Combinatorial number system](https://en.wikipedia.org/wiki/Combinatorial_number_system)
 */
class BaseStateNumberConverter
{
public:
    
    /**
     * @brief converts state to number
     * 
     * @param state state to convert
     * @return statenumber returns corresponding to `state` int
     */
    static statenumber ToNumber(BaseState state);
    
    /**
     * @brief converts int in given sector into BaseState
     * 
     * @param sector targeting sector
     * @param number int to convert
     * @return BaseState returns corresponding BaseState to `sector` and `number`
     */
    static BaseState ToBaseState(Sector sector, statenumber number);
};

} // namespace solid

#endif