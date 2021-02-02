/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:04:56 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:04:57 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

char	*skip_empty_lines(char *str)
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

int		reached_map(void)
{
	if (g_data.s_completed && g_data.r_completed && g_data.c_completed
	&& g_data.f_completed && g_data.no_completed && g_data.so_completed
	&& g_data.ea_completed && g_data.we_completed)
	{
		return (1);
	}
	return (0);
}

void	fetch_element(char *str)
{
	if (*str == 'R' && *(str + 1) == ' ')
		fetch_r(str);
	else if (*str == 'N')
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
		ft_error("error in elements", str);
}

int		max_lenght(void)
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
