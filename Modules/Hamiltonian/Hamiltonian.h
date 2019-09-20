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

class KitaevHamiltonian : public Operator<mat>, public IHamiltonian, public GrandCanonical
{
	public:
		
		virtual void FillElements()
		{
	   		L = 4;
			int size = SetSize();
			matrixElements.set_size(size,size);
			matrixElements.fill(1.0);
			//matrixElements.print();
		   
			cout << size << endl;
			//ParityGrandCanonical::SetSize();
			// terms
		}


};
