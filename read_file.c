
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
int		reach_map(t_struct *data)
{
	data = 0;
	//if(data -> r_check)
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
// void	check_r(char **tab)
// {
// 	int j;

// 	j = 0;
// 	if (tab[0][1] != '\0')
// 		ft_error("first information in resolution element has more than one character");
// 	if (tab[3] != 0 || tab[2] == 0 || tab[1] == 0)
// 		ft_error("you need 3 informations in resolution element");
// 	while (tab[1][j])
// 	{
// 		if (!ft_isdigit(tab[1][j]))
// 			ft_error("second information should be a number");
// 			j++;
// 	}
// 	j = 0;
// 	while (tab[2][j])
// 	{
// 		if (!ft_isdigit(tab[2][j]))
// 			ft_error("third information should be a number");
// 		j++;
// 	}
// }
// char *fetch_r(char *str, t_struct *data)
// {
// 	char ** tmp;
	
// 	tmp = ft_split(str,' ');
// 	check_r(tmp);
// 	data -> x_render_size = ft_atoi(tmp[1]);
// 	data -> y_render_size = ft_atoi(tmp[2]);
// 	free(tmp);
// 	data -> r_completed = 1;
// 	return (str);
// }
// void	check_f()
// {
	
// }
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

int	reached_map(t_struct *data)
{
	if (data -> r_completed && data -> f_completed)
	{
		//printf("%d",data->r_completed);
		return (1);
	}
			//printf("%d",data->r_completed);

	return (0);
}
// void    fetch_data(char *str, t_struct *data)
// {
//     while(!reached_map(data))
// 	{
// 		str = fetch_element(str, data);
// 		///printf("a");
// 	}
	
// }

void	fetch_element(char *str, t_struct *data)
{
	 //forcomp
		while (*str == ' ')
			str++;
		if (*str == 'R')
			data -> r_completed = 1;
		else if(*str == 'F')
			data -> f_completed = 1;
		else
			ft_error("element not known");
}


// void	add_spaces(t_struct data)
// {

// }
int max_lenght(char **map)
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
			if (j > max)
				max = j;
			
		}
		i++;
	}
	return (max);
}
void	add_spaces(t_struct *data)
{
	char *tmp;
	int i;
	int j;
	int tmplen;

	i = 0;
	j = 0;
	
	while (data->map[i])
	{
		tmplen = data->map_lenght - ft_strlen(data->map[i]);
		tmp = calloc(tmplen + 1,1);
		tmp = ft_memset(tmp,' ',tmplen);
		data -> map[i] = ft_strjoin(data -> map[i],tmp);
		
		i++;
		

	}
	 
	// tmp = ft_calloc(data->map_lenght + 1, 1);
		// tmp = ft_strcpy(tmp,data->map[i]);
		//ft_putstr(tmp);
		// j = ft_strlen(data -> map[i]);
		//ft_putnbr(j);
		// while(j < data->map_lenght)
		// {
		// 	tmp[j] = 'a';
		// 	j++;
		// }
	//free(data -> map[i]);
		// data->map[i] = tmp;
		// ft_putstr(data -> map[i]);
		// 		ft_putstr("\n");
    // free(tmp);
	// while (data -> map[i])
	// {
	// 	printf("%s",data->map[i]);
	// 	i++;
	// }
	// printf("%s",data->map[1]);
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
		else if (map_str[i] != '1' && map_str[i] != '0' && map_str[i] != ' ' && map_str[i] != '\n')
			ft_error("ERROR \nbad character in the map");
		i++;
	}
}
void	check_map_frame(t_struct *data)
{
	int i;
	int j;
	i = 0;
	j = 0;

	while(data->map[i])
	{
		//ft_putnbr(data->map_lenght - 1);
		if (data->map[i][0] == '0' || data -> map[i][data->map_lenght - 1] == '0')
			ft_error("ERROR\n 0 at the edge of the map");
		i++;
	}
	while(data->map[0][j])
	{
		if (data->map[0][j] == '0' || data->map[i - 1][j] == '0')
			ft_error("ERROR\n 0 at the edge of the map");
		j++;
	}

}
void	check_map_error(t_struct *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	check_map_frame(data);
	while(data ->map[i + 1])
	{
		j = 0;
		while (data ->map[i + 1][j + 1])
		{
			if (data ->map[i + 1][j + 1] == '0' || data ->map[i + 1][j + 1] == 'N' || data ->map[i + 1][j + 1] == 'S' || data ->map[i + 1][j + 1] == 'W' || data ->map[i + 1][j + 1] == 'E')
				if (data ->map[i + 1][j] == ' ' || data ->map[i][j + 1] == ' ' || data ->map[i + 1][j + 2] == ' ' || data ->map[i + 2][j + 1] == ' ')
					ft_error("ERROR\n0 next to space");
			j++;
		}
		i++;
	}

}
void	fetch_map(char *map_str, t_struct *data)
{
	// int i = 0;
		check_mapstr_error(map_str);
		data -> map = ft_split(map_str,'\n');
		data -> map_lenght = max_lenght(data->map);
		add_spaces(data);
		check_map_error(data);
		// i=0;
		// while (data -> map[i])
		// {
		// 	ft_putstr(data->map[i]);
		// 	ft_putstr("\n");
		// 	i++;
		// }
		//ft_putnbr(max_lenght(data->map));
		//ft_putnbr(data->map_lenght);
	//ft_putstr("a");
		//printf("%s",data->map[1]);
			//printf("%s\n",data->map[1]);

		// while (data -> map[i])
		// {
		// 	printf("%s",data->map[i]);
		// 	i++;
		// }
		//printf("%d",data->map_lenght);
		//free(map_str);
}
int read_file(t_struct *data)
{
	char *line;
	int fd;
	int i;
	char *map_str;

	i = 1;
	map_str = ft_calloc(1,1);
	fd = open("map.cub",O_RDONLY);
	while(i)
	{
		i = get_next_line(fd,&line);
			if(!reached_map(data))
			{
				if(!empty_line(line))
					fetch_element(line, data);
			}
			else
				map_str = ft_strjn(map_str,line);
	}
	fetch_map(map_str,data);
    return (0);
}   