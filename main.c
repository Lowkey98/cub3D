
#include <stdio.h>
#include "includes/cub3d.h"

void initialize_data(char *argv)
{
    g_data.map_name = argv;
    g_data.map = 0;
    g_data.x_render_size = 0;
    g_data.y_render_size = 0;
    g_data.r_completed = 0;
    g_data.f_completed = 0;
    g_data.map_lenght = 0;
}
int is_wall_at(float x, float y)
{
    int i;
    int j;

    i = y / g_tile_size;
    j = x / g_tile_size;
    if (g_data.map[i][j] == '1')
        return (1);
    return (0);
}
void    move_player()
{
    float tmp_x;
    float tmp_y;
    g_player.move_speed = 5;
    g_player.move_step = g_player.move_speed * g_player.walk_direction;

    tmp_x = g_player.x + cos(g_player.rotation_angle + g_a) * g_player.move_step;
    tmp_y = g_player.y + sin(g_player.rotation_angle  + g_a) * g_player.move_step;
	g_a = 0;
    if (is_wall_at(tmp_x,tmp_y))
        return ;
    g_player.x = tmp_x;
    g_player.y = tmp_y;
    //my_mlx_pixel_put(&g_mlx, g_player.x,g_player.y,YELLOW);


    //ft_putstr("a");
}

void   draw_player()
{
    int i;

    i = 0;

    //my_mlx_pixel_put(&g_mlx, g_player.x,g_player.y,YELLOW);
    //players_line();
    while (i != g_tile_size)
    {
        g_player.line_x = g_player.x + (cos(g_player.rotation_angle) * i);
        g_player.line_y = g_player.y + (sin(g_player.rotation_angle) * i);
            my_mlx_pixel_put(&g_mlx, g_player.line_x * MINIMAP_SCALE ,g_player.line_y * MINIMAP_SCALE, GREEN);
      i++;
    }
    //my_mlx_pixel_put(&g_mlx, g_player.line_x,g_player.line_y, YELLOW);

}
void    rotate_player()
{
    // if (!g_player.turn_direction)
    //     return ;
    g_player.rotation_speed = 5 * (PI /180);
    g_player.rotation_angle += g_player.turn_direction * g_player.rotation_speed;
    //ft_putnbr(g_player.turn_direction);
}
void clear()
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < g_data.window_width)
    {
        while (y < g_data.window_height)
        {
            my_mlx_pixel_put(&g_mlx,x,y,BLACK);
            y++;
        }
        y = 0;
        x++;
    }

}
int	key_press(int key)
{
    if (key == 53 || key == 12)
        exit(1);
	if (key == UP_ARROW)
	    g_player.walk_direction = 1;
	else if (key == DOWN_ARROW)
		g_player.walk_direction = -1;
	else if (key == LEFT_ARROW)
	    g_player.turn_direction = -1;
	else if (key == RIGHT_ARROW)
	    g_player.turn_direction = 1;
	else if (key == 2)
	{
		g_a = PI/2;
		g_player.walk_direction = 1;
	}
	else if (key == 0)
	{
		g_a = PI/2;
		g_player.walk_direction = -1;
	}
    //ft_putnbr(5);
    clear();
    draw_map();
    move_player();
    rotate_player();
    //draw_player();
    //cast_rays();
                //my_mlx_pixel_put(&g_mlx, 100,100, YELLOW);
    render_walls();
    mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, g_mlx.img, 0, 0);
    g_player.turn_direction = 0;
    g_player.walk_direction = 0;
    //players_line();
    return (0);
}
int main(int argc,char **argv)
{
	g_tile_size = 64;
	g_FOV_ANGLE = 60 * PI / 180;
    if (argc != 2)
        ft_error("wrong number of arguments");
    initialize_data(argv[1]);
    g_mlx.ptr = mlx_init();
    read_file();
	g_NUM_RAYS = g_data.window_width;
    g_mlx.win = mlx_new_window(g_mlx.ptr, g_data.window_width  ,g_data.window_height,"cub3d");
    g_mlx.img = mlx_new_image(g_mlx.ptr,g_data.window_width,g_data.window_height);
    g_mlx.addr = mlx_get_data_addr(g_mlx.img, &g_mlx.bits_per_pixel,&g_mlx.line_length,&g_mlx.endian);
    //ft_putnbr(g_mlx.line_length);
    g_player.turn_direction = 0;
    g_player.walk_direction = 0;

    draw_map();
    fetch_player_info();
    //draw_player();
    g_rays = malloc((g_NUM_RAYS) *  sizeof(t_rays));
    //cast_rays();
    render_walls();
    //draw_line(200,200,100,100);
    mlx_put_image_to_window(g_mlx.ptr,g_mlx.win,g_mlx.img,0,0);
    mlx_hook(g_mlx.win, 2, 1L << 0, key_press, (void *)0);
    mlx_loop(g_mlx.ptr);
    return (0);
}