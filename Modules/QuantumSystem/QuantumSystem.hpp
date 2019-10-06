#ifndef QUANTUMSYSTEM_HPP
#define QUANTUMSYSTEM_HPP

#include "../HilbertSpace/HilbertSpace.hpp"
#include "../Hamiltonian/Hamiltonian.hpp"
#include "../Parameters/Parameters.hpp"

template <template<typename> class T1, typename T2>
class QuantumSystem
{
public:
    HilbertSpace hilbertSpace;
    Operator<T1,T2> hamiltonian;
    Parameters<T2> parameters;
};

#endif