#include <armadillo>
#include "../Modules/SOLIDstate.hpp"

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
    
    QuantumSystem<SpMat, double> qSystem;

    // ********************************
    // Selecting Ensemble
    // ********************************

    qSystem.SelectEnsemble<ParityGrandCanonical>(L, 0);
    Info::ShowSectors(qSystem.hilbertSpace.ensemble); // other implementation

    // ********************************
    // Setting the parameters
    // ********************************

    sp_mat mu(L, L); // chemical potential
    mu.set_size(L);
    mu = 0.1 * eye<sp_mat>(L,L);

    sp_mat V(L, L); // many-body interaction
    V.set_size(L, L);
    for(int i=0;i<L;i++) V(i,(i+1)%L) = 0.5;

    sp_mat t(L, L); // hopping term
    for (int i = 0; i < L - 1; i++)
        t(i, (i + 1) % L) = 1.0;
    for (int i = 0; i < L - 1; i++)
        t((i + 1) % L, i) = 1.0;
    
    sp_mat delta(L, L); // paring term
    for (int i = 0; i < L - 1; i++)
        delta(i, i + 1) = 1.0; // a+ a+
    for (int i = 0; i < L - 1; i++)
        delta(i + 1, i) = 1.0; // a  a
    
    Parameters<double> param;
    param["M"] = mu;
    param["V"] = V;
    param["t"] = t;
    param["delta"] = delta;
    qSystem.parameters = param;

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