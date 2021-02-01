# include "includes/cub3d.h"
void    draw_sky(float y, int i,float *j)
{
    while (*j < y)
    {
        my_mlx_pixel_put(&g_mlx, i, *j,g_data.c_color);
        (*j)++;
    }
}
int wall_to_texture(int j, int i)
{
	int y;
	y = j + (g_rays[i].wall_stripe_height / 2) - (g_data.window_height /2);
	return (y * (g_tile_size/ g_rays[i].wall_stripe_height));
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
	float a = *j;
    int *texture;
	//float a;
	texture = fetch_texture(i);
	// if (i == 0)
	// {
	// 	printf("texture south %p \n",g_texture.south_texture);
	// 	printf("texture north %p \n",g_texture.north_texture);
	// 	printf("texture east %p \n",g_texture.east_texture);
	// 	printf("texture west %p \n",g_texture.west_texture);
	// 	//printf("texture  %p \n",texture);

	// }
    inc = 0;
	if (g_rays[i].is_wall_v)
	{
		texture_start = fmod(g_rays[i].wall_hit_y,g_tile_size);
		//ft_putchar('a');
	}
	else
		texture_start = fmod(g_rays[i].wall_hit_x,g_tile_size);
	//printf("%d\n",texture_start);
    while (inc < g_rays[i].wall_stripe_height && a < g_data.window_height)
    {
		//if (fetch_texture(i))
		//if (*j > 0)
		//a = *j;
		     //*j = g_data.window_height/2 - (g_rays[i].wall_stripe_height /2);

		// if (g_rays[i].is_ray_facing_up && g_rays[i].is_wall_h)
		//my_mlx_pixel_put(&g_mlx, i, a,texture[n);
	// if (g_rays[i].is_ray_facing_down && g_rays[i].is_wall_h)
	// if (inc == 0)
	int n = (wall_to_texture(*j,i) * g_tile_size) + texture_start;
	// printf("%d\n", n);
	//if (g_texture.north_texture[n] <  0)
		//printf("hello \n");

	//my_mlx_pixel_put(&g_mlx, i, *j,  g_texture.north_texture[(wall_to_texture(*j,i) * g_TILE_SIZE) + texture_start]);
	// if (g_rays[i].is_ray_facing_left && g_rays[i].is_wall_v)
	if (n >= 4096)
		n = 4095;
	my_mlx_pixel_put(&g_mlx, i, *j, texture[n]);
	//if (g_rays[i].is_ray_facing_right && g_rays[i].is_wall_v)
		//my_mlx_pixel_put(&g_mlx, i, *j,g_texture.east_texture[(wall_to_texture(*j,i) * 64) + texture_start]);



		//else
        	//my_mlx_pixel_put(&g_mlx, i, *j,GREEN);
        inc++;
        a++;
		*j = a;
    }
	//printf("%f \n",(*j));
}

void draw_floor(int i, float *j)
{
    while (*j < g_data.window_height)
    {
        my_mlx_pixel_put(&g_mlx, i, *j,g_data.f_color);
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

    while (i < g_num_rays)
    {
        correct_distance =  g_rays[i].distance * cos(g_rays[i].ray_angle - g_player.rotation_angle);
        g_rays[i].distance_projection_plane = (g_data.window_width / 2) / tan(g_fov_angle / 2);
        g_rays[i].wall_stripe_height = (g_tile_size / correct_distance * g_rays[i].distance_projection_plane);
        // if (g_rays[i].wall_stripe_height > g_data.window_height)
        //      g_rays[i].wall_stripe_height = g_data.window_height;
        y = g_data.window_height/2 - (g_rays[i].wall_stripe_height /2);
          //printf("%f\n", y);
		          //my_mlx_pixel_put(&g_mlx,1,1,PINK);
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