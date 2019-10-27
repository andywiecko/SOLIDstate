#include "Modules/SOLIDstate.hpp"

#include <armadillo>
using namespace arma;
using namespace solid;



int main(int argc, char *argv[])
{

	ArgvParser::Parse(argc, argv);
	
	Info::Start();
		
	int L = 4;

	QuantumSystem<Mat, double> qSystem;

	//qSystem.SelectEnsemble<Canonical>(L,L/2);
	qSystem.SelectEnsemble<ParityGrandCanonical>(L,0);
	//qSystem.SelectEnsemble<GrandCanonical>(L);

	Info::ShowSectors(qSystem.hilbertSpace.ensemble);
	//Info::ShowSectors(qSystem); // other implementation 
	
	vec mu;
	mu.set_size(L);
	mu.fill(1);

	sp_mat V;
	V.set_size(L, L);
	//V(0, 1) = 1;

	sp_mat t(L,L);
	for(int i=0;i<L;i++) t(i,(i+1)%L) = 1.0;
	for(int i=0;i<L;i++) t((i+1)%L,i) = 1.0;
	mat(t).print();

	Parameters<double> param;

	param['M'] = mu;
	param['V'] = V;
	param['t'] = t;

	qSystem.parameters = param;

	qSystem.SelectHamiltonian<KitaevHamiltonian>();
	qSystem.Fill();
	//MatrixElementFiller::Fill(qSystem);

	mat eigvec;
	vec eigval;
	eig_sym(eigval,eigvec,qSystem.hamiltonian.matrixElements);
	eigval.t().print();

	qSystem.hamiltonian.matrixElements.print();

	return 0;

	qSystem.SelectObservable<ParticleNumberOperator>(L);
	MatrixElementFiller::Fill(qSystem);
	ParticleNumberOperator<Mat,double>::Preprocessing(qSystem.hamiltonian.matrixElements);


	qSystem.hamiltonian.matrixElements.print();

	qSystem.SelectObservable<ParityOperator>(L);
	MatrixElementFiller::Fill(qSystem);
	ParityOperator<Mat,double>::Preprocessing(qSystem.hamiltonian.matrixElements);

	qSystem.hamiltonian.matrixElements.print();

	Info::Time();

	return 0;
}