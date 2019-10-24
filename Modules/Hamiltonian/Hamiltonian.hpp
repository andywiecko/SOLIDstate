#ifndef HAMILTONIAN_HPP
#define HAMILTONIAN_HPP

namespace solid
{

// Hamiltonian interface
class IHamiltonian
{
public:
	// See TermsEnabled for defaults
	// Hop (not implemented yet)
	// OneBodyInteraction
	// TwoBodyInteraction (not implemented yet)
	// ThreeBodyInteraction (not implemented yet)
	// CreateParticle (not implemented yet)
	// CreatePair (not implemented yet)
	// CreateTriple (not implemented yet)
	virtual void SelectTerms() = 0;
	virtual ~IHamiltonian() {}
};

enum class Particles
{
	Fermions,
	Spins
};

// Terms enabled in Operator
class TermsEnabled
{
public:
	Particles particles = Particles::Fermions;
	bool Hop = false;
	bool OneBodyInteraction = false;
	bool TwoBodyInteraction = false;
	bool ThreeBodyInteraction = false;
	bool CreateParticle = false;
	bool CreatePair = false;
	bool CreateTriple = false;
	bool N05option = false;
};

// TODO: should be temaplate sparse, dense, complex double,...
template <template <typename> class T1, typename T2>
class Operator
{
public:
	T1<T2> matrixElements;
	TermsEnabled termsEnabled;
	virtual ~Operator() {}
};

} // namespace solid

#endif
