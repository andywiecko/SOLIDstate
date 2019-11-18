#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Geometry.hpp"

namespace solid
{

template <typename T>
class Chain : public Geometry<T>, public IGeometry<T>
{
    using Geometry<T>::parameters;

private:
    void Create(int L, std::string key, T value) override
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

public:
    Chain(int L, initList<T> param)
    {
        for (auto const &[key, value] : param)
            Create(L, key, value);
    }

    Chain(int L, uniformParameters<T> &param)
    {
        for (auto const &[key, value] : param)
            Create(L, key, value);
    }
};

} // namespace solid

#endif