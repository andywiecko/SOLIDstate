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
    Particles selectedParticles = qSystem.hamiltonian.termsEnabled.particles;
    switch (selectedParticles)
    {
    case Particles::Fermions:
        FermionFiller(qSystem);
        break;
    case Particles::Spins:
        SpinFiller(qSystem);
        break;
    }
}

template <template <typename> class T1, typename T2>
void MatrixElementFiller::WarmUp(QuantumSystem<T1, T2> &qSystem)
{
    int size = qSystem.hilbertSpace.ensemble.size;
    qSystem.hamiltonian.matrixElements.set_size(size, size);
    if constexpr (std::is_same<T1<T2>, arma::Mat<T2>>::value)
        qSystem.hamiltonian.matrixElements.fill(0);
}

template <template <typename> class T1, typename T2>
void MatrixElementFiller::FermionFiller(QuantumSystem<T1, T2> &qSystem)
{
    // initialisation of the base state
    qSystem.hilbertSpace.InitialBaseState();
    do
    {
        // sector terms
        /*
        // diagonal
        if (qSystem.hamiltonian.termsEnabled.OneBodyInteraction)
            OneBodyInteractionTermFermions::FillElements(qSystem);

        if (qSystem.hamiltonian.termsEnabled.TwoBodyInteraction)
            TwoBodyInteractionTermFermions::FillElements(qSystem);

        // non-diagonal
        if (qSystem.hamiltonian.termsEnabled.Hop)
            HopTermFermions::FillElements(qSystem);

        // inter-sector terms (non-diagonal)
        if (qSystem.hamiltonian.termsEnabled.CreatePair)
            CreatePairTermFermions::FillElements(qSystem);
    */

        for(auto const& value: qSystem.hamiltonian.termsEnabled.terms)
        {
            //std::cout << value << std::endl;
            //TermsEnumConverter::dict[enu](qSystem);
            if (TermsEnumConverter<T1,T2>::dict[value])
                TermsEnumConverter<T1,T2>::dict[value](qSystem);
            //if (value == TermsEnum::Hop) std::cout << "ok" << std::endl;
        }

    }
    // do until last base state in the ensemble
    while (qSystem.hilbertSpace++); //.NextBaseState());
}

template <template <typename> class T1, typename T2>
void MatrixElementFiller::SpinFiller(QuantumSystem<T1, T2> &qSystem)
{
    // initialisation of the base state
    qSystem.hilbertSpace.InitialBaseState();
    do
    {
        /*
        if (qSystem.hamiltonian.termsEnabled.OneBodyInteraction)
            OneBodyInteractionTermSpins::FillElements(qSystem);
        if (qSystem.hamiltonian.termsEnabled.TwoBodyInteraction)
            TwoBodyInteractionTermSpins::FillElements(qSystem);
        */
    } while (qSystem.hilbertSpace++); //.NextBaseState());
}

} // namespace solid