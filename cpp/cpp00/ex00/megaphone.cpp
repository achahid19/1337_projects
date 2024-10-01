#include <iostream>
#include <cctype>

int	main(int ac, char **av) {
	std::string	str;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
	{
		for (size_t index = 1; av[index]; index++)
		{
			str = av[index];
			for (size_t j = 0; str[j]; j++)
				str[j] = toupper(str[j]);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return 0;
}
