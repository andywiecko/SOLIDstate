#ifndef TERMSENUMCONVERTER_HPP
#define TERMSENUMCONVERTER_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
#include "../Hamiltonian/TermsEnum.hpp"
#include "../Terms/Hop.hpp"
#include "../Terms/OneBodyInteraction.hpp"
#include "../Terms/TwoBodyInteraction.hpp"
#include "../Terms/CreatePair.hpp"

#include <map>
#include <functional>

namespace solid
{

template <template <typename> class T1, typename T2>
using mapTermsFunction = std::map<TermsEnum, std::function<void(QuantumSystem<T1, T2> &)>>;

template <template <typename> class T1, typename T2>
class TermsEnumConverter
{

    static mapTermsFunction<T1, T2> CreateDict();

public:
    static mapTermsFunction<T1, T2> dict;
    static void FermionsTerms()
    {

    }
};

} // namespace solid

#endif