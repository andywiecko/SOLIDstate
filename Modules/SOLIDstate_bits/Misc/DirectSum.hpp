#ifndef MISC_DIRECTSUM_HPP
#define MISC_DIRECTSUM_HPP

#include <armadillo>
#include <type_traits>

namespace solid
{

/**
 * @brief Direct sum of two matrices
 * 
 * It returns the following matrix product:
 * \f[
 * A\oplus B = 
 * \left[
 * \begin{array}{cc} 
 *  A & 0 \\ 0 & B
 * \end{array}\right]
 * \f]
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 * @param A upper matrix
 * @param B  lower matrix
 * @return T1<T2> direct sum \f$A\oplus B\f$
 */
template <template <typename> class T1, typename T2>
T1<T2> DirectSum(T1<T2> A, T1<T2> B)
{
    unsigned long int ncA = A.n_cols;
    unsigned long int ncB = B.n_cols;
    unsigned long int nrA = A.n_rows;
    unsigned long int nrB = B.n_rows;

    T1<T2> ret(nrA + nrB, ncA + ncB);

    if constexpr (std::is_same<T1<T2>, arma::Mat<T2>>::value)
        ret.fill(0);
    ret.submat(0, 0, nrA - 1, ncA - 1) = A;
    ret.submat(nrA, ncA, nrA + nrB - 1, ncA + ncB - 1) = B;
    return ret;
}

} // namespace solid

#endif