#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
//	while ()
//	printf("%s\n", get_next_line(fd));
	close(fd);
	return 0;
}

// int open (const char* path, int flags [, int mode ]);
// returns File Descriptor (small nonnegative int) or -1 (error).