/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:35:55 by ayafdel           #+#    #+#             */
/*   Updated: 2020/12/11 13:17:30 by ayafdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
typedef struct  s_struct
{
    char **map;
    int r_check;
    int x_render_size;
    int y_render_size;
    int r_completed;
    int f_completed;
    int map_lenght;
} t_struct;
char	*ft_strjn(char *s1, char *s2);
int empty_line(char *str);
void    ft_error(char *message, char *str);
int read_file(t_struct *data);
#endif