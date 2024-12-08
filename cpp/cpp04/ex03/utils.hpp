#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET_COLOR "\033[0m"

void	print(std::string const &msg, char const *color);
