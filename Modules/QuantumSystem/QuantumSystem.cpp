#include "QuantumSystem.hpp"
#include<armadillo>
#include "../HilbertSpace/HilbertSpace.hpp"
#include "../MatrixElementFiller/MatrixElementFiller.hpp"

namespace solid
{
    template <template <typename> class T1, typename T2>
    void QuantumSystem<T1,T2>::Fill()
    {
        MatrixElementFiller::Fill(*this);
    }

    template <template <typename> class T1, typename T2>
    template <class Ens, typename... Targs>
    void QuantumSystem<T1,T2>::SelectEnsemble(Targs... Fargs)
    {
        HilbertSpace space;
        space.ensemble = Factory::CreateEnsemble<Ens>(Fargs...);
        hilbertSpace = space;
    }


    template void QuantumSystem<arma::Mat,double>::Fill();
    //template void QuantumSystem<arma::Mat,cx_double>::Fill();
    //template void QuantumSystem<arma::SpMat,double>::Fill();
    //template void QuantumSystem<arma::SpMat,cx_double>::Fill();


    // initialisation of the ensembles
    template void QuantumSystem<arma::Mat,double>::SelectEnsemble<Canonical>(int,int);
    template void QuantumSystem<arma::Mat,double>::SelectEnsemble<GrandCanonical>(int);
    template void QuantumSystem<arma::Mat,double>::SelectEnsemble<ParityGrandCanonical>(int,int);

}