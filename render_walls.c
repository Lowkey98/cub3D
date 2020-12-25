# include "includes/cub3d.h"
void    render_walls()
{
    int i;
    float y;
    float j;
    float correct_distance;
    j = 0;
    y = 0;
    i = 0;

    while (i < NUM_RAYS)
    {
        correct_distance =  g_rays[i].distance * cos(g_rays[i].ray_angle - g_player.rotation_angle);
        g_rays[i].distance_projection_plane = (g_data.window_width / 2) / tan(FOV_ANGLE / 2);
        g_rays[i].wall_stripe_height = (TILE_SIZE / correct_distance * g_rays[i].distance_projection_plane);
        y = g_data.window_height/2 - (g_rays[i].wall_stripe_height /2);
          //printf("%f\n", y);
        while (j < g_rays[i].wall_stripe_height && y < g_data.window_height)
        {
            if(y > 0)
                my_mlx_pixel_put(&g_mlx,i,y,WHITE);
            y++;
            j++;
        }
        j = 0;
        i++;
    }
    ft_putnbr(i);
}