#include "QuantumSystem.hpp"
#include<armadillo>
#include "../MatrixElementFiller/MatrixElementFiller.hpp"

namespace solid
{
    template <template <typename> class T1, typename T2>
    void QuantumSystem<T1,T2>::Fill()
    {
        MatrixElementFiller::Fill(*this);
    }

    template void QuantumSystem<arma::Mat,double>::Fill();

}