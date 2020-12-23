#include <stdio.h>
#include <fcntl.h>
int main()
{
	char *line;
	char **lines;
	int j = 0;
	int fd;

	fd = open("./text.cub",O_RDONLY);
	while(get_next_line(fd, &line))
	{
		*lines = realloc(line, j);
		printf("%s",line);
		j++;
	}
	printf("%s",line);
}
