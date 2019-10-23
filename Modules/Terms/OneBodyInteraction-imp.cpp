#include "OneBodyInteraction.cpp"

namespace solid
{

// Fermions
template void OneBodyInteractionTermFermions::FillElements<Mat,double>(QuantumSystem<Mat,double> &qSystem);
template void OneBodyInteractionTermFermions::FillElements<Mat,cx_double>(QuantumSystem<Mat,cx_double> &qSystem);
template void OneBodyInteractionTermFermions::FillElements<SpMat,double>(QuantumSystem<SpMat,double> &qSystem);
template void OneBodyInteractionTermFermions::FillElements<SpMat,cx_double>(QuantumSystem<SpMat,cx_double> &qSystem);

// Spins
template void OneBodyInteractionTermSpins::FillElements<  Mat,   double>(QuantumSystem<  Mat,   double> &qSystem);
//template void OneBodyInteractionTermSpins::FillElements<  Mat,cx_double>(QuantumSystem<  Mat,cx_double> &qSystem);
template void OneBodyInteractionTermSpins::FillElements<SpMat,   double>(QuantumSystem<SpMat,   double> &qSystem);
//template void OneBodyInteractionTermSpins::FillElements<SpMat,cx_double>(QuantumSystem<SpMat,cx_double> &qSystem);

}