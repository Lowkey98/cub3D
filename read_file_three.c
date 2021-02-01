# include "includes/cub3d.h"

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
int	reached_map()
{
	if (g_data.s_completed && g_data.r_completed && g_data.c_completed && g_data.f_completed && g_data.no_completed && g_data.so_completed && g_data.ea_completed && g_data.we_completed)
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
// void fetch_f_r(char **tmp)
// {
// 	int i;

// 	i = 0;


// }


void	fetch_element(char *str)
{
	 //forcomp
		if (*str == 'R' && *(str + 1) == ' ')
			fetch_r(str);
		else if(*str == 'N')
			fetch_no(str);
		else if (*str == 'C' && *(str + 1) == ' ')
			fetch_c(str);
		else if (*str == 'F' && *(str + 1) == ' ')
			fetch_f(str);
		else if (*str == 'E')
			fetch_ea(str);
		else if (*str == 'W')
			fetch_we(str);
		else if (*str == 'S' && *(str + 1) == 'O')
			fetch_so(str);
		else if (*str == 'S' && *(str + 1) == ' ')
			fetch_s(str);
		else
			ft_error("error in elements",str);
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