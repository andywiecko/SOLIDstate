#ifndef SOLVERSWITCHER_HPP
#define SOLVERSWITCHER_HPP

#include "QuantumDynamicSolver.hpp"
#include "RungeKutta4.hpp"
#include <string>

namespace solid
{

template <template <typename> class T1, typename T2, typename T3>
class SolverSwitcher
{
public:
    static IQuantumDynamicSolver<T1, T2, T3> *Switch(const std::string label)
    {

        if (label == RK4<T1, T2, T3>::label)
        {
            if constexpr (std::is_same<T3, arma::cx_double>::value)
                return new RK4<T1, T2, T3>();
        }
        
    }
};

} // namespace solid

#endif