/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:13:40 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 09:52:54 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	normalize_angle(int ray_i)
{
	g_rays[ray_i].ray_angle = remainderf(g_rays[ray_i].ray_angle, (2 * PI));
	if (g_rays[ray_i].ray_angle < 0)
		g_rays[ray_i].ray_angle = (2 * PI) + g_rays[ray_i].ray_angle;
}

void	ray_facing(int ray_i)
{
	g_rays[ray_i].is_ray_facing_down = 0;
	g_rays[ray_i].is_ray_facing_up = 0;
	g_rays[ray_i].is_ray_facing_right = 0;
	g_rays[ray_i].is_ray_facing_left = 0;
	if (g_rays[ray_i].ray_angle > 0 && g_rays[ray_i].ray_angle < PI)
		g_rays[ray_i].is_ray_facing_down = 1;
	else
		g_rays[ray_i].is_ray_facing_up = 1;
	if (g_rays[ray_i].ray_angle < 0.5 * PI ||
		g_rays[ray_i].ray_angle > 1.5 * PI)
		g_rays[ray_i].is_ray_facing_right = 1;
	else
		g_rays[ray_i].is_ray_facing_left = 1;
}

void	initialize_cast_data(int ray_i)
{
	g_rays[ray_i].y_intercept = 0;
	g_rays[ray_i].x_intercept = 0;
	g_rays[ray_i].y_step = 0;
	g_rays[ray_i].x_step = 0;
	g_rays[ray_i].next_h_x = 0;
	g_rays[ray_i].next_h_y = 0;
	g_rays[ray_i].wall_hit_h_x = 0;
	g_rays[ray_i].wall_hit_h_y = 0;
	g_rays[ray_i].found_h_wall = 0;
	g_rays[ray_i].next_v_x = 0;
	g_rays[ray_i].next_v_y = 0;
	g_rays[ray_i].wall_hit_v_x = 0;
	g_rays[ray_i].wall_hit_v_y = 0;
	g_rays[ray_i].found_v_wall = 0;
	g_rays[ray_i].is_ray_facing_left = 0;
	g_rays[ray_i].is_ray_facing_up = 0;
	g_rays[ray_i].is_ray_facing_right = 0;
	g_rays[ray_i].is_ray_facing_down = 0;
}

void	horizontal_cast(int ray_i)
{
	while (g_rays[ray_i].next_h_x >= 0 &&
	g_rays[ray_i].next_h_x < (g_data.map_lenght * g_tile_size) &&
	g_rays[ray_i].next_h_y >= 0 &&
	g_rays[ray_i].next_h_y < (g_data.map_height * g_tile_size))
	{
		if (is_wall_at(g_rays[ray_i].next_h_x,
		g_rays[ray_i].next_h_y - g_rays[ray_i].is_ray_facing_up))
		{
			g_rays[ray_i].wall_hit_h_x = g_rays[ray_i].next_h_x;
			g_rays[ray_i].wall_hit_h_y = g_rays[ray_i].next_h_y;
			g_rays[ray_i].found_h_wall = 1;
			break ;
		}
		else
		{
			g_rays[ray_i].next_h_x += g_rays[ray_i].x_step;
			g_rays[ray_i].next_h_y += g_rays[ray_i].y_step;
		}
	}
}

float	distance_two_points(float x_one, float y_one, float x_two, float y_two)
{
	return (sqrt((x_one - x_two) * (x_one - x_two)
	+ (y_one - y_two) * (y_one - y_two)));
}
