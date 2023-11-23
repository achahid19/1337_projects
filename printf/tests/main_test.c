#include "../ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
	int	x = -INT_MAX;

    printf("Size of int: %zu bits\n", 8 * sizeof(int));
    printf("Size of long long int: %zu bits\n", 8 * sizeof(long long int));

    printf("Size of long int: %zu bits\n", 8 * sizeof(long int));
	printf("%X\n", x);
    return 0;
}
