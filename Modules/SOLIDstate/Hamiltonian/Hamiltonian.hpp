/**
 * @file Hamiltonian.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Hamiltonian interface and parrent class header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef HAMILTONIAN_HAMILTONIAN_HPP
#define HAMILTONIAN_HAMILTONIAN_HPP

#include "TermsEnabled.hpp"

namespace solid
{

// Hamiltonian interface

/**
 * @brief interface for Hamiltonian
 * 
 * Abstract class Containg one purely virtual function
 */
class IHamiltonian
{
public:
	/**
	 * @brief selecting active terms in Hamiltonian
	 * 
	 * Purely virtual function to override
	 * for IHamiltonian implementation
	 * 
	 * See TermsEnabled for defaults:
	 * Hop (not implemented yet)
	 * OneBodyInteraction
	 * TwoBodyInteraction (not implemented yet)
	 * ThreeBodyInteraction (not implemented yet)
	 * CreateParticle (not implemented yet)
	 * CreatePair (not implemented yet)
	 * CreateTriple (not implemented yet)
	 */
	virtual void SelectTerms() = 0;

	/**
	 * @brief Destroy the IHamiltonian object
	 * 
	 */
	virtual ~IHamiltonian() {}
};

/**
 * @brief parent class for Quantum Mechanical Operators
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 */
template <template <typename> class T1, typename T2>
class Operator
{
public:
	/**
	 * @brief container for matrix elements
	 */
	T1<T2> matrixElements;

	/**
	 * @brief Terms enabled in Operator
	 * 
	 * e.g. hopping, one-body interaction, two-body interaction ...
	 */
	TermsEnabled termsEnabled;

	/**
	 * @brief Destroy the Operator object
	 */
	virtual ~Operator() {}
};

} // namespace solid

#endif