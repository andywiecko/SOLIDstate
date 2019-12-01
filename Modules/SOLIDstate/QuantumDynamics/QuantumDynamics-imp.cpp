/**
 * @file QuantumDynamics-imp.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief QuantumDynamics class template initialization
 * @version 0.100.0
 * @date 2019-11-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "QuantumDynamics.cpp"

namespace solid
{

// LoadParameters
template void QuantumDynamics<arma::Mat, double, double>::LoadParameters();
template void QuantumDynamics<arma::Mat, double, arma::cx_double>::LoadParameters();
template void QuantumDynamics<arma::Mat, arma::cx_double, double>::LoadParameters();
template void QuantumDynamics<arma::Mat, arma::cx_double, arma::cx_double>::LoadParameters();
template void QuantumDynamics<arma::SpMat, double, double>::LoadParameters();
template void QuantumDynamics<arma::SpMat, double, arma::cx_double>::LoadParameters();
template void QuantumDynamics<arma::SpMat, arma::cx_double, double>::LoadParameters();
template void QuantumDynamics<arma::SpMat, arma::cx_double, arma::cx_double>::LoadParameters();

// Run
template void QuantumDynamics<arma::Mat, double, double>::Run();
template void QuantumDynamics<arma::Mat, double, arma::cx_double>::Run();
template void QuantumDynamics<arma::Mat, arma::cx_double, double>::Run();
template void QuantumDynamics<arma::Mat, arma::cx_double, arma::cx_double>::Run();
template void QuantumDynamics<arma::SpMat, double, double>::Run();
template void QuantumDynamics<arma::SpMat, double, arma::cx_double>::Run();
template void QuantumDynamics<arma::SpMat, arma::cx_double, double>::Run();
template void QuantumDynamics<arma::SpMat, arma::cx_double, arma::cx_double>::Run();

// Propagate
template void QuantumDynamics<arma::Mat, double, double>::Propagate();
template void QuantumDynamics<arma::Mat, double, arma::cx_double>::Propagate();
template void QuantumDynamics<arma::Mat, arma::cx_double, double>::Propagate();
template void QuantumDynamics<arma::Mat, arma::cx_double, arma::cx_double>::Propagate();
template void QuantumDynamics<arma::SpMat, double, double>::Propagate();
template void QuantumDynamics<arma::SpMat, double, arma::cx_double>::Propagate();
template void QuantumDynamics<arma::SpMat, arma::cx_double, double>::Propagate();
template void QuantumDynamics<arma::SpMat, arma::cx_double, arma::cx_double>::Propagate();

// Measure
template void QuantumDynamics<arma::Mat, double, double>::Measure();
template void QuantumDynamics<arma::Mat, double, arma::cx_double>::Measure();
template void QuantumDynamics<arma::Mat, arma::cx_double, double>::Measure();
template void QuantumDynamics<arma::Mat, arma::cx_double, arma::cx_double>::Measure();
template void QuantumDynamics<arma::SpMat, double, double>::Measure();
template void QuantumDynamics<arma::SpMat, double, arma::cx_double>::Measure();
template void QuantumDynamics<arma::SpMat, arma::cx_double, double>::Measure();
template void QuantumDynamics<arma::SpMat, arma::cx_double, arma::cx_double>::Measure();

} // namespace solid