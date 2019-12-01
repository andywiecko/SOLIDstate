/**
 * @file HilbertSpace.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Hilbert Space header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef HILBERTSPACE_HILBERTSPACE_HPP
#define HILBERTSPACE_HILBERTSPACE_HPP

#include "../Ensemble/Ensemble.hpp"
#include "../Combinadics/Combinadics.hpp"
namespace solid
{

// main purpose: state enumeration within the sectors
// class contains
// - Base State
// - Ensemble

/**
 * @brief Hilbert Space class for state enumeration within the Sectors (Sector)
 * 
 * class contains
 * * BaseState
 * * Ensemble
 */
class HilbertSpace
{
public:
    /**
     * @brief current BaseState in HilbertSpace
     */
    BaseState baseState;
    /**
     * @brief selected Ensemble 
     */
    Ensemble ensemble;

    /**
     * @brief BaseState initialization
     * 
     * it sets first BaseState from Ensemble (from the first Sector)
     */
    void InitialBaseState();

    /**
     * @brief picks up the next BaseState from Ensemble
     * 
     * @return true if the next state exists
     * @return false if the next state does not exist -- the last state from the Ensemble
     */
    bool NextBaseState();

    /**
     * @brief sets stateTotalIndex and all private Indexes to 0
     * 
     * stateTotalIndex -> 0\n
     * sectorIndex     -> 0\n
     * stateIndex      -> 0\n
     * sectorOffet     -> 0
     */
    void Reset();

    /**
    * @brief enumerates the states inside the ensemble (all sectors)
    */
    statenumber stateTotalIndex = 0;

    /**
     * @brief overloaded ++ operator, which execute NextBaseState()
     * 
     * @return true the next BaseState exists
     * @return false the next BaseState does not exist
     */
    bool operator++(int);

    /**
     * @brief Get the State Index In Current Sector object
     * 
     * @param state BaseState to convert
     * @return statenumber returns (total) state index
     */
    statenumber GetStateIndexInCurrentSector(BaseState state);

    /**
     * @brief Get the State Index In Next Parity Sector object
     * 
     * @param state BaseState to convert
     * @return statenumber returns (next parity) sector index
     */
    statenumber GetStateIndexInNextParitySector(BaseState state);


private:
    statenumber stateIndex = 0;             /// current selcted BaseState enumerates the states inside the sector
    int sectorIndex = 0;                    /// current selected sector -- enumerates the sectors //TODO make iterator or pointer instead of indexing
    statenumber sectorOffset = 0;           /// ancillary variable for inserting inter-sector interaction elements
    statenumber nextParitySectorOffset = 0; /// distance between current sector and the next sector with the same parity

    /**
     * @brief switch to the next sector 
     * 
     * @return true the next sector exists
     * @return false the next sector does not exist
     */
    bool NextSector();

    /**
     * @brief checks if current selected sector from Ensemble is the last one
     * 
     * @return true current sector is the last one
     * @return false otherwise
     */
    bool LastSector();

    /**
     * @brief Get the Next Parity Sector Offset object
     * 
     * calculate nextParitySectorOffset
     */
    void GetNextParitySectorOffset();
};

} // namespace solid

#endif