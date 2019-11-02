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

namespace solid
{

class DynamicsSchedule
{
public:
    double time_init;
    double time_final;
    double time_step;

    std::function<double()> fun;


};

} // namespace solid