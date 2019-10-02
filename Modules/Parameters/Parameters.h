#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <map>

template <typename T>
class Parameters
{
    public:
        std::map<char, T> parameters;

};

#endif