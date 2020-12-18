
#include <stdio.h>
#include "includes/cub3d.h"

void initialize_data(t_struct *data)
{
    data -> map = 0;
    data -> x_render_size = 0;
    data -> y_render_size = 0;
    data -> r_completed = 0;
    data -> f_completed = 0;
    data -> map_lenght = 0;
}

int main()
{
    t_struct *data;    
    data = malloc(sizeof(t_struct));
    g_mlx.ptr = mlx_init();
    g_mlx.win = mlx_new_window(g_mlx.ptr,1920,1080,"cub3d");
    g_mlx.img = mlx_new_image(g_mlx.ptr,1920,1080);
    g_mlx.addr = mlx_get_data_addr(g_mlx.img, &g_mlx.bits_per_pixel,&g_mlx.line_length,&g_mlx.endian);
    //ft_putnbr(g_mlx.line_length);
    initialize_data(data);
    read_file(data);
    render_map(data);
    fetch_player_info(data);
    //my_mlx_pixel_put(&g_mlx, 10, 10,0xFF0000);

    mlx_put_image_to_window(g_mlx.ptr,g_mlx.win,g_mlx.img,0,0);
   
    
    //render_map(data);

    mlx_loop(g_mlx.ptr);
    return (0);
}
