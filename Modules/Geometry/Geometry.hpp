#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <string>
#include <map>
#include <armadillo>

namespace solid
{

template <typename T>
class Geometry
{
public:
    std::map<std::string, arma::SpMat<T>> parameters;
};

template <typename T>
class Chain : public Geometry<T>
{
    using Geometry<T>::parameters;

public:
    Chain(int L, std::map<std::string, T> &param)
    {
        for (auto const &[key, value] : param)
        {
            arma::SpMat<T> tmp(L, L);
            for (int i = 0; i < L - 1; i++)
                tmp(i, i + 1) = value;
            for (int i = 0; i < L - 1; i++)
                tmp(i + 1, i) = value; // TODO complex conj
            parameters[key] = tmp;
        }
    }
};

} // namespace solid

#endif