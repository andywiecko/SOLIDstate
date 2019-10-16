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
    static void Preprocessing(){};
    virtual void PreprocessingVirtual() { Preprocessing(); }
    virtual ~IOperatorParameters() {}
};

template <template <typename> class T1, typename T2>
class Observable
{
public:
    Operator<T1, T2> _operator;
    Parameters<T2> parameters;
};

} // namespace solid

#endif