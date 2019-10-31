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

/// Mat<cx_double> overload
template <>
QuantumState<cx_double> Eigensolver::FindGroundState(QuantumSystem<arma::Mat, cx_double> &qSystem)
{
    arma::Mat<cx_double> eigvec;
    arma::Col<double> eigval;
    Info::vTime("starting eig_sym() ...");
    eig_sym(eigval, eigvec, qSystem.hamiltonian.matrixElements);
    Info::vMessage("done!");
    QuantumState<cx_double> qState = eigvec.col(0);
    qState.energy = eigval(0);
    return qState;
}

// sparse

// sparse solver options default

int Eigensolver::SparseSolverOptions::numberOfEigenvalues = 10;
std::string Eigensolver::SparseSolverOptions::eigenvalueTarget = "sa";
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

/// SpMat<cx_double> overload
template <>
QuantumState<cx_double> Eigensolver::FindGroundState(QuantumSystem<arma::SpMat, cx_double> &qSystem)
{
    // TODO
    QuantumState<cx_double> ret;
    ret.set_size(qSystem.hamiltonian.matrixElements.n_rows);
    return ret;
}

} // namespace solid