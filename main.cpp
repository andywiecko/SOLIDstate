#include<armadillo>

// ensemble to set size of the operator 
#include "Ensemble/Ensemble.h"

class IHamiltonian
{
	public:
		virtual void FillElements() = 0;		  
		virtual ~IHamiltonian(){}
};

// should be temaplate sparse, dense, complex double,...
class Operator
{
	public:
		arma::mat matrixElements;
	public:
		virtual ~Operator(){}
};

class KitaevHamiltonian : public Operator, public IHamiltonian, public ParityGrandCanonical
{
	public:
		virtual void FillElements()
		{
			// terms
		}

};

#include "Factory.h"

int main()
{

	Operator ham = Factory::CreateHamiltonian();
	ham.matrixElements.print();
			  
	return 0;
}
