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

#include "SOLIDstate_bits/Combinadics/BaseState.hpp"
#include "SOLIDstate_bits/Combinadics/Binomials.hpp"
#include "SOLIDstate_bits/Combinadics/Combinadics.hpp"

#include "SOLIDstate_bits/Ensemble/Ensemble.hpp"
#include "SOLIDstate_bits/Ensemble/Sector.hpp"
#include "SOLIDstate_bits/Ensemble/Canonical.hpp"
#include "SOLIDstate_bits/Ensemble/GrandCanonical.hpp"
#include "SOLIDstate_bits/Ensemble/ParityGrandCanonical.hpp"

#include "SOLIDstate_bits/Eigensolver/Eigensolver.hpp"

#include "SOLIDstate_bits/Hamiltonian/Hamiltonian.hpp"
#include "SOLIDstate_bits/Hamiltonian/KitaevHamiltonian.hpp"

#include "SOLIDstate_bits/Factory/Factory.hpp"

#include "SOLIDstate_bits/Geometry/Geometry.hpp"
#include "SOLIDstate_bits/Geometry/Chain.hpp"
#include "SOLIDstate_bits/Geometry/Ring.hpp"

#include "SOLIDstate_bits/HilbertSpace/HilbertSpace.hpp"

#include "SOLIDstate_bits/Info/Info.hpp"
#include "SOLIDstate_bits/Info/Argv.hpp"
//#include "Info/Version.hpp"

#include "SOLIDstate_bits/Laboratory/Laboratory.hpp"

#include "SOLIDstate_bits/QuantumSystem/QuantumSystem.hpp"
#include "SOLIDstate_bits/QuantumState/QuantumState.hpp"

#include "SOLIDstate_bits/Terms/Terms.hpp"

#include "SOLIDstate_bits/QuantumDynamics/DynamicsSchedule.hpp"
#include "SOLIDstate_bits/QuantumDynamics/QuantumDynamics.hpp"

#include "SOLIDstate_bits/MatrixElementFiller/MatrixElementFiller.hpp"

#include "SOLIDstate_bits/Observable/Observable.hpp"
#include "SOLIDstate_bits/Observable/ParticleNumberOperator.hpp"
#include "SOLIDstate_bits/Observable/ParityOperator.hpp"

#include "SOLIDstate_bits/Parameters/Parameters.hpp"
#include "SOLIDstate_bits/Parameters/ParametersChecker.hpp"

/**
 * @mainpage SOLIDstate: C++ library
 * 
 * This project helps user to draw shapes.
 * Currently two types of shapes can be drawn:
 * - @subpage drawingRectanglePage "How to draw rectangle?"
 *
 * - @subpage drawingCirclePage "How to draw circle?"
 *
 */ 

/** @page drawingRectanglePage How to draw rectangle?
 *
 * Lorem ipsum dolor sit amet
 *
 */

/** @page drawingCirclePage How to draw circle?
 *
 * This page is about how to draw a circle.
 * Following sections describe circle:
 * - @ref groupCircleDefinition "Definition of Circle"
 * - @ref groupCircleClass "Circle Class"
 */

/** @defgroup groupCircleDefinition Circle Definition
 * A circle is a simple shape in Euclidean geometry.
 * It is the set of all points in a plane that are at a given distance from a given point, the centre;
 * equivalently it is the curve traced out by a point that moves so that its distance from a given point is constant.
 * The distance between any of the points and the centre is called the radius.
 */

/**
 * @brief SOLIDstate namespace
 */
namespace solid{}


#endif