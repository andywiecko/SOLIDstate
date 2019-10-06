#include "HilbertSpace.hpp"

// selecting first sector and initilizing the baseState
void HilbertSpace::InitialBaseState()
{
    baseState.set_size(ensemble.L);
    Sector sector = ensemble.sectors[0];
    //std::cout << sector.size << std::endl;
    baseState = BaseStateNumberConverter::ToBaseState(sector, 0);
}

// selecting next baseState in HilbertSpace
// returns false if this is the last state
bool HilbertSpace::NextBaseState()
{
    Sector sector = ensemble.sectors[sectorIndex];
    // check if this is the last sector
    if (stateIndex == sector.size - 1)
        return NextSector();
    stateIndex++;
    stateTotalIndex++;
    baseState = BaseStateNumberConverter::ToBaseState(sector, stateIndex);
    return true;
}

// push the next sector to the HilbertSpace
// returns false if this is the last Sector
bool HilbertSpace::NextSector()
{
    // this is the last sector
    if (sectorIndex == ensemble.sectors.size() - 1)
        return false;
    // next sector, reset stateIndex
    else
    {
        sectorOffset += ensemble.sectors[sectorIndex].size;
        sectorIndex++;
        stateIndex = 0;
        stateTotalIndex++;
        Sector sector = ensemble.sectors[sectorIndex];
        baseState = BaseStateNumberConverter::ToBaseState(sector, 0);
        return true;
    }
}