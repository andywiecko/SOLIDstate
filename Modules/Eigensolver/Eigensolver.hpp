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
#ifndef EIGENSOLVER_EIGENSOLVER_HPP
#define EIGENSOLVER_EIGENSOLVER_HPP

#include <string>

#include "../Info/Info.hpp"
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
    static QuantumState<T2> FindGroundState(QuantumSystem<T1, T2> &qSystem);

    // TODO
    // MICROCANONICAL LANCHOS FOR EXCITED STATES


    /**
     * @brief class for handling options for sparse matrix
     *        diagonalization procedures
     */
    class SparseSolverOptions
    {
    public:
        /**
         * @brief specifies the number of eigenvalues and eigenvectors 
         */
        static int numberOfEigenvalues;

        /**
         * @brief specifies the tolerance for convergence 
         */
        static double tolerance;

        /**
         * @brief eigenvalue target value
         * 
         * Armadillo target options for eigs_sym()
         * * "lm"	 = 	obtain eigenvalues with largest magnitude 
         * * "sm"	 = 	obtain eigenvalues with smallest magnitude (default operation)
         * * "la"	 = 	obtain eigenvalues with largest algebraic value
         * * "sa"	 = 	obtain eigenvalues with smallest algebraic value
         * 
         * @note  the number of obtained eigenvalues/eigenvectors may be lower than requested, depending on the given data 
         * @note it's more difficult to compute the smallest eigenvalues than the largest eigenvalues;
         *        if the decomposition fails, try increasing numberOfEigenvalues (number of eigenvalues) and/or the tolerance
         */
        static std::string eigenvalueTarget;

        /**
         * @brief eigenvalue (complex) target value
         * 
         * Armadillo target options for eigs_sym()
         * * "lm"	 = 	obtain eigenvalues with largest magnitude (default operation)
         * * "sm"	 = 	obtain eigenvalues with smallest magnitude (see caveat below)
         * * "lr"	 = 	obtain eigenvalues with largest real part
         * * "sr"	 = 	obtain eigenvalues with smallest real part
         * * "li"	 = 	obtain eigenvalues with largest imaginary part
         * * "si"	 = 	obtain eigenvalues with smallest imaginary part
         */
        static std::string eigenvalueComplexTarget;

    };


};

} // namespace solid

#endif