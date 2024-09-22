#include <iostream>
#include <cctype>

int	main(int ac, char **av) {
	int	index = 1;

	(void)ac;
	if (av[index] == NULL)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int j;
		while (av[index])
		{
			j = 0;
			while (av[index][j])
			{
				av[index][j] = toupper(av[index][j]);
				j++;
			}
			std::cout << av[index];
			index++;
			if (av[index] == NULL)
				std::cout << std::endl;
		}
	}
	return 0;
}
