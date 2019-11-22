/**
 * @file QuantumState.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Quantum State class header
 * @version 0.100.0
 * @date 2019-10-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef QUANTUMSTATE_HPP
#define QUANTUMSTATE_HPP

#include <armadillo>
#include <string>
#include <cassert>

#include "../QuantumSystem/QuantumSystem.hpp"

namespace solid
{

/**
 * @brief template class representing Quantum State of the system
 * 
 * @tparam T data type: double, std::complex<double> are supported
 */
template <typename T>
class QuantumState
{

public:
    /**
     * @brief container of the QuantumState
     */
    arma::Col<T> vector;

    QuantumState<T>() {}

    /**
     * @brief Construct a new Quantum State< T> object from arma::Col
     * 
     * @param vec 
     */
    QuantumState<T>(arma::Col<T> vec)
    {
        vector = vec;
    }

    /**
     * @brief Construct a new Quantum State< T> object from arma::subview_col
     * 
     * @param vec 
     */
    QuantumState<T>(arma::subview_col<T> vec)
    {
        vector = vec;
    }

    /**
     * @brief Construct a new Quantum State< T> object
     * 
     * @tparam T2 should be double, converts from double to complex, otherwise assertion
     * @param qState 
     */
    template <typename T2>
    QuantumState<T>(QuantumState<T2> &qState);

    /**
     * @brief print() the vector
     * 
     * @param extra_text 
     */
    void print(std::string extra_text = "")
    {
        vector.print(extra_text);
    }

    /**
     * @brief \f$|\psi\rangle \to \langle \psi|\f$
     * 
     * @return QuantumState<T> hermitian conjugate of the Quantum State
     */
    QuantumState<T> t()
    {
        return this->t(); //TODO it doesnt work !!!!
    }

    /**
     * @brief energy, it is assigned after eigen problem is solved
     * 
     * \f$
     * \hat H | \psi \rangle = E | \psi \rangle,
     * \f$
     * where \f$E\f$ is energy.
     */
    double energy;
};

} // namespace solid

#endif