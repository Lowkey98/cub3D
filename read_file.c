
# include "includes/cub3d.h"
# include "includes/libft.h"
# include "includes/get_next_line.h"

char *fetch_file(char *str)
{
    int  fd;
    char *buff;
	str = malloc(1);
    buff = malloc(100000);
    fd = open("map.cub",O_RDONLY);
    while(read(fd,buff,10000))
        str = ft_strjn(str,buff);
    return (str);
}
int		reach_map(t_struct *g_data)
{
	g_data = 0;
	//if(g_data -> r_check)
		//return (1);
		return (0);
}

char *skip_empty_lines(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == ' ')
	{
		if (str[i] == '\n')
			j = i + 1;
		i++;
	}
	return (str + j);
}

char *cut_string(char *str, char x)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == x)
		{
			str[i] = '\0';
			return (str);
		}
		i++;
	}
	return (str);

}
void	check_r(char **tab)
{
	int j;

	j = 0;
	if (tab[0][1] != '\0')
		ft_error("first information in resolution element has more than one character");
	if (tab[3] != 0 || tab[2] == 0 || tab[1] == 0)
		ft_error("you need 3 informations in resolution element");
	while (tab[1][j])
	{
		if (!ft_isdigit(tab[1][j]))
			ft_error("second information should be a number");
			j++;
	}
	j = 0;
	while (tab[2][j])
	{
		if (!ft_isdigit(tab[2][j]))
			ft_error("third information should be a number");
		j++;
	}
}
void fetch_ea(char *str)
{
	int i;
	void *tmp;
	i = 2;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	tmp = mlx_xpm_file_to_image(g_mlx.ptr, str + i,&i,&i);
	if (tmp == NULL)
		ft_error("ERROR\n East texture file doesnt exist");
	g_texture.east_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
	if (g_texture.east_texture == NULL)
		ft_error("ERROR \n East texture file  isnt readable");

	g_data.ea_completed = 1;

}
void fetch_we(char *str)
{
	int i;
	void *tmp;
	i = 2;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	tmp = mlx_xpm_file_to_image(g_mlx.ptr, str + i,&g_texture.west_texture_w,&g_texture.west_texture_h);
	//printf("%d\n",g_texture.west_texture_h);
	if (tmp == NULL)
		ft_error("ERROR\n West texture file doesnt exist");
	g_texture.west_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
	if (g_texture.west_texture == NULL)
		ft_error("ERROR \n West texture file  isnt readable");

	g_data.we_completed = 1;

}
void fetch_so(char *str)
{
	int i;
	void *tmp;
	i = 2;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	tmp = mlx_xpm_file_to_image(g_mlx.ptr, str + i,&i,&i);
	if (tmp == NULL)
		ft_error("ERROR\n South texture file doesnt exist");
	g_texture.south_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
	if (g_texture.south_texture == NULL)
		ft_error("ERROR \n South texture file  isnt readable");

	g_data.so_completed = 1;

}

void fetch_no(char *str)
{
	int i;
	void *tmp;
	i = 2;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	tmp = mlx_xpm_file_to_image(g_mlx.ptr, str + i,&i,&i);
	if (tmp == NULL)
		ft_error("ERROR\n Invalid North texture file");
	g_texture.north_texture = (int *)mlx_get_data_addr(tmp, &i,&i,&i);
	// int j = 0;
	// while (g_texture.north_texture[j])
	// 	j++;
	// printf("%d",j)

	g_data.no_completed = 1;

}
void fetch_r(char *str)
{
	char ** tmp;

	tmp = ft_split(str,' ');
	check_r(tmp);
	g_data.window_width = ft_atoi(tmp[1]);
	g_data.window_height = ft_atoi(tmp[2]);
	free(tmp);
	g_data.r_completed = 1;
}

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

int	reached_map()
{
	if (g_data.r_completed && g_data.f_completed && g_data.no_completed && g_data.so_completed && g_data.ea_completed && g_data.we_completed)
	{
		//printf("%d",g_data->r_completed);
		return (1);
	}
			//printf("%d",g_data->r_completed);

	return (0);
}
// void    fetch_data(char *str, t_struct *g_data)
// {
//     while(!reached_map(g_data))
// 	{
// 		str = fetch_element(str, g_data);
// 		///printf("a");
// 	}

// }
void fetch_f(char *str)
{
	int i;
	char **tmp;

	i = 0;
	tmp = ft_split(str + 1, ',');

	while (tmp[i])
		i++;
	if (i != 3)
		ft_error("wrong number of informations in element f");
	
	g_data.f_completed = 1;

}

void	fetch_element(char *str)
{
	 //forcomp

		if (*str == 'R')
			fetch_r(str);
		else if(*str == 'N')
			fetch_no(str);
		else if (*str == 'F')
			fetch_f(str);
		else if (*str == 'E')
			fetch_ea(str);
		else if (*str == 'W')
			fetch_we(str);
		else if (*str == 'S')
			fetch_so(str);
		else
			ft_error("element not known");
}


// void	add_spaces(t_struct g_data)
// {

// }
int max_lenght()
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = 0;
	while (g_data.map[i])
	{
		j = 0;
		while (g_data.map[i][j])
		{
			j++;
			if (j > max)
				max = j;

		}
		i++;
	}
	return (max);
}
void	add_spaces()
{
	char *tmp;
	int i;
	int j;
	int tmplen;

	i = 0;
	j = 0;

	while (g_data.map[i])
	{
		tmplen = g_data.map_lenght - ft_strlen(g_data.map[i]);
		tmp = calloc(tmplen + 1,1);
		tmp = ft_memset(tmp,' ',tmplen);
		g_data.map[i] = ft_strjoin(g_data.map[i],tmp);

		i++;


	}

	// tmp = ft_calloc(g_data->map_lenght + 1, 1);
		// tmp = ft_strcpy(tmp,g_data->map[i]);
		//ft_putstr(tmp);
		// j = ft_strlen(g_data -> map[i]);
		//ft_putnbr(j);
		// while(j < g_data->map_lenght)
		// {
		// 	tmp[j] = 'a';
		// 	j++;
		// }
	//free(g_data -> map[i]);
		// g_data->map[i] = tmp;
		// ft_putstr(g_data -> map[i]);
		// 		ft_putstr("\n");
    // free(tmp);
	// while (g_data -> map[i])
	// {
	// 	printf("%s",g_data->map[i]);
	// 	i++;
	// }
	// printf("%s",g_data->map[1]);
}
void	check_player()
{
	if (g_player.exists == 0)
		g_player.exists = 1;
	else
		ft_error("there should be only one player");

}
void	check_mapstr_error(char *map_str)
{
	int i;

	i = 0;
	while (map_str[i] == '\n')
		i++;
	while (map_str[i])
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
			ft_error("ERROR \nempty line in the map");
		if (map_str[i] == 'N' || map_str[i] == 'S' || map_str[i] == 'E' || map_str[i] == 'W')
			check_player();
		else if (map_str[i] != '1' && map_str[i] != '0' && map_str[i] != ' ' && map_str[i] != '\n' && map_str[i] != '2')
			ft_error("ERROR \nbad character in the map");
		i++;
	}
	if (g_player.exists == 0)
		ft_error("there is no player");

}
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
			j++;
		}
		i++;
	}

}
void	fetch_map(char *map_str)
{
	// int i = 0;
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
	fd = open(g_data.map_name,O_RDONLY);
	while(i)
	{
		i = get_next_line(fd,&line);
			if(!reached_map())
			{
				if(!empty_line(line))
					fetch_element(line);
			}
			else
				map_str = ft_strjn(map_str,line);
	}
	fetch_map(map_str);
	g_data.map_height = map_height();
    return (0);
}
