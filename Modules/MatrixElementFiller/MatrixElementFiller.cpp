/**
 * @file MatrixElementFiller.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Matrix Element Filler implementation
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "MatrixElementFiller.hpp"
#include "TermsEnumConverter.hpp"
#include "../Hamiltonian/TermsEnum.hpp"

namespace solid
{

template <template <typename> class T1, typename T2>
void MatrixElementFiller::Fill(QuantumSystem<T1, T2> &qSystem)
{
    WarmUp(qSystem);
    Filler(qSystem);
}

template <template <typename> class T1, typename T2>
void MatrixElementFiller::WarmUp(QuantumSystem<T1, T2> &qSystem)
{
    int size = qSystem.hilbertSpace.ensemble.size;
    qSystem.hamiltonian.matrixElements.clear();
    qSystem.hamiltonian.matrixElements.set_size(size, size);
    if constexpr (std::is_same<T1<T2>, arma::Mat<T2>>::value)
        qSystem.hamiltonian.matrixElements.fill(0);
}

template <template <typename> class T1, typename T2>
void MatrixElementFiller::Filler(QuantumSystem<T1, T2> &qSystem)
{
    // initialisation of the base state
    qSystem.hilbertSpace.InitialBaseState();
    do
    {
        // consider all terms for Hamiltonian/Operator
        for (auto const &value : qSystem.hamiltonian.termsEnabled.terms)
        {
            if (TermsEnumConverter<T1, T2>::dict[value])
                TermsEnumConverter<T1, T2>::dict[value](qSystem);
        }

    }
    // do until last base state in the ensemble
    while (qSystem.hilbertSpace++); //.NextBaseState());
}

} // namespace solid