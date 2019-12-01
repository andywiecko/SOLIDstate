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

#include "SOLIDstate/Combinadics/BaseState.hpp"
#include "SOLIDstate/Combinadics/Binomials.hpp"
#include "SOLIDstate/Combinadics/Combinadics.hpp"

#include "SOLIDstate/Ensemble/Ensemble.hpp"
#include "SOLIDstate/Ensemble/Sector.hpp"
#include "SOLIDstate/Ensemble/Canonical.hpp"
#include "SOLIDstate/Ensemble/GrandCanonical.hpp"
#include "SOLIDstate/Ensemble/ParityGrandCanonical.hpp"

#include "SOLIDstate/Eigensolver/Eigensolver.hpp"

#include "SOLIDstate/Hamiltonian/Hamiltonian.hpp"
#include "SOLIDstate/Hamiltonian/KitaevHamiltonian.hpp"

#include "SOLIDstate/Factory/Factory.hpp"

#include "SOLIDstate/Geometry/Geometry.hpp"
#include "SOLIDstate/Geometry/Chain.hpp"
#include "SOLIDstate/Geometry/Ring.hpp"

#include "SOLIDstate/HilbertSpace/HilbertSpace.hpp"

#include "SOLIDstate/Info/Info.hpp"
#include "SOLIDstate/Info/Argv.hpp"
//#include "Info/Version.hpp"

#include "SOLIDstate/Laboratory/Laboratory.hpp"

#include "SOLIDstate/QuantumSystem/QuantumSystem.hpp"
#include "SOLIDstate/QuantumState/QuantumState.hpp"

#include "SOLIDstate/Terms/Terms.hpp"

#include "SOLIDstate/QuantumDynamics/DynamicsSchedule.hpp"
#include "SOLIDstate/QuantumDynamics/QuantumDynamics.hpp"

#include "SOLIDstate/MatrixElementFiller/MatrixElementFiller.hpp"

#include "SOLIDstate/Observable/Observable.hpp"
#include "SOLIDstate/Observable/ParticleNumberOperator.hpp"
#include "SOLIDstate/Observable/ParityOperator.hpp"

#include "SOLIDstate/Parameters/Parameters.hpp"
#include "SOLIDstate/Parameters/ParametersChecker.hpp"

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