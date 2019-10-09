#ifndef TERM_HPP
#define TERM_HPP

#include "../QuantumSystem/QuantumSystem.hpp"
namespace solid
{

class ITerm
{
public:
	virtual void FillElements() = 0;
	virtual ~ITerm() {}
};

} // namespace solid

#endif