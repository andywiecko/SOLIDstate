/**
 * @file Timer.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Timer class header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TIMER_HPP
#define TIMER_HPP

#include <armadillo>
#include <string>

namespace solid
{

/**
 * @brief static clock class
 * 
 * measures time of the running program
 */
class Timer
{
public:
    
    static arma::wall_clock timer; /// clock class for time measurement
    static double timeInSec;       /// measured seconds

    /**
     * @brief starts the time measurement
     * 
     */
    static void Tic();

    /**
     * @brief displays time with attached message
     * 
     * @param message message to send (deault empty message: "")
     */
    static void Time(std::string message = "");

    /**
     * @brief (verbose version) displays time with attached message
     * 
     * @param message message message to send (deault empty message: "")
     */
    static void vTime(std::string message = "");
};

} // namespace solid

#endif