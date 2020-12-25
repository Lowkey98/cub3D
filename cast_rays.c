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
    g_rays[ray_i].ray_angle = remainderf(g_rays[ray_i].ray_angle,(2 * PI));
    if (g_rays[ray_i].ray_angle < 0)
        g_rays[ray_i].ray_angle = (2 * PI) + g_rays[ray_i].ray_angle;
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
void    initialize_cast_data(int ray_i)
{
    g_rays[ray_i].y_intercept = 0;
    g_rays[ray_i].x_intercept = 0;
    g_rays[ray_i].y_step = 0;
    g_rays[ray_i].x_step = 0;
    g_rays[ray_i].next_h_x = 0;
    g_rays[ray_i].next_h_y = 0;
    g_rays[ray_i].wall_hit_h_x = 0;
    g_rays[ray_i].wall_hit_h_y = 0;
    g_rays[ray_i].found_h_wall = 0;
    g_rays[ray_i].next_v_x = 0;
    g_rays[ray_i].next_v_y = 0;
    g_rays[ray_i].wall_hit_v_x = 0;
    g_rays[ray_i].wall_hit_v_y = 0;
    g_rays[ray_i].found_v_wall = 0;

}
void    horizontal_cast(int ray_i)
{
    while (g_rays[ray_i].next_h_x >= 0 && g_rays[ray_i].next_h_x < (g_data.map_lenght * TILE_SIZE) && g_rays[ray_i].next_h_y >= 0 && g_rays[ray_i].next_h_y < (g_data.map_height * TILE_SIZE) )
    {
        if (is_wall_at(g_rays[ray_i].next_h_x,g_rays[ray_i].next_h_y))
        {
            g_rays[ray_i].wall_hit_h_x = g_rays[ray_i].next_h_x;
            g_rays[ray_i].wall_hit_h_y = g_rays[ray_i].next_h_y;
            g_rays[ray_i].found_h_wall = 1;
            break;
        }
        else
        {
            g_rays[ray_i].next_h_x += g_rays[ray_i].x_step;
            g_rays[ray_i].next_h_y += g_rays[ray_i].y_step;
        }
    }
}
void    vertical_cast(int ray_i)
{
    while (g_rays[ray_i].next_v_x >= 0 && g_rays[ray_i].next_v_x <= (g_data.map_lenght * TILE_SIZE) && g_rays[ray_i].next_v_y  >= 0 && g_rays[ray_i].next_v_y <= (g_data.map_height * TILE_SIZE) )
    {
        if (is_wall_at(g_rays[ray_i].next_v_x,g_rays[ray_i].next_v_y))
        {
            g_rays[ray_i].wall_hit_v_x = g_rays[ray_i].next_v_x;
            g_rays[ray_i].wall_hit_v_y = g_rays[ray_i].next_v_y;
            g_rays[ray_i].found_v_wall = 1;
            break;
        }
        else
        {
            g_rays[ray_i].next_v_x += g_rays[ray_i].x_step;
            g_rays[ray_i].next_v_y += g_rays[ray_i].y_step;
        }
    }
}    

float   distance_two_points(x_one,y_one,x_two,y_two)
{
    return (sqrt((x_one - x_two) * (x_one - x_two) + (y_one - y_two) * (y_one - y_two)));
}
void    shortest_cast(int ray_i)
{
    if (g_rays[ray_i].found_h_wall)
        g_rays[ray_i].h_distance = distance_two_points(g_player.x,g_player.y,g_rays[ray_i].wall_hit_h_x,g_rays[ray_i].wall_hit_h_y);
    else
        g_rays[ray_i].h_distance = MAXFLOAT;
    if (g_rays[ray_i].found_v_wall)
        g_rays[ray_i].v_distance = distance_two_points(g_player.x,g_player.y,g_rays[ray_i].wall_hit_v_x,g_rays[ray_i].wall_hit_v_y);
    else
    {
        g_rays[ray_i].v_distance = MAXFLOAT;
    }
    if (g_rays[ray_i].v_distance > g_rays[ray_i].h_distance )
    {
        g_rays[ray_i].wall_hit_x = g_rays[ray_i].wall_hit_h_x;
        g_rays[ray_i].wall_hit_y = g_rays[ray_i].wall_hit_h_y;
    }
    else
    {
        g_rays[ray_i].wall_hit_x = g_rays[ray_i].wall_hit_v_x;
        g_rays[ray_i].wall_hit_y = g_rays[ray_i].wall_hit_v_y;
    }
}
void horizontal_intercept(int ray_i)
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
    if (g_rays[ray_i].is_ray_facing_right && g_rays[ray_i].x_step < 0)
        g_rays[ray_i].x_step *= -1;
    g_rays[ray_i].next_h_x = g_rays[ray_i].x_intercept;
    g_rays[ray_i].next_h_y = g_rays[ray_i].y_intercept;
    
    if (g_rays[ray_i].is_ray_facing_up)
        g_rays[ray_i].next_h_y--;
}
void    vertical_intercept(int ray_i)
{
        g_rays[ray_i].x_intercept = floor(g_player.x/ TILE_SIZE) * TILE_SIZE;
    if (g_rays[ray_i].is_ray_facing_right)
        g_rays[ray_i].x_intercept += TILE_SIZE;
    g_rays[ray_i].y_intercept = g_player.y + (g_rays[ray_i].x_intercept - g_player.x) * tan(g_rays[ray_i].ray_angle);
    g_rays[ray_i].x_step = TILE_SIZE;
    if (g_rays[ray_i].is_ray_facing_left)
        g_rays[ray_i].x_step *= -1;
    g_rays[ray_i].y_step = TILE_SIZE * tan(g_rays[ray_i].ray_angle);
    if (g_rays[ray_i].is_ray_facing_up && g_rays[ray_i].y_step > 0)
        g_rays[ray_i].y_step *= -1;
    if (g_rays[ray_i].is_ray_facing_down && g_rays[ray_i].y_step < 0)
        g_rays[ray_i].y_step *= -1;
    g_rays[ray_i].next_v_x = g_rays[ray_i].x_intercept;
    g_rays[ray_i].next_v_y = g_rays[ray_i].y_intercept;
    if (g_rays[ray_i].is_ray_facing_left)
        g_rays[ray_i].next_v_x--;
}
void    cast_rays()
{
    int ray_i;
    float angle_inc;
    ray_i = 0;        
    angle_inc = FOV_ANGLE / NUM_RAYS;
    while (ray_i < NUM_RAYS)
    {
        g_rays[ray_i].ray_angle = (g_player.rotation_angle - (FOV_ANGLE / 2)) + (ray_i * angle_inc);  
        normalize_angle(ray_i);
        ray_facing(ray_i);
        initialize_cast_data(ray_i);
        horizontal_intercept(ray_i);
        horizontal_cast(ray_i);
        vertical_intercept(ray_i);
        vertical_cast(ray_i);
        shortest_cast(ray_i);
        draw_line(g_rays[ray_i].wall_hit_x * MINIMAP_SCALE,g_rays[ray_i].wall_hit_y * MINIMAP_SCALE ,g_player.x * MINIMAP_SCALE ,g_player.y * MINIMAP_SCALE);
    
        ray_i = ray_i + 1;;
    }
    g_rays[100].ray_angle = (g_player.rotation_angle - (FOV_ANGLE / 2)) + (ray_i * angle_inc);
}