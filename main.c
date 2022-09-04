#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	//char	*line;
	static int	i = 1;
	int	fd1 = open("tests/test.txt", O_RDONLY);
	int	fd2 = open("tests/test1.txt", O_RDONLY);
	int	fd3 = open("tests/test2.txt", O_RDONLY);

	while (i < 4)
	{
        while (i < 4)
            printf("line [%02d]: %s\n", i++, get_next_line(fd1));
        /*while (i < 7)
            printf("line [%02d]: %s\n", i++, get_next_line(fd2));
        while (i < 9)
            printf("line [%02d]: %s\n", i++, get_next_line(fd3));
	*/}
	close(fd1);
    close(fd2);
    close(fd3);
	return (0);
}
