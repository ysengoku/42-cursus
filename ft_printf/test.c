#include "ft_printf.h"

int	main()
{
//	printf(" (%d)\n", ft_printf("hello"));

// ------ TEST1 ------
	printf("test1 - printf: ");
	printf(" (%i)\n", printf("%c", 'a'));
//	printf("test1 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%c", 'a'));

// ------ TEST2 ------
	printf("test2 - printf: ");
	printf(" (%i)\n", printf("%s", "hello"));
//	printf("test2 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%s\n", "hello"));

// ------ TEST3 ------
	const char	*test3 = "hello";
	printf("test3 - printf: ");
	printf(" (%i)\n", printf("%p", test3));
//	printf("test3 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%p", test3));

// ------ TEST4 ------
	printf("test4 - printf: ");
	printf(" (%i)\n", printf("%d", -42));
//	printf("test4 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%d", -42));

// ------ TEST5 ------
	printf("test5 - printf: ");
	printf(" (%i)\n", printf("%i", 0));
//	printf("test5 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%i", 0));

// ------ TEST6 ------
	printf("test6 - printf: ");
	printf(" (%i)\n", printf("%d", 2147483647));
//	printf("test6 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%d", 2147483647);

// ------ TEST7 ------
	printf("test7 - printf: ");
	printf(" (%i)\n", printf("%u", 42));
//	printf("test7 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%u", 42));

// ------ TEST8 ------
	printf("test8 - printf: ");
	printf(" (%i)\n", printf("%x", 1011));
//	printf("test8 - ft_printf: ");
//	printf(" (%i)\n",ft_printf("%x", 1011);

// ------ TEST9 ------
	printf("test9 - printf: ");
	printf(" (%i)\n", printf("%X", 1011));
//	printf("test9 - ft_printf: ");
//	printf(" (%i)\n",ft_printf("%X", 1011));

// ------ TEST10 ------
	printf("test10 - printf: ");
	printf(" (%i)\n", printf("%%"));
//	printf("test10 - ft_printf: ");
//	printf(" (%i)\n",ft_printf("%%"));

// ------ TEST11 ------
	printf("test11 - printf: ");
	printf(" (%i)\n", printf("I'm %s, %d years old.", "Coco", 18));
//	printf("test11 - ft_printf: ");
//	printf(" (%i)\n",ft_printf("I'm %s, %d years old", "Coco", 18));

// ------ TEST12 ------
	printf("test12 - printf: ");
	printf(" (%i)\n", printf(""));
//	printf("test12 - ft_printf: ");
//	printf(" (%i)\n",ft_printf(""));

// ------ TEST13 ------
//	printf("test13 - printf: ");
//	printf(" (%i)\n", printf("%s", 123));
//	printf("test13 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%s", 123));

// ------ TEST14 ------
	printf("test14 - printf: ");
	printf(" (%i)\n", printf("%u", -123));
//	printf("test14 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%u", -123));

// ------ TEST15 ------
//	printf("test15 - printf: ");
//	printf(" (%i)\n", printf("%i", 'A'));
//	printf("test15 - ft_printf: ");
//	printf(" (%i)\n", ft_printf("%i", 'A'));

	return 0;
}