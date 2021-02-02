/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafdel <ayafdel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:35:55 by ayafdel           #+#    #+#             */
/*   Updated: 2021/02/02 09:41:38 by ayafdel          ###   ########.fr       */
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

# define MINIMAP_SCALE 0.2
int g_num_rays;
# define RED 16711680
# define WHITE 16777215
# define BLACK 0
# define PINK 16752084
# define YELLOW 16776960
# define PURPLE 8681416
# define GREEN 8692050
# define BLUE 11834
int g_tile_size;
# define PI 3.14159265
# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
float g_fov_angle;
int g_save_flag;

typedef struct		s_sprite
{
	int			x;
	int			y;
	float		distance;
	int			size;
	float		x_offset;
	float 		y_offset;
}					t_sprite;
typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;
t_list *g_sprite_h;
typedef struct  s_struct
{
    char **map;
    char *map_name;
    int window_width;
    int window_height;
    int r_check;
    int x_render_size;
    int y_render_size;
    int r_completed;
    int no_completed;
	int so_completed;
	int we_completed;
	int ea_completed;
	int s_completed;
    int f_completed;
	int c_completed;
    int map_lenght;
    int map_height;
	int f_color;
	int c_color;
} t_struct;
t_struct g_data;
float g_a;

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
typedef	struct		s_bmp
{
	int				bitcount;
	int				width;
	int				bf_off_bits;
	int				w_in_b;
	int				image_size;
	int				bi_size;
	int				*data;
	int				bi_planes;
	int				row;
	int				col;
	int				height;
	int				file_size;
	unsigned	char*	buf;
}					t_bmp;
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
    float next_v_x;
    float next_v_y;
    int found_h_wall;
    int found_v_wall;
    int is_wall_v;
    int is_wall_h;
    float x_step;
    float y_step;
    float h_distance;
    float v_distance;
    float distance;
    float distance_projection_plane;
    float wall_stripe_height;
    float wall_stripe_width;
} t_rays;
t_rays *g_rays;
typedef struct s_texture
{
    int *north_texture;
	int *south_texture;
	int *east_texture;
	int *west_texture;
	int *sprite_texture;
    int north_texture_w;
	int south_texture_w;
	int east_texture_w;
	int west_texture_w;
	int north_texture_h;
	int south_texture_h;
	int east_texture_h;
	int west_texture_h;

}t_texture;
t_texture g_texture;
int g_sprite_height;
int g_sprite_width;
int			ft_exit(void);
void ft_error_first(char *message);
void ft_error_map(char *message);
void	check_mapstr_error(char *map_str);
void	check_player();
void	add_spaces();
void fetch_r(char *str);
int	reached_map();
void	fetch_element(char *str);
int max_lenght();
char *skip_empty_lines(char *str);
void fetch_no(char *str);
void fetch_so(char *str);
void fetch_we(char *str);
void fetch_ea(char *str);
void fetch_s(char *str);
void initialize_data(char *argv);
int is_wall_at(float x, float y);
void    move_player();
void   draw_player();
void    rotate_player();
float	distance_two_points(float x_one,float y_one,float x_two,float y_two);
void	horizontal_cast(int ray_i);
void	initialize_cast_data(int ray_i);
void ray_facing(int ray_i);
void	normalize_angle(int ray_i);
void fetch_c(char *str);
int		rgb_to_int(int t, int r, int g, int b);
int*	initialize_rgb(int *rgb);
void fetch_f(char *str);
void	sprite();
void	render_sprites();
float	distance_two_points(float x_one,float y_one,float x_two,float y_two);
void	render_sprite(t_sprite *sprite);
void fetch_sprite_position(int i,int j);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void    render_walls();
void    draw_line(float x_one,float y_one,float x_zero,float y_zero);
void   draw_player();
void    fetch_player_info();
char	*ft_strjn(char *s1, char *s2);
int		empty_line(char *str);
void    ft_error(char *message, char *str);
int is_wall_at(float x, float y);
int read_file();
void    cast_rays();
void    draw_map();
void    my_mlx_pixel_put(t_lib *g_mlx, int x, int y, int color);
void	ft_screenshot();
#endif