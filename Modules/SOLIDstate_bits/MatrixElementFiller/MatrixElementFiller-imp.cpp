/**
 * @file MatrixElementFiller-imp.cpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Matrix Element Filler templates initialization
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "MatrixElementFiller.cpp"

namespace solid
{

// ***************************
// .Fill()
// ***************************
template void MatrixElementFiller::Fill(QuantumSystem<arma::Mat, double> &);
template void MatrixElementFiller::Fill(QuantumSystem<arma::Mat, arma::cx_double> &);
template void MatrixElementFiller::Fill(QuantumSystem<arma::SpMat, double> &);
template void MatrixElementFiller::Fill(QuantumSystem<arma::SpMat, arma::cx_double> &);

} // namespace solid