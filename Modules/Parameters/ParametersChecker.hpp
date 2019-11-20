#ifndef PARAMETERSCHECKER_HPP
#define PARAMETERSCHECKER_HPP

#include <armadillo>

#include "Parameters.hpp"
#include "../Terms/TermsTypeConverter.hpp"
#include "../Terms/TermsTypeEnum.hpp"

namespace solid
{

class ParametersChecker
{
public:
    template <typename T>
    static int Check(Parameters<T> &parameters)
    {
        for (auto &[key, value] : parameters)
        {
            switch (TermsTypeConverter::dict[key])
            {
            case TermsTypeEnum::LocalDiagonal:
                CheckLocalDiagonal(value);
                break; 
            case TermsTypeEnum::LocalNondiagonal:
                CheckLocalNondiagonal(value);
                break; 
            case TermsTypeEnum::NonlocalDiagonal:
                CheckNonlocalDiagonal(value);
                break;
            case TermsTypeEnum::NonlocalNondiagonal:
                CheckNonlocalNondiagonal(value);
                break; 

            }
        }
    }

private:
    template <typename T>
    static void CheckLocalDiagonal(arma::SpMat<T> &parameter)
    {
        if (!parameter.is_diagmat())
        {
            // TODO move to info
            std::cout << "[!] Warning LocalDiagonalTerm should have only diagonal elements!" << std::endl;
            std::cout << "[!] all non-diagonal entries are ignored!" << std::endl;
            parameter = parameter.diag();
        }
    }

    template <typename T>
    static void CheckLocalNondiagonal(arma::SpMat<T> &parameter)
    {
        if (!parameter.diag().is_empty())
        {
            // TODO
        }
    }
    template <typename T>
    static void CheckNonlocalDiagonal(arma::SpMat<T> &parameter)
    {
        //TODO
    }

    template <typename T>
    static void CheckNonlocalNondiagonal(arma::SpMat<T> &parameter)
    {
        //TODO
    }
};

} // namespace solid

#endif