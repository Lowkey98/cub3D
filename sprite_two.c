# include "includes/cub3d.h"

int	 protect_x(t_sprite *sprite, int i)
{
	int valid;
	valid = 1;
	if ((int)sprite->x_offset + i > g_num_rays)
	{

	}
	if (sprite->x_offset + i < 0 ||
				 (int)sprite->x_offset + i >= g_num_rays ||
			 sprite->distance > g_rays[(int)sprite->x_offset + i].distance)
				valid = 0;
	return (valid);
}
void	draw_sprite(t_sprite *sprite, int i, int j)
{
	int color;

	color = g_texture.sprite_texture[((int)g_sprite_width* (j * \
	(int)g_sprite_height/
			(int)sprite->size)) + (i * (int)g_sprite_width /
			(int)sprite->size)];
	if (color != 0)
	{
		my_mlx_pixel_put(&g_mlx, sprite->x_offset + i,sprite->y_offset + j ,color);
	}
}
void	start_draw_sprite(t_sprite *sprite)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < sprite->size - 1)
	{
		if (!protect_x(sprite,i))
		{
			i++;
			continue;
		}
				j = 0;
		while (j < sprite->size - 1)
		{

			if (sprite->y_offset + j < 0 ||
					sprite->y_offset + j >= g_data.window_height)
			{
				j++;
				continue;
			}
			draw_sprite(sprite, i, j);
			j++;
		}
		i++;
	}
}
void render_sprite(t_sprite *sprite)
{
		float s_angle;

	s_angle = atan2(sprite->y - g_player.y, sprite->x - g_player.x);
	while (s_angle - (g_player.rotation_angle) > M_PI)
		s_angle -= 2 * M_PI;
	while (s_angle - (g_player.rotation_angle) < -M_PI)
		s_angle += 2 * M_PI;
	s_angle -= g_player.rotation_angle;
	if (g_data.window_height > g_data.window_width)
		sprite->size = (g_data.window_height/ sprite->distance) * g_tile_size;
	else
		sprite->size = (g_data.window_width/ sprite->distance) * g_tile_size;
	sprite->y_offset = (g_data.window_height / 2) - (sprite->size / 2);
	sprite->x_offset = ((s_angle * g_data.window_width) / g_fov_angle) +
		((g_data.window_width / 2) - (sprite->size / 2));
		start_draw_sprite(sprite);
}
void render_sprites()
{
	t_list *new;

	new = g_sprite_h;
	while(new)
	{
		render_sprite((t_sprite *) new ->content);
		new = new ->next;
	}
}