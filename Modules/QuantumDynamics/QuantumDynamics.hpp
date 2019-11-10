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

// TODO make it as interface for different dynamics
template <template <typename> class T1, typename T2>
class QuantumDynamics
{

public:
    void Create(QuantumSystem<T1, T2> &qSystem,
                QuantumState<T2> &initQuantumState,
                DynamicsSchedule<arma::SpMat<T2>> &dynSchedule,
                MeasurementSchedule<T1, T2> &mesSchedule)
    {
        terms = qSystem.hamiltonian.termsEnabled;
        quantumSystem = qSystem;
        quantumState = initQuantumState;
        param = qSystem.parameters;
        dynamicsSchedule = dynSchedule;
        measurementSchedule = mesSchedule;
    }

private:
    void LoadParameters()
    {
        quantumSystem.hamiltonian.termsEnabled = terms;
        quantumSystem.parameters = param;
        for (const auto &[label, val] : dynamicsSchedule.dict)
        {
            //std::cout << label << std::endl;
            val(quantumSystem.parameters[label], time);
            //arma::mat(quantumSystem.parameters[label]).print(label + ":");
        }
    }
    void Propagate()
    {
        quantumSystem.Fill();
        //quantumSystem.hamiltonian.matrixElements.print("H=");
        // TODO RK4 or chebyshev...
    }
    void Measure()
    {
        measurementSchedule.Measure(quantumSystem, quantumState);
    }

public:
    void Run()
    {
        time = dynamicsSchedule.time_init;
        double dt = dynamicsSchedule.time_step;

        while (time <= dynamicsSchedule.time_final)
        {
            std::cout << "time=" << time << "   |   ";// << std::endl;
            LoadParameters();
            Propagate();
            if (measurementSchedule.timeToMeasure(time))
                Measure();
            time += dt;
        }
    }

private:
    double time;
    TermsEnabled terms;
    QuantumState<T2> quantumState;
    QuantumSystem<T1, T2> quantumSystem;
    Parameters<T2> param;
    DynamicsSchedule<arma::SpMat<T2>> dynamicsSchedule;
    MeasurementSchedule<T1, T2> measurementSchedule;
};

} // namespace solid
#endif