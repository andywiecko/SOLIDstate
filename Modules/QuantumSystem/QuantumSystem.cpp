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

} // namespace solid