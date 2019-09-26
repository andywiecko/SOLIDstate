#include "HilbertSpace.h"

void HilbertSpace::InitialBaseState()
{
    baseState.set_size(ensemble.L);
    Sector sector = ensemble.sectors[0];
    std::cout << sector.size << std::endl;
    baseState = BaseStateNumberConverter::ToBaseState(sector,0);
}

bool HilbertSpace::NextBaseState()
{
    Sector sector = ensemble.sectors[sectorIndex];
    if (stateIndex == sector.size-1) 
    {
        if (sectorIndex == ensemble.sectors.size()-1)
            return false;
        else
        {
            sectorIndex++; stateIndex = 0;
            sector = ensemble.sectors[sectorIndex];
            baseState = BaseStateNumberConverter::ToBaseState(sector,0);
            stateIndex++;
            return true;
        }
    }
    baseState = BaseStateNumberConverter::ToBaseState(sector,stateIndex);
    stateIndex++;
    return true;
}