#include "Modules/SOLIDstate.hpp"

#include <armadillo>
using namespace arma;
using namespace solid;

#include "Modules/QuantumDynamics/DynamicsSchedule.hpp"
#include <functional>

int main(int argc, char *argv[])
{

	ArgvParser::Parse(argc, argv);
	
	Info::Start();
	
	// number of sites
	int L = 4;

	QuantumSystem<Mat, double> qSystem;

	//qSystem.SelectEnsemble<Canonical>(L,L/2);
	qSystem.SelectEnsemble<ParityGrandCanonical>(L,1);
	//qSystem.SelectEnsemble<GrandCanonical>(L);

	Info::ShowSectors(qSystem.hilbertSpace.ensemble);
	//Info::ShowSectors(qSystem); // other implementation 
	
	vec mu(L); mu.fill(0);
	//mu.set_size(L);
	//mu.fill(1);

	sp_mat V(L,L);
	//V.set_size(L, L);
	//for(int i=0;i<L;i++) V(i,(i+1)%L) = 1.0;

	sp_mat t(L,L);
	for(int i=0;i<L-1;i++) t(i,(i+1)%L) = 1.0;
	for(int i=0;i<L-1;i++) t((i+1)%L,i) = 1.0;
	//mat(t).print();

	sp_mat delta(L,L);
	for(int i=0;i<L-1;i++) delta(i,i+1) = 1.0; // a+ a+
	for(int i=0;i<L-1;i++) delta(i+1,i) = 1.0; // a  a
	//mat(delta).print();

	Parameters<double> param;

	param["M"] = mu;
	param["V"] = V;
	param["t"] = t;
	param["delta"] = delta;

	qSystem.parameters = param;


	qSystem.SelectHamiltonian<KitaevHamiltonian>();
	qSystem.Fill();

	qSystem.hamiltonian.matrixElements.print();

	//MatrixElementFiller::Fill(qSystem);
	//qSystem.hamiltonian.matrixElements.print();

	///* eigen problem
	//mat eigvec;
	//vec eigval;
	//eig_sym(eigval,eigvec,qSystem.hamiltonian.matrixElements);
	//eigval.t().print();

	qSystem.quantumState = Eigensolver::FindGroundState(qSystem);
	
	double E = qSystem.quantumState.energy;
	double H = Laboratory::Measure(qSystem,qSystem.quantumState);
	std::cout << "Energy=" << E << "\t <H>=" << H << std::endl;


	//std::function<void()> fun;
	//fun = []() -> double{return 3;};
	
	std::function<void(sp_mat&,double)> fun = [L](auto & A, auto t){for(int i=0;i<L-1;i++) A(i,i+1) += 0.1 * t;};
	mat(t).print("t=0.0");
	fun(t,0.50);
	mat(t).print("t=0.5");

	//DynamicsSchedule schedule;
	//schedule.fun = fun;

	return 0;

/*
	qSystem.SelectObservable<ParticleNumberOperator>(L);
	MatrixElementFiller::Fill(qSystem);
	ParticleNumberOperator<Mat,double>::Preprocessing(qSystem.hamiltonian.matrixElements);


	qSystem.hamiltonian.matrixElements.print();

	qSystem.SelectObservable<ParityOperator>(L);
	MatrixElementFiller::Fill(qSystem);
	ParityOperator<Mat,double>::Preprocessing(qSystem.hamiltonian.matrixElements);

	qSystem.hamiltonian.matrixElements.print();

	qSystem.parameters = param;
	qSystem.SelectHamiltonian<KitaevHamiltonian>();
	qSystem.Fill();
	qSystem.hamiltonian.matrixElements.print();
*/

	Info::Time();

	return 0;
}