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
template void QuantumSystem<arma::Mat, double>::Fill();
template void QuantumSystem<arma::Mat, arma::cx_double>::Fill();
template void QuantumSystem<arma::SpMat, double>::Fill();
template void QuantumSystem<arma::SpMat, arma::cx_double>::Fill();

// ***************************
// Ensembles
// ***************************
// Canonical
template void QuantumSystem<arma::Mat, double>::SelectEnsemble<Canonical>(int, int);
template void QuantumSystem<arma::Mat, arma::cx_double>::SelectEnsemble<Canonical>(int, int);
template void QuantumSystem<arma::SpMat, double>::SelectEnsemble<Canonical>(int, int);
template void QuantumSystem<arma::SpMat, arma::cx_double>::SelectEnsemble<Canonical>(int, int);
// Grand Canonical
template void QuantumSystem<arma::Mat, double>::SelectEnsemble<GrandCanonical>(int);
template void QuantumSystem<arma::Mat, arma::cx_double>::SelectEnsemble<GrandCanonical>(int);
template void QuantumSystem<arma::SpMat, double>::SelectEnsemble<GrandCanonical>(int);
template void QuantumSystem<arma::SpMat, arma::cx_double>::SelectEnsemble<GrandCanonical>(int);
// Parity Grand Canonical
template void QuantumSystem<arma::Mat, double>::SelectEnsemble<ParityGrandCanonical>(int, int);
template void QuantumSystem<arma::Mat, arma::cx_double>::SelectEnsemble<ParityGrandCanonical>(int, int);
template void QuantumSystem<arma::SpMat, double>::SelectEnsemble<ParityGrandCanonical>(int, int);
template void QuantumSystem<arma::SpMat, arma::cx_double>::SelectEnsemble<ParityGrandCanonical>(int, int);

// ***************************
// Hamiltonians
// ***************************
template void QuantumSystem<arma::Mat, double>::SelectHamiltonian<KitaevHamiltonian>();
template void QuantumSystem<arma::Mat, arma::cx_double>::SelectHamiltonian<KitaevHamiltonian>();
template void QuantumSystem<arma::SpMat, double>::SelectHamiltonian<KitaevHamiltonian>();
template void QuantumSystem<arma::SpMat, arma::cx_double>::SelectHamiltonian<KitaevHamiltonian>();

// ***************************
// Observables
// ***************************
// Particle Number Operator
template void QuantumSystem<arma::Mat, double>::SelectObservable<ParticleNumberOperator>(int);
template void QuantumSystem<arma::Mat, arma::cx_double>::SelectObservable<ParticleNumberOperator>(int);
template void QuantumSystem<arma::SpMat, double>::SelectObservable<ParticleNumberOperator>(int);
template void QuantumSystem<arma::SpMat, arma::cx_double>::SelectObservable<ParticleNumberOperator>(int);
// Parity Operator
template void QuantumSystem<arma::Mat, double>::SelectObservable<ParityOperator>(int);
template void QuantumSystem<arma::Mat, arma::cx_double>::SelectObservable<ParityOperator>(int);
template void QuantumSystem<arma::SpMat, double>::SelectObservable<ParityOperator>(int);
template void QuantumSystem<arma::SpMat, arma::cx_double>::SelectObservable<ParityOperator>(int);

} // namespace solid