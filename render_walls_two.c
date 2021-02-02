/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:28:08 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:28:32 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	draw_sky(float y, int i, float *j)
{
	while (*j < y)
	{
		my_mlx_pixel_put(&g_mlx, i, *j, g_data.c_color);
		(*j)++;
	}
}
