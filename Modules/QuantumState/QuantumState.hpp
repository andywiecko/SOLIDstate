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

namespace solid
{

/**
 * @brief template class representing Quantum State of the system
 * 
 * @tparam T data type: double, std::complex<double> are supported
 */
template <typename T>
class QuantumState : public Col<T>
{
    public:
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

}

#endif