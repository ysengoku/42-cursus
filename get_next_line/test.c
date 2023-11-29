#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int	fd;

	fd = open("filenamr.txt", O_RDONLY);
	return 0;
}

// int open (const char* path, int flags [, int mode ]);
// returns File Descriptor (small nonnegative int) or -1 (error).