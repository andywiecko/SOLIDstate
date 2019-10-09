#ifndef HILBERTSPACE_HPP
#define HILBERTSPACE_HPP

#include "../Ensemble/Ensemble.hpp"
#include "../Combinadics/Combinadics.hpp"
namespace solid
{
    
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

} // namespace solid

#endif