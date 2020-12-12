
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
			ft_error("element not known",str);
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
			if (j > max)
				max = j;
			j++;
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

	i = 0;
	j = 0;
	tmp = malloc(data->map_lenght);
	while(data->map[i])
	{
		tmp = ft_strcpy(tmp,data->map[i]);
		j = ft_strlen(tmp);
		while(data -> map[i][j])
		{
			tmp[j] = 'a';
			j++;
		}
		i++;
	//free(data -> map[i]);
	data->map[i] = tmp;
	}
	
	//printf("%s",data->map[1]);
}
void	fetch_map(char *map_str, t_struct *data)
{
	//int i = 0;
		data -> map = ft_split(map_str,'\n');
		data -> map_lenght = max_lenght(data->map);
	//ft_putstr("a");
		//printf("%s",data->map[1]);
			//printf("%s\n",data->map[1]);

		//add_spaces(data);
		while (data -> map[i])
		{
			printf("%s",data->map[i]);
			i++;
		}
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
	map_str = malloc(1);
	fd = open("map.cub",O_RDONLY);
	while(i)
	{
		i = get_next_line(fd,&line);
		if (!empty_line(line))
		{		
			if (!reached_map(data))
				fetch_element(line, data);
			else
				map_str = ft_strjn(map_str,line);
		}
	}
	fetch_map(map_str,data);
    return (0);
}   