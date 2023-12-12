#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	line = get_next_line(fd);	
	printf("1. %s\n", line);

	line = get_next_line(fd);	
	printf("2. %s\n", line);

	line = get_next_line(fd);	
	printf("3. %s\n", line);

	line = get_next_line(fd);	
	printf("4. %s\n", line);

	free(line);
	close(fd);
	return(0);
}

// int open (const char* path, int flags [, int mode ]);
// returns File Descriptor (small nonnegative int) or -1 (error).


/*
	char buf[BUFSIZE];
	read(fd, buf, BUFSIZE);
	printf("%s\n", buf);
*/
