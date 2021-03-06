#include "QuantumDynamics.hpp"

#include <type_traits>

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
    solver->Propagate(time, dynamicsSchedule.time_step, *this);
}

template <template <typename> class T1, typename T2, typename T3>
void QuantumDynamics<T1, T2, T3>::Measure()
{
    measurementSchedule.Measure(quantumSystem, quantumState);
}

} // namespace solid