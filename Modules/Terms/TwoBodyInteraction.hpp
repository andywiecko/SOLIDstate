#ifndef TWOBODYINTERACTION_HPP
#define TWOBODYINTERACTION_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
#include "../Combinadics/BaseState.hpp"
#include "Terms.hpp"
#include <armadillo>
namespace solid
{
	
class TwoBodyInteractionTermFermions : public ITerm
{
public:
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

class TwoBodyInteractionTermSpins : public ITerm
{
public:
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

} // namespace solid

#endif