#include "Eigensolver.hpp"

#include <armadillo>

#include "../QuantumState/QuantumState.hpp"
#include "../QuantumSystem/QuantumSystem.hpp"

namespace solid
{

template <>
QuantumState<double> Eigensolver::FindGroundState(QuantumSystem<arma::Mat, double> &qSystem)
{
    arma::Mat<double> eigvec;
    arma::Col<double> eigval;
    eig_sym(eigval, eigvec, qSystem.hamiltonian.matrixElements);
    QuantumState<double> qState;
    qState.set_size(eigvec.n_rows);
    qState.col(0) = eigvec.col(0);
    qState.energy = eigval(0);
    return qState;
}

template <>
QuantumState<cx_double> Eigensolver::FindGroundState(QuantumSystem<arma::Mat, cx_double> &qSystem)
{
    arma::Mat<cx_double> eigvec;
    arma::Col<double> eigval;
    eig_sym(eigval, eigvec, qSystem.hamiltonian.matrixElements);
    QuantumState<cx_double> qState;
    qState.set_size(eigvec.n_rows);
    qState.col(0) = eigvec.col(0);
    qState.energy = eigval(0);
    return qState;
}

template <>
QuantumState<double> Eigensolver::FindGroundState(QuantumSystem<arma::SpMat, double> &qSystem)
{
    // TODO
}

template <>
QuantumState<cx_double> Eigensolver::FindGroundState(QuantumSystem<arma::SpMat, cx_double> &qSystem)
{
    // TODO
}

} // namespace solid