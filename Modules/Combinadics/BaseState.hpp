/**
 * @file BaseState.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief BaseState header
 * @version 0.100.0
 * @date 2019-10-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BASESTATE_HPP
#define BASESTATE_HPP

#include <armadillo>
using namespace arma;

namespace solid
{
    
// typedefs for state enumeration
/// Hilbert space can be huge...
typedef long int statenumber;
/// typedef for BaseState data container
typedef uvec baseStateContainer;

/**
 * @brief BaseState for HilbertSpace base
 * 
 */
class BaseState : public baseStateContainer
{
public:

    /**
     * @brief returns reversed BaseState
     * 
     * @return BaseState in reversed form e.g. 000111 -> 111000
     */
    BaseState Reverse();

    /**
     * @brief Checks if particle can hop from start to stop
     * 
     * @param start initial hopping index
     * @param stop  final hopping index
     * @return true hopping avaliable
     * @return false hopping forbidden (Pauli principle) 
     */
    bool Hop(int start, int stop);

    /**
     * @brief Checks if particle occupies site
     * 
     * @param site site to check
     * @return true particle occupies the site
     * @return false particle does not occupy the site
     */
    bool OneBodyInteraction(int site);

    /**
     * @brief Checks if particles occupy two sites
     * 
     * @param site1 first site to check
     * @param site2 other site to check
     * @return true particles occupy both sites
     * @return false particles do not occupy sites
     */
    bool TwoBodyInteraction(int site1, int site2);

    /**
     * @brief returns sign of the hopping from start to stop
     * 
     * @param start initial hopping index 
     * @param stop final hopping index
     * @return int sign of the hopping
     * 
     * We used the following convention for sites numbering:
     * * \f$
     * |11111\cdots\,\rangle = \cdots a_3^\dagger a_2^\dagger a_1^\dagger a_0^\dagger |00000\cdots\,\rangle
     * \f$
     */
    int HopSign(int start, int stop);

    /**
     * @brief perform hopping
     * 
     * @param start initial hopping index
     * @param stop final hopping index
     */
    void MakeHop(int start, int stop);

    // NOT YET IMPLEMENTED
    bool CountParticles();
    bool ThreeBodyInteraction(int site1, int site2, int site3);
    bool CreateParticle(int site1);
    bool CreatePair(int site1, int site2);
    bool CreateTriple(int site1, int site2, int site3);
};

} // namespace solid

#endif