#ifndef TERM_H
#define TERM_H

#include "../QuantumSystem/QuantumSystem.h"


class ITerm
{
	public:
		virtual void FillElements() = 0;
		virtual ~ITerm(){}
};

class OneBodyInteractionTerm : public ITerm
{
	public:
		template<typename T>
		static void FillElements(QuantumSystem<T> &system, vec interactions);
};

template<typename T>
void OneBodyInteractionTerm::FillElements(QuantumSystem<T> &system, vec interactions)
{
	//system.hilbertSpace.

}

#endif