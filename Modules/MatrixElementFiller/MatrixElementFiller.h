#ifndef MATRIXELEMENTFILLER_H
#define MATRIXELEMENTFILLER_H

#include "../QuantumSystem/QuantumSystem.h"
#include "../Terms/Terms.h"
#include "../Terms/OneBodyInteraction.h"

// fills the Quantum System matrix elements
class MatrixElementFiller
{
    public:
        template <typename T>
        static void Fill(QuantumSystem<T> & qSystem)
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
        template <typename T>
        static void FermionFiller(QuantumSystem<T> & qSystem)
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
            while(qSystem.hilbertSpace.NextBaseState());
        }

        template <typename T>
        static void SpinFiller(QuantumSystem<T> & qSystem)
        {
            // initialisation of the base state
            qSystem.hilbertSpace.InitialBaseState();
            do
            {
                //TODO
                if (qSystem.hamiltonian.termsEnabled.OneBodyInteraction)
                    OneBodyInteractionTermSpins::FillElements(qSystem);
            }
            while(qSystem.hilbertSpace.NextBaseState());
        }


};

#endif