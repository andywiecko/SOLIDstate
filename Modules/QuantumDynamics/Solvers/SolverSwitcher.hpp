#ifndef SOLVERSWITCHER_HPP
#define SOLVERSWITCHER_HPP

#include "QuantumDynamicSolver.hpp"
#include "RungeKutta4.hpp"
#include <string>
#include <cassert>

namespace solid
{

constexpr unsigned int str2int(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

template <template <typename> class T1, typename T2, typename T3>
class SolverSwitcher
{
public:
    static IQuantumDynamicSolver<T1, T2, T3> *Switch(const std::string label)
    {
        const std::string defaultSolver = RK4<T1, T2, T3>::label;

        switch (str2int(label.c_str()))
        {
        case str2int(RK4<T1, T2, T3>::label):
            if constexpr (std::is_same<T3, arma::cx_double>::value)
                return new RK4<T1, T2, T3>();
            else
                assert(!"selected solver requires complex type! (T3 = arma::cx_double)");
            break;

        default:
            std::cout << "Unknown solver: " << label << ". Running with default solver " << defaultSolver << std::endl;
            return Switch(defaultSolver);
            break;
        }
    }
};

} // namespace solid

#endif