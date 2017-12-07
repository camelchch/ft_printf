#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

void  try(va_list args)
{
	ft_putendl(va_arg(args, char *));
}

void	test(char *str, ...)
{
	va_list		args;
	va_start(args,str);
	char *test = va_arg(args, char *);
	ft_putendl(test);
	ft_putnbr(ft_strlen(test));
	try(args);
	//	return (0);
}



int		main(void)
{
	//	int number = 2;

	//	printf("salut%o%s\n", 11, "huhu");
	//printf("%-10d \n", number);
	//    printf("%010d \n", number);
	//	    printf("%-#10x \n", number);  
	//		    printf("%#x \n", number);
	test("huhu","nihao", "huhu");

	return (0);
}

