#ifndef GEOMETRY_RING_HPP
#define GEOMETRY_RING_HPP

#include "Geometry.hpp"

namespace solid
{

template <typename T>
class Ring : public Geometry<T>, public IGeometry<T>
{
    using Geometry<T>::parameters;

private:
    arma::SpMat<T> RingAdjacency(int L, T value)
    {
        arma::SpMat<T> ret(L, L);
        for (int i = 0; i < L; i++)
            ret(i, (i + 1) % L) = value;
        return ret;
    }

    // TODO move to misc function file
    void Symmatgen(arma::SpMat<T>& mat)
    {
        mat += mat.t();
    }

    void Create(int L, std::string key, T value) override
    {
        arma::SpMat<T> tmp(L, L);
        switch (TermsTypeConverter::dict[key])
        {
        case TermsTypeEnum::LocalDiagonal:
            for (int i = 0; i < L; i++)
                tmp(i, i) = value;
            parameters[key] = tmp;
            break;
        case TermsTypeEnum::LocalNondiagonal:
            tmp = RingAdjacency(L, value);
            Symmatgen(tmp);
            parameters[key] = tmp;
            break;
        case TermsTypeEnum::NonlocalDiagonal:
            tmp = RingAdjacency(L, value);
            parameters[key] = tmp;
            break;
        case TermsTypeEnum::NonlocalNondiagonal:
            tmp = RingAdjacency(L, value);
            Symmatgen(tmp);
            parameters[key] = tmp;
            break;
        }
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