#ifndef LABORATORY_HPP
#define LABORATORY_HPP

#include "../QuantumState/QuantumState.hpp"
#include "../QuantumSystem/QuantumSystem.hpp"

#include <armadillo>

namespace solid
{
    class Laboratory
    {
        template <template <typename> class T1, typename T2>
        static T2 Measure(QuantumSystem<T1,T2> &, QuantumState<T2> &);

    };
}

#endif