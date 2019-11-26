/**
 * @file ParametersChecker.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Parameters Checker class header
 * @version 0.100.0
 * @date 2019-11-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef PARAMETERS_PARAMETERSCHECKER_HPP
#define PARAMETERS_PARAMETERSCHECKER_HPP

#include <armadillo>

#include "Parameters.hpp"
#include "../Terms/TermsTypeConverter.hpp"
#include "../Terms/TermsTypeEnum.hpp"

namespace solid
{

/**
 * @brief class useful for debugging of the Parameters
 */
class ParametersChecker
{
public:
    /**
     * @brief Check and fix for possible error in Parameters elements
     * 
     * @tparam T data type: double, std::complex<double> are supported
     * @param parameters Parameters< T > to check
     */
    template <typename T>
    static void Check(Parameters<T> &parameters);

private:

    /**
     * @brief Checker for LocalDiagonal TermsTypeEnum
     * 
     * @tparam T data type: double, std::complex<double> are supported
     * @param parameter to check
     */
    template <typename T>
    static void CheckLocalDiagonal(arma::SpMat<T> &parameter);

    /**
     * @brief Checker for LocalNondiagonal TermsTypeEnum
     * 
     * @tparam T data type: double, std::complex<double> are supported
     * @param parameter to check
     */
    template <typename T>
    static void CheckLocalNondiagonal(arma::SpMat<T> &parameter);

    /**
     * @brief Checker for NonlocalDiagonal TermsTypeEnum
     * 
     * @tparam T data type: double, std::complex<double> are supported
     * @param parameter to check
     */
    template <typename T>
    static void CheckNonlocalDiagonal(arma::SpMat<T> &parameter);

    /**
     * @brief Checker for NonlocalNondiagonal TermsTypeEnum
     * 
     * @tparam T data type: double, std::complex<double> are supported
     * @param parameter to check
     */
    template <typename T>
    static void CheckNonlocalNondiagonal(arma::SpMat<T> &parameter);
 
};

} // namespace solid

#endif