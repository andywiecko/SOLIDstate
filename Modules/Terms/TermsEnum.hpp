/**
 * @file TermsEnum.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Terms enum class
 * @version 0.100.0
 * @date 2019-11-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TERMS_TERMSENUM_HPP
#define TERMS_TERMSENUM_HPP

namespace solid
{

/**
 * @brief enum class for Terms enumeration
 */
enum class TermsEnum
{
    // Fermions
    FermionHop,                  /*!< \f$a_i^\dagger a_j\f$ */
    FermionOneBodyInteraction,   /*!< \f$\hat n_i \hat n_j  \f$*/
    FermionTwoBodyInteraction,   /*!< \f$\hat n_i \hat n_j  \f$*/
    FermionThreeBodyInteraction, /*!< \f$\hat n_i \hat n_j \hat n_k \f$*/
    FermionCreateParticle,       /*!< \f$a_i^\dagger\f$ */
    FermionCreatePair,           /*!< \f$a_i^\dagger a_j^\dagger\f$ */
    FermionCreateTriple,         /*!< \f$a_i^\dagger a_j^\dagger a_k^\dagger \f$ */

    // Spins
    SpinHop,
    SpinOneBodyInteraction,
    SpinTwoBodyInteraction
};

} // namespace solid
#endif