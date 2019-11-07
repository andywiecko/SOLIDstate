#include "TermsEnumConverter.hpp"

namespace solid
{

template <template <typename> class T1, typename T2>
std::map<TermsEnum, std::function<void(QuantumSystem<T1, T2>&)>> TermsEnumConverter<T1, T2>::CreateDict()
{
    std::map<TermsEnum, std::function<void(QuantumSystem<T1, T2>&)>> dict;
    dict[TermsEnum::Hop] = [](QuantumSystem<T1, T2> &qSystem) { HopTermFermions::FillElements(qSystem); };
    dict[TermsEnum::OneBodyInteraction] = [](QuantumSystem<T1, T2> &qSystem) { OneBodyInteractionTermFermions::FillElements(qSystem);};
    dict[TermsEnum::TwoBodyInteraction] = [](QuantumSystem<T1, T2> &qSystem) { TwoBodyInteractionTermFermions::FillElements(qSystem);};
    dict[TermsEnum::CreatePair] = [](QuantumSystem<T1, T2> &qSystem) { CreatePairTermFermions::FillElements(qSystem);};
    //TODO//dict[TermsEnum::Hop] = [](QuantumSystem<T1, T2> &qSystem) { HopTermFermions::FillElements(qSystem); };
    //dict[TermsEnum::Hop] = [](QuantumSystem<T1, T2> &qSystem) { HopTermFermions::FillElements(qSystem); };

    return dict;
}

template <template <typename> class T1, typename T2>
std::map<TermsEnum, std::function<void(QuantumSystem<T1, T2>&)>> TermsEnumConverter<T1, T2>::dict = TermsEnumConverter<T1,T2>::CreateDict();

} // namespace solid