#include <iostream>
#include <cctype>

int	main(int ac, char **av) {
	std::string	str;

	(void)ac;
	if (av[1] == NULL)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
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
