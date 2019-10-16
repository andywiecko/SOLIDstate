#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "../Hamiltonian/Hamiltonian.hpp"
#include "../Parameters/Parameters.hpp"

namespace solid
{

template <template <typename> class T1, typename T2>
class IOperatorParameters
{
public:
    virtual void FillParameters() = 0;
    static void Preprocessing(T1<T2> & matrixElements){};
    virtual void PreprocessingVirtual(T1<T2> & matrixElements) { Preprocessing(matrixElements); }
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