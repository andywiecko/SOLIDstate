/**
 * @file AdiabaticSolver.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Adiabatic Solver (IQuantumDynamicSolver implementation) header
 * @version 0.100.0
 * @date 2019-11-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef QUANTUMDYNAMICS_SOLVERS_ADIABATICSOLVER_HPP
#define QUANTUMDYNAMICS_SOLVERS_ADIABATICSOLVER_HPP

#include <armadillo>

#include "../../QuantumState/QuantumState.hpp"
#include "../../Eigensolver/Eigensolver.hpp"
#include "../QuantumDynamics.hpp"
#include "QuantumDynamicSolver.hpp"

namespace solid
{

/**
 * @brief Adiabatic Solver header
 * 
 * It propagates the state assuming that \f$|\psi\rangle\f$ is a ground state \f$|GS\rangle\f$ on the entire
 * dynamics path:
 * \f[
 * \hat H | GS \rangle = E_0 | GS \rangle
 * \f]
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type of QuantumSystem: double, std::complex<double> are supported
 * @tparam T3 data type of QuantumState: double, std::complex<double> are supported
 */
template <template <typename> class T1, typename T2, typename T3>
class AdiabaticSolver : public IQuantumDynamicSolver<T1, T2, T3>
{
public:

    /**
     * @brief label, default = "adia"
     */
    inline static constexpr auto label = "adia";

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
        qDynamics.quantumSystem.Fill();
        // TODO remove tmp variable and add conversion in QuantumState
        QuantumState<T2> tmp = Eigensolver::FindGroundState(qDynamics.quantumSystem);
        qDynamics.quantumState = tmp;
    }
};

} // namespace solid

#endif