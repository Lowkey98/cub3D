/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:53:08 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 09:55:34 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	initialize_data(char *argv)
{
	g_data.map_name = argv;
	g_data.map = 0;
	g_data.x_render_size = 0;
	g_data.y_render_size = 0;
	g_data.r_completed = 0;
	g_data.f_completed = 0;
	g_data.map_lenght = 0;
	g_tile_size = 64;
	g_fov_angle = 60 * PI / 180;
	g_sprite_h = NULL;
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
}

int		is_wall_at(float x, float y)
{
	int i;
	int j;

	i = y / g_tile_size;
	j = x / g_tile_size;
	if (g_data.map[i][j] == '1' || g_data.map[i][j] == ' ')
		return (1);
	return (0);
}

void	move_player(void)
{
	float tmp_x;
	float tmp_y;
	g_player.move_speed = 10;
	g_player.move_step = g_player.move_speed * g_player.walk_direction;
	tmp_x = g_player.x + cos(g_player.rotation_angle + g_a) * g_player.move_step;
	tmp_y = g_player.y + sin(g_player.rotation_angle  + g_a) * g_player.move_step;
	g_a = 0;
	if (is_wall_at(tmp_x,tmp_y))
		return ;
	g_player.x = tmp_x;
	g_player.y = tmp_y;
}

void	draw_player(void)
{
	int	i;

	i =	0;
	while (i != g_tile_size)
	{
		g_player.line_x = g_player.x + (cos(g_player.rotation_angle) * i);
		g_player.line_y = g_player.y + (sin(g_player.rotation_angle) * i);
		my_mlx_pixel_put(&g_mlx, g_player.line_x * MINIMAP_SCALE ,g_player.line_y * MINIMAP_SCALE, GREEN);
		i++;
	}
}

void	rotate_player(void)
{
	g_player.rotation_speed = 5 * (PI /180);
    g_player.rotation_angle += g_player.turn_direction * g_player.rotation_speed;
    //ft_putnbr(g_player.turn_direction);
}