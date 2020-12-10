#include <fcntl.h>
#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main()
{
	char *str;

	str = malloc(11);
	str[0] = 'h';
	str[1] = 'h';
	str[2] = 'h';
	str[3] = 'h';
	str++;
	printf("%s",str);
	free(str);
}
/*char *skip_empty_lines(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' ||  str[i] == '\n')
	{
		i++;
	}
	return (str + i);
}
*/
/*int main()
{
	int fd;
	char *str;
	int i;
	fd = open("map.cub",O_RDONLY);
	str = malloc(100000);
	
	i = read(fd,str,10000);
	str[i] = '\0';
	printf("%s",skip_empty_lines(str));
}
*/
