
#include <stdio.h>
#include "includes/cub3d.h"
#include <string.h>



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
	else if (key == 2 || key  == 0)
	{
		g_a = PI/2;
		g_player.walk_direction = -1 + key;
	}

    //ft_putnbr(5);
    clear();
    //draw_map();
    move_player();
    rotate_player();
    //draw_player();
    cast_rays();
                //my_mlx_pixel_put(&g_mlx, 100,100, YELLOW);
    render_walls();
		sprite();

    mlx_put_image_to_window(g_mlx.ptr, g_mlx.win, g_mlx.img, 0, 0);
    g_player.turn_direction = 0;
    g_player.walk_direction = 0;
    //players_line();
    return (0);
}
void check_arg(int argc,char **argv)
{
	if (argc != 2 && argc != 3)
        ft_error_first("format should be ./cub3d ");
	char *dot = strrchr((const char*)argv[1], (int)'.');
		if (dot && strcmp((const char*)dot, ".cub"))
			ft_error_first(".cub at the end needed");
	if (argc == 3)
	{
		if (strcmp(argv[2], "--save"))
			ft_error_first("third argument can only be --save");
		else
			g_save_flag = 1;
	}
}
int main(int argc,char **argv)
{
	check_arg(argc,argv);
    initialize_data(argv[1]);
    g_mlx.ptr = mlx_init();
    read_file();
	g_num_rays = g_data.window_width;
    g_mlx.win = mlx_new_window(g_mlx.ptr, g_data.window_width  ,g_data.window_height,"cub3d");
    g_mlx.img = mlx_new_image(g_mlx.ptr,g_data.window_width,g_data.window_height);
    g_mlx.addr = mlx_get_data_addr(g_mlx.img, &g_mlx.bits_per_pixel,&g_mlx.line_length,&g_mlx.endian);
    //draw_map();
    fetch_player_info();
    g_rays = malloc((g_num_rays) *  sizeof(t_rays));
    cast_rays();
    render_walls();
	sprite();
	if (g_save_flag == 1)
		exit(0);
    mlx_put_image_to_window(g_mlx.ptr,g_mlx.win,g_mlx.img,0,0);
    mlx_hook(g_mlx.win, 2, 1L << 0, key_press, (void *)0);
    mlx_loop(g_mlx.ptr);
    return (0);
}