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

	printf("\n------------- TEST / c -------------\n");
	printf(" (%i)\n", ft_printf("%c", 'a'));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%c", 'a'));

	printf("\n------------- TEST / s -------------\n");
	printf(" (%i)\n", ft_printf("%s", "hello"));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%s", "hello"));

	const char	*testLongText = "Lorem ipsum dolor sit amet, consectetur \
	adipiscing elit. Nullam lorem eros, ornare nec aliquam quis, semper eget dolor. \
	Suspendisse sagittis, ligula nec placerat luctus, eros sem laoreet augue, quis \
	fringilla leo sem eu quam. Vivamus hendrerit purus tortor, sed pulvinar tortor \
	commodo quis. In egestas et lorem nec malesuada. Ut efficitur ex nec eros mattis \
	vulputate. Morbi elit libero, mattis vel pulvinar ac, aliquam ac dolor. \
	Fusce quis justo at sem vehicula volutpat. Nullam sollicitudin blandit turpis. \
	Vivamus quis mollis orci. Fusce non purus posuere, placerat tortor sed, efficitur \
	felis. Aenean vehicula pharetra urna non rhoncus. Duis in arcu libero. Ut vitae \
	ipsum sit amet ligula dapibus tincidunt. Nullam diam mauris, condimentum eget dui \
	eu, congue varius leo. Nam blandit venenatis est, a euismod ex convallis sed. \
	Curabitur id ipsum sollicitudin erat rutrum consequat. Nam cursus dui eu tortor \
	dapibus fermentum. Vestibulum blandit nibh sed leo varius vulputate. \n \
	Nulla elementum quis justo a malesuada. Donec elementum elit nec rutrum \
	vestibulum. Duis bibendum magna vitae ante tempor semper. Suspendisse mattis at \
	mi non eleifend. Donec ultricies odio dui, eget elementum nunc fermentum non. \
	Sed id dui ut justo porta finibus ut vitae magna. Mauris malesuada ante at nisi \
	semper vehicula. Quisque nec orci tincidunt augue venenatis aliquet sed eget risus. \
	Donec facilisis porttitor lectus et porta. Vestibulum ante ipsum primis in \
	faucibus orci luctus et ultrices posuere cubilia curae; Etiam non molestie felis, \
	in ullamcorper sem. Nunc sed sodales dui. Proin lectus massa, varius at mi non, \
	pulvinar rhoncus urna. Praesent egestas vel tellus sed aliquam. \n Vestibulum eu \
	commodo velit. Vivamus pulvinar ex a nisi rhoncus, et scelerisque augue blandit. \
	Duis eget commodo lorem. Cras massa ipsum, dapibus sit amet euismod id, commodo \
	eu erat. Mauris lobortis vel mi a tempor. Praesent ornare mauris ligula, sit amet \
	tempus tortor bibendum rhoncus. Sed sed sollicitudin nibh. Pellentesque habitant \
	morbi tristique senectus et netus et malesuada fames ac turpis egestas. Sed sit \
	amet turpis suscipit, consectetur ante vel, elementum neque. Donec hendrerit est \
	ut urna rhoncus porttitor. Ut est risus, hendrerit id nunc eu, sodales vehicula \
	lorem. Etiam dui ex, sodales quis justo sit amet, semper feugiat tellus. \n \
	Aliquam luctus faucibus dictum. Vivamus finibus erat dui, in maximus justo \
	pretium at. Nullam sed lectus enim. Fusce eget purus in sapien vestibulum \
	pulvinar sit amet non metus. Integer quis dolor orci. Etiam lectus mi, sagittis \
	nec lorem ut, efficitur vulputate enim. Donec maximus quam vel est fringilla \
	malesuada eget at turpis. Pellentesque tincidunt erat id mollis tempus. Maecenas \
	dignissim risus varius leo rutrum, at bibendum nisi vulputate. Proin sem tortor, \
	convallis eu scelerisque non, sodales vitae quam. Duis est risus, scelerisque at \
	urna vitae, porttitor hendrerit ex. \n Interdum et malesuada fames ac ante \
	ipsum primis in faucibus. Pellentesque auctor rhoncus dapibus. Quisque viverra \
	id diam eget condimentum. Mauris sit amet tempor velit, eget mattis ex. Aenean \
	arcu nunc, ornare quis commodo nec, pretium quis diam. Nam sed libero nec dolor \
	rhoncus accumsan. Suspendisse sapien eros, viverra et sapien quis, semper \
	venenatis ex. In ut nisi ex. Orci varius natoque penatibus et magnis dis."; 
	printf(" (%i)\n", ft_printf("%s", testLongText));
	printf("printf: ");
	printf(" (%i)\n\n", printf("%s", testLongText));
	
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
	printf(" (%i)\n",ft_printf("%a", "Coucou")); //--> write nothing & return -1 
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%a", "Coucou"));

	printf(" (%i)\n",ft_printf("%s, %a", "Coucou")); // --> write the 1st arg & return -1 
//	printf("printf: ");
//	printf(" (%i)\n\n", printf("%s, %a", "Coucou"));

//	printf("\n-------- TEST / nil arg --------\n");
//	printf("printf: ");
//	printf(" (%i)\n", printf("%c")); // ---> "more '%' conversions than data arguments"
//	printf("ft_printf: ");
//	printf(" (%i)\n\n",ft_printf("%c")); // ---> write something & return 0

//	printf("\n-------- TEST / bad type arg --------\n");
//	printf("printf: ");
//	printf(" (%i)\n", printf("%s", 123));
//	printf("ft_printf: ");
//	printf(" (%i)\n\n", ft_printf("%s", 123));

//	printf("printf: ");
//	printf(" (%i)\n", printf("%i", 'A'));
//	printf("ft_printf: ");
//	printf(" (%i)\n\n", ft_printf("%i", 'A'));

	return 0;
}