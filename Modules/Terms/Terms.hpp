#ifndef TERM_HPP
#define TERM_HPP

#include "../QuantumSystem/QuantumSystem.hpp"

class ITerm
{
public:
	virtual void FillElements() = 0;
	virtual ~ITerm() {}
};

#endif