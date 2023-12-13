#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("test_multilines.txt", O_RDONLY);
	while (1)
 	{
 		line = get_next_line(fd);
 		printf("%s", line);
	 	free(line);
		if (!line)
 			break ;
 	}
	close(fd);
	return(0);
}

// int open (const char* path, int flags [, int mode ]);
// returns File Descriptor (small nonnegative int) or -1 (error).
