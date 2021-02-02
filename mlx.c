/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:01:22 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 16:08:56 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	my_mlx_pixel_put(t_lib *g_mlx, int x, int y, int color)
{
	char	*dst;

	dst = g_mlx->addr + (y * g_mlx->line_length + x *
	(g_mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
