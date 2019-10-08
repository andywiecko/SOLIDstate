#ifndef ONEBODYINTERACTION_HPP
#define ONEBODYINTERACTION_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
#include "Terms.hpp"

class OneBodyInteractionTermFermions : public ITerm
{
public:
	template <template <typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

class OneBodyInteractionTermSpins : public ITerm
{
public:
	template <template<typename> class T1, typename T2>
	static void FillElements(QuantumSystem<T1, T2> &system);
};

#endif