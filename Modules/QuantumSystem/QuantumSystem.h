#ifndef QUANTUMSYSTEM_H
#define QUANTUMSYSTEM_H

#include "../HilbertSpace/HilbertSpace.h"
#include "../Hamiltonian/Hamiltonian.h"
#include "../Parameters/Parameters.h"

template <template<typename> class T1, typename T2>
class QuantumSystem
{
public:
    HilbertSpace hilbertSpace;
    Operator<T1,T2> hamiltonian;
    Parameters<T2> parameters;
};

#endif