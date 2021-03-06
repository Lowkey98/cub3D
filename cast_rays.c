/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:45:22 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 14:52:43 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	vertical_cast(int ray_i)
{
	while (g_rays[ray_i].next_v_x >= 0 && g_rays[ray_i].next_v_x
	<= (g_data.map_lenght * g_tile_size) && g_rays[ray_i].next_v_y
	>= 0 && g_rays[ray_i].next_v_y <= (g_data.map_height * g_tile_size))
	{
		if (is_wall_at(g_rays[ray_i].next_v_x -
		g_rays[ray_i].is_ray_facing_left, g_rays[ray_i].next_v_y))
		{
			g_rays[ray_i].wall_hit_v_x = g_rays[ray_i].next_v_x;
			g_rays[ray_i].wall_hit_v_y = g_rays[ray_i].next_v_y;
			g_rays[ray_i].found_v_wall = 1;
			break ;
		}
		else
		{
			g_rays[ray_i].next_v_x += g_rays[ray_i].x_step;
			g_rays[ray_i].next_v_y += g_rays[ray_i].y_step;
		}
	}
}

void	shortest_cast(int ray_i)
{
	if (g_rays[ray_i].found_h_wall)
		g_rays[ray_i].h_distance = distance_two_points(g_player.x, g_player.y
		, g_rays[ray_i].wall_hit_h_x, g_rays[ray_i].wall_hit_h_y);
	else
		g_rays[ray_i].h_distance = MAXFLOAT;
	if (g_rays[ray_i].found_v_wall)
		g_rays[ray_i].v_distance = distance_two_points(g_player.x, g_player.y
		, g_rays[ray_i].wall_hit_v_x, g_rays[ray_i].wall_hit_v_y);
	else
		g_rays[ray_i].v_distance = MAXFLOAT;
	if (g_rays[ray_i].v_distance > g_rays[ray_i].h_distance)
	{
		g_rays[ray_i].wall_hit_x = g_rays[ray_i].wall_hit_h_x;
		g_rays[ray_i].wall_hit_y = g_rays[ray_i].wall_hit_h_y;
		g_rays[ray_i].distance = g_rays[ray_i].h_distance;
		g_rays[ray_i].is_wall_h = 1;
	}
	else
	{
		g_rays[ray_i].wall_hit_x = g_rays[ray_i].wall_hit_v_x;
		g_rays[ray_i].wall_hit_y = g_rays[ray_i].wall_hit_v_y;
		g_rays[ray_i].distance = g_rays[ray_i].v_distance;
		g_rays[ray_i].is_wall_v = 1;
	}
}

void	horizontal_intercept(int ray_i)
{
	g_rays[ray_i].y_intercept = floor(g_player.y / g_tile_size) * g_tile_size;
	if (g_rays[ray_i].is_ray_facing_down)
		g_rays[ray_i].y_intercept += g_tile_size;
	g_rays[ray_i].x_intercept = g_player.x + (g_rays[ray_i].y_intercept
	- g_player.y) / tan(g_rays[ray_i].ray_angle);
	g_rays[ray_i].y_step = g_tile_size;
	if (g_rays[ray_i].is_ray_facing_up)
		g_rays[ray_i].y_step *= -1;
	g_rays[ray_i].x_step = g_tile_size / tan(g_rays[ray_i].ray_angle);
	if (g_rays[ray_i].is_ray_facing_left && g_rays[ray_i].x_step > 0)
		g_rays[ray_i].x_step *= -1;
	if (g_rays[ray_i].is_ray_facing_right && g_rays[ray_i].x_step < 0)
		g_rays[ray_i].x_step *= -1;
	g_rays[ray_i].next_h_x = g_rays[ray_i].x_intercept;
	g_rays[ray_i].next_h_y = g_rays[ray_i].y_intercept;
}

void	vertical_intercept(int ray_i)
{
	g_rays[ray_i].x_intercept = floor(g_player.x / g_tile_size) * g_tile_size;
	if (g_rays[ray_i].is_ray_facing_right)
		g_rays[ray_i].x_intercept += g_tile_size;
	g_rays[ray_i].y_intercept = g_player.y + (g_rays[ray_i].x_intercept -
	g_player.x) * tan(g_rays[ray_i].ray_angle);
	g_rays[ray_i].x_step = g_tile_size;
	if (g_rays[ray_i].is_ray_facing_left)
		g_rays[ray_i].x_step *= -1;
	g_rays[ray_i].y_step = g_tile_size * tan(g_rays[ray_i].ray_angle);
	if (g_rays[ray_i].is_ray_facing_up && g_rays[ray_i].y_step > 0)
		g_rays[ray_i].y_step *= -1;
	if (g_rays[ray_i].is_ray_facing_down && g_rays[ray_i].y_step < 0)
		g_rays[ray_i].y_step *= -1;
	g_rays[ray_i].next_v_x = g_rays[ray_i].x_intercept;
	g_rays[ray_i].next_v_y = g_rays[ray_i].y_intercept;
}

void	cast_rays(void)
{
	int		ray_i;
	float	angle_inc;

	ray_i = 0;
	angle_inc = g_fov_angle / g_num_rays;
	while (ray_i < g_num_rays)
	{
		g_rays[ray_i].ray_angle = (g_player.rotation_angle -
		(g_fov_angle / 2)) + (ray_i * angle_inc);
		normalize_angle(ray_i);
		initialize_cast_data(ray_i);
		ray_facing(ray_i);
		horizontal_intercept(ray_i);
		horizontal_cast(ray_i);
		vertical_intercept(ray_i);
		vertical_cast(ray_i);
		shortest_cast(ray_i);
		ray_i++;
	}
}
