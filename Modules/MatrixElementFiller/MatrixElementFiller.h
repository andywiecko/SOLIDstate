#ifndef MATRIXELEMENTFILLER_H
#define MATRIXELEMENTFILLER_H

#include "../QuantumSystem/QuantumSystem.h"

class MatrixElementFiller
{
    public:
        static void Fill(QuantumSystem<mat> & qSystem)
        {
            qSystem.hilbertSpace.InitialBaseState();

            int k = qSystem.hilbertSpace.stateIndex;
            for(int i=0;i<qSystem.hilbertSpace.baseState.size();i++)
            {
                if (qSystem.hilbertSpace.baseState.OneBodyInteraction(i))
                qSystem.hamiltonian.matrixElements(k,k) += qSystem.parameters(i);
            }
            while(qSystem.hilbertSpace.NextBaseState())
            {
                //std::cout << qSystem.hilbertSpace.sectorIndex << "\t" << qSystem.hilbertSpace.stateIndex << " |";// << std::endl;
                //qSystem.hilbertSpace.baseState.t().print();
                // sector terms
                int k = qSystem.hilbertSpace.stateIndex+qSystem.hilbertSpace.sectorOffset;

                // rule1 : move to hamiltonian kitaev
                for(int i=0;i<qSystem.hilbertSpace.baseState.size();i++)
                {
                    if (qSystem.hilbertSpace.baseState.OneBodyInteraction(i))
                    qSystem.hamiltonian.matrixElements(k,k) += qSystem.parameters(i);
                }
                // inter-sector terms

            }


        }

};

#endif