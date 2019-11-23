#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Geometry.hpp"
#include "../Terms/TermsTypeConverter.hpp"
#include "../Terms/TermsTypeEnum.hpp"
#include <armadillo>

namespace solid
{

template <typename T>
class Chain : public Geometry<T>, public IGeometry<T>
{
    using Geometry<T>::parameters;

private:
    arma::SpMat<T> ChainAdjacency(int L,T value)
    {
        arma::SpMat<T> ret(L, L);
        for (int i = 0; i < L - 1; i++)
            ret(i, i + 1) = value;
        return ret;
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
            tmp = ChainAdjacency(L,value);
            tmp = symmatu(tmp);
            parameters[key] = tmp;
            break;
        case TermsTypeEnum::NonlocalDiagonal:
            tmp = ChainAdjacency(L,value);
            parameters[key] = tmp;
            break;
        case TermsTypeEnum::NonlocalNondiagonal:
            tmp = ChainAdjacency(L,value);
            tmp = symmatu(tmp);
            parameters[key] = tmp;
            break;
        }
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