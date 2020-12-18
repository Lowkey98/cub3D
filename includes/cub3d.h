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
# include <mlx.h>

#define RED 16711680
#define WHITE 16777215
#define BLACK 0
#define TILE_SIZE 32
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

typedef struct s_lib
{
    void *ptr;
    void *img;
    void *win;
    char *addr;
    int  bits_per_pixel;
    int  line_length;
    int  endian;
} t_lib;
t_lib g_mlx;

typedef struct s_player
{
    int exists;
    int x;
    int y;
    int radius;
    int turn_direction;
    int walk_direction;
    int rotation_angle;
    int move_speed;
    int rotation_speed;
    char direction;
    
} t_player;
t_player g_player;
void    fetch_player_info(t_struct *data);
char	*ft_strjn(char *s1, char *s2);
int empty_line(char *str);
void    ft_error(char *message);
int read_file(t_struct *data);
void    render_map(t_struct *data);
void    my_mlx_pixel_put(t_lib *g_mlx, int x, int y, int color);
#endif