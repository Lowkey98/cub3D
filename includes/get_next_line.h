/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:44:36 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 15:44:37 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, char x);

#endif
