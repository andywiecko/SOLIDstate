/**
 * @file KitaevHamiltonian.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Kitaev Hamiltonian header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef KITAEVHAMILTONIAN_HPP
#define KITAEVHAMILTONIAN_HPP

#include "Hamiltonian.hpp"

namespace solid
{

/**
 * @brief [Kitaev Hamiltonian](https://arxiv.org/pdf/cond-mat/0010440.pdf) implementation
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type: double, std::complex<double> are supported
 * 
 * Kitaev Hamiltonian extended by the many-body interaction.
 * Model can be described by the following Hamiltonian:
 * \f[ \hat H = \sum_{ij}\left(-t_{ij}a_i^\dagger a_j +\text{H.c.}\right)
 *              +\sum_{ij}\left(\Delta_{ij}a_i^\dagger a_j^\dagger +\text{H.c.}\right)
 *              +\sum_{ij}V_{ij}\hat n_i \hat n_j
 * 				+\sum_i \mu_i \hat n_i
 *   \f]
 */
template <template <typename> class T1, typename T2>
class KitaevHamiltonian : public Operator<T1, T2>, public IHamiltonian
{
	using Operator<T1, T2>::termsEnabled;

public:
	void SelectTerms() override
	{
		// Fermions are default, but it is good to stress out
		termsEnabled.particles = Particles::Fermions;
		termsEnabled.OneBodyInteraction = true;
		termsEnabled.TwoBodyInteraction = true;
		//termsEnabled.N05option = true;
	}
};

} // namespace solid

#endif