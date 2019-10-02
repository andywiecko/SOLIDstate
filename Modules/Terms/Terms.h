#ifndef TERM_H
#define TERM_H

#include "../QuantumSystem/QuantumSystem.h"

class ITerm
{
public:
	virtual void FillElements() = 0;
	virtual ~ITerm() {}
};

#endif