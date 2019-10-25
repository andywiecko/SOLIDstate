/**
 * @file Particles.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief enum class for Particles
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef PARTICLES_HPP
#define PARTICLES_HPP

namespace solid
{

/**
 * @brief Particles enum class
 * 
 */
enum class Particles
{
	Fermions, //< spinless fermion particles
	Spins     //< spin 1/2 particles
};

}

#endif