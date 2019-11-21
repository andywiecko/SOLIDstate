#ifndef TERMSTYPECONVERTER_HPP
#define TERMSTYPECONVERTER_HPP

#include <map>
#include <string>

#include "../Terms/Hop/Hop.hpp"
#include "../Terms/OneBodyInteraction/OneBodyInteraction.hpp"
#include "../Terms/TwoBodyInteraction/TwoBodyInteraction.hpp"
#include "../Terms/CreatePair/CreatePair.hpp"

namespace solid
{

class TermsTypeConverter
{
private:
    static std::map<std::string, TermsTypeEnum> CreateDict();

public:
    static std::map<std::string, TermsTypeEnum> dict;
};


} // namespace solid

#endif