#include "QuantumState.hpp"

namespace solid
{
template <>
template <>
QuantumState<arma::cx_double>::QuantumState(QuantumState<double> &qState)
{
    
    this->vector = arma::Col<arma::cx_double>(qState.vector, arma::zeros<arma::Col<double>>(qState.vector.size()));
}

template QuantumState<double>::QuantumState();
template QuantumState<arma::cx_double>::QuantumState();

} // namespace solid