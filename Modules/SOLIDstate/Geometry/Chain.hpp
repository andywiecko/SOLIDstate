/**
 * @file Chain.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Chain (IGeometry implementation) class header
 * @version 0.100.0
 * @date 2019-11-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef GEOMETRY_CHAIN_HPP
#define GEOMETRY_CHAIN_HPP

#include "Geometry.hpp"
#include "../Terms/TermsTypeConverter.hpp"
#include "../Terms/TermsTypeEnum.hpp"
#include <armadillo>

namespace solid
{

/**
 * @brief Chain (IGeometry implementation) class
 * 
 * Example (\f$L=4\f$):
 *
   \verbatim
   o --- o --- o --- o --- o
   ^     ^                 ^
   |_____|                 |
      NonlocalTerms        LocalTerms
   \endverbatim
 * 
 * @tparam T data type: double, std::complex<double> are supported
 */
template <typename T>
class Chain : public Geometry<T>, public IGeometry<T>
{
    using Geometry<T>::parameters;

private:

    /**
     * @brief Chain Adjacency function for Nonlocal Terms
     * 
     * @param L number of sites
     * @param value parameter value (t,V,delta,...)
     * @return arma::SpMat<T> Parameters matrix
     */
    arma::SpMat<T> ChainAdjacency(int L,T value)
    {
        arma::SpMat<T> ret(L, L);
        for (int i = 0; i < L - 1; i++)
            ret(i, i + 1) = value;
        return ret;
    }

    /**
     * @brief Create Chain (IGeometry) object
     * 
     * @param L number of sites
     * @param key parameter label
     * @param value value of the parameter
     */
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
    /**
     * @brief Construct a new Chain object
     * 
     * @param L number of sites
     * @param param map with Parameters
     */
    Chain(int L, initList<T> param)
    {
        for (auto const &[key, value] : param)
            Create(L, key, value);
    }

    /**
     * @brief Construct a new Chain object
     * 
     * @param L number of sites
     * @param param map with Parameters
     */
    Chain(int L, uniformParameters<T> &param)
    {
        for (auto const &[key, value] : param)
            Create(L, key, value);
    }
};

} // namespace solid

#endif