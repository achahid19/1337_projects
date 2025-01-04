#include "utils.hpp"

void	print(const std::string& msg, const char *color) {
  std::cout << color << msg;
  std::cout << RESET_COLOR << std::endl;
}
