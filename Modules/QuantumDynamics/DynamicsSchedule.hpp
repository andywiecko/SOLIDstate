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
using Schedule = std::function<void(T &, double)>;

template <class T>
using ScheduleMap = std::map<std::string, Schedule<T>>;

typedef std::function<bool(double)> TimeToMeasure;

template <class T>
class DynamicsSchedule
{
public:
    double time_init;
    double time_final;
    double time_step;

    ScheduleMap<T> dict;
};

class MeasurementSchedule
{
public:
    // what to measure (list of operators to measure)

    // when to measure (function/functor)
    TimeToMeasure timeToMeasure;
};

} // namespace solid