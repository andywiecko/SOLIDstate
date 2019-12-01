#ifndef TERMS_TERMSTYPEENUM_HPP
#define TERMS_TERMSTYPEENUM_HPP

namespace solid
{

/**
 * @brief Terms Type enum class
 * 
 * Distinction between (Non)Local and (Non)Diagonal Terms.
 * 
 * Example of Local and NonLocal operator \f$A\f$:
   \verbatim
   o ---- o ---- o ---- o ---- o
   ^             ^      ^
   |             |______|
   Local A           NonLocal A
   \endverbatim
 * 
 * Example of Diagonal and NonDiagonal Term \f$A\f$
 * \f[
 * \textrm{Diagonal:}\,\,\langle n | A | n \rangle \neq 0,
 * \f]
 * \f[
 * \textrm{NonDiagonal:}\,\,\langle n | A | n \rangle = 0,
 * \f]
 * where \f$|n\rangle\f$ is BaseState
 */
enum class TermsTypeEnum
{
    LocalDiagonal,
    LocalNondiagonal,
    NonlocalDiagonal,
    NonlocalNondiagonal
};

} // namespace solid

#endif