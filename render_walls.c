/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:23:27 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:29:52 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int		wall_to_texture(int j, int i)
{
	int y;

	y = j + (g_rays[i].wall_stripe_height / 2) - (g_data.window_height / 2);
	return (y * (g_tile_size / g_rays[i].wall_stripe_height));
}

int		*fetch_texture(int i)
{
	if (g_rays[i].is_ray_facing_up && g_rays[i].is_wall_h)
		return (g_texture.north_texture);
	if (g_rays[i].is_ray_facing_down && g_rays[i].is_wall_h)
		return (g_texture.south_texture);
	if (g_rays[i].is_ray_facing_left && g_rays[i].is_wall_v)
		return (g_texture.west_texture);
	if (g_rays[i].is_ray_facing_right && g_rays[i].is_wall_v)
		return (g_texture.east_texture);
	return (NULL);
}

void	draw_walls(int i, float *j)
{
	float	inc;
	int		texture_start;
	int		*texture;
	int		n;

	texture = fetch_texture(i);
	inc = 0;
	if (g_rays[i].is_wall_v)
	{
		texture_start = fmod(g_rays[i].wall_hit_y, g_tile_size);
	}
	else
		texture_start = fmod(g_rays[i].wall_hit_x, g_tile_size);
	while (inc < g_rays[i].wall_stripe_height && *j < g_data.window_height)
	{
		n = (wall_to_texture(*j, i) * g_tile_size) + texture_start;
		if (n >= 4096)
			n = 4095;
		my_mlx_pixel_put(&g_mlx, i, *j, texture[n]);
		inc++;
		(*j)++;
	}
}

void	draw_floor(int i, float *j)
{
	while (*j < g_data.window_height)
	{
		my_mlx_pixel_put(&g_mlx, i, *j, g_data.f_color);
		(*j)++;
	}
}

void	render_walls(void)
{
	int		i;
	float	y;
	float	j;
	float	correct_distance;

	j = 0;
	y = 0;
	i = 0;
	while (i < g_num_rays)
	{
		correct_distance = g_rays[i].distance * cos(g_rays[i].ray_angle -
		g_player.rotation_angle);
		g_rays[i].distance_projection_plane = (g_data.window_width / 2) /
		tan(g_fov_angle / 2);
		g_rays[i].wall_stripe_height = (g_tile_size / correct_distance *
		g_rays[i].distance_projection_plane);
		y = g_data.window_height / 2 - (g_rays[i].wall_stripe_height / 2);
		draw_sky(y, i, &j);
		draw_walls(i, &j);
		draw_floor(i, &j);
		j = 0;
		i++;
	}
}
