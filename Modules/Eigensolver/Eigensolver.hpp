/**
 * @file Eigensolver.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Eigensolver class header
 * @version 0.100.0
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef EIGENSOLVER_HPP
#define EIGENSOLVER_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
#include "../QuantumState/QuantumState.hpp"

namespace solid
{

/**
 * @brief class, which only job is to find ground state (QuantumState) 
 * and its corresponding energy for given QuantumSystem
 */
class Eigensolver
{
public:

    /**
     * @brief Finding ground state (QuantumState) and its corresponding eigen energy
     * 
     * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
     * @tparam T2 data type: double, std::complex<double> are supported
     * @param qSystem QuantumSystem to solve
     * @param qState  output: resulting ground state (QuantumState)
     * @return double returns eigen energy of the ground state
     * 
     * solving time-independent Schrodinger equation (eigenproblem) for its ground state:
     * \f$
     * \hat H | \psi \rangle = E | \psi \rangle,
     * \f$
     * 
     */
    template <template <typename> class T1, typename T2> 
    static QuantumState<T2> FindGroundState(QuantumSystem<T1,T2> & qSystem);

    // TODO solver options
    // support for sparse

};

} // namespace solid

#endif