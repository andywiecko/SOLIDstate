/**
 * @file QuantumDynamics.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Quantum Dynamics class header
 * @version 0.100.0
 * @date 2019-11-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef QUANTUMDYNAMICS_HPP
#define QUANTUMDYNAMICS_HPP

#include <armadillo>

#include "../QuantumSystem/QuantumSystem.hpp"
#include "../QuantumState/QuantumState.hpp"
#include "../Parameters/Parameters.hpp"
#include "../Hamiltonian/TermsEnabled.hpp"
#include "DynamicsSchedule.hpp"

namespace solid
{

/**
 * @brief Quantum Dynamics class
 * 
 * It uses QuantumSystem QuantumState and DynamicsSchedule MeasurmentSchedule
 * to study dynamics of initial state by performing evolution on the given path
 * of selected IHamiltonian/Operator
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type of QuantumSystem: double, std::complex<double> are supported
 * @tparam T3 data type of QuantumState: double, std::complex<double> are supported
 */
template <template <typename> class T1, typename T2, typename T3>
class QuantumDynamics
{

public:
    void Create(
        QuantumSystem<T1, T2> &qSystem,
        QuantumState<T2> &initQuantumState,
        DynamicsSchedule<arma::SpMat<T2>> &dynSchedule,
        MeasurementSchedule<T1, T2, T3> &mesSchedule)
    {
        terms = qSystem.hamiltonian.termsEnabled;
        quantumSystem = qSystem;
        quantumState = initQuantumState;
        param = qSystem.parameters;
        dynamicsSchedule = dynSchedule;
        measurementSchedule = mesSchedule;
    }

    void Run();

private:
    void LoadParameters();

    void Propagate();

    void Measure();

    double time;
    TermsEnabled terms;
    QuantumState<T3> quantumState;
    QuantumSystem<T1, T2> quantumSystem;
    Parameters<T2> param;
    DynamicsSchedule<arma::SpMat<T2>> dynamicsSchedule;
    MeasurementSchedule<T1, T2, T3> measurementSchedule;
};

} // namespace solid
#endif