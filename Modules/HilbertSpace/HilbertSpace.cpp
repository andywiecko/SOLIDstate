/**
 * @file HilbertSpace.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Hilber Space implementation
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "HilbertSpace.hpp"

namespace solid
{

void HilbertSpace::Reset()
{
    stateIndex = 0;
    stateTotalIndex = 0;
    sectorIndex = 0;
    sectorOffset = 0;
}

void HilbertSpace::InitialBaseState()
{
    Reset();
    baseState.set_size(ensemble.L);
    Sector sector = ensemble.sectors[0];
    baseState = BaseStateNumberConverter::ToBaseState(sector, 0);
}

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

bool HilbertSpace::operator++(int)
{
    return NextBaseState();
}

statenumber HilbertSpace::GetStateIndexInCurrentSector(BaseState state)
{
    return BaseStateNumberConverter::ToNumber(state) + sectorOffset;
}

statenumber HilbertSpace::GetStateIndexInNextParitySector(BaseState state)
{
    statenumber ret = 0;
    
    for (int i=sectorIndex;i<ensemble.sectors.size()-1;i++)
    {
        if (ensemble.sectors[sectorIndex].N+2 == ensemble.sectors[i].N)
        {
            break;
        }
        else
        {
            ret += ensemble.sectors[i].size;
        }
        
    }

    ret += HilbertSpace::GetStateIndexInCurrentSector(state);

    return ret;
}

bool HilbertSpace::NextSector()
{
    if (LastSector())
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

inline bool HilbertSpace::LastSector()
{
    return sectorIndex == ensemble.sectors.size() - 1;
}

} // namespace solid