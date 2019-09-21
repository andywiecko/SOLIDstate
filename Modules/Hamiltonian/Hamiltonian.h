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
	public:
		virtual ~Operator(){}
};

class KitaevHamiltonian : public Operator<mat>, public IHamiltonian
{
	public:

		virtual void FillElements()
		{
			int size = 8;
			matrixElements.set_size(size,size);
			matrixElements.fill(1.0);
		   
			cout << size << endl;
			//ParityGrandCanonical::SetSize();
			// terms
		}


};
