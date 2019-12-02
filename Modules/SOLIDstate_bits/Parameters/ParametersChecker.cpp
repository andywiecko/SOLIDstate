#include "ParametersChecker.hpp"

namespace solid
{
template <typename T>
void ParametersChecker::Check(Parameters<T> &parameters)
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

template <typename T>
void ParametersChecker::CheckLocalDiagonal(arma::SpMat<T> &parameter)
{
    if (!parameter.is_diagmat())
    {
        // TODO move to Info::
        std::cout << "# [!] Warning LocalDiagonalTerm should have only diagonal elements!" << std::endl;
        std::cout << "# [!] all non-diagonal entries are ignored!" << std::endl;
        parameter = arma::diagmat(parameter);
    }
}

template <typename T>
void ParametersChecker::CheckLocalNondiagonal(arma::SpMat<T> &parameter)
{

    // TODO
    std::cout << "LocalNondiagonal TODO" << std::endl;
}

template <typename T>
void ParametersChecker::CheckNonlocalDiagonal(arma::SpMat<T> &parameter)
{
    // [!] arma is_empty does not work -> TODO report this bug
    arma::SpMat<T> diagonal = parameter.diag();
    if (diagonal.n_nonzero > 0)
    {
        std::cout << "# [!] Warning LocalNondiagonalTerm shouldn't have diagonal elements!" << std::endl;
        std::cout << "# [!] all diagonal entries are ignored!" << std::endl;
        parameter.diag() -= parameter.diag(); // TODO fix this ugly solution!
    }
    // matrix shouldn't be symmetric
    // TODO...
}

template <typename T>
void ParametersChecker::CheckNonlocalNondiagonal(arma::SpMat<T> &parameter)
{
    //TODO empty diagonal
    // matrix should be symmetric!

    std::cout << "LocalNondiagonal TODO" << std::endl;
}

// init templates
template void ParametersChecker::Check(Parameters<double> &);
template void ParametersChecker::Check(Parameters<arma::cx_double> &);
} // namespace solid