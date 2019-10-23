/**
 * @file Binomials.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Binomials header
 * @version 0.100.0
 * @date 2019-10-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BINOMIALS_HPP
#define BINOMIALS_HPP

#include <armadillo>
#include <vector>

namespace solid
{
    
// Binomials setting
const int binomialsNo = 30;
typedef unsigned int binint;
//
typedef std::vector<std::vector<binint>> binomialArray;

/**
 * @brief Class for handling binomial coefficients
 */
class Binomials
{
public:

    /**
     * @brief Construct a new Binomials object
     */
    Binomials()
    {
        FillBinomials(binomialsNo);
    }

    /**
     * @brief returns binomial coefficients L over N
     * \f${{L}\choose{N}} =\frac {L!}{N!(L-N)!}\f$
     * calculations are done by usinig Pascal Triangle
     * @param L is less or equal then `binomialsNo`
     * @param N is greater or equal 0 and less or equal then `L`
     * @return binint returns binomial coefficients `L` over `N`
     */
    binint binom(int L, int N);

private:

    /**
     * @brief private binomials array
     * It contains all binom coefficients up to `binomialsNo`
     */
    binomialArray binomials;

    /**
     * @brief Fills the `binomials` up to given `L` 
     * @param L 
     */
    void FillBinomials(int L);
};

} // namespace solid

#endif