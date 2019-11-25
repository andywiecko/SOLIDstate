#ifndef SOLVERSWITCHER_HPP
#define SOLVERSWITCHER_HPP

#include "QuantumDynamicSolver.hpp"
#include "RungeKutta4.hpp"
#include <string>
#include <cassert>

namespace solid
{

template <template <typename> class T1, typename T2, typename T3>
class SolverSwitcher
{
public:
    static IQuantumDynamicSolver<T1, T2, T3> *Switch(const std::string label)
    {
        const std::string defaultSolver = RK4<T1, T2, T3>::label;

        if (label == RK4<T1, T2, T3>::label)
        {
            if constexpr (std::is_same<T3, arma::cx_double>::value)
                return new RK4<T1, T2, T3>();
            else
                assert(!"rk4 requires complex type! (T3=arma::cx_double)");
        }
        else
        {
            std::cout << "Unknown solver name! Running with default solver " << defaultSolver << std::endl;
            return Switch(defaultSolver);
        }
    }
};

} // namespace solid

#endif