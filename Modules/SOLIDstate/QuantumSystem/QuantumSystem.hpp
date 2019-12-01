/**
 * @file QuantumSystem.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Quantum System class header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef QUANTUMSYSTEM_QUANTUMSYSTEM_HPP
#define QUANTUMSYSTEM_QUANTUMSYSTEM_HPP

#include "../HilbertSpace/HilbertSpace.hpp"
#include "../Hamiltonian/Hamiltonian.hpp"
#include "../Parameters/Parameters.hpp"
#include "../Geometry/Geometry.hpp"
#include "../Observable/Observable.hpp"
#include "../Factory/Factory.hpp"
#include "../QuantumState/QuantumState.hpp"

namespace solid
{

/**
 * @brief general purpouse class for solving quantum systems
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 * 
 * class contains:
 *  * HilbertSpace
 *      * Ensemble
 *      * BaseState iterators
 *  * IHamiltonian (Operator)
 *  * system Parameters
 */
template <template <typename> class T1, typename T2>
class QuantumSystem
{
public:
    /**
     * @brief selected HilbertSpace for the QuantumSystem
     */
    HilbertSpace hilbertSpace;

    /**
     * @brief container for matrixElements
     */
    Operator<T1, T2> hamiltonian;

    /**
     * @brief Parameters for hamiltonian
     */
    Parameters<T2> parameters; // TODO make it private?

    /**
     * @brief fills matrixElements for selected Hamiltonian, 
     * with respect to HilbertSpace (Ensemble) and system Parameters
     */
    void Fill();

    /**
     * @brief selects Ensemble for QuantumSystem
     * 
     * @tparam Ens Ensemble template (e.g. GrandCanonical, Canonical)
     * @tparam Targs Ensemble specific argument types 
     * @param Fargs  Ensemble specific arguments (e.g. number of particles \f$N\f$ or parity)
     */
    template <class Ens, typename... Targs>
    void SelectEnsemble(Targs... Fargs);

    /**
     * @brief selects IHamiltonian for QuantumSystem
     * 
     * @tparam Ham IHamiltonian template (e.g. KitaevHamiltonian)
     */
    template <template <template <typename> class, typename> class Ham>
    void SelectHamiltonian();

    /**
     * @brief selects Observable for QuantumSystem
     * 
     * @tparam Obs Observable template
     * @tparam Targs Observable specific argument types
     * @param Fargs Observable specific arguments (e.g. number of sites \f$L\f$)
     */
    template <template <template <typename> class, typename> class Obs, typename... Targs>
    void SelectObservable(Targs... Fargs);

    /**
     * @brief Select Parameters of the QuantumSystem
     * 
     * @param parameters Parameters
     */
    void SelectParameters(Parameters<T2> &parameters);

    /**
     * @brief Select Geometry (predefined Parameters)
     * 
     * @param geometry Geometry
     */
    void SelectParameters(Geometry<T2> &geometry);

};

} // namespace solid

#endif