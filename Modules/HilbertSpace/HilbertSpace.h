#ifndef HILBERTSPACE_H
#define HILBERTSPACE_H

#include "../Ensemble/Ensemble.h"
#include "../Combinadics/Combinadics.h"

// main purpose: state enumeration within the sectors
// class contains
// - Base State 
// - Ensemble
class HilbertSpace
{
    public: 
        BaseState baseState;
        Ensemble ensemble;
        void InitialBaseState();
        bool NextBaseState();
        // enumerates the states inside the sector
        statenumber stateIndex = 0;
        // enumerates the states inside the ensemble (all sectors)
        statenumber stateTotalIndex = 0;
        int sectorIndex = 0;
        // ancillary variable for inserting inter-sector interaction elements
        statenumber sectorOffset = 0;

    private:
        bool NextSector();

};

#endif