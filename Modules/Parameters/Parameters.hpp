/**
 * @file Parameters.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Parameters class header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef PARAMETERS_PARAMETERS_HPP
#define PARAMETERS_PARAMETERS_HPP

#include <string>
#include <map>
#include <armadillo>

//#include "../Geometry/Geometry.hpp"

namespace solid
{

/**
 * @brief class for Parameters storing for generating IHamiltonian, Observable
 * 
 * @tparam T data type: double, std::complex<double> are supported
 */
template <typename T>
class Parameters : public std::map<std::string, arma::SpMat<T>>
{
public:
/*
    void operator=(Geometry<T> & geometry)
    {
        (*this) = geometry.parameters;
    }
*/
};

} // namespace solid

#endif