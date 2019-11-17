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

    friend Geometry<T> operator+(const Geometry<T> geometry1,const Geometry<T> geometry2)
    {
        Geometry<T> ret;
        for (auto const &[key, value] : geometry1.parameters)
        {
            ret.parameters[key] = value;
        }
        for (auto const &[key, value] : geometry2.parameters)
        {
            ret.parameters[key] = value;
        }
        return ret;
    }

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
            // TODO diffrent case for
            // local diagonal, local non-diagonal, non-local diagonal, non-local non-diagonal
            arma::SpMat<T> tmp(L, L);
            for (int i = 0; i < L - 1; i++)
                tmp(i, i + 1) = value;
            for (int i = 0; i < L - 1; i++)
                tmp(i + 1, i) = value; // TODO complex conj
            parameters[key] = tmp;
        }
    }
};

template <typename T>
class Ring : public Geometry<T>
{
    using Geometry<T>::parameters;
    
public:
    Ring(int L, std::map<std::string, T> &param)
    {
        for (auto const &[key, value] : param)
        {
            // TODO diffrent case for
            // local diagonal, local non-diagonal, non-local diagonal, non-local non-diagonal
            arma::SpMat<T> tmp(L, L);
            for (int i = 0; i < L; i++)
                tmp(i, (i + 1) % L) = value;
            for (int i = 0; i < L; i++)
                tmp((i + 1) % L, i) = value; // TODO complex conj
            parameters[key] = tmp;
        }
    }
};

} // namespace solid

#endif