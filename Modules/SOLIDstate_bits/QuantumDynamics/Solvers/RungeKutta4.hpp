/**
 * @file RungeKutta4.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Runge Kutta 4 method class header
 * @version 0.100.0
 * @date 2019-11-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef QUANTUMDYNAMICS_SOLVERS_RUNGEKUTTA4_HPP
#define QUANTUMDYNAMICS_SOLVERS_RUNGEKUTTA4_HPP
#include <armadillo>

#include "../QuantumDynamics.hpp"
#include "QuantumDynamicSolver.hpp"

namespace solid
{

/**
 * @brief Runge--Kutta forth order method [(RK4)](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods) for solving differentional equations
 * 
 * Propagation of the state is obtained in the following way:
 * \f[
 *      |\psi(t+\Delta t)\rangle = |\psi(t)\rangle + \frac16(|k_1\rangle+2|k_2\rangle+2|k_3\rangle+|k_4\rangle), 
 * \f]
 * where corresponding states \f$|k_1\rangle,\,|k_2\rangle,\,|k_3\rangle,\,|k_4\rangle\f$ are given by:
 *  * \f$|k_1\rangle =-i\Delta t \hat H(t) |\psi(t)\rangle \f$
 *  * \f$|k_2\rangle =-i\Delta t \hat H(t+\Delta t/2) (|\psi(t)\rangle +\frac12|k_1\rangle)\f$
 *  * \f$|k_3\rangle =-i\Delta t \hat H(t+\Delta t/2) (|\psi(t)\rangle +\frac12|k_2\rangle)\f$
 *  * \f$|k_4\rangle =-i\Delta t \hat H(t+\Delta t) (|\psi(t)\rangle +|k_3\rangle)\f$
 */
template <template <typename> class T1, typename T2, typename T3>
class RK4 : public IQuantumDynamicSolver<T1, T2, T3>
{
public:

    /**
     * @brief label, default = "rk4"
     */
    inline static constexpr auto label = "rk4";

    /**
     * @brief Get the Label object (IQuantumDynamicSolver override)
     * 
     * @return std::string label
     */
    std::string getLabel() override
    {
        return label;
    }

    /**
     * @brief Propagate the state \f$|\psi\rangle\f$ (IQuantumDynamicSolver override)
     * 
     * @param time current time
     * @param dtime time step
     * @param qDynamics QuantumDynamics<T1,T2,T3> object
     */
    void Propagate(double time, double dtime, QuantumDynamics<T1, T2, T3> &qDynamics)
    {

        arma::cx_double I(0, 1);
        arma::cx_vec k1, k2, k3, k4;

        qDynamics.quantumSystem.Fill();
        k1 = -I * dtime * qDynamics.quantumSystem.hamiltonian.matrixElements * qDynamics.quantumState.vector;
        time += 0.5 * dtime;
        qDynamics.LoadParameters();
        qDynamics.quantumSystem.Fill();
        k2 = -I * dtime * qDynamics.quantumSystem.hamiltonian.matrixElements * (qDynamics.quantumState.vector + 0.5 * k1);
        k3 = -I * dtime * qDynamics.quantumSystem.hamiltonian.matrixElements * (qDynamics.quantumState.vector + 0.5 * k2);
        time += 0.5 * dtime;
        qDynamics.LoadParameters();
        qDynamics.quantumSystem.Fill();
        k4 = -I * dtime * qDynamics.quantumSystem.hamiltonian.matrixElements * (qDynamics.quantumState.vector + k3);
        qDynamics.quantumState.vector += 1. / 6. * (k1 + 2 * k2 + 2 * k3 + k4);
    }
};

} // namespace solid

#endif