#ifndef TIMER_HPP
#define TIMER_HPP

#include <armadillo>
#include <string>

namespace solid
{

class Timer
{
public:
    static arma::wall_clock timer;
    static double timeInSec;
    static void Tic()
    {
        timer.tic();
    }
    static void Time(std::string message = "");
    static void vTime(std::string message = "");
};

} // namespace solid

#endif