/**
 * @file Hop-imp.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Hop term template initialization
 * @version 0.100.0
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Hop.cpp"

namespace solid
{

// ***************************
// Fermions
// ***************************
template void HopTermFermions::FillElements<Mat, double>(QuantumSystem<Mat, double> &qSystem);
template void HopTermFermions::FillElements<Mat, cx_double>(QuantumSystem<Mat, cx_double> &qSystem);
template void HopTermFermions::FillElements<SpMat, double>(QuantumSystem<SpMat, double> &qSystem);
template void HopTermFermions::FillElements<SpMat, cx_double>(QuantumSystem<SpMat, cx_double> &qSystem);

} // namespace solid