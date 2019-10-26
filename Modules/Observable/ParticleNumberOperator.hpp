#ifndef PARTICLENUMBEROPERATOR_HPP
#define PARTICLENUMBEROPERATOR_HPP

#include "Observable.hpp"

namespace solid
{


 
template <template <typename> class T1, typename T2>
class ParticleNumberOperator : public Observable<T1, T2>, public IOperatorParameters<T1, T2>
{
    using Observable<T1, T2>::_operator;
    using Observable<T1, T2>::parameters;

public:
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
};

} // namespace solid

#endif