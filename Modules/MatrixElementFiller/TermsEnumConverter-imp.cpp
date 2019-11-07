#include "TermsEnumConverter.cpp"
#include<armadillo>
namespace solid
{

template std::map<TermsEnum, std::function<void(QuantumSystem<arma::Mat, double>&)>> TermsEnumConverter<arma::Mat,double>::dict;
template std::map<TermsEnum, std::function<void(QuantumSystem<arma::Mat, arma::cx_double>&)>> TermsEnumConverter<arma::Mat,arma::cx_double>::dict;
template std::map<TermsEnum, std::function<void(QuantumSystem<arma::SpMat, double>&)>> TermsEnumConverter<arma::SpMat,double>::dict;
template std::map<TermsEnum, std::function<void(QuantumSystem<arma::SpMat, arma::cx_double>&)>> TermsEnumConverter<arma::SpMat,arma::cx_double>::dict;

//template void TermsEnumConverter<arma::Mat,double>::CreateDict();
//template void TermsEnumConverter<arma::Mat,arma::cx_double>::CreateDict();
//template void TermsEnumConverter<arma::SpMat,double>::CreateDict();
//template std::function<void(QuantumSystem<arma::SpMat, arma::cx_double>)>> TermsEnumConverter<arma::SpMat,arma::cx_double>::CreateDict();

}