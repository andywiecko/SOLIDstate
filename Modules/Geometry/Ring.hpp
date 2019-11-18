#ifndef RING_HPP
#define RING_HPP

#include "Geometry.hpp"

namespace solid
{

template <typename T>
class Ring : public Geometry<T>, public IGeometry<T>
{
    using Geometry<T>::parameters;

private:
    void Create(int L, std::string key, T value) override
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

public:
    Ring(int L, initList<T> param)
    {
        for (auto const &[key, value] : param)
            Create(L, key, value);
    }

    Ring(int L, uniformParameters<T> &param)
    {
        for (auto const &[key, value] : param)
            Create(L, key, value);
    }
};

} // namespace solid

#endif