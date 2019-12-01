/**
 * @file TermsTypeConverter.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Terms Type Converter class header
 * @version 0.100.0
 * @date 2019-11-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TERMS_TERMSTYPECONVERTER_HPP
#define TERMS_TERMSTYPECONVERTER_HPP

#include <map>
#include <string>

#include "../Terms/Hop/Hop.hpp"
#include "../Terms/OneBodyInteraction/OneBodyInteraction.hpp"
#include "../Terms/TwoBodyInteraction/TwoBodyInteraction.hpp"
#include "../Terms/CreatePair/CreatePair.hpp"

namespace solid
{

/**
 * @brief Class for translating labels (e.g M, V) into TermsTypeEnum
 */
class TermsTypeConverter
{
private:
    /**
     * @brief Create a Dict object which contains std::map between label and TermsTypeEnum
     * 
     * @return std::map<std::string, TermsTypeEnum> 
     */
    static std::map<std::string, TermsTypeEnum> CreateDict();

public:
    /**
     * @brief Dict which contains std::map between label and TermsTypeEnum
     */
    static std::map<std::string, TermsTypeEnum> dict;
};

} // namespace solid

#endif