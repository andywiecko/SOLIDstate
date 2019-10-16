#ifndef STANDARDMESSAGES_HPP
#define STANDARDMESSAGES_HPP

#include<string>
#include "../Ensemble/Ensemble.hpp"

namespace solid
{

class StandardMessages
{
public:
	static void Line();
	static void ShowSectors(Ensemble ensemble);
	static void Message(std::string);
	static void vMessage(std::string);
};

}

#endif