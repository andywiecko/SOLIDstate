/**
 * @file QuantumSystem-imp.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Quantum System template initialization
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "QuantumSystem.cpp"

namespace solid
{
// ***************************
// Fill 
// ***************************
template void QuantumSystem<arma::  Mat,   double>::Fill();
template void QuantumSystem<arma::  Mat,cx_double>::Fill();
template void QuantumSystem<arma::SpMat,   double>::Fill();
template void QuantumSystem<arma::SpMat,cx_double>::Fill();

// ***************************
// Ensembles 
// ***************************
// Canonical
template void QuantumSystem<arma::  Mat,    double>::SelectEnsemble<Canonical>(int, int);
template void QuantumSystem<arma::  Mat, cx_double>::SelectEnsemble<Canonical>(int, int);
template void QuantumSystem<arma::SpMat,    double>::SelectEnsemble<Canonical>(int, int);
template void QuantumSystem<arma::SpMat, cx_double>::SelectEnsemble<Canonical>(int, int);
// Grand Canonical
template void QuantumSystem<arma::  Mat,    double>::SelectEnsemble<GrandCanonical>(int);
template void QuantumSystem<arma::  Mat, cx_double>::SelectEnsemble<GrandCanonical>(int);
template void QuantumSystem<arma::SpMat,    double>::SelectEnsemble<GrandCanonical>(int);
template void QuantumSystem<arma::SpMat, cx_double>::SelectEnsemble<GrandCanonical>(int);
// Parity Grand Canonical
template void QuantumSystem<arma::  Mat,    double>::SelectEnsemble<ParityGrandCanonical>(int, int);
template void QuantumSystem<arma::  Mat, cx_double>::SelectEnsemble<ParityGrandCanonical>(int, int);
template void QuantumSystem<arma::SpMat,    double>::SelectEnsemble<ParityGrandCanonical>(int, int);
template void QuantumSystem<arma::SpMat, cx_double>::SelectEnsemble<ParityGrandCanonical>(int, int);

} // namespace solid