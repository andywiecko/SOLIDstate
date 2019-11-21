/**
 * @file TermsEnumConverter.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Terms Enum Converter class header
 * @version 0.100.0
 * @date 2019-11-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TERMSENUMCONVERTER_HPP
#define TERMSENUMCONVERTER_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
#include "../Terms/TermsEnum.hpp"
#include "../Terms/Hop/Hop.hpp"
#include "../Terms/OneBodyInteraction/OneBodyInteraction.hpp"
#include "../Terms/TwoBodyInteraction/TwoBodyInteraction.hpp"
#include "../Terms/CreatePair/CreatePair.hpp"

#include <map>
#include <functional>

namespace solid
{

/**
 * @brief typedef for map between TermsEnum and corresponding function
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 */
template <template <typename> class T1, typename T2>
using mapTermsFunction = std::map<TermsEnum, std::function<void(QuantumSystem<T1, T2> &)>>;

/**
 * @brief static class for converting TermEnum into ITerm implementations
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 */
template <template <typename> class T1, typename T2>
class TermsEnumConverter
{

    /**
     * @brief Create a Dict object
     * 
     * @return mapTermsFunction<T1, T2> 
     */
    static mapTermsFunction<T1, T2> CreateDict();

public:
    /**
     * @brief dictionary 
     */
    static mapTermsFunction<T1, T2> dict;

};

} // namespace solid

#endif