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
void    horizontal_cast(int ray_i)
{
    g_rays[ray_i].y_intercept = floor(g_player.y/ TILE_SIZE) * TILE_SIZE;
    if (g_rays[ray_i].is_ray_facing_down)
        g_rays[ray_i].y_intercept += TILE_SIZE;
    g_rays[ray_i].x_intercept = g_player.x + (g_rays[ray_i].y_intercept - g_player.y) / tan(g_rays[ray_i].ray_angle);
    g_rays[ray_i].y_step = TILE_SIZE;
    if (g_rays[ray_i].is_ray_facing_up)
        g_rays[ray_i].y_step *= -1;

    g_rays[ray_i].x_step = TILE_SIZE / tan(g_rays[ray_i].ray_angle);
    if (g_rays[ray_i].is_ray_facing_left && g_rays[ray_i].x_step > 0)
        g_rays[ray_i].x_step *= -1;
    if (g_rays[ray_i].is_ray_facing_right && g_rays[ray_i].y_step < 0)
        g_rays[ray_i].x_step *= -1;
    //     printf("%f\n",tan(g_rays[ray_i].ray_angle));
    //     printf("%f\n",g_rays[ray_i].x_step);
    // draw_line(g_player.x,g_player.y,g_rays[ray_i].x_step,g_rays[ray_i].x_step);
    g_rays[ray_i].next_h_x = g_rays[ray_i].x_intercept;
    g_rays[ray_i].next_h_y = g_rays[ray_i].y_intercept;
    
    if (g_rays[ray_i].is_ray_facing_up)
        g_rays[ray_i].next_h_y--;
    while (g_rays[ray_i].next_h_x >= 0 && g_rays[ray_i].next_h_x <= g_data.window_width && g_rays[ray_i].next_h_y >= 0 && g_rays[ray_i].next_h_y <= g_data.window_height )
    {
        if (is_wall_at(g_rays[ray_i].next_h_x,g_rays[ray_i].next_h_y))
        {
            g_rays[ray_i].wall_hit_x = g_rays[ray_i].next_h_x;
            g_rays[ray_i].wall_hit_y = g_rays[ray_i].next_h_y;
            printf("%f \n",g_player.x);
            printf("%f \n",g_player.y);
            printf("%f \n",g_rays[ray_i].x_intercept);
            printf("%f \n",g_rays[ray_i].y_intercept);

            //draw_line(g_player.x,g_player.y,g_rays[ray_i].wall_hit_x,g_rays[ray_i].wall_hit_y);
            break;
        }
        else
        {
            g_rays[ray_i].next_h_x += g_rays[ray_i].x_step;
            g_rays[ray_i].next_h_y += g_rays[ray_i].y_step;
        }
        
    }
    // int i;

    // i = 0;
    // while (i != TILE_SIZE)
    // {
    //    g_rays[ray_i].wall_hit_x = g_player.x + (cos(g_rays[ray_i].ray_angle) * i);
    //     g_rays[ray_i].wall_hit_y = g_player.y + (sin(g_rays[ray_i].ray_angle) * i);
    //     my_mlx_pixel_put(&g_mlx, g_rays[ray_i].wall_hit_x,g_rays[ray_i].wall_hit_y, YELLOW);
    //   i++;
    // }


}
void    cast_rays()
{
    int ray_i;

    ray_i = 0;
    //normalize_angle();

    g_rays[ray_i].ray_angle = g_player.rotation_angle - (FOV_ANGLE/2);
    normalize_angle(ray_i); 
    ray_facing(ray_i);
    horizontal_cast(ray_i);
    //ft_putnbr(g_rays[ray_i].is_ray_facing_up);
    //ft_putnbr(g_rays[ray_i].is_ray_facing_left);
    //ft_putnbr(g_rays[ray_i].is_ray_facing_right);
    //ft_putnbr(g_rays[ray_i].is_ray_facing_down);

    //printf("%f\n",g_rays[ray_i].ray_angle);
    //while (i < g_data.window_width)
    //{
        //cast_ray(ray_i);
        //g_rays->ray_angle += FOV_ANGLE / g_data.window_width;
        //i++;
    //}
}