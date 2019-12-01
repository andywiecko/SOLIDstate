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
#ifndef QUANTUMDYNAMICS_DYNAMICSSCHEDULE_HPP
#define QUANTUMDYNAMICS_DYNAMICSSCHEDULE_HPP

#include <functional>
#include <map>
#include <string>

namespace solid
{

/**
 * @brief typedef for function of parameters (T) and time (double)
 * 
 * @tparam T parameters, e.g. arma::SpMat<double>
 */
template <class T>
using Schedule = std::function<void(T &, double)>;

/**
 * @brief typedef for map of label and Schedule<T>
 * 
 * @tparam T parameters, e.g. arma::SpMat<double>
 */
template <class T>
using ScheduleMap = std::map<std::string, Schedule<T>>;

/**
 * @brief typedef for function that returns bool (time to measure?) from argument double (time)
 * 
 */
typedef std::function<bool(double)> TimeToMeasure;

/**
 * @brief Schedule for the dynamics (uniform time step)
 * 
 * @tparam T parameters, e.g. arma::SpMat<double>
 */
template <class T>
class DynamicsSchedule
{
public:
    double time_init = 0;    /*!< initial time */
    double time_final = 1;   /*!< final time */
    double time_step = 0.01; /*!< time step */

    ScheduleMap<T> dict; /*!< Schedule dictionary */

    // TODO
    // * const times
    // * add constructor?
    // * private times/dict?
};

/**
 * @brief Schedule for the measurment
 * 
 * @tparam T1 matrix type: arma::Mat and arma:SpMat are supported
 * @tparam T2 data type of QuantumSystem: double, std::complex<double> are supported
 * @tparam T3=T2 data type of QuantumState: double, std::complex<double> are supported
 */
template <template <typename> class T1, typename T2, typename T3 = T2>
class MeasurementSchedule
{
public:
    /**
     * @brief what to measure? (list of operators to measure)
     */
    std::function<void(QuantumSystem<T1, T2> &, QuantumState<T3> &)> Measure;

    /**
     * @brief when to measure? (function/functor)
     */
    TimeToMeasure timeToMeasure;
};

} // namespace solid

#endif