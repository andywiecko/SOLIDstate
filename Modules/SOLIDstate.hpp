/**
 * @file SOLIDstate.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief 
 * @version 0.100.0
 * @date 2019-10-23
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef SOLIDSTATE_HPP
#define SOLIDSTATE_HPP

#include "Combinadics/BaseState.hpp"
#include "Combinadics/Binomials.hpp"
#include "Combinadics/Combinadics.hpp"

#include "Ensemble/Ensemble.hpp"
#include "Ensemble/Sector.hpp"
#include "Ensemble/Canonical.hpp"
#include "Ensemble/GrandCanonical.hpp"
#include "Ensemble/ParityGrandCanonical.hpp"

#include "Hamiltonian/Hamiltonian.hpp"
#include "Hamiltonian/KitaevHamiltonian.hpp"

#include "Factory/Factory.hpp"

#include "HilbertSpace/HilbertSpace.hpp"

#include "Info/Info.hpp"
#include "Info/Argv.hpp"
#include "Info/Version.hpp"

#include "QuantumSystem/QuantumSystem.hpp"

#include "Terms/Terms.hpp"
#include "Terms/OneBodyInteraction.hpp"
#include "Terms/TwoBodyInteraction.hpp"

#include "MatrixElementFiller/MatrixElementFiller.hpp"

#include "Observable/Observable.hpp"
#include "Observable/ParticleNumberOperator.hpp"
#include "Observable/ParityOperator.hpp"

#include "Parameters/Parameters.hpp"

/**
 * @brief SOLIDstate namespace
 */
namespace solid{}


#endif