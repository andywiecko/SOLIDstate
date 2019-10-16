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

	qSystem.SelectEnsemble<GrandCanonical>(L);
	//qSystem.SelectEnsemble<ParityGrandCanonical>(L,0);
	//qSystem.SelectEnsemble<Canonical>(L,L/2);

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

	MatrixElementFiller::Fill(qSystem);

	qSystem.hamiltonian.matrixElements.print();

	//ParticleNumberOperator<Mat,double> Nop(L);

	Observable<Mat, double> nop = Factory::CreateObservable<ParticleNumberOperator<Mat, double>>(L);
	qSystem.hamiltonian = nop._operator;
	qSystem.parameters = nop.parameters;

	MatrixElementFiller::Fill(qSystem);

	qSystem.hamiltonian.matrixElements.diag() =
		vec(qSystem.hamiltonian.matrixElements.diag()).transform([](double val) { return std::pow(-1, val); });

	qSystem.hamiltonian.matrixElements.print();

	Info::Time();

	return 0;
}