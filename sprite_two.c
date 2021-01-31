# include "includes/cub3d.h"

int	 x_valid(t_sprite *sprite, int i)
{
	int valid;
	valid = 1;
	if (sprite->x_offset + i < 0 ||
				sprite->x_offset + i > g_data.window_width)
			valid = 0;
		if ((int)sprite->x_offset + i >= g_num_rays)
			valid = 0;
		if (sprite->distance > g_rays[(int)sprite->x_offset + i].distance)
			valid = 0;
	return (valid);
}

void	draw_sprite(t_sprite *sprite)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < sprite->size)
	{
		if (!x_valid(sprite,i))
		{
			i++;
			continue;
		}
		j = 0;
		while (j < sprite->size)
		{
			if (sprite->y_offset + j < 0 ||
					sprite->y_offset + j > g_data.window_height)
			{
				j++;
				continue;
			}
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
	s_angle = s_angle - (g_player.rotation_angle);
	if (g_data.window_height > g_data.window_width)
		sprite->size = (g_data.window_height/ sprite->distance) * g_tile_size;
	else
		sprite->size = (g_data.window_width/ sprite->distance) * g_tile_size;
	sprite->y_offset = (g_data.window_height / 2) - (sprite->size / 2);
	sprite->x_offset = ((s_angle * g_data.window_width) / g_fov_angle) +
		((g_data.window_width / 2) - (sprite->size / 2));
		draw_sprite(sprite);
}
void render_sprites()
{
	t_list *new;

	new = g_sprite_h;
	while (new)
	{
		render_sprite((t_sprite *) new ->content);
		new = new ->next;
	}
}