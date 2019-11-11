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

    /**
     * @brief QuantumDynamics constructor
     * 
     * @param qSystem IHamiltonian/Operator to evolve
     * @param initQuantumState initial QuantumState
     * @param dynSchedule DynamicsSchedule (how QuantumSystem Parameters changes during the time)
     * @param mesSchedule MeasurementSchedule (when and what to measure)
     */
    void Create(
        QuantumSystem<T1, T2> &qSystem,
        QuantumState<T3> &initQuantumState,
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

    /**
     * @brief Run the evolution
     */
    void Run();

private:
    /**
     * @brief Loads the parameters with respect to time
     */
    void LoadParameters();

    /**
     * @brief Propagates the state
     */
    void Propagate();

    /**
     * @brief performs MeasurmentSchedule
     */
    void Measure();

    double time;                                         /*!< current time of the evolution */
    TermsEnabled terms;                                  /*!< copy of active terms in QuantumSystem */
    QuantumState<T3> quantumState;                       /*!< current QuantumState at given time */
    QuantumSystem<T1, T2> quantumSystem;                 /*!< current QuantumSystem or Observable at given time */
    Parameters<T2> param;                                /*!< copy of active parameters in QuantumSystem */
    DynamicsSchedule<arma::SpMat<T2>> dynamicsSchedule;  /*!< DynamicsSchedule for QuantumSystem parameters */
    MeasurementSchedule<T1, T2, T3> measurementSchedule; /*!< MeasurmentSchedule: when and what to measure */
};

} // namespace solid
#endif