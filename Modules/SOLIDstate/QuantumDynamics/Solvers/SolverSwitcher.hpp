/**
 * @file SolverSwitcher.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief SolverSwitcher header
 * @version 0.100.0
 * @date 2019-11-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef QUANTUMDYNAMICS_SOLVERS_SOLVERSWITCHER_HPP
#define QUANTUMDYNAMICS_SOLVERS_SOLVERSWITCHER_HPP

#include "QuantumDynamicSolver.hpp"
#include "RungeKutta4.hpp"
#include "AdiabaticSolver.hpp"
#include "../../Misc/StrToInt.hpp"

#include <string>
#include <cassert>

namespace solid
{



/**
 * @brief Switcher for QuantumDynamicSolver
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type of QuantumSystem: double, std::complex<double> are supported
 * @tparam T3 data type of QuantumState: double, std::complex<double> are supported
 */
template <template <typename> class T1, typename T2, typename T3>
class SolverSwitcher
{
public:
    /**
     * @brief Switch between IQuantumDynamicSolvers
     * 
     * @param label label of selected IQuantumDynamicSolver implementation
     * @return IQuantumDynamicSolver<T1, T2, T3>* pointer to selected IQuantumDynamicSolver implementation
     */
    static IQuantumDynamicSolver<T1, T2, T3> *Switch(const std::string label)
    {
        // default solver label
        const std::string defaultSolver = RK4<T1, T2, T3>::label;

        switch (StrToInt(label.c_str()))
        {

        // Runge Kutta 4 order Solver
        case StrToInt(RK4<T1, T2, T3>::label):
            if constexpr (std::is_same<T3, arma::cx_double>::value)
                return new RK4<T1, T2, T3>();
            else
                assert(!"selected solver requires complex type! (T3 = arma::cx_double)");
            break;

        // Adiabatic Solver
        case StrToInt(AdiabaticSolver<T1, T2, T3>::label):
            return new AdiabaticSolver<T1, T2, T3>();

        // default Solver
        default:
            // TODO move to info
            std::cout << "Unknown solver: " << label << ". Running with default solver " << defaultSolver << std::endl;
            return Switch(defaultSolver);
            break;
        }
    }
};

} // namespace solid

#endif