#ifndef LABORATORY_HPP
#define LABORATORY_HPP

#include "../QuantumState/QuantumState.hpp"
#include "../QuantumSystem/QuantumSystem.hpp"

#include <armadillo>

namespace solid
{
    /**
     * @brief contains static methods for measurement
     * 
     */
    class Laboratory
    {
        /**
         * @brief measures dot product between QuantumState and QuantumSystem
         * 
         * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
         * @tparam T2 data type: double, std::complex<double> are supported
         * @return T2 returns scalar product < QuamtumState | QuantumSystem | QuantumState >
         * 
         * Returns \f$\langle \psi | \hat {\mathcal O} | \psi \rangle \f$, 
         * where \f$|\psi\rangle\f$ is QuantumState 
         * and \f$\hat {\mathcal O}\f$ are current matrixElements in QuantumSystem
         */
        template <template <typename> class T1, typename T2>
        static T2 Measure(QuantumSystem<T1,T2> &, QuantumState<T2> &);

    };
}

#endif