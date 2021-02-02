/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:45:42 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:45:52 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *line;
	char **lines;
	int j;
	int fd;

	fd = open("./text.cub",O_RDONLY);
	while (get_next_line(fd, &line))
	{
		*lines = realloc(line, j);
		printf("%s",line);
		j++;
	}
}
