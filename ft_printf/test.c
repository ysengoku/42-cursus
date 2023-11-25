// cc -Wall -Wextra -Werror  -I/includes test.c includes/ft_printf.h includes/libft.h srcs/*.c srcs/Libft/*.c

#include "includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("-------- TEST / no type specifier --------\n");
	printf(" (%i)\n", ft_printf("hello"));
	printf("printf: ");
	printf(" (%i)\n", printf("hello"));

	printf("\n-------- TEST / c --------\n");
	printf(" (%i)\n", ft_printf("%c", 'a'));
	printf("printf: ");
	printf(" (%i)\n", printf("%c", 'a'));

	printf("\n-------- TEST / s --------\n");
	printf(" (%i)\n", ft_printf("%s", "hello"));
	printf("printf: ");
	printf(" (%i)\n", printf("%s", "hello"));

	printf("\n-------- TEST / p --------\n");
	const char	*testp = "hello";
	printf(" (%i)\n", ft_printf("%p", testp));
	printf("printf: ");
	printf(" (%i)\n", printf("%p", testp));

	printf("\n-------- TEST / d --------\n");
	printf(" (%i)\n", ft_printf("%d", -42));
	printf("printf: ");
	printf(" (%i)\n", printf("%d", -42));	

	printf("\n-------- TEST / i --------\n");
	printf(" (%i)\n", ft_printf("%i", 0));
	printf("printf: ");
	printf(" (%i)\n", printf("%i", 0));

	printf("\n-------- TEST / d --------\n");
	printf(" (%i)\n", ft_printf("%d", 2147483647));
	printf("printf: ");
	printf(" (%i)\n", printf("%d", 2147483647));

	printf("\n-------- TEST / u --------\n");
	printf(" (%i)\n", ft_printf("%u", 42));
	printf("printf: ");
	printf(" (%i)\n", printf("%u", 42));

	printf("\n-------- TEST / u --------\n");
	printf(" (%i)\n", ft_printf("%u", -123));
	printf("printf: ");
	printf(" (%i)\n", printf("%u", -123));

	printf("\n-------- TEST / x --------\n");
	printf(" (%i)\n",ft_printf("%x", 1011));
	printf("printf: ");
	printf(" (%i)\n", printf("%x", 1011));

	printf("\n-------- TEST / x --------\n");
	printf(" (%i)\n",ft_printf("%x", 9));
	printf("printf: ");
	printf(" (%i)\n", printf("%x", 9));

	printf("\n-------- TEST / X --------\n");
	printf(" (%i)\n",ft_printf("%X", 12));
	printf("printf: ");
	printf(" (%i)\n", printf("%X", 12));

	printf("\n-------- TEST / X --------\n");
	printf(" (%i)\n",ft_printf("%X", -27));
	printf("printf: ");
	printf(" (%i)\n", printf("%X", -27));

	printf("\n-------- TEST / %% --------\n");
	printf(" (%i)\n",ft_printf("%%"));
	printf("printf: ");
	printf(" (%i)\n", printf("%%"));

	printf("\n-------- TEST / s, d --------\n");
	printf(" (%i)\n",ft_printf("I'm %s, %d years old.", "Coco", 18));
	printf("printf: ");
	printf(" (%i)\n", printf("I'm %s, %d years old.", "Coco", 18));

	printf("\n-------- TEST / empty --------\n");
	printf(" (%i)\n",ft_printf(""));
	printf("printf: ");
	printf(" (%i)\n", printf(""));

//	printf("\n-------- TEST / nil arg --------\n");
//	printf("printf: ");
//	printf(" (%i)\n", printf("%c"));
//	printf("ft_printf: ");
//	printf(" (%i)\n\n",ft_printf(""));

//	printf("\n-------- TEST / bad type arg --------\n");
//	printf("printf: ");
//	printf(" (%i)\n", printf("%s", 123));
//	printf("ft_printf: ");
//	printf(" (%i)\n\n", ft_printf("%s", 123));

//	printf("\n-------- TEST / bad type arg --------\n");
//	printf("printf: ");
//	printf(" (%i)\n", printf("%i", 'A'));
//	printf("ft_printf: ");
//	printf(" (%i)\n\n", ft_printf("%i", 'A'));

	return 0;
}