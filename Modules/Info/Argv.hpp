#ifndef ARGV_HPP
#define ARGV_HPP

#include <unistd.h>
#include <iostream>
namespace solid
{
    
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
                std::cout << "option -" << char(option) << " selected\n";
                std::cout << "Version v0.1\n";
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