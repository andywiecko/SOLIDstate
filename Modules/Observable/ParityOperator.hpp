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
 * @brief implementation of the Parity operator
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 * 
 * implements parity operator \f$\mathcal P \f$ defined in the following way:
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

    void FillParameters()
    {
        arma::Col<T2> mu;
        mu.set_size(L);
        mu.fill(1);
        parameters['M'] = mu;
    }

public:
    virtual void PreprocessingVirtual(T1<T2> &matrixElements) { Preprocessing(matrixElements); }
    static void Preprocessing(T1<T2> &matrixElements)
    {
        std::cout << "parity pre-process..." << std::endl;
        matrixElements.diag() = arma::Col<T2>(matrixElements.diag()).transform([](T2 val) { return std::pow(-1, val); });
    }
};

} // namespace solid

#endif