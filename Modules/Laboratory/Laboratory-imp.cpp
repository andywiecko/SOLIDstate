/**
 * @file Laboratory-imp.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Laboratory class initialization
 * @version 0.100.0
 * @date 2019-10-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Laboratory.cpp"

namespace solid
{

template double Laboratory::Measure(QuantumSystem<arma::Mat, double> &, QuantumState<double> &);
template arma::cx_double Laboratory::Measure(QuantumSystem<arma::Mat, arma::cx_double> &, QuantumState<arma::cx_double> &);
template double Laboratory::Measure(QuantumSystem<arma::SpMat, double> &, QuantumState<double> &);
template arma::cx_double Laboratory::Measure(QuantumSystem<arma::SpMat, arma::cx_double> &, QuantumState<arma::cx_double> &);

}