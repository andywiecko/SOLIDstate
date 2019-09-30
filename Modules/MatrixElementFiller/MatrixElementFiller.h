#ifndef MATRIXELEMENTFILLER_H
#define MATRIXELEMENTFILLER_H

#include "../QuantumSystem/QuantumSystem.h"
#include "../Terms/Terms.h"

class MatrixElementFiller
{
    public:
        static void Fill(QuantumSystem<mat> & qSystem)
        {
            // initialisation of the base state
            qSystem.hilbertSpace.InitialBaseState();
            do
            {
                // sector terms
                OneBodyInteractionTerm::FillElements(qSystem);

            }
            // do until last base state in the ensemble
            while(qSystem.hilbertSpace.NextBaseState());

        }

};

#endif