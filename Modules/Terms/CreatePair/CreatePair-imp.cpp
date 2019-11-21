/**
 * @file CreatePair-imp.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Create Pair term template initialization
 * @version 0.100.0
 * @date 2019-11-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "CreatePair.cpp"

namespace solid
{

// ***************************
// Fermions
// ***************************
template void CreatePairTermFermions::FillElements<arma::Mat, double>(QuantumSystem<arma::Mat, double> &qSystem);
template void CreatePairTermFermions::FillElements<arma::Mat, arma::cx_double>(QuantumSystem<arma::Mat, arma::cx_double> &qSystem);
template void CreatePairTermFermions::FillElements<arma::SpMat, double>(QuantumSystem<arma::SpMat, double> &qSystem);
template void CreatePairTermFermions::FillElements<arma::SpMat, arma::cx_double>(QuantumSystem<arma::SpMat, arma::cx_double> &qSystem);

} // namespace solid