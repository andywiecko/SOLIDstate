/**
 * @file QuantumSystem.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Quantum System class implementation
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "QuantumSystem.hpp"
#include <armadillo>
#include "../HilbertSpace/HilbertSpace.hpp"
#include "../MatrixElementFiller/MatrixElementFiller.hpp"

namespace solid
{

template <template <typename> class T1, typename T2>
void QuantumSystem<T1, T2>::Fill()
{
    MatrixElementFiller::Fill(*this);
}

template <template <typename> class T1, typename T2>
template <class Ens, typename... Targs>
void QuantumSystem<T1, T2>::SelectEnsemble(Targs... Fargs)
{
    HilbertSpace space;
    space.ensemble = Factory::CreateEnsemble<Ens>(Fargs...);
    hilbertSpace = space;
}

template <template <typename> class T1, typename T2>
template <template <template <typename> class, typename> class Ham>
void QuantumSystem<T1, T2>::SelectHamiltonian()
{ 
    hamiltonian = Factory::CreateHamiltonian<Ham<T1, T2>>();
}

template <template <typename> class T1, typename T2>
template <template <template <typename> class, typename> class Obs, typename... Targs>
void QuantumSystem<T1, T2>::SelectObservable(Targs... Fargs)
{ 
    Observable<T1, T2> obs = Factory::CreateObservable<Obs<T1, T2>>(Fargs...);
    hamiltonian = obs._operator;
    parameters = obs.parameters;
    this->Fill();
    Obs<T1, T2>::Preprocessing(this->hamiltonian.matrixElements);
}

template <template <typename> class T1, typename T2>
void QuantumSystem<T1, T2>::SelectParameters(Parameters<T2> &parameters)
{
    this->parameters = parameters;
}

template <template <typename> class T1, typename T2>
void QuantumSystem<T1, T2>::SelectParameters(Geometry<T2> &geometry)
{
    this->parameters = geometry.parameters;
}

} // namespace solid