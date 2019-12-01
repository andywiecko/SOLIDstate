#ifndef MISC_STRTOINT_HPP
#define MISC_STRTOINT_HPP

namespace solid
{

/**
 * @brief Covertr string to intiger [copied from StackOverflow](https://stackoverflow.com/a/16388610)
 * 
 * @param str string to convert
 * @param h 
 * @return constexpr unsigned int intiger string representation
 */
constexpr unsigned int StrToInt(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (StrToInt(str, h + 1) * 33) ^ str[h];
}
} // namespace solid

#endif