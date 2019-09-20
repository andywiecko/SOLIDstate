#include<vector>
using namespace arma;

class IHamiltonian
{
	public:
		virtual void FillElements() = 0;		  
		virtual ~IHamiltonian(){}
};

// should be temaplate sparse, dense, complex double,...
template<class T>
class Operator
{
	public:
		T matrixElements;
		std::vector<Sector> sectors;
	public:
		virtual ~Operator(){}
};

class KitaevHamiltonian : public Operator<mat>, public IHamiltonian, public CompleteCanonical
{
	public:
		
		virtual void FillElements()
		{
	   	L = 4;
			matrixElements.set_size(10,10);
			matrixElements.fill(1.0);
			//matrixElements.print();
		   
			cout << SetSize() << endl;
			//ParityGrandCanonical::SetSize();
			// terms
		}


};
