#ifndef STANDARDMESSAGES_HPP
#define STANDARDMESSAGES_HPP

#include<string>
#include "../Ensemble/Ensemble.hpp"
#include "../QuantumSystem/QuantumSystem.hpp"

namespace solid
{

class StandardMessages
{
public:
	static void Line();
	static void ShowSectors(Ensemble & ensemble);
	template <template <typename> class T1, typename T2>
	static void ShowSectors(QuantumSystem<T1,T2> & qSystem);
	static void Message(std::string);
	static void vMessage(std::string);
};

}

#endif