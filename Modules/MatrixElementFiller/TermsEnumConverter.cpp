#include "TermsEnumConverter.hpp"

namespace solid
{

template <template <typename> class T1, typename T2>
mapTermsFunction<T1, T2> TermsEnumConverter<T1, T2>::CreateDict()
{
    mapTermsFunction<T1, T2> dict;
    dict[TermsEnum::FermionHop] = [](QuantumSystem<T1, T2> &qSystem) { HopTermFermions::FillElements(qSystem); };
    dict[TermsEnum::FermionOneBodyInteraction] = [](QuantumSystem<T1, T2> &qSystem) { OneBodyInteractionTermFermions::FillElements(qSystem); };
    dict[TermsEnum::FermionTwoBodyInteraction] = [](QuantumSystem<T1, T2> &qSystem) { TwoBodyInteractionTermFermions::FillElements(qSystem); };
    dict[TermsEnum::FermionCreatePair] = [](QuantumSystem<T1, T2> &qSystem) { CreatePairTermFermions::FillElements(qSystem); };

    return dict;
}

template <template <typename> class T1, typename T2>
mapTermsFunction<T1, T2> TermsEnumConverter<T1, T2>::dict = TermsEnumConverter<T1, T2>::CreateDict();

} // namespace solid