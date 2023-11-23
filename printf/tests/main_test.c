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

    int number = 42;
    int *ptr = &number;

    printf("Address of the variable 'number': %p\n", (void*)ptr);
    printf("hexa of the number 42 is: %x\n", *ptr);

    return 0;
}
