#ifndef QUANTUMDYNAMICS_SOLVERS_ADIABATICSOLVER_HPP
#define QUANTUMDYNAMICS_SOLVERS_ADIABATICSOLVER_HPP

#include <armadillo>

#include "../../QuantumState/QuantumState.hpp"
#include "../../Eigensolver/Eigensolver.hpp"
#include "../QuantumDynamics.hpp"
#include "QuantumDynamicSolver.hpp"

namespace solid
{

template <template <typename> class T1, typename T2, typename T3>
class AdiabaticSolver : public IQuantumDynamicSolver<T1, T2, T3>
{
public:
    inline static constexpr auto label = "adia";

    std::string getLabel() override
    {
        return label;
    }

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