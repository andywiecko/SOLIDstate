/**
 * @file Geometry.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Geometry class header
 * @version 0.100.0
 * @date 2019-11-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef GEOMETRY_GEOMETRY_HPP
#define GEOMETRY_GEOMETRY_HPP

#include <string>
#include <map>
#include <armadillo>
#include "../Parameters/Parameters.hpp"

namespace solid
{

/**
 * @brief typedef for initializer_list
 * 
 * @tparam T data type: double, std::complex<double> are supported
 */
template <typename T>
using initList = std::initializer_list<std::pair<const std::string, T>>;

/**
 * @brief typedef for map<std::string, T>
 * 
 * @tparam T data type: double, std::complex<double> are supported
 */
template <typename T>
using uniformParameters = std::map<std::string, T>;

/**
 * @brief Interface for Geometry class
 * 
 * @tparam T data type: double, std::complex<double> are supported
 */
template <typename T>
class IGeometry
{
    virtual void Create(int L, std::string key, T value) = 0;
};

/**
 * @brief Geometry parrent class
 * 
 * @tparam T data type: double, std::complex<double> are supported
 */
template <typename T>
class Geometry
{
public:
    //std::map<std::string, arma::SpMat<T>> parameters;
    Parameters<T> parameters;

    friend Geometry<T> operator+(const Geometry<T> geometry1, const Geometry<T> geometry2)
    {
        Geometry<T> ret;
        // TODO
        // check if geometry1 and geometry2 have the same dimensions
        int L = geometry1.parameters.begin()->second.n_cols;
        for (auto const &[key, value] : geometry1.parameters)
        {
            ret.parameters[key].set_size(L, L);
            ret.parameters[key] += value;
        }
        for (auto const &[key, value] : geometry2.parameters)
        {
            ret.parameters[key].set_size(L, L);
            ret.parameters[key] += value;
        }
        return ret;
    }
};

} // namespace solid

#endif