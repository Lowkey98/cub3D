/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:02:55 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:04:36 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/libft.h"
#include "includes/get_next_line.h"

void	add_spaces(void)
{
	char	*tmp;
	int		i;
	int		j;
	int		tmplen;

	i = 0;
	j = 0;
	while (g_data.map[i])
	{
		tmplen = g_data.map_lenght - ft_strlen(g_data.map[i]);
		tmp = calloc(tmplen + 1, 1);
		tmp = ft_memset(tmp, ' ', tmplen);
		g_data.map[i] = ft_strjoin(g_data.map[i], tmp);
		free(tmp);
		i++;
	}
}

void	check_player(char *map_str)
{
	if (g_player.exists == 0)
		g_player.exists = 1;
	else
		ft_error("there should be only one player", map_str);
}

void	check_mapstr_error(char *map_str)
{
	int i;

	i = 0;
	while (map_str[i] == '\n')
		i++;
	if (map_str[i] == '\0')
		ft_error("no map", map_str);
	while (map_str[i])
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
			ft_error("ERROR \nempty line in the map", map_str);
		if (map_str[i] == 'N' || map_str[i] == 'S' || map_str[i] == 'E' ||
		map_str[i] == 'W')
			check_player(map_str);
		else if (map_str[i] != '1' && map_str[i] != '0' && map_str[i] != ' '
		&& map_str[i] != '\n' && map_str[i] != '2')
			ft_error("ERROR \nbad character in the map", map_str);
		i++;
	}
	if (g_player.exists == 0)
		ft_error("no player nor surface to use", map_str);
}
