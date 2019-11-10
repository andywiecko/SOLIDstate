#ifndef TERMSENUM_HPP
#define TERMSENUM_HPP

namespace solid
{
enum class TermsEnum
{
    // Fermions

    FermionHop,
    FermionOneBodyInteraction,
    FermionTwoBodyInteraction,
    FermionThreeBodyInteraction,
    FermionCreateParticle,
    FermionCreatePair,
    FermionCreateTriple,

    // Spins
    SpinHop,
    SpinOneBodyInteraction,
    SpinTwoBodyInteraction
};
}
#endif