/**
 * @file Argv.hpp
 * @author Andrzej Więckowski (andrzej.wieckowski@pwr.edu.pl)
 * @brief Argv Parser class header
 * @version 0.100.0
 * @date 2019-10-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef INFO_ARGV_HPP
#define INFO_ARGV_HPP

#include <unistd.h>
#include <iostream>
#include "Info.hpp"

namespace solid
{
    
/**
 * @brief simple [argv](https://en.wikipedia.org/wiki/Command-line_argument_parsing) class
 */
class ArgvParser
{

public:
    static void Parse(int argc, char *argv[])
    {
        int option;
        int returnCode = 0;
        char optstring[] = ":cvf:";
        while ((option = getopt(argc, argv, optstring)) != -1)
            switch (option)
            {
            case 'c':
                std::cout << "option -" << char(option) << " selected\n";
                break;
            case 'v':
                Info::isVerbose = true;
                break;
            case 'f':
                std::cout << "option -" << char(option) << " selected\n";
                break;
            case ':':
                std::cout << "option -" << char(optopt) << " requires argument\n";
                returnCode = 1;
                break;
            case '?':
            default:
                std::cout << "option -" << char(optopt) << " unknown\n";
                returnCode = 1;
                break;
            }
        //if (optind > 0)
        //    std::cout << "other arguments:\n";
        for (; optind < argc; ++optind)
            std::cout << "argv[" << optind << "] = '" << argv[optind] << "'\n";
    }
};

} // namespace solid

#endif