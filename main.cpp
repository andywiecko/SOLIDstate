#include "Modules/SOLIDstate.hpp"

#include <armadillo>
using namespace arma;
using namespace solid;

#include <functional>

//template <typename T,template <typename> class T1, typename T2>
//auto operator*(QuantumState<T> qState,QuantumSystem<T1,T2> qSystem)
//{
//	return arma::Col<T>(qState.vector * qSystem.hamiltonian.matrixElements);
//}

//template <typename T,template <typename> class T1, typename T2>
//auto operator*(QuantumSystem<T1,T2> qSystem,QuantumState<T> qState)
//{
//	return arma::Col<T>(qSystem.hamiltonian.matrixElements * qState.vector);
//}

int main(int argc, char *argv[])
{

	ArgvParser::Parse(argc, argv);

	Info::Start();

	// number of sites
	int L = 4;

	QuantumSystem<SpMat, double> qSystem;

	//qSystem.SelectEnsemble<Canonical>(L,L/2);
	qSystem.SelectEnsemble<ParityGrandCanonical>(L, 0);
	//qSystem.SelectEnsemble<GrandCanonical>(L);

	Info::ShowSectors(qSystem.hilbertSpace.ensemble);
	//Info::ShowSectors(qSystem); // other implementation

	sp_mat mu(L, L);
	//mu.set_size(L);
	//mu = eye<sp_mat>(L,L);

	sp_mat V(L, L);
	//V.set_size(L, L);
	//for(int i=0;i<L;i++) V(i,(i+1)%L) = 1.0;

	sp_mat t(L, L);
	for (int i = 0; i < L - 1; i++)
		t(i, (i + 1) % L) = 1.0;
	for (int i = 0; i < L - 1; i++)
		t((i + 1) % L, i) = 1.0;
	//mat(t).print();

	sp_mat delta(L, L);
	for (int i = 0; i < L - 1; i++)
		delta(i, i + 1) = 1.0; // a+ a+
	for (int i = 0; i < L - 1; i++)
		delta(i + 1, i) = 1.0; // a  a
	//mat(delta).print();

	Parameters<double> param;

	param["M"] = mu;		// TODO non-diag ignored!
	param["V"] = V;			// TODO diag ignored!
	param["t"] = t;			// TODO diag ignored!
	param["delta"] = delta; // TODO diag ignored! //TODO bonds cheking if this is the last sector

	qSystem.parameters = param;
	Info::ShowParameters(qSystem);

	// TODO typedef uniform parameters
	std::map<std::string, double> paramChain1 = { {"t",4} };
	std::map<std::string, double> paramChain2 = { {"V",2} };
	Geometry<double> geometry = Chain<double>(L,{{"t",4}}) + Ring<double>(L,paramChain2);
 	
	mat(geometry.parameters["V"]).print("GEO V");
	mat(geometry.parameters["t"]).print("GEO t");

	qSystem.SelectHamiltonian<KitaevHamiltonian>();
	qSystem.Fill();

	qSystem.hamiltonian.matrixElements.print();

	QuantumState<double> qState = Eigensolver::FindGroundState(qSystem);

	double E = qState.energy;
	double H = Laboratory::Measure(qSystem, qState);
	std::cout << "Energy=" << E << "\t <H>=" << H << std::endl;

	//qState.vector.print();

	QuantumState<cx_double> cx_qState = qState;
	//cx_qState.vector.print();

	std::cout << Laboratory::Measure(qSystem, qState) << std::endl;
	std::cout << Laboratory::Measure(qSystem, cx_qState) << std::endl;

	//Schedule<sp_mat> t_schedule = [L](auto &A, auto t) {for(int i=0;i<L-1;i++) A(i,i+1) += 0.1 * t; A = symmatu(A); };
	//Schedule<sp_mat> V_schedule = [L](auto &A, auto t) {for(int i=0;i<L-1;i++) A(i,i+1) += -0.1 * t; A = symmatu(A); };

	Schedule<sp_mat> t_schedule = [L](auto &A, auto t) { };
	Schedule<sp_mat> V_schedule = [L](auto &A, auto t) { };

	DynamicsSchedule<sp_mat> dynSchedule;
	dynSchedule.time_step = 0.01;
	dynSchedule.time_final = 1;

	ScheduleMap<sp_mat> dict;
	dict["t"] = t_schedule;
	dict["V"] = V_schedule;

	dynSchedule.dict = dict;

	MeasurementSchedule<SpMat, double, cx_double> meSchedule;
	meSchedule.timeToMeasure = [](auto time) { return true; };
	meSchedule.Measure = [L](QuantumSystem<SpMat, double> &qSys, QuantumState<cx_double> &qSta) {
		QuantumState<double> ground = Eigensolver::FindGroundState(qSys);
		//auto E = Laboratory::Measure(qSys, ground);
		auto E = Laboratory::Measure(qSys, qSta);
		qSys.SelectObservable<ParticleNumberOperator>(L);
		auto N = Laboratory::Measure(qSys, qSta);
		std::cout << "<E> = " << real(E) << "   |   ";
		std::cout << "<N> = " << N << std::endl;
	};

	// Quantum dynamics object
	QuantumDynamics<SpMat, double, cx_double> qDynamics;
	qDynamics.Create(qSystem, cx_qState, dynSchedule, meSchedule);
	//qDynamics.Run();

	cx_vec test;
	test = cx_qState.vector;
	cx_qState.vector += test;


	//return 0;

	/*
	qSystem.SelectObservable<ParticleNumberOperator>(L);
	qSystem.Fill();
	//ParticleNumberOperator<Mat,double>::Preprocessing(qSystem.hamiltonian.matrixElements);
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