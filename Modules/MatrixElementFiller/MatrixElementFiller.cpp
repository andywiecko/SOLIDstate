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
        if (qSystem.hamiltonian.termsEnabled.OneBodyInteraction)
            OneBodyInteractionTermFermions::FillElements(qSystem);

        if (qSystem.hamiltonian.termsEnabled.TwoBodyInteraction)
            TwoBodyInteractionTermFermions::FillElements(qSystem);

        if (qSystem.hamiltonian.termsEnabled.Hop)
            HopTermFermions::FillElements(qSystem);

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
        if (qSystem.hamiltonian.termsEnabled.OneBodyInteraction)
            OneBodyInteractionTermSpins::FillElements(qSystem);
        if (qSystem.hamiltonian.termsEnabled.TwoBodyInteraction)
            TwoBodyInteractionTermSpins::FillElements(qSystem);
    } while (qSystem.hilbertSpace++); //.NextBaseState());
}

} // namespace solid