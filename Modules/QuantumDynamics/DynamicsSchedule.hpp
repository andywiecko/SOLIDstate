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
#ifndef DYNAMICSSCHEDULE_HPP
#define DYNAMICSSCHEDULE_HPP


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
    double time_init = 0;
    double time_final = 1;
    double time_step = 0.01;

    ScheduleMap<T> dict;
};

template <template <typename> class T1, typename T2>
class MeasurementSchedule
{
public:
    // what to measure (list of operators to measure)
    std::function<void(QuantumSystem<T1,T2>)> Measure;

    // when to measure (function/functor)
    TimeToMeasure timeToMeasure;
};



} // namespace solid

#endif