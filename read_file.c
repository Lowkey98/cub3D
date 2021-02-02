/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:08:20 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:17:18 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/libft.h"
#include "includes/get_next_line.h"

void	check_map_frame(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g_data.map[i])
	{
		if (g_data.map[i][0] == '0' ||
		g_data.map[i][g_data.map_lenght - 1] == '0'
		|| g_data.map[i][0] == '2' ||
		g_data.map[i][g_data.map_lenght - 1] == '2')
			ft_error_map("ERROR\n error at the edge of the map");
		i++;
	}
	while (g_data.map[0][j])
	{
		if (g_data.map[0][j] == '0' || g_data.map[i - 1][j] == '0' ||
		g_data.map[0][j] == '2' || g_data.map[i - 1][j] == '2')
			ft_error_map("ERROR\n error at the edge of the map");
		j++;
	}
}

void	check_map_error(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	check_map_frame();
	while (g_data.map[i + 1])
	{
		j = 0;
		while (g_data.map[i + 1][j + 1])
		{
			if (g_data.map[i + 1][j + 1] == '0' ||
			g_data.map[i + 1][j + 1] == 'N'
		|| g_data.map[i + 1][j + 1] == 'S' || g_data.map[i + 1][j + 1] == 'W' ||
		g_data.map[i + 1][j + 1] == 'E' || g_data.map[i + 1][j + 1] == '2')
				if (g_data.map[i + 1][j] == ' ' || g_data.map[i][j + 1] == ' '
		|| g_data.map[i + 1][j + 2] == ' ' || g_data.map[i + 2][j + 1] == ' ')
					ft_error_map("ERROR\n invalid character next to space");
			if (g_data.map[i][j] == '2')
				fetch_sprite_position(i, j);
			j++;
		}
		i++;
	}
}

int		map_height(void)
{
	int i;

	i = 0;
	while (g_data.map[i])
		i++;
	return (i);
}

void	fetch_map(char *map_str)
{
	if (!g_data.r_completed)
		ft_error("empty file", map_str);
	if (*map_str == '\0')
		ft_error("there is no map", map_str);
	check_mapstr_error(map_str);
	g_data.map = ft_split(map_str, '\n');
	g_data.map_lenght = max_lenght();
	add_spaces();
	check_map_error();
	g_data.map_height = map_height();
}

int		read_file(void)
{
	char	*line;
	int		fd;
	int		i;
	char	*map_str;

	i = 1;
	map_str = ft_calloc(1, 1);
	if ((fd = open(g_data.map_name, O_RDONLY)) == -1)
		ft_error("file cant be opened", map_str);
	while (i)
	{
		i = get_next_line(fd, &line);
		if (!reached_map())
		{
			if (!empty_line(line))
				fetch_element(line);
		}
		else
			map_str = ft_strjn(map_str, line);
		free(line);
	}
	fetch_map(map_str);
	free(map_str);
	return (0);
}
