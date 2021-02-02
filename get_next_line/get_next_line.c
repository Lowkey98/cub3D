/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:44:55 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:44:56 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

int		reading(int fd, char **rem, char **line)
{
	char	*buff;
	char	*temp;
	int		i;

	if (!(buff = malloc(100 + 1)))
		return (-1);
	while (((i = read(fd, buff, 100)) > 0))
	{
		buff[i] = '\0';
		if ((*line = ft_strjoin(*line, buff)) == 0)
			return (-1);
		if (ft_strchr(buff, '\n') != 0)
		{
			temp = *rem;
			*rem = ft_strdup(ft_strchr(buff, '\n'));
			if (temp != 0)
				ft_free(&temp);
			if (*rem == 0)
				return (-1);
			ft_free(&buff);
			return (1);
		}
	}
	ft_free(&buff);
	return (i);
}

int		read_leftovers(char **rem, char **line)
{
	char *temp;
	char *chr;

	if (*rem == 0)
		return (0);
	if (((*line = ft_strjoin(*line, *rem)) == 0))
		return (-1);
	if ((chr = ft_strchr(*rem, '\n')))
	{
		temp = *rem;
		*rem = ft_strdup(chr);
		ft_free(&temp);
		if (*rem == 0)
			return (-1);
		return (1);
	}
	else
		ft_free(rem);
	return (0);
}

int		error(char **line, int fd)
{
	if (fd < 0 || line == 0 || 100 < 0)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*rem;
	int				i;

	if (error(line, fd))
		return (-1);
	if ((*line = ft_strdup("")) == 0)
		return (-1);
	if ((i = read_leftovers(&rem, line)))
		return (i);
	return (reading(fd, &rem, line));
}
