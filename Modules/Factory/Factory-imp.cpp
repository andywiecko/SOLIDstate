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
template KitaevHamiltonian<  Mat,    double> Factory::CreateHamiltonian<KitaevHamiltonian<  Mat,    double>>();
template KitaevHamiltonian<  Mat, cx_double> Factory::CreateHamiltonian<KitaevHamiltonian<  Mat, cx_double>>();
template KitaevHamiltonian<SpMat,    double> Factory::CreateHamiltonian<KitaevHamiltonian<SpMat,    double>>();
template KitaevHamiltonian<SpMat, cx_double> Factory::CreateHamiltonian<KitaevHamiltonian<SpMat, cx_double>>();

// ***************************
// Observables
// ***************************
// Particle Number Operator
template ParticleNumberOperator<  Mat,    double> Factory::CreateObservable<ParticleNumberOperator<  Mat,    double>>(int);
template ParticleNumberOperator<  Mat, cx_double> Factory::CreateObservable<ParticleNumberOperator<  Mat, cx_double>>(int);
template ParticleNumberOperator<SpMat,    double> Factory::CreateObservable<ParticleNumberOperator<SpMat,    double>>(int);
template ParticleNumberOperator<SpMat, cx_double> Factory::CreateObservable<ParticleNumberOperator<SpMat, cx_double>>(int);
// Parity Operator
template ParityOperator<  Mat,    double> Factory::CreateObservable<ParityOperator<  Mat,    double>>(int);
template ParityOperator<  Mat, cx_double> Factory::CreateObservable<ParityOperator<  Mat, cx_double>>(int);
template ParityOperator<SpMat,    double> Factory::CreateObservable<ParityOperator<SpMat,    double>>(int);
template ParityOperator<SpMat, cx_double> Factory::CreateObservable<ParityOperator<SpMat, cx_double>>(int);

}