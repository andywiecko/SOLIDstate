#ifndef HAMILTONIAN_H
#define HAMILTONIAN_H

#include <cmath>
#include <armadillo>
using namespace arma;

// Hamiltonian interface
class IHamiltonian
{
	public:
		virtual void SelectTerms() = 0;
		virtual ~IHamiltonian(){}
};

// Terms enabled in Operator
class TermsEnabled
{
	public:
		bool OneBodyTerm = false;
		bool Hop = false;
        bool OneBodyInteraction = false;
        bool TwoBodyInteraction = false;
        bool ThreeBodyInteraction = false;
        bool CreateParticle = false;
        bool CreatePair = false;
        bool CreateTriple = false;
};

// TODO: should be temaplate sparse, dense, complex double,...
template<class T>
class Operator
{
	public:
		T matrixElements;
		TermsEnabled termsEnabled;
		virtual ~Operator(){}
};

#endif
