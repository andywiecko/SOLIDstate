#ifndef PARITYOPERATOR_HPP
#define PARITYOPERATOR_HPP

#include "Observable.hpp"

namespace solid
{

//tex: $$\hat P = (-1)^{\hat N}$$
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