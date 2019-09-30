#ifndef MATRIXELEMENTFILLER_H
#define MATRIXELEMENTFILLER_H

#include "../QuantumSystem/QuantumSystem.h"
#include "../Terms/Terms.h"

// fills the Quantum System matrix elements
class MatrixElementFiller
{
    public:
        static void Fill(QuantumSystem<mat> & qSystem)
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
        static void FermionFiller(QuantumSystem<mat> & qSystem)
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

        static void SpinFiller(QuantumSystem<mat> & qSystem)
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