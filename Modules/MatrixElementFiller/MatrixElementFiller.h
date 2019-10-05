#ifndef MATRIXELEMENTFILLER_H
#define MATRIXELEMENTFILLER_H

#include "../QuantumSystem/QuantumSystem.h"
#include "../Terms/Terms.h"
#include "../Terms/OneBodyInteraction.h"

// fills the Quantum System matrix elements
class MatrixElementFiller
{
public:
    template <template<typename> class T1, typename T2>
    static void Fill(QuantumSystem<T1, T2> &qSystem)
    {
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
    template <template<typename>class T1, typename T2>
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
        }
        // do until last base state in the ensemble
        while (qSystem.hilbertSpace.NextBaseState());
    }

    template <template<typename> class T1, typename T2>
    static void SpinFiller(QuantumSystem<T1, T2> &qSystem)
    {
        // initialisation of the base state
        qSystem.hilbertSpace.InitialBaseState();
        do
        {
            //TODO
            if (qSystem.hamiltonian.termsEnabled.OneBodyInteraction)
                OneBodyInteractionTermSpins::FillElements(qSystem);
        } while (qSystem.hilbertSpace.NextBaseState());
    }
};

#endif