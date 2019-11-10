/**
 * @file MatrixElementFiller.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Matrix Element Filler header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef MATRIXELEMENTFILLER_HPP
#define MATRIXELEMENTFILLER_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
/*#include "../Terms/Terms.hpp"
#include "../Terms/OneBodyInteraction.hpp"
#include "../Terms/TwoBodyInteraction.hpp"
#include "../Terms/Hop.hpp"
#include "../Terms/CreatePair.hpp"
*/
#include <armadillo>
#include <type_traits>

namespace solid
{

/**
 * @brief Static class, which fills the QuantumSystem matrix elements
 * 
 * Class contains functions for different particles, which fill 
 * matrix element for given QuantumSystem (with selected Operator, IHamiltonian, HilbertSpace, Ensemble)
 */
class MatrixElementFiller
{
public:
    /**
     * @brief fills matrixElements for QuantumSystem for selected Operator
     * 
     * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
     * @tparam T2 data type: double, std::complex<double> are supported
     * @param qSystem QuantumSystem to fill
     */
    template <template <typename> class T1, typename T2>
    static void Fill(QuantumSystem<T1, T2> &qSystem);

private:
    /**
     * @brief initialization of the matrixElements for QuantumSystem
     * 
     * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
     * @tparam T2 data type: double, std::complex<double> are supported
     * @param qSystem QuantumSystem to initilize
     */
    template <template <typename> class T1, typename T2>
    static void WarmUp(QuantumSystem<T1, T2> &qSystem);

    /**
     * @brief initialization of the matrixElements for QuantumSystem
     * 
     * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
     * @tparam T2 data type: double, std::complex<double> are supported
     * @param qSystem QuantumSystem to initilize
     */
    template <template <typename> class T1, typename T2>
    static void Filler(QuantumSystem<T1, T2> &qSystem);
};

} // namespace solid

#endif