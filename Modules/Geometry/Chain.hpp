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
            for (int i = 0; i < L - 1; i++)
                tmp(i, i + 1) = value;
            tmp = symmatu(tmp);
            parameters[key] = tmp;
            break;
        case TermsTypeEnum::NonlocalDiagonal:
            for (int i = 0; i < L - 1; i++)
                tmp(i, i + 1) = value;
            parameters[key] = tmp;
            break;
        case TermsTypeEnum::NonlocalNondiagonal:
            for (int i = 0; i < L - 1; i++)
                tmp(i, i + 1) = value;
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