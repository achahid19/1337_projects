#include <stdio.h>
#include <stdarg.h>

struct s_test
{
	int a;
	int (*f)(va_list);
};

int ft_add(va_list av)
{
	int a;

	a = va_arg(av, int);
	printf("entered ft_add\n");
	return (a);
}

int ft_add1(va_list av)
{
	int b;

	printf("entered ft_add1\n");
	b = va_arg(av, int);
	return (b);
}

int	(*ft_func(int c, int num))(va_list)
{
	struct s_test list[2] = {
		{1, ft_add},
		{2, ft_add1}
	};
	
	for (int count = 0; count < num; count++)
	{
		if (list[count].a == c)
			return (list[count].f);
	}
	return (NULL);
}

int	ft_test(int num, ...)
{
	va_list av;
	int (*f)(va_list);
	int len;

	va_start(av, num);
	for (int count = 1; count < num + 1; count++)
	{
		f = ft_func(count, num);
		len = (*f)(av);
		printf("len is: %d\n", len);
	}

}

int main(void)
{
	ft_test(2, 1, 2);
}
