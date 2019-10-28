#include "Laboratory.hpp"



namespace solid 
{
    
    template <template <typename> class T1, typename T2>
    T2 Laboratory::Measure(QuantumSystem<T1,T2> & qSystem, QuantumState<T2> & qState)
    {
        return qState.t() * qSystem.hamiltonian.matrixElements * qState;
    }
}
