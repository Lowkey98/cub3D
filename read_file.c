# include "includes/cub3d.h"
# include "includes/libft.h"
# include "includes/get_next_line.h"
char	*ft_strjn(char *s1, char *s2)
{
	char		*temp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (s2[i] != 0)
		i++;
	if ((temp = malloc(ft_strlen(s1) + i + 1)) == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	free(s1);
	return (temp);
}
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
char *fetch_r(char *str, t_struct *data)
{
	char ** tmp;
	
	tmp = ft_split(str,' ');
	check_r(tmp);
	data -> x_render_size = ft_atoi(tmp[1]);
	data -> y_render_size = ft_atoi(tmp[2]);
	free(tmp);
	data -> r_completed = 1;
	return (str);
}
void	check_f()
{
	
}
char *fetch_f(char *str)
{
	char ** tmp;

	tmp = ft_split(str, ' ');
	check_f();
	return(str);
}
char *skip_element(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	return (str + i);
}
char *fetch_element(char *str, t_struct *data)
{
	str = skip_empty_lines(str);
	if (*str == 'R')
		str = fetch_r(cut_string(str,'\n'), data);
	else if(*str == 'F')
		str = fetch_f(cut_string(str,'\n'), data);
	else 
		ft_error("element not known");
	str = skip_element(str);
	return (str);
}
int	reached_map(t_struct *data)
{
	if (data -> r_completed)
	{
		//printf("%d",data->r_completed);
		return (1);
	}
			//printf("%d",data->r_completed);

	return (0);
}
void    fetch_data(char *str, t_struct *data)
{
    while(!reached_map(data))
	{
		str = fetch_element(str, data);
		///printf("a");
	}
	
}
int read_file(t_struct *data)
{
   char *str;
   
   str = 0;
   //str = malloc(1);
   str = fetch_file(str);
   fetch_data(str,data);
    // added for compilation
   
    return (0);
}   