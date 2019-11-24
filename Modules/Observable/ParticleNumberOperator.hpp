/**
 * @file ParticleNumberOperator.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Particle Number Operator header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef PARTICLENUMBEROPERATOR_HPP
#define PARTICLENUMBEROPERATOR_HPP

#include "Observable.hpp"

namespace solid
{

/**
 * @brief implementation of the Total ParticleNumberOperator
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 * 
 * implements ParticleNumberOperator \f$\hat N \f$ defined in the following way:
 * \f[
 * \hat N  = \sum_i \hat n_i,
 * \f] 
 * where \f$\hat n_i \f$ is particle number operator at site \f$i\f$.
 */
template <template <typename> class T1, typename T2>
class ParticleNumberOperator : public Observable<T1, T2>, public IOperatorParameters<T1, T2>
{
    using Observable<T1, T2>::_operator;
    using Observable<T1, T2>::parameters;

public:
    /**
     * @brief Construct a new Particle Number Operator< T 1,  T 2> object
     * 
     * @param _L number of sites
     */
    ParticleNumberOperator<T1, T2>(int _L)
    {
        L = _L;
        SelectTerms();
        FillParameters();
    }

private:
    int L;

    void SelectTerms()
    {
        _operator.termsEnabled.terms = {TermsEnum::FermionOneBodyInteraction};
    }

    void FillParameters() override
    {
        arma::SpMat<T2> mu = arma::eye<arma::SpMat<T2>>(L, L);
        parameters["mu"] = mu;
    }
};

} // namespace solid

#endif