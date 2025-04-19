#include <iostream>

int	addup(int sum) {
	if (sum == 10) return 1;
	sum++;
	int new_sum = addup(sum);
	std::cout << "this code is executed" << std::endl;
	std::cout << "and sum now is: " << sum << std::endl;
	std::cout << "new sum is: " << new_sum << std::endl;

	return sum;
}


int	main(void) {
	int sum = 1;
	
	sum = addup(sum);

	std::cout << "sum is: " << sum << std::endl;
	return 0;
}
