// cc -Wall -Wextra -Werror  -I/includes test.c includes/ft_printf.h includes/libft.h srcs/*.c srcs/Libft/*.c

#include "includes/ft_printf.h"
#include "includes/libft.h"
#include <stdio.h>

int	main()
{

	printf("------------- TEST / no type specifier -------------\n");
	printf(" (%i)\n", ft_printf("hello"));
	printf("printf: ");
	printf(" (%i)\n\n", printf("hello"));
/*
	printf("\n------------- TEST / c -------------\n");
	printf(" (%i)\n", ft_printf("%c", 'a'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%c", 'a'));

	printf("\n------------- TEST / s -------------\n");
	printf(" (%i)\n", ft_printf("%s", "hello"));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%s", "hello"));

	int	size = 10000;
	char *testLongText = malloc(size * sizeof(char));
	ft_memset(testLongText, 'a', size * sizeof(char));
	testLongText[size * sizeof(char) - 1] = '\0';
	printf(" (%i)\n", ft_printf("%s", testLongText));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%s", testLongText));
	free(testLongText);
	
	printf(" (%i)\n", ft_printf(" NULL %s NULL ", (char *)NULL));
	printf("printf: ");
	printf(" (%i)\n\n", printf(" NULL %s NULL ", (char *)NULL));

	printf("\n------------- TEST / p -------------\n");
	const char	*teststr = "hello";
	printf(" (%i)\n", ft_printf("%p", teststr));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%p", teststr));

	int	*testd = (int *)ft_calloc(2, sizeof(int));
	printf(" (%i)\n", ft_printf("%p", testd));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%p", testd));
	free(testd);

	printf(" (%i)\n", ft_printf(" %p %p ", (void *)0, (void *)0));
	printf("printf: ");
	printf(" (%i)\n\n", printf(" %p %p ", (void *)0, (void *)0));

	printf("\n------------- TEST / d & i------------\n");
	printf(" (%i)\n", ft_printf("%d, %d", -42, -5));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%d, %d", -42, -5));	

	printf(" (%i)\n", ft_printf("%i, %i, %i", 0, 7, 101));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%i, %i, %i", 0, 7, 101));

	printf(" (%i)\n", ft_printf("%d, %d", INT_MAX, INT_MIN));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%d, %d", INT_MAX, INT_MIN));

	printf(" (%i)\n", ft_printf("%d", 'a'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%d", 'a'));

//	printf(" (%i)\n", ft_printf("%d", "abc")); //--> print something & return its length 
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%d", "abc")); //--> format specifies type != argument type

//	printf(" (%i)\n", ft_printf("%d", -2147483648));
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%d", -2147483648)); //--> Original printf can't handle INT_MIN

	printf("\n------------- TEST / u -------------\n");
	printf(" (%i)\n", ft_printf("%u", 42));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%u", 42));

	printf(" (%i)\n", ft_printf("%u, %u", -123, 0));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%u, %u", -123, 0));

	printf(" (%i)\n", ft_printf("%u, %u", INT_MIN, INT_MAX));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%u, %u", INT_MIN, INT_MAX));

	printf("\n------------- TEST / x -------------\n");
	printf(" (%i)\n",ft_printf("%x", 1011));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%x", 1011));

	printf(" (%i)\n",ft_printf("%x", 9));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%x", 9));

	printf(" (%i)\n",ft_printf("%x", 0));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%x", 0));

	printf("\n------------- TEST / X -------------\n");
	printf(" (%i)\n",ft_printf("%X, %X", 15, 16));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%X, %X", 15, 16));

	printf(" (%i)\n",ft_printf("%X", -27));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%X", -27));

	printf(" (%i)\n",ft_printf("%X, %X", INT_MAX, INT_MIN));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%X, %X", INT_MAX, INT_MIN));

	printf("\n------------ TEST / %% -------------\n");
	printf(" (%i)\n",ft_printf("%%"));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%%"));

	printf("\n------------- TEST / s, d -------------\n");
	printf(" (%i)\n",ft_printf("I'm %s, %d years old.", "Coco", 18));
	printf("printf: ");
	printf(" (%i)\n\n", printf("I'm %s, %d years old.", "Coco", 18));

	printf("\n------------- TEST / empty -------------\n");
	printf(" (%i)\n",ft_printf(""));
	printf("printf: ");
	printf(" (%i)\n\n", printf(""));

	printf("\n------------- TEST / invalid specifier -------------\n");
	printf(" (%i)\n\n",ft_printf("%a", "Coucou"));
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%a", "Coucou"));

	printf(" (%i)\n\n",ft_printf("%s, %a", "Coucou"));
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%s, %a", "Coucou"));
*/

//	printf("\n-------- TEST / nil arg --------\n");
// nil arg == null pointer ?
	printf("  -s (%i)\n\n", ft_printf("%s")); 
	printf("  -c (%i)\n\n", ft_printf("%c")); // ---> write something & return 1
//	printf("printf: ");
//	printf(" (%i)\n", printf("%c")); // ---> "more '%' conversions than data arguments"
	printf("  -i (%i)\n\n", ft_printf("%i"));
	printf("  -u (%i)\n\n", ft_printf("%u"));
	printf("  -p (%i)\n\n", ft_printf("%p"));
	printf("  -x (%i)\n\n", ft_printf("%x"));

	printf("  -c (%i)\n\n", ft_printf("%c", NULL));
	printf("  -s (%i)\n\n", ft_printf("%s", NULL)); 
	printf("  -i (%i)\n\n", ft_printf("%i", NULL));
	printf("  -u (%i)\n\n", ft_printf("%u", NULL));
	printf("  -p (%i)\n\n", ft_printf("%p", NULL));
	printf("  -x (%i)\n\n", ft_printf("%x", NULL));

	printf("%lu\n", sizeof(void *));
/*
	printf("\n-------- TEST / arg in unexpected type --------\n");
	printf("specifier == i <--> input == char\n");
	printf(" (%i)\n", ft_printf("%i", 'A'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%i", 'A'));

	printf("specifier == x <--> input == char\n");
	printf(" (%i)\n", ft_printf("%x", 'A'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%x", 'A'));

	printf("specifier == u <--> input == char\n");
	printf(" (%i)\n", ft_printf("%u", 'A'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%u", 'A'));

	printf("specifier == c <--> input == char*\n");
	printf(" (%i)\n\n", ft_printf("%c", "abc")); //---> write something & return 1
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%c", "abc")); // ---> format specifies type 'int' but the argument has type 'char *

//	printf(" specifier == s <--> input == int\n");
//	printf(" (%i)\n\n", ft_printf("%s", 123)); // ---> 	segmentation fault
//	printf("printf: ");
//	printf(" (%i)\n", printf("%s", 123)); // ---> format specifies type 'char *' but the argument has type 'int'

//	printf("specifier == s <--> input == char\n");
//	printf(" (%i)\n", ft_printf("%s", 'A')); // ---> segmentation fault
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%s", 'A')); // ---> format specifies type 'int' but the argument has type 'char *
*/
	return 0;
}