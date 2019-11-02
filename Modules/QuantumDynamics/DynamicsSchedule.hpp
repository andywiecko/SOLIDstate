/**
 * @file DynamicsSchedule.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Dynamics Schedule header
 * @version 0.100.0
 * @date 2019-11-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <functional>
#include <map>
#include <string>

namespace solid
{

template <class T>
using Schedule = std::function<void(T&,double)>;

template <class T>
using ScheduleMap = std::map<std::string, Schedule<T> >;

template <class T>
class DynamicsSchedule
{
public:
    double time_init;
    double time_final;
    double time_step;

    ScheduleMap<T> dict;
};

} // namespace solid