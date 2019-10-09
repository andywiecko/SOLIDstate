#include "Modules/SOLIDstate.hpp"

#include <armadillo>
using namespace arma;
using namespace solid;

int main(int argc, char *argv[])
{

	ArgvParser::Parse(argc,argv);	

	Info info;
	int L = 3;

	QuantumSystem<Mat, double> qSystem;

	HilbertSpace space;

	space.ensemble = Factory::GenerateGrandCanonicalEnsemble(L);

	//Ensemble ensemble = Factory::GenerateCanonicalEnsemble(L,2);
	//info.ShowSectors(ensemble);
	//space.ensemble = ensemble;

	qSystem.hilbertSpace = space;

	vec mu;
	mu.set_size(L);
	mu.fill(1);

	sp_mat V;V.set_size(L,L);
	V(0,1) = 1;
	//qSystem.parameters = mu;

	Parameters<double> param;

	param['M'] = mu;
	param['V'] = V;

	qSystem.parameters = param;
	
	qSystem.hamiltonian = Factory::CreateHamiltonian<KitaevHamiltonian<Mat, double>>();
	MatrixElementFiller::Fill(qSystem);
	qSystem.hamiltonian.matrixElements.print();

	ParticleNumberOperator<Mat,double> Nop(L);
	Observable<Mat,double> nop = Nop;
	qSystem.hamiltonian = nop._operator;
	qSystem.parameters = nop.parameters;

	MatrixElementFiller::Fill(qSystem);
	qSystem.hamiltonian.matrixElements.print();
	
	info.Time();
	return 0;
}