#include "Modules/SOLIDstate.hpp"

#include <armadillo>
using namespace arma;
using namespace solid;



int main(int argc, char *argv[])
{

	ArgvParser::Parse(argc, argv);
	
	Info::Start();
		
	int L = 3;

	QuantumSystem<Mat, double> qSystem;

	//qSystem.SelectEnsemble<Canonical>(L,L/2);
	//qSystem.SelectEnsemble<ParityGrandCanonical>(L,0);
	qSystem.SelectEnsemble<GrandCanonical>(L);

	Info::ShowSectors(qSystem.hilbertSpace.ensemble);
	//Info::ShowSectors(qSystem); // other implementation 
	
	vec mu;
	mu.set_size(L);
	mu.fill(1);

	sp_mat V;
	V.set_size(L, L);
	V(0, 1) = 1;

	Parameters<double> param;

	param['M'] = mu;
	param['V'] = V;
	qSystem.parameters = param;

	qSystem.SelectHamiltonian<KitaevHamiltonian>();
	qSystem.Fill();
	//MatrixElementFiller::Fill(qSystem);

	qSystem.hamiltonian.matrixElements.print();


	qSystem.SelectObservable<ParticleNumberOperator>(L);
	MatrixElementFiller::Fill(qSystem);
	ParticleNumberOperator<Mat,double>::Preprocessing(qSystem.hamiltonian.matrixElements);


	qSystem.hamiltonian.matrixElements.print();

	qSystem.SelectObservable<ParityOperator>(L);
	MatrixElementFiller::Fill(qSystem);
	ParityOperator<Mat,double>::Preprocessing(qSystem.hamiltonian.matrixElements);

	qSystem.hamiltonian.matrixElements.print();

	Info::Time();

	BaseState someState;
	someState.set_size(6);someState.fill(0);
	someState(0) = 1;
	someState(1) = 1;
	someState(2) = 1;

	std::cout << someState.HopSign(3,0) << std::endl;

	BaseState someState2;someState2.set_size(6); someState2.fill(0);
	someState2(4) = 1;
	someState2.print("before");
	someState2.MakeHop(4,0);
	someState2.print("after");

	return 0;
}