/**
 * @file QuantumDynamicSolver.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief QuantumDynamicSolver interface header
 * @version 0.100.0
 * @date 2019-11-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef QUANTUMDYNAMICS_SOLVERS_QUANTUMDYNAMICSOLVER_HPP
#define QUANTUMDYNAMICS_SOLVERS_QUANTUMDYNAMICSOLVER_HPP

#include "../QuantumDynamics.hpp"
#include <string>

namespace solid
{

template <template <typename> class T1, typename T2, typename T3>
class QuantumDynamics; // [!] TODO remove this circular dependency (make interface for QuantumDynamics)!

/**
 * @brief Quantum Dynamic Solver interface.
 * 
 * It contains two purly virtual methods:
 * * getLabel() solver label getter
 * * Propagate() for state propagation
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type of QuantumSystem: double, std::complex<double> are supported
 * @tparam T3 data type of QuantumState: double, std::complex<double> are supported
 */
template <template <typename> class T1, typename T2, typename T3>
class IQuantumDynamicSolver
{
public:
    /**
     * @brief Get the Label object for QuantumDynamicSolver (virtual)
     * 
     * @return std::string Solver label
     */
    virtual std::string getLabel() = 0;

    /**
     * @brief Propagate the state \f$|\psi\rangle\f$
     * 
     * @param time current time
     * @param dtime time step
     * @param qDynamics QuantumDynamics<T1,T2,T3> object
     */
    virtual void Propagate(double time, double dtime, QuantumDynamics<T1, T2, T3> &qDynamics) = 0;

    virtual ~IQuantumDynamicSolver() {}
};

} // namespace solid

#endif