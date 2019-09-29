#ifndef QUANTUMSYSTEM_H
#define QUANTUMSYSTEM_H

#include "../HilbertSpace/HilbertSpace.h"
#include "../Hamiltonian/Hamiltonian.h"

template<class T>
class QuantumSystem
{
    public:
        HilbertSpace hilbertSpace;
        Operator<T> hamiltonian;
        vec parameters;

};

#endif