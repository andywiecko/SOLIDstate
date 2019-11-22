#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <string>
#include <map>
#include <armadillo>
#include "../Parameters/Parameters.hpp"

namespace solid
{

template <typename T>
using initList = std::initializer_list<std::pair<const std::string, T>>;

template <typename T>
using uniformParameters = std::map<std::string, T>;

template <typename T>
class IGeometry
{
    virtual void Create(int L, std::string key, T value) = 0;
};

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