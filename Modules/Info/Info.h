#ifndef INFO_H
#define INFO_H

#include<iostream>
#include<vector>

class StandardMessages
{
	public:
		void Line();
		void ShowSectors(std::vector<Sector> sectors);
		
};

class Info : public StandardMessages
{

};

#endif