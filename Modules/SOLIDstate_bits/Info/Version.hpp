/**
 * @file Version.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Version class header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef INFO_VERSION_HPP
#define INFO_VERSION_HPP

#include <string>
#include <armadillo>

namespace solid
{

/**
 * @brief constant char* about solid version
 */
class Version
{
public:
    /**
    * @brief current solid version 
    */
    static constexpr const char *solidVersion = "0.100.0 (Alpha WIP)";
};

} // namespace solid

#endif