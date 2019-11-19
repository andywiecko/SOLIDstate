#ifndef TERMSTYPECONVERTER_HPP
#define TERMSTYPECONVERTER_HPP

#include <map>
#include <string>

#include "../Terms/Hop.hpp"
#include "../Terms/OneBodyInteraction.hpp"
#include "../Terms/TwoBodyInteraction.hpp"
#include "../Terms/CreatePair.hpp"

namespace solid
{

class TermsTypeConverter
{
private:
    static std::map<std::string, TermsTypeEnum> CreateDict();

public:
    static std::map<std::string, TermsTypeEnum> dict;
};

std::map<std::string, TermsTypeEnum> TermsTypeConverter::CreateDict()
{
    std::map<std::string, TermsTypeEnum> dict;
    dict[HopTermFermions::label] = HopTermFermions::type;
    dict[OneBodyInteractionTermFermions::label] = OneBodyInteractionTermFermions::type;
    dict[TwoBodyInteractionTermFermions::label] = TwoBodyInteractionTermFermions::type;
    dict[CreatePairTermFermions::label] = CreatePairTermFermions::type;
    return dict;
    // TODO Spins
}

std::map<std::string, TermsTypeEnum> TermsTypeConverter::dict = TermsTypeConverter::CreateDict();

} // namespace solid

#endif