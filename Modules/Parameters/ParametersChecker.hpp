#ifndef PARAMETERSCHECKER_HPP
#define PARAMETERSCHECKER_HPP

#include "Parameters.hpp"
#include "../Terms/TermsTypeConverter.hpp"

namespace solid
{

class ParametersChecker
{
public:
    template <typename T>
    static int Check(Parameters<T> parameters)
    {
        for (auto const &[key, value] : parameters)
        {
            std::cout << key << std::endl; //TermsTypeConverter::dict[key] << std::endl;
        }
    }
};

} // namespace solid

#endif