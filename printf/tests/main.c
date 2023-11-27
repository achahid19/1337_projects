#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

void	ft_print(int len, int len1)
{
	ft_printf("--------------------------\n");
	printf("len printf: %d, len ft_printf: %d\n", len, len1);
	ft_printf("--------------------------\n");
}

int main(void)
{
	char	*str = NULL;
	char	c = '9';
	int		len = 0, len1 = 0;
	int		x = 0;
							/* tests %c */
	ft_printf("               %%c TESTS\n"); 
	len = printf("function1: %c\n", c);
	len1 = ft_printf("function2: %c\n", c);

	ft_print(len, len1);

	len = printf("function1: %cfaaa\n", 'd');
	len1 = ft_printf("function2: %cfaaa\n", 'd');

	ft_print(len, len1);
							/* tests %% */
	ft_printf("                %%% TESTS\n"); 
	len = printf("function1: %%%%\n");
	len1 = ft_printf("function2: %%%%\n");

	ft_print(len, len1);

	len = printf("%");
	len1 = ft_printf("%");

	ft_print(len, len1);
							/* tests %s */
	ft_printf("                %%s TESTS\n"); 
	len = printf("%%%s%%%%\n", str);
	len1 = ft_printf("%%%s%%%%\n", str);

	ft_print(len, len1);
	
	str = "1337FUTURE IS LOAD\00ING";
	len = printf("  %%%s%%%%%%  s\n", str); /* case of flag is space, not handled */
	len1 = ft_printf("  %%%s%%%%%%  s\n", str);

	ft_print(len, len1);

	len =  printf("%%%c%%%s\n", 43, "\0''fds");
    len1 = ft_printf("%%%c%%%s\n", 43, "\0''fds");

	ft_print(len, len1);
							/* tests %d, %i and %u */
	ft_printf("                %%d, %%i and %%u TESTS\n"); 
	len = printf("%%, %d, %i\n", x, x);
	len1 = ft_printf("%%, %d, %i\n", x, x);

	ft_print(len, len1);

	x = 0x7fffffff;
	len = printf("%%, %d, %i\n", x + INT_MAX + 2, x + 1);
	len1 = ft_printf("%%, %d, %i\n", x + 0x7fffffff + 2, x + 1);

	ft_print(len, len1);

	x = -0x7fffffff - 1;
	len = printf("%%, %d, %i\n", x, x);
	len1 = ft_printf("%%, %d, %i\n", x, x);

	ft_print(len, len1);

	len = printf("%u, %u, %u, %u\n", INT_MIN + 10, -1, 0, -10);
	len1 = ft_printf("%u, %u, %u, %u\n", INT_MIN + 10, -1, 0, -10);

	ft_print(len, len1);

							/* tests %X, %x */
	ft_printf("                %%X, %%x TESTS\n"); 
	len = printf("%x, %X, %x\n", -77, - 1, INT_MIN);
	len1 = ft_printf("%x, %X, %x\n", -77, - 1, INT_MIN);

	ft_print(len, len1);

	unsigned long num = SIZE_MAX;
	int *ptr = NULL;
	unsigned long int *ctr = &num;

	len = printf("The address of num is: %p, %p\n",  ptr, ctr);
	len1 = ft_printf("The address of num is: %p, %p\n", ptr, ctr);

	ft_print(len, len1);
}
