#include "Modules/SOLIDstate.hpp"

#include <armadillo>
using namespace arma;
using namespace solid;

#include <functional>

template <typename T>
using dataContainer = arma::SpMat<T>;

//typedef arma::cx_double dataType;
typedef double dataType;

int main(int argc, char *argv[])
{

	ArgvParser::Parse(argc, argv);

	Info::Start();

	// number of sites
	int L = 4;

	QuantumSystem<dataContainer, dataType> qSystem;

	//qSystem.SelectEnsemble<Canonical>(L,L/2);
	qSystem.SelectEnsemble<ParityGrandCanonical>(L, 0);
	//qSystem.SelectEnsemble<GrandCanonical>(L);

	Info::ShowSectors(qSystem.hilbertSpace.ensemble);
	//Info::ShowSectors(qSystem); // other implementation

	arma::SpMat<dataType> mu(L, L);
	mu = eye<arma::SpMat<dataType>>(L, L);
	mu(1, 2) = 1;

	arma::SpMat<dataType> V(L, L);
	//V.set_size(L, L);
	//for(int i=0;i<L;i++) V(i,(i+1)%L) = 1.0;
	V(1, 1) = 2;

	arma::SpMat<dataType> t(L, L);
	for (int i = 0; i < L - 1; i++)
		t(i, (i + 1) % L) = 1.0;
	for (int i = 0; i < L - 1; i++)
		t((i + 1) % L, i) = 1.0;
	//mat(t).print();

	arma::SpMat<dataType> delta(L, L);
	for (int i = 0; i < L - 1; i++)
		delta(i, i + 1) = 1.0; // a+ a+
	for (int i = 0; i < L - 1; i++)
		delta(i + 1, i) = 1.0; // a  a
	//mat(delta).print();

	Parameters<dataType> param;

	param["mu"] = mu;		// TODO non-diag ignored!
	param["V"] = V;			// TODO diag ignored!
	param["t"] = t;			// TODO diag ignored!
	param["delta"] = delta; // TODO diag ignored! //TODO bonds cheking if this is the last sector

	qSystem.SelectParameters(param);
	Info::ShowParameters(qSystem);

	ParametersChecker::Check(param);
	(param["mu"]).print();
	(param["V"]).print();

	// TODO typedef uniform parameters
	dataType t_integral = 1.0;
	uniformParameters<dataType> paramChain1 = {{"t", t_integral}};
	uniformParameters<dataType> paramChain2 = {{"V", 2}};
	Geometry<dataType> geometry = Chain<dataType>(L, {{"t", t_integral}, {"V", 0.0}, {"mu", 0.0}, {"delta", 1}}); //+ Ring<double>(L, paramChain2);

	geometry.parameters["t"].print("T");
	geometry.parameters["delta"].print("D");
	geometry.parameters["V"].print("V");
	geometry.parameters["mu"].print("M");

	//return 0;

	qSystem.SelectParameters(geometry);

	qSystem.SelectHamiltonian<KitaevHamiltonian>();
	qSystem.Fill();

	qSystem.hamiltonian.matrixElements.print();

	QuantumState<dataType> qState = Eigensolver::FindGroundState(qSystem);

	dataType E = qState.energy;
	dataType H = Laboratory::Measure(qSystem, qState);
	std::cout << "Energy=" << E << "\t <H>=" << H << std::endl;

	qState.print();

	//return 0;

	QuantumState<cx_double> cx_qState = qState;
	//cx_qState.vector.print();

	std::cout << Laboratory::Measure(qSystem, qState) << std::endl;
	std::cout << Laboratory::Measure(qSystem, cx_qState) << std::endl;

	//Schedule<sp_mat> t_schedule = [L](auto &A, auto t) {for(int i=0;i<L-1;i++) A(i,i+1) += 0.1 * t; A = symmatu(A); };
	//Schedule<sp_mat> V_schedule = [L](auto &A, auto t) {for(int i=0;i<L-1;i++) A(i,i+1) += -0.1 * t; A = symmatu(A); };

	Schedule<arma::SpMat<dataType>> t_schedule = [L](auto &A, auto t) {};
	Schedule<arma::SpMat<dataType>> V_schedule = [L](auto &A, auto t) {};

	DynamicsSchedule<arma::SpMat<dataType>> dynSchedule;
	dynSchedule.time_step = 0.01;
	dynSchedule.time_final = 1;

	ScheduleMap<arma::SpMat<dataType>> dict;
	dict["t"] = t_schedule;
	dict["V"] = V_schedule;

	dynSchedule.dict = dict;

	MeasurementSchedule<dataContainer, dataType, cx_double> meSchedule;
	meSchedule.timeToMeasure = [](auto time) { return true; };
	meSchedule.Measure = [L](QuantumSystem<dataContainer, dataType> &qSys, QuantumState<cx_double> &qSta) {
		QuantumState<dataType> ground = Eigensolver::FindGroundState(qSys);
		//auto E = Laboratory::Measure(qSys, ground);
		auto E = Laboratory::Measure(qSys, qSta);
		qSys.SelectObservable<ParticleNumberOperator>(L);
		auto N = Laboratory::Measure(qSys, qSta);
		std::cout << "<E> = " << real(E) << "   |   ";
		std::cout << "<N> = " << N << std::endl;
	};

	// Quantum dynamics object
	QuantumDynamics<dataContainer, dataType, cx_double> qDynamics;
	qDynamics.Create(qSystem, cx_qState, dynSchedule, meSchedule,"adia");
	qDynamics.Run();

	cx_vec test;
	test = cx_qState.vector;
	cx_qState.vector += test;


	//IQuantumDynamicSolver<dataContainer,dataType,arma::cx_double>* solver;
	//solver = new RK4<dataContainer,dataType,arma::cx_double>();
	//solver->Propagate(0, 0.1, qDynamics);
	//std::cout << solver->getLabel() << std::endl;
	

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