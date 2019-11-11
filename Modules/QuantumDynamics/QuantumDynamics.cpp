#include "QuantumDynamics.hpp"

namespace solid
{
template <template <typename> class T1, typename T2, typename T3>
void QuantumDynamics<T1, T2, T3>::LoadParameters()
{
    quantumSystem.hamiltonian.termsEnabled = terms;
    quantumSystem.parameters = param;
    for (const auto &[label, val] : dynamicsSchedule.dict)
    {
        val(quantumSystem.parameters[label], time);
    }
}

template <template <typename> class T1, typename T2, typename T3>
void QuantumDynamics<T1, T2, T3>::Run()
{
    // time loading
    time = dynamicsSchedule.time_init;
    double dt = dynamicsSchedule.time_step;

    while (time <= dynamicsSchedule.time_final)
    {
        std::cout << "time=" << time << "   |   "; // << std::endl;
        LoadParameters();
        Propagate();
        if (measurementSchedule.timeToMeasure(time))
            Measure();
        time += dt;
    }
}

template <template <typename> class T1, typename T2, typename T3>
void QuantumDynamics<T1, T2, T3>::Propagate()
{
    quantumSystem.Fill();
    double _time = time;
    double dtime = dynamicsSchedule.time_step;
    arma::cx_double I(0, 1);
    arma::cx_vec k1, k2, k3, k4;

    k1 = -I * dtime * quantumSystem.hamiltonian.matrixElements * quantumState.vector;
    time += 0.5 * dtime;
    LoadParameters();
    quantumSystem.Fill();
    k2 = -I * dtime * quantumSystem.hamiltonian.matrixElements * (quantumState.vector + 0.5 * k1);
    k3 = -I * dtime * quantumSystem.hamiltonian.matrixElements * (quantumState.vector + 0.5 * k2);
    time += 0.5 * dtime;
    LoadParameters();
    quantumSystem.Fill();
    k4 = -I * dtime * quantumSystem.hamiltonian.matrixElements * (quantumState.vector + k3);
    //(quantumState.vector + k1 + 2 * k2 + 2 * k3 + k4).print();
    k1 = 1./6. * (k1 + 2 * k2 + 2 * k3 + k4);
    //(quantumState.vector+k1).print(); // TODO [!]
    //quantumState.vector = quantumState.vector+k1;
    time = _time;
}

template <template <typename> class T1, typename T2, typename T3>
void QuantumDynamics<T1, T2, T3>::Measure()
{
    measurementSchedule.Measure(quantumSystem, quantumState);
}

} // namespace solid