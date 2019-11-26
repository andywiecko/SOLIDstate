#ifndef QUANTUMDYNAMICS_SOLVERS_QUANTUMDYNAMICSOLVER_HPP
#define QUANTUMDYNAMICS_SOLVERS_QUANTUMDYNAMICSOLVER_HPP

#include "../QuantumDynamics.hpp"
#include <string>

namespace solid
{

template <template <typename> class T1, typename T2, typename T3>
class QuantumDynamics; // TODO remove this circular dependency (make interface for QuantumDynamics)!

template <template <typename> class T1, typename T2, typename T3>
class IQuantumDynamicSolver
{
public:
    virtual std::string getLabel() = 0;

    virtual void Propagate(double time, double dtime, QuantumDynamics<T1, T2, T3> &qDynamics) = 0;

    //virtual void PropagateVirtual(double time, double dtime, QuantumDynamics<T1, T2, T3> &qDynamics) { Propagate(time, dtime, qDynamics); }

    virtual ~IQuantumDynamicSolver() {}
};

} // namespace solid

#endif