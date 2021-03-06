/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:57:54 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 14:58:30 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/cub3d.h"

int			ft_exit(void)
{
	mlx_destroy_window(g_mlx.ptr, g_mlx.win);
	exit(0);
}

void		ft_error_first(char *message)
{
	ft_putstr(message);
	exit(0);
}

void		ft_error_map(char *message)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_putstr(message);
	while (g_data.map[i] != 0)
	{
		free(g_data.map[i]);
		i++;
	}
	free(g_data.map);
	exit(0);
}

void		ft_error(char *message, char *str)
{
	ft_putstr(message);
	free(str);
	exit(0);
}
