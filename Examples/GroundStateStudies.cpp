#include <armadillo>
#include <SOLIDstate.hpp>

using namespace solid;
using namespace arma;

int main(int argc, char *argv[])
{
    ArgvParser::Parse(argc, argv);
    Info::Start();

    int L = 4; // number of sites

    // ********************************
    // Setting the matrix type: SpMat,
    // and data type: double
    // ********************************

    QuantumSystem<arma::SpMat, double> qSystem;

    // ********************************
    // Selecting Ensemble
    // ********************************

    qSystem.SelectEnsemble<ParityGrandCanonical>(L, 0);
    Info::ShowSectors(qSystem.hilbertSpace.ensemble); 

    // ********************************
    // Setting the parameters
    // ********************************

    double delta_par = 1.0;
    double t_integral = 1.0;
    double V_par = 0.0;
    double M_par = 0.0;
    Geometry<double> geometry = Chain<double>(L, {{"t", t_integral},
                                                  {"delta", delta_par},
                                                  {"V", V_par},
                                                  {"mu", M_par}});

    qSystem.SelectParameters(geometry);

    // ********************************
    // Selecting the model
    // ********************************

    qSystem.SelectHamiltonian<KitaevHamiltonian>();
    qSystem.Fill();

    // ********************************
    // Finding the ground state
    // ********************************

    QuantumState<double> qState = Eigensolver::FindGroundState(qSystem);

    double E = qState.energy;
    double H = Laboratory::Measure(qSystem, qState);
    std::cout << "Energy=" << E << "\t <H>=" << H << std::endl;

    Info::vTime("\n");

    return 0;
}