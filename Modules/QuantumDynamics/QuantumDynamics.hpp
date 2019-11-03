#ifndef QUANTUMDYNAMICS_HPP
#define QUANTUMDYNAMICS_HPP

#include <armadillo>

#include "../QuantumSystem/QuantumSystem.hpp"
#include "../QuantumState/QuantumState.hpp"
#include "../Hamiltonian/TermsEnabled.hpp"
#include "../Laboratory/Laboratory.hpp"
#include "DynamicsSchedule.hpp"

namespace solid
{

// TODO make it as interface for different dynamics
template <template <typename> class T1, typename T2>
class QuantumDynamics
{

public:
    void Create(QuantumSystem<T1, T2> &qSystem,
                DynamicsSchedule<arma::SpMat<T2>> &dynSchedule,
                MeasurementSchedule<T1, T2> &mesSchedule)
    {
        terms = qSystem.hamiltonian.termsEnabled;
        quantumSystem = qSystem;
        dynamicsSchedule = dynSchedule;
        measurementSchedule = mesSchedule;
    }

private:
    void LoadParameters()
    {
        quantumSystem.hamiltonian.termsEnabled = terms;
        for (const auto &[label, val] : dynamicsSchedule.dict)
        {
            //std::cout << label << std::endl;
            val(quantumSystem.parameters[label], time);
            arma::mat(quantumSystem.parameters[label]).print(label + ":");
        }
    }
    void Propagate()
    {
        quantumSystem.Fill();
        quantumSystem.hamiltonian.matrixElements.print("H=");
        // TODO RK4 or chebyshev...
    }
    void Measure()
    {
        double res = Laboratory::Measure<T1, T2>(quantumSystem, quantumSystem.quantumState);
        std::cout << "Measurement result:" << res << std::endl;
        measurementSchedule.Measure(quantumSystem);
    }

public:
    void Run()
    {
        time = dynamicsSchedule.time_init;
        double dt = dynamicsSchedule.time_step;

        while (time <= dynamicsSchedule.time_final)
        {
            std::cout << "time:" << time << std::endl;
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
    QuantumState<arma::cx_double> quntumStateDynamics;
    QuantumSystem<T1, T2> quantumSystem;
    DynamicsSchedule<arma::SpMat<T2>> dynamicsSchedule;
    MeasurementSchedule<T1, T2> measurementSchedule;
};

} // namespace solid
#endif