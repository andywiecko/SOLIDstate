/**
 * @file Ring.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Ring (IGeometry implementation) class header
 * @version 0.100.0
 * @date 2019-11-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef GEOMETRY_RING_HPP
#define GEOMETRY_RING_HPP

#include "Geometry.hpp"
#include "../Misc/Symmatgen.hpp"

namespace solid
{

/**
 * @brief Ring (IGeometry implementation) class
 * 
 * Example (\f$L=4\f$):
 *
   \verbatim
   ------------------------- 
   |                       |
   o --- o --- o --- o --- o
   ^     ^                 ^
   |_____|                 |
      NonlocalTerms        LocalTerms
   \endverbatim
 * 
 * @tparam T data type: double, std::complex<double> are supported
 */
template <typename T>
class Ring : public Geometry<T>, public IGeometry<T>
{
    using Geometry<T>::parameters;

private:
    /**
     * @brief Ring Adjacency function for Nonlocal Terms
     * 
     * @param L number of sites
     * @param value parameter value (t,V,delta,...)
     * @return arma::SpMat<T> Parameters matrix
     */
    arma::SpMat<T> RingAdjacency(int L, T value)
    {
        arma::SpMat<T> ret(L, L);
        for (int i = 0; i < L; i++)
            ret(i, (i + 1) % L) = value;
        return ret;
    }

    /**
     * @brief Create Ring (IGeometry) object
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
    /**
     * @brief Construct a new Ring object
     * 
     * @param L number of sites
     * @param param map with Parameters
     */
    Ring(int L, initList<T> param)
    {
        for (auto const &[key, value] : param)
            Create(L, key, value);
    }

    /**
     * @brief Construct a new Ring object
     * 
     * @param L number of sites
     * @param param map with Parameters
     */
    Ring(int L, uniformParameters<T> &param)
    {
        for (auto const &[key, value] : param)
            Create(L, key, value);
    }
};

} // namespace solid

#endif