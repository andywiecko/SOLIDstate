#ifndef MISC_SYMMATGEN_HPP
#define MISC_SYMMATGEN_HPP

#include <armadillo>

namespace solid
{

/**
 * @brief Symmetrize the matrix by adding transpose to it
 * \f[
 * A \to A + A^\dagger
 * \f]
 * 
 * @tparam T 
 * @param mat matrix to symmetrize 
 */
template <typename T>
void Symmatgen(arma::SpMat<T> &mat)
{
    mat += mat.t();
}
} // namespace solid

#endif