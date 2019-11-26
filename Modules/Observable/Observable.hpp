/**
 * @file Observable.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Interface and class parent for Observables
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef OBSERVABLE_OBSERVABLE_HPP
#define OBSERVABLE_OBSERVABLE_HPP

#include "../Hamiltonian/Hamiltonian.hpp"
#include "../Parameters/Parameters.hpp"

namespace solid
{

/**
 * @brief interface for Observable class
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 * 
 * Abstract class containg two purely virtual functions (one static virtual)
 */
template <template <typename> class T1, typename T2>
class IOperatorParameters
{
public:
	/**
	 * @brief Filling the Parameters
	 * 
	 * Purely virtual function to override
	 * for IOperatorParameters implementation
	 */
    virtual void FillParameters() = 0;
    /** TODO change name to postprocessing
	 * @brief static virtial function for matrixElements postprocessing
     * 
     * @param matrixElements for postprocessing
     * 
     * As an example consider parity operator: \f$\mathcal P = \displaystyle\prod_i (1 -2\hat n_i) \f$.
     * It can be constructed from particle number operator: \f$ \hat N = \sum_i \hat n_i \f$.
     * Solution: 
     *  1. Generate \f$ \hat N \f$
     *  2. Apply postprocessing for all matrix elements: \f$ \hat N_{ij} \to (-1)^{\hat N_{ij}} \f$
     *  
	 * Purely virtual function to override
	 * for IOperatorParameters implementation
	 */
    static void Preprocessing(T1<T2> & matrixElements){};
    
    /**
     * @brief virtual link for static Postprocessing
     */
    virtual void PreprocessingVirtual(T1<T2> & matrixElements) { Preprocessing(matrixElements); }

    /**
     * @brief Destroy the IOperatorParameters object
     */
    virtual ~IOperatorParameters() {}
};

/**
 * @brief Observable parent class
 *  
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 * 
 * contains information about parameters of the Observable and container for matrix elements
 */
template <template <typename> class T1, typename T2>
class Observable
{
public:
    /**
     * @brief container for matrixElements
     */
    Operator<T1, T2> _operator;
    /**
     * @brief parameters for Observable
     */
    Parameters<T2> parameters;
};

} // namespace solid

#endif