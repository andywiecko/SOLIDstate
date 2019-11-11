#include <armadillo>

#include "QuantumDynamics.hpp"
namespace solid
{

class RK4
{
public:
    template <template <typename> class T1, typename T2, typename T3>
    static void Propagate(double time, double dtime, QuantumDynamics<T1, T2, T3> &qDynamics)
    {

        arma::cx_double I(0, 1);
        arma::cx_vec k1, k2, k3, k4;

        qDynamics.quantumSystem.Fill();
        k1 = -I * dtime * qDynamics.quantumSystem.hamiltonian.matrixElements * qDynamics.quantumState.vector;
        time += 0.5 * dtime;
        qDynamics.LoadParameters();
        qDynamics.quantumSystem.Fill();
        k2 = -I * dtime * qDynamics.quantumSystem.hamiltonian.matrixElements * (qDynamics.quantumState.vector + 0.5 * k1);
        k3 = -I * dtime * qDynamics.quantumSystem.hamiltonian.matrixElements * (qDynamics.quantumState.vector + 0.5 * k2);
        time += 0.5 * dtime;
        qDynamics.LoadParameters();
        qDynamics.quantumSystem.Fill();
        k4 = -I * dtime * qDynamics.quantumSystem.hamiltonian.matrixElements * (qDynamics.quantumState.vector + k3);
        qDynamics.quantumState.vector += 1. / 6. * (k1 + 2 * k2 + 2 * k3 + k4);;
    }
};

} // namespace solid