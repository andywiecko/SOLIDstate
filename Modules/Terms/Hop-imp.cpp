/**
 * @file Hop-imp.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Hop term template initialization
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Hop.cpp"

namespace solid
{

// ***************************
// Fermions
// ***************************
template void HopTermFermions::FillElements<arma::Mat, double>(QuantumSystem<arma::Mat, double> &qSystem);
template void HopTermFermions::FillElements<arma::Mat, arma::cx_double>(QuantumSystem<arma::Mat, arma::cx_double> &qSystem);
template void HopTermFermions::FillElements<arma::SpMat, double>(QuantumSystem<arma::SpMat, double> &qSystem);
template void HopTermFermions::FillElements<arma::SpMat, arma::cx_double>(QuantumSystem<arma::SpMat, arma::cx_double> &qSystem);

} // namespace solid