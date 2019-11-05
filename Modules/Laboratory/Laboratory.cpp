/**
 * @file Laboratory.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Laboratory class implementation
 * @version 0.100.0
 * @date 2019-10-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Laboratory.hpp"

namespace solid
{

template <template <typename> class T1, typename T2>
T2 Laboratory::Measure(QuantumSystem<T1, T2> &qSystem, QuantumState<T2> &qState)
{
    Info::vTime("measuring...");
    T2 ret = arma::as_scalar(qState.vector.t() * qSystem.hamiltonian.matrixElements * qState.vector);
    //T2 ret = arma::as_scalar(qState.t() * qSystem.hamiltonian.matrixElements * qState); // TODO remove Col conversion
    Info::vMessage("done!");
    return ret;
}

} // namespace solid
