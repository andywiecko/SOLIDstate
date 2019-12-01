/**
 * @file Terms.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Terms interface header
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TERMS_TERM_HPP
#define TERMS_TERM_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
namespace solid
{

/**
 * @brief interface for Terms class
 * 
 * Abstract class containg one purely virtual function
 */
class ITerm
{
public:
	
	/**
	 * @brief Filling the matrixElement 
	 * 
	 * Purely virtual function to override
	 * for ITerm implementation
	 */
	virtual void FillElements() = 0;

	/**
	 * @brief Destroy the ITerm object
	 * 
	 */
	virtual ~ITerm() {}
};

} // namespace solid

#endif