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

#include "../Terms/TermsEnum.hpp"

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

	/**
	 * @brief container for terms, which are included in the IHamiltonian implementation or Operator
	 */
	std::vector<TermsEnum> terms;

	/**
	 * @brief when this option is enabled, particle number operators are decresed by 0.5
	 * 
	 * it transforms particle number operator in the following way: \f$\hat n_i \to \hat n_i-\frac12\f$
	 */
	bool N05option = false;
};
} // namespace solid

#endif