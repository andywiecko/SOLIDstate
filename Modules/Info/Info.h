#include<vector>

class StandardMessages
{
	public:
		void Line()
		{
			std::cout << "##############################################" << std::endl;
		}

		void ShowSectors(std::vector<Sector> sectors)	
		{
			Line();
			std::cout << "# Ensamble has " << sectors.size() <<" sectors:" << std::endl;
			for (int i=0;i<sectors.size();i++) 
		  	{
				Sector sec = sectors[i];
				std::cout << "# sector with: L=" << sec.L << " N=" << sec.N << " (size=" << sec.size << ")" << std::endl;
			}
			Line();
		}

};

class Info : public StandardMessages
{

};
