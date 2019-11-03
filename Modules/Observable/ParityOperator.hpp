/**
 * @file ParityOperator.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Parity operator header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef PARITYOPERATOR_HPP
#define PARITYOPERATOR_HPP

#include "Observable.hpp"

namespace solid
{

/**
 * @brief implementation of the ParityOperator
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 * 
 * implements ParityOperator \f$\mathcal P \f$ defined in the following way:
 * \f[
 * \mathcal P  = \prod_i (1-2\hat n_i),
 * \f] 
 * where \f$\hat n_i \f$ is particle number operator at site \f$i\f$.
 */
template <template <typename> class T1, typename T2>
class ParityOperator : public Observable<T1, T2>, public IOperatorParameters<T1, T2>
{
    using Observable<T1, T2>::_operator;
    using Observable<T1, T2>::parameters;

public:
    /**
     * @brief Construct a new Parity Operator< T 1,  T 2> object
     * 
     * @param _L number of sites
     */
    ParityOperator<T1, T2>(int _L)
    {
        L = _L;
        SelectTerms();
        FillParameters();
    }

private:
    int L;

    void SelectTerms()
    {
        _operator.termsEnabled.particles = Particles::Fermions;
        _operator.termsEnabled.OneBodyInteraction = true;
    }

    void FillParameters() override
    {
        arma::SpMat<T2> mu = arma::eye<arma::SpMat<T2>>(L, L);
        parameters["M"] = mu;
    }

public:
    void PreprocessingVirtual(T1<T2> &matrixElements) override { Preprocessing(matrixElements); }
    static void Preprocessing(T1<T2> &matrixElements)
    {
        std::cout << "parity pre-process..." << std::endl;
        matrixElements.diag() = arma::Col<T2>(matrixElements.diag()).transform([](T2 val) { return std::pow(-1, val); });
    }
};

} // namespace solid

#endif