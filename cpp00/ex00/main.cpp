#include <iostream>
#include <cctype>

using namespace std;

/**
 * Sales - 95k
 * State Tax - 4%
 * country Tax - 2%
 */
int	main(int ac, char **av) {
	// for monetory values, always use/* 
	/*int		sales = 95000;
	double	stateTax = sales * 0.04;
	double	countryTax = sales * 0.02;
	double	totalTax = stateTax + countryTax;

	cout << "Number of sales: " << sales << "$" << endl;
	cout << "State Tax to pay: " << stateTax << "$" << endl;
	cout << "Country Tax to pay: " << countryTax << "$" << endl;
	cout << "Total Tax: " << totalTax <<"$" << endl; */

	/* double	fahrenheit;
	double	celsius;

	cout << "Enter tempurate in celsius: " << endl;
	cin >> celsius;
	fahrenheit = celsius * (9/5) + 32;
	cout << "Tempurature in F is: " << fahrenheit << endl; */
	int	index = 1;

	if (av[index] == NULL)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
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
			cout << av[index];
			index++;
			if (av[index] == NULL)
				cout << endl;
		}
	}
	return 0;
}
