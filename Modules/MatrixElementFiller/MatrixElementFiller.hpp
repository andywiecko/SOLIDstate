#ifndef MATRIXELEMENTFILLER_HPP
#define MATRIXELEMENTFILLER_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
#include "../Terms/Terms.hpp"
#include "../Terms/OneBodyInteraction.hpp"
#include "../Terms/TwoBodyInteraction.hpp"
#include <armadillo>

// fills the Quantum System matrix elements
class MatrixElementFiller
{
public:
    template <template <typename> class T1, typename T2>
    static void Fill(QuantumSystem<T1, T2> &qSystem)
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

private:
    template <template <typename> class T1, typename T2>
    static void WarmUp(QuantumSystem<T1, T2> &qSystem)
    {
        int size = qSystem.hilbertSpace.ensemble.size;
        qSystem.hamiltonian.matrixElements.set_size(size, size);
        if (typeid(T1<T2>) == typeid(arma::Mat<T2>))
            qSystem.hamiltonian.matrixElements.fill(0);
    }

    template <template <typename> class T1, typename T2>
    static void FermionFiller(QuantumSystem<T1, T2> &qSystem)
    {
        // initialisation of the base state
        qSystem.hilbertSpace.InitialBaseState();
        do
        {
            // TODO selecting particles then selecting Terms implementation
            // sector terms
            if (qSystem.hamiltonian.termsEnabled.OneBodyInteraction)
                OneBodyInteractionTermFermions::FillElements(qSystem);
            if (qSystem.hamiltonian.termsEnabled.TwoBodyInteraction)
                TwoBodyInteractionTermFermions::FillElements(qSystem);

        }
        // do until last base state in the ensemble
        while (qSystem.hilbertSpace.NextBaseState());
    }

    template <template <typename> class T1, typename T2>
    static void SpinFiller(QuantumSystem<T1, T2> &qSystem)
    {
        // initialisation of the base state
        qSystem.hilbertSpace.InitialBaseState();
        do
        {
            //TODO
            if (qSystem.hamiltonian.termsEnabled.OneBodyInteraction)
                OneBodyInteractionTermSpins::FillElements(qSystem);
            if (qSystem.hamiltonian.termsEnabled.TwoBodyInteraction)
                TwoBodyInteractionTermFermions::FillElements(qSystem);
        } while (qSystem.hilbertSpace.NextBaseState());
    }
};

#endif