/**
 * @file Timer.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Timer class implementation
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Timer.hpp"
#include "Info.hpp"
#include <iomanip>

namespace solid
{

// TODO const move somewhere else
const std::string green("\033[1;32m");
const std::string red("\033[0;31m");
const std::string reset("\033[0m");

void Timer::Time(std::string message /*default =""*/)
{
    //std::ios::fmtflags old_settings = std::cout.flags();
    //int old_precision = std::cout.precision();
    std::cout << std::fixed << std::setprecision(6) << std::setfill('0');
    std::cout << "#" << green << " [ " << std::setw(12) << timer.toc();
    std::cout << " ] " << red << message << reset;
    //std::cout.flags(old_settings);
    //std::cout.precision(old_precision);
}

void Timer::Tic()
{
    timer.tic();
}

void Timer::vTime(std::string message /*default =""*/)
{
    if (Info::isVerbose)
        Time(message);
}

} // namespace solid