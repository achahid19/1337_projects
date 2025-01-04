#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

#define NO_GRADE -1

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET_COLOR "\033[0m"

void	print(const std::string& msg, const char *color);

#endif // UTILS_HPP
