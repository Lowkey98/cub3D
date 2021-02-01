
# include "includes/cub3d.h"
# include "includes/libft.h"
# include "includes/get_next_line.h"








// char *fetch_f(char *str)
// {
// 	char ** tmp;

// 	tmp = ft_split(str, ' ');
// 	check_f();
// 	return(str);
// }
// char *skip_element(char *str)
// {
// 	int i;

// 	i = 0;
// 	while(str[i] != '\0' && str[i] != '\n')
// 		i++;
// 	return (str + i);
// }



void	check_map_frame()
{
	int i;
	int j;
	i = 0;
	j = 0;

	while(g_data.map[i])
	{
		//ft_putnbr(g_data->map_lenght - 1);
		if (g_data.map[i][0] == '0' || g_data.map[i][g_data.map_lenght - 1] == '0' || g_data.map[i][0] == '2' || g_data.map[i][g_data.map_lenght - 1] == '2' )
			ft_error("ERROR\n error at the edge of the map");
		i++;
	}
	while(g_data.map[0][j])
	{
		if (g_data.map[0][j] == '0' || g_data.map[i - 1][j] == '0' || g_data.map[0][j] == '2' || g_data.map[i - 1][j] == '2')
			ft_error("ERROR\n error at the edge of the map");
		j++;
	}

}
void	check_map_error()
{
	int i;
	int j;

	i = 0;
	j = 0;
	check_map_frame();
	while(g_data.map[i + 1])
	{
		j = 0;
		while (g_data.map[i + 1][j + 1])
		{
			if (g_data.map[i + 1][j + 1] == '0' || g_data.map[i + 1][j + 1] == 'N' || g_data.map[i + 1][j + 1] == 'S' || g_data.map[i + 1][j + 1] == 'W' || g_data.map[i + 1][j + 1] == 'E' || g_data.map[i + 1][j + 1] == '2')
				if (g_data.map[i + 1][j] == ' ' || g_data.map[i][j + 1] == ' ' || g_data.map[i + 1][j + 2] == ' ' || g_data.map[i + 2][j + 1] == ' ')
					ft_error("ERROR\n invalid character next to space");
			if (g_data.map[i][j] == '2')
				fetch_sprite_position(i,j);
			j++;
		}
		i++;
	}
	//printlinked();

}
void	fetch_map(char *map_str)
{
	// int i = 0;
	if (!g_data.r_completed)
		ft_error("empty file");
	if (*map_str == '\0')
		ft_error("there is no map");
		check_mapstr_error(map_str);
		g_data.map = ft_split(map_str,'\n');
		g_data.map_lenght = max_lenght();
		add_spaces();
		check_map_error();
		// i=0;
		// while (g_data -> map[i])
		// {
		// 	ft_putstr(g_data->map[i]);
		// 	ft_putstr("\n");
		// 	i++;
		// }
		//ft_putnbr(max_lenght(g_data->map));
		//ft_putnbr(g_data->map_lenght);
	//ft_putstr("a");
		//printf("%s",g_data->map[1]);
			//printf("%s\n",g_data->map[1]);

		// while (g_data -> map[i])
		// {
		// 	printf("%s",g_data->map[i]);
		// 	i++;
		// }
		//printf("%d",g_data->map_lenght);
		//free(map_str);
}
int map_height()
{
	int i;
	i = 0;

	while(g_data.map[i])
		i++;
	return (i);
}
int read_file()
{
	char *line;
	int fd;
	int i;
	char *map_str;

	i = 1;
	map_str = ft_calloc(1,1);
	if ((fd = open(g_data.map_name,O_RDONLY)) == -1)
		ft_error("file cant be opened");
	while(i)
	{
		i = get_next_line(fd,&line);
		g_str = line;
			if(!reached_map())
			{
				if(!empty_line(line))
					fetch_element(line);
				free(line);
			}
			else
			{
				map_str = ft_strjn(map_str,line);
				free(line);
			}
	}
	fetch_map(map_str);
	g_data.map_height = map_height();
	free(map_str);
    return (0);
}
