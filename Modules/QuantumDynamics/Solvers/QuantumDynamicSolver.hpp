#ifndef QUANTUMDYNAMICSOLVER_HPP
#define QUANTUMDYNAMICSOLVER_HPP

#include "../QuantumDynamics.hpp"
#include <string>

namespace solid
{
template <template <typename> class T1, typename T2, typename T3>
class IQuantumDynamicSolver
{
public:
    
    virtual std::string getLabel() = 0;

    static void Propagate(double time, double dtime, QuantumDynamics<T1, T2, T3> &qDynamics){};

    virtual void PropagateVirtual(double time, double dtime, QuantumDynamics<T1, T2, T3> &qDynamics) { Propagate(time, dtime, qDynamics); }

    virtual ~IQuantumDynamicSolver() {}
};




} // namespace solid

#endif