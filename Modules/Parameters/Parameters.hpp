#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <map>
#include <armadillo>
namespace solid
{
    
template <typename T>
class Parameters : public std::map<char, arma::SpMat<T>>
{
    //public:
    //std::map<char, T> parameters;
};

} // namespace solid

#endif