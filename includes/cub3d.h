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

# define RED 16711680
# define WHITE 16777215
# define BLACK 0
# define YELLOW 16776960
# define TILE_SIZE 32
# define PI 3.14159265
# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define FOV_ANGLE 60 * PI / 180
typedef struct  s_struct
{
    char **map;
    int window_width;
    int window_height;
    int r_check;
    int x_render_size;
    int y_render_size;
    int r_completed;
    int f_completed;
    int map_lenght;
} t_struct;
t_struct g_data;    

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
    float x;
    float y;
    int radius;
    int turn_direction;
    int walk_direction;
    float rotation_angle;
    int move_speed;
    float rotation_speed;
    char direction;
    float line_x;
    float line_y;
    float move_step;
    
} t_player;
t_player g_player;
typedef struct s_rays
{
    float ray_angle;
    float wall_hit_x;
    float wall_hit_y;
    int is_ray_facing_down;
    int is_ray_facing_up;
    int is_ray_facing_right;
    int is_ray_facing_left;
    float x_intercept;
    float y_intercept;
    float wall_hit_h_x;
    float wall_hit_h_y;
    float wall_hit_v_x;
    float wall_hit_v_y;
    float next_h_x;
    float next_h_y;
    float x_step;
    float y_step;
} t_rays;
t_rays *g_rays;
void    draw_line(float x_one,float y_one,float x_zero,float y_zero);
void   draw_player();
void    fetch_player_info();
char	*ft_strjn(char *s1, char *s2);
int empty_line(char *str);
void    ft_error(char *message);
int is_wall_at(float x, float y);
int read_file();
void    cast_rays();
void    draw_map();
void    my_mlx_pixel_put(t_lib *g_mlx, int x, int y, int color);
#endif