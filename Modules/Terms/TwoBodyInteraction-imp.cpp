#include "TwoBodyInteraction.cpp"

namespace solid
{
// Fermions
template void TwoBodyInteractionTermFermions::FillElements<  Mat,    double>(QuantumSystem<  Mat,    double> &qSystem);
//template void TwoBodyInteractionTermFermions::FillElements<  Mat, cx_double>(QuantumSystem<  Mat, cx_double> &qSystem);
template void TwoBodyInteractionTermFermions::FillElements<SpMat,    double>(QuantumSystem<SpMat,    double> &qSystem);
//template void TwoBodyInteractionTermFermions::FillElements<SpMat, cx_double>(QuantumSystem<SpMat, cx_double> &qSystem);

// Spins
template void TwoBodyInteractionTermSpins::FillElements<  Mat,    double>(QuantumSystem<  Mat,    double> &qSystem);
//template void TwoBodyInteractionTermSpins::FillElements<  Mat, cx_double>(QuantumSystem<  Mat, cx_double> &qSystem);
template void TwoBodyInteractionTermSpins::FillElements<SpMat,    double>(QuantumSystem<SpMat,    double> &qSystem);
//template void TwoBodyInteractionTermSpins::FillElements<SpMat, cx_double>(QuantumSystem<SpMat, cx_double> &qSystem);

}