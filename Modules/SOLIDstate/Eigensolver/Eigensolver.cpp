#include "Eigensolver.hpp"

#include <armadillo>

#include "../QuantumState/QuantumState.hpp"
#include "../QuantumSystem/QuantumSystem.hpp"

namespace solid
{

// dense

/// Mat<double> overload
template <>
QuantumState<double> Eigensolver::FindGroundState(QuantumSystem<arma::Mat, double> &qSystem)
{
    arma::Mat<double> eigvec;
    arma::Col<double> eigval;
    Info::vTime("starting eig_sym() ...");
    eig_sym(eigval, eigvec, qSystem.hamiltonian.matrixElements);
    Info::vMessage("done!");
    QuantumState<double> qState = eigvec.col(0);
    qState.energy = eigval(0);
    return qState;
}

/// Mat<arma::cx_double> overload
template <>
QuantumState<arma::cx_double> Eigensolver::FindGroundState(QuantumSystem<arma::Mat, arma::cx_double> &qSystem)
{
    arma::Mat<arma::cx_double> eigvec;
    arma::Col<double> eigval;
    Info::vTime("starting eig_sym() ...");
    eig_sym(eigval, eigvec, qSystem.hamiltonian.matrixElements);
    Info::vMessage("done!");
    QuantumState<arma::cx_double> qState = eigvec.col(0);
    qState.energy = eigval(0);
    return qState;
}

// sparse

// sparse solver options default

int Eigensolver::SparseSolverOptions::numberOfEigenvalues = 10;
std::string Eigensolver::SparseSolverOptions::eigenvalueTarget = "sa";
std::string Eigensolver::SparseSolverOptions::eigenvalueComplexTarget = "sr";
double Eigensolver::SparseSolverOptions::tolerance = 0.;

/// SpMat<double> overload
template <>
QuantumState<double> Eigensolver::FindGroundState(QuantumSystem<arma::SpMat, double> &qSystem)
{
    arma::Mat<double> eigvec;
    arma::Col<double> eigval;
    int numEig = SparseSolverOptions::numberOfEigenvalues;
    int num = qSystem.hamiltonian.matrixElements.n_cols;
    numEig = numEig > num ? num - 1 : numEig;
    double tol = SparseSolverOptions::tolerance;
    std::string target = SparseSolverOptions::eigenvalueTarget;
    Info::Eigenmessage("eigs_sym()", numEig, target, tol);
    eigs_sym(eigval, eigvec, qSystem.hamiltonian.matrixElements,
             numEig, target.c_str(), tol);
    Info::vMessage("done!");
    QuantumState<double> qState = eigvec.col(0);
    qState.energy = eigval(0);
    return qState;
}

/// SpMat<arma::cx_double> overload
template <>
QuantumState<arma::cx_double> Eigensolver::FindGroundState(QuantumSystem<arma::SpMat, arma::cx_double> &qSystem)
{
    arma::Mat<arma::cx_double> eigvec;
    arma::Col<arma::cx_double> eigval;
    int numEig = SparseSolverOptions::numberOfEigenvalues;
    int num = qSystem.hamiltonian.matrixElements.n_cols;
    numEig = numEig > num ? num - 1 : numEig;
    double tol = SparseSolverOptions::tolerance;
    std::string target = SparseSolverOptions::eigenvalueComplexTarget;
    Info::Eigenmessage("eigs_sym()", numEig, target, tol);
    eigs_gen(eigval, eigvec, qSystem.hamiltonian.matrixElements,
             numEig, target.c_str(), tol);
    Info::vMessage("done!");
    QuantumState<arma::cx_double> qState = eigvec.col(0);
    qState.energy = real(eigval(0)); // WARNING!
    return qState;
}

} // namespace solid