#include "utils.hpp"

void	print(std::string const &msg, char const *color) {
	std::cout << color;
	std::cout << msg;
	std::cout << RESET_COLOR << std::endl;
}
