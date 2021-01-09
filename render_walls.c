# include "includes/cub3d.h"
void    draw_sky(float y, int i,float *j)
{
    while (*j < y)
    {
        my_mlx_pixel_put(&g_mlx, i, *j,PURPLE);
        (*j)++;
    }
}
int wall_to_texture(int j, int i)
{
	int y;
	y = j + (g_rays[i].wall_stripe_height / 2) - (g_data.window_height /2);
	return (y * ((float)TILE_SIZE / g_rays[i].wall_stripe_height));
}
int *fetch_texture(int i)
{
    if (g_rays[i].is_ray_facing_up && g_rays[i].is_wall_h)
        return (g_texture.north_texture);
	if (g_rays[i].is_ray_facing_down && g_rays[i].is_wall_h)
        return (g_texture.south_texture);
	if (g_rays[i].is_ray_facing_left && g_rays[i].is_wall_v)
        return (g_texture.west_texture);
	if (g_rays[i].is_ray_facing_right && g_rays[i].is_wall_v)
        return (g_texture.east_texture);
    return (NULL);
}
void draw_walls(int i, float *j)
{
    float inc;
	int texture_start;
    int *texture;        
	
	texture = fetch_texture(i);
	if (i == 0)
	{
		printf("texture south %p \n",g_texture.south_texture);
		printf("texture north %p \n",g_texture.north_texture);
		printf("texture east %p \n",g_texture.east_texture);
		printf("texture west %p \n",g_texture.west_texture);
		printf("texture  %p \n",texture);

	} 
    inc = 0;
	if (g_rays[i].is_wall_v)
	{
		texture_start = fmod(g_rays[i].wall_hit_y,TILE_SIZE);
		//ft_putchar('a');
	}
	else
		texture_start = fmod(g_rays[i].wall_hit_x,TILE_SIZE);
	//printf("%d\n",texture_start);
    while (inc < g_rays[i].wall_stripe_height && *j < g_data.window_height)
    {
		//if (fetch_texture(i))
		//if (*j > 0)
		my_mlx_pixel_put(&g_mlx, i, *j,texture[(wall_to_texture(*j,i) * TILE_SIZE) + texture_start]);



		//else
        	//my_mlx_pixel_put(&g_mlx, i, *j,GREEN);
        inc++;
        (*j)++;
    }
}

void draw_floor(int i, float *j)
{
    while (*j < g_data.window_height)
    {
        my_mlx_pixel_put(&g_mlx, i, *j,BLUE);
        (*j)++;
    }
}

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
        // if (g_rays[i].wall_stripe_height > g_data.window_height)
        //      g_rays[i].wall_stripe_height = g_data.window_height;
        y = g_data.window_height/2 - (g_rays[i].wall_stripe_height /2);
          //printf("%f\n", y);
            draw_sky(y,i,&j);
            draw_walls(i, &j);
            draw_floor(i, &j);
        

        // while (j < g_rays[i].wall_stripe_height && y < g_data.window_height)
        // {
        //     if(y > 0)
        //         my_mlx_pixel_put(&g_mlx, i, y,WHITE);
        //     y++;
        //     j++;
        // }
        j = 0;
        i++;
    }
    //ft_putnbr(i);
}