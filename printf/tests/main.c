#include "../ft_printf.h"
#include <stdio.h>

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

	ft_printf("               %%c TESTS\n"); /* tests %c */
	len = printf("function: %c\n", c);
	len1 = ft_printf("function: %c\n", c);

	ft_print(len, len1);

	len = printf("function: %cfaaa\n", 'fd');
	len1 = ft_printf("function: %cfaaa\n", 'fd');

	ft_print(len, len1);

	ft_printf("                %%% TESTS\n"); /* tests %% */
	len = printf("function: %%%%%\n");
	len1 = ft_printf("function: %%%%%\n");

	ft_print(len, len1);

	len = printf("%    "); /* same output as "%" */
	len1 = ft_printf("%    ");

	ft_print(len, len1);

	ft_printf("                %%s TESTS\n"); /* tests %s */
	len = printf("%%%s%%%\n", str);
	len1 = ft_printf("%%%s%%%\n", str);

	ft_print(len, len1);
	
	str = "1337";
	len = printf("  %  %s\n", str);
	len1 = ft_printf("  %  %s\n", str);

	ft_print(len, len1);
}
