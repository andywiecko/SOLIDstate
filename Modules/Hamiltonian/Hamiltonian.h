#ifndef HAMILTONIAN_H
#define HAMILTONIAN_H

#include <cmath>
#include <armadillo>
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

#endif
