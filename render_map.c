/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:18:51 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:19:40 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	fetch_rotation_angle(void)
{
	if (g_player.direction == 'S')
		g_player.rotation_angle = PI / 2;
	else if (g_player.direction == 'W')
		g_player.rotation_angle = PI;
	else if (g_player.direction == 'N')
		g_player.rotation_angle = 3 * PI / 2;
	else if (g_player.direction == 'E')
		g_player.rotation_angle = 2 * PI;
}

void	fetch_player_info(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g_data.map[i])
	{
		j = 0;
		while (g_data.map[i][j])
		{
			if (g_data.map[i][j] == 'N' || g_data.map[i][j] == 'S' ||
			g_data.map[i][j] == 'E' || g_data.map[i][j] == 'W')
			{
				g_player.direction = g_data.map[i][j];
				g_player.x = j * g_tile_size + g_tile_size / 2;
				g_player.y = i * g_tile_size + g_tile_size / 2;
			}
			j++;
		}
		i++;
	}
	fetch_rotation_angle();
}

void	draw_rect(int i, int j, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y != g_tile_size)
	{
		x = 0;
		while (x != g_tile_size)
		{
			my_mlx_pixel_put(&g_mlx, ((j * g_tile_size) + x) * MINIMAP_SCALE,
			((i * g_tile_size) + y) * MINIMAP_SCALE, color);
			x++;
		}
		y++;
	}
}

int		grid_color(int i, int j)
{
	if (g_data.map[i][j] == '1')
		return (GREEN);
	if (g_data.map[i][j] == '0' || g_data.map[i][j] == 'N')
		return (BLUE);
	if (g_data.map[i][j] == ' ')
		return (PURPLE);
	return (WHITE);
}

void	draw_map(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g_data.map[i])
	{
		j = 0;
		while (g_data.map[i][j])
		{
			draw_rect(i, j, grid_color(i, j));
			j++;
		}
		i++;
	}
}
