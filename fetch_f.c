/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:56:16 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 14:56:17 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	check_rgb_f(int *rgb, char *str)
{
	if (rgb[0] == -1 || rgb[0] > 255)
		ft_error("invalid rgb in f", str);
	if (rgb[1] == -1 || rgb[1] > 255)
		ft_error("invalid rgb in f", str);
	if (rgb[2] == -1 || rgb[2] > 255)
		ft_error("invalid rgb in f", str);
	g_data.f_color = rgb_to_int(0, rgb[0], rgb[1], rgb[2]);
}

int		fetch_f_r(int i, int *rgb, char *str)
{
	int j;

	j = 0;
	rgb[0] = ft_atoi(str + i);
	if (!ft_isdigit(str[i]))
		ft_error("error information r in F", str);
	while (ft_isdigit(str[i]))
	{
		if (j == 3)
			ft_error("max rgb == 255", str);
		i++;
		j++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != ',')
		ft_error("RGB format 000,000,000", str);
	i++;
	return (i);
}

int		fetch_f_g(int i, int *rgb, char *str)
{
	int j;

	j = 0;
	rgb[1] = ft_atoi(str + i);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (j > 3)
			ft_error("long", str);
		j++;
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] != ',')
		ft_error(",", str);
	i++;
	return (i);
}

int		fetch_f_b(int i, int *rgb, char *str)
{
	int j;

	j = 0;
	rgb[2] = ft_atoi(str + i);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (j > 3)
			ft_error("bigass numb", str);
		i++;
	}
	return (i);
}

void	fetch_f(char *str)
{
	int i;
	int rgb[3];

	i = 2;
	initialize_rgb(rgb);
	while (str[i] == ' ')
		i++;
	i = fetch_f_r(i, rgb, str);
	i = fetch_f_g(i, rgb, str);
	i = fetch_f_b(i, rgb, str);
	if (str[i] != '\0')
		ft_error("error last ddf", str);
	check_rgb_f(rgb, str);
	g_data.f_completed = 1;
}
