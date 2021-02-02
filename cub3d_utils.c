/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:53:13 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 14:55:43 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/cub3d.h"

char	*ft_strjn(char *s1, char *s2)
{
	char		*temp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (s2[i] != 0)
		i++;
	temp = malloc(ft_strlen(s1) + i + 2);
	i = 0;
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = '\n';
	temp[i + 1] = '\0';
	free(s1);
	return (temp);
}

int		empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
