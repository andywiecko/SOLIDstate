#include "Timer.hpp"
#include "Info.hpp"

namespace solid
{

void Timer::Time(std::string message /*default =""*/)
{
    std::cout << "# [ " << timer.toc() << " ] " << message;
}

void Timer::vTime(std::string message /*default =""*/)
{
    if (Info::isVerbose)
        Time(message);
}

} // namespace solid