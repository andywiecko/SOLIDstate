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
    void CreateDict();

public:
    static std::map<std::string, TermsTypeEnum> dict;
};

void TermsTypeConverter::CreateDict()
{
    dict[HopTermFermions::label] = HopTermFermions::type;
    dict[OneBodyInteractionTermFermions::label] = OneBodyInteractionTermFermions::type;
    dict[TwoBodyInteractionTermFermions::label] = TwoBodyInteractionTermFermions::type;
    dict[CreatePairTermFermions::label] = CreatePairTermFermions::type;
}

} // namespace solid

#endif