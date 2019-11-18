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

template <template <typename> class T1, typename T2, typename T3>
typename std::conditional<std::is_same<T2, arma::cx_double>::value || std::is_same<T3, arma::cx_double>::value, arma::cx_double, double>::type
Laboratory::Measure(QuantumSystem<T1, T2> &qSystem, QuantumState<T3> &qState)
{
    Info::vTime("measuring...");
    auto ret = arma::as_scalar(qState.vector.t() * qSystem.hamiltonian.matrixElements * qState.vector);
    Info::vMessage("done!");
    return ret;
}

} // namespace solid
