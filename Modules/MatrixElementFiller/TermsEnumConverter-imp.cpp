/**
 * @file TermsEnumConverter-imp.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Terms Enum Converter class template initialization
 * @version 0.100.0
 * @date 2019-11-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "TermsEnumConverter.cpp"
#include<armadillo>
namespace solid
{

template mapTermsFunction<arma::Mat, double> TermsEnumConverter<arma::Mat,double>::dict;
template mapTermsFunction<arma::Mat, arma::cx_double> TermsEnumConverter<arma::Mat,arma::cx_double>::dict;
template mapTermsFunction<arma::SpMat, double> TermsEnumConverter<arma::SpMat,double>::dict;
template mapTermsFunction<arma::SpMat, arma::cx_double> TermsEnumConverter<arma::SpMat,arma::cx_double>::dict;

}