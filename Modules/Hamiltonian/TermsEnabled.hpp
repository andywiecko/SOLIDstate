/**
 * @file TermsEnabled.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief TermsEnabled header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TERMSENABLED_HPP
#define TERMSENABLED_HPP

#include "Particles.hpp"
#include "TermsEnum.hpp"

#include <vector>

namespace solid
{
/**
 * @brief Terms enebled in Operator
 * 
 */
class TermsEnabled
{
public:
    Particles particles = Particles::Fermions;
    std::vector<TermsEnum> terms;
    bool Hop = false;                  /// hopping between selected sites
    bool OneBodyInteraction = false;   /// one body interaction (e.g. chemical potential)
    bool TwoBodyInteraction = false;   /// two body interaction (e.g. Coulomb repulsion)
    bool ThreeBodyInteraction = false; /// three body interaction
    bool CreateParticle = false;       /// creates one particle at selected site
    bool CreatePair = false;           /// creates two particles at selected sites
    bool CreateTriple = false;         /// creates three particles at selected sites

    /**
	 * @brief when this option is enabled, particle number operators are decresed by 0.5
	 * 
	 * it transforms particle number operator in the following way: \f$\hat n_i \to \hat n_i-\frac12\f$
	 */
    bool N05option = false;
};
} // namespace solid

#endif