# include "includes/cub3d.h"
void    cast_ray(int ray_i)
{
    int i;

    i = 0;
    while (i != TILE_SIZE)
    {
       g_rays[ray_i].wall_hit_x = g_player.x + (cos(g_rays[ray_i].ray_angle) * i);
        g_rays[ray_i].wall_hit_y = g_player.y + (sin(g_rays[ray_i].ray_angle) * i);
        my_mlx_pixel_put(&g_mlx, g_rays[ray_i].wall_hit_x,g_rays[ray_i].wall_hit_y, YELLOW);
      i++;
    }
}
void    normalize_angle(int ray_i)
{
    g_rays[ray_i].ray_angle = remainderf(g_rays->ray_angle,(2 * PI));
    if (g_rays[ray_i].ray_angle < 0)
        g_rays[ray_i].ray_angle = (2 * PI) + g_rays->ray_angle;
}
void ray_facing(int ray_i)
{
    g_rays[ray_i].is_ray_facing_down = 0;
    g_rays[ray_i].is_ray_facing_up = 0;
    g_rays[ray_i].is_ray_facing_right = 0;
    g_rays[ray_i].is_ray_facing_left = 0;
    if (g_rays[ray_i].ray_angle > 0 && g_rays[ray_i].ray_angle < PI)
        g_rays[ray_i].is_ray_facing_down = 1;
    else
        g_rays[ray_i].is_ray_facing_up = 1;
    if (g_rays[ray_i].ray_angle < 0.5 * PI || g_rays[ray_i].ray_angle > 1.5 * PI)
        g_rays[ray_i].is_ray_facing_right = 1;
    else 
        g_rays[ray_i].is_ray_facing_left = 1;
}
void    cast_rays()
{
    int ray_i;

    ray_i = 0;
    //normalize_angle();
    
    g_rays[ray_i].ray_angle = g_player.rotation_angle - (FOV_ANGLE/2);
    normalize_angle(ray_i);
    ray_facing(ray_i);
    //ft_putnbr(g_rays[ray_i].is_ray_facing_up);
    //ft_putnbr(g_rays[ray_i].is_ray_facing_left);
    //ft_putnbr(g_rays[ray_i].is_ray_facing_right);
    ft_putnbr(g_rays[ray_i].is_ray_facing_down);

    //printf("%f\n",g_rays[ray_i].ray_angle);
    //while (i < g_data.window_width)
    //{
        cast_ray(ray_i);
        //g_rays->ray_angle += FOV_ANGLE / g_data.window_width;
        //i++;
    //}
}