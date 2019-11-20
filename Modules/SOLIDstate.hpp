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

#include "Eigensolver/Eigensolver.hpp"

#include "Hamiltonian/Hamiltonian.hpp"
#include "Hamiltonian/KitaevHamiltonian.hpp"

#include "Factory/Factory.hpp"

#include "Geometry/Geometry.hpp"
#include "Geometry/Chain.hpp"
#include "Geometry/Ring.hpp"

#include "HilbertSpace/HilbertSpace.hpp"

#include "Info/Info.hpp"
#include "Info/Argv.hpp"
//#include "Info/Version.hpp"

#include "Laboratory/Laboratory.hpp"

#include "QuantumSystem/QuantumSystem.hpp"
#include "QuantumState/QuantumState.hpp"

#include "Terms/Terms.hpp"

#include "QuantumDynamics/DynamicsSchedule.hpp"
#include "QuantumDynamics/QuantumDynamics.hpp"

#include "MatrixElementFiller/MatrixElementFiller.hpp"

#include "Observable/Observable.hpp"
#include "Observable/ParticleNumberOperator.hpp"
#include "Observable/ParityOperator.hpp"

#include "Parameters/Parameters.hpp"
#include "Parameters/ParametersChecker.hpp"

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