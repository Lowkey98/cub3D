# include "includes/cub3d.h"
void    cast_ray()
{
    int i;

    i = 0;
    while (i != TILE_SIZE)
    {
       g_rays.wall_hit_x = g_player.x + (cos(g_rays.ray_angle) * i);
        g_rays.wall_hit_y = g_player.y + (sin(g_rays.ray_angle) * i);
            my_mlx_pixel_put(&g_mlx, g_rays.wall_hit_x,g_rays.wall_hit_y, YELLOW);
      i++;
    }
}
void    cast_rays()
{
    int i;

    i = 0;
    g_rays.ray_angle = g_player.rotation_angle - (FOV_ANGLE/2);
    while (i < data.window_width)
    {
        cast_ray();
        g_rays.ray_angle += FOV_ANGLE / data.window_width;
        i++;
    }
}