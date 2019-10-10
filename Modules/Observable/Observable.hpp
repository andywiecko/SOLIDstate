#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "../Hamiltonian/Hamiltonian.hpp"
#include "../Parameters/Parameters.hpp"

namespace solid
{

class IOperatorParameters
{
public:
    virtual void FillParameters() = 0;
    virtual ~IOperatorParameters() {}
};

template <template <typename> class T1, typename T2>
class Observable
{
public:
    Operator<T1, T2> _operator;
    Parameters<T2> parameters;
};

template <template <typename> class T1, typename T2>
class ParticleNumberOperator : public Observable<T1, T2>, public IOperatorParameters
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
        // Fermions are default, but it is good to stress out
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