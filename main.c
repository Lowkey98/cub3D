
#include <stdio.h>
#include "includes/cub3d.h"

void initialize_data()
{
    data.map = 0;
    data.x_render_size = 0;
    data.y_render_size = 0;
    data.r_completed = 0;
    data.f_completed = 0;
    data.map_lenght = 0;
}
int is_wall_at(float x, float y)
{
    int i;
    int j;

    i = y / TILE_SIZE;
    j = x / TILE_SIZE;
    if (data.map[i][j] == '1')
        return (1);
    return (0);
}
void    move_player()
{
    float tmp_x;
    float tmp_y;
    g_player.move_speed = 8;
    g_player.move_step = g_player.move_speed * g_player.walk_direction;

    tmp_x = g_player.x + cos(g_player.rotation_angle) * g_player.move_step;
    tmp_y = g_player.y + sin(g_player.rotation_angle) * g_player.move_step;
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
    
    my_mlx_pixel_put(&g_mlx, g_player.x,g_player.y,YELLOW);
    //players_line();
    while (i != TILE_SIZE)
    {
        g_player.line_x = g_player.x + (cos(g_player.rotation_angle) * i);
        g_player.line_y = g_player.y + (sin(g_player.rotation_angle) * i);
            my_mlx_pixel_put(&g_mlx, g_player.line_x,g_player.line_y, YELLOW);
      i++;
    }
    //my_mlx_pixel_put(&g_mlx, g_player.line_x,g_player.line_y, YELLOW);

}
void    rotate_player()
{
    // if (!g_player.turn_direction)
    //     return ;
    g_player.rotation_speed = 2 * (PI /180);
    g_player.rotation_angle += g_player.turn_direction * g_player.rotation_speed;
    //ft_putnbr(g_player.turn_direction);
}
int	key_press(int key)
{
	if (key == UP_ARROW)
	    g_player.walk_direction = 1;
	else if (key == DOWN_ARROW)
		g_player.walk_direction = -1;
	else if (key == LEFT_ARROW)
	    g_player.turn_direction = -1;
	else if (key == RIGHT_ARROW)
	    g_player.turn_direction = 1;
    

    //ft_putnbr(5);
    draw_map();
    move_player();
    rotate_player();
    draw_player();
                //my_mlx_pixel_put(&g_mlx, 100,100, YELLOW);
    mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, g_mlx.img, 0, 0);
    g_player.turn_direction = 0;
    g_player.walk_direction = 0;
    //players_line();
    return (0);
}
int main()
{
    g_mlx.ptr = mlx_init();
    g_mlx.win = mlx_new_window(g_mlx.ptr,1920,1080,"cub3d");
    g_mlx.img = mlx_new_image(g_mlx.ptr,1920,1080);
    g_mlx.addr = mlx_get_data_addr(g_mlx.img, &g_mlx.bits_per_pixel,&g_mlx.line_length,&g_mlx.endian);
    //ft_putnbr(g_mlx.line_length);
    g_player.turn_direction = 0;
    g_player.walk_direction = 0;
    initialize_data();
    read_file();
    draw_map();
    fetch_player_info();
    draw_player();
    mlx_put_image_to_window(g_mlx.ptr,g_mlx.win,g_mlx.img,0,0);
    mlx_hook(g_mlx.win, 2, 1L << 0, key_press, (void *)0);
    mlx_loop(g_mlx.ptr);
    return (0);
}
