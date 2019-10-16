#ifndef QUANTUMSYSTEM_HPP
#define QUANTUMSYSTEM_HPP

#include "../HilbertSpace/HilbertSpace.hpp"
#include "../Hamiltonian/Hamiltonian.hpp"
#include "../Parameters/Parameters.hpp"
#include "../Observable/Observable.hpp"
#include "../Factory/Factory.hpp"

namespace solid
{

// QuantumSystem<T1,T2> class:
// T1 -- matrix type (support for arma::Mat, arma::SpMat)
// T2 -- data type (support for double, float, cx_double, cx_float)
// class contains:
//  |- hilbert space
//  |    |-- ensemble
//  |    |-- BaseState iterators
//  |- hamiltonian (operator)
//  |- system parameters
template <template <typename> class T1, typename T2>
class QuantumSystem
{
public:
    HilbertSpace hilbertSpace;
    Operator<T1, T2> hamiltonian;
    Parameters<T2> parameters;

    template <class Ens, typename... Targs>
    void SelectEnsemble(Targs... Fargs)
    {
        HilbertSpace space;
        space.ensemble = Factory::CreateEnsemble<Ens>(Fargs...);
        hilbertSpace = space;
    }

    template <template <template <typename> class, typename> class Ham>
    void SelectHamiltonian()
    {
        hamiltonian = Factory::CreateHamiltonian<Ham<T1, T2>>();
    }

    template <template <template <typename> class, typename> class Obs,typename...Targs>
    void SelectObservable(Targs... Fargs)
    {
        Observable<T1, T2> obs = Factory::CreateObservable<Obs<T1, T2>>(Fargs...);
	    hamiltonian = obs._operator;
    	parameters = obs.parameters;
    }

};

} // namespace solid

#endif