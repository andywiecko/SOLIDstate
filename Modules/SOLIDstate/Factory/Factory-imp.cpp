/**
 * @file Factory-imp.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Factory templates initialization
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Factory.cpp"

namespace solid
{

// ***************************
// Ensembles 
// ***************************
template Canonical Factory::CreateEnsemble<Canonical>(int, int);
template GrandCanonical Factory::CreateEnsemble<GrandCanonical>(int);
template ParityGrandCanonical Factory::CreateEnsemble<ParityGrandCanonical>(int, int);

// ***************************
// Hamiltonians 
// ***************************
// Kitaev Hamiltonian
template KitaevHamiltonian<  arma::Mat,    double> Factory::CreateHamiltonian<KitaevHamiltonian<  arma::Mat,    double>>();
template KitaevHamiltonian<  arma::Mat, arma::cx_double> Factory::CreateHamiltonian<KitaevHamiltonian<  arma::Mat, arma::cx_double>>();
template KitaevHamiltonian<arma::SpMat,    double> Factory::CreateHamiltonian<KitaevHamiltonian<arma::SpMat,    double>>();
template KitaevHamiltonian<arma::SpMat, arma::cx_double> Factory::CreateHamiltonian<KitaevHamiltonian<arma::SpMat, arma::cx_double>>();

// ***************************
// Observables
// ***************************
// Particle Number Operator
template ParticleNumberOperator<  arma::Mat,    double> Factory::CreateObservable<ParticleNumberOperator<  arma::Mat,    double>>(int);
template ParticleNumberOperator<  arma::Mat, arma::cx_double> Factory::CreateObservable<ParticleNumberOperator<  arma::Mat, arma::cx_double>>(int);
template ParticleNumberOperator<arma::SpMat,    double> Factory::CreateObservable<ParticleNumberOperator<arma::SpMat,    double>>(int);
template ParticleNumberOperator<arma::SpMat, arma::cx_double> Factory::CreateObservable<ParticleNumberOperator<arma::SpMat, arma::cx_double>>(int);
// Parity Operator
template ParityOperator<  arma::Mat,    double> Factory::CreateObservable<ParityOperator<  arma::Mat,    double>>(int);
template ParityOperator<  arma::Mat, arma::cx_double> Factory::CreateObservable<ParityOperator<  arma::Mat, arma::cx_double>>(int);
template ParityOperator<arma::SpMat,    double> Factory::CreateObservable<ParityOperator<arma::SpMat,    double>>(int);
template ParityOperator<arma::SpMat, arma::cx_double> Factory::CreateObservable<ParityOperator<arma::SpMat, arma::cx_double>>(int);

}