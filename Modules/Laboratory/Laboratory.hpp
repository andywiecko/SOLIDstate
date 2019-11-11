/**
 * @file Laboratory.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Laboratory class header
 * @version 0.100.0
 * @date 2019-10-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LABORATORY_HPP
#define LABORATORY_HPP

#include "../QuantumState/QuantumState.hpp"
#include "../QuantumSystem/QuantumSystem.hpp"
#include "../Info/Info.hpp"
#include <armadillo>
#include <type_traits>

namespace solid
{
/**
 * @brief contains static methods for measurement
 * 
 */
class Laboratory
{
public:
    /**
     * @brief measures dot product between QuantumState and QuantumSystem
     * 
     * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
     * @tparam T2 data type: double, std::complex<double> are supported
     * @return T2 returns scalar product < QuantumState | QuantumSystem | QuantumState >
     * 
     * Returns \f$\langle \psi | \hat {\mathcal O} | \psi \rangle \f$, 
     * where \f$|\psi\rangle\f$ is QuantumState 
     * and \f$\hat {\mathcal O}\f$ are current matrixElements in QuantumSystem
     * 
     * @note Return type is deduced based on the types of QuantumSystem and QuantumState.
     * If any of them is complex type: arma::cx_double, than return type is deduced as arma::cx_double
     */
    template <template <typename> class T1, typename T2, typename T3 = arma::cx_double>
    static typename std::conditional<std::is_same<T2, arma::cx_double>::value || std::is_same<T3, arma::cx_double>::value, arma::cx_double, double>::type
    Measure(QuantumSystem<T1, T2> &, QuantumState<T3> &);
};
} // namespace solid

#endif