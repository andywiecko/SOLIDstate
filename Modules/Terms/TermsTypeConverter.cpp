#include "TermsTypeConverter.hpp"

namespace solid 
{

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


}