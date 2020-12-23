/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:55:37 by ayafdel           #+#    #+#             */
/*   Updated: 2020/01/15 09:52:52 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*temp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (s2[i] != 0 && s2[i] != '\n')
		i++;
	if ((temp = malloc(ft_strlen(s1) + i + 1)) == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	free(s1);
	return (temp);
}

char	*ft_strdup(char *str)
{
	char	*s1;
	int		i;

	i = 0;
	if ((s1 = malloc(ft_strlen(str) + 1)) == 0)
		return (0);
	while (str[i] != '\0')
	{
		s1[i] = str[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strchr(char *str, char x)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == x)
			return (str + i + 1);
		i++;
	}
	return (0);
}
