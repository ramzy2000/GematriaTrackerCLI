#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <string_view>
#include <algorithm>
#include <cctype>

/// <summary>
/// Convert a string to a upper case string
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
std::string toUppercase(std::string_view str);

/// <summary>
/// function that takes in a string and returns the
/// get the numbers from the string and add them together.
/// </summary>
/// <returns>Total added numbers</returns>
int getGematria(std::string str);

//reverse a a string
std::string reverseString(const std::string str);

#endif // UTILS_H